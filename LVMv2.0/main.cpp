#include "stdafx.h"
#include "LVM.h"
#include "LVMUntility.h"
#include "LVMCommands.hpp"

int main()
{
	LVMRunner System;
	System.m_CommandReader.InitFromMemory(vector<Command>{
		Command{ 2,{0,1} },
			Command{ 5,{0} },
			Command{ 6,{0} }
	});
	System.Run();
	return 0;
}