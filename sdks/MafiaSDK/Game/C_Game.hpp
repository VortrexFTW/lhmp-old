#ifndef _CGAME_H_
#define _CGAME_H_

namespace MafiaSDK
{
	struct C_Game_Interface
	{
		PADDING(C_Game_Interface, _pad0, 0x4C);
		C_Camera mCamera;
		PADDING(C_Game_Interface, _pad1, 0x94);
		C_Player* mLocalPlayer;
	};
	
	namespace C_Game_Enum
	{
		enum FunctionAddresses
		{
			NewExplosion = 0x005AAE10,
			ScoreSet = 0x005B9FE0,
			ScoreSetOn = 0x005B9FA0,
			SetTrafficVisible = 0x5A8470,
			PlayAllSounds = 0x5B85F0,
			PauseAllSounds = 0x5B8430,
			CreateStream = 0x5B6110,
			DestroyStream = 0x5B62C0,
			StreamGetFreeId = 0x5B5E90,
			GetStreamById = 0x5B64C0,
			ScoreEnabled = 0x5B9FA0, 
			SetScore = 0x5B9FE0,
			AddTemporaryActor = 0x5A77C0,
			RemoveTemporaryActor = 0x5A79A0,
			SetCamerRotRepair = 0x005BA010
		};
	};

	namespace C_Game_Hooks
	{
		void HookOnGameTick(std::function<void()> funcitonPointer);
		void HookOnGameInit(std::function<void()> funcitonPointer);
		void HookOnLocalPlayerFallDown(std::function<void()> functionPointer);

#ifdef MAFIA_SDK_IMPLEMENTATION
		namespace FunctionsPointers
		{
			std::function<void()> gameTick;
			std::function<void()> gameInit;
			std::function<void()> localPlayerFallDown;
		};
		
		namespace Functions
		{
			inline void GameTick()
			{
				if(FunctionsPointers::gameTick != nullptr)
					FunctionsPointers::gameTick();
			}

			inline void GameInit()
			{
				if (FunctionsPointers::gameInit != nullptr)
					FunctionsPointers::gameInit();
			}

			inline void LocalPlayerFallDown()
			{
				if (FunctionsPointers::localPlayerFallDown != nullptr)
					FunctionsPointers::localPlayerFallDown();
			}
		};

		namespace NakedFunctions
		{
			__declspec(naked) void GameTick()
			{
				__asm
				{
					pushad
					call Functions::GameTick
					popad

					retn 4
				}
			}
			
			__declspec(naked) void GameInit()
			{
				__asm
				{
					pushad
					call Functions::GameInit
					popad

					retn
				}
			}

			__declspec(naked) void LocalPlayerFallDown()
			{
				__asm
				{
					pushad
						call Functions::LocalPlayerFallDown
					popad

					// 0x0057BAB1
					mov eax, 0x005A545D
					jmp eax
				}
			}
		};

		inline void HookOnGameTick(std::function<void()> funcitonPointer)
		{
			FunctionsPointers::gameTick = funcitonPointer;

			MemoryPatcher::InstallJmpHook(0x005A6D40, (unsigned long)&NakedFunctions::GameTick);
		}

		inline void HookOnGameInit(std::function<void()> functionPointer) 
		{
			FunctionsPointers::gameInit = functionPointer;

			MemoryPatcher::InstallJmpHook(0x005A395B, (unsigned long)&NakedFunctions::GameInit);
		}

		inline void HookLocalPlayerFallDown(std::function<void()> functionPointer)
		{
			FunctionsPointers::localPlayerFallDown = functionPointer;
			MemoryPatcher::InstallJmpHook(0x005A543B, (unsigned long)&NakedFunctions::LocalPlayerFallDown);
		}
#endif
	};

	class C_Game
	{
	public:
		C_Game_Interface* GetInterface()
		{
			return reinterpret_cast<C_Game_Interface*>(this);
		}

		C_Indicators* GetIndicators()
		{
			return reinterpret_cast<C_Indicators*>(C_Indicators_Enum::GIndicators);
		}

		C_Camera* GetCamera()
		{
			return &this->GetInterface()->mCamera;
		}

		C_Player* GetLocalPlayer()
		{
			return this->GetInterface()->mLocalPlayer;
		}
		
		C_BloodManager* GetBloodManager()
		{
			return reinterpret_cast<C_BloodManager*>((unsigned long)this + 0x2D90);
		}
		
		void SetLocalPlayer(C_Player* player)
		{
			this->GetInterface()->mLocalPlayer = player;
		}

