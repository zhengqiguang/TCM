/*
UPDATE:

    2016-01-07	18:03	���С���ɡ���֧����ɫ��ʮ��������ö����
*/
#pragma once
#ifndef __BASIC_H__
#define __BASIC_H__

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>

using namespace std;

enum Status
{
	FAIL, SUCCESS, VISITED, UNVISITED
};

enum FIVE_PHASES    //����
{
	WOOD, FIRE, EARTH, METAL, WATER
	//NONE, ľ, ��, ��, ��, ˮ
};

enum HEAVENLY_STEMS    //���
{
	JIA, YI, BING, DING, WU, JI, GENG, XIN, REN, GUI
	//NONE, ��, ��, ��, ��, ��, ��, ��, ��, ��, ��
};

enum EARTHLY_BRANCHES    //��֧
{
	ZI, CHOU, YIN, MAO, CHEN, SI, WU_d, WEI, SHEN, YOU, XU, HAI
	//NONE, ��, ��, ��, î, ��, ��, ��, δ, ��, ��, ��, ��
};

enum TWELVE_REGULAR_CHANNELS
{
	TAIYANG_SMALL_INTESTINE_CHANNEL_OF_HAND,//��̫��С����
	SHAOYANG_SANJIAO_CHANNEL_OF_HAND,//������������
	YANGMING_LARGE_INTESTINE_CHANNEL_OF_HAND,//�������󳦾�

	TAIYIN_LUNG_CHANNEL_OF_HAND,//��̫���ξ�
	SHAOYIN_HEART_CHANNEL_OF_HAND,//�������ľ�
	JUEYIN_PERICARDIUM_CHANNEL_OF_HAND,//�������İ���

	TAIYANG_BLADDER_CHANNEL_OF_FOOT,//��̫�����׾�
	SHAOYANG_GALLBLADDER_CHANNEL_OF_FOOT,//����������
	YANGMING_STOMACH_CHANNEL_OF_FOOT,//������θ��

	TAIYIN_SPLEEN_CHANNEL_OF_FOOT,//��̫��Ƣ��
	SHAOYIN_KIDNEY_CHANNEL_OF_FOOT,//����������
	JUEYIN_LIVER_CHANNEL_OF_FOOT//�������ξ�
};

enum TONGUE_COLOR    //��ɫ
{
//	NONE,
	PALE,    //������
	PINK,    //������
	RED,    //����
	DEEP_RED,    //���
	PURPLISH,    //����
	GREEN,    //����
}; 

