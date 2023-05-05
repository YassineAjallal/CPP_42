#include <iostream>

void aligned(std::string str)
{
	int i;
	int length;

	i = 0;
	length = str.length();
	if (length < 10)
	{
		while (i < 10 - length)
		{
			std::cout << " ";
			i++;
		}
		std::cout << str;
	}
	else if (length > 10)
		std::cout << str.substr(0, 9) << ".";
	else
		std::cout << str;

}

class Contact {
public : 
	std::string first_name;
	std::string last_name;
	std::string	nickname;
	std::string darkest_secret;
	long long 	phone_number;

	void fill_info()
	{
		std::cout << "\e[0;34mfirst name :\e[0;00m ";
		std::cin >> this->first_name;
		std::cout << "\e[0;34mlast name :\e[0;00m ";
		std::cin >> this->last_name;
		std::cout << "\e[0;34mnickname :\e[0;00m ";
		std::cin >> this->nickname;
		std::cout << "\e[0;34mdarkest secret :\e[0;00m ";
		std::cin >> this->darkest_secret;
		std::cout << "\e[0;34mphone number :\e[0;00m ";
		std::cin >> this->phone_number;
	}
	void print_info()
	{
		std::cout << "\e[1;33mfirst name :\e[0;00m " << this->first_name << std::endl;
		std::cout << "\e[1;33mlast name :\e[0;00m " << this->last_name << std::endl;
		std::cout << "\e[1;33mnickname :\e[0;00m " << this->nickname << std::endl;
		std::cout << "\e[1;33mdarkest secret :\e[0;00m " << this->darkest_secret << std::endl;
		std::cout << "\e[1;33mphone number :\e[0;00m " << this->phone_number << std::endl;
	}
};

class PhoneBook {
public :
	Contact contacts[3];
	int nb_contact;
	int old_contact;
	void print_contact()
	{
		int i;
		int search;

		i = 0;
		while (i < this->nb_contact)
		{
			std::cout << i << " | ";
			aligned(this->contacts[i].first_name);
			std::cout << " | ";
			aligned(this->contacts[i].last_name);
			std::cout << " | ";
			aligned(this->contacts[i].nickname);
			std::cout << " | " << std::endl;
			i++;
		}
		std::cout << "\e[0;36msearch :\e[0;00m ";
		std::cin >> search;
		if (search > this->nb_contact || search < 0)
			std::cout << "contact not found" << std::endl;
		else
			this->contacts[search].print_info();
	}
};


int main()
{
	PhoneBook book;
	std::string command;
	book.nb_contact = 0;
	book.old_contact = 0;


		while (1)
		{
			std::cout << "\e[1;32mEnter a command (ADD, SEARCH, EXIT) : \e[0;00m";
			std::cin >> command;
			if (command == "ADD")
			{
				if (book.nb_contact > 2)
				{
					book.contacts[book.old_contact].fill_info();
					book.old_contact++;
					if (book.old_contact > 2)
						book.old_contact = 0;
				}
				else
				{
					book.contacts[book.nb_contact].fill_info();
					book.nb_contact++;
				}
			}
			else if (command == "SEARCH")
			{
				book.print_contact();
			}
			else if (command == "EXIT")
				return (0);
			else
				std::cout << "The command is INVALID"<< std::endl;
		}

	return 0;
}

