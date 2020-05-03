/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hud.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:35:43 by sipatry           #+#    #+#             */
/*   Updated: 2020/05/01 12:14:47 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "save.h"

int		write_hud1(int fd, int file)
{
	if ((file = open("./images/HUD/hud.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open the font\n"));
	if (writing_bmp(file, fd, "./images/HUD/hud.bmp"))
		return (-1);
	if ((file = open("./images/HUD/Ammo_hud.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open the font\n"));
	if (writing_bmp(file, fd, "./images/HUD/Ammo_hud.bmp"))
		return (-1);
	if ((file = open("./images/HUD/Life_armor_hud.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open the font\n"));
	if (writing_bmp(file, fd, "./images/HUD/Life_armorhud.bmp"))
		return (-1);
	if ((file = open("./images/HUD/raygun1.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open the font\n"));
	if (writing_bmp(file, fd, "./images/HUD/raygun1.bmp"))
		return (-1);
	if ((file = open("./images/HUD/raygun2.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open the font\n"));
	if (writing_bmp(file, fd, "./images/HUD/raygun2.bmp"))
		return (-1);
	return (0);
}

int		write_hud2(int fd, int file)
{
	if ((file = open("./images/HUD/raygun3.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open the font\n"));
	if (writing_bmp(file, fd, "./images/HUD/raygun3.bmp"))
		return (-1);
	if ((file = open("./images/HUD/raygun4.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open the font\n"));
	if (writing_bmp(file, fd, "./images/HUD/raygun4.bmp"))
		return (-1);
	if ((file = open("./images/HUD/raygun5.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open the font\n"));
	if (writing_bmp(file, fd, "./images/HUD/raygun5.bmp"))
		return (-1);
	if ((file = open("./images/HUD/raygun6.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open the font\n"));
	if (writing_bmp(file, fd, "./images/HUD/raygun6.bmp"))
		return (-1);
	if ((file = open("./images/HUD/raygun7.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open the font\n"));
	if (writing_bmp(file, fd, "./images/HUD/raygun1.bmp"))
		return (-1);
	return (0);
}

int		write_hud3(int fd, int file)
{
	if ((file = open("./images/HUD/raygun7.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open the font\n"));
	if (writing_bmp(file, fd, "./images/HUD/raygun1.bmp"))
		return (-1);
	if ((file = open("./images/HUD/Gatling_1.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open the font\n"));
	if (writing_bmp(file, fd, "./images/HUD/Gatling_1.bmp"))
		return (-1);
	if ((file = open("./images/HUD/Gatling_2.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open the font\n"));
	if (writing_bmp(file, fd, "./images/HUD/Gatling_2.bmp"))
		return (-1);
	if ((file = open("./images/HUD/Gatling_3.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open the font\n"));
	if (writing_bmp(file, fd, "./images/HUD/Gatling_3.bmp"))
		return (-1);
	if ((file = open("./images/HUD/Gatling_4.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open the font\n"));
	if (writing_bmp(file, fd, "./images/HUD/Gatling_4.bmp"))
		return (-1);
	return (0);
}

int		write_hud4(int fd, int file)
{
	if ((file = open("./images/HUD/Gatling_5.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open the font\n"));
	if (writing_bmp(file, fd, "./images/HUD/Gatling_5.bmp"))
		return (-1);
	if ((file = open("./images/HUD/Gatling_6.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open the font\n"));
	if (writing_bmp(file, fd, "./images/HUD/Gatling_6.bmp"))
		return (-1);
	return (0);
}

int		write_hud5(int fd, int file)
{
	if ((file = open("./images/HUD/shot1.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open the font\n"));
	if (writing_bmp(file, fd, "./images/HUD/shot1.bmp"))
		return (-1);
	if ((file = open("./images/HUD/shot2.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open the font\n"));
	if (writing_bmp(file, fd, "./images/HUD/shot2.bmp"))
		return (-1);
	if ((file = open("./images/HUD/shot3.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open the font\n"));
	if (writing_bmp(file, fd, "./images/HUD/shot3.bmp"))
		return (-1);
	if ((file = open("./images/HUD/shot4.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open the font\n"));
	if (writing_bmp(file, fd, "./images/HUD/shot4.bmp"))
		return (-1);
	if ((file = open("./images/HUD/shot5.bmp", O_RDONLY)) < 0)
		return (ft_printf("Could not open the font\n"));
	if (writing_bmp(file, fd, "./images/HUD/shot5.bmp"))
		return (-1);
	return (0);
}
