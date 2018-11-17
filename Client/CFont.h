// (C) LHMP Team 2013-2016; Licensed under Apache 2; See LICENSE;;

#include "CColoredText.h"
#include "d3dfont.h"
#ifndef C_FONT
#define C_FONT

class CFont{
private:
	CD3DFont*	m_pFont;
public:
	CFont(wchar_t font[100], wchar_t font2[100], int size, DWORD flags = 0UL);
	~CFont();

	// Dx callbacks
	void	OnDeviceLost();
	void	OnReset();

	// draw
	void	DrawText(wchar_t text[], int x , int y, D3DCOLOR color, bool shadow = true);
	void	DrawColoredText(CColoredText* text, int x, int y, bool shadow = true);
	void	DrawColoredText(wchar_t* text, int x, int y,DWORD color, bool shadow = true);

	// calculations

	__declspec(noinline) SIZE	GetFontWidth(wchar_t[], int len = -1);
	int		GetColoredTextWidth(wchar_t[]);
	int		GetStrlenForWidth(int, wchar_t*);

};
#endif