/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 15:07:34 by gaerhard          #+#    #+#             */
/*   Updated: 2019/12/04 11:23:39 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int     damage_done(t_env env, double rotated_pos_z)
{
	if (env.weapons[env.player.curr_weapon].splash)
		return ((int)(env.weapons[env.player.curr_weapon].damage / (rotated_pos_z / 4 + 1)));
	else
		return (env.weapons[env.player.curr_weapon].damage);
}

int		hitscan_enemies(t_env *env, int i)
{
	if (env->enemies[i].exists && env->enemies[i].seen)
	{
		if ((env->enemies[i].left - env->enemies[i].left) * (env->h / 2 - env->enemies[i].bottom) - (env->w / 2 - env->enemies[i].left) * (env->enemies[i].top - env->enemies[i].bottom) < 0)
			return (0);
		if ((env->enemies[i].right - env->enemies[i].left) * (env->h / 2 - env->enemies[i].top) - (env->w / 2 - env->enemies[i].left) * (env->enemies[i].top - env->enemies[i].top) < 0)
			return (0);
		if ((env->enemies[i].right - env->enemies[i].right) * (env->h / 2 - env->enemies[i].top) - (env->w / 2 - env->enemies[i].right) * (env->enemies[i].bottom - env->enemies[i].top) < 0)
			return (0);
		if ((env->enemies[i].left - env->enemies[i].right) * (env->h / 2 - env->enemies[i].bottom) - (env->w / 2 - env->enemies[i].right) * (env->enemies[i].bottom - env->enemies[i].bottom) < 0)
			return (0);
		if (env->enemies[i].rotated_pos.z > env->weapons[env->player.curr_weapon].range || env->enemies[i].rotated_pos.z < 0)
			return (0);
		return (1);
	}
	return (-1);
}

int		hitscan_objects(t_env *env, int i)
{
	if (env->objects[i].exists && env->objects[i].seen)
	{
		if ((env->objects[i].left - env->objects[i].left) * (env->h / 2 - env->objects[i].bottom) - (env->w / 2 - env->objects[i].left) * (env->objects[i].top - env->objects[i].bottom) < 0)
			return (0);
		if ((env->objects[i].right - env->objects[i].left) * (env->h / 2 - env->objects[i].top) - (env->w / 2 - env->objects[i].left) * (env->objects[i].top - env->objects[i].top) < 0)
			return (0);
		if ((env->objects[i].right - env->objects[i].right) * (env->h / 2 - env->objects[i].top) - (env->w / 2 - env->objects[i].right) * (env->objects[i].bottom - env->objects[i].top) < 0)
			return (0);
		if ((env->objects[i].left - env->objects[i].right) * (env->h / 2 - env->objects[i].bottom) - (env->w / 2 - env->objects[i].right) * (env->objects[i].bottom - env->objects[i].bottom) < 0)
			return (0);
		if (env->objects[i].rotated_pos.z > env->weapons[env->player.curr_weapon].range || env->objects[i].rotated_pos.z < 0)
			return (0);
		return (1);
	}
	return (-1);
}

void    shot(t_env *env)
{
	int	i;
	int	hit;

	i = 0;
	hit = 0;
	if (env->weapons[env->player.curr_weapon].ammo_type == ROCKET)
	{
		create_projectile(env, new_projectile_data(env->player.pos, env->player.camera.angle * CONVERT_DEGREES, 50, 1),
			new_projectile_stats(0.5, 50, 0.8, env->player.eyesight - 0.4),
			env->player.camera.angle_z);
	}
	else
	{
		while (i < env->nb_enemies)
		{
			if (hitscan_enemies(env, i) == 1)
			{
				env->enemies[i].health -= damage_done(*env, env->enemies[i].rotated_pos.z);
				hit = 1;
				if (env->enemies[i].health <= 0)
					env->player.killed++;
				env->enemies[i].hit = 1;
			}
			i++;
		}
		i = 0;
		while (i < env->nb_objects)
		{
			if (env->objects[i].destructible)
			{
				if (hitscan_objects(env, i) == 1)
				{
					env->objects[i].health -= damage_done(*env, env->objects[i].rotated_pos.z);
					if (env->objects[i].explodes)
					{
						create_explosion(env,
							new_explosion_data(env->objects[i].pos, 7, env->objects[i].damage, 10));
						env->nb_explosions++;
					}
				}
			}
			i++;
		}
	}
	if (hit)
		env->player.touched += 1;
	env->player.nb_shots += 1;
}

void    draw_weapon(t_env *env, int sprite)
{
	int			x;
	int			y;
	int			window_w;
	int			window_h;
	int			texture_w;
	int			texture_h;
	Uint32		*pixels;
	Uint32		*texture_pixels;
	t_sector	sector;

	pixels = env->sdl.texture_pixels;
	texture_pixels = env->sprite_textures[sprite].str;
	texture_w = env->sprite_textures[sprite].surface->w;
	texture_h = env->sprite_textures[sprite].surface->h;
	window_w = (int)(env->w - texture_w) / 1.5;
	window_h = (env->h - texture_h) + env->weapons[0].weapon_switch;
	sector = env->sectors[env->player.sector];
	y = 0;
	while (y < texture_h)
	{
		x = 0;
		while (x < texture_w  && (window_h + y) < env->h)
		{
			if (texture_pixels[x + texture_w * y] != 0xFFC10099)
			{
				if (!env->options.lighting
					|| (!sector.brightness && !sector.intensity))
					pixels[(window_w + x) + env->w * (window_h + y)] = 
						texture_pixels[x + texture_w * y];
				else if (!sector.brightness)
					pixels[(window_w + x) + env->w * (window_h + y)] = 
						apply_light_color(texture_pixels[x + texture_w * y],
								sector.light_color,
								sector.intensity);
				else if (!sector.intensity)
					pixels[(window_w + x) + env->w * (window_h + y)] = 
						apply_light_brightness(texture_pixels[x + texture_w * y],
								sector.brightness);
				else
					pixels[(window_w + x) + env->w * (window_h + y)] = 
						apply_light_both(texture_pixels[x + texture_w * y],
								sector.light_color,
								sector.intensity,
								sector.brightness);
			}
			x++;
		}
		y++;
	}
}

void    weapon_animation(t_env *env, int nb)
{
	if (env->shot.start == 0)
	{
		env->shot.on_going = 1;
		env->shot.start = SDL_GetTicks();
		if (env->weapons[nb].ammo <= 0)
		{
			env->weapons[nb].no_ammo = 1;
			Mix_PlayChannel(2, env->weapons[nb].empty, 0);
		}
		else
		{
			shot(env);
			env->weapons[nb].no_ammo = 0;
			Mix_PlayChannel(2, env->weapons[nb].sound, 0);
			env->weapons[nb].ammo--;
		}
	}
	if (!env->weapons[nb].no_ammo)
	{
		if (env->time.milli_s > env->shot.start + 70 && ((env->time.milli_s - env->shot.start) / 70 < env->weapons[nb].nb_sprites))
			draw_weapon(env, env->weapons[nb].first_sprite + (int)((env->time.milli_s - env->shot.start) / 70));
		else
			draw_weapon(env, env->weapons[nb].first_sprite);
	}
	else
	{
		draw_weapon(env, env->weapons[nb].first_sprite);
	}
	if ((int)((env->time.milli_s - env->shot.start)) >= env->weapons[nb].nb_sprites * 70)
	{
		env->shot.start = 0;
		env->shot.on_going = 0;
	}
}

void    weapon_change(t_env *env)
{
	int time_spent;

	if (env->weapon_change.start == 0)
	{
		env->weapon_change.start = SDL_GetTicks();
		env->weapon_change.on_going = 1;
	}
	time_spent = env->time.milli_s - env->weapon_change.start;
	if (time_spent > 70 && time_spent / 70 <= 4)
		env->weapons[0].weapon_switch  = 75 * (int)(time_spent / 70);
	if (time_spent > 4 * 70)
	{
		if (env->sdl.event.wheel.y > 0)
			env->player.curr_weapon = (env->player.curr_weapon >= NB_WEAPONS - 1 ? 0 : env->player.curr_weapon + 1);
		else if (env->sdl.event.wheel.y < 0)
			env->player.curr_weapon = (env->player.curr_weapon <= 0 ? NB_WEAPONS - 1 : env->player.curr_weapon - 1);
		env->weapons[0].weapon_switch = 0;
		env->weapon_change.start = 0;
		env->weapon_change.on_going = 0;
	}
}

void    print_ammo(t_env *env)
{
	char *str;

	str = ft_sitoa(env->weapons[env->player.curr_weapon].ammo);
	print_text(new_point(env->h - env->h / 12, env->w - env->w / 14 - 5), new_printable_text(str, env->sdl.fonts.amazdoom50, 0xA1A1A100, 0), env);
	str = "/";
	print_text(new_point(env->h - env->h / 12, env->w - env->w / 19), new_printable_text(str, env->sdl.fonts.amazdoom50, 0xA1A1A100, 0), env);
	str = ft_sitoa(env->weapons[env->player.curr_weapon].max_ammo);
	print_text(new_point(env->h - env->h / 12, env->w - env->w / 24), new_printable_text(str, env->sdl.fonts.amazdoom50, 0xA1A1A100, 0), env);
}

int		aoe_damage(double distance, double radius, int damage)
{
	double	percentage;

	percentage = (100 - (distance / radius) * 100) / 100;
	if (percentage < 0.3)
		percentage = 0.3;
	ft_printf("distance = %f radius = %f\n", distance, radius);
	ft_printf("percentage = %f\n", percentage);
	ft_printf("explosion damage = %d\n", (int)(damage * percentage));
	return ((int)(damage * percentage));
}