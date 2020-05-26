/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_menu6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 19:21:04 by gaerhard          #+#    #+#             */
/*   Updated: 2020/05/14 19:21:04 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "env.h"
#include "free.h"
#include "init.h"

int		init_screen_pos(t_env *env)
{
	env->screen_sectors_size = ft_min(env->nb_sectors, env->w);
	if (!(env->player.camera.xmin = (int*)malloc(sizeof(int) *
		(env->screen_sectors_size))))
		return (ft_perror("Could not malloc xmins!"));
	if (!(env->player.camera.xmax = (int*)malloc(sizeof(int) *
		(env->screen_sectors_size))))
		return (ft_perror("Could not malloc xmaxs"));
	if (!(env->player.camera.screen_sectors = (int*)malloc(sizeof(int) *
		(env->screen_sectors_size))))
		return (ft_perror("Could not malloc screen sectors"));
	if (!(env->player.camera.rendered_sectors = (int*)malloc(sizeof(int) *
		(env->screen_sectors_size))))
		return (ft_perror("Could not malloc rendered sectors"));
	return (0);
}

int     next_resolution(void *target)
{
    t_env *env;

    env = (t_env*)target;
    if (env->i < 2)
        env->i++;
	free_all_sdl_relative(env);
	set_screen_size(env);
	set_camera(&env->player.camera, env);
	if (set_sdl(env))
		return (custom_error("Could not re load sdl\n"));
	if (init_screen_pos(env))
		return (custom_error("Could not re load screen pos\n"));
    return (0);
}

int     prev_resolution(void *target)
{
    t_env *env;

    env = (t_env*)target;
    if (env->i > 0)
        env->i--;
	free_all_sdl_relative(env);
	set_screen_size(env);
	set_camera(&env->player.camera, env);
	if (set_sdl(env))
		return (custom_error("Could not re load sdl\n"));
	if (init_screen_pos(env))
		return (custom_error("Could not re load screen pos\n"));
    return (0);
}

int		next_resolution_button(t_env *env)
{
	env->next_resolution = new_next_button(ON_RELEASE,
		&next_resolution, env, env);
	env->next_resolution.pos = new_point(env->h_w + env->h_w / 2,
		env->h_h + env->h_h / 4 + env->next_resolution.size_down.y);
	return (0);
}

int		prev_resolution_button(t_env *env)
{
	env->prev_resolution = new_previous_button(ON_RELEASE,
		&prev_resolution, env, env);
	env->prev_resolution.pos = new_point(env->h_w - env->h_w / 2,
		env->h_h + env->h_h / 4 + env->prev_resolution.size_down.y);
	return (0);
}
