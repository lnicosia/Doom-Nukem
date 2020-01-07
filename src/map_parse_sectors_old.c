/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_sectors_old.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:14:16 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/07 13:48:34 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"
#include "env.h"

int			parse_floor(t_env *env, char **line, t_map_parser *parser)
{
	if (**line != '[')
		return (invalid_char("before floor data", "'['", **line, parser));
	(*line)++;
	if (!**line || **line == ']')
		return (missing_data("floor height, slope and texture", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before floor height", "a digit", **line, parser));
	env->sectors[parser->sectors_count].floor = ft_atof(*line);
	env->sectors[parser->sectors_count].floor_min = env->sectors[parser->
		sectors_count].floor;
	env->sectors[parser->sectors_count].floor_max = env->sectors[parser->
		sectors_count].floor;
	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("floor slope and texture", parser));
	if (**line && **line != ' ')
		return (invalid_char("after floor height", "a digit or space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("floor slope and texture", parser));
	if (valid_number(*line, parser)){
		return (invalid_char("before floor slope", "a digit or space(s)",
					**line, parser));}
		env->sectors[parser->sectors_count].floor_slope = ft_atof(*line);
/*	if (env->sectors[parser->sectors_count].floor_slope > 45
			|| env->sectors[parser->sectors_count].floor_slope < -45)
		return (custom_error_with_line("Slopes must be between -45"
					"and 45 degrees", parser));*/
	//	env->sectors[parser->sectors_count].floor_slope = env->
	//			sectors[parser->sectors_count].floor_slope;
	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("floor texture", parser));
	if (**line && **line != ' ')
		return (invalid_char("after floor slope", "a digit or space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("floor texture", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before floor texture", "a digit or space(s)",
					**line, parser));
	env->sectors[parser->sectors_count].floor_texture = ft_atoi(*line);
	if (env->sectors[parser->sectors_count].floor_texture < -MAX_SKYBOX
			|| env->sectors[parser->sectors_count].floor_texture >= MAX_WALL_TEXTURE)
		return (custom_error_with_line("Invalid floor texture", parser));
	*line = skip_number(*line);

	if (!**line || **line == ']')
		return (missing_data("floor align.x", parser));
	if (**line && **line != ' ')
		return (invalid_char("after floor texture", "a digit or space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("floor align.x", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before floor align.x", "a digit or space(s)",
					**line, parser));
	env->sectors[parser->sectors_count].floor_map_align.x = ft_atoi(*line);
	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("floor align.y", parser));
	if (**line && **line != ' ')
		return (invalid_char("after floor align.x", "a digit or space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("floor align.y", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before floor align.y", "a digit or space(s)",
					**line, parser));
	env->sectors[parser->sectors_count].floor_map_align.y = ft_atoi(*line);

	if (env->sectors[parser->sectors_count].floor_texture < 0)
		env->contains_skybox = 1;
	/*if (env->sectors[parser->sectors_count].floor_texture < 0)
	{
		env->contains_skybox = 1;
		env->sectors[parser->sectors_count].floor_align.x *= env->skyboxes[0].textures[0].surface->w;
		env->sectors[parser->sectors_count].floor_align.y *= env->skyboxes[0].textures[0].surface->h;
		env->sectors[parser->sectors_count].floor_align.x /= 10;
		env->sectors[parser->sectors_count].floor_align.y /= 10;
	}
	else
	{
		env->sectors[parser->sectors_count].floor_align.x *= env->wall_textures[env->sectors[parser->sectors_count].floor_texture].surface->w;
		env->sectors[parser->sectors_count].floor_align.y *= env->wall_textures[env->sectors[parser->sectors_count].floor_texture].surface->h;
		env->sectors[parser->sectors_count].floor_align.x /= 10;
		env->sectors[parser->sectors_count].floor_align.y /= 10;
	}*/
	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("floor scale.x", parser));
	if (**line && **line != ' ')
		return (invalid_char("after floor align.y", "a digit or space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("floor scale.x", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before floor scale.x", "a digit or space(s)",
					**line, parser));
	env->sectors[parser->sectors_count].floor_map_scale.x = ft_atoi(*line);
	if (env->sectors[parser->sectors_count].floor_map_scale.x <= 0)
		return (custom_error_with_line("Floor scale must be positive", parser));
	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("floor scale.y", parser));
	if (**line && **line != ' ')
		return (invalid_char("after floor scale.x", "a digit or space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("floor scale.y", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before floor scale.y", "a digit or space(s)",
					**line, parser));
	env->sectors[parser->sectors_count].floor_map_scale.y = ft_atoi(*line);
	if (env->sectors[parser->sectors_count].floor_map_scale.y <= 0)
		return (custom_error_with_line("Floor scale must be positive", parser));

	if (set_sector_floor_map_array(&env->sectors[parser->sectors_count], 
		env->wall_textures[env->sectors[parser->sectors_count].floor_texture],
		env))
		return (-1);
	*line = skip_number(*line);
	if (!**line)
		return (missing_data("']' after floor scale",parser));
	if (**line != ']')
		return (invalid_char("after floor scale", "a digit or ']'",
					**line, parser));
	(*line)++;
	if (!**line)
		return (missing_data("ceiling, vertices, neighbors, textures and light",
					parser));
	if (**line != ' ')
		return (invalid_char("after floor data", "space(s)", **line, parser));
	*line = skip_spaces(*line);
	return (0);
}

