/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 15:07:34 by gaerhard          #+#    #+#             */
/*   Updated: 2020/05/01 12:10:46 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw.h"

int		print_ammo(t_env *env)
{
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%d/%d",
	env->weapons[env->player.curr_weapon].ammo,
	env->weapons[env->player.curr_weapon].max_ammo);
	if (print_text(new_point(env->h - env->h / 12, env->w - env->w / 14 - 5),
	new_printable_text(env->snprintf, env->sdl.fonts.amazdoom50, 0xfff1f2f3, 0),
	env))
		return (-1);
	return (0);
}

int		aoe_damage(double distance, double radius, int damage)
{
	double	percentage;

	percentage = (100 - (distance / radius) * 100) / 100;
	if (percentage < 0.3)
		percentage = 0.3;
	return ((int)(damage * percentage));
}

int		next_weapon_wheel_up(t_env *env)
{
	int i;
	int	is_playing;
	int	err;

	i = (env->player.curr_weapon == NB_WEAPONS - 1) ? 0 :
	env->player.curr_weapon + 1;
	if (FMOD_Channel_IsPlaying(env->sound.player_shots_chan, &is_playing)
		== FMOD_OK && is_playing == 1)
	{
		if ((err = FMOD_Channel_Stop(env->sound.player_shots_chan)) !=
			FMOD_OK)
			return (custom_error("Could not stop player shots channel"
				"(error %d)\n", err));
	}
	while (i != env->player.curr_weapon)
	{
		if (env->weapons[i].possessed)
		{
			env->player.next_weapon = i;
			return (0);
		}
		i++;
		if (i >= NB_WEAPONS)
			i = 0;
	}
	return (-1);
}

int		next_weapon_wheel_down(t_env *env)
{
	int		i;
	int	is_playing;
	int	err;

	i = (env->player.curr_weapon == 0) ? NB_WEAPONS - 1 :
		env->player.curr_weapon - 1;
	if (FMOD_Channel_IsPlaying(env->sound.player_shots_chan, &is_playing)
		== FMOD_OK && is_playing == 1)
	{
		if ((err = FMOD_Channel_Stop(env->sound.player_shots_chan)) !=
			FMOD_OK)
			return (custom_error("Could not stop player shots channel"
				"(error %d)\n", err));
	}
	while (i != env->player.curr_weapon)
	{
		if (env->weapons[i].possessed)
		{
			env->player.next_weapon = i;
			return (0);
		}
		i--;
		if (i < 0)
			i = NB_WEAPONS - 1;
	}
	return (-1);
}

int		next_possessed_weapon(t_env *env)
{
	if (env->sdl.event.wheel.y > 0)
		return (next_weapon_wheel_up(env));
	if (env->sdl.event.wheel.y < 0)
		return (next_weapon_wheel_down(env));
	return (-1);
}
