#pragma once

#include "LinkListNode.h"

#include "Weight.h"
#include "Node.h"
#include "basic.h"
class LinkListNode;

class LinkList//邻接表类
{
	friend class NetWork;
private:
	int linkListNodeTotal;//节点数目
	LinkListNode* head;//表头指针

public:
	LinkList();//构建
	Node* read(int n) const;//读取第n个节点指针
	Status insert(Node*, Weight*);//默认位置插入指向Node指针的邻接表节点
	Status remove(LinkListNode*);//删除指向的邻接表节点
	Status clear();//清空链表
	~LinkList();
	void printLinkList() const;//输出邻接表成员;
};