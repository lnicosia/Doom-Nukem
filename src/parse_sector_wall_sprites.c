/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sector_wall_sprites.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:20:37 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/19 12:39:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"
#include "parser.h"

int		parse_current_wall_sprites2(t_env *env, char **line,
t_map_parser *parser, int i)
{
	int		j;

	if (!(env->sectors[parser->sectors_count].wall_sprites[i].
		nb_press_events = (size_t*)ft_memalloc(sizeof(size_t)
		* env->sectors[parser->sectors_count].wall_sprites[i].nb_sprites)))
		return (ft_perror("Could not malloc sector nb press event"));
	if (!(env->sectors[parser->sectors_count].wall_sprites[i].press_events =
		(t_event**)ft_memalloc(sizeof(t_event*)
		* env->sectors[parser->sectors_count].wall_sprites[i].nb_sprites)))
		return (ft_perror("Could not malloc sector press events"));
	if (!(env->sectors[parser->sectors_count].wall_sprites[i].shoot_events =
		(t_event**)ft_memalloc(sizeof(t_event*)
		* env->sectors[parser->sectors_count].wall_sprites[i].nb_sprites)))
		return (ft_perror("Could not malloc sector shoot events"));
	j = -1;
	while (++j < env->sectors[parser->sectors_count].wall_sprites[i].
		nb_sprites)
	{
		if (parse_current_sprite(env, line, parser, new_point(i, j)))
			return (-1);
	}
	if (**line != '}')
		return (invalid_char("at sector sprites", "'}'", **line, parser));
	(*line)++;
	return (0);
}

int		parse_current_wall_sprites(t_env *env, char **line,
t_map_parser *parser, int i)
{
	if (**line != '{')
		return (invalid_char("at sector sprites", "'{'", **line, parser));
	(*line)++;
	if ((env->sectors[parser->sectors_count].wall_sprites[i].nb_sprites =
		count_wall_sprites(*line, parser)) == -1)
		return (-1);
	if (!(env->sectors[parser->sectors_count].wall_sprites[i].sprite =
		(int*)ft_memalloc(sizeof(int)
		* env->sectors[parser->sectors_count].wall_sprites[i].nb_sprites)))
		return (ft_perror("Could not malloc sector wall sprite index"));
	if (!(env->sectors[parser->sectors_count].wall_sprites[i].pos =
		(t_v2*)ft_memalloc(sizeof(t_v2)
		* env->sectors[parser->sectors_count].wall_sprites[i].nb_sprites)))
		return (ft_perror("Could not malloc sector wall sprite pos"));
	if (!(env->sectors[parser->sectors_count].wall_sprites[i].scale =
		(t_v2*)ft_memalloc(sizeof(t_v2)
		* env->sectors[parser->sectors_count].wall_sprites[i].nb_sprites)))
		return (ft_perror("Could not malloc sector wall sprite scale"));
	if (!(env->sectors[parser->sectors_count].wall_sprites[i].
		nb_shoot_events = (size_t*)ft_memalloc(sizeof(size_t)
		* env->sectors[parser->sectors_count].wall_sprites[i].nb_sprites)))
		return (ft_perror("Could not malloc sector wall sprite"
		" nb shoot events"));
	return (parse_current_wall_sprites2(env, line, parser, i));
}

int		parse_sector_wall_sprites2(t_env *env, char **line,
t_map_parser *parser, int i)
{
	env->sectors[parser->sectors_count].wall_sprites[i] =
	env->sectors[parser->sectors_count].wall_sprites[0];
	(*line)++;
	if (**line != ' ')
		return (invalid_char("after sector sprites", "space(s)",
			**line, parser));
		*line = skip_spaces(*line);
	return (0);
}

int		parse_sector_wall_sprites(t_env *env, char **line,
t_map_parser *parser)
{
	int	i;

	if (!**line)
		return (missing_data("sprites and light", parser));
	if (**line != '(')
		return (invalid_char("before sector sprites", "'('", **line, parser));
	(*line)++;
	if ((parser->sector_sprites_count = count_sprites(*line, parser)) == -1)
		return (custom_error("Error while counting sprites\n"));
	if (parser->sector_sprites_count < parser->sector_vertices_count)
		return (sector_error("is missing one or more sprites",
		parser->sectors_count, parser));
	if (parser->sector_sprites_count > parser->sector_vertices_count)
		return (sector_error("has too much sprites", parser->sectors_count,
		parser));
	i = 0;
	while (i < parser->sector_sprites_count)
	{
		if (parse_current_wall_sprites(env, line, parser, i))
			return (-1);
		i++;
	}
	return (parse_sector_wall_sprites2(env, line, parser, i));
}
