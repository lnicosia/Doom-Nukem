/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:56:00 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/09 10:30:27 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	draw_minimap_player_game3(t_point p0, t_point p1,
t_env *env)
{
	p0.x = env->player.camera.angle_cos * env->player.camera.near_z
	* env->options.minimap_scale + env->minimap_pos.x;
	p0.y = env->player.camera.angle_sin * env->player.camera.near_z
	* env->options.minimap_scale + env->minimap_pos.y;
	p1.x = p0.x + env->player.camera.perp_cos * env->w
	* env->options.minimap_scale;
	p1.y = p0.y + env->player.camera.perp_sin * env->w
	* env->options.minimap_scale;
	p0.x = p0.x - env->player.camera.perp_cos * env->w
	* env->options.minimap_scale;
	p0.y = p0.y - env->player.camera.perp_sin * env->w
	* env->options.minimap_scale;
	p0.x = env->minimap_pos.x;
	p0.y = env->minimap_pos.y;
	p1.x = env->player.camera.angle_cos * env->player.camera.near_z
	* env->options.minimap_scale + p0.x;
	p1.y = env->player.camera.angle_sin * env->player.camera.near_z
	* env->options.minimap_scale + p0.y;
	draw_line_minimap(p0, p1, env, 0xFFFFFFFF);
}

void	draw_minimap_player_game2(t_v3 triangle[3], t_env *env)
{
	t_point	p0;
	t_point	p1;

	fill_triangle_minimap(triangle, env);
	p0.x = triangle[2].x;
	p0.y = triangle[2].y;
	p1.x = triangle[1].x;
	p1.y = triangle[1].y;
	draw_line_minimap(p0, p1, env, 0xFFFFFF00);
	triangle[2] = new_v3(
		(env->player.camera.angle_cos * env->player.camera.far_z
		- env->player.camera.angle_sin * env->player.camera.far_right)
		* env->options.minimap_scale + env->minimap_pos.x,
		(env->player.camera.angle_sin * env->player.camera.far_z
		+ env->player.camera.angle_cos * env->player.camera.far_right)
		* env->options.minimap_scale + env->minimap_pos.y, 0);
	fill_triangle_minimap(triangle, env);
	p0.x = triangle[0].x;
	p0.y = triangle[0].y;
	p1.x = triangle[2].x;
	p1.y = triangle[2].y;
	draw_line_minimap(p0, p1, env, 0xFFFFFF00);
	draw_minimap_player_game3(p0, p1, env);
}

void	draw_minimap_player_game(t_env *env)
{
	t_v3	triangle[3];

	apply_sprite(env->object_sprites[DOOM_GUY_FACE],
		new_point(env->minimap_pos.y - 7, env->minimap_pos.x - 7),
		new_point(14, 14), env);
	triangle[2] = new_v3(
		(env->player.camera.near_left_pos.x - env->player.pos.x)
		* env->options.minimap_scale + env->minimap_pos.x,
		(env->player.camera.near_left_pos.y - env->player.pos.y)
		* env->options.minimap_scale + env->minimap_pos.y, 0);
	triangle[1] = new_v3(
		(env->player.camera.angle_cos * env->player.camera.far_z
		- env->player.camera.angle_sin * env->player.camera.far_left)
		* env->options.minimap_scale + env->minimap_pos.x,
		(env->player.camera.angle_sin * env->player.camera.far_z
		+ env->player.camera.angle_cos * env->player.camera.far_left)
		* env->options.minimap_scale + env->minimap_pos.y, 0);
	triangle[0] = new_v3(
		(env->player.camera.near_right_pos.x - env->player.pos.x)
		* env->options.minimap_scale + env->minimap_pos.x,
		(env->player.camera.near_right_pos.y - env->player.pos.y)
		* env->options.minimap_scale + env->minimap_pos.y, 0);
	draw_minimap_player_game2(triangle, env);
}

void	draw_current_wall_game_minimap(int v, t_sector *sect, t_env *env)
{
	t_line		line;

	if (sect->neighbors[v] == -1)
	{
		line.p0.x = env->minimap_pos.x + (env->vertices[sect->vertices[v]].x
		- env->player.pos.x) * env->options.minimap_scale;
		line.p0.y = env->minimap_pos.y + (env->vertices[sect->vertices[v]].y
		- env->player.pos.y) * env->options.minimap_scale;
		line.p1.x = env->minimap_pos.x + (env->vertices[sect->vertices[v + 1]].x
		- env->player.pos.x) * env->options.minimap_scale;
		line.p1.y = env->minimap_pos.y + (env->vertices[sect->vertices[v + 1]].y
		- env->player.pos.y) * env->options.minimap_scale;
		draw_line_minimap(line.p0, line.p1, env, 0xFFFFFFFF);
	}
}

void	game_minimap(t_env *env)
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
		while (v < sect->nb_vertices)
		{
		  	draw_current_wall_game_minimap(v, sect, env);
			v++;
		}
		s++;
	}
	draw_minimap_player_game(env);
}
