#include "Music.h"


Music::Music()
{
}

Music::~Music()
{
}

void Music::Music_Stop()
{
	PlaySound(NULL, 0, 0);
}

void Music::Play_Main()
{
	if (isPlayingMain) return;
	else
	{
		isPlayingMain = true;
		isPlayingBattle = false;
		isPlayingTaecho = false;
		Music_Stop();
		PlaySound(TEXT(WAV_MAIN), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}
}

void Music::Play_Battle()
{
	if (isPlayingBattle) return;
	else
	{
		isPlayingMain = false;
		isPlayingBattle = true;
		isPlayingTaecho = false;
		Music_Stop();
		PlaySound(TEXT(WAV_BATTLE), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}
}

void Music::Play_Taecho()
{
	if (isPlayingTaecho) return;
	else
	{
		isPlayingMain = false;
		isPlayingBattle = false;
		isPlayingTaecho = true;
		Music_Stop();
		PlaySound(TEXT(WAV_TAECHO), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}
}
