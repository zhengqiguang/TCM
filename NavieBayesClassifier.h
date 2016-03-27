#pragma once
#include <unordered_map>
#include "DataSet.h"
#include <iostream>
template <class sampleType, class labelType>
class NavieBayesClassifier
{
public:
	unordered_map<labelType, double> priorProbability;//后验概率
	DataSet<sampleType, labelType> dataSet;
	NavieBayesClassifier(const DataSet <sampleType, labelType>& data)
	{
		dataSet = data;
		calculate_Prior_Probability();
	}

	double posteriorProbability(string, sampleType, labelType);//先验概率

private:
	void calculate_Prior_Probability();
};

template<class sampleType, class labelType>
inline double NavieBayesClassifier<sampleType, labelType>::posteriorProbability(string featureName, sampleType sampleName, labelType labelName)
{
	int n = dataSet.exampleNum;
	int d = -1;
	int count = 0;
	for (int i = 0; i < dataSet.dimensionality; ++i)
	{
		if (featureName == dataSet.featureName[i])
		{
			d = i;
			break;
		}
//		else return -1;
	}
	for (int i = 0; i < n; ++i)
	{
		if (dataSet.label(i) == labelName && dataSet[i][d] == sampleName)
		{
			count++;
		}
	}
	return (double)count / priorProbability[labelName] / n;
}

template<class sampleType, class labelType>
inline void NavieBayesClassifier<sampleType, labelType>::calculate_Prior_Probability()
{
	unordered_map <labelType, int> labelCount;
	int n = dataSet.exampleNum;
	for (int i = 0; i < n; ++i)
	{
		labelCount[dataSet.label(i)]++;
	}
	for (auto it = labelCount.begin(); it != labelCount.end(); ++it)
	{
		priorProbability[it->first] = (double)it->second / n;
	}
}


