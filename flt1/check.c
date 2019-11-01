/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalfemp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:39:11 by thalfemp          #+#    #+#             */
/*   Updated: 2019/11/01 14:07:05 by thalfemp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "flt.h"
#include "get_next_line.h"

int num(int nb)
{
    int i;

    i = 1;

    nb = nb * 4;
    while (i * i < nb)
        i++;
    return (i);
}

void free_map(t_map *map)
{
    int i;

    i = 0;
    while (i < map->size)
    {
        ft_memdel((void **)&(map->array[i]));
        i++;
    }
    ft_memdel((void **)&(map->array));
    ft_memdel((void **)&map);
}

t_map *map_new(int size)
{
    t_map *map;
    int i;
    int j;

    map = (t_map *)ft_memalloc(sizeof(t_map));
    map->size = size;
    map->array = (char **)ft_memalloc(sizeof(char *) * size);
    i = 0;
    while (i < size)
    {
        map->array[i] = ft_strnew(size);
        j = 0;
        while (j < size)
        {
            map->array[i][j] = '.';
            j++;
        }
        i++;
    }
    return (map);
}

void tetr(int size, s_list *elem)
{
    t_map *map;
    char **res;
    int j;
    int c;

    size = 10;
    map = map_new(size);
    printf("%d", elem->data[0]);
    printf("\n");
    printf("%d", elem->data[1]);
    printf("\n");
    size++;
    free_map(map);
    map = map_new(size);
    printf("%d", elem->data[0]);
    printf("\n");
    printf("%d", elem->data[1]);
    printf("\n");
    size++;
    free_map(map);
    map = map_new(size);
    printf("%d", elem->data[0]);
    printf("\n");
    printf("%d", elem->data[1]);
    printf("\n");
}

int main()
{
    s_list *head;
    s_list *one;
    //s_list *two;
    //s_list *three;
    //s_list *four;
    //s_list *five;
    //s_list *six;
    //s_list *seven;

    head = (s_list *)malloc(sizeof(s_list));
    one = (s_list *)malloc(sizeof(s_list));
    //two = (s_list*)malloc(sizeof(s_list));
    //three = (s_list*)malloc(sizeof(s_list));
    //four = (s_list*)malloc(sizeof(s_list));
    //five = (s_list*)malloc(sizeof(s_list));
    //six = (s_list*)malloc(sizeof(s_list));
    //seven = (s_list*)malloc(sizeof(s_list));
    head->data[0] = 0;
    head->data[1] = 0;
    head->data[2] = 1;
    head->data[3] = 0;
    head->data[4] = 0;
    head->data[5] = 1;
    head->data[6] = 1;
    head->data[7] = 1;
    head->next = one;
    one->data[0] = 0;
    one->data[1] = 0;
    one->data[2] = 1;
    one->data[3] = 0;
    one->data[4] = 2;
    one->data[5] = 0;
    one->data[6] = 3;
    one->data[7] = 0;
    one->next = NULL;
    tetr(4, head);
    return(0);
}
