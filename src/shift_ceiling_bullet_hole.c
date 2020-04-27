#include "env.h"

void	shift_ceiling_current_bullet_hole(int i, t_sector *sector,
t_projectile *projectile, t_env *env)
{
	int	j;

	j = i + 1;
	while (j < sector->ceiling_sprites.nb_sprites &&
	sector->ceiling_sprites.sprite[j] != 3)
		j++;
	if (j < sector->ceiling_sprites.nb_sprites)
	{
		sector->ceiling_sprites.pos[i] = sector->ceiling_sprites.pos[j];
		sector->ceiling_sprites.scale[i] = sector->ceiling_sprites.scale[j];
	}
	else
	{
		sector->ceiling_sprites.pos[i] = 
		get_ceiling_bullet_hole_pos(sector, projectile, env);
		sector->ceiling_sprites.pos[i].x -=
		sector->ceiling_sprites.scale[i].x / 2;
		sector->ceiling_sprites.pos[i].y -=
		sector->ceiling_sprites.scale[i].y / 2;
	}
}

int		shift_ceiling_bullet_hole(t_sector *sector, t_projectile *projectile,
t_env *env)
{
	int	i;

	i = 0;
	while (i < sector->ceiling_sprites.nb_sprites)
	{
		if (sector->ceiling_sprites.sprite[i] == 3)
		  	shift_ceiling_current_bullet_hole(i, sector, projectile, env);
		i++;
	}
	return (0);
}
