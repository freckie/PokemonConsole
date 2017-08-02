#include "App.h"

App::App()
{
	srand((unsigned int)time(NULL));
}

App::~App()
{
	delete[] ldb;
}

void App::run()
{
	loginMenu();
	while (!isExit)
	{
		mainMenu();
	}
}

void App::loginMenu()
{
	string inputname;
	int choose;
	Pokemon* first;

start:
	music.Play_Main();
	system("cls");
	setCursor(false);
	setWindowSize(42, 15, "Pokemon :: Login");
	cout << "┏━━━━━━━━━━━━━━━━━━━┓" << endl;
	cout << "┃                                      ┃" << endl;
	cout << "┃               Pokemon                ┃" << endl;
	cout << "┃                             @ freckie┃" << endl;
	cout << "┗━━━━━━━━━━━━━━━━━━━┛" << endl;
	cout << " # 이름 : ";
	cin >> inputname;
	setCursor(false);

	cout << endl;
	cout << "  # 첫 포켓몬을 선택하세요." << endl;
	cout << "  # 파이리(1) 꼬부기(2) 이상해씨(3)" << endl;
	cout << " >> 입력 : ";
	cin >> choose;
	setCursor(false);

	if (choose == 1)
	{
		cout << "  # 첫 포켓몬을 파이리로 정했습니다!" << endl;
		first = new Fire1();
	}
	else if (choose == 2)
	{
		cout << "  # 첫 포켓몬을 꼬부기로 정했습니다!" << endl;
		first = new Water1();
	}
	else if (choose == 3)
	{
		cout << "  # 첫 포켓몬을 이상해씨로 정했습니다!" << endl;
		first = new Grass1();
	}
	else if (choose == 9)
	{
		cout << "  # 첫 포켓몬을 피카츄로 정했습니다!" << endl;
		first = new Light1();
	}
	else
	{
		cout << "  # 선택 오류." << endl;
		_getch();
		system("cls");
		goto start;
	}
	user.addPokemon(*first);
	user.getMain()->setLevel(1);

	user.setInven(InvenType::medic, 15);
	user.setInven(InvenType::monster, 15);
	user.setName(inputname);

	cout << "  # 아무 키나 눌러 모험을 떠나세요." << endl;
	_getch();
}

void App::mainMenu()
{
	int choose;

	music.Play_Main();

	setCursor(false);
	system("cls");
	setWindowSize(42, 19, "Pokemon :: Main");
	coutColor("━━━━━━━━━━━━━━━━━━━━━", 0x000E, 0, 0, true);
	cout << "    @ 플레이어 : " << user.getName() << " 님" << endl;
	cout << "    @ 플레이어 자금 : " << user.getMoney() << "$" << endl;
	coutColor("━━━━━━━━━━━━━━━━━━━━━", 0x000E, 0, 0, true);
	cout << "    @ 대표 포켓몬 : " << user.getMain()->getName() << "(";
	user.getMain()->printType();
	cout << ")" << endl;
	cout << "    @ 포켓몬 레벨 : Lv. " << user.getMain()->getLevel() << endl;
	cout << "    @ 포켓몬 체력 : [ " << user.getMain()->getHP() << " / " << user.getMain()->getHpMax() << " ]" << endl;
	cout << "    @ 포켓몬 경험치 : [ " << user.getMain()->getExp() << " / " << user.getMain()->getExpMax() << " ]" << endl;
	coutColor("━━━━━━━━━━━━━━━━━━━━━", 0x000E, 0, 0, true);
	cout << "  # 1. 야생으로 떠난다." << endl;
	cout << "  # 2. 나의 포켓몬을 확인한다." << endl;
	cout << "  # 3. 인벤토리를 확인한다." << endl;
	cout << "  # 4. 포켓몬 상점에 들린다." << endl;
	cout << "  # 5. 포켓몬 병원에 들린다." << endl;
	cout << "  # 0. 종료한다." << endl;
	coutColor("━━━━━━━━━━━━━━━━━━━━━", 0x000E, 0, 0, true);
	cout << " >> 선택 : ";
	setCursor(true);
	cin >> choose;
	setCursor(false);

	if (choose == 1)
		while (fieldMenu()) {}
	else if (choose == 2)
		pokeMenu();
	else if (choose == 3)
		invenMenu();
	else if (choose == 4)
		storeMenu();
	else if (choose == 5)
		clinicMenu();
	else if (choose == 0)
		isExit = true;
	else
		cout << "  # 선택 오류." << endl;

	_getch();

}

