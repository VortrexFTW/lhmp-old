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

#ifndef _CHUMAN_H_
#define _CHUMAN_H_

namespace MafiaSDK
{
	struct C_Human_Interface
	{
		C_Entity_Interface	entity;
		PADDING(C_Human_Interface, _pad0, 0x4);
		byte animStateLocal;
		byte isInAnimWithCarLocal;
		PADDING(C_Human_Interface, _pad1, 0x2);
		byte animState;
		byte isInAnimWithCar;
		PADDING(C_Human_Interface, _pad2, 0x22);
		C_Car* playersCar;
		C_Car* carLeavingOrEntering;
		PADDING(C_Human_Interface, _pad3, 0x144);
		bool isDucking;
		bool isAiming;
		PADDING(C_Human_Interface, _pad4, 0x16);
		bool isReloading;
		PADDING(C_Human_Interface, _pad5, 0x11B);
		I3D_Frame *	neckFrame;
		PADDING(C_Human_Interface, _pad6, 0x164);
		G_Inventory inventory;
		PADDING(C_Human_Interface, _pad7, 0xF4);
		float inCarRotation;
		PADDING(C_Human_Interface, _pad8, 0x4C);
		float health;
	};

	namespace C_Human_Enum
	{
		enum FunctionsAddresses
		{
			Hit = 0x5762A0,
			Intern_UseCar = 0x57E020,
			Intern_FromCar = 0x57E500,
			RepairWeaponPosition = 0x57E980,
			ChangeWeaponModel = 0x57EC20,
			Do_ChangeWeapon = 0x57F550,
			Do_WeaponDrop = 0x585D90,
			Use_Actor = 0x582180,
			Do_Shoot = 0x583590,
			Do_ThrowGranade	= 0x583F40,
			Do_Reload = 0x585B40,
			Do_Holster = 0x585C60,
			Do_Jump	= 0x586190,
			Do_PlayAnim	= 0x585E80,
			Do_ThrowCocotFromCar = 0x587D70,
			EineMeineKleineAutoInLuft = 0x58A5A0,
			NewScream = 0x58B470,
			Intern_ChangeModel = 0x587190,
			Do_StopAnim = 0x57D2E0,
			Do_Breath = 0x57D310,
			Do_Aimed = 0x57F830,
			Do_Crouched = 0x57F8A0,
			G_Inventory_Insert = 0x6092B0,
			G_Inventory_Remove	= 0x6095E0
		};

		//Thanks for DjBozkosz Documentation
		enum BehaviorStates : byte
		{
			ReactsAll = 0, //Reacts on attacks, shots. Ducks only, moves away if char was hit multiple times – Duck.
			ReactsAllUnknown = 1, //Reacts on attacks, shots. Ducks only, moves away if char was hit multiple times – ???
			DoesntReactGuard = 2, //Does not react to anything. Guards the player – No reaction.
			DoesntReactOnWeapon = 4, //Does not react on anything – No reaction on weapon.
			ReactsPlayerOnHit = 8, //Reacts on player only, Attacks player – React when hit.
			ReactsPlayerMovesAway = 16, //Reacts on player, Moves away – Reaction on Player.
			ReactsOnAttacksAwayOrAttack = 32, //Reacts on attacks to other characters. He either moves away or attacks attacker – React on Attack.
			ReactsOnAttacksAttack = 64, //Reacts on attacks to other characters. Attacks attacker – React on Attack 2. 
			ProgrammedReacts = 128 //Used for Little Joe in mission 9 programmed reactions, can add a little variety to non gangster characters – Afra
		};
	};

	class C_Human : public C_Actor
	{
	public:
		C_Human_Interface* GetInterface()
		{
			return reinterpret_cast<C_Human_Interface*>(this);
		}

		int Hit(int hitType, const Vector3D & unk1, const Vector3D & unk2, const Vector3D & unk3, float damage, MafiaSDK::C_Actor* atacker, unsigned long hittedPart, MafiaSDK::I3D_Frame* targetFrame)
		{
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::Hit;
			int returnVal = 0;

			__asm
			{
				push targetFrame
				push hittedPart
				push atacker
				push damage
				push unk3
				push unk2
				push unk1
				push hitType
				mov ecx, this
				call funcAddress
				mov returnVal, eax
			}
			
			return returnVal;
		}

