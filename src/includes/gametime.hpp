#ifndef __GAMETIME_H__
#define __GAMETIME_H__

#include <iostream>
#include "timespan.hpp"

class GameTime
{
    TimeSpan _totalGameTime;
    TimeSpan _elapseGameTime;
    bool _isRunningSlowly;

public:
    GameTime();
    GameTime(TimeSpan totalGameTime, TimeSpan elapseGameTime);
    GameTime(TimeSpan totalGameTime, TimeSpan elapseGameTime, bool isRunningSlowly);

    void SetTotalGameTime(TimeSpan timeSpan);
    TimeSpan GetTotalGameTime();

    void SetElapseGameTime(TimeSpan timeSpan);
    TimeSpan GetElapseGameTime();
};

#endif /// __GAMETIME_H__