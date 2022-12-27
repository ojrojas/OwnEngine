#ifndef __TIMESPAN_H__
#define __TIMESPAN_H__

#include "timetoticks.hpp"

class TimeSpan {
    public:
    TimeSpan()
    {
        _ticks = 0L;
    }
    
    TimeSpan (long ticks)
	{
		_ticks = ticks;
	}

	TimeSpan (int hours, int minutes, int seconds)
	{
		_ticks = TimeToTicks (hours, minutes, seconds);
	}

	TimeSpan (int days, int hours, int minutes, int seconds)
		: TimeSpan (days, hours, minutes, seconds, 0)
	{
	}

	TimeSpan (int days, int hours, int minutes, int seconds, int milliseconds)
	{
		long num = ((long)days * 3600L * 24 + (long)hours * 3600L + (long)minutes * 60L + seconds) * 1000 + milliseconds;
		if (num > 922337203685477L || num < -922337203685477L) {
			throw "Argument null exception, long period out range";
		}
		_ticks = num * 10000;
	}

	long GetValue()
	{
		return _ticks;
	}

    private:
    long _ticks;
};

#endif