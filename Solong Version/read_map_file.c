/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:26:54 by mmaghri           #+#    #+#             */
/*   Updated: 2023/12/31 16:15:54 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapchek.h"

//remake this function
char	*thisfunctionresader(char *string, int fd, int size)
{
	int	readsize;

	readsize = 1;
	while (fd >= 0 && size > 0)
	{
		readsize = read(fd, string, size);
		if (readsize <= 0)
		{
			free(string);
			return (0);
		}
		string[readsize] = '\0';
	}
	if (string)
	{
		if (string[0] == '\0')
		{
			free(string);
			return (0);
		}
	}
	return (string);
}

char	**putfromtoother(char **string)
{
	int		index ;
	int		total;
	char	**alocation;

	index = 0;
	total = maplenghtcheck(string);
	alocation = malloc(sizeof(char *) * (total) + 1);
	while (index <= maplenghtcheck(string))
	{
		alocation[index] = makestringopy(string[index]);
		index++ ;
	}
	alocation[index] = NULL;
	return (alocation);
}

int	keeeey(int key, t_fac *me)
{
	int	colum ;
	int	row ;

	look_for(me , me->twodefor);
	printf("| [%d] [%d] |\n" , me->monster_row , me->monster_colum);
	row = player_row_position(me->twodefor);
	colum = player_colum_position(me->twodefor);
	thiskey(key, me, row, colum);
	return (0);
}

char	**functionfilereader(int fd)
{
	t_map	filereader;
	int		size;
	char	*thistext;
	char	**stringarray;
	char	**res;

	size = 10000;
	if (fd < 0)
		return (0);
	thistext = malloc(sizeof(char) * size + 1);
	thisfunctionresader(thistext, fd, size);
	stringarray = stringreturn(thistext);
	res = putfromtoother(stringarray);
	filereader.numberofclomums = player_row_position(stringarray);
	filereader.colum = player_colum_position(stringarray);
	filereader.checker = mergecheking(stringarray, \
	filereader.numberofclomums, filereader.colum);
	if (filereader.checker == -1)
		return (exit(1), NULL);
	return (res);
}

char	**functionoepn(char *string)
{
	t_map	putmap;

	putmap.filed = open(string, O_RDONLY);
	putmap.twode = functionfilereader(putmap.filed);
	return (putmap.twode);
}
