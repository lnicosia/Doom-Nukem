#include "env.h"

void	shit_floor_current_bullet_hole(int i, t_sector *sector,
t_projectile *projectile, t_env *env)
{
	int	j;

	j = i + 1;
	while (j < sector->floor_sprites.nb_sprites &&
	sector->floor_sprites.sprite[j] != 3)
		j++;
	if (j < sector->floor_sprites.nb_sprites)
	{
		sector->floor_sprites.pos[i] = sector->floor_sprites.pos[j];
		sector->floor_sprites.scale[i] = sector->floor_sprites.scale[j];
	}
	else
	{
		sector->floor_sprites.pos[i] = 
		get_floor_bullet_hole_pos(sector, projectile, env);
		sector->floor_sprites.pos[i].x -=
		sector->floor_sprites.scale[i].x / 2;
		sector->floor_sprites.pos[i].y -=
		sector->floor_sprites.scale[i].y / 2;
	}
}

int		shift_floor_bullet_hole(t_sector *sector, t_projectile *projectile,
t_env *env)
{
	int	i;

	i = 0;
	while (i < sector->floor_sprites.nb_sprites)
	{
		if (sector->floor_sprites.sprite[i] == 3)
		  	shit_floor_current_bullet_hole(i, sector, projectile, env);
		i++;
	}
	return (0);
}
