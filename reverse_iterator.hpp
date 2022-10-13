/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:28:38 by nosterme          #+#    #+#             */
/*   Updated: 2022/10/13 17:50:12 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

namespace ft
{

	template< typename Iterator >
	class reverse_iterator
	{

		public:

		typedef Iterator													iterator_type;
		typedef typename ft::iterator_traits< Iterator >::iterator_category	iterator_category;
		typedef typename ft::iterator_traits< Iterator >::value_type		value_type;
		typedef typename ft::iterator_traits< Iterator >::difference_type	difference_type;
		typedef typename ft::iterator_traits< Iterator >::pointer			pointer;
		typedef typename ft::iterator_traits< Iterator >::reference			reference;

		reverse_iterator( void ) : current( 0 )
		{
			return ;
		}
		explicit reverse_iterator( iterator_type x ) : current( x )
		{
			return ;
		}
		template< typename U >
		reverse_iterator( reverse_iterator< U > const & other ) : current( other.current )
		{
			return ;
		}
		template< typename U >
		reverse_iterator&	operator=( reverse_iterator< U > const & other )
		{
			this->current = other.base();
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
			reverse_iterator	tmp = *this;
			--this->current;
			return ( tmp );
		}
		reverse_iterator	operator--( int )
		{
			reverse_iterator	tmp = *this;
			++this->current;
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

		protected:

		iterator_type	current;

		private:

	};

}

#endif