bool App::fieldMenu() //false면 탐험 끝.
{
	int randnum; //랜덤넘버
	PokemonID pid;
	char chartemp;

	music.Play_Taecho();

	setCursor(false);
	system("cls");
	setWindowSize(42, 23, "Pokemon :: Field");
	coutColor("━━━━━━━━━━━━━━━━━━━━━", 0x000A, 0, 0, true);
	cout << "    @ 플레이어 : " << user.getName() << " 님" << endl;
	coutColor("━━━━━━━━━━━━━━━━━━━━━", 0x000A, 0, 0, true);
	cout << "    @ 대표 포켓몬 : " << user.getMain()->getName() << "(";
	user.getMain()->printType();
	cout << ")" << endl;
	cout << "    @ 포켓몬 레벨 : Lv. " << user.getMain()->getLevel() << endl;
	cout << "    @ 포켓몬 체력 : [ " << user.getMain()->getHP() << " / " << user.getMain()->getHpMax() << " ]" << endl;
	cout << "    @ 포켓몬 경험치 : [ " << user.getMain()->getExp() << " / " << user.getMain()->getExpMax() << " ]" << endl;
	coutColor("━━━━━━━━━━━━━━━━━━━━━", 0x000A, 0, 0, true);

	if (user.getMain()->getDie() == true)
	{
		cout << "  # 대표 포켓몬이 기절 상태입니다." << endl;
		cout << "  # 병원에서 회복시키십시오." << endl;
		return false;
	}

	cout << "  # 야생의 숲 속을 탐험하는 중 ... " << endl;
	cout << "  # 탐험을 멈추려면 아무 키나 눌러주세요." << endl << endl;

	Sleep(1100);

	while (true)
	{
		if (_kbhit() == true)
		{
			cout << "  # 탐험을 중지합니다. " << endl;
			_getch();
			return false;
		}

		randnum = rand() % 100 + 1;

		if (randnum >= 1 && randnum <= PROB_FIND)
		{
			cout << "  # 옆의 풀숲이 들썩입니다." << endl;
			cout << "  # 살펴보려면 Space Bar 눌러주세요." << endl << endl;

			do
			{
				chartemp = _getch();
			} while (chartemp != UI::KEY_SPACE);

			pid = fieldFind();

			if (pid == PokemonID::none)
			{
				cout << "  # 풀숲에 아무 것도 없습니다." << endl;
				cout << endl;
				cout << "  # 아무 키나 눌러 탐험을 계속하세요." << endl;
				_getch();
				return true;
			}

			cout << "  # 야생의 몬스터를 발견했습니다!" << endl;
			cout << endl;
			cout << "  # 아무 키나 눌러 전투를 진행하세요." << endl;
			chartemp = _getch();
			if (chartemp == 'q')
				battleMenu(PokemonID::legend1);
			else if (chartemp == 'w')
				battleMenu(PokemonID::legend2);
			else
				battleMenu(pid);
			return true;
		}
		else
			Sleep(300);
	}
}

void App::pokeMenu()
{
	int choose;

	setCursor(false);
	system("cls");
	setWindowSize(42, 25, "Pokemon :: Pokemon Inventory");
	coutColor("━━━━━━━━━━━━━━━━━━━━━", 0x000D, 0, 0, true);
	cout << "    @ 플레이어 : " << user.getName() << " 님" << endl;
	cout << "    @ 플레이어 자금 : " << user.getMoney() << "$" << endl;
	coutColor("━━━━━━━━━━━━━━━━━━━━━", 0x000D, 0, 0, true);
	cout << "             소유 포켓몬 목록             " << endl;
	coutColor("━━━━━━━━━━━━━━━━━━━━━", 0x000D, 0, 0, true);
	for (int i = 0; i < user.getPokenum(); i++)
	{
		if (user.getPoke(i) == nullptr)
			continue;
		cout << "  # " << i + 1 << ". " << user.getPoke(i)->getName() << " (";
		user.getPoke(i)->printType(); cout << ", Lv. " << user.getPoke(i)->getLevel()
			<< ")" << endl;
		cout << endl;
	}
	cout << endl;
	cout << "  >> 대표 포켓몬 변경 (종료:0) : ";
	setCursor(true);
	cin >> choose;
	setCursor(false);
	if (choose == 0)
		return;
	else if (choose > user.getPokenum())
		return;

	user.setMain(*user.getPoke(choose - 1));
	cout << endl << "  # 변경 완료." << endl;
	cout << "  # 아무 키나 눌러 메뉴로 가세요." << endl;
}

