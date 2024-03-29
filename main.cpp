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
#include <bitset>
#include <ctime>
#if SWITCH
	#include <vector>
	#include <map>
	#include <stack>
	#include <set>
	namespace ft = std;
#else
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
#endif
#include "tests/myallocator.hpp"
#include "tests/mystruct.hpp"
#include "tests/mycompare.hpp"

#include <string>
#include <deque>
#include <cstdlib>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public ft::stack<T>
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

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

template< typename T >
void	vector_check_sizes( ft::vector< T > const & v )
{
	std::cout << "size: " << v.size() << std::endl;
	std::cout << "capacity: " << v.capacity() << std::endl;

	return ;
}

template< typename T >
void	vector_operator_check( ft::vector< T > const & v )
{
	vector_check_sizes( v );
	for ( std::size_t	count = 0; count < v.size(); ++count )
		std::cout << v[ count ] << " ";
	std::cout << std::endl;

	return ;
}

template< typename T >
void	vector_iterator_check( ft::vector< T > & v )
{
	vector_check_sizes( v );
	for ( typename ft::vector< T >::iterator it = v.begin(); it != v.end(); ++it )
		std::cout << *it << " ";
	std::cout << std::endl;

	return ;
}

int	main( int argc, char ** argv )
{

	clock_t const	begin_time = clock();

	{

		if (argc != 2)
		{
			std::cerr << "Usage: ./test seed" << std::endl;
			std::cerr << "Provide a seed please" << std::endl;
			std::cerr << "Count value:" << COUNT << std::endl;
			return 1;
		}
		const int seed = atoi(argv[1]);
		srand(seed);

		ft::vector<std::string> vector_str;
		ft::vector<int> vector_int;
		ft::stack<int> stack_int;
		ft::vector<Buffer> vector_buffer;
		ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
		ft::map<int, int> map_int;

		for (int i = 0; i < COUNT; i++)
		{
			vector_buffer.push_back(Buffer());
		}

		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer[idx].idx = 5;
		}
		ft::vector<Buffer>().swap(vector_buffer);

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
			map_int.insert(ft::make_pair(rand(), rand()));
		}

		int sum = 0;
		for (int i = 0; i < 10000; i++)
		{
			int access = rand();
			sum += map_int[access];
		}
		std::cout << "should be constant with the same seed: " << sum << std::endl;

		{
			ft::map<int, int> copy = map_int;
		}
		MutantStack<char> iterable_stack;
		for (char letter = 'a'; letter <= 'z'; letter++)
			iterable_stack.push(letter);
		for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
		{
			std::cout << *it;
		}
		std::cout << std::endl;

	}

	{

		ft::map< int, int >					map;

		map[2] = 3;
		ft::map< int, int >::iterator		mapit = map.begin();
		ft::map< int, int >::const_iterator	mapcit;

		mapcit = mapit;

		std::cout << mapcit->second << std::endl;

		ft::map< ft::pair< int, long double >, int >	m_pair;
		ft::map< int, char >					m_int;
		ft::map< double, char >					m_char;

		std::cout << "pair:\t\t" << m_pair.max_size() << std::endl;
		std::cout << "int:\t\t" << m_int.max_size() << std::endl;
		std::cout << "char:\t\t" << m_char.max_size() << std::endl;

		ft::set< ft::pair< long, int > >	s_pair;
		ft::set< long >						s_long;
		ft::set< long double >				s_long_double;

		std::cout << "pair:\t\t" << s_pair.max_size() << std::endl;
		std::cout << "long:\t\t" << s_long.max_size() << std::endl;
		std::cout << "long double:\t" << s_long_double.max_size() << std::endl;

		ft::set< int >				set;

		std::cout << "set:" << std::endl;
		std::cout << "set is empty: " << std::boolalpha << set.empty() << std::endl;
		std::cout << "size: " << set.size() << std::endl;

		ft::pair< ft::set< int >::iterator, bool >	pair;

		pair = set.insert( 5 );
		if ( pair.second )
			std::cout << *( pair.first ) << " inserted" << std::endl;
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

		ft::set< int > const		set_const( set );

		ft::set< int >::iterator	s_it = set_const.begin();

		s_it = pair.first;
		std::cout << *( s_it ) << std::endl;

		std::cout << "set is empty: " << std::boolalpha << set.empty() << std::endl;
		std::cout << "size: " << set.size() << std::endl;
		for ( ft::set< int >::iterator	it = set.begin(); it != set.end(); ++it )
			std::cout << *it << " ";
		std::cout << std::endl;
		for ( ft::set< int >::const_reverse_iterator	it = set_const.rbegin(); it != set_const.rend(); ++it )
			std::cout << *it << " ";
		std::cout << std::endl << std::endl;

		if ( ++( set.begin() ) != ( set.begin() )++ )
			std::cout << "++( set.begin() ) != ( set.begin() )++" << std::endl;
		if ( --( set_const.end() ) != ( set_const.end() )-- )
			std::cout << "--( set_const.end() ) != ( set_const.end() )--" << std::endl;
		std::cout << std::endl;
		if ( ++( set_const.rbegin() ) != ( set_const.rbegin() )++ )
			std::cout << "++( set_const.rbegin() ) != ( set_const.rbegin() )++" << std::endl;
		if ( --( set.rend() ) != ( set.rend() )-- )
			std::cout << "--( set.rend() ) != ( set.rend() )--" << std::endl;
		std::cout << std::endl;

		std::cout << "*( set.begin() ): " << *( set.begin() ) << std::endl;
		std::cout << "*( set_const.begin() ): " << *( set_const.begin() ) << std::endl;
		std::cout << "*( --( set.end() ) ): " << *( --( set.end() ) ) << std::endl;
		std::cout << "*( --( set_const.end() ) ): " << *( --( set_const.end() ) ) << std::endl;
		std::cout << std::endl;

		std::cout << "*( set.rbegin() ): " << *( set.rbegin() ) << std::endl;
		std::cout << "*( set_const.rbegin() ): " << *( set_const.rbegin() ) << std::endl;
		std::cout << "*( --( set.rend() ) ): " << *( --( set.rend() ) ) << std::endl;
		std::cout << "*( --( set_const.rend() ) ): " << *( --( set_const.rend() ) ) << std::endl;
		std::cout << std::endl;

		if ( *( set.begin() ) == *( --( set.rend() ) ) )
			std::cout << "*( set.begin() ) == *( --( set.rend() ) )" << std::endl;
		std::cout << std::endl;

		if ( *( --( set_const.end() ) ) == *( set_const.rbegin() ) )
			std::cout << "*( --( set_const.end() ) ) == *( set_const.rbegin() )" << std::endl;
		std::cout << std::endl;

		ft::set< int, mycompare< int >, myallocator< int > > set1;

		set1.insert( 73 );
		set1.insert( 42 );

		if ( set1.count( 42 ) == 1 )
			std::cout << "42" << std::endl;

		set1.insert( 73 );

		if ( set1.count( 73) == 1 )
			std::cout << "73" << std::endl;
		if ( set1.count( 5 ) == 0 )
			std::cout << "no 5" << std::endl;
		std::cout << std::endl;

		ft::set< int >			set2( ++( set_const.begin() ), --( set_const.end() ) );

		std::cout << "set2: " << std::endl;
		std::cout << "set2 is empty: " << std::boolalpha << set2.empty() << std::endl;
		std::cout << "size: " << set2.size() << std::endl;
		for ( ft::set< int >::const_iterator	it = set2.begin(); it != set2.end(); ++it )
			std::cout << *it << " ";
		std::cout << std::endl;
		for ( ft::set< int >::reverse_iterator	it = set2.rbegin(); it != set2.rend(); ++it )
			std::cout << *it << " ";
		std::cout << std::endl << std::endl;

		ft::vector< int >		v5;

		v5.push_back( 10 );
		v5.push_back( 4 );
		v5.push_back( -93 );
		v5.push_back( 7 );

		ft::set< int >			set3( v5.begin(), v5.end() );

		std::cout << "set3: " << std::endl;
		std::cout << "set3 is empty: " << std::boolalpha << set3.empty() << std::endl;
		std::cout << "size: " << set3.size() << std::endl;
		for ( ft::set< int >::iterator	it = set3.begin(); it != set3.end(); ++it )
			std::cout << *it << " ";
		std::cout << std::endl;
		for ( ft::set< int >::reverse_iterator	it = set3.rbegin(); it != set3.rend(); ++it )
			std::cout << *it << " ";
		std::cout << std::endl << std::endl;

		ft::vector< int >		v6( set3.begin(), set3.end() );

		for ( ft::vector< int >::iterator	it = v6.begin(); it != v6.end(); ++it )
			std::cout << *it << " ";
		std::cout << std::endl << std::endl;

		set2 = set;

		std::cout << "set2: " << std::endl;
		std::cout << "set2 is empty: " << std::boolalpha << set2.empty() << std::endl;
		std::cout << "size: " << set2.size() << std::endl;
		for ( ft::set< int >::const_iterator	it = set2.begin(); it != set2.end(); ++it )
			std::cout << *it << " ";
		std::cout << std::endl;
		for ( ft::set< int >::reverse_iterator	it = set2.rbegin(); it != set2.rend(); ++it )
			std::cout << *it << " ";
		std::cout << std::endl << std::endl;

		ft::set< int >::iterator	position;

		position = set2.insert( set2.begin(), 1 );

		std::cout << *position << std::endl;

		position = set2.insert( position, 0 );

		std::cout << *position << std::endl;

		position = set2.insert( position, 2 );

		std::cout << *position << std::endl;

		position = set2.insert( position, 0 );

		std::cout << *position << std::endl;

		position = set2.insert( position, 6 );

		std::cout << *position << std::endl;

		for ( ft::set< int >::const_iterator	it = set2.begin(); it != set2.end(); ++it )
			std::cout << *it << " ";
		std::cout << std::endl;

		set2.insert( set2.begin(), position );

		for ( ft::set< int >::iterator	it = set2.begin(); it != set2.end(); ++it )
			std::cout << *it << " ";
		std::cout << std::endl;

		set2.insert( v5.begin(), v5.end() );

		for ( ft::set< int >::const_iterator	it = set2.begin(); it != set2.end(); ++it )
			std::cout << *it << " ";
		std::cout << std::endl;

		position = set2.find( 5 );
		set2.erase( position );

		position = set2.find( 2 );
		set2.erase( ++( set2.begin() ), position );

		for ( ft::set< int >::iterator	it = set2.begin(); it != set2.end(); ++it )
			std::cout << *it << " ";
		std::cout << std::endl;

		if ( set2.erase( 7 ) == 1 )
			std::cout << "erased 7" << std::endl;

		if ( set2.erase( 7 ) == 0 )
			std::cout << "no 7 found" << std::endl;

		std::cout << "set2: " << std::endl;
		for ( ft::set< int >::iterator	it = set2.begin(); it != set2.end(); ++it )
			std::cout << *it << " ";
		std::cout << std::endl << std::endl;

		set.swap( set2 );

		std::cout << "set: " << std::endl;
		for ( ft::set< int >::iterator	it = set.begin(); it != set.end(); ++it )
			std::cout << *it << " ";
		std::cout << std::endl << std::endl;

		std::cout << "set2: " << std::endl;
		for ( ft::set< int >::iterator	it = set2.begin(); it != set2.end(); ++it )
			std::cout << *it << " ";
		std::cout << std::endl << std::endl;

		set2.clear();

		if ( set2.empty() )
			std::cout << "set2 is empty" << std::endl << std::endl;

		std::swap( set, set2 );

		std::cout << "set: " << std::endl;
		if ( set.empty() )
			std::cout << "set is empty" << std::endl << std::endl;;

		std::cout << "set2: " << std::endl;
		for ( ft::set< int >::iterator	it = set2.begin(); it != set2.end(); ++it )
			std::cout << *it << " ";
		std::cout << std::endl << std::endl;

		set.insert( set2.begin(), set2.end() );

		std::cout << "set: " << std::endl;
		for ( ft::set< int >::const_iterator	it = set.begin(); it != set.end(); ++it )
			std::cout << *it << " ";
		std::cout << std::endl << std::endl;

		ft::set< int >::const_iterator		const_it;

		const_it = set.find( 4 );

		std::cout << *const_it << std::endl;

		const_it = set.find( 23 );

		if ( const_it == set.end() )
			std::cout << "const_it == end" << std::endl;

		ft::pair< ft::set< int >::iterator,\
				ft::set< int >::iterator >			pair_it;

		pair_it = set.equal_range( 7 );
		position = set.lower_bound( 7 );

		if ( pair_it.first == position )
			std::cout << "pair_it.first == position" << std::endl;
		std::cout << *position << std::endl;

		position = set.upper_bound( 7 );
		if ( pair_it.second == position )
			std::cout << "pair_it.second == position" << std::endl;
		std::cout << *position << std::endl;

		ft::pair< ft::set< int >::const_iterator,\
				ft::set< int >::const_iterator >		pair_cit;

		pair_cit = set.equal_range( 4 );
		const_it = set.lower_bound( 4 );

		if ( pair_cit.first == const_it )
			std::cout << "pair_cit.first == const_it" << std::endl;
		std::cout << *const_it << std::endl;

		const_it = set.upper_bound( 4 );
		if ( pair_cit.second == const_it )
			std::cout << "pair_cit.second == const_it" << std::endl;
		std::cout << *const_it << std::endl;

		ft::set< int >::key_compare		key_comp = set.key_comp();

		if ( key_comp( 1, 2 ) )
			std::cout << "1 < 2" << std::endl;
		if ( !key_comp( 2, 2 ) )
			std::cout << "!( 2 < 2 )" << std::endl;
		if ( !key_comp( 2, 1 ) )
			std::cout << "!( 2 < 1 )" << std::endl;

		ft::set< int >::value_compare		val_comp = set.value_comp();
		int									val1( 1 );
		int									val2( 2 );

		if ( val_comp( val1, val2 ) )
			std::cout << "1 < 2" << std::endl;
		if ( !val_comp( val2, val2 ) )
			std::cout << "!( 2 < 2 )" << std::endl;
		if ( !val_comp( val2, val1 ) )
			std::cout << "!( 2 < 1 )" << std::endl;

		std::cout << "set: " << std::endl;
		for ( ft::set< int >::iterator	it = set.begin(); it != set.end(); ++it )
			std::cout << *it << " ";
		std::cout << std::endl << std::endl;

		std::cout << "set3: " << std::endl;
		for ( ft::set< int >::iterator	it = set3.begin(); it != set3.end(); ++it )
			std::cout << *it << " ";
		std::cout << std::endl << std::endl;

		if ( set == set3 )
			std::cout << "set == set3" << std::endl;
		if ( set != set3 )
			std::cout << "set != set3" << std::endl;
		if ( set < set3 )
			std::cout << "set < set3" << std::endl;
		if ( set > set3 )
			std::cout << "set > set3" << std::endl;
		if ( set <= set3 )
			std::cout << "set <= set3" << std::endl;
		if ( set >= set3 )
			std::cout << "set >= set3" << std::endl;

		if ( set3 == set )
			std::cout << "set3 == set" << std::endl;
		if ( set3 != set )
			std::cout << "set3 != set" << std::endl;
		if ( set3 < set )
			std::cout << "set3 < set" << std::endl;
		if ( set3 > set )
			std::cout << "set3 > set" << std::endl;
		if ( set3 <= set )
			std::cout << "set3 <= set" << std::endl;
		if ( set3 >= set )
			std::cout << "set3 >= set" << std::endl;

		if ( set == set )
			std::cout << "set == set" << std::endl;
		if ( set != set )
			std::cout << "set != set" << std::endl;
		if ( set < set )
			std::cout << "set < set" << std::endl;
		if ( set > set )
			std::cout << "set > set" << std::endl;
		if ( set <= set )
			std::cout << "set <= set" << std::endl;
		if ( set >= set )
			std::cout << "set >= set" << std::endl;

		ft::set< int >::allocator_type	alloc = set.get_allocator();

		int *							p = alloc.allocate( 1 );

		alloc.construct( p, val1 );

		std::cout << *p << std::endl;

		alloc.destroy( p );
		alloc.deallocate( p, 1 );

	}

	{

		ft::map< unsigned int, int, mycompare< int >, myallocator< ft::pair< unsigned int const, int > > > map;

		map.insert( ft::make_pair( 50, 70 ) );
		map.insert( ft::make_pair( 4, 10 ) );

		if ( map.count( 4 ) )
			std::cout << map[ 4 ] << std::endl;
		if ( map.count( 50 ) )
			std::cout << map[ 50 ] << std::endl;

	}

	{

		ft::stack< int >	stack;

		if ( stack.empty() )
			std::cout << "stack is empty" << std::endl;
		std::cout << "size: " << stack.size() << std::endl;

		stack.push( 5 );

		std::cout << stack.top() << std::endl;

		stack.push( 2 );

		std::cout << stack.top() << std::endl;

		if ( !( stack.empty() ) )
			std::cout << "stack is not empty" << std::endl;
		std::cout << "size: " << stack.size() << std::endl;

		ft::vector< int >						container( 5, 3 );

		ft::stack< int, ft::vector< int > >		stack1( container );

		std::cout << stack1.top() << std::endl;
		std::cout << "size: " << stack1.size() << std::endl;

		ft::stack< char, ft::vector< char > >	stack2;

		stack2.push( 'r' );

		std::cout << stack2.top() << std::endl;

		ft::stack< int >						stack3( stack );

		std::cout << stack3.top() << std::endl;
		std::cout << "size: " << stack3.size() << std::endl;

		stack3.pop();

		std::cout << stack3.top() << std::endl;
		std::cout << "size: " << stack3.size() << std::endl;

		stack3.top() = 14;

		std::cout << stack3.top() << std::endl;
		std::cout << "size: " << stack3.size() << std::endl;

		ft::stack< int > const					stack4( stack3 );
		int const &								i = stack4.top();

		std::cout << i << std::endl;
		std::cout << "size: " << stack3.size() << std::endl;

		if ( stack == stack3 )
			std::cout << "stack == stack3" << std::endl;
		if ( stack != stack3 )
			std::cout << "stack != stack3" << std::endl;
		if ( stack < stack3 )
			std::cout << "stack < stack3" << std::endl;
		if ( stack <= stack3 )
			std::cout << "stack <= stack3" << std::endl;
		if ( stack > stack3 )
			std::cout << "stack > stack3" << std::endl;
		if ( stack >= stack3 )
			std::cout << "stack >= stack3" << std::endl;

		if ( stack3 == stack )
			std::cout << "stack3 == stack" << std::endl;
		if ( stack3 != stack )
			std::cout << "stack3 != stack" << std::endl;
		if ( stack3 < stack )
			std::cout << "stack3 < stack" << std::endl;
		if ( stack3 <= stack )
			std::cout << "stack3 <= stack" << std::endl;
		if ( stack3 > stack )
			std::cout << "stack3 > stack" << std::endl;
		if ( stack3 >= stack )
			std::cout << "stack3 >= stack" << std::endl;

		if ( stack == stack )
			std::cout << "stack == stack" << std::endl;
		if ( stack != stack )
			std::cout << "stack != stack" << std::endl;
		if ( stack < stack )
			std::cout << "stack < stack" << std::endl;
		if ( stack <= stack )
			std::cout << "stack <= stack" << std::endl;
		if ( stack > stack )
			std::cout << "stack > stack" << std::endl;
		if ( stack >= stack )
			std::cout << "stack >= stack" << std::endl;

	}

	{

		ft::map< unsigned int, int >	map;

		std::cout << "map: max_size: " << map.max_size() << std::endl << std::endl;

		map[ 3 ] = 3;
		std::cout << "map[ 3 ]: " << map[ 3 ] << std::endl;
		std::cout << "size: " << map.size() << std::endl;
		map.at( 3 ) = 6;
		std::cout << "map.at( 3 ): " << map.at( 3 ) << std::endl;
		std::cout << "size: " << map.size() << std::endl;
		map[ 2 ];
		std::cout << "map[ 2 ]: " << map[ 2 ] << std::endl;
		std::cout << "size: " << map.size() << std::endl;
		map.at( 3 );
		std::cout << "map.at( 3 ): " << map.at( 3 ) << std::endl;
		std::cout << "size: " << map.size() << std::endl;
		std::cout << std::endl;

		ft::map< unsigned int, int >	map1;

		std::cout << "map1:" << std::endl;
		std::cout << "size: " << map1.size() << std::endl;
		if ( map1.empty() )
			std::cout << "map1 is empty" << std::endl;
		if ( map1.begin() == map1.end() )
			std::cout << "map1.begin() == map1.end()" << std::endl;
		for ( size_t	count = 1; count < 10; ++count )
			map1[ count ] = ( count * -1 );
		std::cout << "size: " << map1.size() << std::endl;
		if ( !( map1.empty() ) )
			std::cout << "map1 is not empty" << std::endl;
		if ( map1.begin() != map1.end() )
			std::cout << "map1.begin() != map1.end()" << std::endl;
		for ( size_t	count = 1; count < 10; ++count )
			std::cout << map1[ count ] << " ";
		std::cout << std::endl << std::endl;

		ft::map< unsigned int, int >	map2( map1 );

		std::cout << "map2:" << std::endl;
		std::cout << "size: " << map2.size() << std::endl;
		for ( size_t	count = 1; count < 10; ++count )
			std::cout << map2[ count ] << " ";
		std::cout << std::endl << std::endl;
		
		ft::map< unsigned int, int >	map3;

		map3 = map1;
		std::cout << "map3:" << std::endl;
		std::cout << "size: " << map3.size() << std::endl;
		for ( size_t	count = 1; count < 10; ++count )
			std::cout << map3[ count ] << " ";
		std::cout << std::endl << std::endl;

		ft::map< unsigned int, int >	map4( ++( map1.begin() ), --( map1.end() ) );

		std::cout << "map4:" << std::endl;
		std::cout << "size: " << map4.size() << std::endl;
		for ( size_t	count = 2; count < 9; ++count )
			std::cout << map4[ count ] << " ";
		std::cout << std::endl << std::endl;

		std::cout << "map2:" << std::endl;
		std::cout << "size: " << map2.size() << std::endl;
		for ( size_t	count = 1; count < 10; ++count )
			std::cout << map2.at( count ) << " ";
		std::cout << std::endl;
		try
		{
			std::cout << map2.at( 0 ) << std::endl;
		}
		catch( std::out_of_range const & exc )
		{
			std::cout << "out_of_range" << '\n';
		}
		try
		{
			map2.at( 10 ) = -10;
		}
		catch( std::out_of_range const & exc )
		{
			std::cout << "out_of_range" << '\n';
		}
		std::cout << std::endl;

		if ( ++( map.begin() ) != ( map.begin() )++ )
			std::cout << "++( map.begin() ) != ( map.begin() )++" << std::endl;
		if ( --( map.end() ) != ( map.end() )-- )
			std::cout << "--( map.end() ) != ( map.end() )--" << std::endl;
		std::cout << std::endl;
		if ( ++( map.rbegin() ) != ( map.rbegin() )++ )
			std::cout << "++( map.rbegin() ) != ( map.rbegin() )++" << std::endl;
		if ( --( map.rend() ) != ( map.rend() )-- )
			std::cout << "--( map.rend() ) != ( map.rend() )--" << std::endl;
		std::cout << std::endl;

		map[ 4 ] = 23;
		map[ 12 ] = 9;
		map[ 1 ] = -14;

		std::cout << "map:" << std::endl;
		std::cout << "size: " << map.size() << std::endl;
		for ( ft::map< unsigned int, int >::iterator	it = map.begin(); it != map.end(); ++it )
			std::cout << it->first << " ";
		std::cout << std::endl;
		for ( ft::map< unsigned int, int >::reverse_iterator	it = map.rbegin(); it != map.rend(); ++it )
			std::cout << ( *it ).first << " ";
		std::cout << std::endl << std::endl;

		std::cout << "( *( map.begin() ) ).first: " << ( *( map.begin() ) ).first << std::endl;
		std::cout << "( ( map.begin() ) )->second: " << ( ( map.begin() ) )->second << std::endl;
		std::cout << "( --( map.end() ) )->first: " << ( --( map.end() ) )->first << std::endl;
		std::cout << "( --( map.end() ) )->second: " << ( --( map.end() ) )->second << std::endl;
		std::cout << std::endl;

		std::cout << "( ( map.rbegin() ) )->first: " << ( ( map.rbegin() ) )->first << std::endl;
		std::cout << "( *( map.rbegin() ) ).second: " << ( *( map.rbegin() ) ).second << std::endl;
		std::cout << "( --( map.rend() ) )->first: " << ( --( map.rend() ) )->first << std::endl;
		std::cout << "( --( map.rend() ) )->second: " << ( --( map.rend() ) )->second << std::endl;
		std::cout << std::endl;

		std::cout << "( map.begin() )->first: " << ( map.begin() )->first << std::endl;
		std::cout << "( map.begin() )->second: " << ( map.begin() )->second << std::endl;
		std::cout << "( --( map.rend() ) )->first: " << ( --( map.rend() ) )->first << std::endl;
		std::cout << "( --( map.rend() ) )->second: " << ( --( map.rend() ) )->second << std::endl;
		if ( ( map.begin() )->first == ( --( map.rend() ) )->first )
			std::cout << "( map.begin() )->first == ( --( map.rend() ) )->first" << std::endl;
		std::cout << std::endl;

		std::cout << "( --( map.end() ) )->first: " << ( --( map.end() ) )->first << std::endl;
		std::cout << "( --( map.end() ) )->second: " << ( --( map.end() ) )->second << std::endl;
		std::cout << "( map.rbegin() )->first: " << ( map.rbegin() )->first << std::endl;
		std::cout << "( map.rbegin() )->second: " << ( map.rbegin() )->second << std::endl;
		if ( ( --( map.end() ) )->first == ( map.rbegin() )->first )
			std::cout << "( --( map.end() ) )->first == ( map.rbegin() )->first" << std::endl;
		std::cout << std::endl;

		ft::pair< unsigned int, int >				pair( 3, 4 );

		map.insert( pair );

		std::cout << "size: " << map.size() << std::endl;
		for ( ft::map< unsigned int, int >::iterator	it = map.begin(); it != map.end(); ++it )
			std::cout << it->first << "\t";
		std::cout << std::endl;
		for ( ft::map< unsigned int, int >::iterator	it = map.begin(); it != map.end(); ++it )
			std::cout << it->second << "\t";
		std::cout << std::endl;

		map.insert( ft::make_pair( 6, -24 ) );

		std::cout << "size: " << map.size() << std::endl;
		for ( ft::map< unsigned int, int >::iterator	it = map.begin(); it != map.end(); ++it )
			std::cout << it->first << "\t";
		std::cout << std::endl;
		for ( ft::map< unsigned int, int >::iterator	it = map.begin(); it != map.end(); ++it )
			std::cout << it->second << "\t";
		std::cout << std::endl;

		ft::pair< ft::map< unsigned int, int >::iterator, bool >	ret;

		ret = map.insert( ft::make_pair( 7, 40 ) );

		std::cout << std::boolalpha << ret.second << std::endl;
		std::cout << ret.first->first << " " << ret.first->second << std::endl;

		ret = map.insert( ft::make_pair( 7, 5 ) );

		std::cout << ret.second << std::endl;
		std::cout << ret.first->first << " " << ret.first->second << std::endl;

		std::cout << "size: " << map.size() << std::endl;
		for ( ft::map< unsigned int, int >::iterator	it = map.begin(); it != map.end(); ++it )
			std::cout << it->first << "\t";
		std::cout << std::endl;
		for ( ft::map< unsigned int, int >::iterator	it = map.begin(); it != map.end(); ++it )
			std::cout << it->second << "\t";
		std::cout << std::endl;

		map.insert( ft::make_pair( 13, 50 ) );

		std::cout << "size: " << map.size() << std::endl;
		for ( ft::map< unsigned int, int >::iterator	it = map.begin(); it != map.end(); ++it )
			std::cout << it->first << "\t";
		std::cout << std::endl;
		for ( ft::map< unsigned int, int >::iterator	it = map.begin(); it != map.end(); ++it )
			std::cout << it->second << "\t";
		std::cout << std::endl;

		ft::map< unsigned int, int >::iterator		position = map.find( 7 );
		std::cout << position->first << " " << position->second << std::endl;

		position = map.insert( position, ft::make_pair( 9, 83 ) );

		std::cout << position->first << " " << position->second << std::endl;

		position = map.insert( position, ft::make_pair( 9, 37 ) );

		std::cout << position->first << " " << position->second << std::endl;

		map.insert( position, ft::make_pair( 8, 73 ) );

		std::cout << "size: " << map.size() << std::endl;
		for ( ft::map< unsigned int, int >::iterator	it = map.begin(); it != map.end(); ++it )
			std::cout << it->first << "\t";
		std::cout << std::endl;
		for ( ft::map< unsigned int, int >::iterator	it = map.begin(); it != map.end(); ++it )
			std::cout << it->second << "\t";
		std::cout << std::endl;

		std::cout << "map2:" << std::endl;
		std::cout << "size: " << map2.size() << std::endl;
		for ( ft::map< unsigned int, int >::iterator	it = map2.begin(); it != map2.end(); ++it )
			std::cout << it->first << "\t";
		std::cout << std::endl;
		for ( ft::map< unsigned int, int >::iterator	it = map2.begin(); it != map2.end(); ++it )
			std::cout << it->second << "\t";
		std::cout << std::endl;

		map2.insert( position, map.end() );

		std::cout << "map2:" << std::endl;
		std::cout << "size: " << map2.size() << std::endl;
		for ( ft::map< unsigned int, int >::iterator	it = map2.begin(); it != map2.end(); ++it )
			std::cout << it->first << "\t";
		std::cout << std::endl;
		for ( ft::map< unsigned int, int >::iterator	it = map2.begin(); it != map2.end(); ++it )
			std::cout << it->second << "\t";
		std::cout << std::endl;

		std::cout << "map:" << std::endl;

		std::cout << position->first << " " << position->second << std::endl;

		map.erase( position );

		std::cout << "size: " << map.size() << std::endl;
		for ( ft::map< unsigned int, int >::iterator	it = map.begin(); it != map.end(); ++it )
			std::cout << it->first << "\t";
		std::cout << std::endl;
		for ( ft::map< unsigned int, int >::iterator	it = map.begin(); it != map.end(); ++it )
			std::cout << it->second << "\t";
		std::cout << std::endl;

		map.erase( map.begin() );

		std::cout << map.begin()->first << " " << map.begin()->second << std::endl;

		std::cout << "size: " << map.size() << std::endl;
		for ( ft::map< unsigned int, int >::iterator	it = map.begin(); it != map.end(); ++it )
			std::cout << it->first << "\t";
		std::cout << std::endl;
		for ( ft::map< unsigned int, int >::iterator	it = map.begin(); it != map.end(); ++it )
			std::cout << it->second << "\t";
		std::cout << std::endl;

		std::cout << map.count( 12 ) << std::endl;

		position = map.find( 8 );

		map.erase( position, ( --( map.end() ) ) );

		std::cout << map.count( 12 ) << std::endl;

		std::cout << "size: " << map.size() << std::endl;
		for ( ft::map< unsigned int, int >::iterator	it = map.begin(); it != map.end(); ++it )
			std::cout << it->first << "\t";
		std::cout << std::endl;
		for ( ft::map< unsigned int, int >::iterator	it = map.begin(); it != map.end(); ++it )
			std::cout << it->second << "\t";
		std::cout << std::endl;

		if ( map.erase( 2 ) == 1 )
			std::cout << "erase" << std::endl;

		if ( map.erase( 2 ) == 0 )
			std::cout << "no erase" << std::endl;

		if ( map.erase( 4 ) == 1 )
			std::cout << "erase" << std::endl;

		if ( map.erase( 11 ) == 0 )
			std::cout << "no erase" << std::endl;

		std::cout << map.begin()->first << " " << map.begin()->second << std::endl;

		std::cout << "size: " << map.size() << std::endl;
		for ( ft::map< unsigned int, int >::iterator	it = map.begin(); it != map.end(); ++it )
			std::cout << it->first << "\t";
		std::cout << std::endl;
		for ( ft::map< unsigned int, int >::iterator	it = map.begin(); it != map.end(); ++it )
			std::cout << it->second << "\t";
		std::cout << std::endl;

		std::cout << "map1:" << std::endl;
		std::cout << "size: " << map1.size() << std::endl;
		for ( ft::map< unsigned int, int >::iterator	it = map1.begin(); it != map1.end(); ++it )
			std::cout << it->first << "\t";
		std::cout << std::endl;
		for ( ft::map< unsigned int, int >::iterator	it = map1.begin(); it != map1.end(); ++it )
			std::cout << it->second << "\t";
		std::cout << std::endl;

		std::cout << "map2:" << std::endl;
		std::cout << "size: " << map2.size() << std::endl;
		for ( ft::map< unsigned int, int >::const_iterator	it = map2.begin(); it != map2.end(); ++it )
			std::cout << it->first << "\t";
		std::cout << std::endl;
		for ( ft::map< unsigned int, int >::const_iterator	it = map2.begin(); it != map2.end(); ++it )
			std::cout << it->second << "\t";
		std::cout << std::endl;

		std::cout << "map3:" << std::endl;
		std::cout << "size: " << map3.size() << std::endl;
		for ( ft::map< unsigned int, int >::iterator	it = map3.begin(); it != map3.end(); ++it )
			std::cout << it->first << "\t";
		std::cout << std::endl;
		for ( ft::map< unsigned int, int >::iterator	it = map3.begin(); it != map3.end(); ++it )
			std::cout << it->second << "\t";
		std::cout << std::endl;

		std::cout << "map4:" << std::endl;
		std::cout << "size: " << map4.size() << std::endl;
		for ( ft::map< unsigned int, int >::iterator	it = map4.begin(); it != map4.end(); ++it )
			std::cout << it->first << "\t";
		std::cout << std::endl;
		for ( ft::map< unsigned int, int >::iterator	it = map4.begin(); it != map4.end(); ++it )
			std::cout << it->second << "\t";
		std::cout << std::endl;

		if ( !( map3.empty() ) )
			std::cout << "map3 not empty" << std::endl;

		map3.clear();

		if ( map3.empty() )
			std::cout << "map3 empty" << std::endl;

		map1.swap( map2 );

		std::swap( map4, map3 );

		map4.swap( map2 );

		if ( map2.empty() )
			std::cout << "map2 empty" << std::endl;

		std::cout << "map1:" << std::endl;
		std::cout << "size: " << map1.size() << std::endl;
		for ( ft::map< unsigned int, int >::const_iterator	it = map1.begin(); it != map1.end(); ++it )
			std::cout << it->first << "\t";
		std::cout << std::endl;
		for ( ft::map< unsigned int, int >::iterator	it = map1.begin(); it != map1.end(); ++it )
			std::cout << it->second << "\t";
		std::cout << std::endl;

		std::cout << "map2:" << std::endl;
		std::cout << "size: " << map2.size() << std::endl;
		for ( ft::map< unsigned int, int >::const_iterator	it = map2.begin(); it != map2.end(); ++it )
			std::cout << it->first << "\t";
		std::cout << std::endl;
		for ( ft::map< unsigned int, int >::iterator	it = map2.begin(); it != map2.end(); ++it )
			std::cout << it->second << "\t";
		std::cout << std::endl;

		std::cout << "map3:" << std::endl;
		std::cout << "size: " << map3.size() << std::endl;
		for ( ft::map< unsigned int, int >::iterator	it = map3.begin(); it != map3.end(); ++it )
			std::cout << it->first << "\t";
		std::cout << std::endl;
		for ( ft::map< unsigned int, int >::iterator	it = map3.begin(); it != map3.end(); ++it )
			std::cout << it->second << "\t";
		std::cout << std::endl;

		std::cout << "map4:" << std::endl;
		std::cout << "size: " << map4.size() << std::endl;
		for ( ft::map< unsigned int, int >::iterator	it = map4.begin(); it != map4.end(); ++it )
			std::cout << it->first << "\t";
		std::cout << std::endl;
		for ( ft::map< unsigned int, int >::iterator	it = map4.begin(); it != map4.end(); ++it )
			std::cout << it->second << "\t";
		std::cout << std::endl;

		map4.clear();

		map2.swap( map4 );

		std::cout << "map2:" << std::endl;
		std::cout << "size: " << map2.size() << std::endl;
		for ( ft::map< unsigned int, int >::iterator	it = map2.begin(); it != map2.end(); ++it )
			std::cout << it->first << "\t";
		std::cout << std::endl;
		for ( ft::map< unsigned int, int >::iterator	it = map2.begin(); it != map2.end(); ++it )
			std::cout << it->second << "\t";
		std::cout << std::endl;

		std::cout << "map4:" << std::endl;
		std::cout << "size: " << map4.size() << std::endl;
		for ( ft::map< unsigned int, int >::iterator	it = map4.begin(); it != map4.end(); ++it )
			std::cout << it->first << "\t";
		std::cout << std::endl;
		for ( ft::map< unsigned int, int >::const_iterator	it = map4.begin(); it != map4.end(); ++it )
			std::cout << it->second << "\t";
		std::cout << std::endl;

		ft::map< unsigned int, int >::iterator			m_it = map.find( 7 );
		ft::map< unsigned int, int >::const_iterator	m_cit = map.find( 13 );

		std::cout << m_it->first << " " << m_it->second << std::endl;
		std::cout << m_cit->first << " " << m_cit->second << std::endl;

		m_it = map.find( 8 );
		m_cit = map.find( 14 );

		if ( m_it == map.end() )
			std::cout << "m_it == map.end()" << std::endl;
		if ( m_cit == map.end() )
			std::cout << "m_cit == map.end()" << std::endl;

		ft::pair< ft::map< unsigned int, int >::iterator,\
				  ft::map< unsigned int, int >::iterator >			pair_it;

		pair_it = map.equal_range( 7 );
		m_it = map.lower_bound( 7 );

		if ( pair_it.first == m_it )
			std::cout << "pair_it.first == m_it" << std::endl;
		std::cout << m_it->first << " " << m_it->second << std::endl;

		m_it = map.upper_bound( 7 );
		if ( pair_it.second == m_it )
			std::cout << "pair_it.second == m_it" << std::endl;
		std::cout << m_it->first << " " << m_it->second << std::endl;

		ft::pair< ft::map< unsigned int, int >::const_iterator,\
				  ft::map< unsigned int, int >::const_iterator >	pair_cit;

		pair_cit = map.equal_range( 4 );
		m_cit = map.lower_bound( 4 );

		if ( pair_cit.first == m_cit )
			std::cout << "pair_cit.first == m_cit" << std::endl;
		std::cout << m_cit->first << " " << m_cit->second << std::endl;

		m_cit = map.upper_bound( 4 );
		if ( pair_cit.second == m_cit )
			std::cout << "pair_cit.second == m_cit" << std::endl;
		std::cout << m_cit->first << " " << m_cit->second << std::endl;

		ft::map< unsigned int, int >::key_compare		key_comp = map.key_comp();

		if ( key_comp( 1, 2 ) )
			std::cout << "1 < 2" << std::endl;
		if ( !key_comp( 2, 2 ) )
			std::cout << "!( 2 < 2 )" << std::endl;
		if ( !key_comp( 2, 1 ) )
			std::cout << "!( 2 < 1 )" << std::endl;

		ft::map< unsigned int, int >::value_compare		val_comp = map.value_comp();
		ft::pair< unsigned int, int >					val1( ft::make_pair( 1, 2 ) );
		ft::pair< unsigned int, int >					val2( ft::make_pair( 2, 1 ) );

		if ( val_comp( val1, val2 ) )
			std::cout << "1 < 2" << std::endl;
		if ( !val_comp( val2, val2 ) )
			std::cout << "!( 2 < 2 )" << std::endl;
		if ( !val_comp( val2, val1 ) )
			std::cout << "!( 2 < 1 )" << std::endl;

		if ( map1 == map2 )
			std::cout << "map1 == map2" << std::endl;
		if ( map1 != map2 )
			std::cout << "map1 != map2" << std::endl;
		if ( map1 < map2 )
			std::cout << "map1 < map2" << std::endl;
		if ( map1 > map2 )
			std::cout << "map1 > map2" << std::endl;
		if ( map1 <= map2 )
			std::cout << "map1 <= map2" << std::endl;
		if ( map1 >= map2 )
			std::cout << "map1 >= map2" << std::endl;

		if ( map2 == map1 )
			std::cout << "map2 == map1" << std::endl;
		if ( map2 != map1 )
			std::cout << "map2 != map1" << std::endl;
		if ( map2 < map1 )
			std::cout << "map2 < map1" << std::endl;
		if ( map2 > map1 )
			std::cout << "map2 > map1" << std::endl;
		if ( map2 <= map1 )
			std::cout << "map2 <= map1" << std::endl;
		if ( map2 >= map1 )
			std::cout << "map2 >= map1" << std::endl;

		if ( map1 == map1 )
			std::cout << "map1 == map1" << std::endl;
		if ( map1 != map1 )
			std::cout << "map1 != map1" << std::endl;
		if ( map1 < map1 )
			std::cout << "map1 < map1" << std::endl;
		if ( map1 > map1 )
			std::cout << "map1 > map1" << std::endl;
		if ( map1 <= map1 )
			std::cout << "map1 <= map1" << std::endl;
		if ( map1 >= map1 )
			std::cout << "map1 >= map1" << std::endl;

		ft::map< unsigned int, int >::allocator_type	alloc = map.get_allocator();

		ft::pair< unsigned int const, int > *			p = alloc.allocate( 1 );

		alloc.construct( p, val1 );

		std::cout << p->first << " " << p->second << std::endl;

		alloc.destroy( p );
		alloc.deallocate( p, 1 );

	}

	{

		ft::map< int, ft::pair< int, char > >						map1;
		ft::map< ft::pair< int, char const * >, int >				map2;
		ft::map< ft::pair< int, char >, ft::pair< int, char > >		map3;

		ft::vector< ft::pair< int, char > >							vector;

		ft::pair< int, char >										pair( 2, 'f' );

		vector.push_back( pair );

		std::cout << "vector[ 0 ].first: " << vector[ 0 ].first << std::endl;
		std::cout << "vector[ 0 ].second: "<< vector[ 0 ].second << std::endl;

		map1[ 0 ] = pair;
		map2[ ft::make_pair( 3, "pair") ] = 4;
		map3[ pair ] = pair;

		std::cout << "map1[ -7 ].first: " << map1[ -7 ].first << std::endl;
		std::cout << "map1[ 7 ].second: " << map1[ 7 ].second << std::endl;
		std::cout << "map1[ 0 ].first: " << map1[ 0 ].first << std::endl;
		std::cout << "map1[ 0 ].second: " << map1[ 0 ].second << std::endl;
		std::cout << "map2[ ft::make_pair( 3, \"damn\" ) ]: " << map2[ ft::make_pair( 3, "damn" ) ] << std::endl;
		std::cout << "map2[ ft::make_pair( 3, \"pair\" ) ]: " << map2[ ft::make_pair( 3, "pair" ) ] << std::endl;
		std::cout << "map3[ pair ].first: " << map3[ pair ].first << std::endl;
		std::cout << "map3[ pair ].second: " << map3[ pair ].second << std::endl;

		ft::map< int, int >											m;
		ft::map< int, int >::iterator								it = ( m.begin() );

		if ( it == m.end() )
			std::cout << "m.begin() == m.end()" << std::endl;
		m[ 3 ] = 6;
		it = m.begin();
		std::cout << "first: " << it->first << "\tsecond: " << ( *it ).second << std::endl;
	
	}

	{

		{
			std::allocator< int >											alloc;
			myallocator< int >												myalloc;
			my_pointer_struct												pts;
			myallocator< my_pointer_struct >								alloc_pts;

			ft::vector< char >												v_char;
			ft::vector< wchar_t, std::allocator< wchar_t > >				v_wchar_t;
			ft::vector< signed char, std::allocator< signed char > >		v_signed_char;
			ft::vector< unsigned char, myallocator< unsigned char > >		v_unsigned_char;
			ft::vector< short, myallocator< short > >						v_short;
			ft::vector< int >												v_int( alloc );
			ft::vector< long, myallocator< long > >							v_long( myalloc );
			ft::vector< unsigned short >									v_unsigned_short( alloc );
			ft::vector< unsigned int, myallocator< unsigned int > >			v_unsigned_int( myalloc );
			ft::vector< unsigned long, std::allocator< unsigned long > >	v_unsigned_long( alloc );
			ft::vector< float, myallocator< float > >						v_float( myalloc );
			ft::vector< double >											v_double( 4 );
			ft::vector< long double, myallocator< long double > >			v_long_double( 2, 3.14159 );
			ft::vector< void * >											v_void_p( 3, static_cast< void * >( &v_short ) );
			ft::vector< void const * >										v_void_const_p( 2, NULL, std::allocator< void const * >() );
			ft::vector< my_empty_struct, myallocator< my_empty_struct > >	v_my_empty_struct( 3, my_empty_struct() );
			ft::vector<my_pointer_struct, myallocator<my_pointer_struct> >	v_my_pointer_struct( 6, pts, alloc_pts );
			ft::vector< my_const_pointer_struct >							v_my_const_pointer_struct( 4, my_const_pointer_struct() );
			ft::vector< my_bool_struct >									v_my_bool_struct( 2 );
			ft::vector< my_char_struct, std::allocator< my_char_struct > >	v_my_char_struct( 3 );
			ft::vector< my_int_struct, myallocator< my_int_struct > >		v_my_int_struct( 0, my_int_struct() );
			ft::vector< my_double_struct >									v_my_double_struct( 1 );
			ft::vector< my_struct_struct >									v_my_struct_struct( 3 );
			ft::vector< mystruct, myallocator< mystruct > >					v_mystruct;

			std::cout << std::endl << "allocator & get_allocator()" << std::endl << std::endl;

			int	i = 0;

			if ( v_char.get_allocator().address( i ) )
				std::cout << "v_char::allocator:\t\t\t\tstd::allocator" << std::endl;
			if ( v_wchar_t.get_allocator().address( i ) )
				std::cout << "v_wchar_t::allocator:\t\t\t\tstd::allocator" << std::endl;
			if ( v_signed_char.get_allocator().address( i ) )
				std::cout << "v_signed_char::allocator:\t\t\tstd::allocator" << std::endl;
			if ( v_unsigned_char.get_allocator().is_myallocator() )
				std::cout << "v_unsigned_char::allocator:\t\t\tmyallocator" << std::endl;
			if ( v_short.get_allocator().is_myallocator() )
				std::cout << "v_short::allocator:\t\t\t\tmyallocator" << std::endl;
			if ( v_int.get_allocator().address( i ) )
				std::cout << "v_int::allocator:\t\t\t\tstd::allocator" << std::endl;
			if ( v_long.get_allocator().is_myallocator() )
				std::cout << "v_long::allocator:\t\t\t\tmyallocator" << std::endl;
			if ( v_unsigned_short.get_allocator().address( i ) )
				std::cout << "v_unsigned_short::allocator:\t\t\tstd::allocator" << std::endl;
			if ( v_unsigned_int.get_allocator().is_myallocator() )
				std::cout << "v_unsigned_int::allocator:\t\t\tmyallocator" << std::endl;
			if ( v_unsigned_long.get_allocator().address( i ) )
				std::cout << "v_unsigned_long::allocator:\t\t\tstd::allocator" << std::endl;
			if ( v_float.get_allocator().is_myallocator() )
				std::cout << "v_float::allocator:\t\t\t\tmyallocator" << std::endl;
			if ( v_double.get_allocator().address( i ) )
				std::cout << "v_double::allocator:\t\t\t\tstd::allocator" << std::endl;
			if ( v_long_double.get_allocator().is_myallocator() )
				std::cout << "v_long_double::allocator:\t\t\tmyallocator" << std::endl;
			if ( v_void_p.get_allocator().address( *( v_void_p.begin() ) ) )
				std::cout << "v_void_p::allocator:\t\t\t\tstd::allocator" << std::endl;
			if ( v_void_const_p.get_allocator().address( *( v_void_const_p.begin() ) ) )
				std::cout << "v_void_const_p::allocator:\t\t\tstd::allocator" << std::endl;
			if ( v_my_empty_struct.get_allocator().is_myallocator() )
				std::cout << "v_my_empty_struct::allocator:\t\t\tmyallocator" << std::endl;
			if ( v_my_pointer_struct.get_allocator().is_myallocator() )
				std::cout << "v_my_pointer_struct::allocator:\t\t\tmyallocator" << std::endl;
			if ( v_my_const_pointer_struct.get_allocator().address( *( v_my_const_pointer_struct.begin() ) ) )
				std::cout << "v_my_const_pointer_struct::allocator:\t\tstd::allocator" << std::endl;
			if ( v_my_bool_struct.get_allocator().address( *( v_my_bool_struct.begin() ) ) )
				std::cout << "v_my_bool_struct::allocator:\t\t\tstd::allocator" << std::endl;
			if ( v_my_char_struct.get_allocator().address( *( v_my_char_struct.begin() ) ) )
				std::cout << "v_my_char_struct::allocator:\t\t\tstd::allocator" << std::endl;
			if ( v_my_int_struct.get_allocator().is_myallocator() )
				std::cout << "v_my_int_struct::allocator:\t\t\tmyallocator" << std::endl;
			if ( v_my_double_struct.get_allocator().address( *( v_my_double_struct.begin() ) ) )
				std::cout << "v_my_double_struct::allocator:\t\t\tstd::allocator" << std::endl;
			if ( v_my_struct_struct.get_allocator().address( *( v_my_struct_struct.begin() ) ) )
				std::cout << "v_my_struct_struct::allocator:\t\t\tstd::allocator" << std::endl;
			if ( v_mystruct.get_allocator().is_myallocator() )
				std::cout << "v_mystruct::allocator:\t\t\t\tmyallocator" << std::endl;

			std::cout << std::endl;

			std::cout << std::endl << "size() & capacity() & empty()" << std::boolalpha << std::endl << std::endl;

			std::cout << "v_char:\t\t\t\t" << v_char.size() << "\t" << v_char.capacity() << "\t" << v_char.empty() << std::endl;
			std::cout << "v_wchar_t:\t\t\t" << v_wchar_t.size() << "\t" << v_wchar_t.capacity() << "\t" << v_wchar_t.empty() << std::endl;
			std::cout << "v_signed_char:\t\t\t" << v_signed_char.size() << "\t" << v_signed_char.capacity() << "\t" << v_signed_char.empty() << std::endl;
			std::cout << "v_unsigned_char:\t\t" << v_unsigned_char.size() << "\t" << v_unsigned_char.capacity() << "\t" << v_unsigned_char.empty() << std::endl;
			std::cout << "v_short:\t\t\t" << v_short.size() << "\t" << v_short.capacity() << "\t" << v_short.empty() << std::endl;
			std::cout << "v_int:\t\t\t\t" << v_int.size() << "\t" << v_int.capacity() << "\t" << v_int.empty() << std::endl;
			std::cout << "v_long:\t\t\t\t" << v_long.size() << "\t" << v_long.capacity() << "\t" << v_long.empty() << std::endl;
			std::cout << "v_unsigned_short:\t\t" << v_unsigned_short.size() << "\t" << v_unsigned_short.capacity() << "\t" << v_unsigned_short.empty() << std::endl;
			std::cout << "v_unsigned_int:\t\t\t" << v_unsigned_int.size() << "\t" << v_unsigned_int.capacity() << "\t" << v_unsigned_int.empty() << std::endl;
			std::cout << "v_unsigned_long:\t\t" << v_unsigned_long.size() << "\t" << v_unsigned_long.capacity() << "\t" << v_unsigned_long.empty() << std::endl;
			std::cout << "v_float:\t\t\t" << v_float.size() << "\t" << v_float.capacity() << "\t" << v_float.empty() << std::endl;
			std::cout << "v_double:\t\t\t" << v_double.size() << "\t" << v_double.capacity() << "\t" << v_double.empty() << std::endl;
			std::cout << "v_long_double:\t\t\t" << v_long_double.size() << "\t" << v_long_double.capacity() << "\t" << v_long_double.empty() << std::endl;
			std::cout << "v_void_p:\t\t\t" << v_void_p.size() << "\t" << v_void_p.capacity() << "\t" << v_void_p.empty() << std::endl;
			std::cout << "v_void_const_p:\t\t\t" << v_void_const_p.size() << "\t" << v_void_const_p.capacity() << "\t" << v_void_const_p.empty() << std::endl;
			std::cout << "v_my_empty_struct:\t\t" << v_my_empty_struct.size() << "\t" << v_my_empty_struct.capacity() << "\t" << v_my_empty_struct.empty() << std::endl;
			std::cout << "v_my_pointer_struct:\t\t" << v_my_pointer_struct.size() << "\t" << v_my_pointer_struct.capacity() << "\t" << v_my_pointer_struct.empty() << std::endl;
			std::cout << "v_my_const_pointer_struct:\t" << v_my_const_pointer_struct.size() << "\t" << v_my_const_pointer_struct.capacity() << "\t" << v_my_const_pointer_struct.empty() << std::endl;
			std::cout << "v_my_bool_struct:\t\t" << v_my_bool_struct.size() << "\t" << v_my_bool_struct.capacity() << "\t" << v_my_bool_struct.empty() << std::endl;
			std::cout << "v_my_char_struct:\t\t" << v_my_char_struct.size() << "\t" << v_my_char_struct.capacity() << "\t" << v_my_char_struct.empty() << std::endl;
			std::cout << "v_my_int_struct:\t\t" << v_my_int_struct.size() << "\t" << v_my_int_struct.capacity() << "\t" << v_my_int_struct.empty() << std::endl;
			std::cout << "v_my_double_struct:\t\t" << v_my_double_struct.size() << "\t" << v_my_double_struct.capacity() << "\t" << v_my_double_struct.empty() << std::endl;
			std::cout << "v_my_struct_struct:\t\t" << v_my_struct_struct.size() << "\t" << v_my_struct_struct.capacity() << "\t" << v_my_struct_struct.empty() << std::endl;
			std::cout << "v_mystruct:\t\t\t" << v_mystruct.size() << "\t" << v_mystruct.capacity() << "\t" << v_mystruct.empty() << std::endl;

			std::cout << std::endl;

			std::cout << std::endl << "max_size()" << std::endl << std::endl;

			std::cout << "v_wchar_t:\t\t\t" << std::bitset< 64 >( v_wchar_t.max_size() ) << std::endl;
			std::cout << "v_unsigned_char:\t\t" << std::bitset< 64 >( v_unsigned_char.max_size() ) << std::endl;
			std::cout << "v_short:\t\t\t" << std::bitset< 64 >( v_short.max_size() ) << std::endl;
			std::cout << "v_int:\t\t\t\t" << std::bitset< 64 >( v_int.max_size() ) << std::endl;
			std::cout << "v_long:\t\t\t\t" << std::bitset< 64 >( v_long.max_size() ) << std::endl;
			std::cout << "v_unsigned_short:\t\t" << std::bitset< 64 >( v_unsigned_short.max_size() ) << std::endl;
			std::cout << "v_unsigned_int:\t\t\t" << std::bitset< 64 >( v_unsigned_int.max_size() ) << std::endl;
			std::cout << "v_unsigned_long:\t\t" << std::bitset< 64 >( v_unsigned_long.max_size() ) << std::endl;
			std::cout << "v_float:\t\t\t" << std::bitset< 64 >( v_float.max_size() ) << std::endl;
			std::cout << "v_double:\t\t\t" << std::bitset< 64 >( v_double.max_size() ) << std::endl;
			std::cout << "v_long_double:\t\t\t" << std::bitset< 64 >( v_long_double.max_size() ) << std::endl;
			std::cout << "v_void_p:\t\t\t" << std::bitset< 64 >( v_void_p.max_size() ) << std::endl;
			std::cout << "v_void_const_p:\t\t\t" << std::bitset< 64 >( v_void_const_p.max_size() ) << std::endl;
			std::cout << "v_my_empty_struct:\t\t" << std::bitset< 64 >( v_my_empty_struct.max_size() ) << std::endl;
			std::cout << "v_my_pointer_struct:\t\t" << std::bitset< 64 >( v_my_pointer_struct.max_size() ) << std::endl;
			std::cout << "v_my_const_pointer_struct:\t" << std::bitset< 64 >( v_my_const_pointer_struct.max_size() ) << std::endl;
			std::cout << "v_my_int_struct:\t\t" << std::bitset< 64 >( v_my_int_struct.max_size() ) << std::endl;
			std::cout << "v_my_double_struct:\t\t" << std::bitset< 64 >( v_my_double_struct.max_size() ) << std::endl;
			std::cout << "v_my_struct_struct:\t\t" << std::bitset< 64 >( v_my_struct_struct.max_size() ) << std::endl;
			std::cout << "v_mystruct:\t\t\t" << std::bitset< 64 >( v_mystruct.max_size() ) << std::endl;

			std::cout << std::endl;

		}

		int					arr[] = { 0, 1, 2, 3, 4 };
		std::size_t			size = ( sizeof( arr ) / sizeof( arr[ 0 ] ) );
		ft::vector< int >	v( arr, arr + size );

		for ( std::size_t	count = 0; count < size; ++count )
			std::cout << v[ count ] << " ";
		std::cout << std::endl;

		v[ 3 ] = 82;

		for ( std::size_t	count = 0; count < v.size(); ++count )
			std::cout << v[ count ] << " ";
		std::cout << std::endl;

		int &				i_ref = v[ size - 1 ];
		int const &			i_const_ref = v[ size - 1 ];

		if ( i_ref == v.back() )
			std::cout << i_ref << " == " << v.back() << std::endl;
		if ( i_const_ref == v.back() )
			std::cout << i_const_ref << " == " << v.back() << std::endl;

		int &				i_ref_back = v.back();
		int const &			i_const_ref_back = v.back();

		i_ref = 15;

		if ( i_ref == i_ref_back )
			std::cout << i_ref << " == " << i_ref_back << std::endl;
		if ( i_const_ref == i_const_ref_back )
			std::cout << i_const_ref << " == " << i_const_ref_back << std::endl;

		v.at( 1 ) = -18;

		for ( std::size_t	count = 0; count < v.size(); ++count )
			std::cout << v.at( count ) << " ";
		std::cout << std::endl;

		try
		{
			v.at( -1 ) = 23;
		}
		catch( std::out_of_range const & exc )
		{
			std::cout << "out_of_range" << std::endl;
		}
		try
		{
			v.at( 5 ) = -23;
		}
		catch( std::out_of_range const & exc )
		{
			std::cout << "out_of_range" << std::endl;
		}

		int					i = v[ 0 ];
		int					i_at = v.at( 0 );
		int &				i_ref_at = v.at( 0 );
		int const &			i_const_ref_at = v.at( 0 );

		if ( i_ref_at == v.front() )
			std::cout << i_ref_at << " == " << v.front() << std::endl;
		if ( i_const_ref_at == v.front() )
			std::cout << i_const_ref_at << " == " << v.front() << std::endl;

		int &				i_ref_front = v.front();
		int const &			i_const_ref_front = v.front();

		i_ref_at = 307;

		if ( i_ref_at == i_ref_front )
			std::cout << i_ref_at << " == " << i_ref_front << std::endl;
		if ( i_const_ref_at == i_const_ref_front )
			std::cout << i_const_ref_at << " == " << i_const_ref_front << std::endl;
		std::cout << i << " " << i_at << std::endl;

		for ( std::size_t	count = 0; count < v.size(); ++count )
			std::cout << v.at( count ) << " ";
		std::cout << std::endl;

		int *				p = v.data();

		*p = 5;
		p += ( v.size() - 1 );
		std::cout << "last element: " << *p << std::endl;

		for ( std::size_t	count = 0; count < v.size(); ++count )
			std::cout << v[ count ] << " ";
		std::cout << std::endl;

		if ( !( v.empty() ) )
		{
			v.clear();
			std::cout << "v.clear(): " << std::endl;
		}
		if ( v.empty() )
			std::cout << "v.size(): " << v.size() << std::endl;
		if ( v.data() == &v.front() )
			std::cout << "v.data() == &v.front()" << std::endl;

		v.resize( 5 );
		p = v.data();
		*p = 41;
		++p;
		*p = 27;
		p[ 2 ] = 3;
		--p;

		vector_operator_check( v );
		if ( v.data() == p )
			std::cout << "first allocation" << std::endl;
		std::cout << std::endl;

		p = v.data();

		v.resize( 2, 73 );

		vector_operator_check( v );
		if ( v.data() == p )
			std::cout << "no reallocation" << std::endl;
		std::cout << std::endl;

		p = v.data();

		v.resize( 7, 4 );

		vector_operator_check( v );
		if ( v.data() != p )
			std::cout << "reallocation" << std::endl;
		std::cout << std::endl;

		p = v.data();

		v.resize( 13 );

		vector_operator_check( v );
		if ( v.data() != p )
			std::cout << "reallocation" << std::endl;
		std::cout << std::endl;

		p = v.data();

		v.resize( 19 );

		vector_operator_check( v );
		if ( v.data() == p )
			std::cout << "no reallocation" << std::endl;
		std::cout << std::endl;

		p = v.data();

		v.push_back( 5 );

		vector_operator_check( v );
		if ( v.data() == p )
			std::cout << "no reallocation" << std::endl;
		std::cout << std::endl;

		p = v.data();

		v.push_back( -84 );

		vector_operator_check( v );
		if ( v.data() != p )
			std::cout << "reallocation" << std::endl;
		std::cout << std::endl;

		p = v.data();

		v.pop_back();

		vector_operator_check( v );
		if ( v.data() == p )
			std::cout << "no reallocation" << std::endl;
		std::cout << std::endl;

		p = v.data();

		v.erase( v.begin() + 1 );

		vector_operator_check( v );
		if ( v.data() == p )
			std::cout << "no reallocation" << std::endl;
		std::cout << std::endl;

		p = v.data();

		v.erase( v.begin(), v.begin() + 4);

		vector_operator_check( v );
		if ( v.data() == p )
			std::cout << "no reallocation" << std::endl;
		std::cout << std::endl;

		p = v.data();

		v.insert( v.begin(), -50 );

		vector_operator_check( v );
		if ( v.data() == p )
			std::cout << "no reallocation" << std::endl;
		std::cout << std::endl;

		p = v.data();

		v.insert( v.end(), 124 );

		vector_operator_check( v );
		if ( v.data() == p )
			std::cout << "no reallocation" << std::endl;
		std::cout << std::endl;

		p = v.data();

		v.insert( v.begin() + 7, 4, 73 );

		vector_operator_check( v );
		if ( v.data() == p )
			std::cout << "no reallocation" << std::endl;
		std::cout << std::endl;

		p = v.data();

		v.insert( v.end() - 2, 0, 2 );

		vector_operator_check( v );
		if ( v.data() == p )
			std::cout << "no reallocation" << std::endl;
		std::cout << std::endl;

		p = v.data();

		v.insert( v.begin() + 3, v.begin(), v.begin() + 4 );

		vector_operator_check( v );
		if ( v.data() == p )
			std::cout << "no reallocation" << std::endl;
		std::cout << std::endl;

		p = v.data();

		v.insert( v.end() - 10, arr, arr + size );

		vector_operator_check( v );
		if ( v.data() == p )
			std::cout << "no reallocation" << std::endl;
		std::cout << std::endl;

		p = v.data();

		v.insert( v.end() - 22, 63, -39 );

		vector_operator_check( v );
		if ( v.data() != p )
			std::cout << "reallocation" << std::endl;
		std::cout << std::endl;

		p = v.data();

		v.insert( v.begin() + 5, 3 );

		vector_operator_check( v );
		if ( v.data() != p )
			std::cout << "reallocation" << std::endl;
		std::cout << std::endl;

		p = v.data();

		{
			ft::vector< char >	v2;

			v2.push_back( '"' );
			v2.push_back( 'e' );
			v2.push_back( '2' );

			vector_operator_check( v2 );

			v2.erase( v2.begin(), v2.end() );

			vector_operator_check( v2 );

			if ( v2.begin() == v2.end() )
				std::cout << "v2.begin() == v2.end()" << std::endl;

			v2.erase( v2.begin(), v2.end() );

			vector_operator_check( v2 );
		}

		v.resize( 2 );

		vector_operator_check( v );
		if ( v.data() == p )
			std::cout << "no reallocation" << std::endl;
		std::cout << std::endl;

		int *				p_v = &*( v.begin() );
		int &				r_v = *v.begin();
		ft::vector< int > *	v_ptr = &v;

		vector_iterator_check( v );
		if ( p_v == v.data() )
			std::cout << "p_v == v.data()" << std::endl;
		if ( &r_v == v.data() )
			std::cout << "&r_v == v.data()" << std::endl;
		if ( &*( v.begin() ) == v.data() )
			std::cout << "&*( v.begin() ) == v.data()" << std::endl;
		std::cout << "*v.begin(): " << *v.begin() << std::endl;
		if ( v_ptr == &v )
			std::cout << "saved vector address" << std::endl;
		std::cout << std::endl;

		v.reserve( 300 );

		vector_iterator_check( v );
		if ( p_v != v.data() )
			std::cout << "p_v != v.data()" << std::endl;
		if ( &r_v != v.data() )
			std::cout << "&r_v != v.data()" << std::endl;
		if ( &*( v.begin() ) == v.data() )
			std::cout << "&*( v.begin() ) == v.data()" << std::endl;
		std::cout << "*v.begin(): " << *v.begin() << std::endl;
		if ( v_ptr == &v )
			std::cout << "vector address same as before reserve" << std::endl;
		std::cout << std::endl;

		int &				r_v2 = *v.begin();

		p_v = &*( v.begin() );

		v.reserve( 12 );

		vector_iterator_check( v );
		if ( p_v == v.data() )
			std::cout << "p_v == v.data()" << std::endl;
		if ( &r_v2 == v.data() )
			std::cout << "&r_v2 == v.data()" << std::endl;
		if ( &*( v.begin() ) == v.data() )
			std::cout << "&*( v.begin() ) == v.data()" << std::endl;
		std::cout << "*v.begin(): " << *v.begin() << std::endl;
		if ( v_ptr == &v )
			std::cout << "vector address same as before reserve" << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;

		ft::vector< int >::iterator			v_it = v.begin();
		ft::vector< int >::const_iterator	v_cit = ( v.end() - 1 );
		ft::vector< int >					vec( v.begin(), v.end() );
		int *								i_ptr;
		int const *							i_const_ptr = v_cit.base();

		std::cout << "v:" << std::endl;
		vector_iterator_check( v );
		std::cout << std::endl;
		std::cout << "vec:" << std::endl;
		vector_iterator_check( vec );
		std::cout << std::endl;

		if ( *v_it == *vec.begin() )
			std::cout << "*v_it == *vec.begin()" << std::endl;
		if ( *v_cit == *( vec.end() - 1 ) )
			std::cout << "*v_cit == *( vec.end() - 1 )" << std::endl;
		std::cout << std::endl;

		i_ptr = v_it.base();
		std::cout << "*i_ptr: " << *i_ptr << std::endl;
		std::cout << "*i_const_ptr: " << *i_const_ptr << std::endl;

		std::cout << "v_it[ 1 ]: " << v_it[ 1 ] << std::endl;
		v_it[ 1 ] = -3;
		std::cout << "v_cit[ -1 ]: " << v_cit[ -1 ] << std::endl;
		std::cout << "*v_it: " << *v_it << std::endl;
		*v_it = 2;
		std::cout << "i_ptr[ 0 ]: " << i_ptr[ 0 ] << std::endl;
		std::cout << "i_const_ptr[ -1 ]: " << i_const_ptr[ -1 ] << std::endl;
		std::cout << std::endl;

		std::size_t								distance;

		distance = v_it - v_cit;
		std::cout << "distance( v_cit, v_it ) = " << distance << std::endl;
		distance = v_cit - v_it;
		std::cout << "distance( v_it, v_cit ) = " << distance << std::endl;
		distance = v_it[ 1 ] - v_cit[ -1 ];
		std::cout << "distance( v_cit[ -1 ], v_it[ 1 ] ) = " << distance << std::endl;
		std::cout << std::endl;

		if ( ( v_it + 3 ) == ( 3 + v_it ) )
			std::cout << "( v_it + 3 ) == ( 3 + v_it )" << std::endl;
		if ( ( 3 + v_it - 3 ) == ( v_cit - 1 ) )
			std::cout << "( 3 + v_it - 3 ) == ( v_cit - 1 )" << std::endl;
		std::cout << std::endl;

		ft::vector< my_int_struct >				v_struct( 2 );
		ft::vector< my_int_struct >::iterator	v_struct_it( v_struct.begin() );

		v_struct_it->i = 10;
		std::cout << "v_struct_it->i: " << v_struct_it->i << std::endl;

		( *v_struct_it ).i = -1;
		std::cout << "( *v_struct_it ).i: " << ( *v_struct_it ).i << std::endl;


		std::cout << std::endl;

		if ( v_it == v_cit )
			std::cout << "v_it == v_cit" << std::endl;
		if ( v_it != v_cit )
			std::cout << "v_it != v_cit" << std::endl;
		if ( v_it < v_cit )
			std::cout << "v_it < v_cit" << std::endl;
		if ( v_it > v_cit )
			std::cout << "v_it > v_cit" << std::endl;
		if ( v_it <= v_cit )
			std::cout << "v_it <= v_cit" << std::endl;
		if ( v_it >= v_cit )
			std::cout << "v_it >= v_cit" << std::endl;

		if ( v_cit == v_it )
			std::cout << "v_cit == v_it" << std::endl;
		if ( v_cit != v_it )
			std::cout << "v_cit != v_it" << std::endl;
		if ( v_cit < v_it )
			std::cout << "v_cit < v_it" << std::endl;
		if ( v_cit > v_it )
			std::cout << "v_cit > v_it" << std::endl;
		if ( v_cit <= v_it )
			std::cout << "v_cit <= v_it" << std::endl;
		if ( v_cit >= v_it )
			std::cout << "v_cit >= v_it" << std::endl;

		ft::vector< int >::iterator			v_it2;

		v_it2 = v_it;
		++v_it;
		v_it2 += 2;
		if ( v_it++ == ( v_it2 - 1 ) )
			std::cout << "v_it == ( v_it2 - 1 )" << std::endl;

		if ( v_it == v_it2 )
			std::cout << "v_it == v_it2" << std::endl;
		if ( v_it != v_it2 )
			std::cout << "v_it != v_it2" << std::endl;
		if ( v_it < v_it2 )
			std::cout << "v_it < v_it2" << std::endl;
		if ( v_it > v_it2 )
			std::cout << "v_it > v_it2" << std::endl;
		if ( v_it <= v_it2 )
			std::cout << "v_it <= v_it2" << std::endl;
		if ( v_it >= v_it2 )
			std::cout << "v_it >= v_it2" << std::endl;

		ft::vector< int >::const_iterator	v_cit2 = v_cit;

		v_cit--;
		v_cit2 -= 2;
		if ( --v_cit == v_cit2 )
			std::cout << "v_cit == v_cit2" << std::endl;

		if ( v_cit == v_cit2 )
			std::cout << "v_cit == v_cit2" << std::endl;
		if ( v_cit != v_cit2 )
			std::cout << "v_cit != v_cit2" << std::endl;
		if ( v_cit < v_cit2 )
			std::cout << "v_cit < v_cit2" << std::endl;
		if ( v_cit > v_cit2 )
			std::cout << "v_cit > v_cit2" << std::endl;
		if ( v_cit <= v_cit2 )
			std::cout << "v_cit <= v_cit2" << std::endl;
		if ( v_cit >= v_cit2 )
			std::cout << "v_cit >= v_cit2" << std::endl;


		ft::vector< int >			vec1;
		ft::vector< int >			vec2;
		ft::vector< int >			vec3( v );

		if ( vec1 == vec2 )
			std::cout << "vec1 == vec2" << std::endl;

		vec1 = v;
		if ( v == vec1 )
			std::cout << "v == vec1" << std::endl;
		if ( vec1 == vec3 )
			std::cout << "vec1 == vec3" << std::endl;

		vec2.assign( v.begin(), v.end() );
		if ( v == vec2 )
			std::cout << "v == vec2" << std::endl;
		if ( vec1 == vec2 )
			std::cout << "vec1 == vec2" << std::endl;
		std::cout << std::endl;

		vector_operator_check( vec1 );
		vec1.assign( 1, 3 );
		vector_operator_check( vec1 );
		vec1.assign( 3, 7 );
		vector_operator_check( vec1 );
		std::cout << std::endl;

		if ( v == vec1 )
			std::cout << "v == vec1" << std::endl;
		if ( v != vec1 )
			std::cout << "v != vec1" << std::endl;
		if ( v < vec1 )
			std::cout << "v < vec1" << std::endl;
		if ( v > vec1 )
			std::cout << "v > vec1" << std::endl;
		if ( v <= vec1 )
			std::cout << "v <= vec1" << std::endl;
		if ( v >= vec1 )
			std::cout << "v >= vec1" << std::endl;

		if ( vec1 == v )
			std::cout << "vec1 == v" << std::endl;
		if ( vec1 != v )
			std::cout << "vec1 != v" << std::endl;
		if ( vec1 < v )
			std::cout << "vec1 < v" << std::endl;
		if ( vec1 > v )
			std::cout << "vec1 > v" << std::endl;
		if ( vec1 <= v )
			std::cout << "vec1 <= v" << std::endl;
		if ( vec1 >= v )
			std::cout << "vec1 >= v" << std::endl;
		std::cout << std::endl;

		vec1.assign( v.begin(), v.end() );

		vector_operator_check( vec1 );

		if ( v == vec1 )
			std::cout << "v == vec1" << std::endl;
		if ( v != vec1 )
			std::cout << "v != vec1" << std::endl;
		if ( v < vec1 )
			std::cout << "v < vec1" << std::endl;
		if ( v > vec1 )
			std::cout << "v > vec1" << std::endl;
		if ( v <= vec1 )
			std::cout << "v <= vec1" << std::endl;
		if ( v >= vec1 )
			std::cout << "v >= vec1" << std::endl;
		std::cout << std::endl;

		vec1.assign( v.begin(), ( v.end() - 1 ) );

		vector_operator_check( vec1 );

		if ( v == vec1 )
			std::cout << "v == vec1" << std::endl;
		if ( v != vec1 )
			std::cout << "v != vec1" << std::endl;
		if ( v < vec1 )
			std::cout << "v < vec1" << std::endl;
		if ( v > vec1 )
			std::cout << "v > vec1" << std::endl;
		if ( v <= vec1 )
			std::cout << "v <= vec1" << std::endl;
		if ( v >= vec1 )
			std::cout << "v >= vec1" << std::endl;
		std::cout << std::endl;

		vec1[ 0 ] = 50;

		vector_operator_check( vec1 );

		if ( v == vec1 )
			std::cout << "v == vec1" << std::endl;
		if ( v != vec1 )
			std::cout << "v != vec1" << std::endl;
		if ( v < vec1 )
			std::cout << "v < vec1" << std::endl;
		if ( v > vec1 )
			std::cout << "v > vec1" << std::endl;
		if ( v <= vec1 )
			std::cout << "v <= vec1" << std::endl;
		if ( v >= vec1 )
			std::cout << "v >= vec1" << std::endl;
		std::cout << std::endl;

		std::cout << "vec1:" << std::endl;
		vector_operator_check( vec1 );
		std::cout << std::endl << "vec2:" << std::endl;
		vector_operator_check( vec2 );

		ft::swap( vec1, vec2 );
		std::cout << std::endl << "ft::swap( vec1, vec2 )" << std::endl;

		std::cout << std::endl << "vec1:" << std::endl;
		vector_operator_check( vec1 );
		std::cout << std::endl << "vec2:" << std::endl;
		vector_operator_check( vec2 );
		std::cout << std::endl;

		vec1.swap( vec2 );
		std::cout << std::endl << "vec1.swap( vec2 )" << std::endl;

		std::cout << std::endl << "vec1:" << std::endl;
		vector_operator_check( vec1 );
		std::cout << std::endl << "vec2:" << std::endl;
		vector_operator_check( vec2 );
		std::cout << std::endl;

		v.push_back( 29 );
		v.push_back( 5 );
		v.push_back( 63 );
		v.push_back( -8 );

		std::cout << "reverse iterator:" << std::endl << std::endl;

		ft::reverse_iterator< ft::vector< int >::iterator >	ri;
		ft::vector< int >::reverse_iterator					v_rit = v.rbegin();
		ft::vector< int >::const_reverse_iterator			v_crit = ( v.rend() - 1 );
		ft::vector< int >									rvec( v.rbegin(), v.rend() );

		ri = v.rbegin() + 4;

		std::cout << "v:" << std::endl;
		vector_iterator_check( v );
		std::cout << std::endl;
		std::cout << "rvec:" << std::endl;
		vector_iterator_check( rvec );
		std::cout << std::endl;

		std::cout << *v_rit << " " << *rvec.begin() << std::endl;
		if ( *v_rit == *rvec.begin() )
			std::cout << "*v_rit == *rvec.begin()" << std::endl;
		std::cout << *v_crit << " " << *( rvec.end() - 1 ) << std::endl;
		if ( *v_crit == *( rvec.end() - 1 ) )
			std::cout << "*v_crit == *( rvec.end() - 1 )" << std::endl;
		std::cout << std::endl;

		std::cout << *v_rit << " " << *v.rbegin() << std::endl;
		if ( *v_rit == *v.rbegin() )
			std::cout << "*v_rit == *v.rbegin()" << std::endl;
		std::cout << *v_crit << " " << *( v.rend() - 1 ) << std::endl;
		if ( *v_crit == *( v.rend() - 1 ) )
			std::cout << "*v_crit == *( v.rend() - 1 )" << std::endl;
		std::cout << std::endl;

		v_it = v_rit.base();
		v_cit = v_crit.base();
		std::cout << "*( v_it - 1 ): " << *( v_it - 1 ) << std::endl;
		std::cout << "*v_cit: " << *v_cit << std::endl;

		std::cout << "v_rit[ 1 ]: " << v_rit[ 1 ] << std::endl;
		v_rit[ 1 ] = -7;
		std::cout << "v_crit[ -4 ]: " << v_crit[ -4 ] << std::endl;
		std::cout << "*v_rit: " << *v_rit << std::endl;
		*v_rit = 9;
		std::cout << "v_it[ -1 ]: " << v_it[ -1 ] << std::endl;
		std::cout << "v_cit[ 4 ]: " << v_cit[ 4 ] << std::endl;
		std::cout << std::endl;

		distance = v_rit - ri;
		std::cout << "distance( ri, v_rit ) = " << distance << std::endl;
		distance = ri - v_rit;
		std::cout << "distance( v_rit, ri ) = " << distance << std::endl;
		distance = v_rit[ 1 ] - ri[ -3 ];
		std::cout << "distance( ri[ -3 ], v_rit[ 1 ] ) = " << distance << std::endl;
		std::cout << std::endl;

		if ( ( v_rit + 3 ) == ( 3 + v_rit ) )
			std::cout << "( v_rit + 3 ) == ( 3 + v_rit )" << std::endl;
		if ( ( 3 + v_rit - 2 ) == ( v_crit - 4 ) )
			std::cout << "( 3 + v_rit - 2 ) == ( v_crit - 4 )" << std::endl;
		std::cout << std::endl;

		ft::vector< my_char_struct >					v_cstruct( 2 );
		ft::vector< my_char_struct >::reverse_iterator	v_cstruct_rit( v_cstruct.rbegin() );

		v_cstruct_rit->c = 'n';
		std::cout << "v_cstruct_rit->c: " << v_cstruct_rit->c << std::endl;

		( *v_cstruct_rit ).c = '6';
		std::cout << "( *v_cstruct_rit ).c: " << ( *v_cstruct_rit ).c << std::endl;

		std::cout << std::endl;

		if ( v_rit == v_crit )
			std::cout << "v_rit == v_crit" << std::endl;
		if ( v_rit != v_crit )
			std::cout << "v_rit != v_crit" << std::endl;
		if ( v_rit < v_crit )
			std::cout << "v_rit < v_crit" << std::endl;
		if ( v_rit > v_crit )
			std::cout << "v_rit > v_crit" << std::endl;
		if ( v_rit <= v_crit )
			std::cout << "v_rit <= v_crit" << std::endl;
		if ( v_rit >= v_crit )
			std::cout << "v_rit >= v_crit" << std::endl;

		if ( v_crit == v_rit )
			std::cout << "v_crit == v_rit" << std::endl;
		if ( v_crit != v_rit )
			std::cout << "v_crit != v_rit" << std::endl;
		if ( v_crit < v_rit )
			std::cout << "v_crit < v_rit" << std::endl;
		if ( v_crit > v_rit )
			std::cout << "v_crit > v_rit" << std::endl;
		if ( v_crit <= v_rit )
			std::cout << "v_crit <= v_rit" << std::endl;
		if ( v_crit >= v_rit )
			std::cout << "v_crit >= v_rit" << std::endl;

		ft::vector< int >::reverse_iterator			v_rit2;

		v_rit2 = v_rit;
		++v_rit;
		v_rit2 += 2;
		if ( v_rit++ == ( v_rit2 - 1 ) )
			std::cout << "v_rit == ( v_rit2 - 1 )" << std::endl;

		if ( v_rit == v_rit2 )
			std::cout << "v_rit == v_rit2" << std::endl;
		if ( v_rit != v_rit2 )
			std::cout << "v_rit != v_rit2" << std::endl;
		if ( v_rit < v_rit2 )
			std::cout << "v_rit < v_rit2" << std::endl;
		if ( v_rit > v_rit2 )
			std::cout << "v_rit > v_rit2" << std::endl;
		if ( v_rit <= v_rit2 )
			std::cout << "v_rit <= v_rit2" << std::endl;
		if ( v_rit >= v_rit2 )
			std::cout << "v_rit >= v_rit2" << std::endl;

		ft::vector< int >::const_reverse_iterator	v_crit2 = v_crit;

		v_crit--;
		v_crit2 -= 2;
		if ( --v_crit == v_crit2 )
			std::cout << "v_crit == v_crit2" << std::endl;

		if ( v_crit == v_crit2 )
			std::cout << "v_crit == v_crit2" << std::endl;
		if ( v_crit != v_crit2 )
			std::cout << "v_crit != v_crit2" << std::endl;
		if ( v_crit < v_crit2 )
			std::cout << "v_crit < v_crit2" << std::endl;
		if ( v_crit > v_crit2 )
			std::cout << "v_crit > v_crit2" << std::endl;
		if ( v_crit <= v_crit2 )
			std::cout << "v_crit <= v_crit2" << std::endl;
		if ( v_crit >= v_crit2 )
			std::cout << "v_crit >= v_crit2" << std::endl;

		ft::vector< int >::reverse_iterator		revit( v.begin() + 4 );

		std::cout << "v: " << std::endl;
		vector_operator_check( v );
		std::cout << "*( v.begin() + 4 ): " << *( v.begin() + 4 ) << std::endl;
		std::cout << "*revit: " << *revit << std::endl;

	}

	std::cout << std::endl;

	std::cout << "execution time: " << float( clock() - begin_time ) / CLOCKS_PER_SEC;

	std::cout << std::endl << std::endl;

	return ( 0 );
}
