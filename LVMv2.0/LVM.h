#pragma once
#include "stdafx.h"

typedef unsigned char Byte;
typedef Byte CommandTypeType;

extern map<pair<CommandTypeType, int>, function<void(const vector<int>&)> > g_CommandRunner;

#define REGISTERCOMMAND(str) template<CommandTypeType type, int size> \
inline str(){g_CommandRunner.insert(make_pair(make_pair(str::type,str::size),str))}

#define COMMANDTYPEACTION template<CommandTypeType type, int size>\
inline void operator()(const vector<int>& m_Options)


template<CommandTypeType type,int size>
class BaseCommandType
{
public:
	REGISTERCOMMAND(BaseCommandType);
	static const CommandTypeType m_Type = type;
	static const int m_Size = size;
	
	COMMANDTYPEACTION		//command type's action
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

void ReadCommandByBinary(fstream& file, Command& c);
void SaveCommandByBinary(fstream& file, Command& c);