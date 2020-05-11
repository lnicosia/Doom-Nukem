/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_existing_sounds.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 13:14:58 by marvin            #+#    #+#             */
/*   Updated: 2020/04/29 13:14:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		check_sounds3(t_env *env)
{
	int	fd;

	fd = 0;
	if (!(env->init.musics_names[2] = ft_strdup("./audio/at_dooms_gate.wav")))
		return (ft_perror("Error while check musics\n"));
	if ((fd = open("./audio/at_dooms_gate.wav", O_RDONLY)) == -1)
		env->init.musics[2] = 1;
	if (close(fd))
		return (custom_error("Could not close the fd in check sounds\n"));
	return (0);
}

int		check_sounds2(t_env *env)
{
	int	fd;

	fd = 0;
	if (!(env->init.sounds_names[3] = ft_strdup("./audio/footstep.wav")))
		return (ft_perror("Error while cjeck sounds\n"));
	if ((fd = open("./audio/footstep.wav", O_RDONLY)) == -1)
		env->init.sounds[3] = 1;
	if (close(fd))
		return (custom_error("Could not close the fd in check sounds\n"));
	if (!(env->init.musics_names[0] = ft_strdup("./audio/Mt_Erebus.wav")))
		return (ft_perror("Error while check musics\n"));
	if ((fd = open("./audio/Mt_Erebus.wav", O_RDONLY)) == -1)
		env->init.musics[0] = 1;
	if (close(fd))
		return (custom_error("Could not close the fd in check sounds\n"));
	if (!(env->init.musics_names[1] = ft_strdup("./audio/bim_bam_boum.wav")))
		return (ft_perror("Error while check musics\n"));
	if ((fd = open("./audio/bim_bam_boum.wav", O_RDONLY)) == -1)
		env->init.musics[1] = 1;
	if (close(fd))
		return (custom_error("Could not close the fd in check sounds\n"));
	return (check_sounds3(env));
}

int		check_sounds(t_env *env)
{
	int	fd;

	fd = 0;
	if (!(env->init.sounds_names[0] = ft_strdup("./audio/handgun_shot.wav")))
		return (ft_perror("Error while check sounds\n"));
	if ((fd = open("./audio/handgun_shot.wav", O_RDONLY)) == -1)
		env->init.sounds[0] = 1;
	if (close(fd))
		return (custom_error("Could not close the fd in check sounds\n"));
	if (!(env->init.sounds_names[1] = ft_strdup("./audio/shotgun_shot.wav")))
		return (ft_perror("Error while check sounds\n"));
	if ((fd = open("./audio/shotgun_shot.wav", O_RDONLY)) == -1)
		env->init.sounds[1] = 1;
	if (close(fd))
		return (custom_error("Could not close the fd in check sounds\n"));
	if (!(env->init.sounds_names[2] = ft_strdup("./audio/raygun_shot.wav")))
		return (ft_perror("Error while check sounds\n"));
	if ((fd = open("./audio/raygun_shot.wav", O_RDONLY)) == -1)
		env->init.sounds[2] = 1;
	if (close(fd))
		return (custom_error("Could not close the fd in check sounds\n"));
	return (check_sounds2(env));
}

int     check_existing_sounds(t_env *env, char *name)
{
    int i;

    i = 0;
    while (i < NB_SOUNDS)
    {
        if (!(ft_strcmp(name, env->init.sounds_names[i]))
        && env->init.sounds[i] == 1)
            return (1);
        i++;
    }
		return (-1);
	i = 0;
	while (i < NB_MUSICS)
    {
        if (!(ft_strcmp(name, env->init.musics_names[i]))
        && env->init.musics[i] == 1)
            return (1);
        i++;
    }
    return (0);
}