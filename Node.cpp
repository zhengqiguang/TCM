#include "Node.h"
Node::Node()//无参构造，新建邻接表
{
	data = new Data("name?", "detail?");
	inDegree = 0;
	outDegree = 0;
	id = ++nodeCount;
	linklist = new LinkList();
}

Node::Node(string name)//构造带name的节点
{
	data = new Data(name, "detail?");
	inDegree = 0;
	outDegree = 0;
	id = ++nodeCount;
	linklist = new LinkList();
	data->name = name;
}

Node::Node(string name, string detail)//构造带name, detail的节点
{
	data = new Data(name, detail);
	inDegree = 0;
	inDegree = 0;
	outDegree = 0;
	id = ++nodeCount;
	linklist = new LinkList();
	data->name = name;
	data->detail = detail;
}


Data Node::getData() const
{
	return *data;
}

string Node::getName() const
{
	return data->name;
}

string Node::getDetail() const
{
	return data->detail;
}

void Node::setData(Data data)
{
	*(this->data) = data;
}

void Node::setName(string name)
{
	data->name = name;
}

void Node::setDetail(string detail)
{
	data->detail = detail;
}

Node::~Node()
{
	delete linklist;
	delete data;
}
int Node::nodeCount = 0;