/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fonts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 14:16:46 by marvin            #+#    #+#             */
/*   Updated: 2020/05/15 21:31:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	check_existing_fonts(t_env *env, char *name)
{
	int i;

	i = 0;
	while (i < NB_FONTS_FILE)
	{
		if (!(ft_strcmp(name, env->init.fonts_names[i]))
		&& env->init.fonts[i] == 1)
			return (1);
		i++;
	}
	return (0);
}

int	check_fonts3(t_env *env)
{
	int	fd;

	fd = 0;
	if (!(env->init.fonts_names[6] = ft_strdup("./fonts/lato/Lato-Bold.ttf")))
		return (ft_perror("Error while parsing fonts\n"));
	if ((fd = open("./fonts/lato/Lato-Bold.ttf", O_RDONLY)) == -1)
		env->init.fonts[6] = 1;
	if (!env->init.fonts[6] && close(fd))
		return (custom_error("Could not close the fd in check fonts\n"));
	if (!(env->init.fonts_names[7] = ft_strdup("./fonts/lato/Lato-Black.ttf")))
		return (ft_perror("Error while parsing fonts\n"));
	if ((fd = open("./fonts/lato/Lato-Black.ttf", O_RDONLY)) == -1)
		env->init.fonts[7] = 1;
	if (!env->init.fonts[7] && close(fd))
		return (custom_error("Could not close the fd in check fonts\n"));
	return (0);
}

int	check_fonts2(t_env *env)
{
	int	fd;

	fd = 0;
	if (!(env->init.fonts_names[3] =
	ft_strdup("./fonts/montserrat/Montserrat-Regular.ttf")))
		return (ft_perror("Error while parsing fonts\n"));
	if ((fd = open("./fonts/montserrat/Montserrat-Regular.ttf",
		O_RDONLY)) == -1)
		env->init.fonts[3] = 1;
	if (!env->init.fonts[3] && close(fd))
		return (custom_error("Could not close the fd in check fonts\n"));
	if (!(env->init.fonts_names[4] =
	ft_strdup("./fonts/playfair-display/PlayfairDisplay-Regular.ttf")))
		return (ft_perror("Error while parsing fonts\n"));
	if ((fd = open("./fonts/playfair-display/PlayfairDisplay-Regular.ttf",
		O_RDONLY)) == -1)
		env->init.fonts[4] = 1;
	if (!env->init.fonts[4] && close(fd))
		return (custom_error("Could not close the fd in check fonts\n"));
	if (!(env->init.fonts_names[5] =
		ft_strdup("./fonts/lato/Lato-Regular.ttf")))
		return (ft_perror("Error while parsing fonts\n"));
	if ((fd = open("./fonts/lato/Lato-Regular.ttf", O_RDONLY)) == -1)
		env->init.fonts[5] = 1;
	if (!env->init.fonts[5] && close(fd))
		return (custom_error("Could not close the fd in check fonts\n"));
	return (check_fonts3(env));
}

int	check_fonts(t_env *env)
{
	int	fd;

	fd = 0;
	if (!(env->init.fonts_names[0] =
		ft_strdup("./fonts/amazdoom/AmazDooMLeft.ttf")))
		return (ft_perror("Error while parsing fonts\n"));
	if ((fd = open("./fonts/amazdoom/AmazDooMLeft.ttf", O_RDONLY)) == -1)
		env->init.fonts[0] = 1;
	if (!env->init.fonts[0] && close(fd))
		return (custom_error("Could not close the fd in check fonts\n"));
	if (!(env->init.fonts_names[1] =
		ft_strdup("./fonts/alice/Alice-Regular.ttf")))
		return (ft_perror("Error while parsing fonts\n"));
	if ((fd = open("./fonts/alice/Alice-Regular.ttf", O_RDONLY)) == -1)
		env->init.fonts[1] = 1;
	if (!env->init.fonts[1] && close(fd))
		return (custom_error("Could not close the fd in check fonts\n"));
	if (!(env->init.fonts_names[2] =
	ft_strdup("./fonts/bebas_neue/BebasNeue-Regular.ttf")))
		return (ft_perror("Error while parsing fonts\n"));
	if ((fd = open("./fonts/bebas_neue/BebasNeue-Regular.ttf", O_RDONLY)) == -1)
		env->init.fonts[2] = 1;
	if (!env->init.fonts[2] && close(fd))
		return (custom_error("Could not close the fd in check fonts\n"));
	return (check_fonts2(env));
}
