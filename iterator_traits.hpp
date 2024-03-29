/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:11:47 by nosterme          #+#    #+#             */
/*   Updated: 2022/10/12 16:38:46 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP
# include <cstddef>
# include <iterator>

namespace ft
{

	template< typename Iterator >
	struct iterator_traits
	{

		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;

	};

	template< typename T >
	struct iterator_traits< T* >
	{

		typedef typename std::ptrdiff_t						difference_type;
		typedef T											value_type;
		typedef T*											pointer;
		typedef T&											reference;
		typedef typename std::random_access_iterator_tag	iterator_category;

	};

	template< typename T >
	struct iterator_traits< T const * >
	{

		typedef typename std::ptrdiff_t						difference_type;
		typedef T											value_type;
		typedef T const *									pointer;
		typedef T const &									reference;
		typedef typename std::random_access_iterator_tag	iterator_category;

	};

}

#endif
