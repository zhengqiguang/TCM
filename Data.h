#pragma once
#include "basic.h"
class Data//节点数据
{
	friend class Node;
private:
	string name;
	string detail;
public:
	Data(string, string);
};