void App::invenMenu()
{
	setCursor(false);
	system("cls");
	setWindowSize(42, 14, "Pokemon :: Item Inventory");
	coutColor("━━━━━━━━━━━━━━━━━━━━━", 0x000D, 0, 0, true);
	cout << "    @ 플레이어 : " << user.getName() << " 님" << endl;
	cout << "    @ 플레이어 자금 : " << user.getMoney() << "$" << endl;
	coutColor("━━━━━━━━━━━━━━━━━━━━━", 0x000D, 0, 0, true);
	cout << "               인벤토리 목록              " << endl;
	coutColor("━━━━━━━━━━━━━━━━━━━━━", 0x000D, 0, 0, true);
	cout << "  # 1. 몬스터볼 : " << user.getInven().monster << "개" << endl;
	cout << "  # 2. 슈퍼볼 : " << user.getInven().super << "개" << endl;
	cout << "  # 3. 마스터볼 : " << user.getInven().master << "개" << endl;
	cout << "  # 4. 치료약 : " << user.getInven().medic << "개" << endl;
	cout << endl;
	cout << "  # 아무 키나 눌러 메뉴로 가세요." << endl;
}

void App::storeMenu()
{
	int choose;

	setCursor(false);
	system("cls");
	setWindowSize(42, 23, "Pokemon :: Pokemon Store");
	coutColor("━━━━━━━━━━━━━━━━━━━━━", 0x0009, 0, 0, true);
	cout << "    @ 플레이어 : " << user.getName() << " 님" << endl;
	cout << "    @ 플레이어 ID : " << user.getID() << endl;
	cout << "    @ 플레이어 자금 : " << user.getMoney() << "$" << endl;
	coutColor("━━━━━━━━━━━━━━━━━━━━━", 0x0009, 0, 0, true);
	cout << "                포켓몬 상점               " << endl;
	coutColor("━━━━━━━━━━━━━━━━━━━━━", 0x0009, 0, 0, true);
	cout << "  # 1. 몬스터볼 구매 (5$)" << endl;
	cout << "  # 2. 슈퍼볼 구매 (15$)" << endl;
	cout << "  # 3. 마스터볼 구매 (35$)" << endl;
	cout << "  # 4. 치료약 구매 (4$)" << endl;
	cout << "  # 5. 포켓몬 판매" << endl; 
	cout << "  # 0. 메뉴로 돌아가기" << endl;
	coutColor("━━━━━━━━━━━━━━━━━━━━━", 0x0009, 0, 0, true);
	cout << "  >> 선택 : ";
	setCursor(true);
	cin >> choose;
	setCursor(false);

	cout << endl; //16줄
	if (choose == 1)
	{
		cout << "  >> 구매할 수량 : ";
		cin >> choose;
		cout << endl;
		if (user.getMoney() < 5 * choose)
			cout << "  # 자금 부족." << endl;
		else
		{
			user.addMoney(-5 * choose);
			cout << "  # 구매 완료." << endl;
		}
	}
	else if (choose == 2)
	{
		cout << "  >> 구매할 수량 : ";
		cin >> choose;
		cout << endl;
		if (user.getMoney() < 15 * choose)
			cout << "  # 자금 부족." << endl;
		else
		{
			user.addMoney(-15 * choose);
			cout << "  # 구매 완료." << endl;
		}
	}
	else if (choose == 3)
	{
		cout << "  >> 구매할 수량 : ";
		cin >> choose;
		cout << endl;
		if (user.getMoney() < 35 * choose)
			cout << "  # 자금 부족." << endl;
		else
		{
			user.addMoney(-35 * choose);
			cout << "  # 구매 완료." << endl;
		}
	}
	else if (choose == 4)
	{
		cout << "  >> 구매할 수량 : ";
		cin >> choose;
		cout << endl;
		if (user.getMoney() < 4 * choose)
			cout << "  # 자금 부족." << endl;
		else
		{
			user.addMoney(-4 * choose);
			cout << "  # 구매 완료." << endl;
		}
	}
	else if (choose == 5)
		sellMenu();
	else if (choose == 0)
		return;
	else
		cout << "  # 선택 오류." << endl;
	cout << endl;
	cout << "  # 아무 키나 눌러 메뉴로 가세요." << endl;
	return;
}

