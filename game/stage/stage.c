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
	assert(STAGE_01 <= level && level < STAGE_MAX); //������

	static char path[MAX_PATH] = { 0 }; //���ϰ�� ���̸� ���� ���ڹ迭

	sprint_s(path, sizeof(path), "Stage/sage%02d", (int32_t)level); // stage -> ���� , save-> ���

	FILE* fp = NULL;
	fopen_s(&fp, path, "r");
	FILE* fp = fopen(path, "r");
	assert(fp != NULL);

	for (size_t i = 0; i < MAP_SIZE; ++i)
	{
		//fprintf_s(fp, "%s", s_currentStage.Map[i], sizeof(s_currentStage.Map[i])); //������ �о���� ����x
		fgets(s_map[i]); //������ �о����
	}

	fclose(fp);
}

const char** GetMap()
{
	return s_currentStage.Map;
}