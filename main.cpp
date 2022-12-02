/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:55:33 by nosterme          #+#    #+#             */
/*   Updated: 2022/09/12 15:55:33 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory>
#include <iostream>
#include <iterator>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <bitset>
#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include "set.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"
#include "pair.hpp"
#include "make_pair.hpp"
#include "tests/myallocator.hpp"
#include "tests/mystruct.hpp"
#include "tests/mycompare.hpp"

int	main( void )
{
	ft::map< int, int >					map;

	map[2] = 3;
	ft::map< int, int >::iterator		mapit = map.begin();
	ft::map< int, int >::const_iterator	mapcit;

	mapcit = mapit;

	std::cout << mapcit->second << std::endl;

	ft::set< int >				set;
	ft::set< int > const		set_const;

	ft::set< int >::iterator	s_it = set_const.begin();

	if ( s_it == set_const.end() )
		std::cout << "begin == end" << std::endl;

	std::cout << "set:" << std::endl;
	set.max_size();
	std::cout << "set is empty: " << std::boolalpha << set.empty() << std::endl;
	std::cout << "size: " << set.size() << std::endl;

	bool										result;
	ft::pair< ft::set< int >::iterator, bool >	pair;

	pair = set.insert( 5 );
	s_it = pair.first;
	result = pair.second;
	if ( result )
		std::cout << *s_it << " inserted" << std::endl;
	pair = set.insert( 12 );
	if ( pair.second )
		std::cout << *( pair.first ) << " inserted" << std::endl;
	pair = set.insert( 7 );
	if ( pair.second )
		std::cout << *( pair.first ) << " inserted" << std::endl;
	pair = set.insert( -1 );
	if ( pair.second )
		std::cout << *( pair.first ) << " inserted" << std::endl;
	pair = set.insert( 7 );
	if ( !( pair.second ) )
		std::cout << *( pair.first ) << " not inserted" << std::endl;

	std::cout << "set is empty: " << std::boolalpha << set.empty() << std::endl;
	std::cout << "size: " << set.size() << std::endl;
	for ( ft::set< int >::iterator	it = set.begin(); it != set.end(); ++it )
		std::cout << *it << " ";
	std::cout << std::endl;
	for ( ft::set< int >::reverse_iterator	it = set.rbegin(); it != set.rend(); ++it )
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;

	if ( ++( set.begin() ) != ( set.begin() )++ )
		std::cout << "++( set.begin() ) != ( set.begin() )++" << std::endl;
	if ( --( set.end() ) != ( set.end() )-- )
		std::cout << "--( set.end() ) != ( set.end() )--" << std::endl;
	std::cout << std::endl;
	if ( ++( set.rbegin() ) != ( set.rbegin() )++ )
		std::cout << "++( set.rbegin() ) != ( set.rbegin() )++" << std::endl;
	if ( --( set.rend() ) != ( set.rend() )-- )
		std::cout << "--( set.rend() ) != ( set.rend() )--" << std::endl;
	std::cout << std::endl;

	std::cout << "*( set.begin() ): " << *( set.begin() ) << std::endl;
	std::cout << "*( set.begin() ): " << *( set.begin() ) << std::endl;
	std::cout << "*( --( set.end() ) ): " << *( --( set.end() ) ) << std::endl;
	std::cout << "*( --( set.end() ) ): " << *( --( set.end() ) ) << std::endl;
	std::cout << std::endl;

	std::cout << "*( set.rbegin() ): " << *( set.rbegin() ) << std::endl;
	std::cout << "*( set.rbegin() ): " << *( set.rbegin() ) << std::endl;
	std::cout << "*( --( set.rend() ) ): " << *( --( set.rend() ) ) << std::endl;
	std::cout << "*( --( set.rend() ) ): " << *( --( set.rend() ) ) << std::endl;
	std::cout << std::endl;

	if ( *( set.begin() ) == *( --( set.rend() ) ) )
		std::cout << "*( set.begin() ) == *( --( set.rend() ) )" << std::endl;
	std::cout << std::endl;

	if ( *( --( set.end() ) ) == *( set.rbegin() ) )
		std::cout << "*( --( set.end() ) ) == *( set.rbegin() )" << std::endl;
	std::cout << std::endl;


	return ( 0 );
}

/*
#include <iostream>
#include <string>
#include <deque>
#if 0 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include "map.hpp"
	#include "stack.hpp"
	#include "vector.hpp"
#endif

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

int main(int argc, char** argv) {
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	std::vector<std::string> vector_str;
	std::vector<int> vector_int;
	std::stack<int> stack_int;
	std::vector<Buffer> vector_buffer;
	std::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	std::map<int, int> map_int;

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	std::vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}
	
	for (int i = 0; i < COUNT; ++i)
	{
		map_int.insert(std::make_pair(rand(), rand()));
	}

	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand();
		sum += map_int[access];
	}
	std::cout << "should be constant with the same seed: " << sum << std::endl;

	{
		std::map<int, int> copy = map_int;
	}
	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;
	return (0);
}
*/