void App::clinicMenu()
{
	char choose;
	int bill;
	bill = (int)((user.getMain()->getHpMax() - user.getMain()->getHP())*(0.06));
	if (bill <= 1) bill = 5;

	setCursor(false);
	system("cls");
	setWindowSize(42, 14, "Pokemon :: Pokemon Clinic");
	coutColor("━━━━━━━━━━━━━━━━━━━━━", 0x000D, 0, 0, true);
	cout << "    @ 플레이어 : " << user.getName() << " 님" << endl;
	cout << "    @ 플레이어 자금 : " << user.getMoney() << "$" << endl;
	coutColor("━━━━━━━━━━━━━━━━━━━━━", 0x000D, 0, 0, true);
	cout << "                포켓몬 병원               " << endl;
	coutColor("━━━━━━━━━━━━━━━━━━━━━", 0x000D, 0, 0, true);
	cout << "  # 대표 포켓몬을 치료하겠습니까 ?" << endl;
	cout << "      (치료 비용 : " << bill + 4 << "$)" << endl;
	cout << "  >> (Y/N) : ";
	setCursor(true);
	cin >> choose;
	setCursor(false);

	cout << endl;
	if (choose == 'y' || choose == 'Y')
	{
		if (user.getMoney() < bill + 4)
		{
			cout << "  # 병원은 봉사기관이 아닙니다." << endl;
			cout << "  # 아무 키나 눌러 돈 들고 다시 오세요." << endl;
		}
		else
		{
			Sleep(1000);
			user.getMain()->setHP(user.getMain()->getHpMax());
			user.addMoney(-bill);
			user.getMain()->setDie(false);
			cout << "  # 치료가 완료되었습니다." << endl;
			cout << "  # 아무 키나 눌러 메뉴로 가세요." << endl;
		}
	}
	else if (choose == 'n' || choose == 'N')
		return;
	else
	{
		cout << "  # 입력 오류!" << endl;
		cout << "  # 아무 키나 눌러 메뉴로 가세요." << endl;
	}
	return;
}

PokemonID App::fieldFind()
{
	int randnum;

	randnum = rand() % 100 + 1;
	if (randnum >= 1 && randnum <= (PROB_1 * 10))
	{
		randnum = rand() % 10 + 1;
		switch (randnum)
		{
		case 1:
			return PokemonID::fire1;
		case 2:
			return PokemonID::water1;
		case 3:
			return PokemonID::grass1;
		case 4:
			return PokemonID::light1;
		case 5:
			return PokemonID::fire2;
		case 6:
			return PokemonID::fire3;
		case 7:
			return PokemonID::water2;
		case 8:
			return PokemonID::water3;
		case 9:
			return PokemonID::grass2;
		case 10:
			return PokemonID::grass3;
		}
	}

	randnum = rand() % 100 + 1;

	if (randnum >= 1 && randnum <= PROB_L * 2)
	{
		randnum = rand() % 2 + 1;
		switch (randnum)
		{
		case 1:
			return PokemonID::legend1;
		case 2:
			return PokemonID::legend2;
		}
	}

	return PokemonID::none;
}

