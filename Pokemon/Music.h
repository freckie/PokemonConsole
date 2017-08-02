#pragma once

#include<Windows.h>

#pragma comment(lib, "winmm.lib")

#define WAV_MAIN "Main.wav"
#define WAV_BATTLE "Battle.wav"
#define WAV_TAECHO "TaechoVil.wav"

class Music
{
public:
	bool isPlayingMain = false;
	bool isPlayingBattle = false;
	bool isPlayingTaecho = false;
	Music();
	~Music();

	void Music_Stop();
	void Play_Main();
	void Play_Battle();
	void Play_Taecho();
};
