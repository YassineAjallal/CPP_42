#include "PmergeMe.hpp"

// Constructors
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	this->_vectorNumbers = copy._vectorNumbers;
	this->_listNumbers = copy._listNumbers;
	this->_jacobsthalnumbers = copy._jacobsthalnumbers;
	this->_data_manage_clock = copy._data_manage_clock;
}

// Destructor
PmergeMe::~PmergeMe() {}

// Operators
PmergeMe & PmergeMe::operator=(const PmergeMe &assign)
{
    this->_vectorNumbers = assign._vectorNumbers;
	this->_listNumbers = assign._listNumbers;
	this->_jacobsthalnumbers = assign._jacobsthalnumbers;
	this->_data_manage_clock = assign._data_manage_clock;
    return *this;
}

int PmergeMe::jacobsthal(int n)
{
	return (std::pow(2, n) - std::pow(-1, n)) / 3;
}

void PmergeMe::jacobsthalCalc(size_t vect_pairs_size)
{
	this->_jacobsthalnumbers.push_back(jacobsthal(0));
	for (size_t i = 3; i < vect_pairs_size; i++)
	{
		if (jacobsthal(i) >= (int)vect_pairs_size)
		{
			this->_jacobsthalnumbers.push_back(vect_pairs_size - 1);
			break;
		}
		this->_jacobsthalnumbers.push_back(jacobsthal(i));
	}
}

void PmergeMe::insertRangeOfElement(vectOfPairs &vect_pairs, vectOfIterator &mainChainPair, int i)
{
	std::vector<int>::iterator it;
	if (vect_pairs.size() <= 3)
	{
		for (int j = vect_pairs.size() - 1; j > 0; j--)
		{
			it = std::upper_bound(this->_vectorNumbers.begin(), mainChainPair[j], vect_pairs[j].first);
			this->_vectorNumbers.insert(it, vect_pairs[j].first);
			for (size_t k = 0; k < mainChainPair.size(); k++)
				if (it <= mainChainPair[k])
					mainChainPair[k]++;		
		}
		return;
	}
	for (int j = this->_jacobsthalnumbers[i]; j > this->_jacobsthalnumbers[i - 1]; j--)
	{
		it = std::upper_bound(this->_vectorNumbers.begin(), mainChainPair[j], vect_pairs[j].first);
		this->_vectorNumbers.insert(it, vect_pairs[j].first);
		for (size_t k = 0; k < mainChainPair.size(); k++)
			if (it <= mainChainPair[k])
				mainChainPair[k]++;		
	}
}
void PmergeMe::insertIntoMainChain(vectOfPairs &vect_pairs, bool odd_size)
{
	vectOfIterator mainChainPair;
	int last_value;
	int size = this->_vectorNumbers.size();
	last_value = this->_vectorNumbers.back();
	this->_vectorNumbers.clear();
	this->_vectorNumbers.reserve(size);
	size_t i;
	std::vector<int>::iterator it;
	this->_vectorNumbers.push_back(vect_pairs[0].first);
	for(i = 0; i < vect_pairs.size(); i++)
	{
		this->_vectorNumbers.push_back(vect_pairs[i].second);
		mainChainPair.push_back(this->_vectorNumbers.begin() + i + 1);
	}
	if (vect_pairs.size() <= 3)
	{
		this->insertRangeOfElement(vect_pairs, mainChainPair, 0);
		if (odd_size == true)
		{
			it = std::upper_bound(this->_vectorNumbers.begin(), this->_vectorNumbers.end(), last_value);
			this->_vectorNumbers.insert(it, last_value);
		}
		return ;
	}
	this->jacobsthalCalc(vect_pairs.size());
	for (size_t i = 1; i < this->_jacobsthalnumbers.size(); i++)
		this->insertRangeOfElement(vect_pairs, mainChainPair, i);
	if (odd_size == true)
	{
		it = std::upper_bound(this->_vectorNumbers.begin(), this->_vectorNumbers.end(), last_value);
		this->_vectorNumbers.insert(it, last_value);
	}
}

void PmergeMe::groupElementIntoPairs(vectOfPairs &vect_pairs, bool odd_size)
{
	for (size_t i = 0; i < this->_vectorNumbers.size() - odd_size; i += 2)
		vect_pairs.push_back(std::make_pair(this->_vectorNumbers[i], this->_vectorNumbers[i + 1]));
	for (size_t i = 0; i < vect_pairs.size(); i++)
		if (vect_pairs[i].first > vect_pairs[i].second)
			std::swap(vect_pairs[i].first, vect_pairs[i].second);
}
void PmergeMe::sortPairByGreater(vectOfPairs &vect_pairs, size_t i)
{
	if (i >= vect_pairs.size() - 1)
        return;
    for (size_t j = i + 1; j < vect_pairs.size(); j++)
    {
        if (vect_pairs[j].second < vect_pairs[i].second)
            std::swap(vect_pairs[i], vect_pairs[j]);
    }
    this->sortPairByGreater(vect_pairs, i + 1);
}
void PmergeMe::mergeInsertVector()
{
	bool odd_size;
	vectOfPairs vect_pairs;
	this->_vectorNumbers.size() % 2 == 0 ? odd_size = false : odd_size = true;
	this->groupElementIntoPairs(vect_pairs, odd_size);
	this->sortPairByGreater(vect_pairs, 0);
	this->insertIntoMainChain(vect_pairs, odd_size);
}

