#include "BitcoinExchange.hpp"


// Constructors
BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

// Destructor
BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &assign)
{
	this->date_to_search = assign.date_to_search;
    this->csv_data = assign.csv_data;
    return (*this);
}

BitcoinExchange::~BitcoinExchange(){}

// Operators
void BitcoinExchange::bitcoinExchange(std::string csv_file, std::string input_file_name)
{
	this->read_csv_file(csv_file);
	std::ifstream input_file;
	std::string line;
	size_t delemiter_pos;
	double value;
	std::string date;
	input_file.open(input_file_name.c_str(), std::ios::in);
	if (!input_file.is_open())
		throw BitcoinExchangeExceptions("Error : cannot open (database | input) file");
	std::getline(input_file, line);
	if (line != "date | value")
		throw BitcoinExchangeExceptions("invalid csv head format");
	while (!input_file.eof())
	{
		std::getline(input_file, line);
		line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
		if (line.length() != 0)
		{
			delemiter_pos = line.find("|");
			if (delemiter_pos == std::string::npos)
			{
				std::cout << "Error: bad input => " << line << std::endl;
				continue;
			}
			date = line.substr(0, delemiter_pos);
			if (!this->extract_date(date))
			{
				std::cout << "Error: bad input => " << date << std::endl;
				continue;
			}
			value = this->btc_value_error_handling(line.substr(delemiter_pos + 1, line.length() - delemiter_pos + 1));
			if (value != -1)
				this->result(date, value);
		}
		else
			if (!input_file.eof())
				std::cout << "Error: bad input => no infos found" << std::endl;
	}
}

double BitcoinExchange::btc_value_error_handling(std::string value_string)
{
	double value;
	char *end;
	value = strtod(value_string.c_str(), &end);
	if (value_string.length() == 0)
		std::cout << "Error: invalid value." << std::endl;
	else if (*end != '\0')
		std::cout << "Error: value is not a valid number => " << value_string << std::endl;
	else if (value < 0)
		std::cout << "Error: not a positive number." << std::endl;
	else if (value > 1000)
		std::cout << "Error: too large a number." << std::endl;
	else
		return (value);
	return (-1);
}

void BitcoinExchange::result(std::string date, double value)
{
	std::map<std::string, double>::iterator it;
	this->date_to_search = date;
	it = this->csv_data.find(date);
	if (it == this->csv_data.end())
	{
		it = this->csv_data.lower_bound(date);
		--it;
	}
	std::cout << date << " => " << value << " = " << it->second * value << std::endl;
}

void BitcoinExchange::read_csv_file(std::string file_name)
{
	std::ifstream csv_file;
	std::string line;
	size_t delemiter_pos;
	double value;
	char *end;
	std::string date, value_str;
	csv_file.open(file_name.c_str(), std::ios::in);
	if (!csv_file.is_open())
		throw BitcoinExchangeExceptions("Error : cannot open (database | input) file");
	std::getline(csv_file, line);
	if (line != "date,exchange_rate")
		throw BitcoinExchangeExceptions("invalid csv head format");
	while (!csv_file.eof())
	{
		std::getline(csv_file, line);
		line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
		if (line.length() != 0)
		{
			delemiter_pos = line.find(",");
			if (delemiter_pos == std::string::npos)
				throw BitcoinExchangeExceptions("invalid csv infos format");
			date = line.substr(0, delemiter_pos);
			if (!this->extract_date(date))
				throw BitcoinExchangeExceptions("invalid date");
			value_str = line.substr(delemiter_pos + 1, line.length() - delemiter_pos + 1);
			value = strtod(value_str.c_str(), &end);
			if (*end != '\0' || value_str.length() == 0)
				throw BitcoinExchangeExceptions("invalid exchange rate");
			this->csv_data.insert(std::pair<std::string, double>(date, value));
		}
		else
			if (!csv_file.eof())
				throw BitcoinExchangeExceptions("empty line in csv file");
	}
}

int BitcoinExchange::check_valid_day(int month, int year)
{
	if (month == 2) {
        if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
            return 29;
        else
            return 28;
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8
        || month == 10 || month == 12)
        return 31;
    else
        return 30;
}

int BitcoinExchange::extract_date(std::string date_csv)
{
	int pos;
	t_date str_date;
	char *end;
	pos = 0;
	time_t t = time(NULL);
	tm *const timeInfo = localtime(&t);
	if (date_csv.find("-", pos) == std::string::npos)
		return (0);
	str_date.year = date_csv.substr(pos, date_csv.find("-", pos) - pos);
	pos = date_csv.find("-", pos) + 1;
	str_date.n_year = strtol(str_date.year.c_str(), &end, 10);
	if (str_date.year.length() != 4 || *end != '\0' || str_date.n_year < 2009 || str_date.n_year > 1900 + timeInfo->tm_year)
		return (0);
	if (date_csv.find("-", pos) == std::string::npos)
		return (0);
	str_date.month = date_csv.substr(pos, date_csv.find("-", pos) - pos);
	pos = date_csv.find("-", pos) + 1;
	str_date.n_month = strtol(str_date.month.c_str(), &end, 10);
	if (str_date.month.length() != 2 || *end != '\0' || str_date.n_month > 12 || str_date.n_month < 1)
		return (0);
	str_date.day = date_csv.substr(pos, date_csv.length() - pos);
	str_date.n_day = strtol(str_date.day.c_str(), &end, 10);
	if (str_date.day.length() != 2 || *end != '\0' || str_date.n_day > this->check_valid_day(str_date.n_month, str_date.n_year) || str_date.n_day < 1)
		return (0);
	return (1);
}



/*------------------------- Exception Implimentation -------------------------*/

BitcoinExchange::BitcoinExchangeExceptions::BitcoinExchangeExceptions(std::string exception_msg) : _exception_msg("Error : " + exception_msg) {}

const char* BitcoinExchange::BitcoinExchangeExceptions::what() const throw()
{
	return (this->_exception_msg.c_str());
}