int			parse_ceiling(t_env *env, char **line, t_map_parser *parser)
{
	if (!**line)
		return (missing_data("ceiling, vertices, neighbors, textures and light",
					parser));
	if (**line != '[')
		return (invalid_char("before ceiling data", "'['",
					**line, parser));
	(*line)++;
	if (!**line || **line == ']')
		return (missing_data("ceiling height", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before ceiling height", "a digit",
					**line, parser));
	env->sectors[parser->sectors_count].ceiling = ft_atof(*line);
	env->sectors[parser->sectors_count].ceiling_min =
	env->sectors[parser->sectors_count].ceiling;
	env->sectors[parser->sectors_count].ceiling_max =
	env->sectors[parser->sectors_count].ceiling;
	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("ceiling slope", parser));
	if (**line && **line != ' ')
		return (invalid_char("after ceiling height", "a digit or space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("ceiling slope", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before ceiling slope", "a digit or space(s)",
					**line, parser));
	env->sectors[parser->sectors_count].ceiling_slope = ft_atof(*line) * CONVERT_RADIANS;
	if (env->sectors[parser->sectors_count].ceiling_slope > 45
			|| env->sectors[parser->sectors_count].ceiling_slope < -45)
		return (custom_error_with_line("Slopes must be between -45"
					"and 45 degrees", parser));
	env->sectors[parser->sectors_count].ceiling_slope = tan(env->
			sectors[parser->sectors_count].ceiling_slope * CONVERT_RADIANS);
	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("ceiling texture", parser));
	if (**line && **line != ' ')
		return (invalid_char("after ceiling slope", "a digit or space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("ceiling texture", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before ceiling texture", "a digit or space(s)",
					**line, parser));
	env->sectors[parser->sectors_count].ceiling_texture = ft_atoi(*line);
	if (env->sectors[parser->sectors_count].ceiling_texture < -MAX_SKYBOX || env->
			sectors[parser->sectors_count].ceiling_texture >= MAX_WALL_TEXTURE)
		return (custom_error_with_line("Invalid ceiling texture", parser));

	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("ceiling align.x", parser));
	if (**line && **line != ' ')
		return (invalid_char("after ceiling texture", "a digit or space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("ceiling align.x", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before ceiling align.x", "a digit or space(s)",
					**line, parser));
	env->sectors[parser->sectors_count].ceiling_map_align.x = ft_atoi(*line);
	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("ceiling align.y", parser));
	if (**line && **line != ' ')
		return (invalid_char("after ceiling align.x", "a digit or space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("ceiling.y", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before ceiling align.y", "a digit or space(s)",
					**line, parser));
	env->sectors[parser->sectors_count].ceiling_map_align.y = ft_atoi(*line);

	if (env->sectors[parser->sectors_count].ceiling_texture < 0)
		env->contains_skybox = 1;
	/*if (env->sectors[parser->sectors_count].ceiling_texture < 0)
	{
		env->contains_skybox = 1;
		env->sectors[parser->sectors_count].ceiling_align.x *= env->skyboxes[0].textures[0].surface->w;
		env->sectors[parser->sectors_count].ceiling_align.y *= env->skyboxes[0].textures[0].surface->h;
		env->sectors[parser->sectors_count].ceiling_align.x /= 10;
		env->sectors[parser->sectors_count].ceiling_align.y /= 10;
	}
	else
	{
		env->sectors[parser->sectors_count].ceiling_align.x *= env->wall_textures[env->sectors[parser->sectors_count].ceiling_texture].surface->w;
		env->sectors[parser->sectors_count].ceiling_align.y *= env->wall_textures[env->sectors[parser->sectors_count].ceiling_texture].surface->h;
		env->sectors[parser->sectors_count].ceiling_align.x /= 10;
		env->sectors[parser->sectors_count].ceiling_align.y /= 10;
	}*/
	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("ceiling scale.x", parser));
	if (**line && **line != ' ')
		return (invalid_char("after ceiling align.y", "a digit or space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("ceiling scale.x", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before ceiling scale.x", "a digit or space(s)",
					**line, parser));
	env->sectors[parser->sectors_count].ceiling_map_scale.x = ft_atoi(*line);
	if (env->sectors[parser->sectors_count].ceiling_map_scale.x <= 0)
		return (custom_error_with_line("Ceiling scale must be positive", parser));
	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("ceiling scale.y", parser));
	if (**line && **line != ' ')
		return (invalid_char("after ceiling scale.x", "a digit or space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("ceiling scale.y", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before ceiling scale.y", "a digit or space(s)",
					**line, parser));
	env->sectors[parser->sectors_count].ceiling_map_scale.y = ft_atoi(*line);
	if (env->sectors[parser->sectors_count].ceiling_map_scale.y <= 0)
		return (custom_error_with_line("Ceiling scale must be positive", parser));
	
	if (set_sector_ceiling_map_array(&env->sectors[parser->sectors_count], 
		env->wall_textures[env->sectors[parser->sectors_count].ceiling_texture], 
		env))
		return (-1);
	*line = skip_number(*line);
	if (!**line)
		return (missing_data("']' after ceiling texture",parser));
	if (**line != ']')
		return (invalid_char("after ceiling texture", "a digit or ']'",
					**line, parser));
	(*line)++;
	if (!**line)
		return (missing_data("vertices, neighbors, textures and light",
					parser));
	if (**line != ' ')
		return (invalid_char("after ceiling data", "space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	return (0);
}

int			init_sector_data(t_env *env, char *line, t_map_parser *parser)
{
	int	i;

	if (!*line)
		return (missing_data("vertices, neighbors, textures and light",
					parser));
	if (*line != '(')
		return (invalid_char("before sector vertices", "'('", *line, parser));
	line++;
	if ((parser->sector_vertices_count = count_vertices(line, parser)) == -1)
		return (custom_error("Error while counting vertices"));
	if (parser->sector_vertices_count < 3)
	{
		ft_dprintf(STDERR_FILENO,
				"[Line %d] Sector %d must contain at least 3 vertices\n",
				parser->line_count, parser->sectors_count);
		return (-1);
	}
	env->sectors[parser->sectors_count].nb_vertices = parser->
		sector_vertices_count;
	if (!(env->sectors[parser->sectors_count].vertices = (short*)
				malloc(sizeof(short) * (parser->sector_vertices_count + 1))))
		return (ft_perror("Could not malloc sector vertices:"));
	if (!(env->sectors[parser->sectors_count].neighbors = (short*)
				malloc(sizeof(short) * (parser->sector_vertices_count + 1))))
		return (ft_perror("Could not malloc sector neighbors:"));
	if (!(env->sectors[parser->sectors_count].textures = (short*)
				malloc(sizeof(short) * (parser->sector_vertices_count + 1))))
		return (ft_perror("Could not malloc sector vertices:"));
	if (!(env->sectors[parser->sectors_count].sprites = (t_wall_sprites*)
				malloc(sizeof(t_wall_sprites) * (parser->sector_vertices_count + 1))))
		return (ft_perror("Could not malloc sector vertices:"));
	if (!(env->sectors[parser->sectors_count].walls_map_lvl = (double**)
				malloc(sizeof(double*) * (parser->sector_vertices_count + 1))))
		return (ft_perror("Could not malloc sector vertices:"));
	i = 0;
	while (i < parser->sector_vertices_count + 1)
	{
		env->sectors[parser->sectors_count].walls_map_lvl[i] = 0;
		i++;
	}
	if (!(env->sectors[parser->sectors_count].align = (t_v2*)
				malloc(sizeof(t_v2) * (parser->sector_vertices_count + 1))))
		return (ft_perror("Could not malloc textures alignement:"));
	if (!(env->sectors[parser->sectors_count].scale = (t_v2*)
				malloc(sizeof(t_v2) * (parser->sector_vertices_count + 1))))
		return (ft_perror("Could not malloc textures scale:"));
	if (!(env->sectors[parser->sectors_count].ceilings = (double*)
				malloc(sizeof(double) * (parser->sector_vertices_count + 1))))
		return (ft_perror("Could not malloc sector ceilings:"));
	if (!(env->sectors[parser->sectors_count].floors = (double*)
				malloc(sizeof(double) * (parser->sector_vertices_count + 1))))
		return (ft_perror("Could not malloc sector floors:"));
	if (!(env->sectors[parser->sectors_count].clipped_ceilings1 = (double*)
				malloc(sizeof(double) * (parser->sector_vertices_count + 1))))
		return (ft_perror("Could not malloc sector clipped_ceilings1:"));
	if (!(env->sectors[parser->sectors_count].clipped_floors1 = (double*)
				malloc(sizeof(double) * (parser->sector_vertices_count + 1))))
		return (ft_perror("Could not malloc sector clipped_floors1:"));
	if (!(env->sectors[parser->sectors_count].clipped_ceilings2 = (double*)
				malloc(sizeof(double) * (parser->sector_vertices_count + 1))))
		return (ft_perror("Could not malloc sector clipped_ceilings2:"));
	if (!(env->sectors[parser->sectors_count].clipped_floors2 = (double*)
				malloc(sizeof(double) * (parser->sector_vertices_count + 1))))
		return (ft_perror("Could not malloc sector clipped_floors2:"));
	if (!(env->sectors[parser->sectors_count].wall_width = (double*)
				malloc(sizeof(double) * (parser->sector_vertices_count + 1))))
		return (ft_perror("Could not malloc sector wall_size:"));
	if (!(env->sectors[parser->sectors_count].selected = (short*)
				malloc(sizeof(short) * (parser->sector_vertices_count + 1))))
		return (ft_perror("Could not malloc sector vertices:"));
	if (!(env->sectors[parser->sectors_count].nb_sprites = (short*)
				malloc(sizeof(short) * (parser->sector_vertices_count + 1))))
		return (ft_perror("Could not malloc sector vertices:"));
	if (!(env->sectors[parser->sectors_count].xmin = (int*)
				malloc(sizeof(int) * (env->h))))
		return (ft_perror("Could not malloc sector xmins:"));
	if (!(env->sectors[parser->sectors_count].xmax = (int*)
				malloc(sizeof(int) * (env->h))))
		return (ft_perror("Could not malloc sector xmaxs:"));
	return (0);
}

int			parse_sector_vertices(t_env *env, char **line, t_map_parser *parser)
{
	int	i;

	i = 0;
	while (i < parser->sector_vertices_count)
	{
		env->sectors[parser->sectors_count].vertices[i] = ft_atoi(*line);
		if (env->sectors[parser->sectors_count].vertices[i] < 0 || env->
				sectors[parser->sectors_count].vertices[i] >= env->nb_vertices)
		{
			ft_dprintf(STDERR_FILENO,
					"[Line %d] Vertex \'%d\' in sector %d does not exist\n",
					parser->line_count,
					env->sectors[parser->sectors_count].vertices[i],
					parser->sectors_count);
			return (-1);
		}
		*line = skip_number(*line);
		*line = skip_spaces(*line);
		i++;
	}
	env->sectors[parser->sectors_count].vertices[parser->sector_vertices_count]
		= env->sectors[parser->sectors_count].vertices[0];
	if (check_vertices_uniqueness(env->sectors[parser->sectors_count]))
		return (sector_error("has duplicate vertices", parser->sectors_count,
					parser));
	if (check_sector_duplicate(env, env->sectors[parser->sectors_count],
				parser->sectors_count))
		return (sector_error("already exists", parser->sectors_count, parser));
	(*line)++;
	if (!**line)
		return (missing_data("neighbors, textures and light", parser));
	if (**line != ' ')
		return (invalid_char("after vertices data", "space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	return (0);
}

int			parse_sector_neighbors(t_env *env, char **line, t_map_parser *parser)
{
	int	i;

	if (!**line)
		return (missing_data("neighbors, textures and light", parser));
	if (**line != '(')
		return (invalid_char("before sector neighbors", "'('", **line, parser));
	(*line)++;
	if ((parser->sector_neighbors_count = count_neighbors(*line, parser)) == -1)
		return (custom_error("Error while counting neighbors"));
	if (parser->sector_neighbors_count < parser->sector_vertices_count)
		return (sector_error("is missing one or more neighbors",
					parser->sectors_count, parser));
	if (parser->sector_neighbors_count > parser->sector_vertices_count)
		return (sector_error("has too much neighbors",
					parser->sectors_count, parser));
	i = 0;
	while (i < parser->sector_neighbors_count)
	{
		env->sectors[parser->sectors_count].neighbors[i] = ft_atoi(*line);
		if (env->sectors[parser->sectors_count].neighbors[i] < -1 || env->
				sectors[parser->sectors_count].neighbors[i] >= env->nb_sectors)
		{
			ft_dprintf(STDERR_FILENO,
					"[Line %d] Neighbor \'%d\' in sector %d does not exist\n",
					parser->line_count,
					env->sectors[parser->sectors_count].neighbors[i],
					parser->sectors_count);
			return (-1);
		}
		if (env->sectors[parser->sectors_count].neighbors[i] == parser->sectors_count)
			return (sector_error("can not contain a portal to itself", parser->sectors_count, parser));
		*line = skip_number(*line);
		*line = skip_spaces(*line);
		i++;
	}
	(*line)++;
	if (!**line)
		return (missing_data("texures and light", parser));
	if (**line != ' ')
		return (invalid_char("after neighbors data", "space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	return (0);
}

//	New version

int			parse_sector_textures(t_env *env, char **line, t_map_parser *parser)
{
	int	i;

	if (!**line)
		return (missing_data("textures, sprite and light", parser));
	if (**line != '(')
		return (invalid_char("before sector textures", "'('", **line, parser));
	(*line)++;
	if ((parser->sector_textures_count = count_textures(*line, parser)) == -1)
		return (custom_error("Error while counting textures"));
	if (parser->sector_textures_count < parser->sector_vertices_count)
		return (sector_error("is missing one or more textures", parser->sectors_count, parser));
	if (parser->sector_textures_count > parser->sector_vertices_count)
		return (sector_error("has too much textures", parser->sectors_count, parser));
	i = 0;
	while (i < parser->sector_textures_count)
	{
		(*line)++;
		env->sectors[parser->sectors_count].textures[i] = ft_atoi(*line);
		if (env->sectors[parser->sectors_count].textures[i] < -MAX_SKYBOX
		|| env->sectors[parser->sectors_count].textures[i] >= MAX_WALL_TEXTURE)
		{
			ft_dprintf(STDERR_FILENO,
					"[Line %d] Texture \'%d\' in sector %d does not exist\n",
					parser->line_count,
					env->sectors[parser->sectors_count].textures[i],
					parser->sectors_count);
			return (-1);
		}
		*line = skip_number(*line);
		*line = skip_spaces(*line);
		env->sectors[parser->sectors_count].align[i].x = ft_atof(*line);
		*line = skip_number(*line);
		*line = skip_spaces(*line);
		env->sectors[parser->sectors_count].align[i].y = ft_atof(*line);
		*line = skip_number(*line);
		*line = skip_spaces(*line);
		env->sectors[parser->sectors_count].scale[i].x = ft_atof(*line);
		if (env->sectors[parser->sectors_count].scale[i].x <= 0)
			return (custom_error_with_line("Wall scale must be positive", parser));
		*line = skip_number(*line);
		*line = skip_spaces(*line);
		env->sectors[parser->sectors_count].scale[i].y = ft_atof(*line);
		if (env->sectors[parser->sectors_count].scale[i].y <= 0)
			return (custom_error_with_line("Wall scale must be positive", parser));
		*line = skip_number(*line);
		/*if (env->sectors[parser->sectors_count].textures[i] < 0)
		{
			env->sectors[parser->sectors_count].align[i].x *= env->skyboxes[0].textures[0].surface->w;
			env->sectors[parser->sectors_count].align[i].y *= env->skyboxes[0].textures[0].surface->h;
			env->sectors[parser->sectors_count].align[i].x /= 10;
			env->sectors[parser->sectors_count].align[i].y /= 10;
		}
		else
		{
			env->sectors[parser->sectors_count].align[i].x *= env->wall_textures[env->sectors[parser->sectors_count].textures[i]].surface->w;
			env->sectors[parser->sectors_count].align[i].y *= env->wall_textures[env->sectors[parser->sectors_count].textures[i]].surface->h;
			env->sectors[parser->sectors_count].align[i].x /= 10;
			env->sectors[parser->sectors_count].align[i].y /= 10;
		}*/
		if (set_sector_wall_map_array(&env->sectors[parser->sectors_count], 
			env->wall_textures[env->sectors[parser->sectors_count].textures[i]], i,
			env))
			return (-1);
		(*line)++;
		i++;
	}
	(*line)++;
	if (!**line)
		return (missing_data("sprite and light", parser));
	if (**line != ' ')
		return (invalid_char("after textures data", "space(s)", **line, parser));
	*line = skip_spaces(*line);
	return (0);
}

//	Old version

/*int			parse_sector_textures(t_env *env, char **line, t_map_parser *parser)
{
	int	i;

	if (!**line)
		return (missing_data("textures, sprite and light", parser));
	if (**line != '(')
		return (invalid_char("before sector textures", "'('", **line, parser));
	(*line)++;
	if ((parser->sector_textures_count = count_textures(*line, parser)) == -1)
		return (custom_error("Error while counting textures"));
	if (parser->sector_textures_count < parser->sector_vertices_count)
		return (sector_error("is missing one or more textures", parser->sectors_count, parser));
	if (parser->sector_textures_count > parser->sector_vertices_count)
		return (sector_error("has too much textures", parser->sectors_count, parser));
	i = 0;
	while (i < parser->sector_textures_count)
	{
		env->sectors[parser->sectors_count].textures[i] = ft_atoi(*line);
		if (env->sectors[parser->sectors_count].textures[i] < -1 || env->sectors[parser->sectors_count].textures[i] >= MAX_TEXTURE)
		{
			ft_dprintf(STDERR_FILENO,
					"[Line %d] Texture \'%d\' in sector %d does not exist\n",
					parser->line_count,
					env->sectors[parser->sectors_count].textures[i],
					parser->sectors_count);
			return (-1);
		}
		env->sectors[parser->sectors_count].align[i] = new_v2(0, 0);
		if (env->sectors[parser->sectors_count].textures[i] == -1)
		{
			env->sectors[parser->sectors_count].scale[i] = new_v2(
					env->skyboxes[0].textures[0].surface->w,
					env->skyboxes[0].textures[0].surface->h / 10);
		}
		else
		{
			env->sectors[parser->sectors_count].scale[i] = new_v2(
					env->wall_textures[env->sectors[parser->sectors_count].textures[i]].surface->w,
					env->wall_textures[env->sectors[parser->sectors_count].textures[i]].surface->h);
		}
		*line = skip_number(*line);
		*line = skip_spaces(*line);
		i++;
	}
	(*line)++;
	if (!**line)
		return (missing_data("sprite and light", parser));
	if (**line != ' ')
		return (invalid_char("after textures data", "space(s)", **line, parser));
	*line = skip_spaces(*line);
	return (0);
}*/

int			parse_sector_sprite(t_env *env, char **line, t_map_parser *parser)
{
	int	i;
	int	j;

	if (!**line)
		return (missing_data("sprites and light", parser));
	if (**line != '(')
		return (invalid_char("before sector sprites", "'('", **line, parser));
	(*line)++;
	if ((parser->sector_sprites_count = count_sprites(*line, parser)) == -1)
		return (custom_error("Error while counting sprites"));
	if (parser->sector_sprites_count < parser->sector_vertices_count)
		return (sector_error("is missing one or more sprites", parser->sectors_count, parser));
	if (parser->sector_sprites_count > parser->sector_vertices_count)
		return (sector_error("has too much sprites", parser->sectors_count, parser));
	i = 0;
	while (i < parser->sector_sprites_count)
	{
		// NEW VERSION

		if (**line != '{')
			return (invalid_char("at sector sprites", "'{'", **line, parser));
		(*line)++;
		if ((env->sectors[parser->sectors_count].nb_sprites[i] = count_wall_sprites(*line, parser)) == -1)
			return (-1);
		if (!(env->sectors[parser->sectors_count].sprites[i].sprite = (short*)malloc(sizeof(short) * env->sectors[parser->sectors_count].nb_sprites[i])))
			return (-1);
		if (!(env->sectors[parser->sectors_count].sprites[i].pos = (t_v2*)malloc(sizeof(t_v2) * env->sectors[parser->sectors_count].nb_sprites[i])))
			return (-1);
		if (!(env->sectors[parser->sectors_count].sprites[i].scale = (t_v2*)malloc(sizeof(t_v2) * env->sectors[parser->sectors_count].nb_sprites[i])))
			return (-1);
		j = 0;
		while (j < env->sectors[parser->sectors_count].nb_sprites[i])
		{
			(*line)++;
			env->sectors[parser->sectors_count].sprites[i].sprite[j] = ft_atoi(*line);
			if (env->sectors[parser->sectors_count].sprites[i].sprite[j] < -1
					|| env->sectors[parser->sectors_count].sprites[i].sprite[j] > MAX_WALL_SPRITES)
				return (custom_error_with_line("Invalid sprite texture", parser));
			*line = skip_number(*line);
			*line = skip_spaces(*line);
			env->sectors[parser->sectors_count].sprites[i].pos[j].x = ft_atof(*line);
			*line = skip_number(*line);
			*line = skip_spaces(*line);
			env->sectors[parser->sectors_count].sprites[i].pos[j].y = ft_atof(*line);
			*line = skip_number(*line);
			*line = skip_spaces(*line);
			env->sectors[parser->sectors_count].sprites[i].scale[j].x = ft_atof(*line);
			if (env->sectors[parser->sectors_count].sprites[i].scale[j].x <= 0)
				return (custom_error_with_line("Sprite scale must be positive", parser));
			*line = skip_number(*line);
			*line = skip_spaces(*line);
			env->sectors[parser->sectors_count].sprites[i].scale[j].y = ft_atof(*line);
			if (env->sectors[parser->sectors_count].sprites[i].scale[j].y <= 0)
				return (custom_error_with_line("Sprite scale must be positive", parser));
			*line = skip_number(*line);
			(*line)++;
			j++;
		}
		if (**line != '}')
			return (invalid_char("at sector sprites", "'}'", **line, parser));
		(*line)++;
		i++;

		// OLD VERSION

		/*env->sectors[parser->sectors_count].nb_sprites[i] = 1;
		if (!(env->sectors[parser->sectors_count].sprites[i].sprite = (short*)malloc(sizeof(short) * env->sectors[parser->sectors_count].nb_sprites[i])))
			return (-1);
		if (!(env->sectors[parser->sectors_count].sprites[i].pos = (t_v2*)malloc(sizeof(t_v2) * env->sectors[parser->sectors_count].nb_sprites[i])))
			return (-1);
		if (!(env->sectors[parser->sectors_count].sprites[i].scale = (t_v2*)malloc(sizeof(t_v2) * env->sectors[parser->sectors_count].nb_sprites[i])))
			return (-1);
		j = 0;
		while (j < env->sectors[parser->sectors_count].nb_sprites[i])
		{
			(*line)++;
			env->sectors[parser->sectors_count].sprites[i].sprite[j] = ft_atoi(*line);
			if (env->sectors[parser->sectors_count].sprites[i].sprite[j] < -1
					|| env->sectors[parser->sectors_count].sprites[i].sprite[j] > MAX_SPRITES)
				return (custom_error_with_line("Invalid sprite texture", parser));
			*line = skip_number(*line);
			*line = skip_spaces(*line);
			env->sectors[parser->sectors_count].sprites[i].pos[j].x = ft_atof(*line);
			*line = skip_number(*line);
			*line = skip_spaces(*line);
			env->sectors[parser->sectors_count].sprites[i].pos[j].y = ft_atof(*line);
			*line = skip_number(*line);
			*line = skip_spaces(*line);
			env->sectors[parser->sectors_count].sprites[i].scale[j].x = ft_atof(*line);
			if (env->sectors[parser->sectors_count].sprites[i].scale[j].x <= 0)
				return (custom_error_with_line("Sprite scale must be positive", parser));
			*line = skip_number(*line);
			*line = skip_spaces(*line);
			env->sectors[parser->sectors_count].sprites[i].scale[j].y = ft_atof(*line);
			if (env->sectors[parser->sectors_count].sprites[i].scale[j].y <= 0)
				return (custom_error_with_line("Sprite scale must be positive", parser));
			*line = skip_number(*line);
			(*line)++;
			j++;
		}
		i++;*/
	}
	env->sectors[parser->sectors_count].nb_sprites[i] = env->sectors[parser->sectors_count].nb_sprites[0];
	(*line)++;
	if (**line != ' ')
		return (invalid_char("after sector sprites", "space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	return (0);
}

//	NEW VERSION

int			parse_sector_light(t_env *env, char **line, t_map_parser *parser)
{
	if (**line != '[')
		return (invalid_char("before sector light", "'['", **line, parser));
	(*line)++;
	if (!**line)
		return (missing_data("light", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before light", "a digit", **line, parser));
	env->sectors[parser->sectors_count].brightness = ft_atoi(*line);
	env->sectors[parser->sectors_count].light_color = 0xFF409CFF;
	if (env->sectors[parser->sectors_count].brightness < -255 ||
			env->sectors[parser->sectors_count].brightness > 255)
		return (custom_error("Light must be between -255 and 255"));
	env->sectors[parser->sectors_count].intensity = 0;
	*line = skip_number(*line);
	if (**line != ']')
		return (invalid_char("after sector light", "']'", **line, parser));
	(*line)++;
	if (!**line)
		return (missing_data("sector status", parser));
	if (**line != ' ')
		return (invalid_char("after light data", "space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	return (0);
}

//	OLD VERSION

/*int			parse_sector_light(t_env *env, char **line, t_map_parser *parser)
{
	if (!**line)
		return (missing_data("light", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before light", "a digit", **line, parser));
	env->sectors[parser->sectors_count].brightness = ft_atoi(*line);
	env->sectors[parser->sectors_count].light_color = 0xFFFFFFFF;
	if (env->sectors[parser->sectors_count].brightness < -255 ||
			env->sectors[parser->sectors_count].brightness > 255)
		return (custom_error("Light must be between -255 and 255"));
	*line = skip_number(*line);
	*line = skip_spaces(*line);
	if (**line != '\0')
		return (extra_data("light", parser));
	return (0);
}*/

int			parse_sector_status(t_env *env, char **line, t_map_parser *parser)
{
	if (**line != '[')
		return (invalid_char("before sector status", "'['", **line, parser));
	(*line)++;
	if (!**line)
		return (missing_data("sector status", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before sector status", "a digit", **line, parser));
	env->sectors[parser->sectors_count].status = ft_atoi(*line);
	if (env->sectors[parser->sectors_count].status > 5 ||
			env->sectors[parser->sectors_count].status < 0)
		return (custom_error_with_line("sector status must be between 0 and 5", parser));
	*line = skip_number(*line);
	if (**line != ' ')
		return (invalid_char("after sector status", "space(s)",
					**line, parser));
	*line = skip_spaces(*line);
/*	if (valid_number(*line, parser))
		return (invalid_char("before first coordinate", "a digit", **line, parser));
	env->sectors[parser->sectors_count].tp.x = ft_atoi(*line);
	*line = skip_number(*line);
	*line = skip_spaces(*line);
	if (!**line)
		return (missing_data("coordinates missing after sector status", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before second coordinate", "a digit", **line, parser));
	env->sectors[parser->sectors_count].tp.y = ft_atoi(*line);
	*line = skip_number(*line);*/
	if (!**line)
		return (missing_data("coordinates missing after sector status", parser));
	if (**line != '(')
		return (invalid_char("before sector potential telportation pos", "'('", **line, parser));
	(*line)++;
	if (valid_number(*line, parser))
		return (invalid_char("before first coordinate", "a digit", **line, parser));
	env->sectors[parser->sectors_count].tp.x = ft_atoi(*line);
	*line = skip_number(*line);
	if (**line != ' ')
		return (invalid_char("after sector first coordonate for teleportation", "space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	if (!**line)
		return (missing_data("coordinates missing after sector status", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before second coordinate", "a digit", **line, parser));
	env->sectors[parser->sectors_count].tp.y = ft_atoi(*line);
	*line = skip_number(*line);
	if (**line != ')')
		return (invalid_char("after sector status", "')'", **line, parser));
	(*line)++;
	if (**line != ' ')
		return (invalid_char("after sector telportation coordonates", "space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	if (**line != '(')
		return (invalid_char("before sector data for hiding it", "'('", **line, parser));
	(*line)++;
	if (valid_number(*line, parser))
		return (invalid_char("before enemy reference to hide sector", "a digit", **line, parser));
	env->sectors[parser->sectors_count].enemy_flag = ft_atoi(*line);
	*line = skip_number(*line);
	if (**line != ' ')
		return (invalid_char("after enemy reference to hide sector", "space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	if (!**line)
		return (missing_data("coordinates missing after sector enemy reference", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before sector flag of activation to reveal sector", "a digit", **line, parser));
	env->sectors[parser->sectors_count].activated = ft_atoi(*line);
	*line = skip_number(*line);
	if (**line != ' ')
		return (invalid_char("after activation reference to hide sector", "space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	if (!**line)
		return (missing_data("data missing after sector activation reference", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before floor reference to reveal sector", "a digit", **line, parser));
	env->sectors[parser->sectors_count].start_floor = ft_atof(*line);
	*line = skip_number(*line);
	if (**line != ')')
		return (invalid_char("after sector data for hiding", "')'", **line, parser));
	(*line)++;
	if (**line != ']')
		return (invalid_char("before sector status", "']'", **line, parser));
	(*line)++;
	if (**line != '\0')
		return (extra_data(*line, parser));
	return (0);
}

static int	parse_sector(t_env *env, char *line, t_map_parser *parser)
{
	parser->sector_vertices_count = 0;
	parser->sector_neighbors_count = 0;
	parser->sector_textures_count = 0;
	parser->sector_sprites_count = 0;
	env->sectors[parser->sectors_count].sprite_time = 0;
	env->sectors[parser->sectors_count].num = parser->sectors_count;
	if (parse_floor(env, &line, parser))
		return (-1);
	if (parse_floor_sprites(env, &line, parser))
		return (-1);
	//return (custom_error("Error while parsing floor"));
	if (parse_ceiling(env, &line, parser))
		return (-1);
	//return (custom_error("Error while parsing ceiling"));
	if (parse_ceiling_sprites(env, &line, parser))
		return (-1);
	if (env->sectors[parser->sectors_count].ceiling
			< env->sectors[parser->sectors_count].floor)
		return (-1);
	//return (sector_error("ceiling must be higher than its floor",
	//parser->sectors_count, parser));
	if (init_sector_data(env, line, parser))
		return (-1);
	//return (custom_error("Could not init sector data"));
	line++;
	if (parse_sector_vertices(env, &line, parser))
		return (-1);
	//return (custom_error("Error while parsing sector vertices"));z
	if (parse_sector_neighbors(env, &line, parser))
		return (-1);
	//return (custom_error("Error while parsing sector neighbors"));
	if (parse_sector_textures(env, &line, parser))
		return (-1);
	//return (custom_error("Error while parsing sector textures"));
	if (parse_sector_sprite(env, &line, parser))
		return (-1);
	if (parse_sector_light(env, &line, parser))
		return (-1);
		//return (custom_error("Error while parsing sector light"));
	if (parse_sector_status(env, &line, parser))
		return (-1);
	return (0);
}

int			parse_sectors(t_env *env, t_map_parser *parser)
{
	char	*line;
	char	*tmp;

	line = NULL;
	while (parser->sectors_count < env->nb_sectors
			&& (parser->ret = get_next_line(parser->fd, &line)))
	{
		tmp = line;
		parser->line_count++;
		if (*tmp)
		{
			if (parse_sector(env, tmp, parser))
				return (-1);
			parser->sectors_count++;
		}
		else
		{
			ft_dprintf(STDERR_FILENO,
					"[Line %d] You must still declare %d sector(s)\n",
					parser->line_count,
					env->nb_sectors - parser->sectors_count);
			return (-1);
		}
		ft_strdel(&line);
	}
	if ((parser->ret = get_next_line(parser->fd, &line)))
	{
		parser->line_count++;
		if (*line)
			return (custom_error_with_line("Must be an empty line "
						"(every sector has been declared)",
						parser));
		ft_strdel(&line);
	}
	else
		return (missing_data("objects and player data", parser));
	return (0);
}
