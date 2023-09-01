#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <climits>

typedef struct s_date
{
	std::string year;
	std::string month;
	std::string day;
	int n_year;
	int n_month;
	int n_day;

} t_date;

class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange & operator=(const BitcoinExchange &assign);
		~BitcoinExchange();
		void bitcoinExchange(std::string csv_file, std::string input_file);

		class BitcoinExchangeExceptions
		{
			private :
				std::string _exception_msg;
			public :
				BitcoinExchangeExceptions(std::string exception_msg);
				const char* what() const throw();
		};
		// void print_csv_file();

	private:
		std::string date_to_search;
		void read_csv_file(std::string file_name);
		void result(std::string date, double value);
		int extract_date(std::string date);
		int	check_valid_day(int month, int year);
		double btc_value_error_handling(std::string value_string);
		std::map<std::string, double> csv_data;

};

#endif // BitcoinExchange_HPP
