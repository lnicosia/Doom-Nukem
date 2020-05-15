/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_skyboxes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 09:15:55 by marvin            #+#    #+#             */
/*   Updated: 2020/05/15 21:06:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "parser.h"

int		check_skyboxes5(t_env *env)
{
	int	fd;

	fd = 0;
	if (!(env->init.skyboxes_names[12] =
	ft_strdup("images/skyboxes/bottom.bmp")))
		return (ft_perror("Error while parsing skyboxe\n"));
	if ((fd = open("images/skyboxes/bottom.bmp", O_RDONLY)) == -1)
		env->init.skyboxes[12] = 1;
	if (!env->init.skyboxes[12] && close(fd))
		return (custom_error("Could not close the fd in check skyboxes\n"));
	if (!(env->init.skyboxes_names[13] =
		ft_strdup("images/skyboxes/top.bmp")))
		return (ft_perror("Error while parsing skyboxe\n"));
	if ((fd = open("images/skyboxes/top.bmp", O_RDONLY)) == -1)
		env->init.skyboxes[13] = 1;
	if (!env->init.skyboxes[13] && close(fd))
		return (custom_error("Could not close the fd in check skyboxes\n"));
	if (!(env->init.skyboxes_names[14] =
		ft_strdup("images/skyboxes/back.bmp")))
		return (ft_perror("Error while parsing skyboxe\n"));
	if ((fd = open("images/skyboxes/back.bmp", O_RDONLY)) == -1)
		env->init.skyboxes[14] = 1;
	if (!env->init.skyboxes[14] && close(fd))
		return (custom_error("Could not close the fd in check skyboxes\n"));
	return (check_skyboxes6(env));
}

int		check_skyboxes4(t_env *env)
{
	int	fd;

	fd = 0;
	if (!(env->init.skyboxes_names[9] =
		ft_strdup("images/skyboxes/nebula_left.bmp")))
		return (ft_perror("Error while parsing skyboxe\n"));
	if ((fd = open("images/skyboxes/nebula_left.bmp", O_RDONLY)) == -1)
		env->init.skyboxes[9] = 1;
	if (!env->init.skyboxes[9] && close(fd))
		return (custom_error("Could not close the fd in check skyboxes\n"));
	if (!(env->init.skyboxes_names[10] =
		ft_strdup("images/skyboxes/nebula_front.bmp")))
		return (ft_perror("Error while parsing skyboxe\n"));
	if ((fd = open("images/skyboxes/nebula_front.bmp", O_RDONLY)) == -1)
		env->init.skyboxes[10] = 1;
	if (!env->init.skyboxes[10] && close(fd))
		return (custom_error("Could not close the fd in check skyboxes\n"));
	if (!(env->init.skyboxes_names[11] =
		ft_strdup("images/skyboxes/nebula_right.bmp")))
		return (ft_perror("Error while parsing skyboxe\n"));
	if ((fd = open("images/skyboxes/nebula_right.bmp", O_RDONLY)) == -1)
		env->init.skyboxes[11] = 1;
	if (!env->init.skyboxes[11] && close(fd))
		return (custom_error("Could not close the fd in check skyboxes\n"));
	return (check_skyboxes5(env));
}

int		check_skyboxes3(t_env *env)
{
	int	fd;

	fd = 0;
	if (!(env->init.skyboxes_names[6] =
		ft_strdup("images/skyboxes/nebula_bottom.bmp")))
		return (ft_perror("Error while parsing skyboxe\n"));
	if ((fd = open("images/skyboxes/nebula_bottom.bmp", O_RDONLY)) == -1)
		env->init.skyboxes[6] = 1;
	if (!env->init.skyboxes[6] && close(fd))
		return (custom_error("Could not close the fd in check skyboxes\n"));
	if (!(env->init.skyboxes_names[7] =
		ft_strdup("images/skyboxes/nebula_top.bmp")))
		return (ft_perror("Error while parsing skyboxe\n"));
	if ((fd = open("images/skyboxes/nebula_top.bmp", O_RDONLY)) == -1)
		env->init.skyboxes[7] = 1;
	if (!env->init.skyboxes[7] && close(fd))
		return (custom_error("Could not close the fd in check skyboxes\n"));
	if (!(env->init.skyboxes_names[8] =
		ft_strdup("images/skyboxes/nebula_back.bmp")))
		return (ft_perror("Error while parsing skyboxe\n"));
	if ((fd = open("images/skyboxes/nebula_back.bmp", O_RDONLY)) == -1)
		env->init.skyboxes[8] = 1;
	if (!env->init.skyboxes[8] && close(fd))
		return (custom_error("Could not close the fd in check skyboxes\n"));
	return (check_skyboxes4(env));
}

int		check_skyboxes2(t_env *env)
{
	int	fd;

	fd = 0;
	if (!(env->init.skyboxes_names[3] =
		ft_strdup("images/skyboxes/night_left.bmp")))
		return (ft_perror("Error while parsing skyboxe\n"));
	if ((fd = open("images/skyboxes/night_left.bmp", O_RDONLY)) == -1)
		env->init.skyboxes[3] = 1;
	if (!env->init.skyboxes[3] && close(fd))
		return (custom_error("Could not close the fd in check skyboxes\n"));
	if (!(env->init.skyboxes_names[4] =
		ft_strdup("images/skyboxes/night_front.bmp")))
		return (ft_perror("Error while parsing skyboxe\n"));
	if ((fd = open("images/skyboxes/night_front.bmp", O_RDONLY)) == -1)
		env->init.skyboxes[4] = 1;
	if (!env->init.skyboxes[4] && close(fd))
		return (custom_error("Could not close the fd in check skyboxes\n"));
	if (!(env->init.skyboxes_names[5] =
		ft_strdup("images/skyboxes/night_right.bmp")))
		return (ft_perror("Error while parsing skyboxe\n"));
	if ((fd = open("images/skyboxes/night_right.bmp", O_RDONLY)) == -1)
		env->init.skyboxes[5] = 1;
	if (!env->init.skyboxes[5] && close(fd))
		return (custom_error("Could not close the fd in check skyboxes\n"));
	return (check_skyboxes3(env));
}

int		check_skyboxes(t_env *env)
{
	int	fd;

	fd = 0;
	if (!(env->init.skyboxes_names[0] =
	ft_strdup("images/skyboxes/night_bottom.bmp")))
		return (ft_perror("Error while parsing skyboxe\n"));
	if ((fd = open("images/skyboxes/night_bottom.bmp", O_RDONLY)) == -1)
		env->init.skyboxes[0] = 1;
	if (!env->init.skyboxes[0] && close(fd))
		return (custom_error("Could not close the fd in check skyboxes\n"));
	if (!(env->init.skyboxes_names[1] =
	ft_strdup("images/skyboxes/night_bottom.bmp")))
		return (ft_perror("Error while parsing skyboxe\n"));
	if ((fd = open("images/skyboxes/night_bottom.bmp", O_RDONLY)) == -1)
		env->init.skyboxes[1] = 1;
	if (!env->init.skyboxes[1] && close(fd))
		return (custom_error("Could not close the fd in check skyboxes\n"));
	if (!(env->init.skyboxes_names[2] =
	ft_strdup("images/skyboxes/night_back.bmp")))
		return (ft_perror("Error while parsing skyboxe\n"));
	if ((fd = open("images/skyboxes/night_back.bmp", O_RDONLY)) == -1)
		env->init.skyboxes[2] = 1;
	if (!env->init.skyboxes[2] && close(fd))
		return (custom_error("Could not close the fd in check skyboxes\n"));
	return (check_skyboxes2(env));
}
