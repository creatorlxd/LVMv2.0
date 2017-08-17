#pragma once
#include "stdafx.h"

typedef unsigned char Byte;
typedef Byte CommandTypeType;

class LVMRunner;

extern map<pair<CommandTypeType, int>, function<void(LVMRunner&,const vector<int>&)> > g_CommandRunner;


#define REGISTERCOMMAND(str)   str(){g_CommandRunner.insert(make_pair(make_pair(m_Type,m_Size),function<void(LVMRunner&,const vector<int>&)>(&Action)));}
#define COMMANDACTION static void Action(LVMRunner& runner,const vector<int>& options)
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

void RunCommand(LVMRunner& runner,CommandTypeType type, int size,const vector<int>& m_Options);

struct Command
{
	CommandTypeType m_Type;
	vector<int> m_Options;
};

void ReadCommandByBinary(fstream& file,Command& c);
void SaveCommandByBinary(fstream& file, const Command& c);