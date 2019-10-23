/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dele.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalfemp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 13:31:15 by thalfemp          #+#    #+#             */
/*   Updated: 2019/10/23 14:29:46 by thalfemp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "flt.h"

void ft_poisk(s_list ***tmp)
{
	int x;
	int y;
	int i;
	int c1;
	int c2;

	x = 0;
	y = 1;
	c1 = (**tmp)->data[x];
	c2 = (**tmp)->data[y];
	while (y != 7)
	{
		if (c1 > (**tmp)->data[x + 2])
			c1 = (**tmp)->data[x + 2];
		if (c2 > (**tmp)->data[y + 2])
			c2 = (**tmp)->data[y + 2];
		x += 2;
		y += 2;
	}
	x = 0;
	y = 1;
	while (y < 8)
	{
		(**tmp)->data[x] -= c1;
		(**tmp)->data[y] -= c2;
		x += 2;
		y += 2;
	}
}

void creation(s_list **tmp, char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			(*tmp)->data[j] = i % 5;
			j++;
			(*tmp)->data[j] = i / 5;
			j++;
		}
		i++;
	}
	ft_poisk(&tmp);
}

int compare(int s1[8], int s2[8])
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int last_check(int *a)
{
	if (compare(a, I_PAT) || compare(a, IH_PAT) || compare(a, O_PAT))
		return (1);
	else if (compare(a, L_PAT) || compare(a, LA_PAT) || compare(a, LB_PAT))
		return (1);
	else if (compare(a, LC_PAT) || compare(a, J_PAT) || compare(a, JA_PAT))
		return (1);
	else if (compare(a, JB_PAT) || compare(a, JC_PAT) || compare(a, T_PAT))
		return (1);
	else if (compare(a, TA_PAT) || compare(a, TB_PAT) || compare(a, TC_PAT))
		return (1);
	else if (compare(a, S_PAT) || compare(a, SA_PAT) || compare(a, Z_PAT))
		return (1);
	else if (compare(a, ZA_PAT))
		return (1);
	else
		return (-1);
}

int check3(s_list **elem)
{
	s_list *tmp;
	int i;
	s_list *current;
	s_list *next;

	current = *elem;
	tmp = *elem;
	while (tmp)
	{
		if ((last_check(tmp->data) == -1))
		{
			while (current)
			{
				next = current->next;
				free(current);
				current = next;
			}
			*elem = NULL;
			return (-1);
		}
		tmp = tmp->next;
	}
	free(current);
	return(1);
}

s_list *mass(int t, char *str)
{
	s_list *head;
	s_list *tmp;
	int c;
	int x;
	char i;

	if (!(head = (s_list*)malloc(sizeof(s_list))))
		return (NULL);
	tmp = head;
	c = 0;
	i = 'A';
	while (t != 0)
	{
		tmp->c = i;
		creation(&tmp, ft_strsub(str, c, 20));
		if ((t - 1) != 0)
		{
			if (!((tmp->next) = (s_list*)malloc(sizeof(s_list))))
				return (NULL);
		}
		tmp = tmp->next;
		t--;
		c += 21;
		i++;
	}
	return (head);
}

char		*read_file(const int fd, char *line)
{
	int		ret;
	char	*tmp;
	char	buf[BUFF_SIZE + 1];

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (line == NULL)
			line = ft_strnew(1);
		if (!(tmp = ft_strjoin(line, buf)))
			return (NULL);
		free(line);
		line = tmp;
	}
	return(line);
}

int main(int argc, char **argv)
{
	s_list *head;
	s_list *elem;
	int fd;
	char *str;
	int i = 0;

	fd = open(argv[1], O_RDONLY);
	str = read_file((const int)fd, str);
	head = mass(4, str);
	elem = head;
	i = check3(&elem);
	printf("i - %d\n", i);
	while (elem)
	{
		i = 0;
		while (i < 8)
		{
			printf("%d", elem->data[i]);
			//printf("%c", elem->c);
			i++;
		}
		printf("%c", elem->c);
		printf("\n");
		elem = elem->next;
	}
	printf("\n");
	return (0);
}
