/*
Copyright 2017 D�vid Svitana

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

#ifndef _I3D_Frame_H_
#define _I3D_Frame_H_

namespace MafiaSDK
{
	struct I3D_Frame_Interface
	{
		PADDING(I3D_Frame_Interface, _pad0, 0x40);
		Vector3D mPosition;
		Vector3D mRotation;
	};

	namespace I3D_Frame_Enum
	{
		enum FunctionsAddresses
		{
			SetWorldPos = 0x1001B160,
			CacheBlock = 0x647ED8,
			CacheBlock_OpenModel = 0x647DD0,
			CacheBlock_CreateModel = 0x4087E0,
			SetScale = 0x0047A750,
			SetPos = 0x00460980,
			SetRot = 0x0043BCE0
		};
	};

	class I3D_Frame
	{
	public:
		I3D_Frame_Interface* GetInterface()
		{
			return reinterpret_cast<I3D_Frame_Interface*>(this);
		}

		I3D_Frame()
		{
			unsigned long cacheBlock = I3D_Frame_Enum::FunctionsAddresses::CacheBlock;

			__asm
			{
				mov     eax, cacheBlock
				mov     eax, [eax]
				push    9
				push    eax
				mov     ecx, [eax]
				call    dword ptr[ecx + 50h]
				mov		this, eax
			}
		}

		void SetWorldPos(const Vector3D & pos)
		{
			unsigned long funcAddr = I3D_Frame_Enum::FunctionsAddresses::SetWorldPos;

			__asm
			{
				mov edi, this
				push pos
				//mov ecx, edi
				push edi
				call funcAddr
			}
		}

		void LoadModel(const char* modelName)
		{
			unsigned long cacheBlockOpenModel = I3D_Frame_Enum::FunctionsAddresses::CacheBlock_OpenModel;
			unsigned long cacheBlockCreateModel = I3D_Frame_Enum::FunctionsAddresses::CacheBlock_CreateModel;

			__asm
			{
				mov esi, this
				push 0
				push 0
				push 0
				push 0
				push modelName
				push esi
				mov ecx, cacheBlockOpenModel
				call cacheBlockCreateModel

				// Our model was created?
				test eax, eax
				jnz CCache

				//UpdateMatrix
				mov ecx, dword ptr[esi]
				push esi
				call dword ptr[ecx + 18h]
				CCache:
			}
		}

		void UpdateMatrix()
		{
			__asm
			{
				mov eax, this
				push eax
				mov ecx, dword ptr ds : [eax]
				call dword ptr[ecx + 0x18]
			}
		}

		void SetPos(Vector3D vPostion)
		{
			unsigned long funcAddr = I3D_Frame_Enum::FunctionsAddresses::SetPos;


			DWORD dwFunc2 = 0x0047AD10;
			DWORD dwFunc3 = 0x0047A6C0;
			DWORD dwFunc5 = 0x005D92D0;
			DWORD dwFunc6 = 0x0047ADF0;

			//Set position
			__asm
			{
				//SetFrame Pos
				lea eax, vPostion
				push eax
				mov ecx, this
				call funcAddr

				//Update frame
				mov eax, this
				push eax
				mov ecx, dword ptr ds : [eax]
				call dword ptr[ecx + 0x18]

				//Get some offset
				mov ecx, this
				call dwFunc2

				//Check of exists
				cmp dword ptr ds : [eax], 0
				je jump

				//Get offset 1 
				mov ecx, this
				call dwFunc2

				//Get offset 2
				mov ecx, [eax]
				call dwFunc3

				cmp dword ptr ds : [eax], 5
				jnz end

				jump :
				mov ecx, dword ptr ds : [C_MISSION_CLASS]
					mov edx, this
					push edx
					call dwFunc5

					mov ecx, eax
					call dwFunc6
					end :
			}
		}

		void SetRot(Vector4D & vRotation)
		{
			unsigned long addressFunc = I3D_Frame_Enum::FunctionsAddresses::SetRot;

			__asm
			{
				push vRotation
				mov ecx, this
				call addressFunc
			}

			UpdateMatrix();
		}

		void SetScale(Vector3D & vScale)
		{
			unsigned long addressFunc = I3D_Frame_Enum::FunctionsAddresses::SetScale;

			__asm
			{
				push vScale
				mov ecx, this
				call addressFunc
			}

			UpdateMatrix();
		}

		void SetOn(BOOL isOn)
		{
			__asm
			{
				mov edi, this
				mov eax, dword ptr ds : [edi]
				push isOn
				push edi
				call dword ptr ds : [eax + 0x24]
			}
		}

		void SetName(const char* frameName)
		{
			__asm
			{
				mov edi, this
				mov eax, dword ptr ds : [edi]
				push frameName
				push edi
				call dword ptr ds : [eax + 0x28]
			}
		}

		I3D_Frame* FindChildFrame(const char* childFrameName)
		{
			__asm
			{
				mov edi, this

				push 0x0FFFF
				push childFrameName
				push edi
				mov ecx, dword ptr ds : [edi]
				call dword ptr ds : [ecx + 0x38]
			}
		}
	};

	inline I3D_Frame* FindFrame(const char* frameName)
	{
		MafiaSDK::I3D_Frame* returnFrame = nullptr;

		__asm
		{
			//Mission 
			mov ecx, dword ptr ds : [0x63788C]

			//->GetSomething
			mov eax, dword ptr ds : [ecx + 0x10]

			//Find Frame
			mov ecx, dword ptr ds : [eax]
			push 0x4FFFF
			push frameName
			push eax
			call dword ptr ds : [ecx + 0x58]

			mov returnFrame, eax
		}

		return returnFrame;
	}
}

#endif