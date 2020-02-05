/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_sectors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:52:02 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/04 14:42:07 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "save.h"

int			get_main_sprite(int sprite, t_env *env)
{
	int		i;

	i = 0;
	while (i < MAX_OBJECTS)
	{
		if (sprite == env->objects_main_sprites[i])
			return (i);
		i++;
	}
	return (i);
}

static void	write_sector_textures(int fd, t_sector sector)
{
	int	i;

	i = 0;
	ft_dprintf(fd, "(");
	while (i < sector.nb_vertices)
	{
		// Use to save with real scale
		// !!! NOT DONE YET !!!
		ft_dprintf(fd, "[%d %.*f %.*f %.*f %.*f]",
		  sector.textures[i],
		  ft_min(5, get_decimal_len(sector.align[i].x)),
		  sector.align[i].x,
		  ft_min(5, get_decimal_len(sector.align[i].y)),
		  sector.align[i].y,
		  ft_min(5, get_decimal_len(sector.scale[i].x)),
		  sector.scale[i].x,
		  ft_min(5, get_decimal_len(sector.scale[i].y)),
		  sector.scale[i].y);

		// Use to save with default scale
		/*ft_dprintf(fd, "[%d %f %f %f %f]",
				sector.textures[i],
				sector.align[i].x,
				sector.align[i].y,
				10.0,
				10.0);*/
		i++;
	}
	ft_dprintf(fd, ") ");
}

static void	write_sector_neighbors(int fd, t_sector sector)
{
	int	i;

	i = 0;
	ft_dprintf(fd, "(");
	while (i < sector.nb_vertices)
	{
		if (i != 0)
			ft_dprintf(fd, " ");
		ft_dprintf(fd, "%d", sector.neighbors[i]);
		i++;
	}
	ft_dprintf(fd, ") ");
}

static void	write_sector_portals(int fd, t_sector sector)
{
	int	i;

	i = 0;
	ft_dprintf(fd, "(");
	while (i < sector.nb_vertices)
	{
		if (i != 0)
			ft_dprintf(fd, " ");
		ft_dprintf(fd, "%d", sector.portals[i]);
		i++;
	}
	ft_dprintf(fd, ") ");
}

static void	write_sector_vertices(int fd, t_sector sector)
{
	int	i;

	i = 0;
	ft_dprintf(fd, "(");
	while (i < sector.nb_vertices)
	{
		if (i != 0)
			ft_dprintf(fd, " ");
		ft_dprintf(fd, "%d", sector.vertices[i]);
		i++;
	}
	ft_dprintf(fd, ") ");
}

static void	write_sector_wall_sprites(int fd, t_sector sector, t_env *env)
{
	int	i;
	int	j;

	i = 0;
	ft_dprintf(fd, "(");
	while (i < sector.nb_vertices)
	{
		ft_dprintf(fd, "{");
		j = 0;
		while (j < sector.wall_sprites[i].nb_sprites)
		{
			ft_dprintf(fd, "[%d %.*f %.*f %.*f %.*f]",
				get_main_sprite(sector.wall_sprites[i].sprite[j], env),
				ft_min(5, get_decimal_len(sector.wall_sprites[i].pos[j].x)),
				sector.wall_sprites[i].pos[j].x,
				ft_min(5, get_decimal_len(sector.wall_sprites[i].pos[j].y)),
				sector.wall_sprites[i].pos[j].y,
				ft_min(5, get_decimal_len(sector.wall_sprites[i].scale[j].x)),
				sector.wall_sprites[i].scale[j].x,
				ft_min(5, get_decimal_len(sector.wall_sprites[i].scale[j].y)),
				sector.wall_sprites[i].scale[j].y);
			j++;
		}
		ft_dprintf(fd, "}");
		i++;
	}
	ft_dprintf(fd, ") ");
}

static void	write_sector_floor_sprites(int fd, t_sector sector, t_env *env)
{
	int	i;

	ft_dprintf(fd, "(");
	i = 0;
	while (i < sector.floor_sprites.nb_sprites)
	{
		ft_dprintf(fd, "[%d %.*f %.*f %.*f %.*f]",
				get_main_sprite(sector.floor_sprites.sprite[i], env),
				ft_min(5, get_decimal_len(sector.floor_sprites.pos[i].x)),
				sector.floor_sprites.pos[i].x,
				ft_min(5, get_decimal_len(sector.floor_sprites.pos[i].y)),
				sector.floor_sprites.pos[i].y,
				ft_min(5, get_decimal_len(sector.floor_sprites.scale[i].x)),
				sector.floor_sprites.scale[i].x,
				ft_min(5, get_decimal_len(sector.floor_sprites.scale[i].y)),
				sector.floor_sprites.scale[i].y);
		i++;
	}
	ft_dprintf(fd, ") ");
}

static void	write_sector_ceiling_sprites(int fd, t_sector sector, t_env *env)
{
	int	i;

	ft_dprintf(fd, "(");
	i = 0;
	while (i < sector.ceiling_sprites.nb_sprites)
	{
		ft_dprintf(fd, "[%d %.*f %.*f %.*f %.*f]",
				get_main_sprite(sector.ceiling_sprites.sprite[i], env),
				ft_min(5, get_decimal_len(sector.ceiling_sprites.pos[i].x)),
				sector.ceiling_sprites.pos[i].x,
				ft_min(5, get_decimal_len(sector.ceiling_sprites.pos[i].y)),
				sector.ceiling_sprites.pos[i].y,
				ft_min(5, get_decimal_len(sector.ceiling_sprites.scale[i].x)),
				sector.ceiling_sprites.scale[i].x,
				ft_min(5, get_decimal_len(sector.ceiling_sprites.scale[i].y)),
				sector.ceiling_sprites.scale[i].y);
		i++;
	}
	ft_dprintf(fd, ") ");
}

static void	write_sector(int fd, t_sector sector, t_env *env)
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
	write_sector_floor_sprites(fd, sector, env);
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

void		write_sectors(int fd, t_env *env)
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
