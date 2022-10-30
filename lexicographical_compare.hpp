/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:20:20 by nosterme          #+#    #+#             */
/*   Updated: 2022/10/25 15:16:29 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
# define LEXICOGRAPHICAL_COMPARE_HPP

namespace ft
{

	template< typename InputIterator1, typename InputIterator2 >
	bool	lexicographical_compare( InputIterator1 first1, InputIterator1 last1, \
									 InputIterator2 first2, InputIterator2 last2 )
	{
		while ( first1 != last1 )
		{
			if ( first2 == last2 || *first2 < *first1 )
				return ( false );
			else if ( *first1 < *first2 )
				return ( true );
			++first1;
			++first2;
		}
		return ( first2 != last2 );
	}

	template< typename InputIterator1, typename InputIterator2, typename Compare >
	bool	lexicographical_compare( InputIterator1 first1, InputIterator1 last1, \
									 InputIterator2 first2, InputIterator2 last2, \
									 Compare comp )
	{
		while ( first1 != last1 )
		{
			if ( first2 == last2 || comp( *first2, *first1 ) )
				return ( false );
			else if ( comp( *first1, *first2 ) )
				return ( true );
			++first1;
			++first2;
		}
		return ( first2 != last2 );
	}

}

#endif
