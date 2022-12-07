/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myallocator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 23:58:15 by nosterme          #+#    #+#             */
/*   Updated: 2022/12/06 19:58:27 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYALLOCATOR_HPP
# define MYALLOCATOR_HPP
# include <cstdlib>
# include <new>
# include <limits>

template< typename T >
struct	myallocator
{

	typedef T						value_type;
	typedef value_type*				pointer;
	typedef value_type const *		const_pointer;
	typedef value_type&				reference;
	typedef value_type const &		const_reference;
	typedef typename std::size_t	size_type;
	typedef typename std::ptrdiff_t	difference_type;
	template< typename U >
	struct rebind
	{
		typedef myallocator< U >	other;
	};

	myallocator( void ) {}
	template< typename U >
	myallocator( myallocator< U > const & ) {}

	pointer			allocate( size_type n )
	{
		pointer	p = static_cast< pointer >( std::malloc( n * sizeof( T ) ) );
		if ( p )
			return ( p );
		throw std::bad_alloc();
	}
	void		deallocate( pointer p, size_type )
	{
		std::free( p );
		return ;
	}
	size_type	max_size( void ) const throw()
	{
		return ( ( std::numeric_limits< difference_type >::max() / \
				   sizeof( value_type ) ) );
	}
	void		construct( pointer p, const_reference val )
	{
		new( static_cast< void* >( p ) ) value_type( val );
		return ;
	}
	void		destroy( pointer p )
	{
		p->~value_type();
		return ;
	}

	bool		is_myallocator( void )
	{
		return ( true );
	}

};

template< typename T, typename U >
bool	operator==( myallocator< T > const &, \
					myallocator< U > const & ) throw()
{
	return ( true );
}
template< typename T, typename U >
bool	operator!=( myallocator< T > const &, \
					myallocator< U > const & ) throw()
{
	return ( false );
}


#endif
