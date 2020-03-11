/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_resources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 10:06:40 by sipatry           #+#    #+#             */
/*   Updated: 2020/03/11 11:45:09 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "bmp_parser.h"

int		writing_bmp(int file, int fd, char *name)
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

int		write_textures(int fd, t_env *env)
{
	(void)env;
	ft_printf("saving textures\n");
	ft_dprintf(fd, "T %d\n", MAX_WALL_TEXTURE);
	if (write_textures1(fd))
		return (-1);
	if (write_textures2(fd))
		return (-1);
	if (write_textures3(fd))
		return (-1);
	return (0);
}

int		write_sprites(int fd)
{
	ft_printf("saving sprites\n");
	ft_dprintf(fd, "SP %d\n", NB_BMP_SPRITES);
	if (write_sprites1(fd))
		return (-1);
	if (write_sprites2(fd))
		return (-1);
	if (write_sprites3(fd))
		return (-1);
	return (0);
}

int		write_skyboxes(int fd, int file)
{
	ft_printf("saving skyboxes\n");
	ft_dprintf(fd, "SKY %d\n", MAX_SKYBOX * 6);
	if (write_skybox1(fd, file))
		return (-1);
	if (write_skybox2(fd, file))
		return (-1);
	if (write_skybox3(fd, file))
		return (-1);
	return (0);
}

int		write_fonts(int fd, int file)
{
	ft_printf("saving fonts\n");
	ft_dprintf(fd, "F %d\n", NB_FONTS);
	if (write_fonts1(fd, file))
		return (-1);
	if (write_fonts2(fd, file))
		return (-1);
	return (0);
}

int		write_hud(int fd, int file)
{
	ft_printf("saving hud files\n");
	ft_dprintf(fd, "H %d\n", NB_HUD_FILES);
	if (write_hud1(fd, file))
		return (-1);
	if (write_hud2(fd, file))
		return (-1);
	if (write_hud3(fd, file))
		return (-1);
	if (write_hud4(fd, file))
		return (-1);
	if (write_hud5(fd, file))
		return (-1);
	if (write_hud6(fd, file))
		return (-1);
	if (write_hud7(fd, file))
		return (-1);
	return (0);	
}

int		write_resources(int fd, t_env *env)
{
	int file;

	(void)env;
	file = 0;
	if (write_textures(fd, env))
		return (-1);
	if (write_sprites(fd))
		return (-1);
	if (write_skyboxes(fd, file))
		return (-1);
	if (write_hud(fd, file))
		return (-1);
	if (write_sounds(fd, env))
		return (-1);
	if (write_fonts(fd, file))
		return (-1);
	return (0);
}