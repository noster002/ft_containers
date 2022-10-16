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
	char	c( 'c' );
	char	d( 'd' );
	char*	c_ptr = &c;
	char*	d_ptr = &d;

	std::cout << "Address c: " << ( void* )c_ptr << std::endl << "Address d: " << ( void* )d_ptr << std::endl;
	return ( 0 );
}
