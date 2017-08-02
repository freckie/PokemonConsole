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
		 0 - ������
		 1 - �Ķ���
		 2 - �ʷϻ�
		 3 - ����
		 4 - ������
		 5 - ���ֻ�
		 6 - �����
		 7 - ���
		 8 - ȸ��
		 9 - ���� �Ķ���
		 A - ���� �ʷϻ�
		 B - ���� ����
		 C - ���� ������
		 D - ���� ���ֻ�
		 E - ���� �����
		 F - ���� ���
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

void setWindowSize(int col, int line, char* title); //col:�¿�, line:����
void setCursor(bool bVisible);
void setColor(int color_number);
void gotoxy(int x, int y);
void coutColor(std::string data, int color, int start, int end);
void coutColor(std::string data, int color, int start, int end, bool enter);
