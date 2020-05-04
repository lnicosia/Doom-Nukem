/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_skyboxes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:09:54 by sipatry           #+#    #+#             */
/*   Updated: 2020/05/01 12:19:36 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "save.h"

int		write_skybox1(int fd, int file)
{
	if ((file = open("./images/skyboxes/back.bmp", O_RDONLY)) < 0)
		return (custom_error("Could not open back.bmp\n"));
	if (writing_bmp(file, fd, "./images/skyboxes/back.bmp"))
		return (-1);
	if ((file = open("./images/skyboxes/bottom.bmp", O_RDONLY)) < 0)
		return (custom_error("Could not open bottom bmp\n"));
	if (writing_bmp(file, fd, "./images/skyboxes/bottom.bmp"))
		return (-1);
	if ((file = open("./images/skyboxes/front.bmp", O_RDONLY)) < 0)
		return (custom_error("Could not open front bmp\n"));
	if (writing_bmp(file, fd, "./images/skyboxes/front.bmp"))
		return (-1);
	if ((file = open("./images/skyboxes/left.bmp", O_RDONLY)) < 0)
		return (custom_error("Could not open left.bmp\n"));
	if (writing_bmp(file, fd, "./images/skyboxes/left.bmp"))
		return (-1);
	if ((file = open("./images/skyboxes/right.bmp", O_RDONLY)) < 0)
		return (custom_error("Could not open right.bmp\n"));
	if (writing_bmp(file, fd, "./images/skyboxes/right.bmp"))
		return (-1);
	if ((file = open("./images/skyboxes/top.bmp", O_RDONLY)) < 0)
		return (custom_error("Could not open top.bmp\n"));
	if (writing_bmp(file, fd, "./images/skyboxes/top.bmp"))
		return (-1);
	return (0);
}

int		write_skybox2(int fd, int file)
{
	if ((file = open("./images/skyboxes/nebula_back.bmp", O_RDONLY)) < 0)
		return (custom_error("Could not open nebula_back.bmp\n"));
	if (writing_bmp(file, fd, "./images/skyboxes/nebula_back.bmp"))
		return (-1);
	if ((file = open("./images/skyboxes/nebula_bottom.bmp", O_RDONLY)) < 0)
		return (custom_error("Could not open nebula_bottom bmp\n"));
	if (writing_bmp(file, fd, "./images/skyboxes/nebula_bottom.bmp"))
		return (-1);
	if ((file = open("./images/skyboxes/nebula_front.bmp", O_RDONLY)) < 0)
		return (custom_error("Could not open nebula_front bmp\n"));
	if (writing_bmp(file, fd, "./images/skyboxes/nebula_front.bmp"))
		return (-1);
	if ((file = open("./images/skyboxes/nebula_left.bmp", O_RDONLY)) < 0)
		return (custom_error("Could not open nebula_left.bmp\n"));
	if (writing_bmp(file, fd, "./images/skyboxes/nebula_left.bmp"))
		return (-1);
	if ((file = open("./images/skyboxes/nebula_right.bmp", O_RDONLY)) < 0)
		return (custom_error("Could not open nebula_right.bmp\n"));
	if (writing_bmp(file, fd, "./images/skyboxes/nebula_right.bmp"))
		return (-1);
	if ((file = open("./images/skyboxes/nebula_top.bmp", O_RDONLY)) < 0)
		return (custom_error("Could not open nebula_top.bmp\n"));
	if (writing_bmp(file, fd, "./images/skyboxes/nebula_top.bmp"))
		return (-1);
	return (0);
}

int		write_skybox3(int fd, int file)
{
	if ((file = open("./images/skyboxes/night_back.bmp", O_RDONLY)) < 0)
		return (custom_error("Could not open night_back.bmp\n"));
	if (writing_bmp(file, fd, "./images/skyboxes/night_back.bmp"))
		return (-1);
	if ((file = open("./images/skyboxes/night_bottom.bmp", O_RDONLY)) < 0)
		return (custom_error("Could not open night_bottom bmp\n"));
	if (writing_bmp(file, fd, "./images/skyboxes/night_bottom.bmp"))
		return (-1);
	if ((file = open("./images/skyboxes/night_front.bmp", O_RDONLY)) < 0)
		return (custom_error("Could not open night_front bmp\n"));
	if (writing_bmp(file, fd, "./images/skyboxes/night_front.bmp"))
		return (-1);
	if ((file = open("./images/skyboxes/night_left.bmp", O_RDONLY)) < 0)
		return (custom_error("Could not open night_left.bmp\n"));
	if (writing_bmp(file, fd, "./images/skyboxes/night_left.bmp"))
		return (-1);
	if ((file = open("./images/skyboxes/night_right.bmp", O_RDONLY)) < 0)
		return (custom_error("Could not open night_right.bmp\n"));
	if (writing_bmp(file, fd, "./images/skyboxes/night_right.bmp"))
		return (-1);
	if ((file = open("./images/skyboxes/night_top.bmp", O_RDONLY)) < 0)
		return (custom_error("Could not open night_top.bmp\n"));
	if (writing_bmp(file, fd, "./images/skyboxes/night_top.bmp"))
		return (-1);
	return (0);
}
