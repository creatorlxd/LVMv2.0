#include "stdafx.h"
#include "LVMUntility.h"

Memory* Memory::sm_pThis = nullptr;

Memory::Memory()
{
	m_pMemory = new Byte[m_Size];
	memset(m_pMemory, 0, sizeof(Byte)*m_Size);
	sm_pThis = this;
}

Memory::~Memory()
{
	delete[] m_pMemory;
	if (sm_pThis == this)
	{
		sm_pThis = nullptr;
	}
}

Memory * Memory::GetMainMemory()
{
	return sm_pThis;
}

void Memory::SetAsMainMemory()
{
	sm_pThis = this;
}

CommandReader::CommandReader()
{
	m_CommandListIndex = 0;
}

CommandReader::~CommandReader()
{
}

Command & CommandReader::GetCommand()
{
	if (m_CommandListIndex == m_Commands.size())
	{
		ThrowError("get the end of the commands");
		Goto(0);
		return GetCommand();
	}
	else
	{
		return m_Commands[m_CommandListIndex++];
	}
}

void CommandReader::Goto(int i)
{
	m_CommandListIndex = i;
}

void CommandReader::InitFromFile(const string & filename)
{
	fstream file(filename.c_str(), ios::in | ios::binary);

	int size;
	Command buff;
	file.read((char*)&size, sizeof(int));
	for (int i = 0; i < size; i++)
	{
		ReadCommandByBinary(file, buff);
		m_Commands.push_back(buff);
	}

	file.close();
}

bool CommandReader::IfEnd()
{
	return (m_CommandListIndex==m_Commands.size()?true:false);
}

void SaveCommandToFile(const string & filename, const vector<Command>& commands)
{
	fstream file(filename.c_str(), ios::out | ios::binary);

	int size = commands.size();
	file.write((char*)&size, sizeof(int));

	for (int i = 0; i < size; i++)
	{
		SaveCommandByBinary(file, commands[i]);
	}

	file.close();
}

void LVMRunner::InitFromFile(const string & filename)
{
	m_CommandReader.InitFromFile(filename);
}

void LVMRunner::Run()
{
	while (!m_CommandReader.IfEnd())
	{
		Command& c = m_CommandReader.GetCommand();
		RunCommand(c.m_Type, c.m_Options.size(), c.m_Options);
	}
}
