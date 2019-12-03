/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_bullet_hole.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 11:53:44 by lnicosia          #+#    #+#             */
/*   Updated: 2019/12/02 15:51:57 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "wall_sprite_remover.h"

int		add_floor_bullet_hole(t_sector *sector, t_projectile *projectile,
t_env *env)
{
	t_floor_sprite_remover	*param;

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
	if (!(sector->floor_sprites_scale =
				(t_v2*)ft_realloc(sector->floor_sprites_scale,
					sizeof(t_v2) * sector->nb_floor_sprites,
					sizeof(t_v2) * (sector->nb_floor_sprites + 1))))
		return (ft_perror("could not realloc floor sprites scale"));
	sector->floor_sprites.sprite[sector->nb_floor_sprites] = 3;
	sector->floor_sprites.scale[sector->nb_floor_sprites] = new_v2(0.4, 0.4);
	sector->floor_sprites.pos[sector->nb_floor_sprites] =
	get_floor_bullet_hole_pos(sector, projectile, env);
	sector->floor_sprites.pos[sector->nb_floor_sprites].x -=
	sector->floor_sprites.scale[sector->nb_floor_sprites].x / 2;
	sector->floor_sprites.pos[sector->nb_floor_sprites].y -=
	sector->floor_sprites.scale[sector->nb_floor_sprites].y / 2;
	sector->floor_sprites_scale[sector->nb_floor_sprites].x =
	env->wall_sprites[sector->floor_sprites
	.sprite[sector->nb_floor_sprites]].size[0].x /
	sector->floor_sprites.scale[sector->nb_floor_sprites].x;
	sector->floor_sprites_scale[sector->nb_floor_sprites].y =
	env->wall_sprites[sector->floor_sprites
	.sprite[sector->nb_floor_sprites]].size[0].y /
	sector->floor_sprites.scale[sector->nb_floor_sprites].y;
	sector->nb_floor_sprites++;
	if (!(env->floor_bullet_holes_events
		= (t_event*)ft_realloc(env->floor_bullet_holes_events,
		sizeof(t_event) * env->nb_floor_bullet_holes_events,
		sizeof(t_event) * (env->nb_floor_bullet_holes_events + 1))))
		return (ft_perror("Could not realloc bullet_holes events"
		"to make bullet hole fade"));
	if (!(param = (t_floor_sprite_remover*)malloc(sizeof(*param))))
		return (ft_perror("Could not malloc wall sprite remover"));
	param->sector = sector->num;
	param->sprite = sector->nb_floor_sprites - 1;
	env->floor_bullet_holes_events[env->nb_floor_bullet_holes_events]
	= new_func_event(&delete_floor_bullet_hole, param);
	env->floor_bullet_holes_events[env->nb_floor_bullet_holes_events].max_uses
	= 1;
	env->floor_bullet_holes_events[env->nb_floor_bullet_holes_events].delay
	= 5000;
	env->nb_floor_bullet_holes_events++;
	return (0);
}

int		add_ceiling_bullet_hole(t_sector *sector, t_projectile *projectile,
t_env *env)
{
	t_floor_sprite_remover	*param;

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
		return (ft_perror("could not realloc ceiling sprites scale"));
	if (!(sector->ceiling_sprites_scale =
				(t_v2*)ft_realloc(sector->ceiling_sprites_scale,
					sizeof(t_v2) * sector->nb_ceiling_sprites,
					sizeof(t_v2) * (sector->nb_ceiling_sprites + 1))))
		return (ft_perror("could not realloc ceiling sprites scale"));
	sector->ceiling_sprites.sprite[sector->nb_ceiling_sprites] = 3;
	sector->ceiling_sprites.scale[sector->nb_ceiling_sprites] = new_v2(0.4,
	0.4);
	sector->ceiling_sprites.pos[sector->nb_ceiling_sprites] =
	get_ceiling_bullet_hole_pos(sector, projectile, env);
	sector->ceiling_sprites.pos[sector->nb_ceiling_sprites].x -=
	sector->ceiling_sprites.scale[sector->nb_ceiling_sprites].x / 2;
	sector->ceiling_sprites.pos[sector->nb_ceiling_sprites].y -=
	sector->ceiling_sprites.scale[sector->nb_ceiling_sprites].y / 2;
	sector->ceiling_sprites_scale[sector->nb_ceiling_sprites].x =
	env->wall_sprites[sector->ceiling_sprites
	.sprite[sector->nb_ceiling_sprites]].size[0].x /
	sector->ceiling_sprites.scale[sector->nb_ceiling_sprites].x;
	sector->ceiling_sprites_scale[sector->nb_ceiling_sprites].y =
	env->wall_sprites[sector->ceiling_sprites
	.sprite[sector->nb_ceiling_sprites]].size[0].y /
	sector->ceiling_sprites.scale[sector->nb_ceiling_sprites].y;
	sector->nb_ceiling_sprites++;
	if (!(env->ceiling_bullet_holes_events
		= (t_event*)ft_realloc(env->ceiling_bullet_holes_events,
		sizeof(t_event) * env->nb_ceiling_bullet_holes_events,
		sizeof(t_event) * (env->nb_ceiling_bullet_holes_events + 1))))
		return (ft_perror("Could not realloc bullet_holes events"
		"to make bullet hole fade"));
	if (!(param = (t_floor_sprite_remover*)malloc(sizeof(*param))))
		return (ft_perror("Could not malloc wall sprite remover"));
	param->sector = sector->num;
	param->sprite = sector->nb_ceiling_sprites - 1;
	env->ceiling_bullet_holes_events[env->nb_ceiling_bullet_holes_events]
	= new_func_event(&delete_ceiling_bullet_hole, param);
	env->ceiling_bullet_holes_events[env->nb_ceiling_bullet_holes_events]
	.max_uses = 1;
	env->ceiling_bullet_holes_events[env->nb_ceiling_bullet_holes_events].delay
	= 5000;
	env->nb_ceiling_bullet_holes_events++;
	return (0);
}

int		add_wall_bullet_hole(t_sector *sector, t_projectile *projectile,
int i, t_env *env)
{
	t_wall_sprite_remover	*param;

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
	if (!(env->wall_bullet_holes_events
		= (t_event*)ft_realloc(env->wall_bullet_holes_events,
		sizeof(t_event) * env->nb_wall_bullet_holes_events,
		sizeof(t_event) * (env->nb_wall_bullet_holes_events + 1))))
		return (ft_perror("Could not realloc bullet_holes events"
		"to make bullet hole fade"));
	if (!(param = (t_wall_sprite_remover*)malloc(sizeof(*param))))
		return (ft_perror("Could not malloc wall sprite remover"));
	param->sector = sector->num;
	param->wall = i;
	param->sprite = sector->nb_sprites[i] - 1;
	env->wall_bullet_holes_events[env->nb_wall_bullet_holes_events]
	= new_func_event(&delete_wall_bullet_hole, param);
	env->wall_bullet_holes_events[env->nb_wall_bullet_holes_events].max_uses
	= 1;
	env->wall_bullet_holes_events[env->nb_wall_bullet_holes_events].delay
	= 5000;
	env->nb_wall_bullet_holes_events++;
	return (0);
}