void App::battleMenu(PokemonID _pid)
{
	music.Play_Battle();

	Pokemon* fieldmon;
	int temp, temp2;
	int schoose;
	bool turn = true;	//true : 사용자턴
	bool atkbool; //공격bool
	bool capbool; //포획bool

	//포켓몬 생성
	switch (_pid)
	{
	case PokemonID::fire1:
		fieldmon = new Fire1();
		break;
	case PokemonID::fire2:
		fieldmon = new Fire2();
		break;
	case PokemonID::fire3:
		fieldmon = new Fire3();
		break;
	case PokemonID::water1:
		fieldmon = new Water1();
		break;
	case PokemonID::water2:
		fieldmon = new Water2();
		break;
	case PokemonID::water3:
		fieldmon = new Water3();
		break;
	case PokemonID::grass1:
		fieldmon = new Grass1();
		break;
	case PokemonID::grass2:
		fieldmon = new Grass2();
		break;
	case PokemonID::grass3:
		fieldmon = new Grass3();
		break;
	case PokemonID::light1:
		fieldmon = new Light1();
		break;
	case PokemonID::legend1:
		fieldmon = new Legend1();
		break;
	case PokemonID::legend2:
		fieldmon = new Legend2();
		break;
	}
	//레벨 설정
	temp = rand() % 4; temp2 = rand() % 2;
	if (temp2 == 0)
		fieldmon->setLevel(user.getMain()->getLevel() + temp);
	else
		fieldmon->setLevel(user.getMain()->getLevel() - temp);
	fieldmon->setHP(fieldmon->getHpMax());
	if (fieldmon->getLevel() >= 20)
		fieldmon->evolution();

	if (_pid == PokemonID::legend1 || _pid==PokemonID::legend2)
	{
		fieldmon->setLevel(50);
		fieldmon->evolution();
		fieldmon->evolution();
	}

fight:
	setCursor(false);
	system("cls");
	setWindowSize(42, 29, "Pokemon :: Battle");

	coutColor("━━━━━━━━━━━━━━━━━━━━━", 0x000C, 0, 0, true);
	coutColor("━━━━━━━━━━━━━━━━━━━━━", 0x000C, 0, 0, true);
	cout << "    @ 플레이어 : " << user.getName() << " 님" << endl;
	coutColor("━━━━━━━━━━━━━━━━━━━━━", 0x000C, 0, 0, true);
	cout << "    @ 대표 포켓몬 : " << user.getMain()->getName() << "(";
	user.getMain()->printType(); cout << ")" << endl;
	cout << "    @ 포켓몬 레벨 : Lv. " << user.getMain()->getLevel() << endl;
	cout << "    @ 포켓몬 체력 : [ " << user.getMain()->getHP() << " / " << user.getMain()->getHpMax() << " ]" << endl;
	cout << "    @ 포켓몬 경험치 : [ " << user.getMain()->getExp() << " / " << user.getMain()->getExpMax() << " ]" << endl;
	coutColor("━━━━━━━━━━━━━━━━━━━━━", 0x000C, 0, 0, true);
	cout << "                    vs                  " << endl;
	coutColor("━━━━━━━━━━━━━━━━━━━━━", 0x000C, 0, 0, true);
	cout << "    @ 야생의 포켓몬 : " << fieldmon->getName() << "(";
	fieldmon->printType(); cout << ")" << endl;
	cout << "    @ 포켓몬 레벨 : Lv. " << fieldmon->getLevel() << endl;
	cout << "    @ 포켓몬 체력 : [ " << fieldmon->getHP() << " / " << fieldmon->getHpMax() << " ]" << endl;
	coutColor("━━━━━━━━━━━━━━━━━━━━━", 0x000C, 0, 0, true);
	coutColor("━━━━━━━━━━━━━━━━━━━━━", 0x000C, 0, 0, true);
	cout << "  # 1. " << user.getMain()->skill[0]->getName() << " (공격력 : " <<
		user.getMain()->skill[0]->getDamage() << ")" << endl;
	cout << "  # 2. " << user.getMain()->skill[1]->getName() << " (공격력 : " <<
		user.getMain()->skill[1]->getDamage() << ")" << endl;
	cout << "  # 3. " << user.getMain()->skill[2]->getName() << " (공격력 : " <<
		user.getMain()->skill[2]->getDamage() << ")" << endl;
	cout << "  # 4. 가방 열기" << endl;
	cout << "  # 5. 도망가기" << endl;
	coutColor("━━━━━━━━━━━━━━━━━━━━━", 0x000C, 0, 0, true);

	// 사용자 턴.
	if (turn)
	{
		setCursor(true);
		cout << "  >> 스킬 선택 : ";
		cin >> schoose;

		cout << endl;
		if (schoose >= 1 && schoose <= 3)
		{
			if (schoose > user.getMain()->getEvol())
			{
				cout << "  # 현재 배우지 않은 스킬입니다." << endl;
			}
			else
			{
				atkbool = user.getMain()->skill[schoose - 1]->attack(user.getMain()->getType(), fieldmon);
				if (atkbool)
				{
					coutColor("  # 공격이 성공하였습니다!", 0x000B, 11, 14, true);
					if (fieldmon->getDie() == true)
					{
						if (fieldmon->getPokemonID() == PokemonID::legend1 ||
							fieldmon->getPokemonID() == PokemonID::legend2)
							battleEnd(true, true);
						else
							battleEnd(true, false);
						return;
					}
				}
				else
					coutColor("  # 공격이 실패하였습니다!", 0x000C, 11, 14, true);
			}
		}
		else if (schoose == 4)
		{
			if (user.getPokenum() == 6)
				cout << "  # 포켓몬 가방이 꽉찼습니다." << endl;
			else
			{
				capbool = captureMenu(fieldmon, fieldmon->getHP() / fieldmon->getHpMax());
				if (capbool == true)
					return;
				else
				{
					turn = false;
					goto fight;
				}
			}
		}
		else if (schoose == 5)
		{
			cout << "  # 도망을 시도합니다." << endl;
			Sleep(600);
			temp = rand() % 100 + 1;
			if (temp >= 1 && temp <= PROB_36)
			{
				cout << "  # 도망에 성공하였습니다!" << endl;
				return;
			}
			else
				cout << "  # 도망에 실패하였습니다." << endl;
		}
		else
		{
			cout << "  # 잘못된 입력입니다." << endl;
		}

		cout << "  # 상대의 턴이 시작됩니다." << endl;
		turn = false;
		_getch();
		goto fight;
	}

	// AI 턴.
	else
	{
		cout << endl;

		temp = rand() % fieldmon->getEvol();
		atkbool = fieldmon->skill[temp]->attack(fieldmon->getType(), user.getMain());
		cout << "  # 상대의 " << fieldmon->skill[temp]->getName() << " 공격! " << endl;
		if (atkbool)
		{
			coutColor("  # 상대의 공격이 성공하였습니다!", 0x000C, 19, 22, true);
			if (user.getMain()->getDie() == true)
			{
				battleEnd(false, false);
				return;
			}
		}
		else
			coutColor("  # 상대의 공격이 실패하였습니다!", 0x000B, 19, 22, true);

		cout << "  # 당신의 턴이 시작됩니다." << endl;
		turn = true;
		_getch();
		goto fight;
	}

	_getch();
}

