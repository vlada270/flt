/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalfemp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:46:28 by thalfemp          #+#    #+#             */
/*   Updated: 2019/09/16 10:50:56 by thalfemp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *a;

	if (alst)
	{
		while (*alst)
		{
			a = (*alst);
			(*alst) = (*alst)->next;
			del((a)->content, (a)->content_size);
			ft_memdel((void**)&a);
		}
		free(*alst);
	}
}
