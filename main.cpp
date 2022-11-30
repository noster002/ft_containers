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
#include <bitset>
#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"
#include "pair.hpp"
#include "make_pair.hpp"
#include "tests/myallocator.hpp"
#include "tests/mystruct.hpp"

int	main( void )
{
	ft::stack< int >	stack;

	if ( stack.empty() )
		std::cout << "stack is empty" << std::endl;
	std::cout << "size: " << stack.size() << std::endl;

	stack.push( 5 );

	std::cout << stack.top() << std::endl;

	stack.push( 2 );

	std::cout << stack.top() << std::endl;

	if ( !( stack.empty() ) )
		std::cout << "stack is not empty" << std::endl;
	std::cout << "size: " << stack.size() << std::endl;

	ft::vector< int >						container( 5, 3 );

	ft::stack< int, ft::vector< int > >		stack1( container );

	std::cout << stack1.top() << std::endl;
	std::cout << "size: " << stack1.size() << std::endl;

	ft::stack< char, std::vector< char > >	stack2;

	stack2.push( 'r' );

	std::cout << stack2.top() << std::endl;

	ft::stack< int >						stack3( stack );

	std::cout << stack3.top() << std::endl;
	std::cout << "size: " << stack3.size() << std::endl;

	stack3.pop();

	std::cout << stack3.top() << std::endl;
	std::cout << "size: " << stack3.size() << std::endl;

	stack3.top() = 14;

	std::cout << stack3.top() << std::endl;
	std::cout << "size: " << stack3.size() << std::endl;

	ft::stack< int > const					stack4( stack3 );
	int const &								i = stack4.top();

	std::cout << i << std::endl;
	std::cout << "size: " << stack3.size() << std::endl;

	if ( stack == stack1 )
		std::cout << "stack == stack1" << std::endl;
	if ( stack != stack1 )
		std::cout << "stack != stack1" << std::endl;
	if ( stack < stack1 )
		std::cout << "stack < stack1" << std::endl;
	if ( stack <= stack1 )
		std::cout << "stack <= stack1" << std::endl;
	if ( stack > stack1 )
		std::cout << "stack > stack1" << std::endl;
	if ( stack >= stack1 )
		std::cout << "stack >= stack1" << std::endl;

	if ( stack1 == stack )
		std::cout << "stack1 == stack" << std::endl;
	if ( stack1 != stack )
		std::cout << "stack1 != stack" << std::endl;
	if ( stack1 < stack )
		std::cout << "stack1 < stack" << std::endl;
	if ( stack1 <= stack )
		std::cout << "stack1 <= stack" << std::endl;
	if ( stack1 > stack )
		std::cout << "stack1 > stack" << std::endl;
	if ( stack1 >= stack )
		std::cout << "stack1 >= stack" << std::endl;

	if ( stack == stack )
		std::cout << "stack == stack" << std::endl;
	if ( stack != stack )
		std::cout << "stack != stack" << std::endl;
	if ( stack < stack )
		std::cout << "stack < stack" << std::endl;
	if ( stack <= stack )
		std::cout << "stack <= stack" << std::endl;
	if ( stack > stack )
		std::cout << "stack > stack" << std::endl;
	if ( stack >= stack )
		std::cout << "stack >= stack" << std::endl;

	return ( 0 );
}
