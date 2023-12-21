/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:01:22 by mmaghri           #+#    #+#             */
/*   Updated: 2023/11/17 09:55:43 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <unistd.h>

void	callhex(unsigned long long nbr, int *len);
void	downX(unsigned int number, int *len);
void	turn(unsigned int number, char xX, int *len);
void	uuusi(unsigned int number, int *len);
int		lencount(char *string);
void	allthatshit(unsigned long int number, int *len);
void	putnbr(long long number, int *len);
void	putstring(char *string, int *len);
void	paste(const char str, int *len);
int		ft_printf(const char *string, ...);

#endif