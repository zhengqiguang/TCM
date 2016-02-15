#pragma once


#include "Node.h"
#include "LinkList.h"
#include "basic.h"



class NetWork
{
private:
	void showNetWorkhelp(Node*, int, Weight*, bool);//网络显示辅助函数

	void setFlag(Node* node, bool flag);

	void showNode(Node*);//显示节点中"name"

public:
	//int nodeNum, edgeNum;
	//Node* addNode();//增加一个前驱为根的节点
	//Node* addNode(Node* newNode, Node* node, Weight* weight);//增加一个地址为newNode, 前驱指针为node, 权重为weight的节点，返回newNode地址

	Node* root;

	NetWork();//构造函数

	int getNodeNum();

	Node* addNode(Node* node, Weight* weight);//增加一个前驱指针为node，权重为weight的节点，返回其地址

	Status add(Node* from, Node* to, Weight* weight);//通用的添加节点、添加更改权值

	Status add(Node* from, Node* to, double weight);//通用的添加节点、添加更改权值

	Node* add(Node* from, string to, double weight);//返回to的节点地址

	void removeLink(Node* from, Node* to);

	bool hasLink(Node* from, Node* to) const;

	Weight* getWeight(Node* from, Node* to) const;

	
	void showChildrenName(Node* node);
	void showNetWork();

};