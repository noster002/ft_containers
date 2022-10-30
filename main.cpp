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
	p += size;
	*p = 22;

	for ( std::size_t	count = 0; count <= v.size(); ++count )
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

	std::cout << "v.size(): " << v.size() << std::endl;
	for ( std::size_t	count = 0; count < v.size(); ++count )
		std::cout << v[ count ] << " ";
	std::cout << std::endl;
	if ( v.data() != p )
		std::cout << "reallocation" << std::endl;

	v.resize( 2, 73 );

	std::cout << "v.size(): " << v.size() << std::endl;
	for ( std::size_t	count = 0; count < v.size(); ++count )
		std::cout << v[ count ] << " ";
	std::cout << std::endl;
	if ( v.data() != p )
		std::cout << "reallocation" << std::endl;

	v.resize( 7, 4 );

	std::cout << "v.size(): " << v.size() << std::endl;
	for ( std::size_t	count = 0; count < v.size(); ++count )
		std::cout << v[ count ] << " ";
	std::cout << std::endl;
	if ( v.data() != p )
		std::cout << "reallocation" << std::endl;

	v.resize( 13 );

	std::cout << "v.size(): " << v.size() << std::endl;
	for ( std::size_t	count = 0; count < v.size(); ++count )
		std::cout << v[ count ] << " ";
	std::cout << std::endl;
	if ( v.data() != p )
		std::cout << "reallocation" << std::endl;

	v.resize( 2 );

	std::cout << "v.size(): " << v.size() << std::endl;
	for ( std::size_t	count = 0; count < v.size(); ++count )
		std::cout << v[ count ] << " ";
	std::cout << std::endl;
	if ( v.data() != p )
		std::cout << "reallocation" << std::endl;

	// vector::reserve

	int *				p_v = &*( v.begin() );
	int &				r_v = *v.begin();
	ft::vector< int > *	v_ptr = &v;

	std::cout << std::endl << "vector::reserve()" << std::endl << std::endl;

	for ( ft::vector< int >::iterator it = v.begin(); it != v.end(); ++it )
		std::cout << *it << std::endl;
	if ( p_v == v.data() )
		std::cout << "p_v == v.data()" << std::endl;
	if ( &r_v == v.data() )
		std::cout << "&r_v == v.data()" << std::endl;
	if ( &*( v.begin() ) == v.data() )
		std::cout << "&*( v.begin() ) == v.data()" << std::endl;
	std::cout << "*p_v: " << *p_v << std::endl;
	std::cout << "r_v: " << r_v << std::endl;
	std::cout << "*v.begin(): " << *v.begin() << std::endl;
	if ( v_ptr == &v )
		std::cout << "saved vector address" << std::endl;

	v.reserve( 300 );

	for ( ft::vector< int >::iterator it = v.begin(); it != v.end(); ++it )
		std::cout << *it << std::endl;
	if ( p_v != v.data() )
		std::cout << "p_v != v.data()" << std::endl;
	if ( &r_v != v.data() )
		std::cout << "&r_v != v.data()" << std::endl;
	if ( &*( v.begin() ) == v.data() )
		std::cout << "&*( v.begin() ) == v.data()" << std::endl;
	std::cout << "*p_v: " << *p_v << std::endl;
	std::cout << "r_v: " << r_v << std::endl;
	std::cout << "*v.begin(): " << *v.begin() << std::endl;
	if ( v_ptr == &v )
		std::cout << "vector address same as before reserve" << std::endl;
	std::cout << std::endl;

	return ( 0 );
}
