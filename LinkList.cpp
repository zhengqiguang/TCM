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
//Ĭ��λ�ò���ָ��Nodeָ����ڽӱ�ڵ�
{
	if (head != NULL)//ͷָ�벻ָ���
	{
		LinkListNode* p = new LinkListNode(node, weight);
		if (p == NULL)
			return FAIL;
		p->next = head;
		head = p;
		linkListNodeTotal++;
		return SUCCESS;
	}
	else//ͷָ��ָ���ʱ����ӵ�һ���ڵ�
	{
		head = new LinkListNode(node, weight);
		if (head == NULL)
			return FAIL;
		linkListNodeTotal++;
		return SUCCESS;
	}
}

Status LinkList::remove(LinkListNode* node)//ɾ��ָ����ڽӱ�ڵ�
{
	if (node != head)//��ɾ���ڵ㲻�ǵ�һ��
	{
		LinkListNode* p = head;
		int n = linkListNodeTotal;
		while (p->next != node)//��pָ��ɾ���ڵ��ǰһ���ڵ�
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
	else//��ɾ���ڵ��ǵ�һ��
	{
		LinkListNode* p = head;
		head = head->next;
		delete p;
		linkListNodeTotal--;
		return SUCCESS;
	}
}

Status LinkList::clear()//����ڽӱ�
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