/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_floor_sprite.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:27:36 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/06 17:18:16 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	free_floor_sprite_events(t_wall_sprites *wall_sprites, int sprite)
{
	if (wall_sprites->nb_shoot_events[sprite] > 0)
		free_events(wall_sprites->shoot_events[sprite],
		wall_sprites->nb_shoot_events[sprite]);
	if (wall_sprites->nb_press_events[sprite] > 0)
		free_events(wall_sprites->press_events[sprite],
		wall_sprites->nb_press_events[sprite]);
}

int		delete_floor_sprite2(t_wall_sprites *wall_sprites, int sprite)
{
	wall_sprites->shoot_events = (t_event**)ft_delindex(
	wall_sprites->shoot_events,
	sizeof(t_event*) * wall_sprites->nb_sprites,
	sizeof(t_event*), sizeof(t_event*) * sprite);
	wall_sprites->press_events = (t_event**)ft_delindex(
	wall_sprites->press_events,
	sizeof(t_event*) * wall_sprites->nb_sprites,
	sizeof(t_event*), sizeof(t_event*) * sprite);
	wall_sprites->nb_shoot_events = (size_t*)ft_delindex(
	wall_sprites->nb_shoot_events,
	sizeof(size_t*) * wall_sprites->nb_sprites,
	sizeof(size_t*), sizeof(size_t*) * sprite);
	wall_sprites->nb_press_events = (size_t*)ft_delindex(
	wall_sprites->nb_press_events,
	sizeof(size_t*) * wall_sprites->nb_sprites,
	sizeof(size_t*), sizeof(size_t*) * sprite);
	wall_sprites->nb_sprites--;
	if (wall_sprites->nb_sprites > 0
		&& (!wall_sprites->sprite || !wall_sprites->pos || !wall_sprites->scale
		|| !wall_sprites->nb_shoot_events || !wall_sprites->nb_press_events
		|| !wall_sprites->shoot_events || !wall_sprites->press_events))
		return (-1);
	return (0);
}

int		delete_floor_sprite(void *param)
{
	t_env			*env;
	t_wall_sprites	*wall_sprites;
	int				sprite;

	env = (t_env*)param;
	sprite = env->selected_floor_sprite;
	wall_sprites = &env->sectors[env->editor.selected_sector].
	floor_sprites;
	env->selected_floor = -1;
	env->selected_floor_sprite = -1;
	free_floor_sprite_events(wall_sprites, sprite);
	wall_sprites->sprite = (int*)ft_delindex(wall_sprites->sprite,
	sizeof(int) * wall_sprites->nb_sprites,
	sizeof(int), sizeof(int) * sprite);
	wall_sprites->pos = (t_v2*)ft_delindex(wall_sprites->pos,
	sizeof(t_v2) * wall_sprites->nb_sprites,
	sizeof(t_v2), sizeof(t_v2) * sprite);
	wall_sprites->scale = (t_v2*)ft_delindex(wall_sprites->scale,
	sizeof(t_v2) * wall_sprites->nb_sprites,
	sizeof(t_v2), sizeof(t_v2) * sprite);
	return (delete_floor_sprite2(wall_sprites, sprite));
}
