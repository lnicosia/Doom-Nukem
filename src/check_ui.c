/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 10:16:20 by sipatry           #+#    #+#             */
/*   Updated: 2020/05/11 17:47:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

/*
**	Check ui images needed for main menu
*/

int		check_ui(t_env *env)
{
	int	fd;
	int	i;

	fd = 0;
	env->init.ui_names[0] = "./images/ui/hud-button-up.bmp";
	env->init.ui_names[1] = "./images/ui/hud-button-pressed.bmp";
	env->init.ui_names[2] = "./images/ui/hud-button-hover.bmp";
	env->init.ui_names[3] = "./images/ui/minus-button-up.bmp";
	env->init.ui_names[4] = "./images/ui/minus-button-pressed.bmp";
	env->init.ui_names[5] = "./images/ui/minus-button-hover.bmp";
	env->init.ui_names[6] = "./images/ui/add_button.bmp";
	i = 0;
	while (i < NB_UI_FILES)
	{
		if ((fd = open(env->init.ui_names[i], O_RDONLY)) == -1)
			env->init.ui[i] = 1;
		if (!env->init.ui[i] && close(fd))
			return (custom_error("Could not close %s after ui check\n",
			env->init.ui_names[i]));
		i++;
	}
	return (0);
}
