#include "Karen.hpp"

Karen::Karen()
{

}

Karen::~Karen()
{

}

void	Karen::debug()
{
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << "\n" << \
				"I just love it!" << "\n";
}

void	Karen::info()
{
	std::cout << "I cannot believe adding extra bacon cost more money." << "\n" << \
				"You don’t put enough! If you did I would not have to ask for it!" << "\n";
}

void	Karen::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free." << "\n" << \
				"I’ve been coming here for years and you just started working here last month." << "\n";
}

void	Karen::error()
{
	std::cout << "This is unacceptable, I want to speak to the manager now." << "\n";
}

void	Karen::complain( std::string level )
{
	std::string	levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
	};

	// 이러한 형식을 사용해서 배열안에 넣을 수 있음.
	void	(Karen::*action[4]) (void) = {
		&Karen::debug,
		&Karen::info,
		&Karen::warning,
		&Karen::error,
	};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*action[i])();
			return ;
		}
	}
}