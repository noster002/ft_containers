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

#include "vector.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "iterator_traits.hpp"
#include "pair.hpp"
#include "make_pair.hpp"
#include <iostream>
#include <iterator>
#include <memory>
#include <list>
#include <vector>

int	main( void )
{
	ft::vector< int >					vi( 2, 2 );
	ft::vector< int >::iterator		it_vi = vi.begin();
	ft::vector< int >::const_iterator	cit_vi = it_vi;
	ft::vector< int >::const_iterator	cit_vi2 = cit_vi;
	ft::vector< int >::iterator		it_vi2 = it_vi;
	ft::vector< int >::const_iterator	cit_vi3;
	cit_vi3 = 1 + cit_vi;

	if ( cit_vi2 == cit_vi )
		std::cout << "cit_vi3 - it_vi2 = " << ( cit_vi3 - it_vi2 ) << std::endl;
	( void )cit_vi2;
	( void )it_vi2;
	return ( 0 );
}
