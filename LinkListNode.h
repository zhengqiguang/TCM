#pragma once

#include "Weight.h"
#include "basic.h"
#include "LinkList.h"
#include "Node.h"

class LinkListNode//�ڽӱ�ڵ���
{
	friend class LinkList;
public:
	Node* nodePtr;//ָ��ڵ�
	Weight* weight;//Ȩ��
	LinkListNode* next = NULL;//ָ����һ���ڽӱ�ڵ�
	LinkListNode(Node*, Weight*);//����һ���ڽӱ�ڵ㣬������ָ��ڵ�Node, Ȩ��Ϊweight
};