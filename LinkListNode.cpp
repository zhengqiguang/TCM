#include "LinkListNode.h"
LinkListNode::LinkListNode(Node* nodePtr, Weight* weight)//构建一个邻接表节点，其数据指向节点Node, 权重为weight
{
	this->nodePtr = nodePtr;
	this->weight = weight;
}