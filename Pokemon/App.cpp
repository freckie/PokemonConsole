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
	cout << "������������������������������������������" << endl;
	cout << "��                                      ��" << endl;
	cout << "��               Pokemon                ��" << endl;
	cout << "��                             @ freckie��" << endl;
	cout << "������������������������������������������" << endl;
	cout << " # �̸� : ";
	cin >> inputname;
	setCursor(false);

	cout << endl;
	cout << "  # ù ���ϸ��� �����ϼ���." << endl;
	cout << "  # ���̸�(1) ���α�(2) �̻��ؾ�(3)" << endl;
	cout << " >> �Է� : ";
	cin >> choose;
	setCursor(false);

	if (choose == 1)
	{
		cout << "  # ù ���ϸ��� ���̸��� ���߽��ϴ�!" << endl;
		first = new Fire1();
	}
	else if (choose == 2)
	{
		cout << "  # ù ���ϸ��� ���α�� ���߽��ϴ�!" << endl;
		first = new Water1();
	}
	else if (choose == 3)
	{
		cout << "  # ù ���ϸ��� �̻��ؾ��� ���߽��ϴ�!" << endl;
		first = new Grass1();
	}
	else if (choose == 9)
	{
		cout << "  # ù ���ϸ��� ��ī��� ���߽��ϴ�!" << endl;
		first = new Light1();
	}
	else
	{
		cout << "  # ���� ����." << endl;
		_getch();
		system("cls");
		goto start;
	}
	user.addPokemon(*first);
	user.getMain()->setLevel(1);

	user.setInven(InvenType::medic, 15);
	user.setInven(InvenType::monster, 15);
	user.setName(inputname);

	cout << "  # �ƹ� Ű�� ���� ������ ��������." << endl;
	_getch();
}

void App::mainMenu()
{
	int choose;

	music.Play_Main();

	setCursor(false);
	system("cls");
	setWindowSize(42, 19, "Pokemon :: Main");
	coutColor("������������������������������������������", 0x000E, 0, 0, true);
	cout << "    @ �÷��̾� : " << user.getName() << " ��" << endl;
	cout << "    @ �÷��̾� �ڱ� : " << user.getMoney() << "$" << endl;
	coutColor("������������������������������������������", 0x000E, 0, 0, true);
	cout << "    @ ��ǥ ���ϸ� : " << user.getMain()->getName() << "(";
	user.getMain()->printType();
	cout << ")" << endl;
	cout << "    @ ���ϸ� ���� : Lv. " << user.getMain()->getLevel() << endl;
	cout << "    @ ���ϸ� ü�� : [ " << user.getMain()->getHP() << " / " << user.getMain()->getHpMax() << " ]" << endl;
	cout << "    @ ���ϸ� ����ġ : [ " << user.getMain()->getExp() << " / " << user.getMain()->getExpMax() << " ]" << endl;
	coutColor("������������������������������������������", 0x000E, 0, 0, true);
	cout << "  # 1. �߻����� ������." << endl;
	cout << "  # 2. ���� ���ϸ��� Ȯ���Ѵ�." << endl;
	cout << "  # 3. �κ��丮�� Ȯ���Ѵ�." << endl;
	cout << "  # 4. ���ϸ� ������ �鸰��." << endl;
	cout << "  # 5. ���ϸ� ������ �鸰��." << endl;
	cout << "  # 0. �����Ѵ�." << endl;
	coutColor("������������������������������������������", 0x000E, 0, 0, true);
	cout << " >> ���� : ";
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
		cout << "  # ���� ����." << endl;

	_getch();

}