		void AddTemporaryActor(C_Actor* actor)
		{
			unsigned long funcAddress = C_Game_Enum::FunctionAddresses::AddTemporaryActor;

			__asm
			{
				push actor
				mov ecx, this
				call funcAddress
			}
		}

		void SetCameraRotRepair()
		{
			unsigned long funcAddress = C_Game_Enum::FunctionAddresses::SetCamerRotRepair;

			__asm
			{
				mov ecx, this
				call funcAddress
			}
		}

		void RemoveTemporaryActor(C_Actor* actor)
		{
			unsigned long funcAddress = C_Game_Enum::FunctionAddresses::RemoveTemporaryActor;

			__asm
			{
				push actor
				mov ecx, this
				call funcAddress
			}
		}
		
		void SetTrafficVisible(BOOL toggle)
		{
			unsigned long funcAddress = C_Game_Enum::FunctionAddresses::SetTrafficVisible;

			__asm
			{
				push toggle
				call funcAddress
			}
		}

		void PlayAllSound(void)
		{	
			unsigned long funcAddress = C_Game_Enum::FunctionAddresses::PlayAllSounds;
			
			__asm
			{
				push 1
				mov ecx, this
				call funcAddress
			}
			
		}

		void PauseAllSound(void)
		{	
			unsigned long funcAddress = C_Game_Enum::FunctionAddresses::PauseAllSounds;
		
			__asm
			{
				mov ecx, this
				call funcAddress
			}
		}


		int CreateStream(const char * streamName)
		{
			
			unsigned long funcAddress = C_Game_Enum::FunctionAddresses::CreateStream;
			unsigned long funcAddressGetId = C_Game_Enum::FunctionAddresses::StreamGetFreeId;
			
			int returnId = -1;

			__asm
			{
				//Get Free Id for stream
				push 0
				mov ecx, this
				call funcAddressGetId
				mov returnId, eax

				//Create stream
				push eax
				push streamName
				mov ecx, this
				call funcAddress
			}

			return returnId;
		}

		unsigned long GetStreamById(int streamId)
		{
			
			unsigned long funcAddress = C_Game_Enum::FunctionAddresses::GetStreamById;
			unsigned long returnAddress = NULL;
			
			__asm
			{
				push streamId
				mov ecx, this
				call funcAddress
				mov returnAddress, eax
			}

			return returnAddress;
		}

		void SetStreamVolume(int streamId, float volume)
		{
			unsigned long streamAddress = GetStreamById(streamId);

			__asm
			{
				push volume
				push esi
				mov ecx, dword ptr ds : [esi]
				call dword ptr ds : [ecx + 0x38]
			}
		}

		void PlayStream(int streamId)
		{
			unsigned long streamAddress = GetStreamById(streamId);

			__asm
			{
				mov esi, streamAddress
				mov eax, dword ptr ds : [esi]
				push esi
				call dword ptr ds : [eax + 14h]
			}

			//Set volume of stream to same value as in options
			float currentMainVolume = *reinterpret_cast<float*>(0x6D4B10);
			SetStreamVolume(streamId, currentMainVolume);
		}

		void PauseStream(int streamId)
		{
			unsigned long streamAddress = GetStreamById(streamId);

			__asm
			{
				mov esi, streamAddress
				mov eax, dword ptr ds : [esi]
				push esi
				call dword ptr ds : [eax + 0x1C]
			}
		}

		void DestroyStream(int streamId)
		{
			
			unsigned long funcAddress = C_Game_Enum::FunctionAddresses::DestroyStream;
			unsigned long streamAddress = GetStreamById(streamId);
			
			__asm
			{
				push streamAddress
				mov ecx, this
				call funcAddress
			}
		}

		void NewExplosion(C_Actor* actor, Vector3D & pos, float radius, float force, BOOL b1, BOOL b2, BOOL b3, int int1)
		{
			unsigned long funcAddr = C_Game_Enum::FunctionAddresses::NewExplosion;

			__asm
			{
				push int1
				push b3
				push b2
				push b1
				push force
				push radius
				push pos
				push actor
				mov ecx, this
				call funcAddr
			}
		}


		void ScoreSet(int score)
		{
			unsigned long funcAddr = C_Game_Enum::FunctionAddresses::ScoreSet;

			__asm
			{
				push score
				mov ecx, this
				call funcAddr
			}
		}

		void ScoreOn(BOOL on)
		{
			unsigned long funcAddr = C_Game_Enum::FunctionAddresses::ScoreSetOn;

			__asm
			{
				push on
				mov ecx, this
				call funcAddr
			}
		}
	};
};

#endif