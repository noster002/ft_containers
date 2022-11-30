/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:37:05 by nosterme          #+#    #+#             */
/*   Updated: 2022/09/09 20:37:05 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP
# include "vector.hpp"

namespace ft
{

	template< typename T, typename Container >
	class stack;

	template< typename T, typename Container >
	bool	operator==( stack< T, Container > const & lhs, \
						stack< T, Container > const & rhs );
	template< typename T, typename Container >
	bool	operator<( stack< T, Container > const & lhs,\
					   stack< T, Container > const & rhs );


	template< typename T, typename Container = ft::vector< T > >
	class stack
	{

		public:

			typedef Container									container_type;
			typedef typename container_type::value_type			value_type;
			typedef typename container_type::size_type			size_type;
			typedef typename container_type::reference			reference;
			typedef typename container_type::const_reference	const_reference;

		protected:

			container_type	c;

		public:

			explicit stack( container_type const & cont = container_type() ) : c( cont )
			{
				return ;
			}
			stack( stack const & other ) : c( other.c )
			{
				return ;
			}
			~stack( void )
			{
				return ;
			}

			reference			top( void )
			{
				return ( c.back() );
			}
			const_reference		top( void ) const
			{
				return ( c.back() );
			}

			bool				empty( void ) const
			{
				return ( c.empty() );
			}
			size_type			size( void ) const
			{
				return ( c.size() );
			}

			void				push( value_type const & value )
			{
				c.push_back( value );
				return ;
			}
			void				pop( void )
			{
				c.pop_back();
				return ;
			}

		private:

			friend bool	operator== <>( stack< T, Container > const & lhs,\
									   stack< T, Container > const & rhs );
			friend bool	operator< <>( stack< T, Container > const & lhs,\
									  stack< T, Container > const & rhs );

	};

	template< typename T, typename Container >
	bool	operator==( stack< T, Container > const & lhs, \
						stack< T, Container > const & rhs )
	{
		return ( lhs.c == rhs.c );
	}
	template< typename T, typename Container >
	bool	operator!=( stack< T, Container > const & lhs, \
						stack< T, Container > const & rhs )
	{
		return ( !( lhs == rhs ) );
	}
	template< typename T, typename Container >
	bool	operator<( stack< T, Container > const & lhs,\
					   stack< T, Container > const & rhs )
	{
		return ( lhs.c < rhs.c );
	}
	template< typename T, typename Container >
	bool	operator<=( stack< T, Container > const & lhs, \
						stack< T, Container > const & rhs )
	{
		return ( !( rhs < lhs ) );
	}
	template< typename T, typename Container >
	bool	operator>( stack< T, Container > const & lhs,\
					   stack< T, Container > const & rhs )
	{
		return ( rhs < lhs );
	}
	template< typename T, typename Container >
	bool	operator>=( stack< T, Container > const & lhs, \
						stack< T, Container > const & rhs )
	{
		return ( !( lhs < rhs ) );
	}

}

#endif
