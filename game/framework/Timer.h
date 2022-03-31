#pragma once


//타이머를 초기화한다
void InitializeTinmer();

//타이머를 최신화 한다.
void UpdateTimer();


//델타 타임(프레임 간 시간)을 얻는다.
// 프레임 시작 ---- 다음 프레임 시작
        // Δ

float GetDeltaTime();


