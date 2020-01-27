/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_bullet_hole.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 11:53:44 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/27 18:47:54 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "wall_sprite_remover.h"

int		add_floor_bullet_hole(t_sector *sector, t_projectile *projectile,
		t_env *env)
{
	t_floor_sprite_remover	*param;

	if (!(sector->floor_sprites.sprite =
				(int*)ft_realloc(sector->floor_sprites.sprite,
					sizeof(int) * sector->floor_sprites.nb_sprites,
					sizeof(int) * (sector->floor_sprites.nb_sprites + 1))))
		return (ft_perror("Could not realloc floor sprites indexes"));
	if (!(sector->floor_sprites.pos =
				(t_v2*)ft_realloc(sector->floor_sprites.pos,
					sizeof(t_v2) * sector->floor_sprites.nb_sprites,
					sizeof(t_v2) * (sector->floor_sprites.nb_sprites + 1))))
		return (ft_perror("Could not realloc floor sprites pos"));
	if (!(sector->floor_sprites.scale =
				(t_v2*)ft_realloc(sector->floor_sprites.scale,
					sizeof(t_v2) * sector->floor_sprites.nb_sprites,
					sizeof(t_v2) * (sector->floor_sprites.nb_sprites + 1))))
		return (ft_perror("Could not realloc floor sprites scale"));
	if (!(sector->floor_sprites_scale =
				(t_v2*)ft_realloc(sector->floor_sprites_scale,
					sizeof(t_v2) * sector->floor_sprites.nb_sprites,
					sizeof(t_v2) * (sector->floor_sprites.nb_sprites + 1))))
		return (ft_perror("could not realloc floor sprites scale"));
	sector->floor_sprites.sprite[sector->floor_sprites.nb_sprites] = BULLET_HOLE;
	sector->floor_sprites.scale[sector->floor_sprites.nb_sprites] = new_v2(0.4, 0.4);
	sector->floor_sprites.pos[sector->floor_sprites.nb_sprites] =
		get_floor_bullet_hole_pos(sector, projectile, env);
	sector->floor_sprites.pos[sector->floor_sprites.nb_sprites].x -=
		sector->floor_sprites.scale[sector->floor_sprites.nb_sprites].x / 2;
	sector->floor_sprites.pos[sector->floor_sprites.nb_sprites].y -=
		sector->floor_sprites.scale[sector->floor_sprites.nb_sprites].y / 2;
	sector->floor_sprites_scale[sector->floor_sprites.nb_sprites].x =
		env->object_sprites[sector->floor_sprites
		.sprite[sector->floor_sprites.nb_sprites]].size[0].x /
		sector->floor_sprites.scale[sector->floor_sprites.nb_sprites].x;
	sector->floor_sprites_scale[sector->floor_sprites.nb_sprites].y =
		env->object_sprites[sector->floor_sprites
		.sprite[sector->floor_sprites.nb_sprites]].size[0].y /
		sector->floor_sprites.scale[sector->floor_sprites.nb_sprites].y;
	sector->floor_sprites.nb_sprites++;
	if (!(env->floor_bullet_holes_events
				= (t_event*)ft_realloc(env->floor_bullet_holes_events,
					sizeof(t_event) * env->nb_floor_bullet_holes_events,
					sizeof(t_event) * (env->nb_floor_bullet_holes_events + 1))))
		return (ft_perror("Could not realloc bullet_holes events"
					"to make bullet hole fade"));
	if (!(param = (t_floor_sprite_remover*)ft_memalloc(sizeof(*param))))
		return (ft_perror("Could not malloc wall sprite remover"));
	param->sector = sector->num;
	param->sprite = sector->floor_sprites.nb_sprites - 1;
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
				(int*)ft_realloc(sector->ceiling_sprites.sprite,
					sizeof(int) * sector->ceiling_sprites.nb_sprites,
					sizeof(int) * (sector->ceiling_sprites.nb_sprites + 1))))
		return (ft_perror("Could not realloc ceiling sprites indexes"));
	if (!(sector->ceiling_sprites.pos =
				(t_v2*)ft_realloc(sector->ceiling_sprites.pos,
					sizeof(t_v2) * sector->ceiling_sprites.nb_sprites,
					sizeof(t_v2) * (sector->ceiling_sprites.nb_sprites + 1))))
		return (ft_perror("Could not realloc ceiling sprites pos"));
	if (!(sector->ceiling_sprites.scale =
				(t_v2*)ft_realloc(sector->ceiling_sprites.scale,
					sizeof(t_v2) * sector->ceiling_sprites.nb_sprites,
					sizeof(t_v2) * (sector->ceiling_sprites.nb_sprites + 1))))
		return (ft_perror("could not realloc ceiling sprites scale"));
	if (!(sector->ceiling_sprites_scale =
				(t_v2*)ft_realloc(sector->ceiling_sprites_scale,
					sizeof(t_v2) * sector->ceiling_sprites.nb_sprites,
					sizeof(t_v2) * (sector->ceiling_sprites.nb_sprites + 1))))
		return (ft_perror("could not realloc ceiling sprites scale"));
	sector->ceiling_sprites.sprite[sector->ceiling_sprites.nb_sprites] = BULLET_HOLE;
	sector->ceiling_sprites.scale[sector->ceiling_sprites.nb_sprites] = new_v2(0.4,
			0.4);
	sector->ceiling_sprites.pos[sector->ceiling_sprites.nb_sprites] =
		get_ceiling_bullet_hole_pos(sector, projectile, env);
	sector->ceiling_sprites.pos[sector->ceiling_sprites.nb_sprites].x -=
		sector->ceiling_sprites.scale[sector->ceiling_sprites.nb_sprites].x / 2;
	sector->ceiling_sprites.pos[sector->ceiling_sprites.nb_sprites].y -=
		sector->ceiling_sprites.scale[sector->ceiling_sprites.nb_sprites].y / 2;
	sector->ceiling_sprites_scale[sector->ceiling_sprites.nb_sprites].x =
		env->object_sprites[sector->ceiling_sprites
		.sprite[sector->ceiling_sprites.nb_sprites]].size[0].x /
		sector->ceiling_sprites.scale[sector->ceiling_sprites.nb_sprites].x;
	sector->ceiling_sprites_scale[sector->ceiling_sprites.nb_sprites].y =
		env->object_sprites[sector->ceiling_sprites
		.sprite[sector->ceiling_sprites.nb_sprites]].size[0].y /
		sector->ceiling_sprites.scale[sector->ceiling_sprites.nb_sprites].y;
	sector->ceiling_sprites.nb_sprites++;
	if (!(env->ceiling_bullet_holes_events
				= (t_event*)ft_realloc(env->ceiling_bullet_holes_events,
					sizeof(t_event) * env->nb_ceiling_bullet_holes_events,
					sizeof(t_event) * (env->nb_ceiling_bullet_holes_events + 1))))
		return (ft_perror("Could not realloc bullet_holes events"
					"to make bullet hole fade"));
	if (!(param = (t_floor_sprite_remover*)ft_memalloc(sizeof(*param))))
		return (ft_perror("Could not malloc wall sprite remover"));
	param->sector = sector->num;
	param->sprite = sector->ceiling_sprites.nb_sprites - 1;
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
	/*t_wall_sprite_remover	*param;

	if (!(sector->wall_sprites[i].sprite =
				(int*)ft_realloc(sector->wall_sprites[i].sprite,
					sizeof(int) * sector->wall_sprites[i].nb_sprites,
					sizeof(int) * (sector->wall_sprites[i].nb_sprites + 1))))
		return (ft_perror("Could not realloc wall sprites indexes"));
	if (!(sector->wall_sprites[i].pos =
				(t_v2*)ft_realloc(sector->wall_sprites[i].pos,
					sizeof(t_v2) * sector->wall_sprites[i].nb_sprites,
					sizeof(t_v2) * (sector->wall_sprites[i].nb_sprites + 1))))
		return (ft_perror("Could not realloc wall sprites pos"));
	if (!(sector->wall_sprites[i].scale =
				(t_v2*)ft_realloc(sector->wall_sprites[i].scale,
					sizeof(t_v2) * sector->wall_sprites[i].nb_sprites,
					sizeof(t_v2) * (sector->wall_sprites[i].nb_sprites + 1))))
		return (ft_perror("Could not realloc wall sprites scale"));
	if (!(sector->wall_sprites[i].nb_press_events =
				(size_t*)ft_realloc(sector->wall_sprites[i].nb_press_events,
					sizeof(size_t) * sector->wall_sprites[i].nb_sprites,
					sizeof(size_t) * (sector->wall_sprites[i].nb_sprites + 1))))
		return (ft_perror("Could not realloc wall sprites press events count"));
	if (!(sector->wall_sprites[i].nb_shoot_events =
				(size_t*)ft_realloc(sector->wall_sprites[i].nb_shoot_events,
					sizeof(size_t) * sector->wall_sprites[i].nb_sprites,
					sizeof(size_t) * (sector->wall_sprites[i].nb_sprites + 1))))
		return (ft_perror("Could not realloc wall sprites shoot events count"));
	if (!(sector->wall_sprites[i].press_events =
				(t_event**)ft_realloc(sector->wall_sprites[i].press_events,
					sizeof(t_event*) * sector->wall_sprites[i].nb_sprites,
					sizeof(t_event*) * (sector->wall_sprites[i].nb_sprites + 1))))
		return (ft_perror("Could not realloc wall sprites press events"));
	if (!(sector->wall_sprites[i].shoot_events =
				(t_event**)ft_realloc(sector->wall_sprites[i].shoot_events,
					sizeof(t_event*) * sector->wall_sprites[i].nb_sprites,
					sizeof(t_event*) * (sector->wall_sprites[i].nb_sprites + 1))))
		return (ft_perror("Could not realloc wall sprites shoot events"));
	sector->wall_sprites[i].sprite[sector->wall_sprites[i].nb_sprites] = 3;
	sector->wall_sprites[i].scale[sector->wall_sprites[i].nb_sprites] = new_v2(0.4, 0.4);
	sector->wall_sprites[i].pos[sector->wall_sprites[i].nb_sprites] =
		get_wall_bullet_hole_pos(sector, projectile, i, env);
	sector->wall_sprites[i].pos[sector->wall_sprites[i].nb_sprites].x -=
		sector->wall_sprites[i].scale[sector->wall_sprites[i].nb_sprites].x / 2;
	sector->wall_sprites[i].pos[sector->wall_sprites[i].nb_sprites].y -=
		sector->wall_sprites[i].scale[sector->wall_sprites[i].nb_sprites].y / 2;
	sector->wall_sprites[i].nb_sprites++;
	if (set_camera_sprites_array(&env->player.camera, sector->num,
				i, env))
		return (-1);
	if (!(env->wall_bullet_holes_events
				= (t_event*)ft_realloc(env->wall_bullet_holes_events,
					sizeof(t_event) * env->nb_wall_bullet_holes_events,
					sizeof(t_event) * (env->nb_wall_bullet_holes_events + 1))))
		return (ft_perror("Could not realloc bullet_holes events"
					"to make bullet hole fade"));
	if (!(param = (t_wall_sprite_remover*)ft_memalloc(sizeof(*param))))
		return (ft_perror("Could not malloc wall sprite remover"));
	param->sector = sector->num;
	param->wall = i;
	param->sprite = sector->wall_sprites[i].nb_sprites - 1;
	env->wall_bullet_holes_events[env->nb_wall_bullet_holes_events]
		= new_func_event(&delete_wall_bullet_hole, param);
	env->wall_bullet_holes_events[env->nb_wall_bullet_holes_events].max_uses
		= 1;
	env->wall_bullet_holes_events[env->nb_wall_bullet_holes_events].delay
		= 5000;
	env->nb_wall_bullet_holes_events++;*/
	t_list					*new;
	t_wall_sprite_remover	*param;
	t_bullet_hole			bullet_hole;

	bullet_hole.pos =
		get_wall_bullet_hole_pos(sector, projectile, i, env);
	bullet_hole.pos.x -= 0.2;
	bullet_hole.pos.y -= 0.2;
	if (!(new = ft_lstnew(&bullet_hole, sizeof(t_bullet_hole))))
		return (ft_perror("Could not malloc new bullet hole"));
	ft_lstpushback(&sector->wall_bullet_holes[i], new);
	if (!(env->wall_bullet_holes_events
				= (t_event*)ft_realloc(env->wall_bullet_holes_events,
					sizeof(t_event) * env->nb_wall_bullet_holes_events,
					sizeof(t_event) * (env->nb_wall_bullet_holes_events + 1))))
		return (ft_perror("Could not realloc bullet_holes events"
					"to make bullet hole fade"));
	if (!(param = (t_wall_sprite_remover*)ft_memalloc(sizeof(*param))))
		return (ft_perror("Could not malloc wall sprite remover"));
	param->sector = sector->num;
	param->wall = i;
	env->wall_bullet_holes_events[env->nb_wall_bullet_holes_events]
		= new_func_event(&delete_wall_bullet_hole, param);
	env->wall_bullet_holes_events[env->nb_wall_bullet_holes_events].max_uses
		= 1;
	env->wall_bullet_holes_events[env->nb_wall_bullet_holes_events].delay
		= 5000;
	env->nb_wall_bullet_holes_events++;
	return (0);
}
