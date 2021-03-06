#pragma once
#include "stdafx.h"
#include "LVM.h"

class Memory
{
public:
	static const unsigned int m_DefaultSize=0xffffff;
	unsigned int m_Size;
	Byte* m_pMemory;
	short* m_pFlag;
	Memory();
	~Memory();
	void Resize(unsigned int size);

	vector<int> GetIntArray(unsigned int addr);
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
	void InitFromMemory(const vector<Command>& data);
	bool IfEnd();
	int GetIndex();
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
	template<typename T>
	void SetContent(unsigned int addr,const T& content);
	void Invoke(int fa, int num, const vector<int>& options);
public:
	Memory m_Memory;
	CommandReader m_CommandReader;
	stack<bool> m_BoolStack;
	stack<int> m_IntStack;
	stack<float> m_FloatStack;
	stack<char> m_CharStack;
	stack<int> m_LabelStack;
	vector < vector<pair<function<void(LVMRunner&, vector<int>)>,unsigned int>>> m_ExternLibrary;
};
typedef vector<pair<function<void(LVMRunner&, vector<int>)>, unsigned int>> ExternLibray;
template<typename T>
inline void LVMRunner::SetContent(unsigned int addr, const T & content)
{
	memcpy(&m_Memory.m_pMemory[addr], &content, sizeof(T));
}
