/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalfemp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:50:19 by thalfemp          #+#    #+#             */
/*   Updated: 2019/11/01 13:37:27 by thalfemp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define I_PAT (int[8]) {0, 0, 0, 1, 0, 2, 0, 3}
# define IH_PAT (int[8]) {0, 0, 1, 0, 2, 0, 3, 0}
# define O_PAT (int[8]) {0, 0, 1, 0, 0, 1, 1, 1}
# define L_PAT (int[8]) {0, 0, 0, 1, 0, 2, 1, 2}
# define LA_PAT (int[8]) {0, 0, 1, 0, 2, 0, 0, 1}
# define LB_PAT (int[8]) {0, 0, 1, 0, 1, 1, 1, 2}
# define LC_PAT (int[8]) {2, 0, 0, 1, 1, 1, 2, 1}
# define J_PAT (int[8]) {1, 0, 1, 1, 0, 2, 1, 2}
# define JA_PAT (int[8]) {0, 0, 0, 1, 1, 1, 2, 1}
# define JB_PAT (int[8]) {0, 0, 1, 0, 0, 1, 0, 2}
# define JC_PAT (int[8]) {0, 0, 1, 0, 2, 0, 2, 1}
# define T_PAT (int[8]) {0, 0, 1, 0, 2, 0, 1, 1}
# define TA_PAT (int[8]) {1, 0, 0, 1, 1, 1, 1, 2}
# define TB_PAT (int[8]) {1, 0, 0, 1, 1, 1, 2, 1}
# define TC_PAT (int[8]) {0, 0, 0, 1, 1, 1, 0, 2}
# define S_PAT (int[8]) {1, 0, 2, 0, 0, 1, 1, 1}
# define SA_PAT (int[8]) {0, 0, 0, 1, 1, 1, 1, 2}
# define Z_PAT (int[8]) {0, 0, 1, 0, 1, 1, 2, 1}
# define ZA_PAT (int[8]) {1, 0, 0, 1, 1, 1, 0, 2}

typedef struct s_map
{
	int size;
	char **array;
} t_map;

typedef struct			t_list
{
	int				data[8];
	char			c;
	struct t_list		*next;
}						s_list;
