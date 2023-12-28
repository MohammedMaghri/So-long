/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchek.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:10:57 by mmaghri           #+#    #+#             */
/*   Updated: 2023/12/28 22:52:05 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPCHEK_H
# define MAPCHEK_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "mapchek.h"
# include <fcntl.h>
# include <mlx.h>
# include "mlx.h"

typedef struct thefunctions
{
	int		index;
	int		increment;
	void	*forwindow;
	void	*forinit;
	char	*pic;
	void	*picpoiA;
	void	*picB;
	void	*picC;
	int		x;
	int		y;
	int		xx;
	int		yy;
	char	**twod;
	char	**tocopy;
}	t_fac;


typedef struct mapvlidity
{
	char	**tocpy;
	char	*coll;
	char	*wallptr;
	char	*ground;
	int		xx;
	int		yy;
	void	*windowptr;
	char	*imageptr;
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
	void	*ptrmlx;
}	t_map;

typedef struct 	moveit
{
	char **doubled;
} t_move;

// char	**functionoepn(char *string);
char	**putfromtoother(char **string);
void	loopon(t_fac *func, char **string);
char	*makestringopy(char *string);
char	**copymap(char *string);
char	*thisfunctionresader(char *string, int fd, int size);
void	finif(t_fac *string, char **str);
char	**functionfilereader(int fd);
char	**functionoepn(char *string);
int		checkwalsinmap(char **string);
int		maplastcheck(char **string);
int		checktheitems(char **string);
int		mergecheking(char **string, int numbercolum, int filed);
void	trackleftside(char **string, int x, int y);
void	printmapposition(char **string);
int		checkrows(char *string);
void	backtrack(char **string, int row, int colum);
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
// char	**functionfilereader(int fd);
int		checkhowmany(char *string);

#endif