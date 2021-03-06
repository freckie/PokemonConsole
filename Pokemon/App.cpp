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
	cout << "旨收收收收收收收收收收收收收收收收收收收旬" << endl;
	cout << "早                                      早" << endl;
	cout << "早               Pokemon                早" << endl;
	cout << "早                             @ freckie早" << endl;
	cout << "曲收收收收收收收收收收收收收收收收收收收旭" << endl;
	cout << " # 檜葷 : ";
	cin >> inputname;
	setCursor(false);

	cout << endl;
	cout << "  # 羅 ん鰍跨擊 摹鷗ж撮蹂." << endl;
	cout << "  # だ檜葬(1) 窒睡晦(2) 檜鼻п噢(3)" << endl;
	cout << " >> 殮溘 : ";
	cin >> choose;
	setCursor(false);

	if (choose == 1)
	{
		cout << "  # 羅 ん鰍跨擊 だ檜葬煎 薑ц蝗棲棻!" << endl;
		first = new Fire1();
	}
	else if (choose == 2)
	{
		cout << "  # 羅 ん鰍跨擊 窒睡晦煎 薑ц蝗棲棻!" << endl;
		first = new Water1();
	}
	else if (choose == 3)
	{
		cout << "  # 羅 ん鰍跨擊 檜鼻п噢煎 薑ц蝗棲棻!" << endl;
		first = new Grass1();
	}
	else if (choose == 9)
	{
		cout << "  # 羅 ん鰍跨擊 Я蘋鏘煎 薑ц蝗棲棻!" << endl;
		first = new Light1();
	}
	else
	{
		cout << "  # 摹鷗 螃盟." << endl;
		_getch();
		system("cls");
		goto start;
	}
	user.addPokemon(*first);
	user.getMain()->setLevel(1);

	user.setInven(InvenType::medic, 15);
	user.setInven(InvenType::monster, 15);
	user.setName(inputname);

	cout << "  # 嬴鼠 酈釭 揚楝 賅я擊 集釭撮蹂." << endl;
	_getch();
}

void App::mainMenu()
{
	int choose;

	music.Play_Main();

	setCursor(false);
	system("cls");
	setWindowSize(42, 19, "Pokemon :: Main");
	coutColor("收收收收收收收收收收收收收收收收收收收收收", 0x000E, 0, 0, true);
	cout << "    @ Ы溯檜橫 : " << user.getName() << " 椒" << endl;
	cout << "    @ Ы溯檜橫 濠旎 : " << user.getMoney() << "$" << endl;
	coutColor("收收收收收收收收收收收收收收收收收收收收收", 0x000E, 0, 0, true);
	cout << "    @ 渠ル ん鰍跨 : " << user.getMain()->getName() << "(";
	user.getMain()->printType();
	cout << ")" << endl;
	cout << "    @ ん鰍跨 溯漣 : Lv. " << user.getMain()->getLevel() << endl;
	cout << "    @ ん鰍跨 羹溘 : [ " << user.getMain()->getHP() << " / " << user.getMain()->getHpMax() << " ]" << endl;
	cout << "    @ ん鰍跨 唳я纂 : [ " << user.getMain()->getExp() << " / " << user.getMain()->getExpMax() << " ]" << endl;
	coutColor("收收收收收收收收收收收收收收收收收收收收收", 0x000E, 0, 0, true);
	cout << "  # 1. 撿儅戲煎 集陪棻." << endl;
	cout << "  # 2. 釭曖 ん鰍跨擊 �挫恉挬�." << endl;
	cout << "  # 3. 檣漸饜葬蒂 �挫恉挬�." << endl;
	cout << "  # 4. ん鰍跨 鼻薄縑 菟萼棻." << endl;
	cout << "  # 5. ん鰍跨 煽錳縑 菟萼棻." << endl;
	cout << "  # 0. 謙猿и棻." << endl;
	coutColor("收收收收收收收收收收收收收收收收收收收收收", 0x000E, 0, 0, true);
	cout << " >> 摹鷗 : ";
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
		cout << "  # 摹鷗 螃盟." << endl;

	_getch();

}

