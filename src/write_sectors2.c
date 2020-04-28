#include "save.h"

void	write_sector_wall_sprites(int fd, t_sector sector, t_env *env)
{
	int	i;
	int	j;

	i = -1;
	ft_dprintf(fd, "(");
	while (++i < sector.nb_vertices)
	{
		ft_dprintf(fd, "{");
		j = -1;
		while (++j < sector.wall_sprites[i].nb_sprites)
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
		}
		ft_dprintf(fd, "}");
	}
	ft_dprintf(fd, ") ");
}

void	write_sector_floor_sprites(int fd, t_sector sector, t_env *env)
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

void	write_sector_ceiling_sprites(int fd, t_sector sector, t_env *env)
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
