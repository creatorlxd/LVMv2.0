#include "stdafx.h"
#include "LVM.h"
#include "LVMUntility.h"
#include "LVMCommands.hpp"

int main()
{
	LVMRunner System;
	System.m_CommandReader.InitFromMemory(vector<Command>{
		Command{4,{1024,10}},			// asc(10) == \n
		Command{2,{0,0}},
		Command{2,{4,0}},
			Command{ 5,{0} },
			Command{5,{4}},
			Command{2,{8,0}},
			Command{21,{8,0,4}},
			Command{6,{8}},
			Command{10,{1024}}
	});
	System.Run();
	system("pause");
	return 0;
}