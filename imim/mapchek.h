/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchek.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:10:57 by mmaghri           #+#    #+#             */
/*   Updated: 2023/12/23 12:57:10 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPCHEK_H
# define MAPCHEK_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "mapchek.h"
# include <fcntl.h>

typedef struct mapvlidity
{
	int		filed;
	int		i;
	char	**twode;
	int		checkpoint ;
	char	*allocation ;
	int		flag ;
	int		checker ;
	int		index ;
	int		player ;
	int		collectiles ;
	int		runout ;
	int		numberofclomums ;
	int		linelenght ;
	int		checkinglinevalidity ;
	int		totallenghtline ;
}	t_map;

int		lencount(char *string);
char	**stringreturn(char *string);
int		checkvalidmap(char *string);
char	*functionfilereader(int fd);
int		checkwithealllines(char *string, int linetotal);
int		checkhowmany(char *string);

#endif