#include "my_model.h"
#include "DataSet.h"
#include <string>
#include "NavieBayesClassifier.h"

using namespace std;

int main()
{
	DataSet<double, string> a;
	a.readDataFromFile();
	a.printDataSet();
	NavieBayesClassifier <double, string> nbc(a);
	nbc.calculate_Prior_Probability();
	cout << nbc.priorProbability["1"] << endl;
//	nbc.printPriorProbability();
//	cout << a[1][2];
//	cout << a.label(1);
	system("pause");
}