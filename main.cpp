#include "my_model.h"

using namespace std;

int main()
{
	Ba_Zi a(2016);
	cout << a.printNianGan() << a.printNianZhi() << endl;
	NetWork b;
	Node* p;
	Node* q;
	p = b.add(b.root, "n11", 0.11);
	q = b.add(b.root, "n12", 0.12);
	p = b.add(p, "n21", 0.21);
	
	b.showNetWork();
	system("pause");
}