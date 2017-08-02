#pragma once

#include<string>
#include<Windows.h>
#include<iostream>

namespace UI
{
	enum
	{
		// Keyboard Events
		ARROW_UP = 72,
		ARROW_DOWN = 80,
		ARROW_LEFT = 75,
		ARROW_RIGHT = 77,
		KEY_SPACE = 32,
		KEY_ESC = 27,
	};
}

/*
	"setColor() Usages"
		0x00#% (# : Background, % : Font Color)
		 0 - 검정색
		 1 - 파랑색
		 2 - 초록색
		 3 - 옥색
		 4 - 빨간색
		 5 - 자주색
		 6 - 노랑색
		 7 - 흰색
		 8 - 회색
		 9 - 연한 파랑색
		 A - 연한 초록색
		 B - 연한 옥색
		 C - 연한 빨간색
		 D - 연한 자주색
		 E - 연한 노랑색
		 F - 밝은 흰색
		default : '0x0007'
*/

/*
	"coutColor() Usage"
		data : Data to Print
		color : Color Number to Set
		start : Starting Index to Set Color
		end : Ending Index to Set Color
		enter : \n After Print (true)

		if 'start=end=0', Print All.
*/

/*** Function Definitions ***/

void setWindowSize(int col, int line, char* title); //col:좌우, line:상하
void setCursor(bool bVisible);
void setColor(int color_number);
void gotoxy(int x, int y);
void coutColor(std::string data, int color, int start, int end);
void coutColor(std::string data, int color, int start, int end, bool enter);
