/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:49:39 by nosterme          #+#    #+#             */
/*   Updated: 2022/10/18 14:54:32 by nosterme         ###   ########.fr       */
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

		// naming policy

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

		// constructors, destructor, assignment

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
			typename ft::enable_if< ( is_same< Iter, typename Container::pointer >::value ), Container>::type> const & it )\
		 : m_current( it.base() )
		{
			return ;
		}
		~iterator( void )
		{
			return ;
		}
		iterator&	operator=( iterator const & rhs )
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

		// random access

		iterator&	operator+=( difference_type const & n )
		{
			this->m_current += n;
			return ( *this );
		}
		iterator&	operator-=( difference_type const & n )
		{
			this->m_current -= n;
			return ( *this );
		}
		iterator	operator+( difference_type const & n ) const
		{
			return ( iterator( this->m_current + n ) );
		}
		iterator	operator-( difference_type const & n ) const
		{
			return ( iterator( this->m_current - n ) );
		}
		reference	operator[]( difference_type const & n ) const
		{
			return ( this->m_current[n] );
		}

	private:

		template< typename T, typename U >
		struct is_same : public false_type {};

		template< typename T >
		struct is_same< T, T > : public true_type{};

};

// compare

template< typename IteratorL, typename IteratorR, typename Container >
inline bool	operator==( iterator< IteratorL, Container > const & lhs, \
						iterator< IteratorR, Container > const & rhs )
{
	return ( lhs.base() == rhs.base() );
}
template< typename Iterator, typename Container >
inline bool	operator==( iterator< Iterator, Container > const & lhs, \
						iterator< Iterator, Container > const & rhs )
{
	return ( lhs.base() == rhs.base() );
}
template< typename IteratorL, typename IteratorR, typename Container >
inline bool	operator!=( iterator< IteratorL, Container > const & lhs, \
						iterator< IteratorR, Container > const & rhs )
{
	return ( lhs.base() != rhs.base() );
}
template< typename Iterator, typename Container >
inline bool	operator!=( iterator< Iterator, Container > const & lhs, \
						iterator< Iterator, Container > const & rhs )
{
	return ( lhs.base() != rhs.base() );
}

template< typename IteratorL, typename IteratorR, typename Container >
inline bool	operator<( iterator< IteratorL, Container > const & lhs, \
					   iterator< IteratorR, Container > const & rhs )
{
	return ( lhs.base() < rhs.base() );
}
template< typename Iterator, typename Container >
inline bool	operator<( iterator< Iterator, Container > const & lhs, \
					   iterator< Iterator, Container > const & rhs )
{
	return ( lhs.base() < rhs.base() );
}
template< typename IteratorL, typename IteratorR, typename Container >
inline bool	operator>( iterator< IteratorL, Container > const & lhs, \
					   iterator< IteratorR, Container > const & rhs )
{
	return ( lhs.base() > rhs.base() );
}
template< typename Iterator, typename Container >
inline bool	operator>( iterator< Iterator, Container > const & lhs, \
					   iterator< Iterator, Container > const & rhs )
{
	return ( lhs.base() > rhs.base() );
}
template< typename IteratorL, typename IteratorR, typename Container >
inline bool	operator<=( iterator< IteratorL, Container > const & lhs, \
						iterator< IteratorR, Container > const & rhs )
{
	return ( lhs.base() <= rhs.base() );
}
template< typename Iterator, typename Container >
inline bool	operator<=( iterator< Iterator, Container > const & lhs, \
						iterator< Iterator, Container > const & rhs )
{
	return ( lhs.base() <= rhs.base() );
}
template< typename IteratorL, typename IteratorR, typename Container >
inline bool	operator>=( iterator< IteratorL, Container > const & lhs, \
						iterator< IteratorR, Container > const & rhs )
{
	return ( lhs.base() >= rhs.base() );
}
template< typename Iterator, typename Container >
inline bool	operator>=( iterator< Iterator, Container > const & lhs, \
						iterator< Iterator, Container > const & rhs )
{
	return ( lhs.base() >= rhs.base() );
}

// difference

template< typename IteratorL, typename IteratorR, typename Container >
inline typename iterator< IteratorL, Container >::difference_type\
	operator-( iterator< IteratorL, Container > const & lhs, \
			   iterator< IteratorR, Container > const & rhs )
{
	return ( lhs.base() - rhs.base() );
}
template< typename Iterator, typename Container >
inline typename iterator< Iterator, Container >::difference_type\
	operator-( iterator< Iterator, Container > const & lhs, \
			   iterator< Iterator, Container > const & rhs )
{
	return ( lhs.base() - rhs.base() );
}

// rvalue operation

template< typename Iterator, typename Container >
inline iterator< Iterator, Container >\
	operator+( typename iterator< Iterator, Container >\
					::difference_type const & n, \
			   iterator< Iterator, Container > const & it )
{
	return ( iterator< Iterator, Container >( it.base() + n ) );
}

#endif
