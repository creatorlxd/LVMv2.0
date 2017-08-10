#pragma once
#include "stdafx.h"
#include "LVM.h"

class Memory
{
public:
	static const int m_Size=0xffffff;
	Byte* m_pMemory;
	Memory();
	~Memory();
	static Memory* GetMainMemory();
	void SetAsMainMemory();
private:
	static Memory* sm_pThis;
};

class CommandReader
{
public:
	CommandReader();
	~CommandReader();
	Command& GetCommand();
	void Goto(int i);
	void InitFromFile(const string& filename);
	bool IfEnd();
private:
	vector<Command> m_Commands;
	int m_CommandListIndex;
};

void SaveCommandToFile(const string& filename, const vector<Command>& commands);

/*
type system:
	three base type:
		int
		char
		float
	three stack
*/

class LVMRunner
{
public:
	void InitFromFile(const string& filename);
	void Run();
private:
	Memory m_Memory;
	CommandReader m_CommandReader;
};