/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 15:33:44 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/18 11:19:32 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void		reset_clipped(t_env *env)
{
	int			i;
	int			j;
	int			max;

	i = 0;
	max = env->nb_vertices;
	while (i < max)
	{
		env->vertices[i].clipped[0] = 0;
		env->vertices[i].clipped[1] = 0;
		env->vertices[i].clipped_x[0] = env->vertices[i].x;
		env->vertices[i].clipped_x[1] = env->vertices[i].x;
		env->vertices[i].clipped_y[0] = env->vertices[i].y;
		env->vertices[i].clipped_y[1] = env->vertices[i].y;
		i++;
	}
	i = 0;
	while (i < env->nb_sectors)
	{
		j = 0;
		max = env->sectors[i].nb_vertices;
		while (j <= max)
		{
			env->sectors[i].clipped_floors1[j] = env->sectors[i].floors[j];
			env->sectors[i].clipped_ceilings1[j] = env->sectors[i].ceilings[j];
			env->sectors[i].clipped_floors2[j] = env->sectors[i].floors[j];
			env->sectors[i].clipped_ceilings2[j] = env->sectors[i].ceilings[j];
			j++;
		}
		i++;
	}
}

static void	get_intersections(t_render *render, t_env *env)
{
	render->inter_left = get_intersection(
			new_v2(render->vx1, render->vz1),
			new_v2(render->vx2, render->vz2),
			new_v2(env->player.camera.near_left, env->player.camera.near_z),
			new_v2(env->player.camera.far_left, env->player.camera.far_z));
	render->inter_right = get_intersection(
			new_v2(render->vx1, render->vz1),
			new_v2(render->vx2, render->vz2),
			new_v2(env->player.camera.near_right, env->player.camera.near_z),
			new_v2(env->player.camera.far_right, env->player.camera.far_z));
	render->inter_near = get_intersection(
				new_v2(render->vx1, render->vz1),
				new_v2(render->vx2, render->vz2),
				new_v2(env->player.camera.near_left, env->player.camera.near_z),
				new_v2(env->player.camera.near_right, env->player.camera.near_z));
	render->inter_far = get_intersection(
				new_v2(render->vx1, render->vz1),
				new_v2(render->vx2, render->vz2),
				new_v2(env->player.camera.far_left, env->player.camera.far_z),
				new_v2(env->player.camera.far_right, env->player.camera.far_z));
/*	ft_printf("Inter near = [%f, %f]\n", render->inter_near.y, render->inter_near.x);
	ft_printf("Inter far = [%f, %f]\n", render->inter_far.y, render->inter_far.x);
	ft_printf("Inter left = [%f, %f]\n", render->inter_left.y, render->inter_left.x);
	ft_printf("Inter right = [%f, %f]\n", render->inter_right.y, render->inter_right.x);*/
}

int			check_fov(t_render *render, t_env *env)
{
	if ((render->vz1 < env->player.camera.near_z && render->vz2 < env->player.camera.near_z)
			|| (render->vz1 > env->player.camera.far_z && render->vz2 > env->player.camera.far_z)
			|| (render->vx1 < env->player.camera.far_left && render->vx2 < env->player.camera.far_left)
			|| (render->vx1 > env->player.camera.far_right && render->vx2 > env->player.camera.far_right))
		return (0);
	get_intersections(render, env);
	return (1);
	if ((render->inter_left.x >= env->player.camera.far_left
			&& render->inter_left.x <= env->player.camera.near_left
			&& render->inter_left.y >= env->player.camera.near_z
			&& render->inter_left.y <= env->player.camera.far_z)
			|| (render->inter_right.x >= env->player.camera.near_right
			&& render->inter_right.x <= env->player.camera.far_right
			&& render->inter_right.y >= env->player.camera.near_z
			&& render->inter_right.y <= env->player.camera.far_z)
			|| (render->inter_far.x >= env->player.camera.far_left
			&& render->inter_far.x <= env->player.camera.far_right)
			|| (render->inter_near.x >= env->player.camera.near_left
			&& render->inter_near.x <= env->player.camera.near_right))
		return (1);
	/*if ((render->vx1 >= render->inter_left.x && render->vx1 <= render->inter_right.x
				&& render->vz1 >= render->inter_near.y && render->vz1 <= render->inter_far.y)
			|| (render->vx2 >= render->inter_left.x && render->vx2 <= render->inter_right.x
				&& render->vz2 >= render->inter_near.y && render->vz2 <= render->inter_far.y))
		return (1);*/
	/*if (render->vz1 >= env->player.camera.near_z || render->vz2 >= env->player.camera.near_z)
		return (1);*/
	return (0);
}

void		clip_walls(t_render *render, t_env *env)
{
	/*handle_left(render, env);
	handle_right(render, env);
	handle_near(render, env);
	handle_far(render, env);*/
	/*if (render->vx1 < render->inter_left.x)
	{
		render->vx1 = render->inter_left.x;
		render->vz1 = render->inter_left.y;
		render->v1_clipped = 1;
		render->clipped = 1;
	}
	if (render->vz1 < render->inter_near.y)
	{
		render->vx1 = render->inter_near.x;
		render->vz1 = render->inter_near.y;
		render->v1_clipped = 1;
		render->clipped = 1;
	}
	if (render->vx2 > render->inter_right.x)
	{
		render->vx2 = render->inter_right.x;
		render->vz2 = render->inter_right.y;
		render->v2_clipped = 1;
		render->clipped = 1;
	}
	if (render->vz2 < render->inter_near.y)
	{
		render->vx2 = render->inter_near.x;
		render->vz2 = render->inter_near.y;
		render->v2_clipped = 1;
		render->clipped = 1;
	}*/
	if (render->vz1 < env->player.camera.near_z)
	{
		render->clipped_vx1 = render->inter_near.x;
		render->clipped_vz1 = render->inter_near.y;
		render->v1_clipped = 1;
	}
	if (render->vz2 < env->player.camera.near_z)
	{
		render->clipped_vx2 = render->inter_near.x;
		render->clipped_vz2 = render->inter_near.y;
		render->v2_clipped = 1;
	}
	/*if (render->vz1 <= env->player.camera.near_z || render->vz2 <= env->player.camera.near_z)
	{
		render->clipped = 1;
		//Trouver une intersection entre le mur et le champ de vision du joueur
		if (render->vz1 < env->player.camera.near_z)
		{
			if(render->inter_left.y > env->player.camera.near_z)
			{
				render->vx1 = render->inter_left.x;
				render->vz1 = render->inter_left.y;
			}
			else
			{
				render->vx1 = render->inter_right.x;
				render->vz1 = render->inter_right.y;
			}
			render->v1_clipped = 1;
		}
		if (render->vz2 < env->player.camera.near_z)
		{
			if(render->inter_left.y > env->player.camera.near_z)
			{
				render->vx2 = render->inter_left.x;
				render->vz2 = render->inter_left.y;
			}
			else
			{
				render->vx2 = render->inter_right.x;
				render->vz2 = render->inter_right.y;
			}
			render->v2_clipped = 1;
		}
	}
	else
		render->clipped = 0;*/
}
