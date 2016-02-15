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
	case JIA: return "¼×";
	case YI: return "ÒÒ";
	case BING: return "±û";
	case DING: return "¶¡";
	case WU: return "Îì";
	case JI: return "¼º";
	case GENG: return "¸ý";
	case XIN: return "ÐÁ";
	case REN: return "ÈÉ";
	case GUI: return "¹ï";
	default:return "?";
	}
}

string Ba_Zi::toString(EARTHLY_BRANCHES const x)
{
	switch (x)
	{
	case ZI: return "×Ó";
	case CHOU: return "³ó";
	case YIN: return "Òú";
	case MAO: return "Ã®";
	case CHEN: return "³½";
	case SI: return "ËÈ";
	case WU_d: return "Îç";
	case WEI: return "Î´";
	case SHEN: return "Éê";
	case YOU: return "ÓÏ";
	case XU: return "Ðç";
	case HAI: return "º¥";
	default: return "?";
	}
}
