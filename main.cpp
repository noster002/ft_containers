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
	std::vector< int >				vi( 3, 5 );
	std::vector< float >			vf( 3, 2.5 );
	std::vector< int >::iterator	it_vi = vi.begin();
	vf[0] = 3.2;
	std::vector< float >::iterator	it_vf = vf.begin();
	std::vector< int >::iterator	it_vi2;

	std::cout << "it_vi.base(): " << *it_vi.base() << std::endl;
	std::cout << "it_vf.base(): " << *it_vf.base() << std::endl;
	return ( 0 );
}