/*
class FIVE_EVOLUTIVE_PHASES_AND_SIX_CLIMATIC_FACTORS    //����
{
private:
	HEAVENLY_STEMS year_t;    //���
	EARTHLY_BRANCHES year_d;    //��֧
	HEAVENLY_STEMS month_t;    //�¸�
	EARTHLY_BRANCHES month_d;    //��֧
	HEAVENLY_STEMS day_t;    //�ո�
	EARTHLY_BRANCHES day_d;    //��֧
	int year;
	int month;
	int day;
	
	FIVE_EVOLUTIVE_PHASES_AND_SIX_CLIMATIC_FACTORS()
	{
		time_t tt = time(NULL);//��䷵�ص�ֻ��һ��ʱ��cuo
		tm* t = localtime(&tt);
		year = t->tm_year + 1900;
		month = t->tm_mon + 1;
		day = t->tm_mday;
		f();
	}

	FIVE_EVOLUTIVE_PHASES_AND_SIX_CLIMATIC_FACTORS(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
		f();
	}

	void f()
	{
		switch (year % 10)
		{
		case 0: year_t = GENG; break;
		case 1: year_t = XIN; break;
		case 2: year_t = REN; break;
		case 3: year_t = GUI; break;
		case 4: year_t = JIA; break;
		case 5: year_t = YI; break;
		case 6: year_t = BING; break;
		case 7: year_t = DING; break;
		case 8: year_t = WU; break;
		case 9: year_t = JI; break;
		}

		switch (year % 12)
		{
		case 0: year_d = SHEN; break;
		case 1: year_d = YOU; break;
		case 2: year_d = XU; break;
		case 3: year_d = HAI; break;
		case 4: year_d = ZI; break;
		case 5: year_d = CHOU; break;
		case 6: year_d = YIN; break;
		case 7: year_d = MAO; break;
		case 8: year_d = CHEN; break;
		case 9: year_d = SI; break;
		case 10: year_d = WU_d; break;
		case 11: year_d = WEI; break;
		}

		switch (year_t)
		{
		case JI: month_t = (HEAVENLY_STEMS)(((int)BING +month -1)%10); break;
		case GENG:month_t = (HEAVENLY_STEMS)(((int)WU + month-1)%10); break;
		case XIN: month_t = (HEAVENLY_STEMS)(((int)GENG + month-1)%10); break;
		case REN: month_t = (HEAVENLY_STEMS)(((int)REN + month-1)%10); break;
		case GUI:month_t = (HEAVENLY_STEMS)(((int)JIA + month-1)%10); break;
		case JIA: month_t = (HEAVENLY_STEMS)(((int)BING + month-1)%10) ; break;
		case YI: month_t = (HEAVENLY_STEMS)(((int)WU + month-1)%10); break;
		case BING:month_t = (HEAVENLY_STEMS)(((int)GENG + month-1)%10) ; break;
		case DING: month_t = (HEAVENLY_STEMS)(((int)REN + month-1)%10); break;
		case WU: month_t = (HEAVENLY_STEMS)(((int)JIA + month-1)%10); break;
		}

		month_d = EARTHLY_BRANCHES(month - 1);

	}

public:
	string tostring(HEAVENLY_STEMS x)
	{
		switch (x)
		{
		case JIA: return "��";
		case YI: return "��";
		case BING: return "��";
		case DING: return "��";
		case WU: return "��";
		case JI: return "��";
		case GENG: return "��";
		case XIN: return "��";
		case REN: return "��";
		case GUI: return "��";
		}
	}

	string tostring(EARTHLY_BRANCHES x)
	{
		switch (x)
		{
		case ZI: return "��";
		case CHOU: return "��";
		case YIN: return "��";
		case MAO: return "î";
		case CHEN: return "��";
		case SI: return "��";
		case WU_d: return "��";
		case WEI: return "δ";
		case SHEN: return "��";
		case YOU: return "��";
		case XU: return "��";
		case HAI: return "��";
		}
	}

	
};
*/


class Ba_Zi    //����
{
private:
	HEAVENLY_STEMS year_t;
	EARTHLY_BRANCHES year_d;
	HEAVENLY_STEMS month_t;
	EARTHLY_BRANCHES month_d;
	HEAVENLY_STEMS day_t;
	EARTHLY_BRANCHES day_d;
	HEAVENLY_STEMS hour_t;
	EARTHLY_BRANCHES hour_d;
	int year;
	int month;
	int day;
	string toString(HEAVENLY_STEMS const x);//���תΪ�ַ���
	string toString(EARTHLY_BRANCHES const x);//��֧תΪ�ַ���
	HEAVENLY_STEMS getNianGan();//�������
	EARTHLY_BRANCHES getNianZhi();//������֧
	HEAVENLY_STEMS getYueGan();
	EARTHLY_BRANCHES getYueZhi();

	

public:
	Ba_Zi();//�޲ι��캯�����㵱ǰʱ��
	Ba_Zi(int year);//����ָ����
	Ba_Zi(int year, int month);//����ָ������
	Ba_Zi(int year, int month, int day);//����ָ��������
	Ba_Zi(int year, int month, int day, int hour);//����ָ��ʱ��

	

	string printNianGan();//������Ϊ�ַ���
	string printNianZhi();//��֧���Ϊ�ַ���

	HEAVENLY_STEMS Nian_Gan();//���
	EARTHLY_BRANCHES Nian_Zhi();//��֧
	HEAVENLY_STEMS Yue_Gan();//�¸�
	EARTHLY_BRANCHES Yue_Zhi();//��֧
	HEAVENLY_STEMS Ri_Gan();//�ո�
	EARTHLY_BRANCHES Ri_Zhi();//��֧
	HEAVENLY_STEMS Shi_Gan();//ʱ��
	EARTHLY_BRANCHES Shi_Zhi();//ʱ֧


};

class Yun_Qi
{
private:
	Yun_Qi();
	Yun_Qi(Ba_Zi x);

public:

};

#endif

