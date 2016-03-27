#include "my_model.h"
#include "DataSet.h"
#include <string>
#include "NavieBayesClassifier.h"

using namespace std;

int main()
{
	DataSet<string, string> a;
	a.readDataFromFile();
	a.printDataSet();
	NavieBayesClassifier<string, string> nbc(a);

	cout << "p(gg) = " << nbc.priorProbability["gg"] << endl;
	cout << "p(headache = y | gz) = " << nbc.posteriorProbability("headache", "y", "gz") << endl;
//	nbc.printPriorProbability();
//	cout << a[1][2];
//	cout << a.label(1);
	system("pause");
}