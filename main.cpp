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
#include <list>
#include <iostream>
#include <iterator>
#include <vector>
#include <map>
#include <bitset>
#include "vector.hpp"
#include "map.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"
#include "pair.hpp"
#include "make_pair.hpp"
#include "tests/myallocator.hpp"
#include "tests/mystruct.hpp"

int	main( void )
{
	ft::map< unsigned int, int >	map;

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
		std::cerr << "out_of_range" << '\n';
	}
	try
	{
		map2.at( 10 ) = -10;
	}
	catch( std::out_of_range const & exc )
	{
		std::cerr << "out_of_range" << '\n';
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

	return ( 0 );
}
