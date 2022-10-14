/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pair.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:35:01 by nosterme          #+#    #+#             */
/*   Updated: 2022/10/14 16:42:28 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_PAIR_HPP
# define MAKE_PAIR_HPP
# include "pair.hpp"

namespace ft
{

	template< typename T1, typename T2 >
	pair< T1, T2 >	make_pair( T1 x, T2 y )
	{
		return ( pair< T1, T2 >( x, y ) );
	}

}

#endif
