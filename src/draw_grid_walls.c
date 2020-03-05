/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:25:43 by sipatry           #+#    #+#             */
/*   Updated: 2020/03/05 10:13:25 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	draw_grid_current_sector(t_env *env)
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
		draw_line(v1, v2, *env, 0xFFFFFF00);
		v1 = v2;
		tmp = tmp->next;
	}
	if (env->drawing)
	{
		v2.x = env->sdl.mx;
		v2.y = env->sdl.my;
		draw_line(v1, v2, *env, 0xFFFFFF00);
	}
	return ;
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

int		count_sector_angles(t_sector *sector, t_env *env)
{
	int		i;
	int		count;
	t_point	v[3];

	i = 0;
	v[0] = new_point(0, 0);
	v[1] = new_point(0, 0);
	v[2] = new_point(0, 0);
	count = 0;
	while (i < sector->nb_vertices - 1)
	{
		v[0].x = env->vertices[sector->vertices[i]].x;
		v[0].y = env->vertices[sector->vertices[i]].y;
		v[1].x = env->vertices[sector->vertices[i + 1]].x;
		v[1].y = env->vertices[sector->vertices[i + 1]].y;
		v[2].x = env->vertices[sector->vertices[i + 2]].x;
		v[2].y = env->vertices[sector->vertices[i + 2]].y;
		if (get_angle(v))
			count++;
		i++;
	}
	v[0].x = env->vertices[sector->vertices[i]].x;
	v[0].y = env->vertices[sector->vertices[i]].y;
	v[1].x = env->vertices[sector->vertices[0]].x;
	v[1].y = env->vertices[sector->vertices[0]].y;
	v[2].x = env->vertices[sector->vertices[1]].x;
	v[2].y = env->vertices[sector->vertices[1]].y;
	if (get_angle(v))
		count++;
	return (count);
}

void	draw_grid_sector(t_sector sector, Uint32 color, t_env *env)
{
	int			i;
	int			font_size;
	int			nb_angles;
	t_point		v[3];
	t_point		center;
	t_point		text_size;
	Uint32		c;

	i = 0;
	center = new_point(0, 0);
	nb_angles = 0;
	//ft_printf("drawing sector %d\n", sector.num);
	//ft_printf("%d vertices\n", sector.nb_vertices);
	while (i < sector.nb_vertices - 1)
	{
		v[0].x = env->editor.center.x +
			env->vertices[sector.vertices[i]].x * env->editor.scale;
		v[0].y = env->editor.center.y +
			env->vertices[sector.vertices[i]].y * env->editor.scale;
		v[1].x = env->editor.center.x +
			env->vertices[sector.vertices[i + 1]].x * env->editor.scale;
		v[1].y = env->editor.center.y +
			env->vertices[sector.vertices[i + 1]].y * env->editor.scale;
		v[2].x = env->editor.center.x +
		env->vertices[sector.vertices[i + 2]].x * env->editor.scale;
		v[2].y = env->editor.center.y +
		env->vertices[sector.vertices[i + 2]].y * env->editor.scale;
		if (get_angle(v))
		{
			center.x += v[1].x;
			center.y += v[1].y;
			nb_angles++;
		}
		if (sector.neighbors[i] == -1)
			c = color;
		else
			c = 0xFFFF0000;
		draw_line(v[0], v[1], *env, c);
		i++;
	}
	v[0].x = env->editor.center.x +
		env->vertices[sector.vertices[i]].x * env->editor.scale;
	v[0].y = env->editor.center.y +
		env->vertices[sector.vertices[i]].y * env->editor.scale;
	v[1].x = env->editor.center.x +
		env->vertices[sector.vertices[0]].x * env->editor.scale;
	v[1].y = env->editor.center.y +
		env->vertices[sector.vertices[0]].y * env->editor.scale;
	v[2].x = env->editor.center.x +
	env->vertices[sector.vertices[1]].x * env->editor.scale;
	v[2].y = env->editor.center.y +
	env->vertices[sector.vertices[1]].y * env->editor.scale;
	if (get_angle(v))
	{
		center.x += v[1].x;
		center.y += v[1].y;
		nb_angles++;
	}
	if (sector.neighbors[i] == -1)
		c = color;
	else
		c = 0xFFFF0000;
	draw_line(v[0], v[1], *env, c);
	//center.x += v2.x;
	//center.y += v2.y;
	center.x /= nb_angles;
	center.y /= nb_angles;
	font_size = env->editor.scale * 2;
	if (env->editor.selected_sector == sector.num)
		color = 0x00FF00FF;
	else
		color = 0xFFFFFFFF;
	while (font_size % 5 != 0)
		font_size++;
	font_size = ft_clamp(font_size, 10, 50);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%d", sector.num);
	TTF_SizeText(get_correct_font(font_size, env), env->snprintf,
			&text_size.x, &text_size.y);
	print_text(new_point(center.y - text_size.y / 2,
	center.x - text_size.x / 2), new_printable_text(env->snprintf,
	get_correct_font(font_size, env), color, 0), env);
}

void	draw_grid_sectors(t_env *env)
{
	int	i;

	i = 0;
	if (!env->editor.player_exist && env->nb_sectors == 1)
		add_player(env);
	while (i < env->nb_sectors)
	{
		if (i == env->editor.selected_sector)
			draw_grid_sector(env->sectors[i], 0xFF00FF00, env);
		else
			draw_grid_sector(env->sectors[i], 0xFFFFFFFF, env);
		i++;
	}
}
