/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 11:50:11 by sipatry           #+#    #+#             */
/*   Updated: 2020/05/01 12:19:06 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "save.h"

int		write_sprites1(int fd)
{
	int file;

	if ((file = open("./images/sprites/bullet_hole.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open bullet hole bmp\n"));
	if (writing_bmp(file, fd, "./images/sprites/bullet_hole.bmp"))
		return (-1);
	if ((file = open("./images/sprites/button_off.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open button off bmp\n"));
	if (writing_bmp(file, fd, "./images/sprites/button_off.bmp"))
		return (-1);
	if ((file = open("./images/sprites/button_on.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open button on bmp\n"));
	if (writing_bmp(file, fd, "./images/sprites/button_on.bmp"))
		return (-1);
	if ((file = open("./images/sprites/camera.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open camera.bmp\n"));
	if (writing_bmp(file, fd, "./images/sprites/camera.bmp"))
		return (-1);
	if ((file = open("./images/sprites/MIDSPACE.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open MIDPSACE.bmp\n"));
	if (writing_bmp(file, fd, "./images/sprites/MIDSPACE.bmp"))
		return (-1);
	return (0);
}

int		write_sprites2(int fd)
{
	int file;

	if ((file = open("./images/sprites/cyber_demon.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open cyber_demon.bmp\n"));
	if (writing_bmp(file, fd, "./images/sprites/cyber_demon.bmp"))
		return (-1);
	if ((file = open("./images/sprites/lost_soul.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open lost_soul.bmp\n"));
	if (writing_bmp(file, fd, "./images/sprites/lost_soul.bmp"))
		return (-1);
	if ((file = open("./images/sprites/doom_guy.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open doom_guy.bmp\n"));
	if (writing_bmp(file, fd, "./images/sprites/doom_guy.bmp"))
		return (-1);
	if ((file = open("./images/sprites/doom_guy_face.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open doom_guy_face.bmp\n"));
	if (writing_bmp(file, fd, "./images/sprites/doom_guy_face.bmp"))
		return (-1);
	return (0);
}

int		write_sprites3(int fd)
{
	int file;

	if ((file = open("./images/sprites/objects_sprites.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open objects_sprites.bmp\n"));
	if (writing_bmp(file, fd, "./images/sprites/objects_sprites.bmp"))
		return (-1);
	if ((file = open("./images/sprites/projectiles_sprites.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open projectiles_sprites\n"));
	if (writing_bmp(file, fd, "./images/sprites/projectiles_sprites.bmp"))
		return (-1);
	if ((file = open("./images/sprites/sprite_sheet.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open sprite_sheet.bmp\n"));
	if (writing_bmp(file, fd, "./images/sprites/sprite_sheet.bmp"))
		return (-1);
	if ((file = open("./images/sprites/raygun.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open raygun.bmp\n"));
	if (writing_bmp(file, fd, "./images/sprites/raygun.bmp"))
		return (-1);
	return (0);
}
