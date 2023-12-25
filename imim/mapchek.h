/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchek.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:10:57 by mmaghri           #+#    #+#             */
/*   Updated: 2023/12/25 10:48:11 by mmaghri          ###   ########.fr       */
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
	int		row ;
	int		colum;
	int		res ;
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

void	printmapposition(char **string);
int		checkrows(char string, int *collectible, int *exit);
int		backtrack(char **string, int row, int colum);
int		player_row_position(char **string);
int		player_colum_position(char **string);
int		weirddetection(char string);
int		maplenghtcheck(char **string);
int		checkthelenghtline(char **array);
int		checksidesofmap(char **string);
int		checkvalidity(int player, int collec, int out);
int		chekingarraybyone(char *string);
int		chekthewalsinmap(char **string);
int		lencount(char *string);
char	**stringreturn(char *string);
int		checkvalidmap(char *string);
char	*functionfilereader(int fd);
int		checkhowmany(char *string);

#endif