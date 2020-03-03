/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_musics_choices.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:02:27 by gaerhard          #+#    #+#             */
/*   Updated: 2020/03/03 16:06:13 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "save.h"

void	write_music_choices(int fd, t_env *env)
{
	ft_dprintf(fd, "\nA %d\nF %d", env->sound.ambient_music,
		env->sound.fight_music);
}
