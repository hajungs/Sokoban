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

 
  
   

   //0.5�� �������� Ư�� �޽����� �����̱�
   
  
   


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
    //Game Loop = �÷��̾�κ����� �Է��� �ϵ����� �и���Ų��.
    //���ۿ� �������α׷��� �����̶�� �˻� ������

    //Game Loop�� ��ü�� Frame
    while (true)
    {

        UpdateTimer();

        //�Է�ó��
        processInput();
        //������Ʈ
        update();
        //������
        render();
    }
    return 0;

}