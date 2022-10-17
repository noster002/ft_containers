/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:49:39 by nosterme          #+#    #+#             */
/*   Updated: 2022/10/17 19:51:32 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP
# include "iterator_traits.hpp"
# include "is_integral.hpp"

template< typename Iterator, typename Container >
struct iterator
{

	protected:

		Iterator	m_current;

	public:

		typedef typename ft::iterator_traits< Iterator >::difference_type\
			difference_type;
		typedef typename ft::iterator_traits< Iterator >::value_type\
			value_type;
		typedef typename ft::iterator_traits< Iterator >::pointer\
			pointer;
		typedef typename ft::iterator_traits< Iterator >::reference\
			reference;
		typedef typename ft::iterator_traits< Iterator >::iterator_category\
			iterator_category;

		iterator( void )\
		 : m_current( Iterator() )
		{
			return ;
		}
		explicit iterator( Iterator const & it )\
		 : m_current( it )
		{
			return ;
		}
		template< typename Iter >
		iterator( iterator< Iter, \
			typename ft::enable_if< \
			( is_same< Iter, typename Container::pointer >::value ), \
			Container>::type> const & it )\
		 : m_current( i.base() )
		{
			return ;
		}
		~iterator( void )
		{
			return ;
		}
		iterator< value_type >&	operator=( iterator< value_type > const & rhs )
		{
			this->m_current = rhs.m_current;
			return ( *this );
		}

		pointer		base( void ) const
		{
			return ( this->m_current );
		}

		reference	operator*( void ) const
		{
			return ( *( this->m_current ) );
		}
		pointer		operator->( void )
		{
			return ( this->m_current );
		}

		iterator&	operator++( void )
		{
			++( this->m_current );
			return ( *this );
		}
		iterator&	operator--( void )
		{
			--( this->m_current );
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

	private:

		template< typename T, typename U >
		struct is_same : public false_type {};

		template< typename T >
		struct is_same< T, T > : public true_type{};

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
