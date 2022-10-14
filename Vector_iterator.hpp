/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:49:39 by nosterme          #+#    #+#             */
/*   Updated: 2022/10/14 18:32:54 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

template< typename Val >
struct iterator
{

	public:

		typedef typename std::random_access_iterator_tag	iterator_category;
		typedef typename std::ptrdiff_t						difference_type;
		typedef T											value_type;
		typedef value_type*									pointer;
		typedef value_type&									reference;

		iterator( pointer ptr )\
		 : m_ptr( ptr )
		{
			return ;
		}
		iterator( iterator const & other )\
		 : m_ptr( other.m_ptr )
		{
			return ;
		}
		~iterator( void )
		{
			return ;
		}
		iterator&	operator=( iterator const & rhs )
		{
			this->m_ptr = rhs.m_ptr;
			return ( *this );
		}

		pointer		base( void ) const
		{
			return ( this->m_ptr );
		}

		reference	operator*( void ) const
		{
			return ( *( this->m_ptr ) );
		}
		pointer		operator->( void )
		{
			return ( this->m_ptr );
		}

		iterator&	operator++( void )
		{
			++( this->m_ptr );
			return ( *this );
		}
		iterator&	operator--( void )
		{
			--( this->m_ptr );
			return ( *this );
		}
		iterator	operator++( int )
		{
			iterator	tmp( *this );
			++( *this );
			return ( tmp );
		}
		iterator	operator--( int )
		{
			iterator	tmp( *this );
			--( *this );
			return ( tmp );
		}

		friend bool	operator==( iterator const & it1, \
								iterator const & it2 );
		friend bool	operator!=( iterator const & it1, \
								iterator const & it2 );

	protected:

		pointer	m_ptr;

};

template< typename Val >
bool	operator==( iterator< Val > const & it1, \
					iterator< Val > const & it2 )
{
	return ( it1.base() == it2.base() );
}

template< typename Val >
bool	operator!=( iterator< Val > const & it1, \
					iterator< Val > const & it2 )
{
	return ( !( it1.base() == it2.base() ) );
}

#endif
