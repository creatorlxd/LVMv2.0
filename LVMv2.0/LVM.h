#pragma once
#include "stdafx.h"

typedef unsigned char Byte;
typedef Byte CommandTypeType;

extern map<pair<CommandTypeType, int>, function<void(const vector<int>&)> > g_CommandRunner;

#define REGISTERCOMMAND(str)   str(){g_CommandRunner.insert(make_pair(make_pair(m_Type,m_Size),function<void(const vector<int>&)>(&Action)));}
#define COMMANDACTION static void Action(const vector<int>& options)
template<CommandTypeType type,int size>
class BaseCommandType
{
public:
	REGISTERCOMMAND(BaseCommandType);
	static const CommandTypeType m_Type = type;
	static const int m_Size = size;
	
	COMMANDACTION		//command type's action
	{

	}
};

void ThrowError(const string& error);

void RunCommand(CommandTypeType type, int size,const vector<int>& m_Options);

struct Command
{
	CommandTypeType m_Type;
	vector<int> m_Options;
};

void ReadCommandByBinary(fstream& file,Command& c);
void SaveCommandByBinary(fstream& file, const Command& c);