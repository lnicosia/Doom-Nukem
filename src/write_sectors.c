/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_sectors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:52:02 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/21 14:59:48 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "save.h"

void	write_sector_floor(int fd, t_sector sector)
{
	ft_dprintf(fd, "[%.*f %.*f %d %d %.*f %.*f %.*f %.*f] ",
			ft_min(5, get_decimal_len(sector.floor)),
			sector.floor,
			ft_min(5, get_decimal_len(sector.floor_slope)),
			sector.floor_slope,
			sector.start_floor_slope,
			sector.floor_texture,
			ft_min(5, get_decimal_len(sector.floor_map_align.x)),
			sector.floor_map_align.x,
			ft_min(5, get_decimal_len(sector.floor_map_align.y)),
			sector.floor_map_align.y,
			ft_min(5, get_decimal_len(sector.floor_map_scale.x)),
			sector.floor_map_scale.x,
			ft_min(5, get_decimal_len(sector.floor_map_scale.y)),
			sector.floor_map_scale.y);
}

void	write_sector_ceiling(int fd, t_sector sector)
{
	ft_dprintf(fd, "[%.*f %.*f %d %d %.*f %.*f %.*f %.*f] ",
			ft_min(5, get_decimal_len(sector.ceiling)),
			sector.ceiling,
			ft_min(5, get_decimal_len(sector.ceiling_slope)),
			sector.ceiling_slope,
			sector.start_ceiling_slope,
			sector.ceiling_texture,
			ft_min(5, get_decimal_len(sector.ceiling_map_align.x)),
			sector.ceiling_map_align.x,
			ft_min(5, get_decimal_len(sector.ceiling_map_align.y)),
			sector.ceiling_map_align.y,
			ft_min(5, get_decimal_len(sector.ceiling_map_scale.x)),
			sector.ceiling_map_scale.x,
			ft_min(5, get_decimal_len(sector.ceiling_map_scale.y)),
			sector.ceiling_map_scale.y);
}

void	write_sector(int fd, t_sector sector, t_env *env)
{
	write_sector_floor(fd, sector);
	write_sector_floor_sprites(fd, sector, env);
	write_sector_ceiling(fd, sector);
	write_sector_ceiling_sprites(fd, sector, env);
	write_sector_vertices(fd, sector);
	write_sector_neighbors(fd, sector);
	write_sector_portals(fd, sector);
	write_sector_textures(fd, sector);
	write_sector_wall_sprites(fd, sector, env);
	ft_dprintf(fd, "[%d %x %d %.*f]\n", (int)(sector.brightness),
	sector.light_color, (int)sector.intensity,
	ft_min(5, get_decimal_len(sector.gravity)),
	sector.gravity);
}

void	write_sectors(int fd, t_env *env)
{
	int	i;

	i = 0;
	ft_dprintf(fd, "\nS %d\n", env->nb_sectors);
	while (i < env->nb_sectors)
	{
		write_sector(fd, env->sectors[i], env);
		i++;
	}
}
