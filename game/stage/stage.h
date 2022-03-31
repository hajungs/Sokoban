#pragma once

//역할
//1. 스테이지 불러오
//2. 스테이지 현재 상황을 보관
//3. 스테이지가 클리어 됐는지?
// 
//1. 스테이지를 불러와야함
//2. 초기 세팅을 해야함
//1. 플레이어 위치를 알아야 함
//3. 게임 완료도 됐는지를 파악해야 함.

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
///스테이지를 로딩한다.
/// 
/// 

void LoadStage(EStageLevel level);



const char** GetMap();
