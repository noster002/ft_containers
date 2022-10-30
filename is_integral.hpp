/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:26:18 by nosterme          #+#    #+#             */
/*   Updated: 2022/10/27 18:43:46 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

template< typename T, T Val >
struct integral_constant
{

	static T const								value;
	typedef T									value_type;
	typedef struct integral_constant< T, Val >	type;

	operator	value_type( void ) const
	{
		return ( value );
	}

};

template< typename T, T Val >
T const integral_constant< T, Val >::value = Val;

typedef struct integral_constant< bool, true >	true_type;
typedef struct integral_constant< bool, false >	false_type;

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

	template<> struct is_integral< short > : public true_type {};
	template<> struct is_integral< int > : public true_type {};
	template<> struct is_integral< long > : public true_type {};

	template<> struct is_integral< unsigned short > : public true_type {};
	template<> struct is_integral< unsigned int > : public true_type {};
	template<> struct is_integral< unsigned long > : public true_type {};

}

template< typename T, typename U >
struct is_same : public false_type {};

template< typename T >
struct is_same< T, T > : public true_type {};

#endif