bool App::fieldMenu() //false�� Ž�� ��.
{
	int randnum; //�����ѹ�
	PokemonID pid;
	char chartemp;

	music.Play_Taecho();

	setCursor(false);
	system("cls");
	setWindowSize(42, 23, "Pokemon :: Field");
	coutColor("������������������������������������������", 0x000A, 0, 0, true);
	cout << "    @ �÷��̾� : " << user.getName() << " ��" << endl;
	coutColor("������������������������������������������", 0x000A, 0, 0, true);
	cout << "    @ ��ǥ ���ϸ� : " << user.getMain()->getName() << "(";
	user.getMain()->printType();
	cout << ")" << endl;
	cout << "    @ ���ϸ� ���� : Lv. " << user.getMain()->getLevel() << endl;
	cout << "    @ ���ϸ� ü�� : [ " << user.getMain()->getHP() << " / " << user.getMain()->getHpMax() << " ]" << endl;
	cout << "    @ ���ϸ� ����ġ : [ " << user.getMain()->getExp() << " / " << user.getMain()->getExpMax() << " ]" << endl;
	coutColor("������������������������������������������", 0x000A, 0, 0, true);

	if (user.getMain()->getDie() == true)
	{
		cout << "  # ��ǥ ���ϸ��� ���� �����Դϴ�." << endl;
		cout << "  # �������� ȸ����Ű�ʽÿ�." << endl;
		return false;
	}

	cout << "  # �߻��� �� ���� Ž���ϴ� �� ... " << endl;
	cout << "  # Ž���� ���߷��� �ƹ� Ű�� �����ּ���." << endl << endl;

	Sleep(1100);

	while (true)
	{
		if (_kbhit() == true)
		{
			cout << "  # Ž���� �����մϴ�. " << endl;
			_getch();
			return false;
		}

		randnum = rand() % 100 + 1;

		if (randnum >= 1 && randnum <= PROB_FIND)
		{
			cout << "  # ���� Ǯ���� ����Դϴ�." << endl;
			cout << "  # ���캸���� Space Bar �����ּ���." << endl << endl;

			do
			{
				chartemp = _getch();
			} while (chartemp != UI::KEY_SPACE);

			pid = fieldFind();

			if (pid == PokemonID::none)
			{
				cout << "  # Ǯ���� �ƹ� �͵� �����ϴ�." << endl;
				cout << endl;
				cout << "  # �ƹ� Ű�� ���� Ž���� ����ϼ���." << endl;
				_getch();
				return true;
			}

			cout << "  # �߻��� ���͸� �߰��߽��ϴ�!" << endl;
			cout << endl;
			cout << "  # �ƹ� Ű�� ���� ������ �����ϼ���." << endl;
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
	coutColor("������������������������������������������", 0x000D, 0, 0, true);
	cout << "    @ �÷��̾� : " << user.getName() << " ��" << endl;
	cout << "    @ �÷��̾� �ڱ� : " << user.getMoney() << "$" << endl;
	coutColor("������������������������������������������", 0x000D, 0, 0, true);
	cout << "             ���� ���ϸ� ���             " << endl;
	coutColor("������������������������������������������", 0x000D, 0, 0, true);
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
	cout << "  >> ��ǥ ���ϸ� ���� (����:0) : ";
	setCursor(true);
	cin >> choose;
	setCursor(false);
	if (choose == 0)
		return;
	else if (choose > user.getPokenum())
		return;

	user.setMain(*user.getPoke(choose - 1));
	cout << endl << "  # ���� �Ϸ�." << endl;
	cout << "  # �ƹ� Ű�� ���� �޴��� ������." << endl;
}

void App::invenMenu()
{
	setCursor(false);
	system("cls");
	setWindowSize(42, 14, "Pokemon :: Item Inventory");
	coutColor("������������������������������������������", 0x000D, 0, 0, true);
	cout << "    @ �÷��̾� : " << user.getName() << " ��" << endl;
	cout << "    @ �÷��̾� �ڱ� : " << user.getMoney() << "$" << endl;
	coutColor("������������������������������������������", 0x000D, 0, 0, true);
	cout << "               �κ��丮 ���              " << endl;
	coutColor("������������������������������������������", 0x000D, 0, 0, true);
	cout << "  # 1. ���ͺ� : " << user.getInven().monster << "��" << endl;
	cout << "  # 2. ���ۺ� : " << user.getInven().super << "��" << endl;
	cout << "  # 3. �����ͺ� : " << user.getInven().master << "��" << endl;
	cout << "  # 4. ġ��� : " << user.getInven().medic << "��" << endl;
	cout << endl;
	cout << "  # �ƹ� Ű�� ���� �޴��� ������." << endl;
}

void App::storeMenu()
{
	int choose;

	setCursor(false);
	system("cls");
	setWindowSize(42, 23, "Pokemon :: Pokemon Store");
	coutColor("������������������������������������������", 0x0009, 0, 0, true);
	cout << "    @ �÷��̾� : " << user.getName() << " ��" << endl;
	cout << "    @ �÷��̾� ID : " << user.getID() << endl;
	cout << "    @ �÷��̾� �ڱ� : " << user.getMoney() << "$" << endl;
	coutColor("������������������������������������������", 0x0009, 0, 0, true);
	cout << "                ���ϸ� ����               " << endl;
	coutColor("������������������������������������������", 0x0009, 0, 0, true);
	cout << "  # 1. ���ͺ� ���� (5$)" << endl;
	cout << "  # 2. ���ۺ� ���� (15$)" << endl;
	cout << "  # 3. �����ͺ� ���� (35$)" << endl;
	cout << "  # 4. ġ��� ���� (4$)" << endl;
	cout << "  # 5. ���ϸ� �Ǹ�" << endl; 
	cout << "  # 0. �޴��� ���ư���" << endl;
	coutColor("������������������������������������������", 0x0009, 0, 0, true);
	cout << "  >> ���� : ";
	setCursor(true);
	cin >> choose;
	setCursor(false);

	cout << endl; //16��
	if (choose == 1)
	{
		cout << "  >> ������ ���� : ";
		cin >> choose;
		cout << endl;
		if (user.getMoney() < 5 * choose)
			cout << "  # �ڱ� ����." << endl;
		else
		{
			user.addMoney(-5 * choose);
			cout << "  # ���� �Ϸ�." << endl;
		}
	}
	else if (choose == 2)
	{
		cout << "  >> ������ ���� : ";
		cin >> choose;
		cout << endl;
		if (user.getMoney() < 15 * choose)
			cout << "  # �ڱ� ����." << endl;
		else
		{
			user.addMoney(-15 * choose);
			cout << "  # ���� �Ϸ�." << endl;
		}
	}
	else if (choose == 3)
	{
		cout << "  >> ������ ���� : ";
		cin >> choose;
		cout << endl;
		if (user.getMoney() < 35 * choose)
			cout << "  # �ڱ� ����." << endl;
		else
		{
			user.addMoney(-35 * choose);
			cout << "  # ���� �Ϸ�." << endl;
		}
	}
	else if (choose == 4)
	{
		cout << "  >> ������ ���� : ";
		cin >> choose;
		cout << endl;
		if (user.getMoney() < 4 * choose)
			cout << "  # �ڱ� ����." << endl;
		else
		{
			user.addMoney(-4 * choose);
			cout << "  # ���� �Ϸ�." << endl;
		}
	}
	else if (choose == 5)
		sellMenu();
	else if (choose == 0)
		return;
	else
		cout << "  # ���� ����." << endl;
	cout << endl;
	cout << "  # �ƹ� Ű�� ���� �޴��� ������." << endl;
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
	coutColor("������������������������������������������", 0x000D, 0, 0, true);
	cout << "    @ �÷��̾� : " << user.getName() << " ��" << endl;
	cout << "    @ �÷��̾� �ڱ� : " << user.getMoney() << "$" << endl;
	coutColor("������������������������������������������", 0x000D, 0, 0, true);
	cout << "                ���ϸ� ����               " << endl;
	coutColor("������������������������������������������", 0x000D, 0, 0, true);
	cout << "  # ��ǥ ���ϸ��� ġ���ϰڽ��ϱ� ?" << endl;
	cout << "      (ġ�� ��� : " << bill + 4 << "$)" << endl;
	cout << "  >> (Y/N) : ";
	setCursor(true);
	cin >> choose;
	setCursor(false);

	cout << endl;
	if (choose == 'y' || choose == 'Y')
	{
		if (user.getMoney() < bill + 4)
		{
			cout << "  # ������ �������� �ƴմϴ�." << endl;
			cout << "  # �ƹ� Ű�� ���� �� ��� �ٽ� ������." << endl;
		}
		else
		{
			Sleep(1000);
			user.getMain()->setHP(user.getMain()->getHpMax());
			user.addMoney(-bill);
			user.getMain()->setDie(false);
			cout << "  # ġ�ᰡ �Ϸ�Ǿ����ϴ�." << endl;
			cout << "  # �ƹ� Ű�� ���� �޴��� ������." << endl;
		}
	}
	else if (choose == 'n' || choose == 'N')
		return;
	else
	{
		cout << "  # �Է� ����!" << endl;
		cout << "  # �ƹ� Ű�� ���� �޴��� ������." << endl;
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
	bool turn = true;	//true : �������
	bool atkbool; //����bool
	bool capbool; //��ȹbool

	//���ϸ� ����
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
	//���� ����
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

	coutColor("������������������������������������������", 0x000C, 0, 0, true);
	coutColor("������������������������������������������", 0x000C, 0, 0, true);
	cout << "    @ �÷��̾� : " << user.getName() << " ��" << endl;
	coutColor("������������������������������������������", 0x000C, 0, 0, true);
	cout << "    @ ��ǥ ���ϸ� : " << user.getMain()->getName() << "(";
	user.getMain()->printType(); cout << ")" << endl;
	cout << "    @ ���ϸ� ���� : Lv. " << user.getMain()->getLevel() << endl;
	cout << "    @ ���ϸ� ü�� : [ " << user.getMain()->getHP() << " / " << user.getMain()->getHpMax() << " ]" << endl;
	cout << "    @ ���ϸ� ����ġ : [ " << user.getMain()->getExp() << " / " << user.getMain()->getExpMax() << " ]" << endl;
	coutColor("������������������������������������������", 0x000C, 0, 0, true);
	cout << "                    vs                  " << endl;
	coutColor("������������������������������������������", 0x000C, 0, 0, true);
	cout << "    @ �߻��� ���ϸ� : " << fieldmon->getName() << "(";
	fieldmon->printType(); cout << ")" << endl;
	cout << "    @ ���ϸ� ���� : Lv. " << fieldmon->getLevel() << endl;
	cout << "    @ ���ϸ� ü�� : [ " << fieldmon->getHP() << " / " << fieldmon->getHpMax() << " ]" << endl;
	coutColor("������������������������������������������", 0x000C, 0, 0, true);
	coutColor("������������������������������������������", 0x000C, 0, 0, true);
	cout << "  # 1. " << user.getMain()->skill[0]->getName() << " (���ݷ� : " <<
		user.getMain()->skill[0]->getDamage() << ")" << endl;
	cout << "  # 2. " << user.getMain()->skill[1]->getName() << " (���ݷ� : " <<
		user.getMain()->skill[1]->getDamage() << ")" << endl;
	cout << "  # 3. " << user.getMain()->skill[2]->getName() << " (���ݷ� : " <<
		user.getMain()->skill[2]->getDamage() << ")" << endl;
	cout << "  # 4. ���� ����" << endl;
	cout << "  # 5. ��������" << endl;
	coutColor("������������������������������������������", 0x000C, 0, 0, true);

	// ����� ��.
	if (turn)
	{
		setCursor(true);
		cout << "  >> ��ų ���� : ";
		cin >> schoose;

		cout << endl;
		if (schoose >= 1 && schoose <= 3)
		{
			if (schoose > user.getMain()->getEvol())
			{
				cout << "  # ���� ����� ���� ��ų�Դϴ�." << endl;
			}
			else
			{
				atkbool = user.getMain()->skill[schoose - 1]->attack(user.getMain()->getType(), fieldmon);
				if (atkbool)
				{
					coutColor("  # ������ �����Ͽ����ϴ�!", 0x000B, 11, 14, true);
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
					coutColor("  # ������ �����Ͽ����ϴ�!", 0x000C, 11, 14, true);
			}
		}
		else if (schoose == 4)
		{
			if (user.getPokenum() == 6)
				cout << "  # ���ϸ� ������ ��á���ϴ�." << endl;
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
			cout << "  # ������ �õ��մϴ�." << endl;
			Sleep(600);
			temp = rand() % 100 + 1;
			if (temp >= 1 && temp <= PROB_36)
			{
				cout << "  # ������ �����Ͽ����ϴ�!" << endl;
				return;
			}
			else
				cout << "  # ������ �����Ͽ����ϴ�." << endl;
		}
		else
		{
			cout << "  # �߸��� �Է��Դϴ�." << endl;
		}

		cout << "  # ����� ���� ���۵˴ϴ�." << endl;
		turn = false;
		_getch();
		goto fight;
	}

	// AI ��.
	else
	{
		cout << endl;

		temp = rand() % fieldmon->getEvol();
		atkbool = fieldmon->skill[temp]->attack(fieldmon->getType(), user.getMain());
		cout << "  # ����� " << fieldmon->skill[temp]->getName() << " ����! " << endl;
		if (atkbool)
		{
			coutColor("  # ����� ������ �����Ͽ����ϴ�!", 0x000C, 19, 22, true);
			if (user.getMain()->getDie() == true)
			{
				battleEnd(false, false);
				return;
			}
		}
		else
			coutColor("  # ����� ������ �����Ͽ����ϴ�!", 0x000B, 19, 22, true);

		cout << "  # ����� ���� ���۵˴ϴ�." << endl;
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
	coutColor("������������������������������������������", 0x000B, 0, 0, true);
	cout << "    @ �߻��� ���ϸ� : " << _mon->getName() << "(";
	_mon->printType(); cout << ")" << endl;
	cout << "    @ ���ϸ� ���� Lv. : " << _mon->getLevel() << endl;
	cout << "    @ ���ϸ� ü�� : [ " << _mon->getHP() << " / " << _mon->getHpMax() << " ]" << endl;
	coutColor("������������������������������������������", 0x000B, 0, 0, true);
	cout << "  # 1. ���ͺ� : " << user.getInven().monster << "��" << endl;
	cout << "  # 2. ���ۺ� : " << user.getInven().super << "��" << endl;
	cout << "  # 3. �����ͺ� : " << user.getInven().master << "��" << endl;
	cout << "  # 4. ġ��� : " << user.getInven().medic << "��" << endl;
	coutColor("������������������������������������������", 0x000B, 0, 0, true);
	cout << "  >> �Է� : ";
	cin >> choose;

	cout << endl;
	if (choose == 1)
	{
		if (user.getInven().monster <= 0)
		{
			cout << "  # ���ͺ��� �� ���������ϴ�." << endl;
			_getch();
			return false;
		}
		else
		{
			cout << "  # ���ͺ��� �������ϴ�." << endl;
			Sleep(1600);
			temp = user.capture(*_mon, Ball::Monster);
		}
	}
	else if (choose == 2)
	{
		if (user.getInven().super <= 0)
		{
			cout << "  # ���ͺ��� �� ���������ϴ�." << endl;
			_getch();
			return false;
		}
		else
		{
			cout << "  # ���ۺ��� �������ϴ�." << endl;
			Sleep(1200);
			temp = user.capture(*_mon, Ball::Super);
		}
	}
	else if (choose == 3)
	{
		if (user.getInven().master <= 0)
		{
			cout << "  # ���ͺ��� �� ���������ϴ�." << endl;
			_getch();
			return false;
		}
		else
		{
			cout << "  # �����ͺ��� �������ϴ�." << endl;
			Sleep(800);
			temp = user.capture(*_mon, Ball::Master);
		}
	}
	else if (choose == 4)
	{
		if (user.getInven().medic <= 0)
		{
			cout << "  # ġ����� �� ���������ϴ�." << endl;
			_getch();
			return false;
		}
		else
		{
			cout << "  # ġ����� ����߽��ϴ�." << endl;
			Sleep(500);
			user.getMain()->heal(30);
		}
	}
	else
	{
		cout << "  # �Է� ����! " << endl;
		cout << "  # �ƹ� Ű�� ���� �ǵ��ư�����." << endl;
		_getch();
		goto capture;
	}

	if (temp)
	{
		cout << "  # ���ϸ��� ��ҽ��ϴ�!" << endl;
		cout << "  # ���ϸ� ���濡 ��ϵ˴ϴ�." << endl << endl;
		cout << "  # �ƹ� Ű�� ���� ������ ������." << endl;
		_getch();
		return true;
	}
	else
	{
		cout << "  # ���ϸ��� Ż���Ͽ����ϴ�!" << endl << endl;
		cout << "  # �ƹ� Ű�� ���� ������ ������." << endl;
		_getch();
		return false;
	}
}

void App::battleEnd(bool _win, bool _legend)
{
	int temp = rand() % 31 + 10; //����� ����ġ ����
	int temp2 = rand() % 94 + 1; //����� �ڱ�

	if (_legend == true) //�������ϸ� �̰������.
	{
		temp = 80;
		temp2 = 4000;
	}

	_getch();
	system("cls");

	cout << endl;
	if (_win)
	{
		coutColor("  # �������� �¸��Ͽ����ϴ�!", 0x000B, 14, 17, true);
		cout << "  # ����ġ�� " << temp << "% ����մϴ�." << endl;
		cout << "  # �ڱ��� " << temp2 << "$ ����մϴ�." << endl;
		user.getMain()->incExpProp(temp);
		user.addMoney(temp2);
	}
	else
		coutColor("  # �������� �й��Ͽ����ϴ�.", 0x000C, 14, 17, true);
	
	cout << endl;
	cout << "  # �ƹ� Ű�� ���� ������ ������." << endl;
	_getch();
}

void App::sellMenu()
{
	int choose;

	setCursor(false);
	system("cls");
	setWindowSize(42, 22, "Pokemon :: Pokemon Store");
	coutColor("������������������������������������������", 0x0009, 0, 0, true);
	cout << "    @ �÷��̾� : " << user.getName() << " ��" << endl;
	cout << "    @ �÷��̾� �ڱ� : " << user.getMoney() << "$" << endl;
	coutColor("������������������������������������������", 0x0009, 0, 0, true);
	cout << "                ���ϸ� �Ǹ�               " << endl;
	coutColor("������������������������������������������", 0x0009, 0, 0, true);
	for (int i = 0; i < user.getPokenum(); i++)
	{
		if (user.getPoke(i) == nullptr)
			continue;
		cout << "  # " << i + 1 << ". " << user.getPoke(i)->getName() << " (";
		user.getPoke(i)->printType(); cout << ", Lv. " << user.getPoke(i)->getLevel()
			<< ")" << endl;
		cout << "    - �Ǹ� ���� : " << user.getPoke(i)->getPrice() << "$" << endl;
		cout << endl;
	}
	coutColor("������������������������������������������", 0x0009, 0, 0, true);
	cout << "  >> ���� (����:0) : ";
	setCursor(true);
	cin >> choose;
	setCursor(false);
	cout << endl;

	if (choose >= 1 && choose <= user.getPokenum())
	{
		user.sellPokemon(choose - 1);
		cout << "  # �Ǹ� �Ϸ�." << endl;
	}
	else if (choose == 0)
		return;
	else
		cout << "  # ���� ����." << endl;
}