#pragma once
#include "basic.h"
class Data//�ڵ�����
{
	friend class Node;
private:
	string name;
	string detail;
public:
	Data(string, string);
};