#include "stdafx.h"
#include "LVM.h"
#include "LVMUntility.h"
#include "LVMCommands.hpp"

int main()
{
	LVMRunner System;
	System.m_CommandReader.InitFromMemory(vector<Command>{
		Command{4,{1024,10}},			// asc(10) == \n
		Command{2,{0,1}},
		Command{3,{4,3,14}},
		Command{4,{8,76}},
		Command{13,{0}},
		Command{15,{4}},
		Command{17,{8}},
		Command{14,{10}},
		Command{16,{14}},
		Command{ 18, {18} },
			Command{ 6,{10} },
			Command{10,{1024}},
			Command{8,{14}},
			Command{10,{1024}},
			Command{10,{18}},
			Command{10,{1024}}
	});
	System.Run();
	system("pause");
	return 0;
}