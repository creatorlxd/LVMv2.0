#pragma once
#include "stdafx.h"
#include "LVMUntility.h"

#define COMMANDTYPE(str,type,size,action)\
template<>\
class BaseCommandType<type,size>\
{\
public:\
	static const CommandTypeType m_Type = type;\
	static const int m_Size = size;\
	REGISTERCOMMAND(BaseCommandType)\
	COMMANDACTION \
		action	\
};\
BaseCommandType<type,size> g_##str;

/*
runner
options
*/

COMMANDTYPE(ExitCommandType, 1, 0, { exit(0); })

COMMANDTYPE(IntCommandType, 2, 2, {
	*(int*)(&runner.m_Memory.m_pMemory[options[0]]) = options[1];
})

COMMANDTYPE(FloatCommmandType, 3, 3, {
	float buff=0;
	stringstream ss;
	ss << options[2];
	string strbuff;
	ss >> strbuff;
	strbuff = "0." + strbuff;
	ss << strbuff;
	ss >> buff;
	buff += options[1];
	*(float*)(&runner.m_Memory.m_pMemory[options[0]]) = buff;
})

COMMANDTYPE(CharCommmandType, 4, 2, {
	*(char*)(&runner.m_Memory.m_pMemory[options[0]]) = options[1];
})

COMMANDTYPE(ReadIntCommandType, 5, 1, {
	cin >> *(int*)(&runner.m_Memory.m_pMemory[options[0]]);
})

COMMANDTYPE(PrintIntCommandType, 6, 1, {
	cout<< *(int*)(&runner.m_Memory.m_pMemory[options[0]]);
})

COMMANDTYPE(ReadFloatCommandType, 7, 1, {
	cin >> *(float*)(&runner.m_Memory.m_pMemory[options[0]]);
})

COMMANDTYPE(PrintFloatCommandType, 8, 1, {
	cout << *(float*)(&runner.m_Memory.m_pMemory[options[0]]);
})

COMMANDTYPE(ReadCharCommandType, 9, 1, {
	cin >> *(char*)(&runner.m_Memory.m_pMemory[options[0]]);
})

COMMANDTYPE(PrintCharCommandType, 10, 1, {
	cout << *(char*)(&runner.m_Memory.m_pMemory[options[0]]);
})