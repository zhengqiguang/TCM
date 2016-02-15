#pragma once

#include "Weight.h"
#include "basic.h"
#include "LinkList.h"
#include "Node.h"

class LinkListNode//邻接表节点类
{
	friend class LinkList;
public:
	Node* nodePtr;//指向节点
	Weight* weight;//权重
	LinkListNode* next = NULL;//指向下一个邻接表节点
	LinkListNode(Node*, Weight*);//构建一个邻接表节点，其数据指向节点Node, 权重为weight
};