		void SetBehavior(C_Human_Enum::BehaviorStates behavior)
		{
			/*__asm
			{
				mov ecx, this
				mov ax, behavior
				mov byte ptr ds : [ ecx + 0x5FC ], ax
			}*/
			*(byte*)(this + 0x5FC) = behavior;
		}

		void SetShooting(float shooting)
		{
			*(byte*)(this + 0x628) = shooting;
		}

		void Intern_UseCar(C_Car* car, int seatID)
		{
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::Intern_UseCar;
			

			__asm
			{
				push seatID
				push car
				mov ecx, this
				call funcAddress
			}
		}

		void Intern_FromCar(void)
		{
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::Intern_FromCar;
			I3D_Frame* vehicleFrame  = *(I3D_Frame**)((unsigned long)this->GetInterface()->playersCar + 0x68);
			
			__asm
			{
				push vehicleFrame
				mov ecx, this
				call funcAddress
			}
		}

		void RepairWeaponPosition(void)
		{
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::RepairWeaponPosition;
			
			__asm
			{
				mov ecx, this
				call funcAddress
			}
		}

		void ChangeWeaponModel(void)
		{
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::ChangeWeaponModel;
			
			__asm
			{
				mov ecx, this
				call funcAddress
			}
		}

		void Do_ChangeWeapon(int weaponId, BOOL bool1)
		{
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::Do_ChangeWeapon;
			
			__asm
			{
				push bool1
				push weaponId
				mov ecx, this
				call funcAddress
			}
		}

		void Do_PlayAnim( const char* animationName )
		{
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::Do_PlayAnim;
			
			__asm
			{
				push 0
				push 0
				push animationName
				mov ecx, this
				call funcAddress
			}
		}

		void Do_StopAnim(void)
		{
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::Do_PlayAnim;
			

			__asm
			{
				mov ecx, this
				call funcAddress
			}
		}

		void Use_Actor(C_Actor* actor, int unk1, int unk2, int unk3)
		{
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::Use_Actor;
			
			__asm
			{
				push unk3
				push unk2
				push unk1
				push actor
				mov ecx, this
				call funcAddress
			}
		}

		void Do_Shoot(bool isShooting, Vector3D * vPos)
		{
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::Do_Shoot;
			
			__asm
			{
				push vPos
				push isShooting
				mov ecx, this
				call funcAddress
			}
		}

		void Do_ThrowGranade(Vector3D vPos)
		{
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::Do_ThrowGranade;
			
			__asm
			{
				lea eax, vPos
				push eax
				mov ecx, this
				call funcAddress
			}
		}

		void Do_Reload(void)
		{
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::Do_Reload;
			
			__asm
			{
				mov ecx, this
				call funcAddress
			}
		}

		void Do_Holster(void)
		{
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::Do_Holster;
			
			__asm
			{
				mov ecx, this
				call funcAddress
			}
		}

		void Do_WeaponDrop(void)
		{
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::Do_WeaponDrop;
			
			__asm
			{
				mov ecx, this
				call funcAddress
			}
		}

		void Do_ThrowCocotFromCar(C_Car * car, int seatId)
		{
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::Do_ThrowCocotFromCar;
			
			__asm
			{
				push seatId
				push car
				mov ecx, this
				call funcAddress
			}
		}

		void EineMeineKleineAutoInLuft(C_Car * car)
		{
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::EineMeineKleineAutoInLuft;
			
			__asm
			{
				push car
				mov ecx, this
				call funcAddress
			}
		}

		void NewScream(unsigned int screamId)
		{
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::NewScream;
			

			__asm
			{
				push screamId
				mov ecx, this
				call funcAddress
			}
		}

		void Intern_ChangeModel(const char* modelName)
		{
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::Intern_ChangeModel;
			

			__asm
			{
				push 0
				push modelName
				mov ecx, this
				call funcAddress
			}
		}

		void G_Inventory_Insert(S_GameItem newItem, BOOL unk)
		{
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::G_Inventory_Insert;
			G_Inventory* inventory = &this->GetInterface()->inventory;

			__asm
			{
				push unk
				lea eax, newItem
				push eax
				mov ecx, inventory
				call funcAddress
			}
		}

