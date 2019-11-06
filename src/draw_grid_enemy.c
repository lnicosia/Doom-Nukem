/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   draw_grid_enemy.c								  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: sipatry <marvin@42.fr>					 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/09/05 16:56:49 by sipatry		   #+#	#+#			 */
/*   Updated: 2019/11/06 13:42:23 by lnicosia         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "env.h"


void	draw_grid_enemies(t_env *env)
{
	t_point		center;
	double		scale;
	int			i;
	Uint32		color;
	//t_v3		v[3];

	i = 0;
	if (env->editor.dragged_enemy != -1)
	{
		color = 0xFF0000FF;
		scale = env->editor.scale / 2.0;
		center.x = env->sdl.mx;
		center.y = env->sdl.my;
		draw_circle(new_circle(color, color, center, scale), env);
	}
	while (i < env->nb_enemies)
	{
		center.x = env->enemies[i].pos.x * env->editor.scale + env->editor.center.x;
		center.y = env->enemies[i].pos.y * env->editor.scale + env->editor.center.y;
		if (env->sdl.mx > center.x - env->editor.scale / 2.0
				&& env->sdl.mx < center.x + env->editor.scale / 2.0
				&& env->sdl.my > center.y - env->editor.scale / 2.0
				&& env->sdl.my < center.y + env->editor.scale / 2.0)
		{
			scale = env->editor.scale;
			color = 0xFF0000FF;
			if (env->inputs.left_click
					&& !env->confirmation_box.state
					&& !env->input_box.state
					&& env->editor.start_vertex == -1
					&& env->editor.dragged_player == -1
					&& env->editor.dragged_enemy == -1
					&& env->editor.dragged_vertex == -1
					&& env->editor.dragged_object == -1)
			{
				env->editor.dragged_enemy = i;
				env->selected_enemy = i;
				env->editor.selected_vertex = -1;
				env->editor.selected_sector = -1;
				env->editor.selected_player = -1;
				env->editor.selected_object = -1;
			}
		}
		else
		{
			color = 0xFF0000FF;
			scale = env->editor.scale / 2.0;
		}
		if (env->selected_enemy == i)
			color = 0xFF0000FF;
		if (env->editor.dragged_enemy != i)
			draw_circle(new_circle(color, color, center, scale), env);
		i++;
		/*v[0] = new_v3(center.x + cos(env->enemies[i].angle - M_PI / 2) * scale / 2,
				center.y + sin(env->enemies[i].angle - M_PI / 2) * scale / 2,
				0);
		v[2] = new_v3(center.x - cos(env->enemies[i].angle - M_PI / 2) * scale / 2,
				center.y - sin(env->enemies[i].angle - M_PI / 2) * scale / 2,
				0);
		v[1] = new_v3(center.x + cos(env->enemies[i].angle) * scale * 2,
				center.y + sin(env->enemies[i].angle) * scale * 2,
				0);
		fill_triangle(v, 0xFFFFFF00, env);*/
	}
}
