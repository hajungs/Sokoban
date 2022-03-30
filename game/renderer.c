#include "std.h"
#include "Render.h"


#define MAP_SIZE 24

static char s_map[MAP_SIZE][MAP_SIZE] = {
    "**",
    " sokodomo  ",
    "**"
};
static HANDLE s_consoleHandle;

//SetConsolePosition �� �����
//GetStdHandle �� �����
bool InitializeRenderer()
{
    s_consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    if (INVALID_HANDLE_VALUE == s_consoleHandle)
    {
        return false;
    }

    CONSOLE_CURSOR_INFO    info;
    info.dwSize = 100;
    info.bVisible = false;

    if (false == SetConsoleCursorInfo(s_consoleHandle, &info))
    {
        return false;
    } 

        return true;
}

//�׾�� ��Ÿ���� ������ �츮������ ȭ�鿡 ������������ ��µǾ� �������� ������ ��Ÿ���°�.
//double buffering�� �̿��Ͽ� ���� �������� back buffer�� �ΰ� ���� ���ۿ� ����ġ�ϴ� �� => �׷��� ȭ���� ����� ������ �پ���.
//�ٽ��� ���۸� �ΰ� ����Ѵ�.
void RenderMap()
{
    const static COORD initialPos = { 0, 0 };
    const static CONSOLE_CURSOR_INFO info = { 100, false };
    SetConsoleCursorPosition(s_consoleHandle, initialPos);
    SetConsoleCursorInfo(s_consoleHandle, &info);

    //memcpy(s_map, s_backBuffer, sizeof(s_map));

    for (int i = 0; i < MAP_SIZE; i++)
    {
        puts(s_map[i]);
    }
}