		S_GameItem* G_Inventory_AddWeapon(int weaponId, int ammoLoaded, int ammoHidden)
		{
			S_GameItem newItem = { weaponId, ammoLoaded, ammoHidden, NULL };

			this->G_Inventory_Insert(newItem, false);

			this->ChangeWeaponModel();

			return &newItem;
		}

		void G_Inventory_RemoveWeapon(short int iWeaponId)
		{
			G_Inventory* inventory = &this->GetInterface()->inventory;
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::G_Inventory_Remove;

			__asm
			{
				sub esp, 500h
				mov ax, iWeaponId
				lea ecx, dword ptr ss : [esp + 0x1EC]
				push 0
				push ecx
				mov ecx, inventory
				mov word ptr ss : [esp + 0x1F4], ax
				call funcAddress
				add esp, 500h
			}

			this->ChangeWeaponModel();
		}
	};

	namespace C_Human_Hooks
	{
		inline void HookOnHumanHit(std::function<int(MafiaSDK::C_Human*, int, const Vector3D &, const Vector3D &, const Vector3D &, float, MafiaSDK::C_Actor*, unsigned long, MafiaSDK::I3D_Frame*)> funcitonPointer);

#ifdef MAFIA_SDK_IMPLEMENTATION
		namespace FunctionsPointers
		{
			std::function<int(MafiaSDK::C_Human*, int, const Vector3D &, const Vector3D &, const Vector3D &, float, MafiaSDK::C_Actor*, unsigned long, MafiaSDK::I3D_Frame*)> humanHit;
			std::function<void(const Vector3D &)> humanShoot;
			std::function<void(MafiaSDK::C_Human*, byte)> humanDoWeaponChange;
		};

		namespace Functions
		{
			inline int HumanHit(MafiaSDK::C_Human* thisInstance, int hitType, const Vector3D & unk1, const Vector3D & unk2, const Vector3D & unk3, float damage, MafiaSDK::C_Actor* atacker, unsigned long hittedPart, MafiaSDK::I3D_Frame* targetFrame)
			{
				if (FunctionsPointers::humanHit != nullptr)
					return FunctionsPointers::humanHit(thisInstance, hitType, unk1, unk2, unk3, damage, atacker, hittedPart, targetFrame);

				else return 0;
			}

			inline void HumanShoot(const Vector3D & position)
			{
				if (FunctionsPointers::humanShoot != nullptr)
					FunctionsPointers::humanShoot(position);
			}

			inline void HumanDoWeaponChange(MafiaSDK::C_Human* thisInstance, byte weaponId)
			{
				if (FunctionsPointers::humanDoWeaponChange != nullptr)
				{
					FunctionsPointers::humanDoWeaponChange(thisInstance, weaponId);
				}
			}
		};

		namespace NakedFunctions
		{
			__declspec(naked) void HumanHitOne()
			{
				__asm
				{
					MOV EAX, DWORD PTR SS : [ESP + 0x30]
					MOV ECX, DWORD PTR SS : [ESP + 0x2C]
					MOV EDI, DWORD PTR SS : [ESP + 0x28]
					MOV EDX, DWORD PTR SS : [ESP + 0x24]
					PUSH EAX; / Arg8 = 00000001
					MOV EAX, DWORD PTR SS : [ESP + 0x24]; |
					PUSH ECX; | Arg7 = 000000CB
					MOV ECX, DWORD PTR SS : [ESP + 0x24]; |
					PUSH EDI; | Arg6 = 0C691FC8 ASCII "xXb"
					PUSH EDX; | Arg5 = 00000000
					MOV EDX, DWORD PTR SS : [ESP + 0x28]; |
					PUSH EAX; | Arg4 = 00000001
					MOV EAX, DWORD PTR SS : [ESP + 0x28]; |
					PUSH ECX; | Arg3 = 000000CB
					PUSH EDX; | Arg2 = 00000000
					PUSH EAX; | Arg1 = 00000001
					PUSH ESI
					CALL Functions::HumanHit
					ADD ESP, 0x24

					MOV EAX, 0x00507F10
					JMP EAX
				}
			}

