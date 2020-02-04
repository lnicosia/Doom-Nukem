/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_sectors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:52:02 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/04 10:08:28 by lnicosia         ###   ########.fr       */
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
		ft_dprintf(fd, "[%d %f %f %f %f]",
		  sector.textures[i],
		  sector.align[i].x,
		  sector.align[i].y,
		  sector.scale[i].x,
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
			ft_dprintf(fd, "[%d %f %f %f %f]",
					get_main_sprite(sector.wall_sprites[i].sprite[j], env),
					sector.wall_sprites[i].pos[j].x,
					sector.wall_sprites[i].pos[j].y,
					sector.wall_sprites[i].scale[j].x,
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
		ft_dprintf(fd, "[%d %f %f %f %f]",
				get_main_sprite(sector.floor_sprites.sprite[i], env),
				sector.floor_sprites.pos[i].x,
				sector.floor_sprites.pos[i].y,
				sector.floor_sprites.scale[i].x,
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
		ft_dprintf(fd, "[%d %f %f %f %f]",
				get_main_sprite(sector.ceiling_sprites.sprite[i], env),
				sector.ceiling_sprites.pos[i].x,
				sector.ceiling_sprites.pos[i].y,
				sector.ceiling_sprites.scale[i].x,
				sector.ceiling_sprites.scale[i].y);
		i++;
	}
	ft_dprintf(fd, ") ");
}

static void	write_sector(int fd, t_sector sector, t_env *env)
{
	ft_dprintf(fd, "[%.5f %.5f %d %.5f %.5f %.5f %.5f] ",
			sector.floor, sector.floor_slope, sector.floor_texture,
			sector.floor_map_align.x, sector.floor_map_align.y,
			sector.floor_map_scale.x, sector.floor_map_scale.y);
	write_sector_floor_sprites(fd, sector, env);
	ft_dprintf(fd, "[%.5f %.5f %d %.5f %.5f %.5f %.5f] ",
			sector.ceiling, sector.ceiling_slope, sector.ceiling_texture,
			sector.ceiling_map_align.x, sector.ceiling_map_align.y,
			sector.ceiling_map_scale.x, sector.ceiling_map_scale.y);
	write_sector_ceiling_sprites(fd, sector, env);
	write_sector_vertices(fd, sector);
	write_sector_neighbors(fd, sector);
	write_sector_portals(fd, sector);
	write_sector_textures(fd, sector);
	write_sector_wall_sprites(fd, sector, env);
	ft_dprintf(fd, "[%d %x %d %f]\n", (int)(sector.brightness),
	sector.light_color, (int)sector.intensity, sector.gravity);
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
