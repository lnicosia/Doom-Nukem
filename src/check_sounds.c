/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sounds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 13:14:58 by marvin            #+#    #+#             */
/*   Updated: 2020/05/11 15:42:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		check_sounds5(int fd, t_env *env)
{
	if (!(env->init.sounds_names[12] = ft_strdup("./audio/monster_nearby.wav")))
		return (ft_perror("Error while checking sounds\n"));
	if ((fd = open("./audio/monster_nearby.wav", O_RDONLY)) == -1)
		env->init.sounds[12] = 1;
	if (!env->init.sounds[12] && close(fd))
		return (custom_error("Could not close the fd in check sounds\n"));
	if (!(env->init.sounds_names[13] = ft_strdup("./audio/explosion.wav")))
		return (ft_perror("Error while checking sounds\n"));
	if ((fd = open("./audio/explosion.wav", O_RDONLY)) == -1)
		env->init.sounds[13] = 1;
	if (!env->init.sounds[13] && close(fd))
		return (custom_error("Could not close the fd in check sounds\n"));
	if (!(env->init.musics_names[0] = ft_strdup("./audio/Mt_Erebus.wav")))
		return (ft_perror("Error while checking musics\n"));
	if ((fd = open("./audio/Mt_Erebus.wav", O_RDONLY)) == -1)
		env->init.musics[0] = 1;
	if (!env->init.musics[0] && close(fd))
		return (custom_error("Could not close the fd in check sounds\n"));
	if (!(env->init.musics_names[1] = ft_strdup("./audio/bim_bam_boum.wav")))
		return (ft_perror("Error while checking musics\n"));
	if ((fd = open("./audio/bim_bam_boum.wav", O_RDONLY)) == -1)
		env->init.musics[1] = 1;
	if (!env->init.musics[1] && close(fd))
		return (custom_error("Could not close the fd in check sounds\n"));
	return (check_sounds6(fd, env));
}

int		check_sounds4(int fd, t_env *env)
{
	if (!(env->init.sounds_names[9] = ft_strdup("./audio/lost_soul_death.wav")))
		return (ft_perror("Error while checking sounds\n"));
	if ((fd = open("./audio/lost_soul_death.wav", O_RDONLY)) == -1)
		env->init.sounds[9] = 1;
	if (!env->init.sounds[9] && close(fd))
		return (custom_error("Could not close the fd in check sounds\n"));
	if (!(env->init.sounds_names[10] =
		ft_strdup("./audio/lost_soul_attack.wav")))
		return (ft_perror("Error while checking sounds\n"));
	if ((fd = open("./audio/lost_soul_attack.wav", O_RDONLY)) == -1)
		env->init.sounds[10] = 1;
	if (!env->init.sounds[10] && close(fd))
		return (custom_error("Could not close the fd in check sounds\n"));
	if (!(env->init.sounds_names[11] = ft_strdup("./audio/monster_hit.wav")))
		return (ft_perror("Error while checking sounds\n"));
	if ((fd = open("./audio/monster_hit.wav", O_RDONLY)) == -1)
		env->init.sounds[11] = 1;
	if (!env->init.sounds[11] && close(fd))
		return (custom_error("Could not close the fd in check sounds\n"));
	return (check_sounds5(fd, env));
}

int		check_sounds3(int fd, t_env *env)
{
	if (!(env->init.sounds_names[6] = ft_strdup("./audio/player_hit.wav")))
		return (ft_perror("Error while checking sounds\n"));
	if ((fd = open("./audio/player_hit.wav", O_RDONLY)) == -1)
		env->init.sounds[6] = 1;
	if (!env->init.sounds[6] && close(fd))
		return (custom_error("Could not close the fd in check sounds\n"));
	if (!(env->init.sounds_names[7] = ft_strdup("./audio/player_death.wav")))
		return (ft_perror("Error while checking sounds\n"));
	if ((fd = open("./audio/player_death.wav", O_RDONLY)) == -1)
		env->init.sounds[7] = 1;
	if (!env->init.sounds[7] && close(fd))
		return (custom_error("Could not close the fd in check sounds\n"));
	if (!(env->init.sounds_names[8] =
		ft_strdup("./audio/cyberdemon_death.wav")))
		return (ft_perror("Error while checking sounds\n"));
	if ((fd = open("./audio/cyberdemon_death.wav", O_RDONLY)) == -1)
		env->init.sounds[8] = 1;
	if (!env->init.sounds[8] && close(fd))
		return (custom_error("Could not close the fd in check sounds\n"));
	return (check_sounds4(fd, env));
}

int		check_sounds2(int fd, t_env *env)
{
	if (!(env->init.sounds_names[3] = ft_strdup("./audio/footstep.wav")))
		return (ft_perror("Error while checking sounds\n"));
	if ((fd = open("./audio/footstep.wav", O_RDONLY)) == -1)
		env->init.sounds[3] = 1;
	if (!env->init.sounds[3] && close(fd))
		return (custom_error("Could not close the fd in check sounds\n"));
	if (!(env->init.sounds_names[4] =
		ft_strdup("./audio/rocket_launcher_shot.wav")))
		return (ft_perror("Error while checking sounds\n"));
	if ((fd = open("./audio/rocket_launcher_shot.wav", O_RDONLY)) == -1)
		env->init.sounds[4] = 1;
	if (!env->init.sounds[4] && close(fd))
		return (custom_error("Could not close the fd in check sounds\n"));
	if (!(env->init.sounds_names[5] = ft_strdup("./audio/gatling_shot.wav")))
		return (ft_perror("Error while checking sounds\n"));
	if ((fd = open("./audio/gatling_shot.wav", O_RDONLY)) == -1)
		env->init.sounds[5] = 1;
	if (!env->init.sounds[5] && close(fd))
		return (custom_error("Could not close the fd in check sounds\n"));
	return (check_sounds3(fd, env));
}

int		check_sounds(t_env *env)
{
	int	fd;

	fd = 0;
	if (!(env->init.sounds_names[0] = ft_strdup("./audio/handgun_shot.wav")))
		return (ft_perror("Error while checking sounds\n"));
	if ((fd = open("./audio/handgun_shot.wav", O_RDONLY)) == -1)
		env->init.sounds[0] = 1;
	if (!env->init.sounds[0] && close(fd))
		return (custom_error("Could not close the fd in check sounds\n"));
	if (!(env->init.sounds_names[1] = ft_strdup("./audio/shotgun_shot.wav")))
		return (ft_perror("Error while checking sounds\n"));
	if ((fd = open("./audio/shotgun_shot.wav", O_RDONLY)) == -1)
		env->init.sounds[1] = 1;
	if (!env->init.sounds[1] && close(fd))
		return (custom_error("Could not close the fd in check sounds\n"));
	if (!(env->init.sounds_names[2] = ft_strdup("./audio/raygun_shot.wav")))
		return (ft_perror("Error while checking sounds\n"));
	if ((fd = open("./audio/raygun_shot.wav", O_RDONLY)) == -1)
		env->init.sounds[2] = 1;
	if (!env->init.sounds[2] && close(fd))
		return (custom_error("Could not close the fd in check sounds\n"));
	return (check_sounds2(fd, env));
}
