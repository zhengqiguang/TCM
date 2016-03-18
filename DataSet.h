#pragma once

//#include <list>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "Example.h"

/*
DataSet模板类，用于读取，储存文件中的数据

*/

template <class sampleType, class labelType>
class DataSet
{
private:
	int dimensionality = 0;//维度数
	int exampleNum = 0;//样本数
	vector <string> featureName;//
	vector <Example<sampleType, labelType>> example;

	int readFeatureName(fstream&);//读取特征名，返回读取的维度数
	int readExample(fstream&);
public:
	DataSet() {}
	~DataSet() {}
	int readDataFromFile(string filename = "C:\\Users\\Zheng\\Desktop\\test.txt");//读取数据
	void printDataSet();

};



template<class sampleType, class labelType>
inline int DataSet<sampleType, labelType>::readFeatureName(fstream& reader)//读取特征名称，返回成功读取的数量
{
	do
	{
		string t;
		reader >> t;
		featureName.push_back(t);
	} while (reader.get() != '\n');
	int d = featureName.size();
	cout << d << " features found" << endl;
	return d;
}

template<class sampleType, class labelType>
inline int DataSet<sampleType, labelType>::readExample(fstream& reader)//读取数据
{
	int d = dimensionality;
	do
	{
		Example<sampleType, labelType> e;
		e.readSampleFromFile(reader, dimensionality);
		e.readLabelFromFile(reader);
		if (reader.get() == '\n')
		{
			example.push_back(e);
		}
	} while (reader.get() != EOF);
	exampleNum = example.size();
	cout << exampleNum << " examples read" << endl;
	return exampleNum;
}


template<class sampleType, class labelType>
inline int DataSet<sampleType, labelType>::readDataFromFile(string filename)
{
	fstream reader;
	reader.open(filename, ios::in);
	if (reader.fail())
	{
		cout << "file open filed!" << endl;
	}
	cout << "file open succeed" << endl;
	dimensionality = readFeatureName(reader);
	exampleNum = readExample(reader);
	return exampleNum;
}

template<class sampleType, class labelType>
inline void DataSet<sampleType, labelType>::printDataSet()
{
	cout << "printing data set..." << endl;
	for (int i = 0; i < dimensionality; i++)
	{
		cout << featureName[i] << '\t';
	}
	cout << "\t\t" << "Label" << endl;
	for (int i = 0; i < exampleNum; i++)
	{
		example[i].printExample();
	}
	cout << example.size() << " examples printed" << endl;
	cout << endl;
}
