#include "Ships.h"
#include <iostream>
#include <algorithm>

Ships & Ships::getInstance()
{
	static Ships ships;
	return ships;
}

void Ships::setShips(std::array<std::array<char, 10>, 10> & field)
{
	for (int i = 0; i < 1; ++i)
	{
		setShipWithSize(4, field);
	}

	for (int i = 0; i < 2; ++i)
	{
		setShipWithSize(3, field);
	}

	for (int i = 0; i < 3; ++i)
	{
		setShipWithSize(2, field);
	}

	for (int i = 0; i < 4; ++i)
	{
		setShipWithSize(1, field);
	}
}

void Ships::setShipWithSize(const int & shipSize, std::array<std::array<char, 10>, 10> & field)
{
	bool  isHorizont = std::rand() % 2 == 0;
	int   rowTop = 0;
	int   collumnLeft = 0;

	do
	{
		do
		{
			rowTop = rand() % sizeField_;
		} while (!isHorizont && rowTop > sizeField_ - shipSize);

		do
		{
			collumnLeft = rand() % sizeField_;
		} while (isHorizont && collumnLeft > sizeField_ - shipSize);
	} while (!isGoodShip(shipSize, isHorizont, rowTop, collumnLeft, field));

	if (isHorizont)
	{
		for (int j = collumnLeft; j < collumnLeft + shipSize; ++j)
		{
			field[rowTop][j] = shipSymbol_;
		}
	}
	else//вертикальный
	{
		for (int i = rowTop; i < rowTop + shipSize; ++i)
		{
			field[i][collumnLeft] = shipSymbol_;
		}
	}
}

const bool Ships::isGoodShip(const int & shipSize, const bool & isHorizont, const int & rowTop, const int & collumnLeft, std::array<std::array<char, 10>, 10> & field)
{
	if (isHorizont)
	{
		for (int i = std::max(0, rowTop - 1);
		i <= std::min(sizeField_ - 1, rowTop + 1);
			++i)
		{
			for (int j = std::max(0, collumnLeft - 1);
			j <= std::min(sizeField_ - 1, collumnLeft + shipSize);
				++j)
			{
				if (field[i][j] == shipSymbol_) return false;
			}
		}
		return  true;
	}
	else//вертикальный
	{
		for (int i = std::max(0, rowTop - 1);
		i <= std::min(sizeField_ - 1, rowTop + shipSize);
			++i)
		{
			for (int j = std::max(0, collumnLeft - 1);
			j <= std::min(sizeField_ - 1, collumnLeft + 1);
				++j)
			{
				if (field[i][j] == shipSymbol_) return false;
			}
		}
		return  true;
	}
}

bool Ships::shootYou(const short int secondIndex, const short int & firstIndex, std::array<std::array<char, 10>, 10> & fieldEnemy)
{
	static std::deque<std::pair<int, int>> woundedEnemyShip;

	short int plusI = (firstIndex == 10) ? 0 : 1;
	short int minusI = (firstIndex == 0) ? 0 : 1;
	short int plusJ = (secondIndex == 10) ? 0 : 1;
	short int minusJ = (secondIndex == 0) ? 0 : 1;

	if (fieldEnemy[firstIndex][secondIndex] == -2)
	{
		fieldEnemy[firstIndex][secondIndex] = 88;

		if (fieldEnemy[firstIndex][secondIndex + plusJ] == -2 || fieldEnemy[firstIndex][secondIndex - minusJ] == -2 ||
			fieldEnemy[firstIndex + plusI][secondIndex] == -2 || fieldEnemy[firstIndex - minusI][secondIndex] == -2)
			woundedEnemyShip.push_back(std::make_pair(firstIndex, secondIndex));
		else
			if (woundedEnemyShip.size())
			{
				int i = 0;
				for (std::pair<int, int> & coordinates : woundedEnemyShip)
				{
					if (fieldEnemy[coordinates.first][coordinates.second + plusJ] == -2 || fieldEnemy[coordinates.first][coordinates.second - minusJ] == -2 ||
						fieldEnemy[coordinates.first + plusI][coordinates.second] == -2 || fieldEnemy[coordinates.first - minusI][coordinates.second] == -2)
					{
					}
					else
					{
						woundedEnemyShip.erase(woundedEnemyShip.begin() + 1);
						if (!woundedEnemyShip.size())
							--nShipsLiveEnemy_;
					}
				}
			}
			else
				--nShipsLiveEnemy_;
		return 0;
	}
	else if (fieldEnemy[firstIndex][secondIndex] == 0)
	{
		fieldEnemy[firstIndex][secondIndex] = 249;
		return 1;
	}
	else
		return 1;
}

bool Ships::shootEnemy(std::array<std::array<char, 10>, 10> & fieldYour)
{
	short int firstIndex = std::rand() % 10;
	short int secondIndex = std::rand() % 10;

	if (fieldYour[firstIndex][secondIndex] == -2)
	{
		fieldYour[firstIndex][secondIndex] = 88;
		return 1;
	}
	else if (fieldYour[firstIndex][secondIndex] == 0)
	{
		fieldYour[firstIndex][secondIndex] = 249;
		return 0;
	}
	else
		return 0;
	//static bool isHorizontal = 0;
	//static bool isGotShip = 0;
	//static std::deque<std::pair<int, int>> woundedYourShip;
	//static short int firstIndex = std::rand() % 10;
	//static short int secondIndex = std::rand() % 10;
	//short int plusI = (firstIndex == 10) ? 0 : 1;
	//short int minusI = (firstIndex == 0) ? 0 : 1;
	//short int plusJ = (secondIndex == 10) ? 0 : 1;
	//short int minusJ = (secondIndex == 0) ? 0 : 1;
	//
	//do
	//{
	//	if (isGotShip)
	//	{
	//	}
	//	else
	//	{
	//		if (fieldYour[firstIndex][secondIndex] == -2)
	//		{
	//			fieldYour[firstIndex][secondIndex] = 88;
	//			if (fieldYour[firstIndex][secondIndex + plusJ] == -2 || fieldYour[firstIndex][secondIndex - minusJ] == -2
	//				|| fieldYour[firstIndex + plusI][secondIndex] == -2 || fieldYour[firstIndex - minusI][secondIndex] == -2)
	//			{
	//				woundedYourShip.push_back(std::make_pair(firstIndex, secondIndex));
	//				isGotShip = 1;
	//			}
	//			else
	//				--nShipsLiveYour_;
	//		}
	//	}
	//} while (isGotShip);
	//
	//return 0;
}

short int & Ships::getNShipsLiveYour()
{
	return nShipsLiveYour_;
}

short int & Ships::getNShipsLiveEnemy()
{
	return nShipsLiveEnemy_;
}