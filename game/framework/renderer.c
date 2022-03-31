#include "std.h"
#include "Render.h"


#define MAP_SIZE 24

static char s_map[MAP_SIZE][MAP_SIZE];
static HANDLE s_consoleHandle;

void clear()
{
    memset(s_map, ' ', sizeof(s_map));
    // ' ' 공백을 출력

    for (size_t i = 0; i < MAP_SIZE; ++i)
    {
        s_map[i][MAP_SIZE - 1] = '\0';
        //우리가 하고 싶은 건 [콘솔 창을 지우는 것]
        
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

//테어링이 나타나는 현상은 우리가보는 화면에 다음프레임이 출력되어 찢어지는 현상이 나타나는것.
//double buffering을 이용하여 다음 프레임은 back buffer에 두고 현재 버퍼와 스위치하는 것 => 그러면 화면이 끊기는 현상이 줄어든다.
//핵심은 버퍼를 두개 사용한다.

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
    //출력 후에 현재 프레임을 지움.

    clear();

}

void SetMessage(const char message[24])
{
    strcpy_s(s_map[0], MAP_SIZE, message[24]);
}

//void SetKeyMessage(int keycode)
//{
//    sprintf_s(s_map[0], sizeof(s_map[0]), "%c키가 눌림", keycode);
//}