/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sounds2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 13:14:58 by marvin            #+#    #+#             */
/*   Updated: 2020/05/11 15:42:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		check_sounds6(int fd, t_env *env)
{
	if (!(env->init.musics_names[2] = ft_strdup("./audio/at_dooms_gate.wav")))
		return (ft_perror("Error while check musics\n"));
	if ((fd = open("./audio/at_dooms_gate.wav", O_RDONLY)) == -1)
		env->init.musics[2] = 1;
	if (!env->init.musics[2] && close(fd))
		return (custom_error("Could not close the fd in check sounds\n"));
	return (0);
}
