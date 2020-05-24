/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_directories.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 11:31:07 by marvin            #+#    #+#             */
/*   Updated: 2020/05/08 11:31:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include <sys/stat.h>

int		check_existing_directory(char *path)
{
	int	fd;

	if ((fd = open(path, O_RDONLY, O_DIRECTORY)) == -1)
	{
		ft_printf("%s directory not found, creating it..\n", path);
		if (mkdir(path, 0000700))
			return (custom_error("Could not create %s directory\n", path));
	}
	else if (close(fd))
		return (custom_error("Could not close %s directory\n", path));
	return (0);
}

int		check_images_directory(void)
{
	if (check_existing_directory("./images"))
		return (-1);
	if (check_existing_directory("./images/HUD"))
		return (-1);
	if (check_existing_directory("./images/textures"))
		return (-1);
	if (check_existing_directory("./images/ui"))
		return (-1);
	if (check_existing_directory("./images/sprites"))
		return (-1);
	if (check_existing_directory("./images/skyboxes"))
		return (-1);
	return (0);
}

int		check_fonts_directory(void)
{
	if (check_existing_directory("./fonts"))
		return (-1);
	if (check_existing_directory("./fonts/alice"))
		return (-1);
	if (check_existing_directory("./fonts/amazdoom"))
		return (-1);
	if (check_existing_directory("./fonts/bebas_neue"))
		return (-1);
	if (check_existing_directory("./fonts/lato"))
		return (-1);
	if (check_existing_directory("./fonts/montserrat"))
		return (-1);
	if (check_existing_directory("./fonts/playfair-display"))
		return (-1);
	return (0);
}

int		check_directories(void)
{
	if (check_images_directory())
		return (-1);
	if (check_fonts_directory())
		return (-1);
	if (check_existing_directory("./audio"))
		return (-1);
	return (0);
}
