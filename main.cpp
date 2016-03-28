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

//	cout << "p(gz) = " << nbc.priorProbability["gz"] << endl;
//	cout << "p(headache = y | gz) = " << nbc.posteriorProbability("headache", "y", "gz") << endl;


	vector<string> s = {"头痛", "恶寒", "恶风", "烦躁", "鼻塞", "鼻涕"};

	vector<string> sample = { "y", "y","y","y", "y","y"};
	nbc.m_Estimate();

	cout << "" << nbc.classifier(s, sample);


	system("pause");
}