			__declspec(naked) void HumanHitTwo()
			{
				__asm
				{
					MOV EAX, DWORD PTR SS : [ESP + 0x24]
					MOV ECX, DWORD PTR SS : [ESP + 0x20]
					MOV EDX, DWORD PTR SS : [ESP + 0x1C]
					PUSH EAX; / Arg8 = 00001001
					MOV EAX, DWORD PTR SS : [ESP + 0x1C]; |
					PUSH ECX; | Arg7 = 00001001
					MOV ECX, DWORD PTR SS : [ESP + 0x1C]; |
					PUSH EDX; | Arg6 = 00000000
					MOV EDX, DWORD PTR SS : [ESP + 0x1C]; |
					PUSH EAX; | Arg5 = 00001001
					MOV EAX, DWORD PTR SS : [ESP + 0x1C]; |
					PUSH ECX; | Arg4 = 00001001
					MOV ECX, DWORD PTR SS : [ESP + 0x1C]; |
					PUSH EDX; | Arg3 = 00000000
					PUSH EAX; | Arg2 = 00001001
					PUSH ECX; | Arg1 = 00001001
					PUSH ESI
					CALL Functions::HumanHit
					ADD ESP, 0x24

					MOV EAX, 0x0059425F
					JMP EAX
				}
			}

			__declspec(naked) void HumanShoot()
			{
				__asm
				{
					LEA ECX, DWORD PTR SS : [ESP + 0x38]

					pushad
						push ecx
						call Functions::HumanShoot
						add esp, 0x4
					popad

					PUSH ECX;
					PUSH 1
					MOV ECX, ESI
					MOV EAX, 0x583590
					CALL EAX

					mov eax, 0x00591424
					jmp eax
				}	
			}

			__declspec(naked) void HumanDoWeaponChangeOne()
			{
				__asm
				{
					PUSH ECX; / Arg2 = 00000000
					PUSH EBP; | Arg1 = 00000000
					MOV ECX, ESI; |
					MOV EAX, 0x0057F550; \Game.0057F550
					CALL EAX

					pushad
						mov ax, word ptr ds : [esi + 0x4A0]
						push ax
						push esi
						call Functions::HumanDoWeaponChange
						add esp, 0x6
					popad

					MOV EAX, 0x005903F6
					JMP EAX
				}
			}


			__declspec(naked) void HumanDoWeaponChangeTwo()
			{
				__asm
				{
					PUSH ECX; / Arg2 = 00000000
					PUSH EBP; | Arg1 = 00000000
					MOV ECX, ESI; |
					MOV EAX, 0x0057F550; \Game.0057F550
					CALL EAX

					pushad
						mov ax, word ptr ds : [esi + 0x4A0]
						push ax
						push esi
						call Functions::HumanDoWeaponChange
						add esp, 0x6
					popad

					MOV EAX, 0x00590303 
					JMP EAX
				}
			}
		};

		inline void HookOnHumanHit(std::function<int(MafiaSDK::C_Human*, int, const Vector3D &, const Vector3D &, const Vector3D &, float, MafiaSDK::C_Actor*, unsigned long, MafiaSDK::I3D_Frame*)> functionPointer)
		{
			FunctionsPointers::humanHit = functionPointer;

			MemoryPatcher::InstallJmpHook(0x00507EE1, (unsigned long)&NakedFunctions::HumanHitOne);
			MemoryPatcher::InstallJmpHook(0x00594230, (unsigned long)&NakedFunctions::HumanHitTwo);
		}

		inline void HookOnHumanShoot(std::function<void(const Vector3D &)> functionPointer)
		{
			FunctionsPointers::humanShoot = functionPointer;
			MemoryPatcher::InstallJmpHook(0x00591416, (unsigned long)&NakedFunctions::HumanShoot);
		}

		inline void HookHumanDoWeaponChange(std::function<void(MafiaSDK::C_Human* thisInstance, byte weaponId)> functionPointer)
		{
			FunctionsPointers::humanDoWeaponChange = functionPointer;

			MemoryPatcher::InstallJmpHook(0x005903ED, (unsigned long)&NakedFunctions::HumanDoWeaponChangeOne);
			MemoryPatcher::InstallJmpHook(0x005902FA, (unsigned long)&NakedFunctions::HumanDoWeaponChangeTwo);
		}
#endif
	};
};

#endif