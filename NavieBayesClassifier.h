#pragma once
#include <unordered_map>
#include <vector>
#include "DataSet.h"
#include <iostream>
template <class sampleType, class labelType>
class NavieBayesClassifier
{
public:
	unordered_map<labelType, double> priorProbability;//先验概率

	unordered_map<labelType, double> labelProbability;

	DataSet<sampleType, labelType> dataSet;

	NavieBayesClassifier(const DataSet <sampleType, labelType>& data)
	{
		dataSet = data;
		calculate_Prior_Probability();
	}

	double posteriorProbability(string, sampleType, labelType);//后验概率

	void m_Estimate();

	labelType classifier(vector<string> featureName, vector<sampleType>);
	
private:
	double classifierHelp(vector<string> featureName, vector<sampleType> sample, labelType labelName);//calculate one probability of one label


	void calculate_Prior_Probability();
};

template<class sampleType, class labelType>
inline double NavieBayesClassifier<sampleType, labelType>::posteriorProbability(string featureName, sampleType sampleName, labelType labelName)
{
	//calculate P(featureName = sampleName | labelName)
	int n = dataSet.exampleNum;
	int d = -1;
	int count = 0;
	for (int i = 0; i < dataSet.dimensionality; ++i)
	{
		//find the position of feature name in the sample
		if (featureName == dataSet.featureName[i])
		{
			d = i;
			break;
		}
//		else return -1;
	}
	for (int i = 0; i < n; ++i)
	{
		//count the number of the right feature name and label name
		if (dataSet.label(i) == labelName && dataSet[i][d] == sampleName)
		{
			count++;
		}
	}
	double r = (double)count / priorProbability[labelName] / n;
//	cout << " P(" << featureName << "=" << sampleName << "|" << labelName << ")=" << r << endl;

	{
		// Laplace's correction
		unordered_map <sampleType, int> number_of_vaule;
		for (int i = 0; i < n; ++i)
		{
			number_of_vaule[dataSet[i][d]]++;
		}
		int nc = number_of_vaule.size();
		r = ((double)count + 1) / (priorProbability[labelName] + nc) / n;
	}

	return r;
}

template<class sampleType, class labelType>
inline void NavieBayesClassifier<sampleType, labelType>::m_Estimate()
{
	int n = dataSet.exampleNum;
	int m = priorProbability.size();
	int nc;
	for (auto it = priorProbability.begin(); it != priorProbability.end(); ++it)
	{
		nc = (int)it->second * n;
		it->second = ((double)nc + 1) / (n + m);
	}
}

template<class sampleType, class labelType>
inline labelType NavieBayesClassifier<sampleType, labelType>::classifier(vector<string> featureName, vector<sampleType> sample)
{
	labelType maxLabel;
	for (auto it = labelProbability.begin(); it != labelProbability.end(); ++it)
	{
		it->second = classifierHelp(featureName, sample, it->first);
	}


	return maxLabel;
}

template<class sampleType, class labelType>
inline double NavieBayesClassifier<sampleType, labelType>::classifierHelp(vector<string> featureName, vector<sampleType> sample, labelType labelName)
{
	//calculate the probability of one label
	int d = featureName.size();
	double p = priorProbability[labelName];

	cout << "P( " << labelName <<" | ";

	for (int i = 0; i < d; ++i)
	{

		p *= posteriorProbability(featureName[i], sample[i], labelName);
		cout << featureName[i] << "==" << sample[i] << ", ";
	}

	cout << "\b\b)= " << p << endl;

	return p;
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
		labelProbability[it->first] = 0;
	}
}


