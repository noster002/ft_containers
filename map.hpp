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
# include "RedBlackTree.hpp"

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

			typedef Key													key_type;
			typedef T													mapped_type;
			typedef typename ft::pair< key_type const, mapped_type >	value_type;
			typedef Compare												key_compare;
			typedef Allocator											allocator_type;

			class value_compare : public std::binary_function< value_type, value_type, bool >
			{

				private:

					friend class ft::map< Key, T, Compare, Allocator >;

				protected:

					Compare	comp;

					value_compare( Compare c ) : comp( c )
					{
						return ;
					}

				public:

					bool	operator()( value_type const & lhs, value_type const & rhs )
					{
						return ( comp( lhs.first, rhs.first ) );
					}

			};

		private:

			typedef typename\
			 allocator_type::template rebind< value_type >::other		type_alloc_type;
			typedef RedBlackTree< Key, T, Compare, Allocator >			rb_tree;

			rb_tree														m_rb_tree;

		public:

			typedef typename type_alloc_type::pointer					pointer;
			typedef typename type_alloc_type::const_pointer				const_pointer;
			typedef typename type_alloc_type::reference					reference;
			typedef typename type_alloc_type::reference					const_reference;
			typedef typename rb_tree::iterator							iterator;
			typedef typename rb_tree::const_iterator					const_iterator;
			typedef typename rb_tree::reverse_iterator					reverse_iterator;
			typedef typename rb_tree::reverse_iterator					const_reverse_iterator;
			typedef typename rb_tree::difference_type					difference_type;
			typedef typename rb_tree::size_type							size_type;

	};

}

#endif
