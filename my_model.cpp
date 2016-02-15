#include "my_model.h"

void NetWork::showNetWorkhelp(Node* node, int level, Weight* weight, bool isroot)
{
	int n = node->outDegree;
	Weight* w = weight;
	int l = level;
	while (l--)
	{
		cout << "---- ";
	}
	this->showNode(node);
	if (isroot)
	{
		cout << endl;
		isroot = false;
	}
	else
	{
		cout << "        weight: " << w->value<< endl;
	}

	if (node->isVisited == true)
	{
		return;
	}
	node->isVisited = true;

	while (n--)
	{
		w = getWeight(node, node->linklist->read(n));
		showNetWorkhelp(node->linklist->read(n), level + 1, w, false);
	}
	setFlag(node, false);
}


void NetWork::setFlag(Node * node, bool flag)
{
	node->isVisited = flag;
}



NetWork::NetWork()
{
	//nodeNum = 0;
	//edgeNum = 0;
	root = new Node("root");
	Node::nodeCount = 0;
}

//Node * NetWork::addNode()//增加一个前驱为根，权值为0的节点
//{
//	return addNode(root, 0);
//}

Node* NetWork::addNode(Node* node, Weight* weight)//增加一个前驱指针为node，权重为weight的节点，返回其地址
{
	Node* p = new Node();
	node->linklist->insert(p, weight);
	//nodeNum++;
	//edgeNum++;
	node->outDegree++;
	p->inDegree++;
	return p;
}

//Node * NetWork::addNode(Node* newNode, Node * node, Weight* weight)
////增加一个前驱指针为node, 权重为weight，地址为newNode的节点，返回newNode地址
//{
//	node->linklist->insert(newNode, weight);
//	//nodeNum++;
//	//edgeNum++;
//	node->outDegree++;
//	newNode->inDegree++;
//	return newNode;
//}

Status NetWork::add(Node * from, Node * to, Weight* weight)
{
	if (from == NULL || to == NULL || weight == NULL)
	{
		return FAIL;
	}
	LinkListNode* p = from->linklist->head;
	while (p != NULL)
	{
		if (p->nodePtr == to)
		{
			from->linklist->remove(p);
			from->outDegree--;
			to->inDegree--;
		}
		p = p->next;
	}
	from->linklist->insert(to, weight);
	from->outDegree++;
	to->inDegree++;
	return SUCCESS;
}

Status NetWork::add(Node * from, Node * to, double weight)
{
	Weight* p = new Weight(weight);
	add(from, to, p);
	return SUCCESS;
}

Node* NetWork::add(Node * from, string to, double weight)//返回to的节点地址
{
	Node* p = new Node(to);
	add(from, p, weight);
	return p;
}


void NetWork::removeLink(Node * from, Node * to)
{
	LinkListNode* p = from->linklist->head;
	while (p != NULL)
	{
		if (p->nodePtr == to)
		{
			from->linklist->remove(p);
			from->outDegree--;
			to->inDegree--;
			return;
		}
		p = p->next;
	}
}

bool NetWork::hasLink(Node *from, Node *to) const
{
	LinkListNode* p = from->linklist->head;
	while (p != NULL)
	{
		if (p->nodePtr == to)
		{
			return true;
		}
		p = p->next;
	}
	return false;
}

Weight* NetWork::getWeight(Node * from, Node * to) const
{
//	Weight weight;
	LinkListNode* p = from->linklist->head;
	while (p != NULL)
	{
		if (p->nodePtr == to)
		{
			return p->weight;
		}
		p = p->next;
	}
	cout << "finding weight fail on:" << from->getName() << "--->" << to->getName() << endl;
	return NULL;
}

void NetWork::showNode(Node *node)
{
	cout << node->getName();
}

void NetWork::showChildrenName(Node * node)
{
	cout <<node->getName() << ":" << endl;
	for (int i = 0; i < node->outDegree; i++)
	{
		cout << "  " << node->linklist->read(i)->getName() << "  weight: "<<node->linklist->read(i)<<endl;
	}
}

void NetWork::showNetWork()
{
	showNetWorkhelp(root, 0, 0, true);
}





