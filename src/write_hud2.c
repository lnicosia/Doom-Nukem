/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hud2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:55:51 by sipatry           #+#    #+#             */
/*   Updated: 2020/05/01 12:14:25 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "save.h"

int		write_hud6(int fd, int file)
{
	if ((file = open("./images/HUD/shot6.bmp", O_RDONLY)) < 0)
		return (custom_error("Could not open the font\n"));
	if (writing_bmp(file, fd, "./images/HUD/shot6.bmp"))
		return (-1);
	if ((file = open("./images/HUD/shot7.bmp", O_RDONLY)) < 0)
		return (custom_error("Could not open the font\n"));
	if (writing_bmp(file, fd, "./images/HUD/shot7.bmp"))
		return (-1);
	if ((file = open("./images/HUD/shot8.bmp", O_RDONLY)) < 0)
		return (custom_error("Could not open the font\n"));
	if (writing_bmp(file, fd, "./images/HUD/shot8.bmp"))
		return (-1);
	if ((file = open("./images/HUD/shot9.bmp", O_RDONLY)) < 0)
		return (custom_error("Could not open the font\n"));
	if (writing_bmp(file, fd, "./images/HUD/shot9.bmp"))
		return (-1);
	if ((file = open("./images/HUD/shot10.bmp", O_RDONLY)) < 0)
		return (custom_error("Could not open the font\n"));
	if (writing_bmp(file, fd, "./images/HUD/shot10.bmp"))
		return (-1);
	return (0);
}

int		write_hud7(int fd, int file)
{
	if ((file = open("./images/HUD/shot11.bmp", O_RDONLY)) < 0)
		return (custom_error("Could not open the font\n"));
	if (writing_bmp(file, fd, "./images/HUD/shot11.bmp"))
		return (-1);
	if ((file = open("./images/HUD/shot12.bmp", O_RDONLY)) < 0)
		return (custom_error("Could not open the font\n"));
	if (writing_bmp(file, fd, "./images/HUD/shot12.bmp"))
		return (-1);
	if ((file = open("./images/HUD/shot13.bmp", O_RDONLY)) < 0)
		return (custom_error("Could not open the font\n"));
	if (writing_bmp(file, fd, "./images/HUD/shot13.bmp"))
		return (-1);
	if ((file = open("./images/HUD/shot14.bmp", O_RDONLY)) < 0)
		return (custom_error("Could not open the font\n"));
	if (writing_bmp(file, fd, "./images/HUD/shot14.bmp"))
		return (-1);
	if ((file = open("./images/HUD/shot15.bmp", O_RDONLY)) < 0)
		return (custom_error("Could not open the font\n"));
	if (writing_bmp(file, fd, "./images/HUD/shot15.bmp"))
		return (-1);
	return (0);
}

int		write_hud8(int fd, int file)
{
	if ((file = open("./images/HUD/gun_1.bmp", O_RDONLY)) < 0)
		return (ft_perror("Could not open the font\n"));
	if (writing_bmp(file, fd, "./images/HUD/gun_1.bmp"))
		return (-1);
	if ((file = open("./images/HUD/gun_2.bmp", O_RDONLY)) < 0)
		return (ft_perror("Could not open the font\n"));
	if (writing_bmp(file, fd, "./images/HUD/gun_2.bmp"))
		return (-1);
	if ((file = open("./images/HUD/gun_3.bmp", O_RDONLY)) < 0)
		return (ft_perror("Could not open the font\n"));
	if (writing_bmp(file, fd, "./images/HUD/gun_3.bmp"))
		return (-1);
	return (0);
}

int		write_hud9(int fd, int file)
{
	if ((file = open("./images/HUD/gun_4.bmp", O_RDONLY)) < 0)
		return (ft_perror("Could not open the font\n"));
	if (writing_bmp(file, fd, "./images/HUD/gun_4.bmp"))
		return (-1);
	if ((file = open("./images/HUD/gun_5.bmp", O_RDONLY)) < 0)
		return (ft_perror("Could not open the font\n"));
	if (writing_bmp(file, fd, "./images/HUD/gun_5.bmp"))
		return (-1);
	if ((file = open("./images/HUD/gun_6.bmp", O_RDONLY)) < 0)
		return (ft_perror("Could not open the font\n"));
	if (writing_bmp(file, fd, "./images/HUD/gun_6.bmp"))
		return (-1);
	return (0);
}
