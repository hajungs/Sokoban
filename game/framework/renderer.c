#include "std.h"
#include "Render.h"


#define MAP_SIZE 24

static char s_map[MAP_SIZE][MAP_SIZE];
static HANDLE s_consoleHandle;

void clear()
{
    memset(s_map, ' ', sizeof(s_map));
    // ' ' ������ ���

    for (size_t i = 0; i < MAP_SIZE; ++i)
    {
        s_map[i][MAP_SIZE - 1] = '\0';
        //�츮�� �ϰ� ���� �� [�ܼ� â�� ����� ��]
        
    }

}


bool InitializeRenderer()
{
    s_consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    if (INVALID_HANDLE_VALUE == s_consoleHandle)
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

    const char** stage = GetMap();

    memcpy(s_map, stage, sizeof(s_map));

    /*clock_t tick = clock();*/

   /* sprintf_s(s_map[0], sizeof(s_map[0]), "Delta Time: %f", GetDeltaTime());

    clock_t fps =1 / GetDeltaTime();
    sprintf_s(s_map[1], sizeof(s_map[1]), "FPS : %d", (int32_t)(1 / GetDeltaTime()));
    */
  
    
    // 1: deltaIme = x : 1
   // x = 1/ deltaTime
    
    for (size_t i = 0; i < MAP_SIZE; i++)
    {
        puts(s_map[i]);
    }
    //��� �Ŀ� ���� �������� ����.

    clear();

}

void SetMessage(const char message[24])
{
    strcpy_s(s_map[0], MAP_SIZE, message[24]);
}

//void SetKeyMessage(int keycode)
//{
//    sprintf_s(s_map[0], sizeof(s_map[0]), "%cŰ�� ����", keycode);
//}