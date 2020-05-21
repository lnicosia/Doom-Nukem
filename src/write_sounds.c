/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_sounds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 13:48:58 by sipatry           #+#    #+#             */
/*   Updated: 2020/03/09 10:39:28 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "bmp_parser.h"

int		write_sound(int file, int fd, char *name)
{
	unsigned char	resource[10000];
	unsigned char	header[44];
	int				ret;
	int32_t			size;

	if (read(file, header, 44) != 44)
	{
		if (close(file))
			return (custom_error(
			"Invalid wav file and could not close the file\n"));
			return (custom_error("Invalid wav file\n"));
	}
	size = read_int32(header, 4) + 8;
	ft_dprintf(fd, "%s\n%d\n", name, size);
	write(fd, header, 44);
	while ((ret = (read(file, resource, 10000))) > 0)
		write(fd, resource, ret);
	write(fd, "\n", 1);
	if (close(file))
		return (custom_error("Could not close the wav file\n"));
	return (0);
}

int		write_sounds2(int fd, t_env *env)
{
	int	i;
	int	file;

	i = 0;
	while (i < NB_SOUNDS)
	{
		if ((file = open(env->init.sounds_names[i], O_RDONLY)) < 0)
			return (custom_error("Could not open %s to save it\n",
			env->init.sounds_names[i]));
			if (write_sound(file, fd, env->init.sounds_names[i]))
			return (-1);
		i++;
	}
	return (0);
}

int		write_sounds(int fd, t_env *env)
{
	int	i;
	int	file;

	ft_printf("Saving musics and sounds..\n");
	ft_dprintf(fd, "S %d\n", NB_MUSICS + NB_SOUNDS);
	i = 0;
	while (i < NB_MUSICS)
	{
		if ((file = open(env->init.musics_names[i], O_RDONLY)) < 0)
			return (custom_error("Could not open %s to save it\n",
			env->init.musics_names[i]));
			if (write_sound(file, fd, env->init.musics_names[i]))
			return (-1);
		i++;
	}
	return (write_sounds2(fd, env));
}
