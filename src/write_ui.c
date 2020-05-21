/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_ui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 10:16:20 by sipatry           #+#    #+#             */
/*   Updated: 2020/05/11 17:47:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "save.h"

/*
**	Write ui textures needed for main menu in the map
*/

int	write_ui(int fd, t_env *env)
{
	int	i;
	int	file;

	i = 0;
	ft_printf("Saving ui files\n");
	ft_dprintf(fd, "U %d\n", NB_UI_FILES);
	while (i < NB_UI_FILES)
	{
		if ((file = open(env->init.ui_names[i], O_RDONLY)) < 0)
			return (custom_error("Could not open %s to save it\n",
			env->init.ui_names[i]));
			if (writing_bmp(file, fd, env->init.ui_names[i]))
			return (custom_error("Could not write %s\n",
			env->init.ui_names[i]));
			i++;
	}
	return (0);
}
