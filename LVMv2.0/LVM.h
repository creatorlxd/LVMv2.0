#pragma once
#include "stdafx.h"

typedef unsigned char Byte;
typedef Byte CommandTypeType;

extern map<pair<CommandTypeType, int>, function<void(const vector<int>&)> > g_CommandRunner;

#define REGISTERCOMMAND(str) template<CommandTypeType type, int size> \
inline str(){g_CommandRunner.insert(make_pair(make_pair(str::type,str::size),str))}

template<CommandTypeType type,int size>
class BaseCommand
{
public:
	REGISTERCOMMAND(BaseCommand);
	static const CommandTypeType m_Type = type;
	static const int m_Size = size;
};
