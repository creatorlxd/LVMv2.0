#include "stdafx.h"
#include "LVMUntility.h"

Memory* Memory::sm_pThis = nullptr;

Memory::Memory()
{
	m_pMemory = new Byte[m_DefaultSize];
	m_pFlag = new short[m_DefaultSize];
	m_Size = m_DefaultSize;
	memset(m_pMemory, 0, sizeof(Byte)*m_Size);
	memset(m_pFlag, false, sizeof(bool)*m_Size);
}

Memory::~Memory()
{
	delete[] m_pMemory;
	delete[] m_pFlag;
}

void Memory::Resize(unsigned int size)
{
	Byte* buff = new Byte[size];
	short* bbuff = new short[size];
	memcpy(buff, m_pMemory, m_Size * sizeof(Byte));
	memcpy(bbuff, m_pFlag, m_Size * sizeof(short));
	delete[] m_pMemory;
	delete[] m_pFlag;
	m_pMemory = buff;
	m_pFlag = bbuff;
	m_Size = size;
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

	unsigned int size;
	Command buff;
	file.read((char*)&size, sizeof(unsigned int));
	for (int i = 0; i < size; i++)
	{
		ReadCommandByBinary(file, buff);
		m_Commands.push_back(buff);
	}

	file.close();
}

void CommandReader::InitFromMemory(const vector<Command>& data)
{
	m_Commands = data;
}

bool CommandReader::IfEnd()
{
	return (m_CommandListIndex==m_Commands.size()?true:false);
}

void SaveCommandToFile(const string & filename, const vector<Command>& commands)
{
	fstream file(filename.c_str(), ios::out | ios::binary);

	unsigned int size = commands.size();
	file.write((char*)&size, sizeof(unsigned int));

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
		Command c = m_CommandReader.GetCommand();
		//change macro to the normal number
		if (c.m_Type != 11 && c.m_Type != 12&&c.m_Type!=19&&c.m_Type!=20)		// 11 == define macro ; 12 == undefine macro
		{
			int defcount = 0;
			do {
				defcount = 0;
				for (int& i : c.m_Options)
				{
					if (m_Memory.m_pFlag[i]==1)
					{
						i = *(reinterpret_cast<int*>(&m_Memory.m_pMemory[i]));
						defcount += 1;
					}
				}
			} while (defcount > 0);
			for (int& i : c.m_Options)
			{
				if (m_Memory.m_pFlag[i] == 2)
				{
					i = *(reinterpret_cast<int*>(&m_Memory.m_pMemory[i]));
				}
			}
		}
		RunCommand(*this,c.m_Type, c.m_Options.size(), c.m_Options);
	}
}