bool App::captureMenu(Pokemon* _mon, double _hpprop)
{
	int choose;
	bool temp;

capture:
	system("cls");
	setWindowSize(42, 21, "Pokemon :: Capture");
	coutColor("━━━━━━━━━━━━━━━━━━━━━", 0x000B, 0, 0, true);
	cout << "    @ 야생의 포켓몬 : " << _mon->getName() << "(";
	_mon->printType(); cout << ")" << endl;
	cout << "    @ 포켓몬 레벨 Lv. : " << _mon->getLevel() << endl;
	cout << "    @ 포켓몬 체력 : [ " << _mon->getHP() << " / " << _mon->getHpMax() << " ]" << endl;
	coutColor("━━━━━━━━━━━━━━━━━━━━━", 0x000B, 0, 0, true);
	cout << "  # 1. 몬스터볼 : " << user.getInven().monster << "개" << endl;
	cout << "  # 2. 슈퍼볼 : " << user.getInven().super << "개" << endl;
	cout << "  # 3. 마스터볼 : " << user.getInven().master << "개" << endl;
	cout << "  # 4. 치료약 : " << user.getInven().medic << "개" << endl;
	coutColor("━━━━━━━━━━━━━━━━━━━━━", 0x000B, 0, 0, true);
	cout << "  >> 입력 : ";
	cin >> choose;

	cout << endl;
	if (choose == 1)
	{
		if (user.getInven().monster <= 0)
		{
			cout << "  # 몬스터볼이 다 떨어졌습니다." << endl;
			_getch();
			return false;
		}
		else
		{
			cout << "  # 몬스터볼을 던졌습니다." << endl;
			Sleep(1600);
			temp = user.capture(*_mon, Ball::Monster);
		}
	}
	else if (choose == 2)
	{
		if (user.getInven().super <= 0)
		{
			cout << "  # 몬스터볼이 다 떨어졌습니다." << endl;
			_getch();
			return false;
		}
		else
		{
			cout << "  # 슈퍼볼을 던졌습니다." << endl;
			Sleep(1200);
			temp = user.capture(*_mon, Ball::Super);
		}
	}
	else if (choose == 3)
	{
		if (user.getInven().master <= 0)
		{
			cout << "  # 몬스터볼이 다 떨어졌습니다." << endl;
			_getch();
			return false;
		}
		else
		{
			cout << "  # 마스터볼을 던졌습니다." << endl;
			Sleep(800);
			temp = user.capture(*_mon, Ball::Master);
		}
	}
	else if (choose == 4)
	{
		if (user.getInven().medic <= 0)
		{
			cout << "  # 치료약이 다 떨어졌습니다." << endl;
			_getch();
			return false;
		}
		else
		{
			cout << "  # 치료약을 사용했습니다." << endl;
			Sleep(500);
			user.getMain()->heal(30);
		}
	}
	else
	{
		cout << "  # 입력 에러! " << endl;
		cout << "  # 아무 키나 눌러 되돌아가세요." << endl;
		_getch();
		goto capture;
	}

	if (temp)
	{
		cout << "  # 포켓몬을 잡았습니다!" << endl;
		cout << "  # 포켓몬 가방에 등록됩니다." << endl << endl;
		cout << "  # 아무 키나 눌러 숲으로 가세요." << endl;
		_getch();
		return true;
	}
	else
	{
		cout << "  # 포켓몬이 탈출하였습니다!" << endl << endl;
		cout << "  # 아무 키나 눌러 숲으로 가세요." << endl;
		_getch();
		return false;
	}
}

