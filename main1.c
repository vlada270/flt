/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalfemp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:39:11 by thalfemp          #+#    #+#             */
/*   Updated: 2019/10/31 17:41:54 by thalfemp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flt.h"
#include "get_next_line.h"
#include <unistd.h>

char **create_mas(int size);
int num(int nb);
char **algoritm(char **map, int size, s_list *elem);

char **tetr(int size, s_list *elem)
{
	char **mas;
	char **res;
	int i;
	int j;

	i = 0;
	size = num(size);
	if (!(mas = create_mas(size)))
		return(NULL);
	while (!(res = algoritm(mas, size, elem)))
	{
			j = 0;
			while (j < size)
			{
				free(mas[j]);
				j++;
			}
			free(mas);
			size++;
			if (!(mas = create_mas(size)))
				return(NULL);
	}
	return (res);
}

void prnt(char **res, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		printf("%s", res[i]);
		printf("\n");
		i++;
	}
}

int num(int nb)
{
	int i;

	i  = 1;
	nb = nb * 4;
	while (i * i < nb)
		i++;
	return (i);
}

void help_c(s_list *elem, int x, int y)
{
	int i;

	i = 0;
	while (i < 8)
	{
		elem->data[i] += x;
		i++;
		elem->data[i] += y;
		i++;
	}
}

void help_c1(s_list *elem, int x, int y)
{
	int i;

	i = 0;
	while (i < 8)
	{
		elem->data[i] -= x;
		i++;
		elem->data[i] -= y;
		i++;
	}
}

void d(s_list *elem)
{
	int i;

	i = 0;
	while (i < 8)
	{
		printf("%d", elem->data[i]);
		i++;
	}
}

int check_m(s_list *elem, int y, int x,  char **mas, int size)
{
	int  i;
	int y1;
	int x1;

	help_c(elem, x, y);
	i = 0;
	y1 = 0;
	while (y1 < size)
	{
		x1 = 0;
		while (x1 < size)
		{
			if (elem->data[i] < size && elem->data[i+1] < size
				&& mas[elem->data[i+1]][elem->data[i]] == '.')
				i += 2;
			if (i == 8)
				return (1);
			x1++;
		}
		y1++;
	}
	help_c1(elem, x, y);
	return (0);
}

char **c_array(s_list *elem, int y, int x, char **mas, int size)
{
	int  i;
	int y1;
	int x1;

	i = 0;
	y1 = 0;
	while (y1 < size)
	{
		x1 = 0;
		while (x1 < size)
		{
			if (elem->data[i] < size && elem->data[i+1] < size
				&& mas[elem->data[i+1]][elem->data[i]] == '.')
			{
				mas[elem->data[i+1]][elem->data[i]] = elem->c;
				i += 2;
			}
			if (i == 8)
			{
				help_c1(elem, x, y);
				return (mas);
			}
			x1++;
		}
		y1++;
	}
	help_c1(elem, x, y);
	return (mas);
}

void del_e(char c, char **mas, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (mas[i][j] == c)
				mas[i][j] = '.';
			j++;
		}
		i++;
	}
}

char **algoritm(char **map, int size, s_list *elem)
{
	int x;
	int y;
	char **tetris;

	if (elem == NULL)
		return (map);
	tetris = NULL;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if ((check_m(elem,y, x, map, size)) == 1)
				tetris = algoritm(c_array(elem, y, x, map, size),size, elem->next);
			if (tetris != NULL)
				return (tetris);
			del_e(elem->c, map, size);
			x++;
		}
		y++;
	}
	return (NULL);
}
