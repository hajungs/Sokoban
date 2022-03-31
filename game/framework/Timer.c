#include "Timer.h"
#include "std.h"


static clock_t s_prevTick;
static float s_deltaTime;

void InitializeTimer()
{
	s_prevTick = clock();
}

void UpdateTimer()
{

	clock_t currentTick = clock();
	
	//clock_t (long type) CLOCK_PER~ (long type) => ���� ����ȯ �ʿ�
	//deltatime = frame/time
	s_deltaTime = ( currentTick - s_prevTick) / (float)CLOCKS_PER_SEC;

	s_prevTick = currentTick;
}

 
float GetDeltaTime()
{
	return s_deltaTime;
}