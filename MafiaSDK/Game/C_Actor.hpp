/*
	Copyright 2017 Dávid Svitana

	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.
*/


#ifndef _CACTOR_H_
#define _CACTOR_H_

namespace MafiaSDK
{
	struct C_Actor_Interface
	{
		C_Entity_Interface entity;
	};

	namespace C_Actor_Enum
	{
		enum FunctionAddresses
		{
			Activate = 0x47AFE0
		};
	};

	class C_Actor
	{
	public:
		C_Actor_Interface* GetInterface()
		{
			return reinterpret_cast<C_Actor_Interface*>(this);
		}

		void Init( I3D_Frame* frame )
		{
			__asm
			{
				mov edi, this
				mov esi, frame
				mov eax, dword ptr[edi]
				mov ecx, edi
				push esi
				call dword ptr[eax + 48h]	
			}
		}

		void SetActive( BOOL active )
		{
			unsigned long funcAddress = C_Actor_Enum::FunctionAddresses::Activate;
			__asm
			{
				mov ecx, this
				push active
				call funcAddress
			}

		}
	};
};

#endif