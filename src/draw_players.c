/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   draw_players.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lnicosia <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/09/19 10:38:52 by lnicosia		  #+#	#+#			 */
/*   Updated: 2019/09/19 14:51:57 by lnicosia		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "env.h"
#include "render.h"

int			draw_players(t_camera camera, t_env *env)
{
	t_enemies	player;

	if (camera.pos.x == env->player.pos.x && camera.pos.y == env->player.pos.y
			&& camera.pos.z == env->player.head_z)
		return (1);
	ft_printf("cc\n");
	player.pos = env->player.pos;
	player.sprite = 5;
	player.scale = 50;
	if (env->player.camera.angle < 0)
		player.angle = 360 + (int)(env->player.camera.angle * CONVERT_DEGREES) % 360;
	else
		player.angle = (int)(env->player.camera.angle * CONVERT_DEGREES) % 360;
	get_translated_enemy_pos(camera, &player);
	get_rotated_enemy_pos(camera, &player);
	draw_enemy(camera, &player, env, 9);
	return (0);
}
