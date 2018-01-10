#pragma once

#include <deque>
#include <array>

class Ships
{
	short int nShipsLiveYour_ = 10;
	short int nShipsLiveEnemy_ = 10;
	const char shipSymbol_ = 254;
	const short int sizeField_ = 10;
	Ships() = default;
	~Ships() = default;
	Ships(const Ships &) = delete;
	Ships & operator=(const Ships &) = delete;
	void  setShipWithSize(const int &, std::array<std::array<char, 10>, 10> &);
	const bool isGoodShip(const int &, const bool &, const int &, const int &, std::array<std::array<char, 10>, 10> &);
public:
	void setShips(std::array<std::array<char, 10>, 10> &);
	static Ships & getInstance();
	bool shootYou(const short int, const short int &, std::array<std::array<char, 10>, 10> &);
	bool shootEnemy(std::array<std::array<char, 10>, 10> & fieldYour);
	short int & getNShipsLiveYour();
	short int & getNShipsLiveEnemy();
};