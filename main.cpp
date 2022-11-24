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
	std::map< int, ft::pair< int, char > >						map1;
	std::map< ft::pair< int, char const * >, int >				map2;
	std::map< ft::pair< int, char >, ft::pair< int, char > >	map3;

	ft::vector< ft::pair< int, char > >							vector;

	ft::pair< int, char >										pair( 2, 'f' );

	vector.push_back( pair );

	std::cout << "vector[ 0 ].first: " << vector[ 0 ].first << std::endl;
	std::cout << "vector[ 0 ].second: "<< vector[ 0 ].second << std::endl;

	map1[ 0 ] = pair;
	map2[ ft::make_pair( 3, "pair") ] = 0;
	map3[ pair ] = pair;

	std::cout << "map1[ -7 ].first: " << map1[ -7 ].first << std::endl;
	std::cout << "map1[ 7 ].second: " << map1[ 7 ].second << std::endl;
	std::cout << "map1[ 0 ].first: " << map1[ 0 ].first << std::endl;
	std::cout << "map1[ 0 ].second: " << map1[ 0 ].second << std::endl;
	std::cout << "map2[ ft::make_pair( 3, \"damn\" ) ]: " << map2[ ft::make_pair( 3, "damn" ) ] << std::endl;
	std::cout << "map2[ ft::make_pair( 3, \"pair\" ) ]: " << map2[ ft::make_pair( 3, "pair" ) ] << std::endl;
	std::cout << "map3[ pair ].first: " << map3[ pair ].first << std::endl;
	std::cout << "map3[ pair ].second: " << map3[ pair ].second << std::endl;

	std::map< int, int >										m;
	std::map< int, int >::iterator								it = ( m.begin() );

	if ( it == m.end() )
		std::cout << "m.begin() == m.end()" << std::endl;
	m[ 3 ] = 6;
	it = m.begin();
	std::cout << "first: " << it->first << "\tsecond: " << ( *it ).second << std::endl;

	return ( 0 );
}