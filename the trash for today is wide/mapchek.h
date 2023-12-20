/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchek.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:10:57 by mmaghri           #+#    #+#             */
/*   Updated: 2023/12/19 16:52:22 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAPCHECK_H
# define MAPCHECK_H

int checkvalidmap(char *string);
char *functionfilereader(int fd);
int checkwithealllines(char *string ,int linetotal);
int checkhowmany(char *string);

#endif