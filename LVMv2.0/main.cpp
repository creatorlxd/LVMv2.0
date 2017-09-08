#include "stdafx.h"
#include "LVM.h"
#include "LVMUntility.h"
#include "LVMCommands.hpp"

int main(int argc,char** argv)
{
	string filename;
	if (argc == 2)
	{
		filename = argv[1];
	}
	else
	{
		cin >> filename;
	}
	LVMRunner System;
	ExternLibray SystemLibray = { make_pair([&](LVMRunner& runner,const vector<int>& options)->void {
		system("pause");
	},0) };
	System.m_ExternLibrary.push_back(SystemLibray);
	System.InitFromFile(filename);
	System.Run();
	system("pause");
	return 0;
}
