/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mystruct.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 00:00:29 by nosterme          #+#    #+#             */
/*   Updated: 2022/10/27 15:42:16 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYSTRUCT_HPP
# define MYSTRUCT_HPP

struct	my_empty_struct {};

struct	my_pointer_struct
{
	void*			p;
};

struct	my_const_pointer_struct
{
	void const *	pc;
};

struct	my_bool_struct
{
	bool			b;
};

struct	my_char_struct
{
	char			c;
};

struct	my_int_struct
{
	int				i;
};

struct	my_double_struct
{
	double			d;
};

struct	my_struct_struct
{
	my_empty_struct			se;
	my_pointer_struct		sp;
	my_const_pointer_struct	spc;
	my_bool_struct			sb;
	my_char_struct			sc;
	my_int_struct			si;
	my_double_struct		sd;
};

struct	mystruct
{
	bool					b;
	char					c;
	wchar_t					cw;
	signed char				cs;
	unsigned char			cu;
	short					s;
	int						i;
	long					l;
	unsigned short			su;
	unsigned int			iu;
	unsigned long			lu;
	float					f;
	double					d;
	long double				ld;
	void*					p;
	void const *			pc;
	my_empty_struct			se;
	my_pointer_struct		sp;
	my_const_pointer_struct	spc;
	my_bool_struct			sb;
	my_char_struct			sc;
	my_int_struct			si;
	my_double_struct		sd;
	my_struct_struct		ss;
};

#endif
