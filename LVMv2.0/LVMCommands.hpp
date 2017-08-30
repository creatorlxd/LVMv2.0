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

#define Memory runner.m_Memory.m_pMemory
#define Flag runner.m_Memory.m_pFlag
#define BoolStack runner.m_BoolStack
#define IntStack runner.m_IntStack
#define FloatStack runner.m_FloatStack
#define CharStack runner.m_CharStack

COMMANDTYPE(ExitCommandType, 1, 0, { exit(0); })

COMMANDTYPE(IntCommandType, 2, 2, {
	*(int*)(&runner.m_Memory.m_pMemory[options[0]]) = options[1];
})

COMMANDTYPE(FloatCommmandType, 3, 3, {
	*(float*)(&runner.m_Memory.m_pMemory[options[0]]) = stof(to_string(options[1])+"."+to_string(options[2]));
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

COMMANDTYPE(DefineRefCommandType, 11, 1, {
	Flag[options[0]] = 1;
})

COMMANDTYPE(UndefineRefCommandType, 12, 1, {
	Flag[options[0]] = 0;
})

COMMANDTYPE(PushIntCommandType, 13, 1, {
	IntStack.push(*(int*)(&runner.m_Memory.m_pMemory[options[0]]));
})

COMMANDTYPE(PopIntCommandType, 14, 1, {
	*(int*)(&runner.m_Memory.m_pMemory[options[0]]) = IntStack.top();
	IntStack.pop();
})

COMMANDTYPE(PushFloatCommandType, 15, 1, {
	FloatStack.push(*(float*)(&runner.m_Memory.m_pMemory[options[0]]));
})

COMMANDTYPE(PopFloatCommandType, 16, 1, {
	*(float*)(&runner.m_Memory.m_pMemory[options[0]]) = FloatStack.top();
	FloatStack.pop();
})

COMMANDTYPE(PushCharCommandType, 17, 1, {
	CharStack.push(*(char*)(&runner.m_Memory.m_pMemory[options[0]]));
})

COMMANDTYPE(PopCharCommandType, 18, 1, {
	*(char*)(&runner.m_Memory.m_pMemory[options[0]]) = CharStack.top();
	CharStack.pop();
})

COMMANDTYPE(DefinePointerCommandType, 19, 1, {
	Flag[options[0]] = 2;
})

COMMANDTYPE(UndefinePointerCommandType, 20, 1, {
	Flag[options[0]] = 0;
})

#define PSMDM(commandname,type,dtype,sign)\
COMMANDTYPE(commandname,type,3,{	\
	*(reinterpret_cast<dtype*>(&Memory[options[0]]))=*(reinterpret_cast<dtype*>(&Memory[options[1]]))##sign##(*(reinterpret_cast<dtype*>(&Memory[options[2]])));\
})

PSMDM(IntPlusCommandType, 21, int, +)
PSMDM(IntSubCommandType, 22, int, -)
PSMDM(IntMulCommandType, 23, int, *)
PSMDM(IntDivCommandType, 24, int, / )
PSMDM(IntModCommandType, 25, int, %)

PSMDM(FloatPlusCommandType, 26, float, +)
PSMDM(FloatSubCommandType, 27, float, -)
PSMDM(FloatMulCommandType, 28, float, *)
PSMDM(FloatDivCommandType, 29, float, / )

PSMDM(CharPlusCommandType, 30, char, +)
PSMDM(CharSubCommandType, 31, char, -)
PSMDM(CharMulCommandType, 32, char, *)
PSMDM(CharDivCommandType, 33, char, / )
PSMDM(CharModCommandType, 34, char, %)

COMMANDTYPE(NotCommandType, 35, 2, { *(reinterpret_cast<int*>(&Memory[options[0]])) = ~*(reinterpret_cast<int*>(&Memory[options[1]])); })
PSMDM(AndCommandType,36,int,&)
PSMDM(OrCommandType,37,int,|)
PSMDM(NotOrCommandType,38,int,^)

//TODO:float和int之间&int和char之间的相互转化;三个跳转;if分支&bool stack == < >