bool App::fieldMenu() //false賊 鬚я 部.
{
	int randnum; //楠渾剩幗
	PokemonID pid;
	char chartemp;

	music.Play_Taecho();

	setCursor(false);
	system("cls");
	setWindowSize(42, 23, "Pokemon :: Field");
	coutColor("收收收收收收收收收收收收收收收收收收收收收", 0x000A, 0, 0, true);
	cout << "    @ Ы溯檜橫 : " << user.getName() << " 椒" << endl;
	coutColor("收收收收收收收收收收收收收收收收收收收收收", 0x000A, 0, 0, true);
	cout << "    @ 渠ル ん鰍跨 : " << user.getMain()->getName() << "(";
	user.getMain()->printType();
	cout << ")" << endl;
	cout << "    @ ん鰍跨 溯漣 : Lv. " << user.getMain()->getLevel() << endl;
	cout << "    @ ん鰍跨 羹溘 : [ " << user.getMain()->getHP() << " / " << user.getMain()->getHpMax() << " ]" << endl;
	cout << "    @ ん鰍跨 唳я纂 : [ " << user.getMain()->getExp() << " / " << user.getMain()->getExpMax() << " ]" << endl;
	coutColor("收收收收收收收收收收收收收收收收收收收收收", 0x000A, 0, 0, true);

	if (user.getMain()->getDie() == true)
	{
		cout << "  # 渠ル ん鰍跨檜 晦瞰 鼻鷓殮棲棻." << endl;
		cout << "  # 煽錳縑憮 �蛹厭藷偷宒藩�." << endl;
		return false;
	}

	cout << "  # 撿儅曖 膛 樓擊 鬚яж朝 醞 ... " << endl;
	cout << "  # 鬚я擊 誇蹺溥賊 嬴鼠 酈釭 揚楝輿撮蹂." << endl << endl;

	Sleep(1100);

	while (true)
	{
		if (_kbhit() == true)
		{
			cout << "  # 鬚я擊 醞雖м棲棻. " << endl;
			_getch();
			return false;
		}

		randnum = rand() % 100 + 1;

		if (randnum >= 1 && randnum <= PROB_FIND)
		{
			cout << "  # 蕙曖 ヴ膛檜 菟賤殮棲棻." << endl;
			cout << "  # 髦よ爾溥賊 Space Bar 揚楝輿撮蹂." << endl << endl;

			do
			{
				chartemp = _getch();
			} while (chartemp != UI::KEY_SPACE);

			pid = fieldFind();

			if (pid == PokemonID::none)
			{
				cout << "  # ヴ膛縑 嬴鼠 匙紫 橈蝗棲棻." << endl;
				cout << endl;
				cout << "  # 嬴鼠 酈釭 揚楝 鬚я擊 啗樓ж撮蹂." << endl;
				_getch();
				return true;
			}

			cout << "  # 撿儅曖 跨蝶攪蒂 嫦唯ц蝗棲棻!" << endl;
			cout << endl;
			cout << "  # 嬴鼠 酈釭 揚楝 瞪癱蒂 霞чж撮蹂." << endl;
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
	coutColor("收收收收收收收收收收收收收收收收收收收收收", 0x000D, 0, 0, true);
	cout << "    @ Ы溯檜橫 : " << user.getName() << " 椒" << endl;
	cout << "    @ Ы溯檜橫 濠旎 : " << user.getMoney() << "$" << endl;
	coutColor("收收收收收收收收收收收收收收收收收收收收收", 0x000D, 0, 0, true);
	cout << "             模嶸 ん鰍跨 跡煙             " << endl;
	coutColor("收收收收收收收收收收收收收收收收收收收收收", 0x000D, 0, 0, true);
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
	cout << "  >> 渠ル ん鰍跨 滲唳 (謙猿:0) : ";
	setCursor(true);
	cin >> choose;
	setCursor(false);
	if (choose == 0)
		return;
	else if (choose > user.getPokenum())
		return;

	user.setMain(*user.getPoke(choose - 1));
	cout << endl << "  # 滲唳 諫猿." << endl;
	cout << "  # 嬴鼠 酈釭 揚楝 詭景煎 陛撮蹂." << endl;
}

void App::invenMenu()
{
	setCursor(false);
	system("cls");
	setWindowSize(42, 14, "Pokemon :: Item Inventory");
	coutColor("收收收收收收收收收收收收收收收收收收收收收", 0x000D, 0, 0, true);
	cout << "    @ Ы溯檜橫 : " << user.getName() << " 椒" << endl;
	cout << "    @ Ы溯檜橫 濠旎 : " << user.getMoney() << "$" << endl;
	coutColor("收收收收收收收收收收收收收收收收收收收收收", 0x000D, 0, 0, true);
	cout << "               檣漸饜葬 跡煙              " << endl;
	coutColor("收收收收收收收收收收收收收收收收收收收收收", 0x000D, 0, 0, true);
	cout << "  # 1. 跨蝶攪獐 : " << user.getInven().monster << "偃" << endl;
	cout << "  # 2. 蓬ぷ獐 : " << user.getInven().super << "偃" << endl;
	cout << "  # 3. 葆蝶攪獐 : " << user.getInven().master << "偃" << endl;
	cout << "  # 4. 纂猿擒 : " << user.getInven().medic << "偃" << endl;
	cout << endl;
	cout << "  # 嬴鼠 酈釭 揚楝 詭景煎 陛撮蹂." << endl;
}

void App::storeMenu()
{
	int choose;

	setCursor(false);
	system("cls");
	setWindowSize(42, 23, "Pokemon :: Pokemon Store");
	coutColor("收收收收收收收收收收收收收收收收收收收收收", 0x0009, 0, 0, true);
	cout << "    @ Ы溯檜橫 : " << user.getName() << " 椒" << endl;
	cout << "    @ Ы溯檜橫 ID : " << user.getID() << endl;
	cout << "    @ Ы溯檜橫 濠旎 : " << user.getMoney() << "$" << endl;
	coutColor("收收收收收收收收收收收收收收收收收收收收收", 0x0009, 0, 0, true);
	cout << "                ん鰍跨 鼻薄               " << endl;
	coutColor("收收收收收收收收收收收收收收收收收收收收收", 0x0009, 0, 0, true);
	cout << "  # 1. 跨蝶攪獐 掘衙 (5$)" << endl;
	cout << "  # 2. 蓬ぷ獐 掘衙 (15$)" << endl;
	cout << "  # 3. 葆蝶攪獐 掘衙 (35$)" << endl;
	cout << "  # 4. 纂猿擒 掘衙 (4$)" << endl;
	cout << "  # 5. ん鰍跨 っ衙" << endl; 
	cout << "  # 0. 詭景煎 給嬴陛晦" << endl;
	coutColor("收收收收收收收收收收收收收收收收收收收收收", 0x0009, 0, 0, true);
	cout << "  >> 摹鷗 : ";
	setCursor(true);
	cin >> choose;
	setCursor(false);

	cout << endl; //16還
	if (choose == 1)
	{
		cout << "  >> 掘衙й 熱榆 : ";
		cin >> choose;
		cout << endl;
		if (user.getMoney() < 5 * choose)
			cout << "  # 濠旎 睡褶." << endl;
		else
		{
			user.addMoney(-5 * choose);
			cout << "  # 掘衙 諫猿." << endl;
		}
	}
	else if (choose == 2)
	{
		cout << "  >> 掘衙й 熱榆 : ";
		cin >> choose;
		cout << endl;
		if (user.getMoney() < 15 * choose)
			cout << "  # 濠旎 睡褶." << endl;
		else
		{
			user.addMoney(-15 * choose);
			cout << "  # 掘衙 諫猿." << endl;
		}
	}
	else if (choose == 3)
	{
		cout << "  >> 掘衙й 熱榆 : ";
		cin >> choose;
		cout << endl;
		if (user.getMoney() < 35 * choose)
			cout << "  # 濠旎 睡褶." << endl;
		else
		{
			user.addMoney(-35 * choose);
			cout << "  # 掘衙 諫猿." << endl;
		}
	}
	else if (choose == 4)
	{
		cout << "  >> 掘衙й 熱榆 : ";
		cin >> choose;
		cout << endl;
		if (user.getMoney() < 4 * choose)
			cout << "  # 濠旎 睡褶." << endl;
		else
		{
			user.addMoney(-4 * choose);
			cout << "  # 掘衙 諫猿." << endl;
		}
	}
	else if (choose == 5)
		sellMenu();
	else if (choose == 0)
		return;
	else
		cout << "  # 摹鷗 螃盟." << endl;
	cout << endl;
	cout << "  # 嬴鼠 酈釭 揚楝 詭景煎 陛撮蹂." << endl;
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
	coutColor("收收收收收收收收收收收收收收收收收收收收收", 0x000D, 0, 0, true);
	cout << "    @ Ы溯檜橫 : " << user.getName() << " 椒" << endl;
	cout << "    @ Ы溯檜橫 濠旎 : " << user.getMoney() << "$" << endl;
	coutColor("收收收收收收收收收收收收收收收收收收收收收", 0x000D, 0, 0, true);
	cout << "                ん鰍跨 煽錳               " << endl;
	coutColor("收收收收收收收收收收收收收收收收收收收收收", 0x000D, 0, 0, true);
	cout << "  # 渠ル ん鰍跨擊 纂猿ж啊蝗棲梱 ?" << endl;
	cout << "      (纂猿 綠辨 : " << bill + 4 << "$)" << endl;
	cout << "  >> (Y/N) : ";
	setCursor(true);
	cin >> choose;
	setCursor(false);

	cout << endl;
	if (choose == 'y' || choose == 'Y')
	{
		if (user.getMoney() < bill + 4)
		{
			cout << "  # 煽錳擎 瑰餌晦婦檜 嬴椎棲棻." << endl;
			cout << "  # 嬴鼠 酈釭 揚楝 絲 菟堅 棻衛 螃撮蹂." << endl;
		}
		else
		{
			Sleep(1000);
			user.getMain()->setHP(user.getMain()->getHpMax());
			user.addMoney(-bill);
			user.getMain()->setDie(false);
			cout << "  # 纂猿陛 諫猿腎歷蝗棲棻." << endl;
			cout << "  # 嬴鼠 酈釭 揚楝 詭景煎 陛撮蹂." << endl;
		}
	}
	else if (choose == 'n' || choose == 'N')
		return;
	else
	{
		cout << "  # 殮溘 螃盟!" << endl;
		cout << "  # 嬴鼠 酈釭 揚楝 詭景煎 陛撮蹂." << endl;
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
	bool turn = true;	//true : 餌辨濠欐
	bool atkbool; //奢問bool
	bool capbool; //ん�鉉ool

	//ん鰍跨 儅撩
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
	//溯漣 撲薑
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

	coutColor("收收收收收收收收收收收收收收收收收收收收收", 0x000C, 0, 0, true);
	coutColor("收收收收收收收收收收收收收收收收收收收收收", 0x000C, 0, 0, true);
	cout << "    @ Ы溯檜橫 : " << user.getName() << " 椒" << endl;
	coutColor("收收收收收收收收收收收收收收收收收收收收收", 0x000C, 0, 0, true);
	cout << "    @ 渠ル ん鰍跨 : " << user.getMain()->getName() << "(";
	user.getMain()->printType(); cout << ")" << endl;
	cout << "    @ ん鰍跨 溯漣 : Lv. " << user.getMain()->getLevel() << endl;
	cout << "    @ ん鰍跨 羹溘 : [ " << user.getMain()->getHP() << " / " << user.getMain()->getHpMax() << " ]" << endl;
	cout << "    @ ん鰍跨 唳я纂 : [ " << user.getMain()->getExp() << " / " << user.getMain()->getExpMax() << " ]" << endl;
	coutColor("收收收收收收收收收收收收收收收收收收收收收", 0x000C, 0, 0, true);
	cout << "                    vs                  " << endl;
	coutColor("收收收收收收收收收收收收收收收收收收收收收", 0x000C, 0, 0, true);
	cout << "    @ 撿儅曖 ん鰍跨 : " << fieldmon->getName() << "(";
	fieldmon->printType(); cout << ")" << endl;
	cout << "    @ ん鰍跨 溯漣 : Lv. " << fieldmon->getLevel() << endl;
	cout << "    @ ん鰍跨 羹溘 : [ " << fieldmon->getHP() << " / " << fieldmon->getHpMax() << " ]" << endl;
	coutColor("收收收收收收收收收收收收收收收收收收收收收", 0x000C, 0, 0, true);
	coutColor("收收收收收收收收收收收收收收收收收收收收收", 0x000C, 0, 0, true);
	cout << "  # 1. " << user.getMain()->skill[0]->getName() << " (奢問溘 : " <<
		user.getMain()->skill[0]->getDamage() << ")" << endl;
	cout << "  # 2. " << user.getMain()->skill[1]->getName() << " (奢問溘 : " <<
		user.getMain()->skill[1]->getDamage() << ")" << endl;
	cout << "  # 3. " << user.getMain()->skill[2]->getName() << " (奢問溘 : " <<
		user.getMain()->skill[2]->getDamage() << ")" << endl;
	cout << "  # 4. 陛寞 翮晦" << endl;
	cout << "  # 5. 紫蜂陛晦" << endl;
	coutColor("收收收收收收收收收收收收收收收收收收收收收", 0x000C, 0, 0, true);

	// 餌辨濠 欐.
	if (turn)
	{
		setCursor(true);
		cout << "  >> 蝶鑒 摹鷗 : ";
		cin >> schoose;

		cout << endl;
		if (schoose >= 1 && schoose <= 3)
		{
			if (schoose > user.getMain()->getEvol())
			{
				cout << "  # ⑷營 寡辦雖 彊擎 蝶鑒殮棲棻." << endl;
			}
			else
			{
				atkbool = user.getMain()->skill[schoose - 1]->attack(user.getMain()->getType(), fieldmon);
				if (atkbool)
				{
					coutColor("  # 奢問檜 撩奢ж艘蝗棲棻!", 0x000B, 11, 14, true);
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
					coutColor("  # 奢問檜 褒ぬж艘蝗棲棻!", 0x000C, 11, 14, true);
			}
		}
		else if (schoose == 4)
		{
			if (user.getPokenum() == 6)
				cout << "  # ん鰍跨 陛寞檜 粕獺蝗棲棻." << endl;
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
			cout << "  # 紫蜂擊 衛紫м棲棻." << endl;
			Sleep(600);
			temp = rand() % 100 + 1;
			if (temp >= 1 && temp <= PROB_36)
			{
				cout << "  # 紫蜂縑 撩奢ж艘蝗棲棻!" << endl;
				return;
			}
			else
				cout << "  # 紫蜂縑 褒ぬж艘蝗棲棻." << endl;
		}
		else
		{
			cout << "  # 澀跤脹 殮溘殮棲棻." << endl;
		}

		cout << "  # 鼻渠曖 欐檜 衛濛腌棲棻." << endl;
		turn = false;
		_getch();
		goto fight;
	}

	// AI 欐.
	else
	{
		cout << endl;

		temp = rand() % fieldmon->getEvol();
		atkbool = fieldmon->skill[temp]->attack(fieldmon->getType(), user.getMain());
		cout << "  # 鼻渠曖 " << fieldmon->skill[temp]->getName() << " 奢問! " << endl;
		if (atkbool)
		{
			coutColor("  # 鼻渠曖 奢問檜 撩奢ж艘蝗棲棻!", 0x000C, 19, 22, true);
			if (user.getMain()->getDie() == true)
			{
				battleEnd(false, false);
				return;
			}
		}
		else
			coutColor("  # 鼻渠曖 奢問檜 褒ぬж艘蝗棲棻!", 0x000B, 19, 22, true);

		cout << "  # 渡褐曖 欐檜 衛濛腌棲棻." << endl;
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
	coutColor("收收收收收收收收收收收收收收收收收收收收收", 0x000B, 0, 0, true);
	cout << "    @ 撿儅曖 ん鰍跨 : " << _mon->getName() << "(";
	_mon->printType(); cout << ")" << endl;
	cout << "    @ ん鰍跨 溯漣 Lv. : " << _mon->getLevel() << endl;
	cout << "    @ ん鰍跨 羹溘 : [ " << _mon->getHP() << " / " << _mon->getHpMax() << " ]" << endl;
	coutColor("收收收收收收收收收收收收收收收收收收收收收", 0x000B, 0, 0, true);
	cout << "  # 1. 跨蝶攪獐 : " << user.getInven().monster << "偃" << endl;
	cout << "  # 2. 蓬ぷ獐 : " << user.getInven().super << "偃" << endl;
	cout << "  # 3. 葆蝶攪獐 : " << user.getInven().master << "偃" << endl;
	cout << "  # 4. 纂猿擒 : " << user.getInven().medic << "偃" << endl;
	coutColor("收收收收收收收收收收收收收收收收收收收收收", 0x000B, 0, 0, true);
	cout << "  >> 殮溘 : ";
	cin >> choose;

	cout << endl;
	if (choose == 1)
	{
		if (user.getInven().monster <= 0)
		{
			cout << "  # 跨蝶攪獐檜 棻 雲橫螺蝗棲棻." << endl;
			_getch();
			return false;
		}
		else
		{
			cout << "  # 跨蝶攪獐擊 湍螺蝗棲棻." << endl;
			Sleep(1600);
			temp = user.capture(*_mon, Ball::Monster);
		}
	}
	else if (choose == 2)
	{
		if (user.getInven().super <= 0)
		{
			cout << "  # 跨蝶攪獐檜 棻 雲橫螺蝗棲棻." << endl;
			_getch();
			return false;
		}
		else
		{
			cout << "  # 蓬ぷ獐擊 湍螺蝗棲棻." << endl;
			Sleep(1200);
			temp = user.capture(*_mon, Ball::Super);
		}
	}
	else if (choose == 3)
	{
		if (user.getInven().master <= 0)
		{
			cout << "  # 跨蝶攪獐檜 棻 雲橫螺蝗棲棻." << endl;
			_getch();
			return false;
		}
		else
		{
			cout << "  # 葆蝶攪獐擊 湍螺蝗棲棻." << endl;
			Sleep(800);
			temp = user.capture(*_mon, Ball::Master);
		}
	}
	else if (choose == 4)
	{
		if (user.getInven().medic <= 0)
		{
			cout << "  # 纂猿擒檜 棻 雲橫螺蝗棲棻." << endl;
			_getch();
			return false;
		}
		else
		{
			cout << "  # 纂猿擒擊 餌辨ц蝗棲棻." << endl;
			Sleep(500);
			user.getMain()->heal(30);
		}
	}
	else
	{
		cout << "  # 殮溘 縑楝! " << endl;
		cout << "  # 嬴鼠 酈釭 揚楝 腎給嬴陛撮蹂." << endl;
		_getch();
		goto capture;
	}

	if (temp)
	{
		cout << "  # ん鰍跨擊 濩懊蝗棲棻!" << endl;
		cout << "  # ん鰍跨 陛寞縑 蛔煙腌棲棻." << endl << endl;
		cout << "  # 嬴鼠 酈釭 揚楝 膛戲煎 陛撮蹂." << endl;
		_getch();
		return true;
	}
	else
	{
		cout << "  # ん鰍跨檜 驍轎ж艘蝗棲棻!" << endl << endl;
		cout << "  # 嬴鼠 酈釭 揚楝 膛戲煎 陛撮蹂." << endl;
		_getch();
		return false;
	}
}

void App::battleEnd(bool _win, bool _legend)
{
	int temp = rand() % 31 + 10; //鼻蝓й 唳я纂 綠徽
	int temp2 = rand() % 94 + 1; //鼻蝓й 濠旎

	if (_legend == true) //瞪撲ん鰍跨 檜啣擊唳辦.
	{
		temp = 80;
		temp2 = 4000;
	}

	_getch();
	system("cls");

	cout << endl;
	if (_win)
	{
		coutColor("  # 瞪癱縑憮 蝓葬ж艘蝗棲棻!", 0x000B, 14, 17, true);
		cout << "  # 唳я纂陛 " << temp << "% 鼻蝓м棲棻." << endl;
		cout << "  # 濠旎檜 " << temp2 << "$ 鼻蝓м棲棻." << endl;
		user.getMain()->incExpProp(temp);
		user.addMoney(temp2);
	}
	else
		coutColor("  # 瞪癱縑憮 ぬ寡ж艘蝗棲棻.", 0x000C, 14, 17, true);
	
	cout << endl;
	cout << "  # 嬴鼠 酈釭 揚楝 膛戲煎 陛撮蹂." << endl;
	_getch();
}

void App::sellMenu()
{
	int choose;

	setCursor(false);
	system("cls");
	setWindowSize(42, 22, "Pokemon :: Pokemon Store");
	coutColor("收收收收收收收收收收收收收收收收收收收收收", 0x0009, 0, 0, true);
	cout << "    @ Ы溯檜橫 : " << user.getName() << " 椒" << endl;
	cout << "    @ Ы溯檜橫 濠旎 : " << user.getMoney() << "$" << endl;
	coutColor("收收收收收收收收收收收收收收收收收收收收收", 0x0009, 0, 0, true);
	cout << "                ん鰍跨 っ衙               " << endl;
	coutColor("收收收收收收收收收收收收收收收收收收收收收", 0x0009, 0, 0, true);
	for (int i = 0; i < user.getPokenum(); i++)
	{
		if (user.getPoke(i) == nullptr)
			continue;
		cout << "  # " << i + 1 << ". " << user.getPoke(i)->getName() << " (";
		user.getPoke(i)->printType(); cout << ", Lv. " << user.getPoke(i)->getLevel()
			<< ")" << endl;
		cout << "    - っ衙 陛問 : " << user.getPoke(i)->getPrice() << "$" << endl;
		cout << endl;
	}
	coutColor("收收收收收收收收收收收收收收收收收收收收收", 0x0009, 0, 0, true);
	cout << "  >> 摹鷗 (謙猿:0) : ";
	setCursor(true);
	cin >> choose;
	setCursor(false);
	cout << endl;

	if (choose >= 1 && choose <= user.getPokenum())
	{
		user.sellPokemon(choose - 1);
		cout << "  # っ衙 諫猿." << endl;
	}
	else if (choose == 0)
		return;
	else
		cout << "  # 摹鷗 螃盟." << endl;
}