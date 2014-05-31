/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 08:17:31 by lverniss          #+#    #+#             */
/*   Updated: 2013/12/22 18:45:47 by lverniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 				MY_H
# define 				MY_H

# include				<unistd.h>
# include 				<stdarg.h>
# include 				<stdlib.h>

# define DECI			"0123456789"
# define HEXA			"0123456789abcdef"

# define BSIZE			2096

/*
**						STD STRUCT FOR WORDS
*/

typedef struct	s_list	t_list;

struct					s_list
{
	char				str[BSIZE];
	ssize_t				len;
	t_list				*next;
};

/*
**						PTR Function for print
*/

typedef size_t			(*fprint)(const int fd, va_list arg);

/*
**						Count Function
*/

size_t					count_num(const ssize_t val);
size_t					ft_strlen(const char const *str);

/*
**						Print Fuction
*/

size_t					putnbr(const int fd, const size_t nb,
							const char const *base, size_t len);
size_t					putnbr_base(const int fd, ssize_t nb,
							const char const *base, int flag);
size_t					print_str(const int fd, va_list arg);
size_t					print_num(const int fd, va_list arg);
size_t					print_ptr(const int fd, va_list arg);

/*
**						OP PRINT
*/

ssize_t					print(const int fd, const char const *format, ...);

/*
**						Read ANY FD
*/

char					*mread(const int fd);

/*
**						GUARDIAN
*/
#endif
