/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:43:25 by nosterme          #+#    #+#             */
/*   Updated: 2022/10/14 16:43:58 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{

	template< typename T1, typename T2 >
	struct pair
	{

		typedef T1		first_type;
		typedef T2		second_type;

		first_type		first;
		second_type		second;

		pair( void ) : first( 0 ), second( 0 )
		{
			return ;
		}
		pair( first_type const & x, second_type const & y )\
		 : first( x ), second( y )
		{
			return ;
		}
		template< typename U1, typename U2 >
		pair( pair< U1, U2 > const & other )\
		 : first( other.first ), second( other.second )
		{
			return ;
		}
		pair&	operator=( pair const & rhs )
		{
			this->first = rhs.first;
			this->second = rhs.second;
			return ( *this );
		}

	};

	template< typename T1, typename T2 >
	bool	operator==( pair< T1, T2 > const & lhs, \
						pair< T1, T2 > const & rhs )
	{
		return ( ( lhs.first == rhs.first ) && ( lhs.second == rhs.second ) );
	}
	template< typename T1, typename T2 >
	bool	operator!=( pair< T1, T2 > const & lhs, \
						pair< T1, T2 > const & rhs )
	{
		return ( !( lhs == rhs ) );
	}
	template< typename T1, typename T2 >
	bool	operator<( pair< T1, T2 > const & lhs, \
					   pair< T1, T2 > const & rhs )
	{
		return ( ( lhs.first < rhs.first ) || \
				 ( !( rhs.first < lhs.first ) && ( lhs.second < rhs.second ) ) );
	}
	template< typename T1, typename T2 >
	bool	operator<=( pair< T1, T2 > const & lhs, \
						pair< T1, T2 > const & rhs )
	{
		return ( !( rhs < lhs ) );
	}
	template< typename T1, typename T2 >
	bool	operator>( pair< T1, T2 > const & lhs, \
					   pair< T1, T2 > const & rhs )
	{
		return ( rhs < lhs );
	}
	template< typename T1, typename T2 >
	bool	operator>=( pair< T1, T2 > const & lhs, \
						pair< T1, T2 > const & rhs )
	{
		return ( !( lhs < rhs ) );
	}

}

#endif
