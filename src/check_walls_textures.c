/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 16:15:46 by marvin            #+#    #+#             */
/*   Updated: 2020/05/14 14:06:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		check_wall_textures4(t_env *env)
{
	int	fd;

	fd = 0;
	if (!(env->init.text_name[13] = ft_strdup("./images/textures/sand.bmp")))
		return (ft_perror("Error while malloc texture name\n"));
	if ((fd = open("./images/textures/sand.bmp", O_RDONLY)) == -1)
		env->init.textures[13] = 1;
	if (!env->init.textures[13] && close(fd))
		return (custom_error("Could not close the file in check textures\n"));
	if (!(env->init.text_name[14] = ft_strdup("./images/textures/grey.bmp")))
		return (ft_perror("Error while malloc texture name\n"));
	if ((fd = open("./images/textures/grey.bmp", O_RDONLY)) == -1)
		env->init.textures[14] = 1;
	if (!env->init.textures[14] && close(fd))
		return (custom_error("Could not close the file in check textures\n"));
	return (0);
}

int		check_wall_textures3(t_env *env)
{
	int	fd;

	fd = 0;
	if (!(env->init.text_name[10] = ft_strdup("./images/textures/grass2.bmp")))
		return (ft_perror("Error while malloc texture name\n"));
	if ((fd = open("./images/textures/grass2.bmp", O_RDONLY)) == -1)
		env->init.textures[10] = 1;
	if (!env->init.textures[10] && close(fd))
		return (custom_error("Could not close the file in check textures\n"));
	if (!(env->init.text_name[11] = ft_strdup("./images/textures/grass3.bmp")))
		return (ft_perror("Error while malloc texture name\n"));
	if ((fd = open("./images/textures/grass3.bmp", O_RDONLY)) == -1)
		env->init.textures[11] = 1;
	if (!env->init.textures[11] && close(fd))
		return (custom_error("Could not close the file in check textures\n"));
	if (!(env->init.text_name[12] = ft_strdup("./images/textures/tiles.bmp")))
		return (ft_perror("Error while malloc texture name\n"));
	if ((fd = open("./images/textures/tiles.bmp", O_RDONLY)) == -1)
		env->init.textures[12] = 1;
	if (!env->init.textures[12] && close(fd))
		return (custom_error("Could not close the file in check textures\n"));
	return (check_wall_textures4(env));
}

int    check_wall_textures2(t_env *env)
{
	int	fd;

	fd = 0;
    if (!(env->init.text_name[5] = ft_strdup("./images/textures/floor1.bmp")))
		return (ft_perror("Error while malloc texture name\n"));
	if ((fd = open("./images/textures/floor1.bmp", O_RDONLY)) == -1)
		env->init.textures[5] = 1;
	if (!env->init.textures[5] && close(fd))
		return (custom_error("Could not close the file in check textures\n"));
	if (!(env->init.text_name[6] = ft_strdup("./images/textures/rust.bmp")))
		return (ft_perror("Error while malloc texture name\n"));
	if ((fd = open("./images/textures/rust.bmp", O_RDONLY)) == -1)
		env->init.textures[6] = 1;
	if (!env->init.textures[6] && close(fd))
		return (custom_error("Could not close the file in check textures\n"));
	if (!(env->init.text_name[7] =
		ft_strdup("./images/textures/black_tiles.bmp")))
		return (ft_perror("Error while malloc texture name\n"));
	if ((fd = open("./images/textures/black_tiles.bmp", O_RDONLY)) == -1)
		env->init.textures[7] = 1;
	if (!env->init.textures[7] && close(fd))
		return (custom_error("Could not close the file in check textures\n"));
	if (!(env->init.text_name[8] = ft_strdup("./images/textures/rock.bmp")))
		return (ft_perror("Error while malloc texture name\n"));
	if ((fd = open("./images/textures/rock.bmp", O_RDONLY)) == -1)
		env->init.textures[8] = 1;
	if (!env->init.textures[8] && close(fd))
		return (custom_error("Could not close the file in check textures\n"));
	if (!(env->init.text_name[9] = ft_strdup("./images/textures/grass1.bmp")))
		return (ft_perror("Error while malloc texture name\n"));
	if ((fd = open("./images/textures/grass1.bmp", O_RDONLY)) == -1)
		env->init.textures[9] = 1;
	if (!env->init.textures[9] && close(fd))
		return (custom_error("Could not close the file in check textures\n"));
    return (check_wall_textures3(env));
}

int    check_wall_textures(t_env *env)
{
    int fd;

	fd = 0;
    if (!(env->init.text_name[0] = ft_strdup("./images/textures/wall0.bmp")))
		return (ft_perror("Error while malloc texture name\n"));
    if ((fd = open("./images/textures/wall0.bmp", O_RDONLY)) == -1)
        env->init.textures[0] = 1;
	if (!env->init.textures[0] && close(fd))
		return (custom_error("Could not close the file in check textures\n"));
    if (!(env->init.text_name[1] = ft_strdup("./images/textures/wall1.bmp")))
		return (ft_perror("Error while malloc texture name\n"));
	if ((fd = open("./images/textures/wall1.bmp", O_RDONLY)) == -1)
		env->init.textures[1] = 1;
	if (!env->init.textures[1] && close(fd))
		return (custom_error("Could not close the file in check textures\n"));
	if (!(env->init.text_name[2] = ft_strdup("./images/textures/wall2.bmp")))
		return (ft_perror("Error while malloc texture name\n"));
	if ((fd = open("./images/textures/wall2.bmp", O_RDONLY)) == -1)
		env->init.textures[2] = 1;
	if (!env->init.textures[2] && close(fd))
		return (custom_error("Could not close the file in check textures\n"));
	if (!(env->init.text_name[3] = ft_strdup("./images/textures/wall3.bmp")))
		return (ft_perror("Error while malloc texture name\n"));
	if ((fd = open("./images/textures/wall3.bmp", O_RDONLY)) == -1)
		env->init.textures[3] = 1;
	if (!env->init.textures[3] && close(fd))
		return (custom_error("Could not close the file in check textures\n"));
	if (!(env->init.text_name[4] = ft_strdup("./images/textures/floor0.bmp")))
		return (ft_perror("Error while malloc texture name\n"));
	if ((fd = open("./images/textures/floor0.bmp",O_RDONLY)) == -1)
		env->init.textures[4] = 1;
	if (!env->init.textures[4] && close(fd))
		return (custom_error("Could not close the file in check textures\n"));
	return (check_wall_textures2(env));
}
