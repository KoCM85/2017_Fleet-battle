#include "Field.h"
#include "Ships.h"
#include <iostream>
#include <ctime>
#include <windows.h>
#include <iomanip>

// 32  - пробел
// 249 - точка по центру
// 254 - квадрат белый
// 88  - X(engl)

inline void clear();

int main()
{
	time_t startTime = std::time(nullptr);
	time_t endTime;

	char copyright = 169;
	char readSymbol;
	bool isShoot = std::rand() % 2;

	std::srand(std::time(nullptr));

	Field & field = Field::getInstance();
	Ships & ships = Ships::getInstance();

	ships.setShips(field.getFieldYour());
	ships.setShips(field.getFieldEnemy());
	do
	{
		if (!isShoot)
		{
			char firstIndex = 0;
			short int secondIndex = 0;

			SetConsoleCP(866);
			field.Draw(0);
			std::locale::global(std::locale(".1251"));

			std::cout << "Введите координаты выстрела:\n";
			SetConsoleCP(1251);
			std::cin >> firstIndex;
			SetConsoleCP(866);
			if (firstIndex != 'А' && firstIndex != 'Б' && firstIndex != 'В' && firstIndex != 'Г' && firstIndex != 'Д'
				&& firstIndex != 'Е' && firstIndex != 'Ж' && firstIndex != 'З' && firstIndex != 'И' && firstIndex != 'К'
				&& firstIndex != 'а' && firstIndex != 'б' && firstIndex != 'в' && firstIndex != 'г' && firstIndex != 'д'
				&& firstIndex != 'е' && firstIndex != 'ж' && firstIndex != 'з' && firstIndex != 'и' && firstIndex != 'к')
			{
				clear();
				std::cout << "Вы ввели неверные координаты, введите заново\n\n";
				continue;
			}
			SetConsoleCP(1251);
			std::cin >> secondIndex;
			SetConsoleCP(866);
			if (secondIndex > 10 || secondIndex < 1)
			{
				clear();
				std::cout << "Вы ввели неверные координаты, введите заново\n\n";
				continue;
			}
			clear();
			isShoot = ships.shootYou(field.calculateIndex(firstIndex), secondIndex - 1, field.getFieldEnemy());
		}
		else
		{
			//isShoot = 0;
			
			isShoot = ships.shootEnemy(field.getFieldYour());
		}
	} while (ships.getNShipsLiveYour() > 0 && ships.getNShipsLiveEnemy() > 0);
	
	endTime = std::time(nullptr);

	field.Draw(1);
	std::locale::global(std::locale(".1251"));
	field.statistic(startTime, endTime, ships.getNShipsLiveYour(), ships.getNShipsLiveEnemy());
	
	std::cout << '\n' << "------------------------------------------------------------------------------" << '\n';
	std::cout << std::setw(27) << std::right << copyright << " | Копа Сергей Михайлович \n\n";
	
	std::cout << "Для выхода нажмите q или й и Enter" << std::endl;
	SetConsoleCP(1251);
	do
	{
		readSymbol = std::cin.get();
	} while (readSymbol != 'q' && readSymbol != 'й');

	return 0;
}

inline void clear()
{
	system("cls");
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
}