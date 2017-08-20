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
	*(int*)(runner.m_Memory.m_pMemory[options[0]]) = options[1];
})

COMMANDTYPE(FloatCommmandType, 3, 2, {
	*(float*)(runner.m_Memory.m_pMemory[options[0]]) = options[1];
})

COMMANDTYPE(CharCommmandType, 4, 2, {
	*(char*)(runner.m_Memory.m_pMemory[options[0]]) = options[1];
})

