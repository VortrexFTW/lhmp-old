// (C) LHMP Team 2013-2016; Licensed under Apache 2; See LICENSE;;

#ifndef __FILETRANSFER_H
#define __FILETRANSFER_H
#include <vector>
#include "md5lhmp.h"
#include "BitStream.h"


enum FILETRANSFER_STATE
{
	NO_TRANSFER,
	CHECKING_INTEGRITY,
	DOWNLOADING
};
class CFile
{
private:
	unsigned int ID;
	wchar_t name[255];
	FILE* handle;
	wchar_t checksum[33];
	int size;
	int alreadyWritten;
public:
	CFile(unsigned int _ID, FILE* _handle, char _name[], char _checksum[], int _size);
	~CFile();
	wchar_t*		GetName();
	wchar_t*		GetCheckSum();
	int				GetSize();
	unsigned int	GetID();
	FILE*			GetFileHandle();
	void			WriteBytes(unsigned char data[], int len);
	int				GetAlreadyWritten();

	void CloseHandle();
};

class CFileTransfer
{
private:
	int downloadingID;
	int status;
	std::vector <CFile*> fileList;

	// All files which are going to be received together
	int overallBytes;
	// Count of already received bytes (< or == overallBytes)
	int receivedBytes;

	void InitTransfer(RakNet::BitStream* stream);
public:
	CFileTransfer();
	void HandlePacket(RakNet::BitStream* stream);
	void Render();

	void Reset();
};

#endif