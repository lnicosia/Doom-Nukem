/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid_walls_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 16:22:58 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 17:30:43 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw.h"
#include "draw_grid_walls.h"

void		draw_current_sector_last_wall(t_point v1, t_point v2, t_env *env)
{
	v2.x = env->sdl.mx;
	v2.y = env->sdl.my;
	draw_line(v1, v2, env, 0xFFFFFF00);
}

void		draw_grid_current_sector(t_env *env)
{
	t_list		*tmp;
	t_vertex	*v;
	t_point		v1;
	t_point		v2;

	tmp = env->editor.current_vertices;
	if (!tmp)
		return ;
	v = (t_vertex*)tmp->content;
	v1.x = env->editor.center.x + v->x * env->editor.scale;
	v1.y = env->editor.center.y + v->y * env->editor.scale;
	tmp = tmp->next;
	while (tmp)
	{
		v = (t_vertex*)tmp->content;
		v2.x = env->editor.center.x + v->x * env->editor.scale;
		v2.y = env->editor.center.y + v->y * env->editor.scale;
		draw_line(v1, v2, env, 0xFFFFFF00);
		v1 = v2;
		tmp = tmp->next;
	}
	if (env->drawing)
		draw_current_sector_last_wall(v1, v2, env);
}

TTF_Font	*get_correct_font(int size, t_env *env)
{
	if (size == 10)
		return (env->sdl.fonts.lato_black10);
	else if (size == 15)
		return (env->sdl.fonts.lato_black15);
	else if (size == 20)
		return (env->sdl.fonts.lato_black20);
	else if (size == 25)
		return (env->sdl.fonts.lato_black25);
	else if (size == 30)
		return (env->sdl.fonts.lato_black30);
	else if (size == 35)
		return (env->sdl.fonts.lato_black35);
	else if (size == 40)
		return (env->sdl.fonts.lato_black40);
	else if (size == 45)
		return (env->sdl.fonts.lato_black45);
	else
		return (env->sdl.fonts.lato_black50);
}
