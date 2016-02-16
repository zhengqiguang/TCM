#include "basic.h"

HEAVENLY_STEMS Ba_Zi::getNianGan()
{
	return (HEAVENLY_STEMS)((year - 4) % 10);
}

EARTHLY_BRANCHES Ba_Zi::getNianZhi()
{
	return (EARTHLY_BRANCHES)((year - 4) % 12);
}

string Ba_Zi::printNianGan()
{
	return toString(year_t);
}

string Ba_Zi::printNianZhi()
{
	return toString(year_d);
}

Ba_Zi::Ba_Zi(int y)
{
	year = y;
	year_t = getNianGan();
	year_d = getNianZhi();
}

Ba_Zi::Ba_Zi(int y, int m)
{
	year = y;
	month = m;
}

Ba_Zi::Ba_Zi(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}

HEAVENLY_STEMS Ba_Zi::Nian_Gan()
{
	return year_t;
}

EARTHLY_BRANCHES Ba_Zi::Nian_Zhi()
{
	return year_d;
}

HEAVENLY_STEMS Ba_Zi::Yue_Gan()
{
	return month_t;
}

EARTHLY_BRANCHES Ba_Zi::Yue_Zhi()
{
	return month_d;
}

HEAVENLY_STEMS Ba_Zi::Ri_Gan()
{
	return day_t;
}

EARTHLY_BRANCHES Ba_Zi::Ri_Zhi()
{
	return day_d;
}

HEAVENLY_STEMS Ba_Zi::Shi_Gan()
{
	return hour_t;
}

EARTHLY_BRANCHES Ba_Zi::Shi_Zhi()
{
	return hour_d;
}

string Ba_Zi::toString(HEAVENLY_STEMS const x)
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
	default:return "?";
	}
}

string Ba_Zi::toString(EARTHLY_BRANCHES const x)
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
	default: return "?";
	}
}
//testing 不要回答！