#include "LinkListNode.h"
LinkListNode::LinkListNode(Node* nodePtr, Weight* weight)//����һ���ڽӱ�ڵ㣬������ָ��ڵ�Node, Ȩ��Ϊweight
{
	this->nodePtr = nodePtr;
	this->weight = weight;
}