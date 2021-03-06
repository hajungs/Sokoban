#include "std.h"
#include "Game.h"
#include "Render.h"
#include "Input.h"
#include "Timer.h"

bool Initialize()
{
    if (false == InitializeRenderer())
    {
        return false;
    }
    return true;
}


void processInput()
{
    UpdateInput();
}



void update()
{
    static float time = 0.0f;
    static bool message = false;

    time += GetDeltaTime();
    if (time > 0.5f)
    {
        time = 0.0f;
        message = !message;
    }
    if (message)
    {
        printf("hi");
    }

 
  
   

   //0.5초 간격으로 특정 메시지를 깜빡이기
   
  
   


   /* if (GetButton(KEYCODE_W))
    {
        SetKeyMessage(KEYCODE_W);
    }
    else if (GetButton(KEYCODE_D))
    {
        SetKeyMessage(KEYCODE_D);
    }
    else if (GetButton(KEYCODE_S))
    {
        SetKeyMessage(KEYCODE_S);
    }
    else if (GetButton(KEYCODE_A))
    {
        SetKeyMessage(KEYCODE_A);
    }*/

}

void render()
{
    RenderMap();
}

int32_t Run()
{
    //Game Loop = 플레이어로부터의 입력을 하드웨어와 분리시킨다.
    //구글에 게임프로그래밍 패턴이라고 검색 ㄱㄱㄱ

    //Game Loop의 전체를 Frame
    while (true)
    {

        UpdateTimer();

        //입력처리
        processInput();
        //업데이트
        update();
        //렌더링
        render();
    }
    return 0;

}