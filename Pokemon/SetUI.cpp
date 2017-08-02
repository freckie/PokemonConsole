#include "SetUI.h"

/*
	Note:
		SetUI.h helps to know how to use functions.
*/

/*** UI�� �Լ� ���� ***/
void setWindowSize(int col, int line, char* title)
{
	//�ܼ� â ũ�� ����
	std::string tempstr = "mode con:cols=";
	tempstr += std::to_string(col);
	tempstr += " lines=";
	tempstr += std::to_string(line);
	const char* tempchar = tempstr.c_str();
	system(tempchar);

	//�ܼ� â ���� ����
	tempstr = "title ";
	tempstr += title;
	const char* tempchar2 = tempstr.c_str();
	system(tempchar2);
}

void setCursor(bool bVisible)
{
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = bVisible; // true ����, false �Ⱥ���
	ConsoleCursor.dwSize = 1; // Ŀ��������
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor); // ����
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