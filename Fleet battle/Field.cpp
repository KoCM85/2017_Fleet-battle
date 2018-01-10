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

	std::cout << "\t  ��: \t\t\t\t\t\t  ����:\n\n";
	std::cout << "  |� � � � � � � � � �|\t\t\t\t  |� � � � � � � � � �|";
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

	std::cout << "����������: \n\n";
	std::cout << "����� ����������� �� ����:  " << calendareTime->tm_hour << ':' << calendareTime->tm_min << ':' << calendareTime->tm_sec << '\n';
	std::cout << "���������� �������� �����:   ����� - " << nShipsLiveYour << "  ������� - " << 10 - nShipsLiveYour << '\n';
	std::cout << "���������� �������� �����:   ����� - " << nShipsLiveEnemy << "  ������� - " << 10 - nShipsLiveEnemy << '\n';
}

short int Field::calculateIndex(const char & firstIndex)
{
	if ('�' == firstIndex || '�' == firstIndex)
		return 0;
	else if ('�' == firstIndex || '�' == firstIndex)
		return 1;
	else if ('�' == firstIndex || '�' == firstIndex)
		return 2;
	else if ('�' == firstIndex || '�' == firstIndex)
		return 3;
	else if ('�' == firstIndex || '�' == firstIndex)
		return 4;
	else if ('�' == firstIndex || '�' == firstIndex)
		return 5;
	else if ('�' == firstIndex || '�' == firstIndex)
		return 6;
	else if ('�' == firstIndex || '�' == firstIndex)
		return 7;
	else if ('�' == firstIndex || '�' == firstIndex)
		return 8;
	else if ('�' == firstIndex || '�' == firstIndex)
		return 9;
}