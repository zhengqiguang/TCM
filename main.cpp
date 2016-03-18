#include "my_model.h"
#include "DataSet.h"


using namespace std;

int main()
{
	DataSet<double, int> a;
	a.readDataFromFile();
	a.printDataSet();
	cout << a[1][2];
	cout << a.label(1);
	system("pause");
}