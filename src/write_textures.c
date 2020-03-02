/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 10:16:20 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/28 17:58:18 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "bmp_parser.h"

int		writing_texture(int file, int fd, char *name)
{
	unsigned char	resource[10000];
	unsigned char	header[14];
	int				ret;
	int32_t		size;

	if (read(file, header, 14) != 14)
		return (ft_printf("Invalid bmp file\n"));
	size = read_int32(header, 2);
	ft_dprintf(fd, "%s\n%d\n", name, size);
	write(fd, header, 14);
	while ((ret = (read(file, resource, 10000))) > 0)
		write(fd, resource, ret);
	write(fd, "\n", 1);
	if (close(file))
		return (ft_printf("Could not close the resource\n"));
	return (0);
}

int		write_textures1(int fd)
{
	int		file;
	
	if ((file = open("./images/textures/wall0.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open texture\n"));
	if (writing_texture(file, fd, "./images/textures/wall0.bmp"))
		return (-1);
	if ((file = open("./images/textures/wall1.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open texture\n"));
	if (writing_texture(file, fd, "./images/textures/wall1.bmp"))
		return (-1);
	if ((file = open("./images/textures/wall2.bmp", O_RDONLY)) < 0)
		return (ft_printf("problem with read ressource\n"));
	if (writing_texture(file, fd, "./images/textures/wall2.bmp"))
		return (-1);
	if ((file = open("./images/textures/wall3.bmp", O_RDONLY)) < 0)
		return (ft_printf("problem with read ressource\n"));
	if (writing_texture(file, fd, "./images/textures/wall2.bmp"))
		return (-1);
	if ((file = open("./images/textures/floor0.bmp", O_RDONLY)) < 0)
		return (ft_printf("problem with read ressource\n"));
	if (writing_texture(file, fd, "./images/textures/wall2.bmp"))
		return (-1);
	return (0);
}

int		write_textures2(int fd)
{
	int		file;
	
	if ((file = open("images/textures/floor1.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open texture\n"));
	if (writing_texture(file, fd, "images/textures/floor1.bmp"))
		return (-1);
	if ((file = open("images/textures/rust.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open texture\n"));
	if (writing_texture(file, fd, "images/textures/rust.bmp"))
		return (-1);
	if ((file = open("images/textures/black_tiles.bmp", O_RDONLY)) < 0)
		return (ft_printf("problem with read ressource\n"));
	if (writing_texture(file, fd, "images/textures/black_tiles.bmp"))
		return (-1);
	if ((file = open("images/textures/rock.bmp", O_RDONLY)) < 0)
		return (ft_printf("problem with read ressource\n"));
	if (writing_texture(file, fd, "images/textures/rock.bmp"))
		return (-1);
	if ((file = open("images/textures/grass1.bmp", O_RDONLY)) < 0)
		return (ft_printf("problem with read ressource\n"));
	if (writing_texture(file, fd, "images/textures/grass1.bmp"))
		return (-1);
	return (0);
}

int		write_textures3(int fd)
{
	int		file;
	
	if ((file = open("images/textures/grass2.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open texture\n"));
	if (writing_texture(file, fd, "images/textures/grass2.bmp"))
		return (-1);
	if ((file = open("images/textures/grass3.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open texture\n"));
	if (writing_texture(file, fd, "images/textures/grass3.bmp"))
		return (-1);
	if ((file = open("images/textures/tiles.bmp", O_RDONLY)) < 0)
		return (ft_printf("problem with read ressource\n"));
	if (writing_texture(file, fd, "images/textures/tiles.bmp"))
		return (-1);
	if ((file = open("images/textures/sand.bmp", O_RDONLY)) < 0)
		return (ft_printf("problem with read ressource\n"));
	if (writing_texture(file, fd, "images/textures/sand.bmp"))
		return (-1);
	if ((file = open("images/textures/grey.bmp", O_RDONLY)) < 0)
		return (ft_printf("problem with read ressource\n"));
	if (writing_texture(file, fd, "images/textures/grey.bmp"))
		return (-1);
	return (0);
}