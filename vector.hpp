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
# include "Vector_iterator.hpp"
# include "reverse_iterator.hpp"
# include "iterator_traits.hpp"
# include <limits>

namespace ft
{

	template< typename T, typename Allocator = std::allocator< T > >
	class vector : protected VectorBase< T, Allocator >
	{

		public:

		typedef T															value_type;
		typedef Allocator													allocator_type;
		typedef typename allocator_type::reference							reference;
		typedef typename allocator_type::const_reference					const_reference;
		typedef typename allocator_type::pointer							pointer;
		typedef typename allocator_type::const_pointer						const_pointer;
		typedef struct iterator< T >										iterator;
		typedef struct iterator< T const >									const_iterator;
		typedef typename ft::reverse_iterator< iterator >					reverse_iterator;
		typedef typename ft::reverse_iterator< const_iterator >				const_reverse_iterator;
		typedef typename ft::iterator_traits< iterator >::difference_type	difference_type;
		typedef typename std::size_t										size_type;

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
			defaultInitialize( count, value );
			return ;
		}
		template< typename InputIterator >
		vector( InputIterator first, InputIterator last, \
				allocator_type const & alloc = allocator_type() )\
		 : VectorBase< T, Allocator >( alloc )
		{
			if ( std::numeric_limits< InputIterator >::is_integer )
				integralInitialize( static_cast< typename ft::vector< T, Allocator >::size_type >( first ), \
									static_cast< typename ft::vector< T, Allocator >::value_type >( last ) );
			else
				iteratorPreInitialize( static_cast< typename ft::vector< T, Allocator >::iterator >( first ), \
									static_cast< typename ft::vector< T, Allocator >::iterator >( last ) );
			return ;
		}
		vector( vector const & other )\
		 : VectorBase< T, Allocator >( other.size(), other.get_allocator() )
		{
			iteratorInitialize( other.m_init.m_start, other.m_init.m_finish );
			return ;
		}
		~vector( void )
		{
			return ;
		}

		allocator_type	get_allocator( void ) const
		{
			return ( *static_cast< Allocator const * >( &this->m_init ) );
		}

		size_type	size( void ) const
		{
			return ( std::distance( this->m_init.m_start, this->m_init.m_finish ) );
		}

		iterator	begin( void )
		{
			return ( iterator( this->m_init.m_start ) );
		}
		iterator	end( void )
		{
			return ( iterator( this->m_init.m_finish ) );
		}

		protected:

		void	setBase( size_type n )
		{
			this->m_init.m_start = this->vAllocate( n );
			this->m_init.m_finish = this->m_init.m_start;
			this->m_init.m_end_of_storage = this->m_init.m_start + n;
			return ;
		}

		void	integralInitialize( size_type n, value_type value )
		{
			setBase( n );
			defaultInitialize( n, value );
			return ;
		}
		void	defaultInitialize( size_type n, value_type value )
		{
			std::uninitialized_fill_n( this->m_init.m_start, n, value );
			this->m_init.m_finish = this->m_init.m_end_of_storage;
			return ;
		}

		template< typename InputIterator >
		void	iteratorPreInitialize( InputIterator first, InputIterator last )
		{
			setBase( last - first );
			iteratorInitialize( first, last );
			return ;
		}
		template< typename InputIterator >
		void	iteratorInitialize( InputIterator first, InputIterator last )
		{
			this->m_init.m_finish = \
				std::uninitialized_copy( first, last, this->m_init.m_start );
			return ;
		}

	};

}

#endif
