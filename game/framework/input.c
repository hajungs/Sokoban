#include "std.h"
#include "Input.h"



static bool s_currentKeyStates[256] = { false };
static bool s_prevKeyStates[256] = { false };

bool iskeyDown(int keycode) 
//iskeyDown -> 키가 눌렸는지 떼졌는지 체크하는 함수

{
    // 1001 1001
    // 1000 1000 & 
    // 1000 1000
    if (0x8000 & GetAsyncKeyState(keycode))
     //현재 눌러져있는지 확인하면됨
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

    //모든 키의 상태를 저장하는 것
    for (int keycode = 0; keycode < 256; ++keycode)
    {
        //iskeyDown : 키가 눌렸는지 확인. 눌렸으면 true, 아니면 false
        if (iskeyDown(keycode))
        {
            s_currentKeyStates[keycode] = true;
        }
        else
        {
            s_currentKeyStates[keycode] = false;
        }


        //현재 키의 상태 값을 반환한다.
        //short -> 2byte
        /* 1. 현재 키가 눌렸는지 ⇒ MSB(Most Significant Bit)가 set(1)
        * //따라서 MSB set(1)이면 버튼 눌렀는지
        * 
        *  0x8000 => 0b 1000 0000 0000 0000 => 눌린상태
        *  0x0000 8001 => 0b 1000 0000 0000 0001 => 계속 눌린 상태
        *  0x0001 => 사이엔 눌렸는데 지금은 뗌
        *  0x0000 => 아예 안 눌림
        * 
           2. 현재  키가 떼졌는지⇒ MSB가 0
          많이 사용하진 않음(불확실) ->  3. GetAsyncLeystate() ---- GetAsyncLeystate()
                                  ↑요 사이에 눌렸는지 => LSB set*/


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
bool GetButton(EKeyCode keyCode) //과거에도 눌려져있는지 지금도 눌려져있는지
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