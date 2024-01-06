/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchek.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:10:57 by mmaghri           #+#    #+#             */
/*   Updated: 2024/01/06 16:38:42 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPCHEK_H
# define MAPCHEK_H

# include <unistd.h>
# include <stdlib.h>

# include "mapchek.h"
# include <fcntl.h>
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
	int		foresult;
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
	char	*tmp;
}	t_map;

void	outofgame(void);
void	freethfunction(char **string);
char	*new_copy_lenght(char *string, int maxlenght);
void	*ft_mlx_xpm_file_to_image(t_fac *me, char *string, int x, int y);
void	*ft_mlx_new_window(t_fac *me);
void	*ft_mlx_init(void);
void	putstr(char *string);
int		movecoin(t_fac *me);
int		w_check(char string);
void	first_complete(int key, t_fac *me, int row, int colum);
int		count_number_len(int number);
void	fill(int number, int lenght, int index, char *string);
void	move_player(int key, t_fac *me, int row, int colum);
char	*change_data_type(int number);
int		monster_move(t_fac *me);
int		get_monster_position(t_fac *this, char **string);
int		count_collectibles(char **string);
void	thiskey_complete(int key, t_fac *me, int row, int colum);
int		destro(char string, t_fac *this);
int		check(char string);
void	openthis(t_fac *me);
void	put_character(t_fac *func, char **string);
int		merge_for_moving_player(int key, t_fac *me);
int		closeprogram(int key);
char	**copy_of_array(char **string);
void	fill_window_map(t_fac *func, char **string);
char	*copy_of_string(char *string);
void	thisfunctionresader(char *string, int fd, int size);
void	fill_struct(t_fac *string, char **str);
char	**return_array_from_text(int fd);
char	**get_array(char *string);
int		checkwalsinmap(char **string);
int		maplastcheck(char **string);
int		check_double_items(char **string);
int		mergecheking(char **string, int numbercolum, int filed);
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
int		lencount(char *string);
char	**stringreturn(char *string);
char	**merge_functions_checks(char *string, t_fac *me);
#endif