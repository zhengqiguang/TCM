#pragma once

#include "Data.h"
#include "LinkList.h"
#include "basic.h"
class LinkList;
class Node//�ڵ���
{
private:
	Data* data;
public:
	int id;
	//Status isVisited = UNVISITED;
	bool isVisited = false;
	LinkList* linklist;//�ڽӱ�ָ��
	int inDegree;//���
	int outDegree;//����
	static int nodeCount;//�ڵ�����

	Node();
	Node(string name);
	Node(string name, string detail);

	Data getData() const;//���ؽڵ�����
	string getName() const;//���ؽڵ������е�name
	string getDetail() const;//���ؽڵ������е�detail
	void setData(Data);
	void setName(string);
	void setDetail(string);
	~Node();

}; 
