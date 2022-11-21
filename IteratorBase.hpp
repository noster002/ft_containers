/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IteratorBase.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:05:00 by nosterme          #+#    #+#             */
/*   Updated: 2022/11/16 20:40:16 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORBASE_HPP
# define ITERATORBASE_HPP
# include "iterator_traits.hpp"
# include "is_integral.hpp"
# include "enable_if.hpp"
# include <iostream>

template< typename Iterator, typename Container >
struct IteratorBase
{

	protected:

		Iterator	m_current;

	public:

		// naming policy

		typedef typename ft::iterator_traits< Iterator >::difference_type	difference_type;
		typedef typename ft::iterator_traits< Iterator >::value_type		value_type;
		typedef typename ft::iterator_traits< Iterator >::pointer			pointer;
		typedef typename ft::iterator_traits< Iterator >::reference			reference;
		typedef typename ft::iterator_traits< Iterator >::iterator_category	iterator_category;

		// constructors, destructor, assignment

		IteratorBase( void )\
		 : m_current( Iterator() )
		{
			return ;
		}
		explicit IteratorBase( Iterator const & it )\
		 : m_current( it )
		{
			return ;
		}
		template< typename Iter >
		IteratorBase( IteratorBase< Iter, typename ft::enable_if< \
					  ( is_same< Iter, typename Container::pointer >::value ), \
					  Container >::type > const & it )\
		 : m_current( it.base() )
		{
			return ;
		}
		~IteratorBase( void )
		{
			return ;
		}
		IteratorBase&	operator=( IteratorBase const & rhs )
		{
			this->m_current = rhs.m_current;
			return ( *this );
		}

		// accessor

		pointer		base( void ) const
		{
			return ( this->m_current );
		}

		// derefencable

		reference	operator*( void ) const
		{
			return ( *( this->m_current ) );
		}
		pointer		operator->( void ) const
		{
			return ( this->m_current );
		}

		// increment & decrement

		IteratorBase&	operator++( void )
		{
			++( this->m_current );
			return ( *this );
		}
		IteratorBase&	operator--( void )
		{
			--( this->m_current );
			return ( *this );
		}
		IteratorBase	operator++( int )
		{
			IteratorBase	tmp( *this );
			++( *this );
			return ( tmp );
		}
		IteratorBase	operator--( int )
		{
			IteratorBase	tmp( *this );
			--( *this );
			return ( tmp );
		}

		// random access

		IteratorBase&	operator+=( difference_type const & n )
		{
			this->m_current += n;
			return ( *this );
		}
		IteratorBase&	operator-=( difference_type const & n )
		{
			this->m_current -= n;
			return ( *this );
		}
		IteratorBase	operator+( difference_type const & n ) const
		{
			return ( IteratorBase( this->m_current + n ) );
		}
		IteratorBase	operator-( difference_type const & n ) const
		{
			return ( IteratorBase( this->m_current - n ) );
		}
		reference		operator[]( difference_type const & n ) const
		{
			return ( this->m_current[n] );
		}

};

// compare

template< typename IteratorL, typename IteratorR, typename Container >
bool		operator==( IteratorBase< IteratorL, Container > const & lhs, \
						IteratorBase< IteratorR, Container > const & rhs )
{
	return ( lhs.base() == rhs.base() );
}
template< typename Iterator, typename Container >
bool		operator==( IteratorBase< Iterator, Container > const & lhs, \
						IteratorBase< Iterator, Container > const & rhs )
{
	return ( lhs.base() == rhs.base() );
}
template< typename IteratorL, typename IteratorR, typename Container >
bool		operator!=( IteratorBase< IteratorL, Container > const & lhs, \
						IteratorBase< IteratorR, Container > const & rhs )
{
	return ( lhs.base() != rhs.base() );
}
template< typename Iterator, typename Container >
bool		operator!=( IteratorBase< Iterator, Container > const & lhs, \
						IteratorBase< Iterator, Container > const & rhs )
{
	return ( lhs.base() != rhs.base() );
}

template< typename IteratorL, typename IteratorR, typename Container >
bool		operator<( IteratorBase< IteratorL, Container > const & lhs, \
					   IteratorBase< IteratorR, Container > const & rhs )
{
	return ( lhs.base() < rhs.base() );
}
template< typename Iterator, typename Container >
bool		operator<( IteratorBase< Iterator, Container > const & lhs, \
					   IteratorBase< Iterator, Container > const & rhs )
{
	return ( lhs.base() < rhs.base() );
}
template< typename IteratorL, typename IteratorR, typename Container >
bool		operator>( IteratorBase< IteratorL, Container > const & lhs, \
					   IteratorBase< IteratorR, Container > const & rhs )
{
	return ( lhs.base() > rhs.base() );
}
template< typename Iterator, typename Container >
bool		operator>( IteratorBase< Iterator, Container > const & lhs, \
					   IteratorBase< Iterator, Container > const & rhs )
{
	return ( lhs.base() > rhs.base() );
}
template< typename IteratorL, typename IteratorR, typename Container >
bool		operator<=( IteratorBase< IteratorL, Container > const & lhs, \
						IteratorBase< IteratorR, Container > const & rhs )
{
	return ( lhs.base() <= rhs.base() );
}
template< typename Iterator, typename Container >
bool		operator<=( IteratorBase< Iterator, Container > const & lhs, \
						IteratorBase< Iterator, Container > const & rhs )
{
	return ( lhs.base() <= rhs.base() );
}
template< typename IteratorL, typename IteratorR, typename Container >
bool		operator>=( IteratorBase< IteratorL, Container > const & lhs, \
						IteratorBase< IteratorR, Container > const & rhs )
{
	return ( lhs.base() >= rhs.base() );
}
template< typename Iterator, typename Container >
bool		operator>=( IteratorBase< Iterator, Container > const & lhs, \
						IteratorBase< Iterator, Container > const & rhs )
{
	return ( lhs.base() >= rhs.base() );
}

// difference

template< typename IteratorL, typename IteratorR, typename Container >
typename IteratorBase< IteratorL, Container >::difference_type\
	operator-( IteratorBase< IteratorL, Container > const & lhs, \
			   IteratorBase< IteratorR, Container > const & rhs )
{
	return ( lhs.base() - rhs.base() );
}
template< typename Iterator, typename Container >
typename IteratorBase< Iterator, Container >::difference_type\
	operator-( IteratorBase< Iterator, Container > const & lhs, \
			   IteratorBase< Iterator, Container > const & rhs )
{
	return ( lhs.base() - rhs.base() );
}

// rvalue operation

template< typename Iterator, typename Container >
IteratorBase< Iterator, Container >\
	operator+( typename IteratorBase< Iterator, Container >\
					::difference_type const & n, \
			   IteratorBase< Iterator, Container > const & it )
{
	return ( IteratorBase< Iterator, Container >( it.base() + n ) );
}

#endif
