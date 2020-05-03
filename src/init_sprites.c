/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:51:46 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 13:35:25 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "map_parser.h"

int		init_object_sprites(t_env *env)
{
	init_minigun(env);
	init_rocket(env);
	init_health_pack(env);
	init_ammo(env);
	init_lamp(env);
	init_monitor(env);
	init_armor_green(env);
	init_candle(env);
	init_barrel(env);
	init_explosion(env);
	init_grid_sprite(env);
	init_button_sprite(env);
	init_bullet_hole(env);
	init_object_lost_soul(env);
	init_object_cyber_demon(env);
	init_doom_guy_face(env);
	init_camera_sprite(env);
	init_shotgun_sprite(env);
	init_raygun_sprite(env);
	init_doom_guy(env);
	init_hd_sprite(env);
	return (0);
}

int		init_enemy_sprites(t_env *env)
{
	init_lost_soul_sprite(env);
	init_lost_soul_rest(env);
	init_lost_soul_pursuit(env);
	init_lost_soul_pursuit_two(env);
	init_lost_soul_death(env);
	init_cyber_demon_pursuit(env);
	init_cyber_demon_pursuit_two(env);
	init_cyber_demon_pursuit_three(env);
	init_cyber_demon_pursuit_four(env);
	init_cyber_demon_firing_anim(env);
	init_cyber_demon_firing_anim_two(env);
	init_cyber_demon_firing_anim_three(env);
	init_cyber_demon_death(env);
	env->enemies_main_sprites[0] = LOST_SOUL;
	env->enemies_main_sprites[1] = CYBER_DEMON;
	init_objects_main_sprites(env);
	return (0);
}
