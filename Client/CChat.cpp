// (C) LHMP Team 2013-2016; Licensed under Apache 2; See LICENSE;;

#include "CCore.h"
#include "CChat.h"
#define	DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#pragma comment(lib, "d3dx8.lib")

#include <lhmp_gamestructures.h>

#include <RakPeerInterface.h>
#include <MessageIdentifiers.h>
#include <BitStream.h>
#include <RakNetTypes.h> 

extern CCore *g_CCore;


CChat::CChat()
{
	CHAT_WIDTH				=	0;
	CHAT_MAX_LINES			=	100;
	CHAT_LINES_PER_RENDER	=	12;
	CHAT_POINTER			=	0;
	IsRendering				=	false;
	bIsTyping				=	false;
	m_bBackground			=	false;
	chatTexture				=	NULL;

	shouldReRender			=	true;
	animation				=	0;
	
	this->ChatPoolStart = NULL;
	this->elementCount = 0;
	this->lastInputNext = 0;
	this->lastInputPointer = 0;
}
CChat::~CChat()
{
}
void CChat::Render(IDirect3DDevice8* pInterface,LPD3DXFONT font)
{
	if (shouldReRender)
		this->RenderTexture(pInterface);
	if (chatTexture != NULL)
	{
		D3DXVECTOR2 scaling;
		scaling.x = 1.0f;
		scaling.y = 1.0f;
		D3DXVECTOR2 translation;
		translation.x = 0;
		translation.y = (float) animation;

		animation -= 1;
		if (animation < 0) animation = 0;
		
		if (g_CCore->GetGraphics()->GetSprite()->Begin() != S_OK)
			return;
		g_CCore->GetGraphics()->GetSprite()->Draw(chatTexture, NULL, &scaling, NULL, 0.0, &translation, D3DCOLOR_ARGB(255, 255, 255, 255));
		g_CCore->GetGraphics()->GetSprite()->End();
		
		return;
	}
}

// add message process and add message into chat log
void CChat::AddMessage(std::string message)
{
	if (message.length() > 0)
	{
		if (elementCount > (unsigned int) CHAT_LINES_PER_RENDER-1)
			animation = 20;
		//----
		CColoredText* newText = new CColoredText((char*)message.c_str());
		CChatStack* newStack = new CChatStack();
		newStack->text = newText;
		newStack->next = this->ChatPoolStart;
		this->ChatPoolStart = newStack;
		elementCount++;
	
		CColoredText* nextText = newText->SplitText(CHAT_WIDTH - 10, true);
		while (nextText != NULL)
		{
			if (nextText->GetElementCount() == 0)
			{
				delete[] nextText;
				shouldReRender = true;
				return;
			}
			else {
				nextText->ReCalculate();
				newStack = new CChatStack();
				newStack->text = nextText;
				newStack->next = this->ChatPoolStart;
				this->ChatPoolStart = newStack;
				// this line is important
				newText = nextText;
				elementCount++;
			}
			nextText = newText->SplitText(CHAT_WIDTH - 10, true);
		}
		shouldReRender = true;
	}
}

void CChat::AddDebugMessage(char* format, ...) {
	#if LHMP_VERSION_TYPE == 0
		char buff[512] = "";
		char endbuff[512] = "";

		va_list args;
		va_start(args, format);
		vsprintf(buff, format, args);
		va_end(args);

		sprintf(endbuff, "#f31d2f>> #e3e3e3%s", buff);

		//AddMessage(endbuff);
	#endif
}

void CChat::DoneMessage()
{
	if(ChatMessage != "")
	{
		if(ChatMessage.substr(0,1) == "/")
		{
			if(ChatMessage.size() > 1)
			{
				char buff[1024];
				sprintf(buff,"%s",ChatMessage.c_str());
				DoCommand(buff);
			}
		} else
		{
			RakNet::BitStream bsOut;
			bsOut.Write((RakNet::MessageID)ID_GAME_LHMP_PACKET);
			bsOut.Write((RakNet::MessageID)LHMP_PLAYER_CHAT_MESSAGE);
			bsOut.Write((unsigned short)ChatMessage.length());
			bsOut.Write(ChatMessage.c_str());
			g_CCore->GetNetwork()->SendServerMessage(&bsOut,HIGH_PRIORITY,RELIABLE_ORDERED);
		}
		ChatMessage	= "";
	}
}

