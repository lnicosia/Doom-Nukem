/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_fonts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:16:31 by sipatry           #+#    #+#             */
/*   Updated: 2020/03/06 14:46:24 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "sys/stat.h"

int     find_size(char *name)
{
    struct stat st;

    if(stat(name, &st)==0)
        return ((int)st.st_size);
    else
        return (0);
}

int     write_font(int file, int fd, char *name)
{
    int size;
   	unsigned char	resource[10000];
	int				ret;
    int             check_size;

    check_size = 0;
    if (!(size = find_size(name)))
        return (ft_printf("Couldn't find the font file size\n"));
    ft_dprintf(fd, "%s\n%d\n", name, size);
    while ((ret = (read(file, resource, 10000))) > 0)
    {
        check_size += ret;
        write(fd, resource, ret);
    }
    write(fd, "\n", 1);
    if (check_size != size)
        return (ft_printf("Invalid read size for a font file\n"));
    if (close(file))
		return (ft_printf("Could not close the font file\n"));
    return (0);
}

int     write_fonts1(int fd, int file)
{
    if ((file = open("./fonts/amazdoom/AmazDoomLeft.ttf", O_RDONLY)) < 0)
		return (ft_printf("Could not open the font\n"));
	if (write_font(file, fd, "./fonts/amazdoom/AmazDoomLeft.ttf"))
		return (-1);
    if ((file = open("./fonts/alice/Alice-Regular.ttf", O_RDONLY)) < 0)
		return (ft_printf("Could not open the font\n"));
	if (write_font(file, fd, "./fonts/alice/Alice-Regular.ttf"))
		return (-1);
    if ((file = open("./fonts/bebas_neue/BebasNeue-Regular.ttf", O_RDONLY)) < 0)
		return (ft_printf("Could not open the font\n"));
	if (write_font(file, fd, "./fonts/bebas_neue/BebasNeue-Regular.ttf"))
		return (-1);
    if ((file = open("./fonts/montserrat/Montserrat-Regular.ttf", O_RDONLY)) < 0)
		return (ft_printf("Could not open the font\n"));
	if (write_font(file, fd, "./fonts/montserrat/Montserrat-Regular.ttf"))
		return (-1);
    if ((file = open("./fonts/playfair-display/PlayfairDisplay-Regular.ttf", O_RDONLY)) < 0)
		return (ft_printf("Could not open the font\n"));
	if (write_font(file, fd, "./fonts/playfair-display/PlayfairDisplay-Regular.ttf"))
		return (-1);
	return (0);
}

int write_fonts2(int fd, int file)
{
    if ((file = open("./fonts/lato/Lato-Regular.ttf", O_RDONLY)) < 0)
		return (ft_printf("Could not open the font\n"));
	if (write_font(file, fd, "./fonts/lato/Lato-Regular.ttf"))
		return (-1);
    if ((file = open("./fonts/lato/Lato-Bold.ttf", O_RDONLY)) < 0)
		return (ft_printf("Could not open the font\n"));
	if (write_font(file, fd, "./fonts/lato/Lato-Bold.ttf"))
		return (-1);
    if ((file = open("./fonts/lato/Lato-Black.ttf", O_RDONLY)) < 0)
		return (ft_printf("Could not open the font\n"));
	if (write_font(file, fd, "./fonts/lato/Lato-Black.ttf"))
		return (-1);
    return (0);
}