#include "stdafx.h"
#include "LVM.h"

map<pair<CommandTypeType, int>, function<void(const vector<int>&)> > g_CommandRunner;