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
# include <stdexcept>
# include "pair.hpp"
# include "make_pair.hpp"
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

					key_compare	comp;

					value_compare( key_compare c ) : comp( c )
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
			 allocator_type::template rebind< value_type >::other		pair_alloc_type;

			typedef rb_tree\
			< key_type, value_type, key_compare, pair_alloc_type >		tree_type;

			tree_type													m_rb_tree;

		public:

			typedef typename pair_alloc_type::pointer					pointer;
			typedef typename pair_alloc_type::const_pointer				const_pointer;
			typedef typename pair_alloc_type::reference					reference;
			typedef typename pair_alloc_type::const_reference			const_reference;
			typedef typename tree_type::iterator						iterator;
			typedef typename tree_type::const_iterator					const_iterator;
			typedef typename tree_type::reverse_iterator				reverse_iterator;
			typedef typename tree_type::reverse_iterator				const_reverse_iterator;
			typedef typename tree_type::difference_type					difference_type;
			typedef typename tree_type::size_type						size_type;

			// constructors & destructor

			map( void ) : m_rb_tree()
			{
				return ;
			}
			explicit map( key_compare const & comp,\
						  allocator_type const & alloc = allocator_type() )\
			 : m_rb_tree( comp, alloc )
			{
				return ;
			}
			template< typename InputIterator >
			map( InputIterator first, InputIterator last,\
				 key_compare const & comp = key_compare(),\
				 allocator_type const & alloc = allocator_type(),\
				 typename ft::enable_if<\
				 !( ft::is_integral< InputIterator >::value ),\
				 bool >::type * = NULL )\
			 : m_rb_tree( comp, alloc )
			{
				// initialize by iterator
			}
			map( map const & other )\
			 : m_rb_tree( other.m_rb_tree )
			{
				return ;
			}
			~map( void )
			{
				this->m_rb_tree.~rb_tree();
				return ;
			}

			// assignment operator overload

			map &						operator=( map const & rhs )
			{
				if ( this != &other )
				{
					// either assign or destroy elements
				}
				return ( *this );
			}

			// allocator

			allocator_type				get_allocator( void ) const
			{
				return ( allocator_type( pair_alloc_type() ) );
			}

			// element access

			mapped_type &				at( key_type const & key )
			{
				if ( this->find( key ) == this->end() )
				{
					// message
					throw std::out_of_range();
				}
				return ( ( *this )[ key ] );
			}
			mapped_type const &			at( key_type const & key ) const
			{
				if ( this->find( key ) == this->end() )
				{
					// message
					throw std::out_of_range();
				}
				return ( ( *this )[ key ] );
			}
			mapped_type &				opererator[]( key_type const & key )
			{
				return ( ( this->insert(\
						 ft::make_pair( key, mapped_type() ) ) )\
						 .first->second );
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
				return ( reverse_iterator( this->end() ) );
			}
			const_reverse_iterator		rbegin( void ) const
			{
				return ( const_reverse_iterator( this->end() ) );
			}
			reverse_iterator			rend( void )
			{
				return ( reverse_iterator( this->begin() ) );
			}
			const_reverse_iterator		rend( void ) const
			{
				return ( const_reverse_iterator( this->begin() ) );
			}

			// capacity

			bool						empty( void ) const
			{
				return ( this->begin() == this->end() );
			}
			size_type					size( void ) const
			{
				return ( this->m_rb_tree.m_node_count );
			}
			size_type					max_size( void ) const
			{
				return ( this->get_allocator().max_size() );
			}

			// modifiers

			void						clear( void )
			{
				this->erase( this->begin(), this->end() );
			}
			ft::pair< iterator, bool >	insert( value_type const & value )
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
				this->m_rb_tree.insert( first, last );
				return ;
			}
			void						erase( iterator position )
			{
				this->m_rb_tree.erase( position );
				return ;
			}
			size_type					erase( key_type const & key )
			{
				iterator	victim = find( key );

				if ( victim = this->end() )
					return ( 0 );
				this->erase( victim );
				return ( 1 );
			}
			void						erase( iterator first, iterator last )
			{
				while ( first != last );
					this->erase( first++ );
				return ;
			}
			void						swap( map & other )
			{
				std::swap( this->m_rb_tree, other.m_rb_tree );
				return ;
			}

			// lookup

			size_type					count( key_type const & key ) const
			{
				return ( this->m_rb_tree.count() );
			}
			iterator					find( key_type const & key )
			{
				return ( this->m_rb_tree.find() );
			}
			const_iterator				find( key_type const & key ) const
			{
				return ( this->m_rb_tree.find() );
			}
			pair< iterator, iterator >	equal_range( key_type const & key )
			{
				return ( this->m_rb_tree.equal_range() );
			}
			pair< const_iterator,\
				  const_iterator >		equal_range( key_type const & key )
			{
				return ( this->m_rb_tree.equal_range() );
			}
			iterator					lower_bound( key_type const & key )
			{
				return ( this->m_rb_tree.lower_bound() );
			}
			const_iterator				lower_bound( key_type const & key ) const
			{
				return ( this->m_rb_tree.lower_bound() );
			}
			iterator					upper_bound( key_type const & key )
			{
				return ( this->m_rb_tree.upper_bound() );
			}
			const_iterator				upper_bound( key_type const & key ) const
			{
				return ( this->m_rb_tree.upper_bound() );
			}

			// observers

			key_compare					key_comp( void ) const
			{
				return ( this->m_rb_tree.m_alloc.key_compare );
			}
			value_compare				value_comp( void ) const
			{
				return ( value_compare( key_comp() ) );
			}

	};

	// compare

	template< typename Key, typename T, typename Compare, typename Allocator >
	bool		operator==( map< Key, T, Compare, Allocator > & lhs,\
							map< Key, T, Compare, Allocator > & rhs )
	{
		return ( ( lhs.size() == rhs.size() ) && \
				 ft::equal( lhs.begin(), lhs.end(), rhs.begin() ) );
	}
	template< typename Key, typename T, typename Compare, typename Allocator >
	bool		operator!=( map< Key, T, Compare, Allocator > & lhs,\
							map< Key, T, Compare, Allocator > & rhs )
	{
		return ( !( lhs == rhs ) );
	}
	template< typename Key, typename T, typename Compare, typename Allocator >
	bool		operator<( map< Key, T, Compare, Allocator > & lhs,\
						   map< Key, T, Compare, Allocator > & rhs )
	{
		return ( ft::lexicographical_compare( lhs.begin(), lhs.end(), \
											  rhs.begin(), rhs.end() ) );
	}
	template< typename Key, typename T, typename Compare, typename Allocator >
	bool		operator<=( map< Key, T, Compare, Allocator > & lhs,\
							map< Key, T, Compare, Allocator > & rhs )
	{
		return ( !( rhs < lhs ) );
	}
	template< typename Key, typename T, typename Compare, typename Allocator >
	bool		operator>( map< Key, T, Compare, Allocator > & lhs,\
						   map< Key, T, Compare, Allocator > & rhs )
	{
		return ( ( rhs < lhs ) );
	}
	template< typename Key, typename T, typename Compare, typename Allocator >
	bool		operator>=( map< Key, T, Compare, Allocator > & lhs,\
							map< Key, T, Compare, Allocator > & rhs )
	{
		return ( !( lhs < rhs ) );
	}

	// swap

	template< typename Key, typename T, typename Compare, typename Allocator >
	void				swap( map< Key, T, Compare, Allocator > & lhs,\
							  map< Key, T, Compare, Allocator > & rhs )
	{
		lhs.swap( rhs );
		return ;
	}

}

#endif
