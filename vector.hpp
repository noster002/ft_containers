/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:35:54 by nosterme          #+#    #+#             */
/*   Updated: 2022/09/09 20:35:54 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include "VectorBase.hpp"
# include "IteratorBase.hpp"
# include "reverse_iterator.hpp"
# include "iterator_traits.hpp"
# include "is_integral.hpp"
# include "enable_if.hpp"
# include "equal.hpp"
# include "lexicographical_compare.hpp"
# include <limits>
# include <stdexcept>
# include <cstdio>

namespace ft
{

	template< typename T, typename Allocator = std::allocator< T > >
	class vector : protected VectorBase< T, Allocator >
	{

		private:

			typedef typename VectorBase< T, Allocator >::type_alloc_type		type_alloc_type;

		public:

			// naming policy

			typedef T															value_type;
			typedef typename type_alloc_type::reference							reference;
			typedef typename type_alloc_type::const_reference					const_reference;
			typedef typename type_alloc_type::pointer							pointer;
			typedef typename type_alloc_type::const_pointer						const_pointer;
			typedef IteratorBase< pointer, vector >								iterator;
			typedef IteratorBase< const_pointer, vector >						const_iterator;
			typedef typename ft::reverse_iterator< iterator >					reverse_iterator;
			typedef typename ft::reverse_iterator< const_iterator >				const_reverse_iterator;
			typedef typename ft::iterator_traits< iterator >::difference_type	difference_type;
			typedef typename std::size_t										size_type;
			typedef Allocator													allocator_type;

			// constructors, destructor

			vector( void )\
			: VectorBase< T, Allocator >()
			{
				return ;
			}
			explicit vector( allocator_type const & alloc )\
			: VectorBase< T, Allocator >( alloc )
			{
				return ;
			}
			explicit vector( size_type count,\
							value_type const & value = value_type(),\
							allocator_type const & alloc = allocator_type() )\
			: VectorBase< T, Allocator >( count, alloc )
			{
				this->defaultInitialize( count, value );
				return ;
			}
			template< typename InputIterator >
			vector( InputIterator first, InputIterator last, \
					allocator_type const & alloc = allocator_type(), \
					typename ft::enable_if< \
					!( ft::is_integral< InputIterator >::value ), \
					bool >::type* = NULL )\
			: VectorBase< T, Allocator >( alloc )
			{
				this->setBase( size_type( std::distance( first, last ) ) );
				this->iteratorInitialize( first, last );
				return ;
			}
			vector( vector const & other )\
			: VectorBase< T, Allocator >( other.size(), other.get_type_alloc_type() )
			{
				this->iteratorInitialize( other.m_alloc.m_start, \
										  other.m_alloc.m_finish );
				return ;
			}
			~vector( void )
			{
				this->clear();
				return ;
			}

			// assignment

			vector&				operator=( vector const & other )
			{
				if ( this != &other )
				{
					if ( other.size() > this->capacity() )
					{
						this->~vector();
						this->setBase( other.size() );
					}
					else
						this->clear();
					this->iteratorInitialize( other.begin(), other.end() );
				}
				return ( *this );
			}
			void				assign( size_type count, value_type const & value )
			{
				if ( count > this->capacity() )
				{
					this->~vector();
					this->setBase( count );
				}
				else
					this->clear();
				this->defaultInitialize( count, value );
				return ;
			}
			template< typename InputIterator >
			void				assign( InputIterator first, InputIterator last, 
										typename ft::enable_if< \
										!( ft::is_integral< InputIterator >::value ), \
										bool >::type* = NULL )
			{
				if ( size_type( std::distance( first, last ) ) > this->capacity() )
				{
					this->~vector();
					this->setBase( size_type( std::distance( first, last ) ) );
				}
				else
					this->clear();
				this->iteratorInitialize( first, last );
				return ;
			}

			// allocator

			allocator_type		get_allocator( void ) const
			{
				return ( allocator_type( this->get_type_alloc_type() ) );
			}

			// element access

			reference			at( size_type n )
			{
				if ( n >= this->size() )
				{
					char	buffer[1024];

					sprintf( buffer, "vector::_M_range_check: __n (which is %lu)"
									 " >= this->size() (which is %lu)", \
									 n, this->size() );
					throw std::out_of_range( buffer );
				}
				return ( ( *this )[ n ] );
			}
			const_reference		at( size_type n ) const
			{
				if ( n >= this->size() )
				{
					char	buffer[1024];

					sprintf( buffer, "vector::_M_range_check: __n (which is %lu)"
									 " >= this->size() (which is %lu)", \
									 n, this->size() );
					throw std::out_of_range( buffer );
				}
				return ( ( *this )[ n ] );
			}
			reference			operator[]( size_type n )
			{
				return ( *( this->m_alloc.m_start + n ) );
			}
			const_reference		operator[]( size_type n ) const
			{
				return ( *( this->m_alloc.m_start + n ) );
			}
			reference			front( void )
			{
				return ( *( this->begin() ) );
			}
			const_reference		front( void ) const
			{
				return ( *( this->begin() ) );
			}
			reference			back( void )
			{
				return ( *( this->end() - 1 ) );
			}
			const_reference		back( void ) const
			{
				return ( *( this->end() - 1 ) );
			}
			pointer				data( void )
			{
				return ( this->m_alloc.m_start );
			}
			const_pointer		data( void ) const
			{
				return ( this->m_alloc.m_start );
			}

			// iterators

			iterator				begin( void )
			{
				return ( iterator( this->m_alloc.m_start ) );
			}
			const_iterator			begin( void ) const
			{
				return ( const_iterator( this->m_alloc.m_start ) );
			}
			iterator				end( void )
			{
				return ( iterator( this->m_alloc.m_finish ) );
			}
			const_iterator			end( void ) const
			{
				return ( const_iterator( this->m_alloc.m_finish ) );
			}
			reverse_iterator		rbegin( void )
			{
				return ( reverse_iterator( this->end() ) );
			}
			const_reverse_iterator	rbegin( void ) const
			{
				return ( const_reverse_iterator( this->end() ) );
			}
			reverse_iterator		rend( void )
			{
				return ( reverse_iterator( this->begin() ) );
			}
			const_reverse_iterator	rend( void ) const
			{
				return ( const_reverse_iterator( this->begin() ) );
			}

			// capacity

			bool		empty( void ) const
			{
				return ( this->begin() == this->end() );
			}
			size_type	size( void ) const
			{
				return ( ( this->end() - this->begin() ) );
			}
			size_type	max_size( void ) const
			{
				return ( this->m_alloc.max_size() );
			}
			void		reserve( size_type new_cap )
			{
				if ( new_cap > this->max_size() )
					throw std::length_error( "vector::reserve" );
				else if ( new_cap > this->capacity() )
				{
					pointer		tmp_begin = this->m_alloc.m_start;
					pointer		tmp_end = this->m_alloc.m_finish;
					size_type	tmp_capacity = this->capacity();

					this->setBase( new_cap );
					this->iteratorInitialize( tmp_begin, tmp_end );
					this->m_alloc.m_end_of_storage = this->m_alloc.m_start + new_cap;
					this->vDeallocate( tmp_begin, tmp_capacity );
				}
				return ;
			}
			size_type	capacity( void ) const
			{
				return ( size_type( this->m_alloc.m_end_of_storage - \
									this->m_alloc.m_start ) );
			}

			// modifiers

			void		clear( void )
			{
				this->erase( this->begin(), this->end() );
				return ;
			}
			iterator	insert( iterator position, \
								value_type const & value )
			{
				difference_type	distance = ( position - this->begin() );
				size_type		new_storage = ( 2 * this->capacity() );

				if ( ( this->size() + 1 ) > this->capacity() )
				{
					if ( ( this->size() + 1 ) > new_storage )
						new_storage = ( this->size() + 1 );
					this->reserve( new_storage );
				}
				iterator	new_position = ( this->begin() + distance );

				++this->m_alloc.m_finish;
				for ( iterator	move = ( this->end() - 1 );\
					  move != new_position; --move )
				{
					*move = *( move - 1 );
				}
				this->m_alloc.construct( &( *( new_position) ), value );
				return ( new_position );
			}
			void		insert( iterator position, size_type count, \
								value_type const & value )
			{
				difference_type	distance = ( position - this->begin() );
				size_type		new_storage = ( 2 * this->capacity() );

				if ( count == 0 )
					return ;
				if ( ( this->size() + count ) > this->capacity() )
				{
					if ( ( this->size() + count ) > new_storage )
						new_storage = ( this->size() + count );
					this->reserve( new_storage );
				}
				iterator	new_position = ( this->begin() + distance );

				this->m_alloc.m_finish += count;
				for ( iterator	move = ( this->end() - 1 );\
					  ( move - count + 1 ) != new_position; --move )
				{
					*move = *( move - count );
				}
				for ( iterator	insert = new_position;\
					  insert != new_position + count; ++insert )
				{
					this->m_alloc.construct( &( *( insert ) ), value );
				}
				return ;
			}
			template< typename InputIterator >
			void		insert( iterator position, InputIterator first, \
								InputIterator last, \
								typename ft::enable_if< \
								!( ft::is_integral< InputIterator >::value ), \
								bool >::type* = NULL )
			{
				difference_type				distance = ( position - this->begin() );
				size_type					count = size_type( std::distance( first, last ) );
				size_type					new_storage = ( 2 * this->capacity() );

				if ( count == 0 )
					return ;
				if ( ( this->size() + count ) > this->capacity() )
				{
					if ( ( this->size() + count ) > new_storage )
						new_storage = ( this->size() + count );
					this->reserve( new_storage );
				}
				iterator	new_position = ( this->begin() + distance );
				iterator	insert = new_position;

				this->m_alloc.m_finish += count;
				for ( iterator	move = ( this->end() - 1 );\
					  ( move - count + 1 ) != new_position; --move )
				{
					*move = *( move - count );
				}
				while ( ( insert != ( new_position + count ) ) && \
						( first != last ) )
				{
					if ( &( *( first ) ) == &( *( new_position ) ) )
					{
						first += count;
						last += count;
					}
					this->m_alloc.construct( &( *( insert ) ), *first );
					++insert;
					++first;
				}
				return ;
			}
			iterator	erase( iterator position )
			{
				this->m_alloc.destroy( &( *( position ) ) );
				for ( iterator	move = position + 1;\
					  move != this->end(); ++move )
				{
					*( move - 1 ) = *move;
				}
				--this->m_alloc.m_finish;
				return ( position );
			}
			iterator	erase( iterator first, iterator last )
			{
				for ( iterator	remove = first; remove != last; ++remove )
					this->m_alloc.destroy( &( *( remove ) ) );
				for ( iterator	move = last; move != this->end(); ++move )
					*( move - ( last - first ) ) = *move;
				this->m_alloc.m_finish -= ( last - first );
				return ( last );
			}
			void		push_back( value_type const & value )
			{
				this->insert( this->end(), value );
				return ;
			}
			void		pop_back( void )
			{
				this->erase( this->end() - 1 );
				return ;
			}
			void		resize( size_type count, \
								value_type const & value = value_type() )
			{
				if ( count < this->size() )
					this->erase( ( this->begin() + count ), this->end() );
				else if ( count > this->size() )
					this->insert( ( this->end() ), \
								  ( count - this->size() ), value );
				return ;
			}
			void		swap( vector& other )
			{
				std::swap( this->m_alloc.m_start, other.m_alloc.m_start );
				std::swap( this->m_alloc.m_finish, other.m_alloc.m_finish );
				std::swap( this->m_alloc.m_end_of_storage, \
						   other.m_alloc.m_end_of_storage );
				return ;
			}

		protected:

			// initialize

			void	setBase( size_type n )
			{
				this->m_alloc.m_start = this->vAllocate( n );
				this->m_alloc.m_finish = this->m_alloc.m_start;
				this->m_alloc.m_end_of_storage = this->m_alloc.m_start + n;
				return ;
			}
			void	defaultInitialize( size_type n, value_type value )
			{
				std::uninitialized_fill_n( this->m_alloc.m_start, n, value );
				this->m_alloc.m_finish = this->m_alloc.m_start + n;
				return ;
			}
			template< typename Iterator >
			void	iteratorInitialize( Iterator first, Iterator last )
			{
				this->m_alloc.m_finish = \
					std::uninitialized_copy( first, last, this->m_alloc.m_start );
				return ;
			}

	};

	// compare

	template< typename T, typename Alloc >
	bool		operator==( vector< T, Alloc > const & lhs, \
							vector< T, Alloc > const & rhs )
	{
		return ( ( lhs.size() == rhs.size() ) && \
				 ft::equal( lhs.begin(), lhs.end(), rhs.begin() ) );
	}
	template< typename T, typename Alloc >
	bool		operator!=( vector< T, Alloc > const & lhs, \
							vector< T, Alloc > const & rhs )
	{
		return ( !( lhs == rhs ) );
	}
	template< typename T, typename Alloc >
	bool		operator<( vector< T, Alloc > const & lhs, \
						   vector< T, Alloc > const & rhs )
	{
		return ( ft::lexicographical_compare( lhs.begin(), lhs.end(), \
											  rhs.begin(), rhs.end() ) );
	}
	template< typename T, typename Alloc >
	bool		operator<=( vector< T, Alloc > const & lhs, \
							vector< T, Alloc > const & rhs )
	{
		return ( !( rhs < lhs ) );
	}
	template< typename T, typename Alloc >
	bool		operator>( vector< T, Alloc > const & lhs, \
						   vector< T, Alloc > const & rhs )
	{
		return ( ( rhs < lhs ) );
	}
		template< typename T, typename Alloc >
	bool		operator>=( vector< T, Alloc > const & lhs, \
							vector< T, Alloc > const & rhs )
	{
		return ( !( lhs < rhs ) );
	}

	//swap

	template< typename T, typename Alloc >
	void		swap( vector< T, Alloc >& lhs, \
					  vector< T, Alloc >& rhs )
	{
		lhs.swap( rhs );
		return ;
	}

}

#endif
