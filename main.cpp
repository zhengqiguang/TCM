#include "my_model.h"
#include "DataSet.h"


using namespace std;

int main()
{
	DataSet<double, int> a;
	a.readDataFromFile();
	a.printDataSet();
	system("pause");
}