/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mycompare.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:13:23 by nosterme          #+#    #+#             */
/*   Updated: 2022/12/01 13:14:04 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYCOMPARE_HPP
# define MYCOMPARE_HPP

template< typename T >
struct mycompare
{

	bool	operator()( T const & lhs, T const & rhs ) const
	{
		return ( lhs < rhs );
	}

};

#endif
