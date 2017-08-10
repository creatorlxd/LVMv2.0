#pragma once
#include "stdafx.h"
#include "LVMUntility.h"

class ExitCommandType :public BaseCommandType<1, 0>
{
public:
	REGISTERCOMMAND(ExitCommandType);

	COMMANDACTION
	{
		exit(0);
	}
};

