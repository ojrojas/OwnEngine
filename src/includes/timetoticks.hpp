#ifndef __TIMETOTICKS_H__
#define __TIMETOTICKS_H__

static long TimeToTicks (int hour, int minute, int second)
{
	long num = (long)hour * 3600L + (long)minute * 60L + second;
	if (num > 922337203685L || num < -922337203685L) {
		throw "Exception period long time out range expcetion";
	}
	return num * 10000000;
}

#endif