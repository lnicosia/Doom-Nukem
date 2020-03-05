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

#include "env.h"

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
			if (valid_int(line, parser) == WRONG_CHAR)
				return (ft_printf("Invalid int for nb_vertices\n"));
			env->nb_vertices = ft_atoi(line);
			if (env->nb_vertices > 100000)
				return (ft_printf("vertices can't exceed 100 000\n"));
			line = skip_number(line);
			if (*line && *line == ' ')
				return (extra_data("vertices number", parser));
			if (*line)
				return (invalid_char("after vertices number",
							"a digit or the end of the line",
							*line, parser));
			if (env->nb_vertices < 3)
				return (custom_error("You can not declare less than 3 walls."));
			if (!(env->vertices = (t_vertex *)ft_memalloc(sizeof(t_vertex)
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
			if (valid_int(line, parser))
				return (ft_printf("Invalid int for nb_sectors\n"));
			env->nb_sectors = ft_atoi(line);
			env->screen_sectors_size = ft_min(env->nb_sectors, env->w);
			line = skip_number(line);
			if (*line && *line == ' ')
				return (extra_data("sectors number declaration", parser));
			if (*line)
				return (invalid_char("sectors number",
							"a digit", *line, parser));
			if (env->nb_sectors < 1)
				return (custom_error("You need at least one sector"));
			else if (env->nb_sectors > 100000)
				return (ft_printf("nb_sectors can't exceed 100 000\n"));
			if (!(env->sectors = (t_sector *)ft_memalloc(sizeof(t_sector)
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
	if (parse_resources(env, &(env->parser)))
		return (custom_error("Could not parser resources"));
	if (init_vertices(env, &(env->parser)))
		return (custom_error("Could not init vertices"));
	if (parse_vertices(env, &(env->parser)))
		return (custom_error("Error while parsing vertices"));
	if (init_sectors(env, &(env->parser)))
		return (custom_error("Could not init sectors"));
	if (parse_sectors(env, &(env->parser)))
		return (custom_error("Error while parsing sectors"));
	if (init_objects(env, &(env->parser)))
		return (custom_error("Could not init objects"));
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
