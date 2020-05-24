/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 14:09:52 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 14:09:53 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALID_MAP_H
# define VALID_MAP_H
# include "env.h"

typedef struct	s_sector_comparer
{
	t_sector	sect1;
	t_sector	sect2;
	int			start_v1;
	int			start_v2;
	int			i;
	int			j;
}				t_sector_comparer;

#endif
