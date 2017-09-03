#include "stdafx.h"
#include "LVM.h"
#include "LVMUntility.h"
#include "LVMCommands.hpp"

int main()
{
	LVMRunner System;
	System.m_CommandReader.InitFromMemory(vector<Command>{
		Command{4,{1024,10}},			// asc(10) == \n
		Command{ 2,{0,76} },
		Command{44,{0,4,4}},
		Command{ 46,{6} },
		Command{6,{0}},
		Command{10,{1024}},
		Command{6,{4}},
		Command{ 10,{ 1024 } },
		Command{47,{}}
	});
	System.Run();
	system("pause");
	return 0;
}