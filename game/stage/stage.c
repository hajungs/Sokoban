#include "std.h"
#include "stage.h"
#include "Macro.h"

typedef struct tagstage
{
	char Map[MAP_SIZE][MAP_SIZE];
} Stage;

static Stage s_currentStage;

void LoadStage(EStageLevel level)
{
	assert(STAGE_01 <= level && level < STAGE_MAX); //단정문

	static char path[MAX_PATH] = { 0 }; //파일경로 길이를 받을 문자배열

	sprint_s(path, sizeof(path), "Stage/sage%02d", (int32_t)level); // stage -> 파일 , save-> 경로

	FILE* fp = NULL;
	fopen_s(&fp, path, "r");
	FILE* fp = fopen(path, "r");
	assert(fp != NULL);

	for (size_t i = 0; i < MAP_SIZE; ++i)
	{
		//fprintf_s(fp, "%s", s_currentStage.Map[i], sizeof(s_currentStage.Map[i])); //파일을 읽어오기 공백x
		fgets(s_map[i]); //파일을 읽어오기
	}

	fclose(fp);
}

const char** GetMap()
{
	return s_currentStage.Map;
}