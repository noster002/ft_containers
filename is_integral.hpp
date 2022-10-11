/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:26:18 by nosterme          #+#    #+#             */
/*   Updated: 2022/10/11 19:13:07 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

template< bool Val >
struct integral_constant_bool
{

	static bool										value = Val;
	typedef bool									value_type;
	typedef struct integral_constant_bool< Val >	type;

	operator	value_type( void ) const
	{
		return ( value );
	}

};

typedef struct integral_constant_bool< true >	true_type;
typedef struct integral_constant_bool< false >	false_type;

namespace ft
{

	template< typename T > struct is_integral : public false_type {};
	template< typename T > struct is_integral< T const > : public is_integral< T > {};
	template< typename T > struct is_integral< T volatile > : public is_integral< T > {};
	template< typename T > struct is_integral< T const volatile > : public is_integral< T > {};

	template<> struct is_integral< bool > : public true_type {};

	template<> struct is_integral< char > : public true_type {};
	template<> struct is_integral< wchar_t > : public true_type {};
	template<> struct is_integral< signed char > : public true_type {};
	template<> struct is_integral< unsigned char > : public true_type {};

	template<> struct is_integral< short int > : public true_type {};
	template<> struct is_integral< int > : public true_type {};
	template<> struct is_integral< long int > : public true_type {};

	template<> struct is_integral< unsigned short int > : public true_type {};
	template<> struct is_integral< unsigned int > : public true_type {};
	template<> struct is_integral< unsigned long int > : public true_type {};

}

#endif
