#include"std.h"
#include"Input.h"

static bool s_currentKeyStates[256] = { false };
//현재 키상태
static bool s_prevKeyStates[256] = { false };

void UpdateInput()
{

}

bool GetButtonDown(Ekeycode keycode)
{
	if (false == s_prevKeyStates[keycode] && _currentkeystates[keycode])
	{
		return true;
	}
}