void PmergeMe::insertIntoMainChainList(listOfPairs &list_pairs, bool odd_size)
{
	listOfIterator mainChainPair;
	int last_value;
	last_value = this->_listNumbers.back();
	this->_listNumbers.clear();
	std::list<int>::iterator it;
	this->_listNumbers.push_back((*list_pairs.begin()).first);
	for (listOfPairs::iterator it = list_pairs.begin(); it != list_pairs.end(); ++it)
	{
		std::list<int>::iterator listIt = this->_listNumbers.begin();
		++listIt;
		this->_listNumbers.push_back((*it).second);
		std::advance(listIt, std::distance(list_pairs.begin(), it));
		mainChainPair.push_back(listIt);
	}
	if (list_pairs.size() <= 3)
	{
		this->insertRangeOfElementList(list_pairs, mainChainPair, 0);
		if (odd_size)
		{
			it = std::upper_bound(this->_listNumbers.begin(), this->_listNumbers.end(), last_value);
			this->_listNumbers.insert(it, last_value);
		}
		return ;
	}
	for (size_t i = 1; i < this->_jacobsthalnumbers.size(); i++)
	{
		this->insertRangeOfElementList(list_pairs, mainChainPair, i);
	}
	if (odd_size)
	{
		it = std::upper_bound(this->_listNumbers.begin(), this->_listNumbers.end(), last_value);
		this->_listNumbers.insert(it, last_value);
	}
}

void PmergeMe::insertRangeOfElementList(listOfPairs &list_pairs, listOfIterator &mainChainPair, int i)
{
	std::list<int>::iterator it;
	if (list_pairs.size() <= 3)
	{
		listOfPairs::iterator itj = list_pairs.end();
		--itj;
		for (; itj != list_pairs.begin(); --itj)
		{
			it = std::upper_bound(this->_listNumbers.begin(), mainChainPair[std::distance(list_pairs.begin(), itj)], (*itj).first);
			this->_listNumbers.insert(it, (*itj).first);
		}
		return;
	}
	for (int j = this->_jacobsthalnumbers[i]; j > this->_jacobsthalnumbers[i - 1]; j--)
	{
		listOfPairs::iterator itj = list_pairs.begin();
		std::advance(itj, j);
		it = std::upper_bound(this->_listNumbers.begin(), mainChainPair[j], (*itj).first);
		this->_listNumbers.insert(it, (*itj).first);
	}

}

void PmergeMe::groupElementIntoPairsList(listOfPairs &list_pairs, bool odd_size)
{
	std::list<int>::iterator it, ite;
	listOfPairs::iterator itp;
	ite = this->_listNumbers.end();
	odd_size ? --ite : ite;
	for (it = this->_listNumbers.begin(); it != ite; ++it)
		list_pairs.push_back(std::make_pair(*it, *(++it)));
	for (itp = list_pairs.begin(); itp != list_pairs.end(); ++itp)
		if (itp->first > itp->second)
			std::swap(itp->first, itp->second);
}

void PmergeMe::sortPairListByGreater(listOfPairs &list_pairs, listOfPairs::iterator it)
{
	listOfPairs::iterator itj, iti;
	iti =  list_pairs.end();
	if (it == --iti)
		return;
	itj = it;
	for (++itj; itj != list_pairs.end(); ++itj)
	{
		if ((*itj).second < (*it).second)
            std::swap((*it), (*itj));
	}
	this->sortPairListByGreater(list_pairs, ++it);
}

void PmergeMe::mergeInsertList()
{
	bool odd_size;
	listOfPairs list_pairs;
	this->_listNumbers.size() % 2 == 0 ? odd_size = false : odd_size = true;
	this->groupElementIntoPairsList(list_pairs, odd_size);
	this->sortPairListByGreater(list_pairs, list_pairs.begin());
	this->insertIntoMainChainList(list_pairs, odd_size);
}

int	PmergeMe::checkValidNumber(std::string numberString)
{
	long int number;
	std::vector<int>::iterator it;
	char *end;
	number = strtod(numberString.c_str(), &end);
	if (*end != '\0')
		return (std::cout << "Error : invalid number." << std::endl, -1);
	if (number < 0)
		return (std::cout << "Error : negative number." << std::endl, -1);
	if (number > INT_MAX)
		return (std::cout << "Error : number is out of range." << std::endl, -1);
	return (number);
}

int PmergeMe::parseInput(std::string input)
{
	std::stringstream ss(input);
	clock_t start;
	std::string line;
	long int number;
	start = clock();
	while(!ss.eof())
	{
		std::getline(ss, line, ' ');
		if (line.length() != 0)
		{
			number = this->checkValidNumber(line);
			if (number < 0)
				return (0);
			this->_vectorNumbers.push_back(number);
		}
	}
	if (this->_vectorNumbers.size() < 2)
		return (std::cout << "Error : more than 2 numbers required" << std::endl, 0);
	this->_listNumbers.assign(this->_vectorNumbers.begin(), this->_vectorNumbers.end());
	this->_data_manage_clock = clock() - start;
	return (1);
}

void PmergeMe::printNumbers()
{
	std::list<int>::iterator it;
	for (it = this->_listNumbers.begin(); it != this->_listNumbers.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::showResult(std::string input)
{
	clock_t start;
	clock_t end_vect;
	clock_t end_list;
	if (!parseInput(input))
		return;
	std::cout << "Before : ";
	this->printNumbers(); 
	start = clock();
	this->mergeInsertVector();
	end_vect = clock() - start;
	start = clock();
	this->mergeInsertList();
	end_list = clock() - start;
	std::cout << "after  : ";
	this->printNumbers(); 
	std::cout << "Time to process a range of " << this->_vectorNumbers.size() << " elements with std::vector : " << (double)(end_vect) + this->_data_manage_clock << " us." << std::endl;
	std::cout << "Time to process a range of " << this->_listNumbers.size() << " elements with std::list : " << (double)(end_list) + this->_data_manage_clock << " us." << std::endl;

}