#include "stdafx.h"
#include "LVM.h"
#include "LVMUntility.h"
#include "LVMCommands.hpp"

int main()
{
	LVMRunner System;
	System.m_CommandReader.InitFromMemory(vector<Command>{
		Command{4,{1024,10}},			// asc(10) == \n
		Command{2,{0,4}},
		Command{2,{4,8}},
		Command{3,{8,1,5}},
			Command{ 11,{0} },
			Command{11,{4}},
			Command{8,{0}},
			Command{ 10,{1024} },
			Command{ 12,{ 0 } },
			Command{ 12,{ 4 } },
			Command{19,{4}},
			Command{ 8,{ 4 } },
			Command{ 10,{ 1024 } }
	});
	System.Run();
	system("pause");
	return 0;
}