void App::battleEnd(bool _win, bool _legend)
{
	int temp = rand() % 31 + 10; //상승할 경험치 비율
	int temp2 = rand() % 94 + 1; //상승할 자금

	if (_legend == true) //전설포켓몬 이겼을경우.
	{
		temp = 80;
		temp2 = 4000;
	}

	_getch();
	system("cls");

	cout << endl;
	if (_win)
	{
		coutColor("  # 전투에서 승리하였습니다!", 0x000B, 14, 17, true);
		cout << "  # 경험치가 " << temp << "% 상승합니다." << endl;
		cout << "  # 자금이 " << temp2 << "$ 상승합니다." << endl;
		user.getMain()->incExpProp(temp);
		user.addMoney(temp2);
	}
	else
		coutColor("  # 전투에서 패배하였습니다.", 0x000C, 14, 17, true);
	
	cout << endl;
	cout << "  # 아무 키나 눌러 숲으로 가세요." << endl;
	_getch();
}

void App::sellMenu()
{
	int choose;

	setCursor(false);
	system("cls");
	setWindowSize(42, 22, "Pokemon :: Pokemon Store");
	coutColor("━━━━━━━━━━━━━━━━━━━━━", 0x0009, 0, 0, true);
	cout << "    @ 플레이어 : " << user.getName() << " 님" << endl;
	cout << "    @ 플레이어 자금 : " << user.getMoney() << "$" << endl;
	coutColor("━━━━━━━━━━━━━━━━━━━━━", 0x0009, 0, 0, true);
	cout << "                포켓몬 판매               " << endl;
	coutColor("━━━━━━━━━━━━━━━━━━━━━", 0x0009, 0, 0, true);
	for (int i = 0; i < user.getPokenum(); i++)
	{
		if (user.getPoke(i) == nullptr)
			continue;
		cout << "  # " << i + 1 << ". " << user.getPoke(i)->getName() << " (";
		user.getPoke(i)->printType(); cout << ", Lv. " << user.getPoke(i)->getLevel()
			<< ")" << endl;
		cout << "    - 판매 가격 : " << user.getPoke(i)->getPrice() << "$" << endl;
		cout << endl;
	}
	coutColor("━━━━━━━━━━━━━━━━━━━━━", 0x0009, 0, 0, true);
	cout << "  >> 선택 (종료:0) : ";
	setCursor(true);
	cin >> choose;
	setCursor(false);
	cout << endl;

	if (choose >= 1 && choose <= user.getPokenum())
	{
		user.sellPokemon(choose - 1);
		cout << "  # 판매 완료." << endl;
	}
	else if (choose == 0)
		return;
	else
		cout << "  # 선택 오류." << endl;
}