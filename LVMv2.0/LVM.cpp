#include "stdafx.h"
#include "LVM.h"

map<pair<CommandTypeType, int>, function<void(const vector<int>&)> > g_CommandRunner;

void ThrowError(const string & error)
{
	cout << error << endl;
	abort();
}

void RunCommand(CommandTypeType type, int size, const vector<int>& options)
{
	auto f = g_CommandRunner.find(make_pair(type, size));
	if (f == g_CommandRunner.end())
	{
		ThrowError("do not have this command type");
		return;
	}
	else
	{
		(*f).second(options);
	}
}
