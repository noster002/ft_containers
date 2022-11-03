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
#include "reverse_iterator.hpp"
#include "pair.hpp"
#include "make_pair.hpp"
#include "tests/myallocator.hpp"
#include "tests/mystruct.hpp"

template< typename T >
void	vector_check_sizes( ft::vector< T > const & v )
{
	std::cout << "size: " << v.size() << std::endl;
	std::cout << "capacity: " << v.capacity() << std::endl;
	std::cout << "max_size: " << v.max_size() << std::endl;

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

int	main( void )
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

		std::cout << "v_char:\t\t\t\t" << std::bitset< 64 >( v_char.max_size() ) << std::endl;
		std::cout << "v_wchar_t:\t\t\t" << std::bitset< 64 >( v_wchar_t.max_size() ) << std::endl;
		std::cout << "v_signed_char:\t\t\t" << std::bitset< 64 >( v_signed_char.max_size() ) << std::endl;
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
		std::cout << "v_my_bool_struct:\t\t" << std::bitset< 64 >( v_my_bool_struct.max_size() ) << std::endl;
		std::cout << "v_my_char_struct:\t\t" << std::bitset< 64 >( v_my_char_struct.max_size() ) << std::endl;
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

	return ( 0 );
}
