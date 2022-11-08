/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:48:06 by nosterme          #+#    #+#             */
/*   Updated: 2022/11/08 14:34:13 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RedBlackTree.hpp"

void	rb_tree_rotate_left( rb_tree_node_base * const lhs,\
							 rb_tree_node_base *& root )
{
	rb_tree_node_base * const	rhs = lhs->m_right;

	lhs->m_right = rhs->m_left;
	if ( rhs->m_left != 0 )
		rhs->m_left->m_parent = lhs;
	rhs->m_parent = lhs->m_parent;
	if ( lhs == root )
		root = rhs;
	else if ( lhs == lhs->m_parent->m_left )
		lhs->m_parent->m_left = rhs;
	else
		lhs->m_parent->m_right = rhs;
	rhs->m_left = lhs;
	lhs->m_parent = rhs;

	return ;
}

void	rb_tree_rotate_right( rb_tree_node_base * const rhs,\
							  rb_tree_node_base *& root )
{
	rb_tree_node_base * const	lhs = rhs->m_left;

	rhs->m_left = lhs->m_right;
	if ( lhs->m_left != 0 )
		lhs->m_left->m_parent = rhs;
	lhs->m_parent = rhs->m_parent;
	if ( rhs == root )
		root = lhs;
	else if ( rhs == rhs->m_parent->m_right )
		rhs->m_parent->m_right = lhs;
	else
		rhs->m_parent->m_left = lhs;
	lhs->m_right = rhs;
	rhs->m_parent = lhs;

	return ;
}

void	rb_tree_insert_and_rebalance( bool const insert_left,\
									  rb_tree_node_base * node,\
									  rb_tree_node_base * parent,\
									  rb_tree_node_base & head )
{
	node->m_color = red;
	node->m_parent = parent;
	node->m_left = 0;
	node->m_right = 0;

	if ( insert_left )
	{
		parent->m_left = node;

		if ( parent == head.m_left )
			head.m_left = node;
	}
	else
	{
		parent->m_right = node;

		if ( parent == head.m_right )
			head.m_right = node;
	}
	return ;
}
