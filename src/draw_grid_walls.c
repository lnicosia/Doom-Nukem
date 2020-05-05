/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:25:43 by sipatry           #+#    #+#             */
/*   Updated: 2020/04/29 16:22:47 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw_grid_walls.h"
#include "draw.h"

void	draw_current_wall(int i, t_grid_wall_drawer *drawer, t_env *env)
{
	drawer->v[0].x = env->editor.center.x +
		env->vertices[drawer->sector->vertices[i]].x * env->editor.scale;
	drawer->v[0].y = env->editor.center.y +
		env->vertices[drawer->sector->vertices[i]].y * env->editor.scale;
	drawer->v[1].x = env->editor.center.x +
		env->vertices[drawer->sector->vertices[i + 1]].x * env->editor.scale;
	drawer->v[1].y = env->editor.center.y +
		env->vertices[drawer->sector->vertices[i + 1]].y * env->editor.scale;
	drawer->v[2].x = env->editor.center.x +
	env->vertices[drawer->sector->vertices[i + 2]].x * env->editor.scale;
	drawer->v[2].y = env->editor.center.y +
	env->vertices[drawer->sector->vertices[i + 2]].y * env->editor.scale;
	if (get_angle(drawer->v))
	{
		drawer->center.x += drawer->v[1].x;
		drawer->center.y += drawer->v[1].y;
		drawer->nb_angles++;
	}
	if (drawer->sector->neighbors[i] == -1)
		draw_line(drawer->v[0], drawer->v[1], env, drawer->color);
	else
		draw_line(drawer->v[0], drawer->v[1], env, 0xFFFF0000);
}

void	draw_last_wall(int i, t_grid_wall_drawer *drawer, t_env *env)
{
	drawer->v[0].x = env->editor.center.x +
		env->vertices[drawer->sector->vertices[i]].x * env->editor.scale;
	drawer->v[0].y = env->editor.center.y +
		env->vertices[drawer->sector->vertices[i]].y * env->editor.scale;
	drawer->v[1].x = env->editor.center.x +
		env->vertices[drawer->sector->vertices[0]].x * env->editor.scale;
	drawer->v[1].y = env->editor.center.y +
		env->vertices[drawer->sector->vertices[0]].y * env->editor.scale;
	drawer->v[2].x = env->editor.center.x +
	env->vertices[drawer->sector->vertices[1]].x * env->editor.scale;
	drawer->v[2].y = env->editor.center.y +
	env->vertices[drawer->sector->vertices[1]].y * env->editor.scale;
	if (get_angle(drawer->v))
	{
		drawer->center.x += drawer->v[1].x;
		drawer->center.y += drawer->v[1].y;
		drawer->nb_angles++;
	}
	if (drawer->sector->neighbors[i] == -1)
		draw_line(drawer->v[0], drawer->v[1], env, drawer->color);
	else
		draw_line(drawer->v[0], drawer->v[1], env, 0xFFFF0000);
}

int		draw_sector_num(t_grid_wall_drawer *drawer, t_env *env)
{
	if (env->editor.selected_sector == drawer->sector->num)
		drawer->color = 0x00FF00FF;
	else
		drawer->color = 0xFFFFFFFF;
	while (drawer->font_size % 5 != 0)
		drawer->font_size++;
	drawer->font_size = ft_clamp(drawer->font_size, 10, 50);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%d", drawer->sector->num);
	TTF_SizeText(get_correct_font(drawer->font_size, env), env->snprintf,
			&drawer->text_size.x, &drawer->text_size.y);
	if (print_text(new_point(drawer->center.y - drawer->text_size.y / 2,
	drawer->center.x - drawer->text_size.x / 2), new_printable_text(
	env->snprintf, get_correct_font(drawer->font_size, env), drawer->color, 0),
	env))
		return (-1);
	return (0);
}

int		draw_grid_sector(t_sector *sector, Uint32 color, t_env *env)
{
	t_grid_wall_drawer	drawer;
	int					i;

	i = 0;
	drawer.center = new_point(0, 0);
	drawer.nb_angles = 0;
	drawer.sector = sector;
	drawer.color = color;
	while (i < drawer.sector->nb_vertices - 1)
	{
		draw_current_wall(i, &drawer, env);
		i++;
	}
	draw_last_wall(i, &drawer, env);
	drawer.center.x /= drawer.nb_angles;
	drawer.center.y /= drawer.nb_angles;
	drawer.font_size = env->editor.scale * 2;
	if (draw_sector_num(&drawer, env))
		return (-1);
	return (0);
}

int		draw_grid_sectors(t_env *env)
{
	int	i;

	i = 0;
	if (!env->editor.player_exist && env->nb_sectors == 1)
		add_player(env);
	while (i < env->nb_sectors)
	{
		if (i == env->editor.selected_sector)
		{
			if (draw_grid_sector(&env->sectors[i], 0xFF00FF00, env))
				return (-1);
		}
		else
		{
			if (draw_grid_sector(&env->sectors[i], 0xFFFFFFFF, env))
				return (-1);
		}
		i++;
	}
	return (0);
}
