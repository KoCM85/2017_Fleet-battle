#pragma once

#include <array>

class Field
{
	std::array<std::array<char, 10>, 10> fieldYour_;
	std::array<std::array<char, 10>, 10> fieldEnemy_;
	Field() = default;
	~Field() = default;
	Field(const Field &) = delete;
	Field & operator=(const Field &) = delete;
public:
	static Field & getInstance();
	void Draw(const bool &);
	std::array<std::array<char, 10>, 10> & getFieldYour();
	std::array<std::array<char, 10>, 10> & getFieldEnemy();
	void statistic(const time_t &, const time_t &, short int &, short int &);
	short int calculateIndex(const char &);
};