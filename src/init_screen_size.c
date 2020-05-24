/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_screen_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:06:03 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/09 11:06:17 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

int		init_screen_size(t_env *env)
{
	env->screen_w[2] = 2560;
	env->screen_h[2] = 1440;
	env->screen_w[1] = 1920;
	env->screen_h[1] = 1080;
	env->screen_w[0] = 1600;
	env->screen_h[0] = 900;
	if (!(env->res[2] = ft_strdup("2560 x 1440")))
		return (ft_perror("Could not malloc screen size 0"));
	if (!(env->res[1] = ft_strdup("1920 x 1080")))
		return (ft_perror("Could not malloc screen size 1"));
	if (!(env->res[0] = ft_strdup("1600 x 900")))
		return (ft_perror("Could not malloc screen size 2"));
	set_screen_size(env);
	return (0);
}

void	set_screen_size(t_env *env)
{
	env->w = env->screen_w[env->i];
	env->h = env->screen_h[env->i];
	env->h_w = env->w / 2;
	env->h_h = env->h / 2;
}
