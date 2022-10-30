/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:22:09 by nosterme          #+#    #+#             */
/*   Updated: 2022/10/28 00:15:41 by nosterme         ###   ########.fr       */
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

	// vector::reserve

	ft::vector< int >	vi( 2, 3 );
	int*				p_vi = &*( vi.begin() );
	int&				r_vi = *vi.begin();

	std::cout << std::endl << "vector::reserve()" << std::endl << std::endl;

	for ( ft::vector< int >::iterator it = vi.begin(); it != vi.end(); ++it )
		std::cout << *it << std::endl;
	std::cout << "*p_vi: " << *p_vi << "\np_vi: " << p_vi << std::endl;
	std::cout << "r_vi: " << r_vi << "\n&r_vi: " << &r_vi << std::endl;
	std::cout << "&*vi.begin(): " << &*vi.begin() << std::endl;
	std::cout << "*vi.begin(): " << *vi.begin() << std::endl;
	std::cout << "&vi: " << &vi << std::endl;

	vi.reserve( 3 );

	for ( ft::vector< int >::iterator it = vi.begin(); it != vi.end(); ++it )
		std::cout << *it << std::endl;
	std::cout << "*p_vi: " << *p_vi << "\np_vi: " << p_vi << std::endl;
	std::cout << "r_vi: " << r_vi << "\n&r_vi: " << &r_vi << std::endl;
	std::cout << "&*vi.begin(): " << &*vi.begin() << std::endl;
	std::cout << "*vi.begin(): " << *vi.begin() << std::endl;
	std::cout << "&vi: " << &vi << std::endl;

	try
	{
		data.reserve( 2587996154 );
	}
	catch ( std::exception const & exc )
	{
		std::cout << exc.what() << std::endl;
	}
	try
	{
		data.reserve( 2587996155 );
	}
	catch ( std::exception const & exc )
	{
		std::cout << exc.what() << std::endl;
	}

	std::cout << std::endl;

}
*/
