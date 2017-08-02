#include "SetUI.h"

/*
	Note:
		SetUI.h helps to know how to use functions.
*/

/*** UI용 함수 정의 ***/
void setWindowSize(int col, int line, char* title)
{
	//콘솔 창 크기 설정
	std::string tempstr = "mode con:cols=";
	tempstr += std::to_string(col);
	tempstr += " lines=";
	tempstr += std::to_string(line);
	const char* tempchar = tempstr.c_str();
	system(tempchar);

	//콘솔 창 제목 설정
	tempstr = "title ";
	tempstr += title;
	const char* tempchar2 = tempstr.c_str();
	system(tempchar2);
}

void setCursor(bool bVisible)
{
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = bVisible; // true 보임, false 안보임
	ConsoleCursor.dwSize = 1; // 커서사이즈
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor); // 설정
}

void setColor(int color_number)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}

void gotoxy(int x, int y)
{
	COORD pos;
	pos.X = x; pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void coutColor(std::string data, int color, int start, int end)
{
	if (start == 0 && end == 0)
	{
		setColor(0x0007);
		setColor(color);
		std::cout << data;
		setColor(0x0007);
		return;
	}

	setColor(0x0007);
	for (int i = 0; i < start; i++)
		std::cout << data[i];
	setColor(color);
	for (int i = start; i <= end; i++)
		std::cout << data[i];
	setColor(0x0007);
	for (int i = end + 1; i < data.length(); i++)
		std::cout << data[i];
}

void coutColor(std::string data, int color, int start, int end, bool enter)
{
	if (start == 0 && end == 0)
	{
		setColor(0x0007);
		setColor(color);
		std::cout << data;
		setColor(0x0007);
		std::cout << std::endl;
		return;
	}

	setColor(0x0007);
	for (int i = 0; i < start; i++)
		std::cout << data[i];
	setColor(color);
	for (int i = start; i <= end; i++)
		std::cout << data[i];
	setColor(0x0007);
	for (int i = end + 1; i < data.length(); i++)
		std::cout << data[i];

	std::cout << std::endl;
}