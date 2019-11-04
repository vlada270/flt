/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalfemp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:39:11 by thalfemp          #+#    #+#             */
/*   Updated: 2019/11/04 14:40:25 by thalfemp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flt.h"
#include "get_next_line.h"
#include <unistd.h>

char **algoritm(char **map, int size, s_list *elem);

int num(int nb)
{
	int i;

	i  = 1;
	nb = nb * 4;
	while (i * i < nb)
		i++;
	return (i);
}

char **create_mas(int size)
{
	char **map;
	int i;
	int j;

	i = 0;
	if (!(map = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		if (!(map[i] = (char*)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		j = -1;
		while (j++ < size - 1)
			map[i][j] = '.';
		map[i][j] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}


/*void tetr(int size, s_list *elem)
{
	t_map  *map;
	char **res;
	int j;
	int c;

	size = num(size);
	map = map_new(size);
	printf("%d", elem->data[0]);
	printf("\n");
	printf("%d", elem->data[1]);
	printf("\n");
	//print_map(map);
	size++;
	free_map(map);
	map = map_new(size);
	printf("%d", elem->data[0]);
	printf("\n");
	printf("%d", elem->data[1]);
	printf("\n");
	//print_map(map);
	size++;
	free_map(map);
	map = map_new(size);
	printf("%d", elem->data[0]);
	printf("\n");
	printf("%d", elem->data[1]);
	printf("\n");
	//print_map(map);
}*/

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

void pr(int size, char **mas)
{
	int i;

	i = 0;
	while (i < size)
	{
		printf("%s", mas[i]);
		printf("\n");
		i++;
	}
}

void ls(int size, s_list *elem)
{
	s_list *tmp;

	tmp = elem;
	printf("elem- %d\n", tmp->data[0]);
	printf("elem- %d\n", tmp->data[1]);
}

char **algoritm(char **map, int size, s_list *elem)
{
	int x;
	int y;
	char **tetris;

	if (elem == NULL)
		return (map);
	tetris = NULL;
	pr(size, map);
	ls(size, elem);
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (check_m(elem, y, x, map, size))
				tetris = algoritm(c_array(elem, y, x, map, size),
						size, elem->next);
			if (tetris != NULL)
				return (tetris);
			del_e(elem->c, map, size);
			x++;
		}
		y++;
	}
	//ls(size, elem);
	return (NULL);
}
