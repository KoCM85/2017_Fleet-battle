#include "Field.h"
#include <iostream>
#include <iomanip>
#include <windows.h>

Field & Field::getInstance()
{
	static Field field;
	return field;
}

void Field::Draw(const bool & end)
{
	std::locale::global(std::locale(".1251"));

	std::cout << "\t  Вы: \t\t\t\t\t\t  Враг:\n\n";
	std::cout << "  |А Б В Г Д Е Ж З И К|\t\t\t\t  |А Б В Г Д Е Ж З И К|";
	std::cout << "\n----------------------|\t\t\t\t----------------------|\n";

	std::locale::global(std::locale(".866"));

	for (int i = 0; i < 10; ++i)
	{
		std::cout << std::setw(2) << i + 1 << '|';
		for (int j = 0; j < 10; ++j)
		{
			std::cout << fieldYour_[i][j] << '|';
		}
		std::cout << "\b|\t\t\t\t";

		std::cout << std::setw(2) << i + 1 << '|';
		for (int j = 0; j < 10; ++j)
		{
			if (!end)
			{
				if (fieldEnemy_[i][j] == -2)
					std::cout << ' ' << '|';
				else
					std::cout << fieldEnemy_[i][j] << '|';
			}
			else
				std::cout << fieldEnemy_[i][j] << '|';
		}
		std::cout << "\b|\n";
	}
	std::cout << "-----------------------\t\t\t\t-----------------------\n";
}

std::array<std::array<char, 10>, 10> & Field::getFieldYour()
{
	return fieldYour_;
}
std::array<std::array<char, 10>, 10> & Field::getFieldEnemy()
{
	return fieldEnemy_;
}

void Field::statistic(const time_t & startTime, const time_t & endTime, short int & nShipsLiveYour, short int & nShipsLiveEnemy)
{
	struct tm * calendareTime;
	time_t workTime;
	workTime = endTime - startTime;
	calendareTime = std::gmtime(&workTime);

	std::cout << "Статистика: \n\n";
	std::cout << "Время затраченное на игру:  " << calendareTime->tm_hour << ':' << calendareTime->tm_min << ':' << calendareTime->tm_sec << '\n';
	std::cout << "Количество кораблей ваших:   Живых - " << nShipsLiveYour << "  Мертвых - " << 10 - nShipsLiveYour << '\n';
	std::cout << "Количество кораблей врага:   Живых - " << nShipsLiveEnemy << "  Мертвых - " << 10 - nShipsLiveEnemy << '\n';
}

short int Field::calculateIndex(const char & firstIndex)
{
	if ('А' == firstIndex || 'а' == firstIndex)
		return 0;
	else if ('Б' == firstIndex || 'б' == firstIndex)
		return 1;
	else if ('В' == firstIndex || 'в' == firstIndex)
		return 2;
	else if ('Г' == firstIndex || 'г' == firstIndex)
		return 3;
	else if ('Д' == firstIndex || 'д' == firstIndex)
		return 4;
	else if ('Е' == firstIndex || 'е' == firstIndex)
		return 5;
	else if ('Ж' == firstIndex || 'ж' == firstIndex)
		return 6;
	else if ('З' == firstIndex || 'з' == firstIndex)
		return 7;
	else if ('И' == firstIndex || 'и' == firstIndex)
		return 8;
	else if ('К' == firstIndex || 'К' == firstIndex)
		return 9;
}