/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorBase.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 00:13:52 by nosterme          #+#    #+#             */
/*   Updated: 2022/10/17 19:08:29 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORBASE_HPP
# define VECTORBASE_HPP
# include <memory>

template< typename T, typename Allocator >
class VectorBase
{

	public:

		typedef typename std::size_t	size_type;

		struct VectorInitialize : public Allocator
		{

			typename Allocator::pointer	m_start;
			typename Allocator::pointer	m_finish;
			typename Allocator::pointer	m_end_of_storage;

			VectorInitialize( void )\
			 : Allocator(), m_start( 0 ), m_finish( 0 ), m_end_of_storage( 0 )
			{
				return ;
			}
			VectorInitialize( Allocator const & alloc )\
			 : Allocator( alloc ), m_start( 0 ), m_finish( 0 ), m_end_of_storage( 0 )
			{
				return ;
			}

		};

		VectorInitialize	m_init;

		VectorBase( void )\
		 : m_init()
		{
			return ;
		}
		VectorBase( Allocator const & alloc )\
		 : m_init( alloc )
		{
			return ;
		}
		VectorBase( size_type n )\
		 : m_init()
		{
			this->m_init.m_start = this->vAllocate( n );
			this->m_init.m_finish = this->m_init.m_start;
			this->m_init.m_end_of_storage = this->m_init.m_start + n;
			return ;
		}
		VectorBase( size_type n, Allocator const & alloc )\
		 : m_init( alloc )
		{
			this->m_init.m_start = this->vAllocate( n );
			this->m_init.m_finish = this->m_init.m_start;
			this->m_init.m_end_of_storage = this->m_init.m_start + n;
			return ;
		}
		~VectorBase( void )
		{
			this->vDeallocate( this->m_init.m_start,\
			 std::distance( this->m_init.m_start, this->m_init.m_end_of_storage ) );
			return ;
		}

		typename Allocator::pointer	vAllocate( size_type n )
		{
			return ( n != 0 ? this->m_init.allocate( n ) : 0 );
		}
		void	vDeallocate( typename Allocator::pointer ptr, size_type n )
		{
			if ( ptr )
				this->m_init.deallocate( ptr, n );
			return ;
		}

};

#endif
