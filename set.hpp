/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:48:23 by nosterme          #+#    #+#             */
/*   Updated: 2022/12/01 15:14:30 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP
# include "RedBlackTree.hpp"

namespace ft
{

	template< typename Key, typename Compare, typename Allocator >
	class set;

	template< typename Key, typename Compare, typename Allocator >
	bool		operator==( set< Key, Compare, Allocator > const & lhs, \
							set< Key, Compare, Allocator > const & rhs );
	template< typename Key, typename Compare, typename Allocator >
	bool		operator<( set< Key, Compare, Allocator > const & lhs,\
						   set< Key, Compare, Allocator > const & rhs );

}

template< typename Key, typename Compare, typename Allocator >
std::ostream &	operator<<( std::ostream & out, \
							ft::set< Key, Compare, Allocator > const & rhs );

namespace ft
{

	template< typename Key,\
			  typename Compare = std::less< Key >,\
			  typename Allocator = std::allocator< Key >\
			>
	class set
	{

		public:

			typedef Key						key_type;
			typedef Key						value_type;
			typedef Compare					key_compare;
			typedef Compare					value_compare;
			typedef Allocator				allocator_type;

		private:

			typedef typename allocator_type::template rebind< value_type >::other\
				type_alloc_type;

			template< typename KeyOfValue >
			struct key_of_value_type
			{

				KeyOfValue &		operator()( KeyOfValue & type )
				{
					return ( type );
				}
				KeyOfValue const &	operator()( KeyOfValue const & type ) const
				{
					return ( type );
				}

			};
			typedef key_of_value_type< value_type >				keyofvalue;

			typedef rb_tree< key_type, value_type, keyofvalue, key_compare, type_alloc_type >\
				tree_type;

			tree_type		m_rb_tree;

		public:

			typedef typename type_alloc_type::pointer			pointer;
			typedef typename type_alloc_type::const_pointer		const_pointer;
			typedef typename type_alloc_type::reference			reference;
			typedef typename type_alloc_type::const_reference	const_reference;
			typedef typename tree_type::iterator				iterator;
			typedef typename tree_type::const_iterator			const_iterator;
			typedef typename tree_type::reverse_iterator		reverse_iterator;
			typedef typename tree_type::const_reverse_iterator	const_reverse_iterator;
			typedef typename tree_type::difference_type			difference_type;
			typedef typename tree_type::size_type				size_type;

			// constructors & destructor

			set( void ) : m_rb_tree()
			{
				return ;
			}
			explicit set( key_compare const & comp,\
						  allocator_type const & alloc = allocator_type() )\
			 : m_rb_tree( comp, alloc )
			{
				return ;
			}
			template< typename InputIterator >
			set( InputIterator first, InputIterator last,\
				 key_compare const & comp = key_compare(),\
				 allocator_type const & alloc = allocator_type(),\
				 typename ft::enable_if<\
				 !( ft::is_integral< InputIterator >::value ),\
				 bool >::type * = NULL )
			 : m_rb_tree( comp, alloc )
			{
				this->insert( first, last );
				return ;
			}
			set( set const & other ) : m_rb_tree( other.m_rb_tree )
			{
				return ;
			}
			~set( void )
			{
				this->m_rb_tree.~rb_tree();
				return ;
			}

			// assignment operator overload

			set &						operator=( set const & other )
			{
				if ( this != &other )
					this->m_rb_tree = other.m_rb_tree;
				return ( *this );
			}

			// allocator

			allocator_type				get_allocator( void ) const
			{
				return ( this->m_rb_tree.get_allocator() );
			}

			// iterators

			iterator					begin( void )
			{
				return ( this->m_rb_tree.begin() );
			}
			const_iterator				begin( void ) const
			{
				return ( this->m_rb_tree.begin() );
			}
			iterator					end( void )
			{
				return ( this->m_rb_tree.end() );
			}
			const_iterator				end( void ) const
			{
				return ( this->m_rb_tree.end() );
			}
			reverse_iterator			rbegin( void )
			{
				return ( this->m_rb_tree.rbegin() );
			}
			const_reverse_iterator		rbegin( void ) const
			{
				return ( this->m_rb_tree.rbegin() );
			}
			reverse_iterator			rend( void )
			{
				return ( this->m_rb_tree.rend() );
			}
			const_reverse_iterator		rend( void ) const
			{
				return ( this->m_rb_tree.rend() );
			}

			// capacity

			bool						empty( void ) const
			{
				return ( this->m_rb_tree.empty() );
			}
			size_type					size( void ) const
			{
				return ( this->m_rb_tree.size() );
			}
			size_type					max_size( void ) const
			{
				return ( this->m_rb_tree.max_size() );
			}

			// modifiers

			void						clear( void )
			{
				this->m_rb_tree.clear();
			}
			pair< iterator, bool >		insert( value_type const & value )
			{
				return ( this->m_rb_tree.insert( value ) );
			}
			iterator					insert( iterator position, \
												value_type const & value )
			{
				return ( this->m_rb_tree.insert( position, value ) );
			}
			template< typename InputIterator >
			void						insert( InputIterator first, \
												InputIterator last, \
												typename ft::enable_if< \
												!( ft::is_integral< InputIterator >::value ), \
												bool >::type * = NULL )
			{
				while ( first != last )
					this->m_rb_tree.insert( *( first++ ) );
				return ;
			}
			void						erase( iterator position )
			{
				this->m_rb_tree.erase( position );
				return ;
			}
			size_type					erase( key_type const & key )
			{
				iterator	victim = this->find( key );

				if ( victim == this->end() )
					return ( 0 );
				this->erase( victim );
				return ( 1 );
			}
			void						erase( iterator first, iterator last )
			{
				while ( first != last )
					this->erase( first++ );
				return ;
			}
			void						swap( set & other )
			{
				this->m_rb_tree.swap( other.m_rb_tree );
				return ;
			}

			// lookup

			size_type					count( key_type const & key ) const
			{
				return ( this->m_rb_tree.count( key ) );
			}
			iterator					find( key_type const & key )
			{
				return ( this->m_rb_tree.find( key ) );
			}
			const_iterator				find( key_type const & key ) const
			{
				return ( this->m_rb_tree.find( key ) );
			}
			pair< iterator, iterator >	equal_range( key_type const & key )
			{
				return ( this->m_rb_tree.equal_range( key ) );
			}
			pair< const_iterator,\
				  const_iterator >		equal_range( key_type const & key ) const
			{
				return ( this->m_rb_tree.equal_range( key ) );
			}
			iterator					lower_bound( key_type const & key )
			{
				return ( this->m_rb_tree.lower_bound( key ) );
			}
			const_iterator				lower_bound( key_type const & key ) const
			{
				return ( this->m_rb_tree.lower_bound( key ) );
			}
			iterator					upper_bound( key_type const & key )
			{
				return ( this->m_rb_tree.upper_bound( key ) );
			}
			const_iterator				upper_bound( key_type const & key ) const
			{
				return ( this->m_rb_tree.upper_bound( key ) );
			}

			// observers

			key_compare					key_comp( void ) const
			{
				return ( this->m_rb_tree.key_comp() );
			}
			value_compare				value_comp( void ) const
			{
				return ( this->m_rb_tree.key_comp() );
			}

		private:

			friend bool	operator== <>( set< Key, Compare, Allocator > const & lhs,\
									   set< Key, Compare, Allocator > const & rhs );
			friend bool	operator< <>( set< Key, Compare, Allocator > const & lhs,\
									  set< Key, Compare, Allocator > const & rhs );

			friend std::ostream &	operator<< <>( std::ostream & out,\
												   set< Key, Compare, Allocator > const & rhs );

	};

	// relational operators

	template< typename Key, typename Compare, typename Allocator >
	bool		operator==( set< Key, Compare, Allocator > const & lhs, \
							set< Key, Compare, Allocator > const & rhs )
	{
		return ( ( lhs.m_rb_tree == rhs.m_rb_tree ) );
	}
	template< typename Key, typename Compare, typename Allocator >
	bool		operator!=( set< Key, Compare, Allocator > const & lhs, \
							set< Key, Compare, Allocator > const & rhs )
	{
		return ( !( lhs == rhs ) );
	}

	template< typename Key, typename Compare, typename Allocator >
	bool		operator<( set< Key, Compare, Allocator > const & lhs,\
						   set< Key, Compare, Allocator > const & rhs )
	{
		return ( ( lhs.m_rb_tree < rhs.m_rb_tree ) );
	}
	template< typename Key, typename Compare, typename Allocator >
	bool		operator<=( set< Key, Compare, Allocator > const & lhs, \
							set< Key, Compare, Allocator > const & rhs )
	{
		return ( !( rhs < lhs ) );
	}
	template< typename Key, typename Compare, typename Allocator >
	bool		operator>( set< Key, Compare, Allocator > const & lhs,\
						   set< Key, Compare, Allocator > const & rhs )
	{
		return ( ( rhs < lhs ) );
	}
	template< typename Key, typename Compare, typename Allocator >
	bool		operator>=( set< Key, Compare, Allocator > const & lhs, \
							set< Key, Compare, Allocator > const & rhs )
	{
		return ( !( lhs < rhs ) );
	}

	// swap

	template< typename Key, typename Compare, typename Allocator >
	void		swap( set< Key, Compare, Allocator > const & lhs,\
					  set< Key, Compare, Allocator > const & rhs )
	{
		lhs.swap( rhs );
		return ;
	}

}

template< typename Key, typename Compare, typename Allocator >
std::ostream &	operator<<( std::ostream & out, \
							ft::set< Key, Compare, Allocator > const & rhs )
{
	out << rhs.m_rb_tree;
	return ( out );
}

#endif
