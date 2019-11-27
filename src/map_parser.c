/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 09:53:18 by sipatry           #+#    #+#             */
/*   Updated: 2019/11/27 16:38:54 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "map_parser.h"

static int	init_vertices(t_env *env, t_map_parser *parser)
{
	char	*line;
	char	*tmp;

	while ((parser->ret = get_next_line(parser->fd, &tmp)))
	{
		parser->line_count++;
		line = tmp;
		if (parser->ret == -1)
			return (custom_error("Invalid file"));
		if (*line && *line != '#')
		{
			if (*line != 'V')
				return (invalid_char("at vertices number", "'V'", *line, parser));
			line++;
			if (!*line)
				return (missing_data("at vertices number", parser));
			if (*line != ' ')
				return (invalid_char("at vertices number", "space or a digit",
							*line, parser));
			line = skip_spaces(line);
			if (!*line)
				return (missing_data("before vertices number", parser));
			if (valid_number(line, parser) == WRONG_CHAR)
				return (invalid_char("before vertices number",
							"space or a digit", *line, parser));
			env->nb_vertices = ft_atoi(line);
			line = skip_number(line);
			if (*line && *line == ' ')
				return (extra_data("vertices number", parser));
			if (*line)
				return (invalid_char("after vertices number",
							"a digit or the end of the line",
							*line, parser));
			if (env->nb_vertices < 3)
				return (custom_error("You can not declare less than 3 walls."));
			if (!(env->vertices = (t_vertex *)malloc(sizeof(t_vertex)
							* (env->nb_vertices))))
				return (ft_perror("Could not malloc vertices:"));
			ft_strdel(&tmp);
			return (0);
		}
		else if (*line != '#')
			return (missing_data("vertices number declaration", parser));
		ft_strdel(&tmp);
	}
	return (0);
}

static int	init_sectors(t_env *env, t_map_parser *parser)
{
	int		i;
	char	*line;
	char	*tmp;

	line = NULL;
	while ((parser->ret = get_next_line(parser->fd, &tmp)))
	{
		parser->line_count++;
		line = tmp;
		if (*line && *line != '#')
		{
			if (*line != 'S')
				return (invalid_char("sectors number", "'S'", *line, parser));
			line++;
			if (!*line)
				return (missing_data("sectors number", parser));
			if (*line != ' ')
				return (invalid_char("sectors number",
							"space or a digit", *line, parser));
			line = skip_spaces(line);
			if (!*line)
				return (missing_data("sectors number", parser));
			if (valid_number(line, parser) == WRONG_CHAR)
				return (invalid_char("sectors numbers",
							"space or a digit", *line, parser));
			env->nb_sectors = atoi(line);
			env->screen_sectors_size = ft_min(env->nb_sectors, env->w);
			line = skip_number(line);
			if (*line && *line == ' ')
				return (extra_data("sectors number declaration", parser));
			if (*line)
				return (invalid_char("sectors number",
							"a digit", *line, parser));
			if (env->nb_sectors < 1)
				return (custom_error("You need at least one sector"));
			if (!(env->sectors = (t_sector *)malloc(sizeof(t_sector)
							* env->nb_sectors)))
				return (custom_error("Could not malloc sectors!"));
			i = 0;
			while (i < env->nb_sectors)
			{
				ft_bzero(&env->sectors[i], sizeof(t_sector));
				env->sectors[i].x_max = -2147483648;
				i++;
			}
			ft_strdel(&tmp);
			return (0);
		}
		else if (*line != '#')
			return (missing_data("sectors number declaration", parser));
		ft_strdel(&tmp);
	}
	return (0);
}

void	set_sectors_xmax(t_env *env)
{
	int i;
	int	j;

	i = 0;
	while (i < env->nb_sectors)
	{
		j = 0;
		while (j < env->sectors[i].nb_vertices)
		{
			if (env->sectors[i].x_max
					< env->vertices[env->sectors[i].vertices[j]].x)
				env->sectors[i].x_max =
					env->vertices[env->sectors[i].vertices[j]].x;
			j++;
		}
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
	env->player.pos.z = 0;
	env->player.health = 100;
	env->player.killed = 0;
	env->player.touched = 0;
	env->player.nb_shots = 0;
	env->player.accuracy = 0;
	env->player.size_2d = 0.75;
	env->player.velocity = 0;
	env->player.acceleration = 0;
	env->player.drop_flag = 0;
	env->gravity.velocity = 0;
	env->gravity.acceleration = 0;
	env->player.state.drop = 0;
	env->player.state.fall = 0;
	env->player.state.climb = 0;
	env->player.state.jump = 0;
	env->player.state.fly = 0;
	env->player.state.crouch = 0;
	env->player.state.walk = 0;
	env->gravity.force = -9.81;
	env->gravity.collision = 0;
}

int		parse_map(char *file, t_env *env)
{
	t_map_parser	parser;

	env->nb_sectors = 0;
	env->nb_vertices = 0;
	parser.sectors_count = 0;
	parser.vertices_count = 0;
	parser.objects_count = 0;
	parser.enemies_count = 0;
	parser.line_count = 0;
	ft_printf("{red}");
	if ((parser.fd = open(file, O_RDONLY)) < 0)
	{
		ft_dprintf(STDERR_FILENO, "Could not open %s\n", file);
		return (-1);
	}
	if (init_vertices(env, &parser))
		return (-1);
	//return (custom_error("Could not init vertices"));
	if (parse_vertices(env, &parser))
		return (-1);
	//return (custom_error("Error while parsing vertices"));
	if (init_sectors(env, &parser))
		return (-1);
	//return (custom_error("Could not init sectors"));
	if (parse_sectors(env, &parser))
		return (custom_error("Error while parsing sectors"));
				//return (-1);
	precompute_slopes(env);
	if (init_objects(env, &parser))
		return (-1);
	//return (custom_error("Could not init objects"));
	if (parse_objects(env, &parser))
		return (-1);
	//return (custom_error("Error while parsing objects"));
	if (init_enemies(env, &parser))
		return (-1);
	//return (custom_error("Could not init objects"));
	if (parse_enemies(env, &parser))
		return (-1);
	//return (custom_error("Error while parsing creatures"));
	if (parse_player(env, &parser))
		return (-1);
	//return (custom_error("Error while parsing player"));
	if (env->player.sector == -1)
		return (missing_data("You need to give player data", &parser));
	update_player_z(env);
	set_sectors_xmax(env);
	init_enemies_data(env);
	init_objects_data(env);
	if (close(parser.fd))
		return (custom_error("Could not close the file"));
	ft_printf("{reset}");
	return (0);
}
