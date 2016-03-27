#pragma once
#include <unordered_map>
#include "DataSet.h"
#include <iostream>
template <class sampleType, class labelType>
class NavieBayesClassifier
{
public:
	unordered_map <labelType, int> priorProbability;//label count

	DataSet <sampleType, labelType> dataSet;
	NavieBayesClassifier(const DataSet <sampleType, labelType>& data)
	{
		dataSet = data;
	}
	NavieBayesClassifier() {}

	void calculate_Prior_Probability();
	void printPriorProbability();
};

template<class sampleType, class labelType>
inline void NavieBayesClassifier<sampleType, labelType>::calculate_Prior_Probability()
{
	for (int i = 0; i < dataSet.exampleNum; ++i)
	{
		priorProbability[dataSet.label(i)]++;
	}
}

template<class sampleType, class labelType>
inline void NavieBayesClassifier<sampleType, labelType>::printPriorProbability()
{
	cout << priorProbability["1"] << priorProbability["2"] << endl;
}

