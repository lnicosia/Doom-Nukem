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
	int32_t		size;

	if (read(file, header, 44) != 44)
		return (ft_printf("Invalid wav file\n"));
	size = read_int32(header, 4);
	ft_dprintf(fd, "%s\n%d\n", name, size);
	write(fd, header, 44);
	while ((ret = (read(file, resource, 10000))) > 0)
		write(fd, resource, ret);
	write(fd, "\n", 1);
	if (close(file))
		return (ft_printf("Could not close the wav file\n"));
	return (0);
}

int		write_sounds(int fd, t_env *env)
{
	int	file;

	(void)env;
	ft_printf("saving musics and sounds\n");
	ft_dprintf(fd, "S %d\n", NB_MUSICS + NB_SOUNDS);
	if ((file = open("./audio/Mt_Erebus.wav", O_RDONLY)) < 0)
		return (ft_printf("Could not open music Mt_Erebus\n"));
	if (write_sound(file, fd, "./audio/Mt_Erebus.wav"))
		return (-1);
	if ((file = open("./audio/bim_bam_boum.wav", O_RDONLY)) < 0)
		return (ft_printf("Could not open music bim bam boum\n"));
	if (write_sound(file, fd, "./audio/bim_bam_boum.wav"))
		return (-1);
	if ((file = open("./audio/at_dooms_gate.wav", O_RDONLY)) < 0)
		return (ft_printf("Could not open music at dooms gate\n"));
	if (write_sound(file, fd, "./audio/at_dooms_gate.wav"))
		return (-1);
	if ((file = open("./audio/raygun_shot.wav", O_RDONLY)) < 0)
		return (ft_printf("Could not open raygun sound\n"));
	if (write_sound(file, fd, "./audio/raygun_shot.wav"))
		return (-1);
	if ((file = open("./audio/shotgun_shot.wav", O_RDONLY)) < 0)
		return (ft_printf("Could not open shotgun sound\n"));
	if (write_sound(file, fd, "./audio/shotgun.wav"))
		return (-1);
	if ((file = open("./audio/footstep.wav", O_RDONLY)) < 0)
		return (ft_printf("Could not open footstep sound\n"));
	if (write_sound(file, fd, "./audio/footstep.wav"))
		return (-1);
	return (0);
}