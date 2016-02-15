#include "LinkList.h"
LinkList::LinkList()
{
	head = NULL;
	linkListNodeTotal = 0;
}

Node * LinkList::read(int n) const
{
	LinkListNode* p = head;
	while (n--)
	{
		p = p->next;
	}
	return p->nodePtr;
}

Status LinkList::insert(Node *node, Weight* weight)
//默认位置插入指向Node指针的邻接表节点
{
	if (head != NULL)//头指针不指向空
	{
		LinkListNode* p = new LinkListNode(node, weight);
		if (p == NULL)
			return FAIL;
		p->next = head;
		head = p;
		linkListNodeTotal++;
		return SUCCESS;
	}
	else//头指针指向空时，添加第一个节点
	{
		head = new LinkListNode(node, weight);
		if (head == NULL)
			return FAIL;
		linkListNodeTotal++;
		return SUCCESS;
	}
}

Status LinkList::remove(LinkListNode* node)//删除指向的邻接表节点
{
	if (node != head)//被删除节点不是第一个
	{
		LinkListNode* p = head;
		int n = linkListNodeTotal;
		while (p->next != node)//把p指向将删除节点的前一个节点
		{
			p = p->next;
			n--;
			if (n < 0)
				return FAIL;
		}
		p->next = node->next;
		delete node;
		linkListNodeTotal--;
		return SUCCESS;
	}
	else//被删除节点是第一个
	{
		LinkListNode* p = head;
		head = head->next;
		delete p;
		linkListNodeTotal--;
		return SUCCESS;
	}
}

Status LinkList::clear()//清空邻接表
{
	while (linkListNodeTotal > 0)
	{
		remove(head);
		linkListNodeTotal--;
	}
	return SUCCESS;
}

LinkList::~LinkList()
{
	clear();

}

void LinkList::printLinkList() const
{
	//int n = linkListNodeTotal;
	LinkListNode* p = head;
	while (p != NULL)
	{
		cout << p->nodePtr->getName() << " ";
		p = p->next;
	}
}