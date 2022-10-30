/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:22:09 by nosterme          #+#    #+#             */
/*   Updated: 2022/10/30 17:03:03 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
{

	std::allocator< int >											alloc;
	myallocator< int >												myalloc;

	ft::vector< char >												v_char;
	ft::vector< wchar_t, std::allocator< wchar_t > >				v_wchar_t;
	ft::vector< signed char, std::allocator< float > >				v_signed_char;
	ft::vector< unsigned char, myallocator< unsigned char > >		v_unsigned_char;
	ft::vector< short, myallocator< void * > >						v_short;
	ft::vector< int >												v_int( alloc );
	ft::vector< long, myallocator< long > >							v_long( myalloc );
	ft::vector< unsigned short >									v_unsigned_short( alloc );
	ft::vector< unsigned int, myallocator< double > >				v_unsigned_int( myalloc );
	ft::vector< unsigned long, std::allocator< unsigned long > >	v_unsigned_long( alloc );
	ft::vector< float, myallocator< mystruct > >					v_float( myalloc );
	ft::vector< double >											v_double( 4.12 );
	ft::vector< long double, myallocator< void const * > >			v_long_double( 2.562 );
	ft::vector< void * >											v_void_p( 3, static_cast< void * >( &v_short ) );
	ft::vector< void const * >										v_void_const_p( 2, NULL, std::allocator< void * >() );
	ft::vector< my_empty_struct, myallocator< my_empty_struct > >	v_my_empty_struct( 3, my_empty_struct() );
	ft::vector< my_pointer_struct, myallocator< char > >			v_my_pointer_struct( 6, my_pointer_struct(), myallocator< int >() );
	ft::vector< my_const_pointer_struct >							v_my_const_pointer_struct( 4, my_const_pointer_struct() );
	ft::vector< my_bool_struct >									v_my_bool_struct( 2 );
	ft::vector< my_char_struct, std::allocator< my_char_struct > >	v_my_char_struct( 3 );
	ft::vector< my_int_struct, myallocator< int > >					v_my_int_struct( 0, my_int_struct() );
	ft::vector< my_double_struct, myallocator< double > >			v_my_double_struct;
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
	if ( v_my_double_struct.get_allocator().is_myallocator() )
		std::cout << "v_my_double_struct::allocator:\t\t\tmyallocator" << std::endl;
	if ( v_my_struct_struct.get_allocator().address( *( v_my_struct_struct.begin() ) ) )
		std::cout << "v_my_struct_struct::allocator:\t\t\tstd::allocator" << std::endl;
	if ( v_mystruct.get_allocator().is_myallocator() )
		std::cout << "v_mystruct::allocator:\t\t\t\tmyallocator" << std::endl;

	std::cout << std::endl;

	std::cout << std::endl << "size() & empty()" << std::boolalpha << std::endl << std::endl;

	std::cout << "v_char:\t\t\t\t" << v_char.size() << "\t" << v_char.empty() << std::endl;
	std::cout << "v_wchar_t:\t\t\t" << v_wchar_t.size() << "\t" << v_wchar_t.empty() << std::endl;
	std::cout << "v_signed_char:\t\t\t" << v_signed_char.size() << "\t" << v_signed_char.empty() << std::endl;
	std::cout << "v_unsigned_char:\t\t" << v_unsigned_char.size() << "\t" << v_unsigned_char.empty() << std::endl;
	std::cout << "v_short:\t\t\t" << v_short.size() << "\t" << v_short.empty() << std::endl;
	std::cout << "v_int:\t\t\t\t" << v_int.size() << "\t" << v_int.empty() << std::endl;
	std::cout << "v_long:\t\t\t\t" << v_long.size() << "\t" << v_long.empty() << std::endl;
	std::cout << "v_unsigned_short:\t\t" << v_unsigned_short.size() << "\t" << v_unsigned_short.empty() << std::endl;
	std::cout << "v_unsigned_int:\t\t\t" << v_unsigned_int.size() << "\t" << v_unsigned_int.empty() << std::endl;
	std::cout << "v_unsigned_long:\t\t" << v_unsigned_long.size() << "\t" << v_unsigned_long.empty() << std::endl;
	std::cout << "v_float:\t\t\t" << v_float.size() << "\t" << v_float.empty() << std::endl;
	std::cout << "v_double:\t\t\t" << v_double.size() << "\t" << v_double.empty() << std::endl;
	std::cout << "v_long_double:\t\t\t" << v_long_double.size() << "\t" << v_long_double.empty() << std::endl;
	std::cout << "v_void_p:\t\t\t" << v_void_p.size() << "\t" << v_void_p.empty() << std::endl;
	std::cout << "v_void_const_p:\t\t\t" << v_void_const_p.size() << "\t" << v_void_const_p.empty() << std::endl;
	std::cout << "v_my_empty_struct:\t\t" << v_my_empty_struct.size() << "\t" << v_my_empty_struct.empty() << std::endl;
	std::cout << "v_my_pointer_struct:\t\t" << v_my_pointer_struct.size() << "\t" << v_my_pointer_struct.empty() << std::endl;
	std::cout << "v_my_const_pointer_struct:\t" << v_my_const_pointer_struct.size() << "\t" << v_my_const_pointer_struct.empty() << std::endl;
	std::cout << "v_my_bool_struct:\t\t" << v_my_bool_struct.size() << "\t" << v_my_bool_struct.empty() << std::endl;
	std::cout << "v_my_char_struct:\t\t" << v_my_char_struct.size() << "\t" << v_my_char_struct.empty() << std::endl;
	std::cout << "v_my_int_struct:\t\t" << v_my_int_struct.size() << "\t" << v_my_int_struct.empty() << std::endl;
	std::cout << "v_my_double_struct:\t\t" << v_my_double_struct.size() << "\t" << v_my_double_struct.empty() << std::endl;
	std::cout << "v_my_struct_struct:\t\t" << v_my_struct_struct.size() << "\t" << v_my_struct_struct.empty() << std::endl;
	std::cout << "v_mystruct:\t\t\t" << v_mystruct.size() << "\t" << v_mystruct.empty() << std::endl;

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
*/


/*
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

}
*/
