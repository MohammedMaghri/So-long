/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchek.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:10:57 by mmaghri           #+#    #+#             */
/*   Updated: 2023/12/22 22:52:50 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAPCHECK_H
# define MAPCHECK_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "mapchek.h"
#include <fcntl.h>

char **stringreturn(char *string);
int checkvalidmap(char *string);
char *functionfilereader(int fd);
int checkwithealllines(char *string ,int linetotal);
int checkhowmany(char *string);

#endif