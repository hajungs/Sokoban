#include "Timer.h"
#include "std.h"

time_t _prevTime; // 처음 실행됐을 때 시간

void InitializeTimer() //game.c에서 호출
{
	time(&_prevTime);
}

void UpdateTime()
{
	time_t currentTime;
	time(&)
}




