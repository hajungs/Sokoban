#include "std.h"
#include "Game.h"
#include "Render.h"

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

}

void update()
{


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
        //�Է�ó��
        processInput();
        //������Ʈ
        update();
        //������
        render();
    }

}