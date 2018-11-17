// (C) LHMP Team 2013-2016; Licensed under Apache 2; See LICENSE;;

#ifndef __NETWORK_H
#define __NETWORK_H

#include <stdio.h>
#include <string.h>

typedef void(*callback)(char*);

#include "RakPeerInterface.h"
#include "MessageIdentifiers.h"
#include "BitStream.h"
#include "RakNetTypes.h"
#include "RakSleep.h"
#include "TCPInterface.h"
#include <iostream>
#include "lhmp_structures.h"

#include "FileListTransfer.h"

struct sHttpRequest
{
	int type;
	char buff[400];
	void* callback;
};
class CNetworkManager
{
private:
	RakNet::RakPeerInterface	*peer;
	RakNet::Packet				*packet;
	RakNet::SocketDescriptor	sd;
	wchar_t						CONNECT_IP[100];
	int							CONNECT_PORT;
	wchar_t						CONNECT_PASSWORD[100];
	wchar_t						NickName[100];
	wchar_t						m_pServerName[255];

	bool						isConnected;

	RakNet::FileListTransfer*	transferPlugin;
public:
	CNetworkManager();
	~CNetworkManager();

	// Attemp to connect server
	bool	ConnectServer();

	// Called when server accept our connection
	void	OnConnectionAccepted(RakNet::Packet* packet);
	void	OnConnectionIsAboutFinish();



	void GetConnectInfo();
	void ValidateIP();
	void Pulse();
	void SendServerMessage(RakNet::BitStream*, PacketPriority, PacketReliability, char = 0);
	RakNet::RakPeerInterface* GetPeer();
	wchar_t* GetNick();
	RakNet::RakPeerInterface* ReturnPeer();
	bool IsConnected();

	wchar_t*	GetServerName();

	void httpRequest(int type, char* url, void* callback);

	// Used for loading nickname from Windows Registry system
	void LoadRegistryConfig();
};
#endif