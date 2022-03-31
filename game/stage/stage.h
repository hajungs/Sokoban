#pragma once

//����
//1. �������� �ҷ���
//2. �������� ���� ��Ȳ�� ����
//3. ���������� Ŭ���� �ƴ���?
// 
//1. ���������� �ҷ��;���
//2. �ʱ� ������ �ؾ���
//1. �÷��̾� ��ġ�� �˾ƾ� ��
//3. ���� �Ϸᵵ �ƴ����� �ľ��ؾ� ��.

typedef enum MapType
{
	MAPTYP_WALL = '#',
	MAPTYP_PALYER = 'P',
	MAPTYP_BOX = 'a',
	MAPTYP_GOAL = 'O',
	MAPTYP_BOX_ON_GOAL = '@',
	MAPTYP_PATH = ' '

} EMapType;

typedef enum StageLevel
{
	STAGE_01 = 1,
	STAGE_MAX
} EStageLevel;

///<summary>
///���������� �ε��Ѵ�.
/// 
/// 

void LoadStage(EStageLevel level);



const char** GetMap();
