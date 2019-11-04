/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dele.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   B) thalfemptruct s_map
 *   {
 *   int size;
 *   char **array;
 *   } t_map;<marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 13:31:15 by thalfemp          #+#    #+#             */
/*   Updated: 2019/11/01 13:18:58 by thalfemp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "flt.h"


char **tetr(int size, s_list *elem);

void ft_poisk(s_list *tmp)
{
	int x;
	int y;
	int i;
	int c1;
	int c2;

	x = 0;
	y = 1;
	c1 = (tmp)->data[x];
	c2 = (tmp)->data[y];
	while (y != 7)
	{
		if (c1 > (tmp)->data[x + 2])
			c1 = (tmp)->data[x + 2];
		if (c2 > (tmp)->data[y + 2])
			c2 = (tmp)->data[y + 2];
		x += 2;
		y += 2;
	}
	x = 0;
	y = 1;
	while (y < 8)
	{
		(tmp)->data[x] -= c1;
		(tmp)->data[y] -= c2;
		x += 2;
		y += 2;
	}
}

int ft_check2(char *str, int i, int j)
{
	int x1;
	int x2;
	int x3;


	x1 = 0;
	x2 = 0;
	x3 = 0;
	while (i < j && str[i] != '\0')
	{
		if  (str[i] == '.')
			x1++;
		else if (str[i] == '#')
			x2++;
		else if (str[i] == '\n')
			x3++;
		i++;
	}
	if (x1 == 12 && x2 == 4 && x3 == 4)
		return(1);
	return (-1);
}

int ft_check1(char *str)
{
	int i;
	int j;
	int x;
	int f;

	i = 20;
	j = 0;
	x = 0;
	f = ft_strlen(str) + 21;
	while ((i != f) && (x <= 26)) //уточнить насчет ограничения в 26
	{
		if ((str[i] == '\n' && str[i - 1] == '\n') ||
				str[i] == '\0')
		{
			if (ft_check2(str, j, i) == -1)
				return (-1);
			j = i + 1;
			i = i + 21;
			x++;
		}
		else 
			return (-1);
	}
	if (x > 26)
		return (-1);
	return (x);
}


void creation(s_list *tmp, char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			(tmp)->data[j] = i % 5;
			j++;
			(tmp)->data[j] = i / 5;
			j++;
		}
		i++;
	}
	ft_poisk(tmp);
}

int check(int s1[8], int s2[8])
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

int last_check(int a[8])
{
	if (check(a, I_PAT) || check(a, IH_PAT) || check(a, O_PAT))
		return (1);
	else if (check(a, L_PAT) || check(a, LA_PAT) || check(a, LB_PAT))
		return (1);
	else if (check(a, LC_PAT) || check(a, J_PAT) || check(a, JA_PAT))
		return (1);
	else if (check(a, JB_PAT) || check(a, JC_PAT) || check(a, T_PAT))
		return (1);
	else if (check(a, TA_PAT) || check(a, TB_PAT) || check(a, TC_PAT))
		return (1);
	else if (check(a, S_PAT) || check(a, SA_PAT) || check(a, Z_PAT))
		return (1);
	else if (check(a, ZA_PAT))
		return (1);
	else
		return (-1);
}

void deleteList(s_list ***elem)
{
	s_list *current;
	s_list *next;

	current = **elem;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	**elem = NULL;
}

int check3(s_list **elem)
{
	s_list *tmp;
	
	tmp = *elem;
	while (tmp)
	{
		if ((last_check(tmp->data) == -1))
		{
			deleteList(&elem);
			return (-1);
		}
		tmp = tmp->next;
	}
	return(1);
}
		
s_list *mass(int t, char *str, s_list *head)
{
	s_list *tmp;
	char i;
	int x;

	if (!(head = (s_list*)malloc(sizeof(s_list))))
		return (NULL);
	tmp = head;
	i = 'A';
	x = 0;
	while (t != 0)
	{	
		tmp->c = i;
		creation(tmp, ft_strsub(str, x, 20));
		if ((t - 1) != 0)
		{
			if (!((tmp->next) = (s_list*)malloc(sizeof(s_list))))
				return (NULL);
		}
		tmp = tmp->next;
		t--;
		x += 21;
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

void sol(int size, s_list *head)
{
	s_list *elem;

	elem = head;
	while (elem && size != 100)
	{
		size = 0;
		while (size < 8)
		{
			printf("%d", elem->data[size]);
			size++;
		}
		printf("%c", elem->c);
		printf("\n");
		elem = elem->next;
	}
}

void p(char **mas)
{
	int i;

	i = 0;
	while (i < 6)
	{
		printf("%s", mas[i]);
		printf("\n");
		i++;
	}
}

int main(int argc, char **argv)
{
	s_list *head;
	int fd;
	char *str;
	int size;
	char **mas;
	s_list *elem;

	
	fd = open(argv[1], O_RDONLY);
	str = read_file((const int)fd, str);
	if (str == NULL)
		return(-1);
	if ((size = ft_check1(str)) == -1)
			return(-1);
	head = NULL;
	head = mass(size, str, head);
	if ((check3(&head)) == -1)
		return(-1);
   	mas = tetr(size, head);
	p(mas);
	//sol(size, head);
	return (0);
}
