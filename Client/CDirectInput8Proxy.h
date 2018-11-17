// (C) LHMP Team 2013-2016; Licensed under Apache 2; See LICENSE;;

#ifndef __CDIRECT_INPUT_PROXY_H
#define __CDIRECT_INPUT_PROXY_H

#define DIRECTINPUT_VERSION 0x0800
#include "CDirectInput8DeviceProxy.h"
#include <dinput.h>
#include "CCore.h"

#pragma comment(lib,"Dxguid.lib")

extern CCore	*g_CCore;

class MyDirectInput : public IDirectInput8A
{
	private:
		IDirectInput8A* p_DI;
	public:
		MyDirectInput(IDirectInput8A* di) : p_DI(di)
		{
		}
		~MyDirectInput ( )
		{
		}

		/*** IUnknown methods ***/
		HRESULT STDMETHODCALLTYPE QueryInterface ( REFIID riid,  LPVOID * ppvObj )
		{
			return p_DI->QueryInterface ( riid, ppvObj );
		}

		ULONG STDMETHODCALLTYPE AddRef ( VOID )
		{
			return p_DI->AddRef ( );
		}

		ULONG STDMETHODCALLTYPE Release ( VOID )
		{
			ULONG ulRefCount = p_DI->Release ();
			if ( ulRefCount == 0 )
			{
				delete this;
			}
			return ulRefCount;
		}

		HRESULT STDMETHODCALLTYPE EnumDevices ( DWORD a, LPDIENUMDEVICESCALLBACKA b, LPVOID c, DWORD d )
		{
			return p_DI->EnumDevices ( a, b, c, d );
		}

		HRESULT STDMETHODCALLTYPE GetDeviceStatus ( REFGUID a )
		{
			return p_DI->GetDeviceStatus ( a );
		}

		HRESULT STDMETHODCALLTYPE RunControlPanel ( HWND a, DWORD b )
		{
			return p_DI->RunControlPanel ( a, b );
		}

		HRESULT STDMETHODCALLTYPE Initialize ( HINSTANCE a, DWORD b )
		{
			return p_DI->Initialize ( a, b );
		}

		HRESULT STDMETHODCALLTYPE FindDevice ( REFGUID a, LPCSTR b, LPGUID c )
		{
			return p_DI->FindDevice ( a, b, c );
		}

		HRESULT STDMETHODCALLTYPE EnumDevicesBySemantics ( LPCSTR a, LPDIACTIONFORMATA b, LPDIENUMDEVICESBYSEMANTICSCBA c, LPVOID d, DWORD e )
		{
			return p_DI->EnumDevicesBySemantics ( a, b, c, d, e );
		}

		HRESULT STDMETHODCALLTYPE ConfigureDevices ( LPDICONFIGUREDEVICESCALLBACK a, LPDICONFIGUREDEVICESPARAMSA b, DWORD c, LPVOID d )
		{
			return p_DI->ConfigureDevices ( a, b, c, d );
		}

		STDMETHOD(CreateDevice)(REFGUID rguid, LPDIRECTINPUTDEVICE8A *b, LPUNKNOWN unknown)
        {
				bool isKB	= false;
				if(rguid == GUID_SysKeyboard)
				{
					isKB		= true;
				}
				
                HRESULT hr = p_DI->CreateDevice(rguid, b, unknown);
                if(SUCCEEDED(hr)/* && rguid == GUID_SysKeyboard*/)
                {
                        // Return our own keyboard device that checks for injected keypresses
                        MyDirectDevice* MDD = new MyDirectDevice(*b,isKB);
						*b = MDD;
                }

                return hr;
        }
};

#endif