/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:48:06 by nosterme          #+#    #+#             */
/*   Updated: 2022/11/09 01:20:23 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RedBlackTree.hpp"

void	rb_tree_rotate_left( rb_tree_node_base * const lhs,\
							 rb_tree_node_base *& root )
{
	if ( ( lhs == 0 ) || ( lhs->m_right == 0 ) )
		return ;
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
	if ( ( rhs == 0 ) || ( rhs->m_left == 0 ) )
		return ;
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
	rb_tree_node_base *&	root = head.m_parent;

	node->m_color = red;
	node->m_parent = parent;
	node->m_left = 0;
	node->m_right = 0;

	if ( insert_left )
	{
		parent->m_left = node;

		if ( parent == &head )
		{
			head.m_parent = node;
			head.m_right = node;
		}
		else if ( parent == head.m_left )
			head.m_left = node;
	}
	else
	{
		parent->m_right = node;

		if ( parent == head.m_right )
			head.m_right = node;
	}
	while ( ( node != root ) && ( node->m_parent->m_color == red ) )
	{
		rb_tree_node_base * const	grandparent = node->m_parent->m_parent;

		if ( node->m_parent == grandparent->m_left)
		{
			rb_tree_node_base * const	uncle = grandparent->m_right;

			if ( uncle && ( uncle->m_color == red ) )
			{
				node->m_parent->m_color = black;
				uncle->m_color = black;
				grandparent->m_color = red;
				node = grandparent;
			}
			else
			{
				if ( node == node->m_parent->m_right )
				{
					node = node->m_parent;
					rb_tree_rotate_left( node, root );
				}
				node->m_parent->m_color = black;
				grandparent->m_color = red;
				rb_tree_rotate_right( grandparent, root );
			}
		}
		else
		{
			rb_tree_node_base * const	uncle = grandparent->m_left;

			if ( uncle && ( uncle->m_color == red ) )
			{
				node->m_parent->m_color = black;
				uncle->m_color = black;
				grandparent->m_color = red;
				node = grandparent;
			}
			else
			{
				if ( node == node->m_parent->m_left )
				{
					node = node->m_parent;
					rb_tree_rotate_right( node, root );
				}
				node->m_parent->m_color = black;
				grandparent->m_color = red;
				rb_tree_rotate_left( grandparent, root );
			}
		}
	}
	root->m_color = black;
	return ;
}

rb_tree_node_base *	rb_tree_rebalance_for_erase( rb_tree_node_base * const node,\
												 rb_tree_node_base & head )
{
	rb_tree_node_base *&	root = head.m_parent;

	// node has two NIL nodes

	if ( node == node->m_parent->m_left )
	{
		if ( node->m_color == black )
		{
			rb_tree_node_base *	sibling = node->m_parent->m_right;

			if ( sibling->m_color == red )
			{
				rb_tree_rotate_left( node->m_parent, root );
				node->m_parent->m_parent->m_color = black;
				sibling = node->m_parent->m_right;
				if ( sibling == 0 )
					node->m_parent->m_color = red;
				else
					sibling->m_color = red;
			}
			else
			{
				if ( sibling->m_right )
				{
					rb_tree_rotate_left( node->m_parent, root );
					node->m_parent->m_parent->m_color = node->m_parent->m_color;
					sibling->m_right->m_color = black;
					node->m_parent->m_color = black;
				}
				else
				{
					rb_tree_rotate_right( sibling, root );
					rb_tree_rotate_left( node->m_parent, root );
					node->m_parent->m_parent->m_color = node->m_parent->m_color;
					node->m_parent->m_color = black;
				}
			}
		}
		node->m_parent->m_left = 0;
	}
	else
	{
		if ( node->m_color == black )
		{
			rb_tree_node_base *	sibling = node->m_parent->m_left;

			if ( sibling->m_color == red )
			{
				rb_tree_rotate_right( node->m_parent, root );
				node->m_parent->m_parent->m_color = black;
				sibling = node->m_parent->m_left;
				if ( sibling == 0 )
					node->m_parent->m_color = red;
				else
					sibling->m_color = red;
			}
			else
			{
				if ( sibling->m_left )
				{
					rb_tree_rotate_right( node->m_parent, root );
					node->m_parent->m_parent->m_color = node->m_parent->m_color;
					sibling->m_left->m_color = black;
					node->m_parent->m_color = black;
				}
				else
				{
					rb_tree_rotate_left( sibling, root );
					rb_tree_rotate_right( node->m_parent, root );
					node->m_parent->m_parent->m_color = node->m_parent->m_color;
					node->m_parent->m_color = black;
				}
			}
		}
		node->m_parent->m_right = 0;
	}
	return ( node );
}