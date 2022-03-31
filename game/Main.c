#include "std.h"
#include "framework/Game.h"

int main(void)
{

	if (false == Initialize())
	{
		puts("게임을 로딩하는데 실패했습니다.");

		return 1;
	}

	return Run();
}