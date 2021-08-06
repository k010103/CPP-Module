#include "phone_book.hpp"

void	line_eof(void)
{
	if(std::cin.eof())
	{
		std::cout << "\ngood bye :D" << "\n";
		exit(1);
	}
}

void				explanation(void)
{
	std::cout << "📖 phone_book 📖" << "\n";
	std::cout << "EXIT : program quits." << "\n";
	std::cout << "ADD : new contact’s information." << "\n";
	std::cout << "SEARCH : look at the phone_book." << "\n";
}

// & 를 유동적으로 받을 수는 없을까..?
void				search_contact(phone_book (&phone_book)[8], int count)
{
	std::string	index;

	while (true)
	{
		std::cout << "Enter index to get full page (EXIT) : ";
		getline(std::cin, index);
		line_eof();
		if (index == "EXIT")
		{
			std::cout << ":D" << "\n";
			break ;
		}
		else if (("0" <= index && index <= "9") || index <= "0")
		{
			if (index <= "0" || index > std::to_string(count))
				std::cout << "Index range is too large. [MAX : " << count << "]" << "\n";
			else
				phone_book[std::stoi(index) - 1].cout_contact();
		}
		else
			std::cout << "Undefined Command." << "\n";
	}
}

void				all_search(phone_book (&phone_book)[8], int count, int search_check)
{
	if (search_check)
		count = 8;
	if (count == 0)
		std::cout << "There is no data. " << "\n";
	else
	{
		std::cout << "--------------------------------------------" << "\n";
		std::cout << "     index|first name| last name|  nickname|" << "\n";
		for (int i = 0; i < count; i++)
		{
			std::cout << "         " << i + 1 << "|";
			phone_book[i].SEARCH();
		}
		std::cout << "--------------------------------------------" << "\n";
		search_contact(phone_book, count);
	}
}

int					main(void)
{
	std::string		input;
	phone_book		phone_book[8];
	int				count = 0;
	int				search_check = 0;

	explanation();
	while (true)
	{
		std::cout << "📖 : ";
		std::getline(std::cin, input);
		line_eof();
		if (input == "EXIT")
			break ;
		else if (input == "ADD")
		{
			phone_book[count].ADD();
			std::cout << "It's been saved in number " << count + 1 << "\n";
			count++;
			if (count >= 8)
				search_check = 1;
		}
		else if (input == "SEARCH")
			all_search(phone_book, count, search_check);
		else
		{
			std::cout << "Invalid input value. 🥲  (EXIT, ADD, SEARCH)" << "\n";
		}
		if (count >= 8)
			count = 0;
	}
	std::cout << "good bye :D" << "\n";
	return (0);
}
