/*
UPDATE:

    2016-01-07	18:03	五行、天干、地支、舌色、十二经脉的枚举类
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

enum FIVE_PHASES    //五行
{
	WOOD, FIRE, EARTH, METAL, WATER
	//NONE, 木, 火, 土, 金, 水
};

enum HEAVENLY_STEMS    //天干
{
	JIA, YI, BING, DING, WU, JI, GENG, XIN, REN, GUI
	//NONE, 甲, 乙, 丙, 丁, 戊, 己, 庚, 辛, 壬, 癸
};

enum EARTHLY_BRANCHES    //地支
{
	ZI, CHOU, YIN, MAO, CHEN, SI, WU_d, WEI, SHEN, YOU, XU, HAI
	//NONE, 子, 丑, 寅, 卯, 辰, 巳, 午, 未, 申, 酉, 戌, 亥
};

enum TWELVE_REGULAR_CHANNELS
{
	TAIYANG_SMALL_INTESTINE_CHANNEL_OF_HAND,//手太阳小肠经
	SHAOYANG_SANJIAO_CHANNEL_OF_HAND,//手少阳三焦经
	YANGMING_LARGE_INTESTINE_CHANNEL_OF_HAND,//手阳明大肠经

	TAIYIN_LUNG_CHANNEL_OF_HAND,//手太阴肺经
	SHAOYIN_HEART_CHANNEL_OF_HAND,//手少阴心经
	JUEYIN_PERICARDIUM_CHANNEL_OF_HAND,//手厥阴心包经

	TAIYANG_BLADDER_CHANNEL_OF_FOOT,//足太阳膀胱经
	SHAOYANG_GALLBLADDER_CHANNEL_OF_FOOT,//足少阳胆经
	YANGMING_STOMACH_CHANNEL_OF_FOOT,//足阳明胃经

	TAIYIN_SPLEEN_CHANNEL_OF_FOOT,//足太阴脾经
	SHAOYIN_KIDNEY_CHANNEL_OF_FOOT,//足少阴肾经
	JUEYIN_LIVER_CHANNEL_OF_FOOT//足厥阴肝经
};

enum TONGUE_COLOR    //舌色
{
//	NONE,
	PALE,    //淡白舌
	PINK,    //淡红舌
	RED,    //红舌
	DEEP_RED,    //绛舌
	PURPLISH,    //紫舌
	GREEN,    //青舌
}; 

/*
class FIVE_EVOLUTIVE_PHASES_AND_SIX_CLIMATIC_FACTORS    //运气
{
private:
	HEAVENLY_STEMS year_t;    //年干
	EARTHLY_BRANCHES year_d;    //年支
	HEAVENLY_STEMS month_t;    //月干
	EARTHLY_BRANCHES month_d;    //月支
	HEAVENLY_STEMS day_t;    //日干
	EARTHLY_BRANCHES day_d;    //日支
	int year;
	int month;
	int day;
	
	FIVE_EVOLUTIVE_PHASES_AND_SIX_CLIMATIC_FACTORS()
	{
		time_t tt = time(NULL);//这句返回的只是一个时间cuo
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
		case JIA: return "甲";
		case YI: return "乙";
		case BING: return "丙";
		case DING: return "丁";
		case WU: return "戊";
		case JI: return "己";
		case GENG: return "庚";
		case XIN: return "辛";
		case REN: return "壬";
		case GUI: return "癸";
		}
	}

	string tostring(EARTHLY_BRANCHES x)
	{
		switch (x)
		{
		case ZI: return "子";
		case CHOU: return "丑";
		case YIN: return "寅";
		case MAO: return "卯";
		case CHEN: return "辰";
		case SI: return "巳";
		case WU_d: return "午";
		case WEI: return "未";
		case SHEN: return "申";
		case YOU: return "酉";
		case XU: return "戌";
		case HAI: return "亥";
		}
	}

	
};
*/


class Ba_Zi    //八字
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
	string toString(HEAVENLY_STEMS const x);//天干转为字符串
	string toString(EARTHLY_BRANCHES const x);//地支转为字符串
	HEAVENLY_STEMS getNianGan();//计算年干
	EARTHLY_BRANCHES getNianZhi();//计算年支
	HEAVENLY_STEMS getYueGan();
	EARTHLY_BRANCHES getYueZhi();

	

public:
	Ba_Zi();//无参构造函数计算当前时间
	Ba_Zi(int year);//计算指定年
	Ba_Zi(int year, int month);//计算指定年月
	Ba_Zi(int year, int month, int day);//计算指定年月日
	Ba_Zi(int year, int month, int day, int hour);//计算指定时间

	

	string printNianGan();//年干输出为字符串
	string printNianZhi();//年支输出为字符串

	HEAVENLY_STEMS Nian_Gan();//年干
	EARTHLY_BRANCHES Nian_Zhi();//年支
	HEAVENLY_STEMS Yue_Gan();//月干
	EARTHLY_BRANCHES Yue_Zhi();//月支
	HEAVENLY_STEMS Ri_Gan();//日干
	EARTHLY_BRANCHES Ri_Zhi();//日支
	HEAVENLY_STEMS Shi_Gan();//时干
	EARTHLY_BRANCHES Shi_Zhi();//时支


};

class Yun_Qi
{
private:
	Yun_Qi();
	Yun_Qi(Ba_Zi x);

public:

};

#endif