void CChat::DoCommand(char str[])
{
	char command[256];
	char varlist[512] = "";
	char *pch;
	pch = strchr(str,' ');
	if(pch == NULL)
	{
		memcpy(command,str+1,strlen(str));
	} else {
		memcpy(command,str+1,(pch-str));
		command[(pch-str)-1] = '\0';
		memcpy(varlist,pch+1,strlen(pch));
	}

	RakNet::BitStream bsOut;
	bsOut.Write((RakNet::MessageID)ID_GAME_LHMP_PACKET);
	bsOut.Write((RakNet::MessageID)LHMP_PLAYER_COMMAND);
	bsOut.Write(command);
	bsOut.Write(varlist);
	g_CCore->GetNetwork()->SendServerMessage(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED);
	

	if (strcmp(command, "exit") == 0 || strcmp(command, "quit") == 0 || strcmp(command, "q") == 0)
	{
		g_CCore->ShutdownClient();
	}
	else if (strcmp(command, "clearchat") == 0)
	{
		this->ClearChat();
	}
	else if (strcmp(command, "chatwidth") == 0)
	{
		if (strlen(varlist) > 0)
		{
			int newwidth = atoi(varlist);
			CHAT_WIDTH = Tools::Clamp(newwidth, 200, 500);
		}
	}
	else if (strcmp(command, "chatlines") == 0)
	{
		if (strlen(varlist) > 0)
		{
			int newwidth = atoi(varlist);
			if (newwidth > 5)
			{
				this->CHAT_LINES_PER_RENDER = newwidth;
			}
		}
	}
	else if (strcmp(command, "crash") == 0)
	{
		g_CCore->GetGame()->ChangeSkin(122, 5);	// wrong PED base => 100% crash :)
	}
	else if(strcmp(command,"chatback") == 0)
	{
		g_CCore->GetChat()->SetBackground(!this->IsBackgroundActive());
	}
}

bool CChat::IsTyping()
{
	return bIsTyping;
}

void CChat::SetTyping(bool b)
{
	bIsTyping = b;
	//g_CCore->GetGame()->UpdateControls(); --- NO LONGER NEEDED
}


void CChat::SetBackground(bool bg)
{
	m_bBackground = bg;
}

bool CChat::IsBackgroundActive()
{
	return m_bBackground;
}


// Clears all chat messages
void	CChat::ClearChat()
{
	this->elementCount = 0;
	CChatStack* pointer = this->ChatPoolStart;
	CChatStack* current;
	this->ChatPoolStart = NULL;
	while (pointer != NULL)
	{
		current = pointer;
		pointer = pointer->next;
		delete current->text;
		delete current;
	}

	this->shouldWeRerender();
}

