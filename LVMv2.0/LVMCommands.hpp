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

COMMANDTYPE(ExitCommandType, 1, 0, { exit(0); })

