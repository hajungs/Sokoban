#pragma once
#include <stdbool.h>
#include <stdint.h>

typedef enum KeyCode
{
    KEYCODE_W = 'W',
    KEYCODE_A = 'A',
    KEYCODE_S = 'S',
    KEYCODE_D = 'D'
} EKeyCode;

/// <summary>
/// �Է� ���¸� ������Ʈ �Ѵ�.
/// </summary>
void UpdateInput();

/// <summary>
/// ���� �����ӿ� ��ư�� �������� üũ�Ѵ�.
/// </summary>
/// <param name = "keyCode" > ���� Ű �ڵ� </param>
/// <return �����ٸ� true, �ƴϸ� false</return>
bool GetButtonDown(EKeyCode keyCode);

/// <summary>
/// ���� �����ӿ� ��ư�� �������� üũ�Ѵ�.
/// </summary>
/// <param name = "keyCode" > ���� Ű �ڵ� </param>
/// <return �����ٸ� true, �ƴϸ� false</return>
bool GetButtonUp(EKeyCode keyCode);

/// <summary>
/// ��ư�� ��� ���ȴ��� üũ�Ѵ�.
/// </summary>
/// <param name = "keyCode" > ���� Ű �ڵ� </param>
/// <return �����ٸ� true, �ƴϸ� false</return>
bool GetButton(EKeyCode keyCode);
// ���ſ��� �������ִ��� ���ݵ� ���ȴ��� Ȯ���ϴ� �Լ