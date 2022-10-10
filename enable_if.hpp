/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:48:56 by nosterme          #+#    #+#             */
/*   Updated: 2022/10/10 18:25:59 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

namespace ft
{

	template< bool B, typename T = void >
	struct enable_if
	{
	};

	template< typename T >
	struct enable_if< true, T >
	{

		typedef T	type;

	};

}

#endif
