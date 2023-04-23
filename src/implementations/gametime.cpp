#include "../includes/gametime.hpp"

GameTime::GameTime()
{
    _totalGameTime = TimeSpan(0L);
    _elapseGameTime = TimeSpan(0L);
    _isRunningSlowly = false;
};

GameTime::GameTime(TimeSpan totalGameTime, TimeSpan elapseGameTime)
{
    _totalGameTime = totalGameTime;
    _elapseGameTime = elapseGameTime;
};

GameTime::GameTime(TimeSpan totalGameTime, TimeSpan elapseGameTime, bool isRunningSlowly)
{
    _totalGameTime = totalGameTime;
    _elapseGameTime = elapseGameTime;
    _isRunningSlowly = isRunningSlowly;
};

void GameTime::SetTotalGameTime(TimeSpan timeSpan)
{
    _totalGameTime = timeSpan;
};

TimeSpan GameTime::GetTotalGameTime()
{
    return _totalGameTime;
};

void GameTime::SetElapseGameTime(TimeSpan timeSpan)
{
    _elapseGameTime = timeSpan;
};

TimeSpan GameTime::GetElapseGameTime()
{
    return _elapseGameTime;
};
