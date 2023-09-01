#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <climits>
#include <list>
#include <cmath>

typedef	std::vector< std::vector<int>::iterator > vectOfIterator;
typedef	std::vector<std::pair<int, int> > vectOfPairs;
typedef std::list<std::pair<int, int> > listOfPairs;
typedef std::vector< std::list<int>::iterator > listOfIterator;


class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		~PmergeMe();
		PmergeMe & operator=(const PmergeMe &assign);

		// vector merge-insertion sort
		void groupElementIntoPairs(vectOfPairs &vect_pairs, bool odd_size); // group element into sorted pairs
		void sortPairByGreater(vectOfPairs &vect_pairs, size_t i); // sort vector by greater
		void insertIntoMainChain(vectOfPairs &vect_pairs, bool odd_size);
		void insertRangeOfElement(vectOfPairs &vect_pairs, vectOfIterator &mainChainPair, int i);
		void mergeInsertVector();

		// list merge-insertion sort
		void groupElementIntoPairsList(listOfPairs &list_pairs, bool odd_size); // group element into sorted pairs
		void sortPairListByGreater(listOfPairs &list_pairs, listOfPairs::iterator it);
		void insertIntoMainChainList(listOfPairs &list_pairs, bool odd_size);
		void insertRangeOfElementList(listOfPairs &list_pairs, listOfIterator &mainChainPair, int i);
		void mergeInsertList();

		// jacobsthal sequence tools
		int jacobsthal(int n);
		void jacobsthalCalc(size_t vect_pairs_size);

		// parsing && validation
		int parseInput(std::string input);
		int	checkValidNumber(std::string numberString);

		// print tools
		void showResult(std::string input);
		void printNumbers();
	private:
		std::vector<int>	_vectorNumbers;
		std::list <int>		_listNumbers;
		std::vector<int>	_jacobsthalnumbers;
		clock_t				_data_manage_clock;
};

#endif // PmergeMe_HPP
