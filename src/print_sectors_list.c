/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sectors_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 10:11:50 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/26 12:40:33 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	print_sector_vertices(t_sector sector)
{
	int	i;

	i = 0;
	while (i < sector.nb_vertices)
	{
		ft_printf("%d", sector.vertices[i]);
		if (i < sector.nb_vertices - 1)
			ft_printf(" ");
		else
			ft_printf(") (");
		i++;
	}
}

void	print_sector_neighbors(t_sector sector)
{
	int	i;

	i = 0;
	while (i < sector.nb_vertices)
	{
		ft_printf("%d", sector.neighbors[i]);
		if (i < sector.nb_vertices - 1)
			ft_printf(" ");
		else
			ft_printf(") (");
		i++;
	}
}

void	print_sector_textures(t_sector sector)
{
	int	i;

	i = 0;
	while (i < sector.nb_vertices)
	{
		ft_printf("%d", sector.textures[i]);
		if (i < sector.nb_vertices - 1)
			ft_printf(" ");
		else
			ft_printf(") ");
		i++;
	}
}

void	print_sector(t_sector sector)
{
	ft_printf("sector %d =", sector.num);
	ft_printf("[%f %f %d] ", sector.floor, sector.floor_slope,
			sector.floor_texture);
	ft_printf("[%f %f %d] (", sector.ceiling, sector.ceiling_slope,
			sector.ceiling_texture);
	print_sector_vertices(sector);
	print_sector_neighbors(sector);
	print_sector_textures(sector);
	ft_printf("%d\n", (int)(sector.light * 100));
}

void	print_sector_list(t_env *env)
{
	t_list		*tmp;
	t_sector	*sector;

	tmp = env->editor.sectors;
	while (tmp)
	{
		sector = (t_sector*)tmp->content;
		print_sector(*sector);
		tmp = tmp->next;
	}
}
