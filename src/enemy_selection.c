/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   enemy_selection.c								  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: sipatry <marvin@42.fr>					 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/09/05 15:40:36 by sipatry		   #+#	#+#			 */
/*   Updated: 2019/09/05 17:19:28 by sipatry		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "env.h"

void	enemy_selection(t_env *env)
{
	if (env->inputs.left_click
			&& env->sdl.mx > 80
			&& env->sdl.mx < 120
			&& env->sdl.my > 280
			&& env->sdl.my < 320
			&& env->editor.start_vertex == -1
			&& env->editor.dragged_player == -1
			&& env->editor.dragged_vertex == -1
			&& env->editor.dragged_object == -1
			&& env->editor.dragged_enemy == -1)
	{
		env->editor.dragged_enemy = env->nb_enemies;
	}
	if (!env->inputs.left_click && env->editor.dragged_enemy != -1)
	{
		if (env->sdl.mx > 200)
		{
			if (env->editor.dragged_enemy == env->nb_enemies)
			{
				add_enemy(env);
				env->nb_enemies++;
			}
			else
			{
				env->enemies[env->editor.dragged_enemy].pos.x =	(env->sdl.mx - env->editor.center.x) / env->editor.scale;
				env->enemies[env->editor.dragged_enemy].pos.y =	(env->sdl.my - env->editor.center.y) / env->editor.scale;
			}
		}
		else
			delete_enemy(env, env->editor.dragged_enemy);
		env->editor.dragged_enemy = -1;
	}
}
