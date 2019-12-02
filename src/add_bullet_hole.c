/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_bullet_hole.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 11:53:44 by lnicosia          #+#    #+#             */
/*   Updated: 2019/12/02 15:24:57 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		add_floor_bullet_hole(t_sector *sector, t_projectile *projectile,
t_env *env)
{
	if (!(sector->floor_sprites.sprite =
				(short*)ft_realloc(sector->floor_sprites.sprite,
					sizeof(short) * sector->nb_floor_sprites,
					sizeof(short) * (sector->nb_floor_sprites + 1))))
		return (ft_perror("Could not realloc floor sprites indexes"));
	if (!(sector->floor_sprites.pos =
				(t_v2*)ft_realloc(sector->floor_sprites.pos,
					sizeof(t_v2) * sector->nb_floor_sprites,
					sizeof(t_v2) * (sector->nb_floor_sprites + 1))))
		return (ft_perror("Could not realloc floor sprites pos"));
	if (!(sector->floor_sprites.scale =
				(t_v2*)ft_realloc(sector->floor_sprites.scale,
					sizeof(t_v2) * sector->nb_floor_sprites,
					sizeof(t_v2) * (sector->nb_floor_sprites + 1))))
		return (ft_perror("Could not realloc floor sprites scale"));
	sector->floor_sprites.sprite[sector->nb_floor_sprites] = 3;
	sector->floor_sprites.scale[sector->nb_floor_sprites] = new_v2(0.4, 0.4);
	sector->floor_sprites.pos[sector->nb_floor_sprites] =
	get_floor_bullet_hole_pos(sector, projectile, env);
	sector->floor_sprites.pos[sector->nb_floor_sprites].x -=
	sector->floor_sprites.scale[sector->nb_floor_sprites].x / 2;
	sector->floor_sprites.pos[sector->nb_floor_sprites].y -=
	sector->floor_sprites.scale[sector->nb_floor_sprites].y / 2;
	sector->nb_floor_sprites++;
	return (0);
}

int		add_ceiling_bullet_hole(t_sector *sector, t_projectile *projectile,
t_env *env)
{
	(void)env;
	if (!(sector->ceiling_sprites.sprite =
				(short*)ft_realloc(sector->ceiling_sprites.sprite,
					sizeof(short) * sector->nb_ceiling_sprites,
					sizeof(short) * (sector->nb_ceiling_sprites + 1))))
		return (ft_perror("Could not realloc ceiling sprites indexes"));
	if (!(sector->ceiling_sprites.pos =
				(t_v2*)ft_realloc(sector->ceiling_sprites.pos,
					sizeof(t_v2) * sector->nb_ceiling_sprites,
					sizeof(t_v2) * (sector->nb_ceiling_sprites + 1))))
		return (ft_perror("Could not realloc ceiling sprites pos"));
	if (!(sector->ceiling_sprites.scale =
				(t_v2*)ft_realloc(sector->ceiling_sprites.scale,
					sizeof(t_v2) * sector->nb_ceiling_sprites,
					sizeof(t_v2) * (sector->nb_ceiling_sprites + 1))))
		return (ft_perror("Could not realloc ceiling sprites scale"));
	sector->ceiling_sprites.sprite[sector->nb_ceiling_sprites] = 3;
	sector->ceiling_sprites.scale[sector->nb_ceiling_sprites] = new_v2(0.4,
	0.4);
	sector->ceiling_sprites.pos[sector->nb_ceiling_sprites] =
	get_ceiling_bullet_hole_pos(sector, projectile, env);
	sector->ceiling_sprites.pos[sector->nb_ceiling_sprites].x -=
	sector->ceiling_sprites.scale[sector->nb_ceiling_sprites].x / 2;
	sector->ceiling_sprites.pos[sector->nb_ceiling_sprites].y -=
	sector->ceiling_sprites.scale[sector->nb_ceiling_sprites].y / 2;
	sector->nb_ceiling_sprites++;
	return (0);
}

int		add_wall_bullet_hole(t_sector *sector, t_projectile *projectile,
int i, t_env *env)
{
	if (!(sector->sprites[i].sprite =
				(short*)ft_realloc(sector->sprites[i].sprite,
					sizeof(short) * sector->nb_sprites[i],
					sizeof(short) * (sector->nb_sprites[i] + 1))))
		return (ft_perror("Could not realloc wall sprites indexes"));
	if (!(sector->sprites[i].pos =
				(t_v2*)ft_realloc(sector->sprites[i].pos,
					sizeof(t_v2) * sector->nb_sprites[i],
					sizeof(t_v2) * (sector->nb_sprites[i] + 1))))
		return (ft_perror("Could not realloc wall sprites pos"));
	if (!(sector->sprites[i].scale =
				(t_v2*)ft_realloc(sector->sprites[i].scale,
					sizeof(t_v2) * sector->nb_sprites[i],
					sizeof(t_v2) * (sector->nb_sprites[i] + 1))))
		return (ft_perror("Could not realloc wall sprites scale"));
	sector->sprites[i].sprite[sector->nb_sprites[i]] = 3;
	sector->sprites[i].scale[sector->nb_sprites[i]] = new_v2(0.4, 0.4);
	sector->sprites[i].pos[sector->nb_sprites[i]] =
	get_wall_bullet_hole_pos(sector, projectile, i, env);
	sector->sprites[i].pos[sector->nb_sprites[i]].x -=
	sector->sprites[i].scale[sector->nb_sprites[i]].x / 2;
	sector->sprites[i].pos[sector->nb_sprites[i]].y -=
	sector->sprites[i].scale[sector->nb_sprites[i]].y / 2;
	sector->nb_sprites[i]++;
	if (set_camera_sprites_array(&env->player.camera, sector->num,
		i, env))
		return (-1);
	ft_printf("%d holes\n", sector->nb_sprites[i]);
	return (0);
}
