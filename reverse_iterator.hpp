/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:28:38 by nosterme          #+#    #+#             */
/*   Updated: 2022/10/18 14:06:29 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP
# include "iterator_traits.hpp"

namespace ft
{

	template< typename Iterator >
	class reverse_iterator
	{

		protected:

		Iterator	current;

		public:

		typedef Iterator													iterator_type;
		typedef typename ft::iterator_traits< Iterator >::iterator_category	iterator_category;
		typedef typename ft::iterator_traits< Iterator >::value_type		value_type;
		typedef typename ft::iterator_traits< Iterator >::difference_type	difference_type;
		typedef typename ft::iterator_traits< Iterator >::pointer			pointer;
		typedef typename ft::iterator_traits< Iterator >::reference			reference;

		reverse_iterator( void ) : current()
		{
			return ;
		}
		explicit reverse_iterator( iterator_type x ) : current( x )
		{
			return ;
		}
		template< typename U >
		reverse_iterator( reverse_iterator< U > const & other )\
		 : current( other.base() )
		{
			return ;
		}
		template< typename U >
		reverse_iterator&	operator=( reverse_iterator< U > const & rhs )
		{
			this->current = rhs.base();
			return ( *this );
		}

		iterator_type	base( void ) const
		{
			return ( this->current );
		}

		reference	operator*( void ) const
		{
			iterator_type	tmp = this->current;
			return ( *( --tmp ) );
		}
		pointer		operator->( void ) const
		{
			return ( &( this->operator*() ) );
		}
		reference	operator[]( difference_type n ) const
		{
			return ( this->base()[ -n - 1 ] );
		}

		reverse_iterator&	operator++( void )
		{
			--this->current;
			return ( *this );
		}
		reverse_iterator&	operator--( void )
		{
			++this->current;
			return ( *this );
		}
		reverse_iterator	operator++( int )
		{
			reverse_iterator	tmp( *this );
			++( *this );
			return ( tmp );
		}
		reverse_iterator	operator--( int )
		{
			reverse_iterator	tmp( *this );
			--( *this );
			return ( tmp );
		}
		reverse_iterator	operator+( difference_type n ) const
		{
			return ( reverse_iterator( base() - n ) );
		}
		reverse_iterator	operator-( difference_type n ) const
		{
			return ( reverse_iterator( base() + n ) );
		}
		reverse_iterator&	operator+=( difference_type n )
		{
			this->current -= n;
			return ( *this );
		}
		reverse_iterator&	operator-=( difference_type n )
		{
			this->current += n;
			return ( *this );
		}

	};

	template< typename Iterator1, typename Iterator2 >
	bool	operator==( reverse_iterator< Iterator1 > const & lhs, \
						reverse_iterator< Iterator2 > const & rhs )
	{
		return ( lhs.base() == rhs.base() );
	}
	template< typename Iterator1, typename Iterator2 >
	bool	operator!=( reverse_iterator< Iterator1 > const & lhs, \
						reverse_iterator< Iterator2 > const & rhs )
	{
		return ( lhs.base() != rhs.base() );
	}
	template< typename Iterator1, typename Iterator2 >
	bool	operator<( reverse_iterator< Iterator1 > const & lhs, \
					   reverse_iterator< Iterator2 > const & rhs )
	{
		return ( lhs.base() > rhs.base() );
	}
	template< typename Iterator1, typename Iterator2 >
	bool	operator<=( reverse_iterator< Iterator1 > const & lhs, \
						reverse_iterator< Iterator2 > const & rhs )
	{
		return ( lhs.base() >= rhs.base() );
	}
	template< typename Iterator1, typename Iterator2 >
	bool	operator>( reverse_iterator< Iterator1 > const & lhs, \
					   reverse_iterator< Iterator2 > const & rhs )
	{
		return ( lhs.base() < rhs.base() );
	}
	template< typename Iterator1, typename Iterator2 >
	bool	operator>=( reverse_iterator< Iterator1 > const & lhs, \
						reverse_iterator< Iterator2 > const & rhs )
	{
		return ( lhs.base() <= rhs.base() );
	}

	template< typename Iterator >
	reverse_iterator< Iterator >\
		operator+( typename reverse_iterator< Iterator >::difference_type n, \
				   reverse_iterator< Iterator > const & rev_it )
	{
		return ( reverse_iterator< Iterator >( rev_it.base() - n ) );
	}
	template< typename Iterator >
	typename reverse_iterator< Iterator >::difference_type\
		operator-( reverse_iterator< Iterator > const & lhs, \
				   reverse_iterator< Iterator > const & rhs )
	{
		return ( rhs.base() - lhs.base() );
	}

}

#endif
