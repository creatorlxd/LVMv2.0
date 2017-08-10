#include "stdafx.h"
#include "LVM.h"

map<pair<CommandTypeType, int>, function<void(const vector<int>&)> > g_CommandRunner;

void ThrowError(const string & error)
{
	cout << error << endl;
	abort();
}

void RunCommand(CommandTypeType type, int size, const vector<int>& m_Options)
{
	auto f = g_CommandRunner.find(make_pair(type, size));
	if (f == g_CommandRunner.end())
	{
		ThrowError("do not have this command type");
		return;
	}
	else
	{
		(*f).second(m_Options);
	}
}

void ReadCommandByBinary(fstream & file,Command & c)
{
	c.m_Options.clear();
	size_t size;
	file.read((char*)&c.m_Type, sizeof(c.m_Type));
	file.read((char*)&size, sizeof(size));
	for (size_t i = 1; i <= size; i++)
	{
		int buff;
		file.read((char*)&buff, sizeof(int));
		c.m_Options.push_back(buff);
	}
}

void SaveCommandByBinary(fstream & file,const Command & c)
{
	size_t size = c.m_Options.size();
	file.write((char*)&c.m_Type, sizeof(c.m_Type));
	file.write((char*)&size, sizeof(size));
	for (int i : c.m_Options)
	{
		file.write((char*)&i, sizeof(int));
	}
}
