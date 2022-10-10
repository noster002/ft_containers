/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:26:18 by nosterme          #+#    #+#             */
/*   Updated: 2022/10/10 18:49:33 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

template< typename T, T Val >
struct integral_constant
{

	typedef T							value_type;
	typedef integral_constant< T, Val >	type;

}

typedef struct integral_constant< bool, true >	true_type;
typedef struct integral_constant< bool, false >	false_type;

namespace ft
{



}

#endif
