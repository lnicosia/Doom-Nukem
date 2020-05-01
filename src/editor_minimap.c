/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:56:00 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 18:42:55 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw_grid_walls.h"
#include "draw.h"

void	draw_enemy_minimap(int i, t_enemy *enemy, t_sprite *sprite, t_env *env)
{
	t_point	pos;
	t_point	size;

	if (!enemy->exists)
		return ;
	sprite = &env->enemy_sprites[enemy->sprite];
	size = new_point(6 * env->options.minimap_scale,
		6 * env->options.minimap_scale / (sprite->size[0].x
			/ (double)sprite->size[0].y));
	pos.y = env->minimap_pos.x + (enemy->pos.x - env->player.pos.x)
		* env->options.minimap_scale - size.y / 2;
	pos.x = env->minimap_pos.y + (enemy->pos.y - env->player.pos.y)
		* env->options.minimap_scale - size.x / 2;
	if (pos.y < env->minimap_pos.x - env->minimap_size.y / 2
		|| pos.y + size.y > env->minimap_pos.x + env->minimap_size.x / 2
		|| pos.x < env->minimap_pos.y - env->minimap_size.y / 2
		|| pos.x + size.x > env->minimap_pos.y + env->minimap_size.y / 2)
		return ;
	if (env->selected_enemy == i)
		apply_sprite_selected(*sprite, pos, size, env);
	else
		apply_sprite(*sprite, pos, size, env);
}

void	draw_enemies_minimap(t_env *env)
{
	int			i;

	i = -1;
	while (++i < env->nb_enemies)
	{
		draw_enemy_minimap(i, &env->enemies[i],
		&env->enemy_sprites[env->enemies[i].sprite], env);
	}
}

void	draw_current_wall_minimap(int v, int s, t_sector *sect, t_env *env)
{
	t_line		line;

	if (sect->neighbors[v] != -1)
		line.color = 0xFFFF0000;
	else if (s == env->player.sector)
		line.color = 0xFF00FF00;
	else
		line.color = 0xFFFFFFFF;
	line.p0.x = env->minimap_pos.x + (env->vertices[sect->vertices[v]].x
	- env->player.pos.x) * env->options.minimap_scale;
	line.p0.y = env->minimap_pos.y + (env->vertices[sect->vertices[v]].y
	- env->player.pos.y) * env->options.minimap_scale;
	line.p1.x = env->minimap_pos.x + (env->vertices[sect->vertices[v + 1]].x
	- env->player.pos.x) * env->options.minimap_scale;
	line.p1.y = env->minimap_pos.y + (env->vertices[sect->vertices[v + 1]].y
	- env->player.pos.y) * env->options.minimap_scale;
	draw_line_minimap(line.p0, line.p1, env, line.color);
}

void	editor_minimap(t_env *env)
{
	int			s;
	int			v;
	t_sector	*sect;

	s = 0;
	draw_minimap_hud(env);
	while (s < env->nb_sectors)
	{
		sect = &env->sectors[s];
		v = 0;
		draw_minimap_sector_num(env, sect);
		while (v < sect->nb_vertices)
		{
			draw_current_wall_minimap(v, s, sect, env);
			v++;
		}
		s++;
	}
	draw_objects_minimap(env);
	draw_enemies_minimap(env);
	draw_minimap_player(env);
}
