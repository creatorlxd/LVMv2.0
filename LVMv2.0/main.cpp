#include "stdafx.h"
#include "LVM.h"
#include "LVMUntility.h"
#include "LVMCommands.hpp"

int main()
{
	LVMRunner System;
	ExternLibray SystemLibray = { make_pair([&](LVMRunner& runner,const vector<int>& options)->void {
		system("pause");
	},0) };
	System.m_ExternLibrary.push_back(SystemLibray);
	System.m_CommandReader.InitFromMemory(vector<Command>{
		Command{4,{1024,10}},			// asc(10) == \n
		Command{ 2,{8,76}},
		Command{2,{0,0}},
		Command{2,{4,0}},
		Command{5,{0}},
		Command{5,{4}},
		Command{54,{0,4,4}},
		Command{48,{8,9,1}},
		Command{10,{8} },
		Command{},
		Command{10,{1024}},
		Command{55,{0,0,16}}
	});
	System.Run();
	system("pause");
	return 0;
}