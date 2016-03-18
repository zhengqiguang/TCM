#pragma once

#include <vector>
/*
Example类，描述数据集中的一条数据
sample向量，是sampleType类型的向量，描述数据中的特征向量X
label变量，描述分类标签Y
*/
template<class sampleType, class labelType>
class Example
{
private:
	vector<sampleType> sample;
	labelType label;
public:
	void readSampleFromFile(fstream& reader, int const dimensionality);
	void readLabelFromFile(fstream& reader);
	void printExample() const;
	Example() {}
	bool setSample(int position, sampleType newSample);//设置position位置的数据为newSample
	bool setLabel(labelType newLabel);//设置label为newLabel
	sampleType getSampleAt(int position) const;//返回position位置的sample数据
	labelType getLabel() const;//返回label

	~Example() {}
};

template<class sampleType, class labelType>
inline void Example<sampleType, labelType>::readSampleFromFile(fstream & reader, int const dimensionality)
{
	for (int i = 0; i < dimensionality; i++)
	{
		sampleType s;
		reader >> s;
		sample.push_back(s);
	}
}

template<class sampleType, class labelType>
inline void Example<sampleType, labelType>::readLabelFromFile(fstream & reader)
{
	reader >> label;
}

template<class sampleType, class labelType>
inline void Example<sampleType, labelType>::printExample() const
{
	int d = sample.size();
	for (int i = 0; i < d; i++)
	{
		cout << sample[i] << '\t';
	}
	cout << "\t\t" << label << endl;
}
