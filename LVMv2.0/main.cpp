#include "stdafx.h"
#include "LVM.h"
#include "LVMUntility.h"
#include "LVMCommands.hpp"

int main()
{
	LVMRunner System;
	System.m_CommandReader.InitFromMemory(vector<Command>{
		Command{4,{1024,10}}			// asc(10) == \n
	});
	System.Run();
	system("pause");
	return 0;
}