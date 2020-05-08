/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_fonts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:16:31 by sipatry           #+#    #+#             */
/*   Updated: 2020/05/01 12:18:12 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "sys/stat.h"

int		find_size(char *name)
{
	struct stat st;

	if (stat(name, &st) == 0)
		return ((int)st.st_size);
	else
		return (0);
}

int		write_font(int file, int fd, char *name)
{
	int				size;
	unsigned char	resource[10000];
	int				ret;
	int				check_size;

	check_size = 0;
	if (!(size = find_size(name)))
		return (custom_error("Couldn't find the font file size\n"));
	ft_dprintf(fd, "%s\n%d\n", name, size);
	//ft_printf("data: %s\n%d\n", name, size);
	while ((ret = (read(file, resource, 10000))) > 0)
	{
		check_size += ret;
		write(fd, resource, ret);
	}
	write(fd, "\n", 1);
	if (check_size != size)
		return (custom_error("Invalid read size for a font file\n"));
	if (close(file))
		return (custom_error("Could not close the font file\n"));
	return (0);
}

int		write_fonts1(int fd, int file)
{
	if ((file = open("./fonts/AmazDoomLeft.ttf", O_RDONLY)) < 0)
		return (custom_error("Could not open the font\n"));
	if (write_font(file, fd, "./fonts/AmazDoomLeft.ttf"))
		return (-1);
	if ((file = open("./fonts/Alice-Regular.ttf", O_RDONLY)) < 0)
		return (custom_error("Could not open the font\n"));
	if (write_font(file, fd, "./fonts/Alice-Regular.ttf"))
		return (-1);
	if ((file = open("./fonts/BebasNeue-Regular.ttf", O_RDONLY)) < 0)
		return (custom_error("Could not open the font\n"));
	if (write_font(file, fd, "./fonts/BebasNeue-Regular.ttf"))
		return (-1);
	if ((file = open("./fonts/Montserrat-Regular.ttf", O_RDONLY)) < 0)
		return (custom_error("Could not open the font\n"));
	if (write_font(file, fd, "./fonts/Montserrat-Regular.ttf"))
		return (-1);
	if ((file = open("./fonts/PlayfairDisplay-Regular.ttf", O_RDONLY)) < 0)
		return (custom_error("Could not open the font\n"));
	if (write_font(file, fd, "./fonts/PlayfairDisplay-Regular.ttf"))
		return (-1);
	return (0);
}

int		write_fonts2(int fd, int file)
{
	if ((file = open("./fonts/Lato-Regular.ttf", O_RDONLY)) < 0)
		return (custom_error("Could not open the font\n"));
	if (write_font(file, fd, "./fonts/Lato-Regular.ttf"))
		return (-1);
	if ((file = open("./fonts/Lato-Bold.ttf", O_RDONLY)) < 0)
		return (custom_error("Could not open the font\n"));
	if (write_font(file, fd, "./fonts/Lato-Bold.ttf"))
		return (-1);
	if ((file = open("./fonts/Lato-Black.ttf", O_RDONLY)) < 0)
		return (custom_error("Could not open the font\n"));
	if (write_font(file, fd, "./fonts/Lato-Black.ttf"))
		return (-1);
	return (0);
}
