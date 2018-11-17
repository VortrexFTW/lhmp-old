// (C) LHMP Team 2013-2016; Licensed under Apache 2; See LICENSE;;

#include <iostream>
#include <vector>

class CFileSystemCharacter;

class CFileSystemLink
{
private:
	char character;
	CFileSystemCharacter* nextOne;
public:
	CFileSystemLink(char _character)
	{
		character = _character;
		//nextOne = new CFileSystemCharacter;
	}
	char	GetCharacter()
	{
		return character;
	}

	CFileSystemCharacter* GetNext()
	{
		return nextOne;
	}
	void SetNext(CFileSystemCharacter* one)
	{
		this->nextOne = one;
	}
};

class CFileSystemCharacter
{
private:
	wchar_t* aliasString;
	std::vector<CFileSystemLink*> nextList;
	void SetAlias(wchar_t* alias)
	{
		aliasString = new wchar_t[wcslen(alias) + 1];
		wcscpy(aliasString, alias);
	}
public:
	CFileSystemCharacter()
	{
		aliasString = 0;
	}
	~CFileSystemCharacter()
	{
		for (unsigned int i = 0; i < nextList.size(); i++)
		{
			if (nextList[i] != NULL)
			{
				delete nextList[i];
				nextList[i] = NULL;
			}
		}
	}

	void	AddFile(wchar_t* genuieName, wchar_t* alias)
	{
		if (genuieName[0] == 0x0)
		{
			this->SetAlias(alias);
		}
		else 
		{
			for (unsigned int i = 0; i < nextList.size(); i++)
			{
				if (nextList[i]->GetCharacter() == genuieName[0])
				{
					nextList[i]->GetNext()->AddFile(genuieName + 1, alias);
					return;
				}
			}
			CFileSystemLink* link = new CFileSystemLink(genuieName[0]);
			link->SetNext(new CFileSystemCharacter());
			nextList.push_back(link);
			link->GetNext()->AddFile(genuieName + 1, alias);
		}
	}

	// return NULL if there is no link
	wchar_t*	GetFileAlias(wchar_t* genuieName)
	{
		if (genuieName[0] == 0x0)
		{
			return this->aliasString;
		}
		else {
			for (unsigned int i = 0; i < nextList.size(); i++)
			{
				if (nextList[i]->GetCharacter() == genuieName[0])
				{
					/*nextList[i]->GetNext()->AddFile(genuieName + 1, alias);
					return;*/
					return nextList[i]->GetNext()->GetFileAlias(genuieName + 1);
				}
			}
		}
		return NULL;
	}

	void	Delete()
	{
		int len = this->nextList.size();
		for (int i = 0; i < len; i++)
		{
			this->nextList[i]->GetNext()->Delete();

			delete this->nextList[i]->GetNext();
			delete this->nextList[i];
		}
		this->nextList.clear();
		delete[] this->aliasString;
	}

};

class CFileSystem
{
private:
	CFileSystemCharacter		base;
public:
	void  AddFile(wchar_t* genuieName, wchar_t* alias)
	{
		wchar_t test[255];
		wcscpy(test, genuieName);

		int len = wcslen(test);
		for (int i = 0; i < len; i++)
		{
			if (test[i] >= 'A' && test[i] <= 'Z')
			{
				test[i] += 'a' - 'A';
			}
			if (test[i] == '\\')
				test[i] = '/';
		}
		base.AddFile(test, alias);
	}

	wchar_t*	GetFileAliasFromName(wchar_t* file)
	{
		wchar_t test[255];
		wcscpy(test, file);

		int len = wcslen(test);
		for (int i = 0; i < len; i++)
		{
			if (test[i] >= 'A' && test[i] <= 'Z')
			{
				test[i] += 'a' - 'A';
			}
			if (test[i] == '\\')
				test[i] = '/';
		}
		return base.GetFileAlias(test);
	}

	void Reset()
	{
		this->base.Delete();
	}
};