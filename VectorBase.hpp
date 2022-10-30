/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorBase.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 00:13:52 by nosterme          #+#    #+#             */
/*   Updated: 2022/10/26 16:13:29 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORBASE_HPP
# define VECTORBASE_HPP
# include <memory>

template< typename T, typename Allocator >
class VectorBase
{

	public:

		typedef typename std::size_t							size_type;
		typedef typename Allocator::template rebind< T >::other	type_alloc_type;
		typedef Allocator										alloc_type;

		struct VectorAllocator : public type_alloc_type
		{

			typename type_alloc_type::pointer	m_start;
			typename type_alloc_type::pointer	m_finish;
			typename type_alloc_type::pointer	m_end_of_storage;

			VectorAllocator( void )\
			 : type_alloc_type(), m_start( 0 ), m_finish( 0 ), \
			   m_end_of_storage( 0 )
			{
				return ;
			}
			VectorAllocator( type_alloc_type const & alloc )\
			 : type_alloc_type( alloc ), m_start( 0 ), \
			   m_finish( 0 ), m_end_of_storage( 0 )
			{
				return ;
			}

		};

		VectorAllocator	m_alloc;

		VectorBase( void )\
		 : m_alloc()
		{
			return ;
		}
		VectorBase( type_alloc_type const & alloc )\
		 : m_alloc( alloc )
		{
			return ;
		}
		VectorBase( size_type n )\
		 : m_alloc()
		{
			this->m_alloc.m_start = this->vAllocate( n );
			this->m_alloc.m_finish = this->m_alloc.m_start;
			this->m_alloc.m_end_of_storage = this->m_alloc.m_start + n;
			return ;
		}
		VectorBase( size_type n, type_alloc_type const & alloc )\
		 : m_alloc( alloc )
		{
			this->m_alloc.m_start = this->vAllocate( n );
			this->m_alloc.m_finish = this->m_alloc.m_start;
			this->m_alloc.m_end_of_storage = this->m_alloc.m_start + n;
			return ;
		}
		~VectorBase( void )
		{
			this->vDeallocate( this->m_alloc.m_start,\
							   ( this->m_alloc.m_end_of_storage - \
							   this->m_alloc.m_start ) );
			return ;
		}

		type_alloc_type&			get_type_alloc_type( void )
		{
			return ( this->m_alloc );
		}
		type_alloc_type const &		get_type_alloc_type( void ) const
		{
			return ( this->m_alloc );
		}

		typename type_alloc_type::pointer	vAllocate( size_type n )
		{
			return ( n != 0 ? this->m_alloc.allocate( n ) : 0 );
		}
		void	vDeallocate( typename type_alloc_type::pointer ptr, size_type n )
		{
			if ( ptr )
				this->m_alloc.deallocate( ptr, n );
			return ;
		}

};

#endif
