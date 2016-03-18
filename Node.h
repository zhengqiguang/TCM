#pragma once

#include "Data.h"
#include "LinkList.h"
#include "basic.h"
class LinkList;
class Node//节点类
{
private:
	Data* data;
public:
	int id;
	//Status isVisited = UNVISITED;
	bool isVisited = false;
	LinkList* linklist;//邻接表指针
	int inDegree;//入度
	int outDegree;//出度
	static int nodeCount;//节点总数

	Node();
	Node(string name);
	Node(string name, string detail);

	Data getData() const;//返回节点数据
	string getName() const;//返回节点数据中的name
	string getDetail() const;//返回节点数据中的detail
	void setData(Data);
	void setName(string);
	void setDetail(string);
	void f();
	~Node();

}; 
