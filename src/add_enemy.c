/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   add_enemy.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: sipatry <marvin@42.fr>					 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/09/05 16:40:52 by sipatry		   #+#	#+#			 */
/*   Updated: 2019/11/29 15:22:42 by lnicosia         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "env.h"

int	add_enemy(t_env *env)
{
	t_enemies	enemy;

	enemy.num = env->nb_enemies;
	enemy.pos.x = (env->sdl.mx - env->editor.center.x) / env->editor.scale;
	enemy.pos.y = (env->sdl.my - env->editor.center.y) / env->editor.scale;
	enemy.sprite = 0;
	enemy.scale = 5;
	enemy.angle = 0;
	enemy.exists = 1;
	enemy.sector = get_sector_no_z(env, new_v3(enemy.pos.x, enemy.pos.y, 0));
	enemy.pos.z = env->sectors[enemy.sector].floor + 5;
	enemy.speed = 40;
	enemy.health = 40;
	enemy.damage = 25;
	if (enemy.sector != -1)
	{
		enemy.light_color = env->sectors[enemy.sector].light_color;
		enemy.brightness = env->sectors[enemy.sector].brightness;
		enemy.intensity = env->sectors[enemy.sector].intensity;
	}
	else
	{
		enemy.light_color = 0xFFFFFFFF;
		enemy.brightness = 0;
		enemy.intensity = 0;
	}
	if (!(env->enemies = (t_enemies*)ft_realloc(env->enemies, sizeof(t_enemies) * env->nb_enemies, sizeof(t_enemies) * (env->nb_enemies + 1))))
		return (ft_printf("Could not realloc enemys\n"));
	env->enemies[env->nb_enemies] = enemy;
	return (0);
}
