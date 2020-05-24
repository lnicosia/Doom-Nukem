/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 10:16:20 by sipatry           #+#    #+#             */
/*   Updated: 2020/05/11 17:47:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "save.h"
#include "bmp_parser.h"

int		write_textures1(int fd)
{
	int		file;

	if ((file = open("./images/textures/wall0.bmp", O_RDONLY)) < 0)
		return (custom_error("Could not open texture\n"));
	if (writing_bmp(file, fd, "./images/textures/wall0.bmp"))
		return (-1);
	if ((file = open("./images/textures/wall1.bmp", O_RDONLY)) < 0)
		return (custom_error("Could not open texture\n"));
	if (writing_bmp(file, fd, "./images/textures/wall1.bmp"))
		return (-1);
	if ((file = open("./images/textures/wall2.bmp", O_RDONLY)) < 0)
		return (custom_error("problem with read ressource\n"));
	if (writing_bmp(file, fd, "./images/textures/wall2.bmp"))
		return (-1);
	if ((file = open("./images/textures/wall3.bmp", O_RDONLY)) < 0)
		return (custom_error("problem with read ressource\n"));
	if (writing_bmp(file, fd, "./images/textures/wall3.bmp"))
		return (-1);
	if ((file = open("./images/textures/floor0.bmp", O_RDONLY)) < 0)
		return (custom_error("problem with read ressource\n"));
	if (writing_bmp(file, fd, "./images/textures/floor0.bmp"))
		return (-1);
	return (0);
}

int		write_textures2(int fd)
{
	int		file;

	if ((file = open("./images/textures/floor1.bmp", O_RDONLY)) < 0)
		return (custom_error("Could not open texture\n"));
	if (writing_bmp(file, fd, "./images/textures/floor1.bmp"))
		return (-1);
	if ((file = open("./images/textures/rust.bmp", O_RDONLY)) < 0)
		return (custom_error("Could not open texture\n"));
	if (writing_bmp(file, fd, "./images/textures/rust.bmp"))
		return (-1);
	if ((file = open("./images/textures/black_tiles.bmp", O_RDONLY)) < 0)
		return (custom_error("problem with read ressource\n"));
	if (writing_bmp(file, fd, "./images/textures/black_tiles.bmp"))
		return (-1);
	if ((file = open("./images/textures/rock.bmp", O_RDONLY)) < 0)
		return (custom_error("problem with read ressource\n"));
	if (writing_bmp(file, fd, "./images/textures/rock.bmp"))
		return (-1);
	if ((file = open("./images/textures/grass1.bmp", O_RDONLY)) < 0)
		return (custom_error("problem with read ressource\n"));
	if (writing_bmp(file, fd, "./images/textures/grass1.bmp"))
		return (-1);
	return (0);
}

int		write_textures3(int fd)
{
	int		file;

	if ((file = open("./images/textures/grass2.bmp", O_RDONLY)) < 0)
		return (custom_error("Could not open texture\n"));
	if (writing_bmp(file, fd, "./images/textures/grass2.bmp"))
		return (-1);
	if ((file = open("./images/textures/grass3.bmp", O_RDONLY)) < 0)
		return (custom_error("Could not open texture\n"));
	if (writing_bmp(file, fd, "./images/textures/grass3.bmp"))
		return (-1);
	if ((file = open("./images/textures/tiles.bmp", O_RDONLY)) < 0)
		return (custom_error("problem with read ressource\n"));
	if (writing_bmp(file, fd, "./images/textures/tiles.bmp"))
		return (-1);
	if ((file = open("./images/textures/sand.bmp", O_RDONLY)) < 0)
		return (custom_error("problem with read ressource\n"));
	if (writing_bmp(file, fd, "./images/textures/sand.bmp"))
		return (-1);
	if ((file = open("./images/textures/grey.bmp", O_RDONLY)) < 0)
		return (custom_error("problem with read ressource\n"));
	if (writing_bmp(file, fd, "./images/textures/grey.bmp"))
		return (-1);
	return (0);
}
