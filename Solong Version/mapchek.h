/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchek.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:10:57 by mmaghri           #+#    #+#             */
/*   Updated: 2023/12/31 16:13:50 by mmaghri          ###   ########.fr       */
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
	int		monster_row;
	int		monster_colum;
	int		flag;
	int		colom;
	int		row;
	int		index;
	int		increment;
	void	*forwindow;
	void	*forinit;
	char	*pic;
	void	*picb;
	void	*picc;
	void	*picx;
	void	*picz;
	int		x;
	int		y;
	int		xx;
	int		yy;
	char	**twod;
	char	**tocopy;
	int		yfor;
	int		xfor;
	int		indexfor;
	char	**twodefor;
	int		total;
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

typedef struct moveit
{
	char	**doubled;
}	t_move;
void	look_for(t_fac *this, char **string);
int		count_col(char **string);
void	thiskey(int key, t_fac *me, int row, int colum);
void	thiskey_complete(int key, t_fac *me, int row, int colum);
int		destro(char string, t_fac *this);
void	finif(t_fac *string, char **str);
int		check(char string);
void	openthis(t_fac *me);
void	put_character(t_fac *func, char **string);
int		map_cle(int number, t_fac *copy);
int		keeeey(int key, t_fac *me);
int		closeprogram(int key);
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
int		check_w(char **string);
int		checkhowmany(char *string);
char	**evry_thing(char *string, t_fac *me);
#endif