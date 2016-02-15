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
	default:return "?";
	}
}

string Ba_Zi::toString(EARTHLY_BRANCHES const x)
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
	default: return "?";
	}
}
