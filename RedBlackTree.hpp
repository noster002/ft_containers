/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:40:53 by nosterme          #+#    #+#             */
/*   Updated: 2022/11/08 13:52:54 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef rb_tree_HPP
# define rb_tree_HPP
# include <algorithm>

enum rb_tree_color
{
	red = false,
	black = true
};

struct rb_tree_node_base
{

	typedef rb_tree_node_base *				node_base_ptr;
	typedef rb_tree_node_base const *		const_node_base_ptr;

	rb_tree_color			m_color;
	node_base_ptr			m_parent;
	node_base_ptr			m_left;
	node_base_ptr			m_right;

};

template< typename Val >
struct rb_tree_node : public rb_tree_node_base
{

	typedef rb_tree_node< Val > *			node_ptr;

	Val						m_value;

};


template< typename Key, typename Val, typename Compare, typename Allocator >
class rb_tree
{

	private:

		typedef typename Allocator::template rebind< rb_tree_node< Val >::other\
			node_allocator;

	protected:

		typedef rb_tree_node_base *				node_base_ptr;
		typedef rb_tree_node_base const *		const_node_base_ptr;

	public:

		typedef Key										key_type;
		typedef Val										value_type;
		typedef rb_tree_node< value_type > *			node_ptr;
		typedef rb_tree_node< value_type > const *		const_node_ptr;
		typedef typename std::size_t					size_type;
		typedef typename std::ptrdiff_t					difference_type;
		typedef Allocator								allocator_type;

	protected:

		template< typename KeyCompare,\
				  typename ft::enable_if< \
				  !ft::is_integral< KeyCompare >::value >::type >
		struct rb_tree_allocator : public node_allocator
		{

			typedef KeyCompare		key_compare;

			key_compare				m_key_compare;
			rb_tree_node_base		m_head;
			size_type				m_node_count;

			rb_tree_allocator( void )\
			 : node_allocator(), m_key_compare(), m_head(), m_node_count( 0 )
			{
				m_initialize();
				return ;
			}
			rb_tree_allocator( key_compare const & comp, node_allocator const & alloc )\
			 : node_allocator( alloc ), m_key_compare( comp ), m_head(), m_node_count( 0 )
			{
				m_initialize();
				return ;
			}

		private:

			void	m_initialize( void )
			{
				m_head.m_color = red;
				m_head.m_parent = 0;
				m_head.m_left = 0;
				m_head.m_right = 0;
				return ;
			}

		};

	rb_tree_allocator		m_alloc;

};


#endif
