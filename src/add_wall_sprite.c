/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_wall_sprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:02:25 by sipatry           #+#    #+#             */
/*   Updated: 2020/04/28 16:22:06 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	update_wall_sprite_arrays3(t_env *env, t_wall_sprites *wall, int index)
{
	if (!(wall->nb_shoot_events = (size_t*)ft_realloc(wall->nb_shoot_events,
	sizeof(size_t) * wall->nb_sprites, sizeof(size_t)
	* (wall->nb_sprites + 1))))
		return (-1);
	if (!(wall->shoot_events = (t_event**)ft_realloc(wall->shoot_events,
	sizeof(t_event *) * wall->nb_sprites, sizeof(t_event*)
	* (wall->nb_sprites + 1))))
		return (-1);
	wall->nb_sprites++;
	if (set_camera_sprites_array(&env->player.camera,
		env->editor.selected_sector, index, env))
		return (-1);
	return (0);
}

int	update_wall_sprite_arrays2(t_env *env, t_wall_sprites *wall,
t_sector *sector, int index)
{
	wall->sprite[wall->nb_sprites] = env->editor.current_sprite;
	if (!(wall->pos = (t_v2*)ft_realloc(wall->pos,
	sizeof(t_v2) * wall->nb_sprites, sizeof(t_v2)
	* (wall->nb_sprites + 1))))
		return (-1);
	wall->pos[wall->nb_sprites].x =
	sector->wall_width[index] / 2 - 1;
	wall->pos[wall->nb_sprites].y =
	sector->ceiling - sector->floor - env->player.eyesight - 1;
	if (!(wall->scale = (t_v2*)ft_realloc(wall->scale,
	sizeof(t_v2) * wall->nb_sprites, sizeof(t_v2)
	* (wall->nb_sprites + 1))))
		return (-1);
	wall->scale[wall->nb_sprites] = new_v2(2, 2);
	if (!(wall->nb_press_events = (size_t*)ft_realloc(wall->nb_press_events,
	sizeof(size_t) * wall->nb_sprites, sizeof(size_t)
	* (wall->nb_sprites + 1))))
		return (-1);
	if (!(wall->press_events = (t_event**)ft_realloc(wall->press_events,
	sizeof(t_event *) * wall->nb_sprites, sizeof(t_event*)
	* (wall->nb_sprites + 1))))
		return (-1);
	return (update_wall_sprite_arrays3(env, wall, index));
}

int	update_wall_sprite_arrays(t_env *env)
{
	t_wall_sprites	*wall;
	t_sector		*sector;
	int				index;

	index = 0;
	wall = NULL;
	sector = NULL;
	if (env->selected_wall_sprite_wall != -1)
	{
		sector = &env->sectors[env->editor.selected_sector];
		wall = &sector->wall_sprites[env->selected_wall_sprite_wall];
		index = env->selected_wall_sprite_wall;
	}
	if (env->editor.selected_wall != -1)
	{
		sector = &env->sectors[env->editor.selected_sector];
		wall = &env->sectors[env->editor.selected_sector].
		wall_sprites[env->editor.selected_wall];
		index = env->editor.selected_wall;
	}
	if (!(wall->sprite = (int*)ft_realloc(wall->sprite,
	sizeof(int) * wall->nb_sprites, sizeof(int) * (wall->nb_sprites + 1))))
		return (-1);
	return (update_wall_sprite_arrays2(env, wall, sector, index));
}
