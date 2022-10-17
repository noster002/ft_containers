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

//#include "vector.hpp"
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
	std::vector< int >					vi( 2, 2 );
	std::vector< int >::iterator		it_vi = vi.begin();
	std::vector< int >::const_iterator	cit_vi = it_vi;
	std::vector< int >::const_iterator	cit_vi2 = cit_vi;
	std::vector< int >::iterator		it_vi2 = it_vi;

	std::cout << *cit_vi2 << *it_vi2 << std::endl;
	return ( 0 );
}