void	CChat::RenderTexture(IDirect3DDevice8* device)
{
	// init chat width if it hasn't been yet
	if (CHAT_WIDTH == 0)
	{
		Vector2D screen = g_CCore->GetGraphics()->GetResolution();
		CHAT_WIDTH = (int)(screen.x / 2.25f);
	}

	if (chatTexture == NULL)
	{
		D3DXCreateTexture(device, CHAT_WIDTH, 700,
			1, D3DUSAGE_RENDERTARGET,
			D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &chatTexture);
	}
	if (chatTexture == NULL)
	{
		return;
	}

	shouldReRender = false;

	IDirect3DSurface8* pSurf, *pOldTarget, *oldStencil;
	
	if (!SUCCEEDED(chatTexture->GetSurfaceLevel(0, &pSurf)))
		return;
	if (!SUCCEEDED(device->GetRenderTarget(&pOldTarget)))
		return;
	if (!SUCCEEDED(device->GetDepthStencilSurface(&oldStencil)))
		return;
	HRESULT hr;
	hr = device->SetRenderTarget(pSurf, NULL);
	if (FAILED(hr)) {
		char buffer[255];
		D3DXGetErrorString(hr, buffer, 200);
		sprintf(buffer, "SetRenderTarget %s", buffer);
		MessageBoxA(NULL, buffer, buffer, MB_OK);
	}
	
	device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 255, 255, 255), 1.0f, 0);
	
	if (elementCount > 0)
	{
		if (this->IsBackgroundActive() == 1)
		{
			int howMany = elementCount;
			if (elementCount > (unsigned int)this->CHAT_LINES_PER_RENDER)
				howMany = this->CHAT_LINES_PER_RENDER;
			g_CCore->GetGraphics()->Clear(10, 10, 10 + CHAT_WIDTH, 20 + (howMany * 20), D3DCOLOR_ARGB(200, 0, 0, 0));
		}
		int iRendered = 0;

		// ------------------------------	Render chat lines
		int howMany = elementCount;
		if (elementCount > (unsigned int)this->CHAT_LINES_PER_RENDER)
			howMany = this->CHAT_LINES_PER_RENDER;

		CChatStack* stackPointer = this->ChatPoolStart;
		for (int i = 0; i < howMany; i++)
		{
			int line_y = (20 * (howMany - i));
			g_CCore->GetGraphics()->GetFont()->DrawColoredText(stackPointer->text, 20, line_y, true);
			stackPointer = stackPointer->next;
		}
		iRendered = howMany;
		// ------------------------------	Render input with its background if it's needed
		if (IsTyping())
		{

			int base_y = 30 + (20 * iRendered);
			iRendered = 0;
			// if there hasn't been any text on the input yet
			if (ChatMessage.length() == 0)
			{
				if (this->IsBackgroundActive() == true)
					g_CCore->GetGraphics()->Clear(10, base_y, 10 + CHAT_WIDTH, 30, D3DCOLOR_ARGB(200, 50, 0, 0));
				g_CCore->GetGraphics()->GetFont()->DrawTextA(">", 21, base_y + 5, D3DCOLOR_XRGB(200, 200, 200), true);
			}
			else
			{
				int index = 0;
				int howMuchWeNeed = g_CCore->GetGraphics()->GetStrlenForWidth(CHAT_WIDTH - 10, (char*) ChatMessage.c_str() + index);
				while (howMuchWeNeed > 0)
				{
					std::string	colour = g_CCore->GetGraphics()->GetLastColorInText((char*)ChatMessage.c_str(), index);
					// let's presume there will never be more than 512 characters per line
					// TODO - buffer overflow warning
					char buf[512];
					sprintf(buf, "%s%s", colour.c_str(), ChatMessage.substr(index, howMuchWeNeed).c_str());
					// if background filling is enabled, then render the background
					if (this->IsBackgroundActive() == true)
						g_CCore->GetGraphics()->Clear(10, base_y, 10 + CHAT_WIDTH, 30, D3DCOLOR_ARGB(200, 50, 0, 0));
					// draw the text
					g_CCore->GetGraphics()->GetFont()->DrawTextA(buf, 21, base_y + 5, D3DCOLOR_XRGB(200, 200, 200), true);
					// sum up the position pointer with the already drawn text
					index += howMuchWeNeed;
					// add up pixels for rendered line
					base_y += 20;
					howMuchWeNeed = g_CCore->GetGraphics()->GetStrlenForWidth(CHAT_WIDTH - 10, (char*)ChatMessage.c_str() + index);
				}
			}
		}
	}
	
	device->SetRenderTarget(pOldTarget, oldStencil);
	pSurf->Release();
	pOldTarget->Release();
	oldStencil->Release();
}

