/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:02:41 by nosterme          #+#    #+#             */
/*   Updated: 2022/10/14 15:18:05 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
# define EQUAL_HPP

namespace ft
{

	template< typename InputIterator1, typename InputIterator2 >
	bool	equal( InputIterator1 first1, InputIterator1 last1, \
				   InputIterator2 first2 )
	{
		while ( first1 != last1 )
		{
			if ( *first1 != *first2 )
				return ( false );
			++first1;
			++first2;
		}
		return ( true );
	}

	template< typename InputIterator1, typename InputIterator2, \
			  typename BinaryPredicate >
	bool	equal( InputIterator1 first1, InputIterator1 last1, \
				   InputIterator2 first2, BinaryPredicate pred )
	{
		while ( first1 != last1 )
		{
			if ( !pred( *first1, *first2 ) )
				return ( false );
			++first1;
			++first2;
		}
		return ( true );
	}

}

#endif
