#pragma once


#include "Node.h"
#include "LinkList.h"
#include "basic.h"



class NetWork
{
private:
	void showNetWorkhelp(Node*, int, Weight*, bool);//������ʾ��������

	void setFlag(Node* node, bool flag);

	void showNode(Node*);//��ʾ�ڵ���"name"

public:
	//int nodeNum, edgeNum;
	//Node* addNode();//����һ��ǰ��Ϊ���Ľڵ�
	//Node* addNode(Node* newNode, Node* node, Weight* weight);//����һ����ַΪnewNode, ǰ��ָ��Ϊnode, Ȩ��Ϊweight�Ľڵ㣬����newNode��ַ

	Node* root;

	NetWork();//���캯��

	int getNodeNum();

	Node* addNode(Node* node, Weight* weight);//����һ��ǰ��ָ��Ϊnode��Ȩ��Ϊweight�Ľڵ㣬�������ַ

	Status add(Node* from, Node* to, Weight* weight);//ͨ�õ���ӽڵ㡢��Ӹ���Ȩֵ

	Status add(Node* from, Node* to, double weight);//ͨ�õ���ӽڵ㡢��Ӹ���Ȩֵ

	Node* add(Node* from, string to, double weight);//����to�Ľڵ��ַ

	void removeLink(Node* from, Node* to);

	bool hasLink(Node* from, Node* to) const;

	Weight* getWeight(Node* from, Node* to) const;

	
	void showChildrenName(Node* node);
	void showNetWork();

};