void	CChat::DoRendering()
{
	if (this->IsBackgroundActive() == 1)
	{
		int howMany = elementCount;
		if (elementCount > (unsigned int)this->CHAT_LINES_PER_RENDER)
			howMany = this->CHAT_LINES_PER_RENDER;
		g_CCore->GetGraphics()->Clear(10, 10, 10 + CHAT_WIDTH, 20 + (howMany * 20), D3DCOLOR_ARGB(200, 0, 0, 0));
	}
	int iRendered = 0;

	// Render chat lines
	int howMany = elementCount;
	if (elementCount > (unsigned int)this->CHAT_LINES_PER_RENDER)
		howMany = this->CHAT_LINES_PER_RENDER;

	CChatStack* stackPointer = this->ChatPoolStart;
	for (int i = 0; i < howMany; i++)
	{
		int line_y = (20 * (howMany - i));
		g_CCore->GetGraphics()->GetFont()->DrawColoredText(stackPointer->text, 20, line_y, true);
		stackPointer = stackPointer->next;
	}
	iRendered = howMany;
	// Render input with its background if it's needed
	if (IsTyping())
	{

		int base_y = 30 + (20 * iRendered);
		iRendered = 0;
		if (ChatMessage == "")
		{
			if (this->IsBackgroundActive() == true)
				g_CCore->GetGraphics()->Clear(10, base_y, 10 + CHAT_WIDTH, 30, D3DCOLOR_ARGB(200, 50, 0, 0));
			//return;
			g_CCore->GetGraphics()->GetFont()->DrawTextA(">", 21, base_y + 5, D3DCOLOR_XRGB(200, 200, 200), true);
		}
		else
		{
			char buff[255];
			sprintf(buff, "%s", ChatMessage.c_str());
			int index = 0;
			while (1)
			{
				int howMuchWeNeed = g_CCore->GetGraphics()->GetStrlenForWidth(CHAT_WIDTH - 10, buff + index);
				std::string	farba = g_CCore->GetGraphics()->GetLastColorInText(buff, index);
				if (howMuchWeNeed == 0) break;
				char buf[255];
				sprintf(buf, "%s%s", farba.c_str(), ChatMessage.substr(index, howMuchWeNeed).c_str());
				int line_y = base_y + (30 * iRendered);
				if (this->IsBackgroundActive() == true)
					g_CCore->GetGraphics()->Clear(10, line_y, 10 + CHAT_WIDTH, 30, D3DCOLOR_ARGB(200, 50, 0, 0));

				g_CCore->GetGraphics()->DrawText(buf, 21, line_y + 5, D3DCOLOR_XRGB(200, 200, 200), true,true);
				index += howMuchWeNeed;
				iRendered++;
			}
		}
	}
}

__declspec(noinline) void	CChat::OnLostDevice()
{
	if (chatTexture != NULL)
	{
		chatTexture->Release();
		chatTexture = NULL;
	}
}

void	CChat::OnResetDevice()
{
	chatTexture = false;
	shouldReRender = true;
}


bool	CChat::shouldWeRerender()
{
	return this->shouldReRender;
}
void	CChat::SetRerenderState(bool state)
{
	this->shouldReRender = state;
}

//-------------------- Handles chat history things ----------------

void	CChat::AddNewLastMessage(std::string message)
{
	this->lastInputs[this->lastInputNext] = message;
	this->lastInputNext++;
	if (this->lastInputNext > 9)
		this->lastInputNext = 0;
	this->lastInputPointer = this->lastInputNext;

}
std::string	CChat::GetNextLast()
{
	this->lastInputPointer++;
	if (lastInputPointer > 9)
		lastInputPointer = 0;
	return this->lastInputs[lastInputPointer];
}
std::string	CChat::GetPreviousLast()
{
	if (this->lastInputPointer <= 0)
	{
		this->lastInputPointer = 9;
	}
	else {
		this->lastInputPointer--;
	}
	return this->lastInputs[lastInputPointer];
}