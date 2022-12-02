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

#include <memory>
#include <iostream>
#include <iterator>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <bitset>
#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include "set.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"
#include "pair.hpp"
#include "make_pair.hpp"
#include "tests/myallocator.hpp"
#include "tests/mystruct.hpp"
#include "tests/mycompare.hpp"

int	main( void )
{
	ft::set< int >			set;

	std::cout << set.max_size() << std::endl;
	std::cout << "set is empty: " << std::boolalpha << set.empty() << std::endl;
	std::cout << set.size() << std::endl;

	set.insert( 5 );

	std::cout << "set is empty: " << std::boolalpha << set.empty() << std::endl;
	std::cout << set.size() << std::endl;

	return ( 0 );
}
