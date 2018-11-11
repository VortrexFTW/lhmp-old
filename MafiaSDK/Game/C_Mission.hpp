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

#ifndef _CMISSION_H_
#define _CMISSION_H_

namespace MafiaSDK
{
	namespace C_Mission_Enum
	{
		enum FunctionAddresses
		{
			CLASS_CMISSION = C_MISSION_CLASS,
			CreateActor = 0x53F7D0,
			FindActorByName = 0x00540490
		};

		enum ObjectTypes
		{
			GhostObject = 1,
			Player = 2,
			Car = 4,
			Detector = 5,
			Door = 6,
			Trolley = 8,
			SpecialIDK = 9,
			Bottle = 10,
			TrafficSetup = 12,
			PedestrianSetup = 18,
			Unknown = 20,
			Dog = 21,
			Plane = 22,
			RailRoute = 24,
			Pumpar = 25,
			Enemy = 27,
			RaceCamera = 28,
			Wagons = 30,
			Clocks = 34,
			Physical = 35,
			Truck = 36,
			InitScript = 155
		};
	}

	struct C_Mission_Interface
	{
		PADDING(C_Mission_Interface, _pad0, 0x24);
		C_Game * mGame;
	};
	
	class C_Mission
	{
	public:
		C_Mission_Interface* GetMissionInterface()
		{
			return reinterpret_cast<C_Mission_Interface*>(this);
		}

		C_Game* GetGame()
		{
			return GetMissionInterface()->mGame;
		}

		C_Actor* CreateActor(C_Mission_Enum::ObjectTypes actorType)
		{
			C_Actor* returnActor = nullptr;
			unsigned long funcAddress = C_Mission_Enum::FunctionAddresses::CreateActor;

			__asm
			{
				mov ecx, this
				push actorType
				call funcAddress
				mov returnActor, eax
			}

			return returnActor;
		}

		C_Actor* FindActorByName(const char* actorName)
		{
			C_Actor* returnActor = nullptr;
			unsigned long funcAddress = C_Mission_Enum::FunctionAddresses::FindActorByName;

			__asm
			{
				push actorName
				mov ecx, this
				call funcAddress
				mov returnActor, eax
			}

			return returnActor;
		}
	};

	inline C_Mission* GetMission()
	{
		return *reinterpret_cast<C_Mission**>(C_Mission_Enum::FunctionAddresses::CLASS_CMISSION);
	}
}

#endif