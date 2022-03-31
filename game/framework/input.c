#include "std.h"
#include "Input.h"



static bool s_currentKeyStates[256] = { false };
static bool s_prevKeyStates[256] = { false };

bool iskeyDown(int keycode) 
//iskeyDown -> Ű�� ���ȴ��� �������� üũ�ϴ� �Լ�

{
    // 1001 1001
    // 1000 1000 & 
    // 1000 1000
    if (0x8000 & GetAsyncKeyState(keycode))
     //���� �������ִ��� Ȯ���ϸ��
    {
        return true;
    }
    else
    {
        return false;
    }
}


void UpdateInput()
{
    memcpy(s_prevKeyStates, s_currentKeyStates, sizeof(s_prevKeyStates));

    //��� Ű�� ���¸� �����ϴ� ��
    for (int keycode = 0; keycode < 256; ++keycode)
    {
        //iskeyDown : Ű�� ���ȴ��� Ȯ��. �������� true, �ƴϸ� false
        if (iskeyDown(keycode))
        {
            s_currentKeyStates[keycode] = true;
        }
        else
        {
            s_currentKeyStates[keycode] = false;
        }


        //���� Ű�� ���� ���� ��ȯ�Ѵ�.
        //short -> 2byte
        /* 1. ���� Ű�� ���ȴ��� �� MSB(Most Significant Bit)�� set(1)
        * //���� MSB set(1)�̸� ��ư ��������
        * 
        *  0x8000 => 0b 1000 0000 0000 0000 => ��������
        *  0x0000 8001 => 0b 1000 0000 0000 0001 => ��� ���� ����
        *  0x0001 => ���̿� ���ȴµ� ������ ��
        *  0x0000 => �ƿ� �� ����
        * 
           2. ����  Ű�� ���������� MSB�� 0
          ���� ������� ����(��Ȯ��) ->  3. GetAsyncLeystate() ---- GetAsyncLeystate()
                                  ��� ���̿� ���ȴ��� => LSB set*/


    }
}

bool GetButtonDown(EKeyCode keyCode)
{
   /* swich(keycode)
    {
        case W:
            return false == s_isWKeyDownPrev && s_isWKeyDown;
        case S:
            return false == s_isWKeyDownPrev && s_isWKeyDown;
        case A:
            return false == s_isWKeyDownPrev && s_isWKeyDown;
        case D:
            return false == s_isWKeyDownPrev && s_isWKeyDown;
        case Space:


    }*/
    if (false == s_prevKeyStates[keyCode] && false == s_currentKeyStates[keyCode])
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool GetButtonUp(EKeyCode keyCode)
{
    if (false == s_prevKeyStates[keyCode] && s_currentKeyStates[keyCode])
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool GetButton(EKeyCode keyCode) //���ſ��� �������ִ��� ���ݵ� �������ִ���
{
    if (s_prevKeyStates[keyCode] && s_currentKeyStates[keyCode]) 
    {
        return true;
    }
    else
    {
        return false;
    }
}