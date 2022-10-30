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
#include <bitset>
#include "vector.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "iterator_traits.hpp"
#include "pair.hpp"
#include "make_pair.hpp"
#include "tests/myallocator.hpp"
#include "tests/mystruct.hpp"

int	main( void )
{

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

	v.at( 1 ) = -18;

	for ( std::size_t	count = 0; count < v.size(); ++count )
		std::cout << v[ count ] << " ";
	std::cout << std::endl;

	try
	{
		v.at( -1 ) = 23;
	}
	catch( const std::exception & e )
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		v.at( 5 ) = -23;
	}
	catch( const std::exception & e )
	{
		std::cout << e.what() << std::endl;
	}

	return ( 0 );
}
