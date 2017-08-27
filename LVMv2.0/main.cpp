#include "stdafx.h"
#include "LVM.h"
#include "LVMUntility.h"
#include "LVMCommands.hpp"

int main()
{
	LVMRunner System;
	System.m_CommandReader.InitFromMemory(vector<Command>{
		Command{ 3,{0,1,2} },
			Command{ 8,{0} }
	});
	System.Run();
	return 0;
}