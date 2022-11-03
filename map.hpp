/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:37:50 by nosterme          #+#    #+#             */
/*   Updated: 2022/09/09 20:37:50 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
# include <functional>
# include <memory>
# include "pair.hpp"
# include "iterator_traits.hpp"

namespace ft
{

	template<\
			 typename Key,\
			 typename T,\
			 typename Compare = std::less< Key >,\
			 typename Allocator = std::allocator< ft::pair< Key const, T > >\
			>
	class map
	{

		public:

			typedef Key															key_type;
			typedef T															mapped_type;
			typedef typename ft::pair< key_type const, mapped_type >			value_type;
			
			typedef typename ft::reverse_iterator< iterator >					reverse_iterator;
			typedef typename ft::reverse_iterator< const_iterator >				const_reverse_iterator;
			typedef typename ft::iterator_traits< iterator >::difference_type	difference_type;
			typedef typename std::size_t										size_type;

	};

}

#endif
