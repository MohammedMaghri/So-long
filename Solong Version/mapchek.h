/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchek.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:10:57 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/03 11:38:17 by mmaghri          ###   ########.fr       */
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
	int		worck;
	int		movment;
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
	void	*picza;
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
	int		col;
	int		countcol;
	int		countmovment;
	char	*changedata;
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
int		w_check(char string);
void	first_complete(int key, t_fac *me, int row, int colum);
int		count_number_len(int number);
void	paste(char string);
void	fill(int number, int lenght, int index, char *string);
void	move_player(int key, t_fac *me, int row, int colum);
char	*change_data_type(int number);
int		monster_move(int key, t_fac *me);
void	get_monster_position(t_fac *this, char **string);
int		count_collectibles(char **string);
void	thiskey_complete(int key, t_fac *me, int row, int colum);
int		destro(char string, t_fac *this);
int		check(char string);
void	openthis(t_fac *me);
void	put_character(t_fac *func, char **string);
int		map_cle(int number, t_fac *copy);
int		merge_for_moving_player(int key, t_fac *me);
int		closeprogram(int key);
char	**copy_of_array(char **string);
void	fill_window_map(t_fac *func, char **string);
char	*copy_of_string(char *string);
char	**copymap(char *string);
char	*thisfunctionresader(char *string, int fd, int size);
void	fill_struct(t_fac *string, char **str);
char	**return_array_from_text(int fd);
char	**get_array(char *string);
int		checkwalsinmap(char **string);
int		maplastcheck(char **string);
int		check_double_items(char **string);
int		mergecheking(char **string, int numbercolum, int filed);
void	trackleftside(char **string, int x, int y);
void	printmapposition(char **string);
int		checkrows(char *string);
void	backtrack(char **string, int row, int colum);
int		player_row_position(char **string);
int		player_colum_position(char **string);
int		weirddetection(char **string);
int		maplenghtcheck(char **string);
int		checkthelenghtline(char **array);
int		checksidesofmap(char **string);
int		checkvalidity(int player, int collec, int out);
int		chekingarraybyone(char *string);
int		chekthewalsinmap(char **string);
int		lencount(char *string);
char	**stringreturn(char *string);
int		checkvalidmap(char *string);
int		check_wierd_ithem(char **string);
char	**merge_functions_checks(char *string, t_fac *me);
#endif