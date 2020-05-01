/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 09:53:18 by sipatry           #+#    #+#             */
/*   Updated: 2020/03/04 18:25:37 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	set_sector_xmax(t_env *env, t_sector *sector)
{
	int i;

	i = 0;
	while (i < sector->nb_vertices)
	{
		if (sector->x_max < env->vertices[sector->vertices[i]].x)
			sector->x_max = env->vertices[sector->vertices[i]].x;
		i++;
	}
}

void	set_sectors_xmax(t_env *env)
{
	int i;

	i = 0;
	while (i < env->nb_sectors)
	{
		set_sector_xmax(env, &env->sectors[i]);
		i++;
	}
}

void	init_player(t_env *env)
{
	env->player.eyesight = 6;
	env->player.size_2d = 0.75;
	env->player.sector = -1;
	env->player.camera.angle_z_cos = cos(0);
	env->player.camera.angle_z_sin = sin(0);
	env->player.speed = 0.1;
	env->player.health = 100;
	env->player.size_2d = 0.75;
}

int		parse_map2(t_env *env)
{
	if (parse_objects(env, &(env->parser)))
		return (custom_error("Error while parsing objects"));
	if (init_enemies(env, &(env->parser)))
		return (custom_error("Could not init objects"));
	if (parse_enemies(env, &(env->parser)))
		return (custom_error("Error while parsing creatures"));
	if (parse_events(env, &(env->parser)))
		return (custom_error("Error while parsing events"));
	if (parse_ambient_music(env, &(env->parser)))
		return (custom_error("Error while parsing ambient music"));
	if (parse_fight_music(env, &(env->parser)))
		return (custom_error("Error while parsing combat music"));
	if (parse_player(env, &(env->parser)))
		return (custom_error("Error while parsing player data"));
	if (env->player.sector == -1)
		return (missing_data("You need to give player data", &(env->parser)));
	set_sectors_xmax(env);
	init_enemies_data(env);
	init_objects_data(env);
	if (close(env->parser.fd))
		return (custom_error("Could not close the file"));
	ft_printf("{reset}");
	return (0);
}

int		parse_map(char *file, t_env *env)
{
	env->nb_sectors = 0;
	env->nb_vertices = 0;
	env->parser.sectors_count = 0;
	env->parser.vertices_count = 0;
	env->parser.objects_count = 0;
	env->parser.enemies_count = 0;
	env->parser.line_count = 0;
	ft_printf("{red}");
	if ((env->parser.fd = open(file, O_RDONLY)) < 0)
	{
		ft_dprintf(STDERR_FILENO, "Could not open %s\n", file);
		return (-1);
	}
	if (init_vertices(env, &env->parser))
		return (custom_error("Could not init vertices"));
	if (parse_vertices(env, &env->parser))
		return (custom_error("Error while parsing vertices"));
	if (init_sectors(env, &env->parser))
		return (custom_error("Could not init sectors"));
	if (parse_sectors(env, &env->parser))
		return (custom_error("Error while parsing sectors"));
	if (init_objects(env, &env->parser))
		return (custom_error("Could not init objects"));
	return (parse_map2(env));
}
