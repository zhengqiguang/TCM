#pragma once

#include "LinkListNode.h"

#include "Weight.h"
#include "Node.h"
#include "basic.h"
class LinkListNode;

class LinkList//�ڽӱ���
{
	friend class NetWork;
private:
	int linkListNodeTotal;//�ڵ���Ŀ
	LinkListNode* head;//��ͷָ��

public:
	LinkList();//����
	Node* read(int n) const;//��ȡ��n���ڵ�ָ��
	Status insert(Node*, Weight*);//Ĭ��λ�ò���ָ��Nodeָ����ڽӱ�ڵ�
	Status remove(LinkListNode*);//ɾ��ָ����ڽӱ�ڵ�
	Status clear();//�������
	~LinkList();
	void printLinkList() const;//����ڽӱ��Ա;
};