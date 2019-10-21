#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "flt.h"
int ft_check3(char *str, int i, int j);
int ft_check2(char *str, int i, int j);

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

int ft_check1(char *str)
{
	int i;
	int j;
	int k;
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
			if ((ft_check2(str, j, i) == -1) || (ft_check3(str, j, i) == -1))
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

int *ft_poisk(int *str)
{
	int x;
	int y;
	int i;
	int c1;
	int c2;

	x = 0;
	y = 1;
	c1 = str[x];
	c2 = str[y];
	while (y != 7)   //находим самый маленький x и y
	{
		if (c1 > str[x + 2])
			c1 = str[x + 2];
		if (c2 > str[y + 2])
			c2 = str[y + 2];
		x += 2;
		y += 2;
	}
	x = 0;
	y = 1;
	while (y < 8)   //делаем сдвиг в сторону верхнего левого угла
	{
		str[x] -= c1;
		str[y] -= c2;
		x += 2;
		y += 2;
	}
	return(last_check(str));
}


int *ft_check3(char *str, int i, int j, int *i_m)
{
	int x;
	int y;
	int a;
	int i_m[8]

	x = 0;
	y = 0;
	a = 0;
	while (i < j)
	{
		if (str[i] == '#')
		{
			i_m[a++] = x;
			i_m[a++] = y;
		}
		if (x == 4)
		{
			x = -1;
			y++;
		}
		x++;
		i++;
	}
	return(ft_poisk(i_m));
}

int main(int argc, char **argv)
{
	int fd;
	char *str;

	fd = open(argv[1], O_RDONLY);
	str = read_file((const int)fd, str);
	if (str == NULL)
		return(-1);
	if ((ft_check1(str)) == -1)
			return(-1);
}
