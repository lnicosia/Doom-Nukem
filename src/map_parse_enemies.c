/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_enemies.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 14:18:10 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/11 12:25:18 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "map_parser.h"

static int	parse_enemy_data(t_env *env, char **line, t_map_parser *parser)
{
	if (**line != '[')
		return (invalid_char("before enemy data", "'['", **line, parser));
	(*line)++;
	if (!**line || **line == ']')
		return (missing_data("enemy health, speed and damage", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before enemy health", "a digit",
					**line, parser));
	env->enemies[parser->enemies_count].health = ft_atoi(*line);
	if (env->enemies[parser->enemies_count].health <= 0)
		return (custom_error_with_line("Enemy must have 1 or more health points", parser));
	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("enemy speed and damage", parser));
	if (**line && **line != ' ')
		return (invalid_char("after enemy health", "a digit or space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("enemy speed and damage", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before enemy speed", "a digit or space(s)",
					**line, parser));
	env->enemies[parser->enemies_count].speed = ft_atoi(*line);
	if (env->enemies[parser->enemies_count].speed < 0 || env->enemies[parser->enemies_count].speed > 100)
		return (custom_error_with_line("Enemy must have speed between 0 and 100", parser));
	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("enemy damage", parser));
	if (**line && **line != ' ')
		return (invalid_char("after enemy speed", "a digit or space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("enemy damage", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before enemy damage", "a digit or space(s)",
					**line, parser));
	env->enemies[parser->enemies_count].damage = ft_atoi(*line);
	if (env->enemies[parser->enemies_count].damage <= 0)
		return (custom_error_with_line("Enemy must do more than 0 damage", parser));
	*line = skip_number(*line);
	if (!**line)
		return (missing_data("']' after enemy damage", parser));
	if (**line != ']')
		return (invalid_char("after enemy damage", "a digit or ']'",
					**line, parser));
	(*line)++;
	if (**line)
		return (extra_data("enemy damage", parser));
	return (0);
}

static int	parse_enemy_sprite(t_env *env, char **line, t_map_parser *parser)
{
	if (**line != '[')
		return (invalid_char("before enemy sprite", "'['", **line, parser));
	(*line)++;
	if (!**line || **line == ']')
		return (missing_data("enemy sprite and scale", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before enemy sprite", "a digit",
					**line, parser));
	env->enemies[parser->enemies_count].sprite = ft_atoi(*line);
	if (env->enemies[parser->enemies_count].sprite < 0
			|| env->enemies[parser->enemies_count].sprite >= MAX_SPRITES)
		return (custom_error_with_line("Invalid sprite texture", parser));
	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("enemy scale", parser));
	if (**line && **line != ' ')
		return (invalid_char("after enemy sprite", "a digit or space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("enemy scale", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before enemy scale", "a digit or space(s)",
					**line, parser));
	env->enemies[parser->enemies_count].scale = ft_atof(*line);
	*line = skip_number(*line);
	if (!**line)
		return (missing_data("']' after enemy scale", parser));
	if (**line != ']')
		return (invalid_char("after enemy scale", "a digit or ']'",
					**line, parser));
	(*line)++;
	if (!**line)
		return (missing_data("enemy data, health speed and damage", parser));
	if (**line != ' ')
		return (invalid_char("after enemy scale", "space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	return (0);
}

static int	parse_enemy_pos(t_env *env, char **line, t_map_parser *parser)
{
	if (**line != '[')
		return (invalid_char("before enemy y", "'['", **line, parser));
	(*line)++;
	if (!**line || **line == ']')
		return (missing_data("enemy y, x, z and angle", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before enemy y", "a digit", **line, parser));
	env->enemies[parser->enemies_count].pos.y = ft_atof(*line);
	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("enemy x, z and angle", parser));
	if (**line && **line != ' ')
		return (invalid_char("after enemy y", "a digit or space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("enemy x, z and angle", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before enemy x", "a digit", **line, parser));
	env->enemies[parser->enemies_count].pos.x = ft_atof(*line);
	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("enemy z and angle", parser));
	if (**line && **line != ' ')
		return (invalid_char("after enemy x", "a digit or space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("enemy z and angle", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before enemy z", "a digit or space(s)",
					**line, parser));
	env->enemies[parser->enemies_count].pos.z = ft_atof(*line);
	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("enemy angle", parser));
	if (**line && **line != ' ')
		return (invalid_char("after enemy z", "a digit or space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("enemy angle", parser));
	if (valid_number(*line, parser))
		return (invalid_char("before enemy angle", "a digit or space(s)",
					**line, parser));
	env->enemies[parser->enemies_count].angle = ft_atof(*line);
	*line = skip_number(*line);
	if (!**line)
		return (missing_data("']' after enemy angle", parser));
	if (**line != ']')
		return (invalid_char("after enemy angle", "a digit or ']'",
					**line, parser));
	(*line)++;
	if (!**line)
		return (missing_data("enemy sprite and scale", parser));
	if (**line != ' ')
		return (invalid_char("after enemy angle", "space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	env->enemies[parser->enemies_count].sector = get_sector_no_z(env,
			new_v3(env->enemies[parser->enemies_count].pos.x,
				env->enemies[parser->enemies_count].pos.y,
				env->enemies[parser->enemies_count].pos.z));
	env->enemies[parser->enemies_count].brightness =
		env->sectors[env->enemies[parser->enemies_count].sector].brightness;
	env->enemies[parser->enemies_count].light_color =
		env->sectors[env->enemies[parser->enemies_count].sector].light_color;
	return (0);
}

static int	parse_enemy(t_env *env, char *line, t_map_parser *parser)
{
	env->enemies[parser->enemies_count].num = parser->enemies_count;
	if (parse_enemy_pos(env, &line, parser))
		return (-1);
	//return (custom_error("Error while parsing enemy pos"));
	if (parse_enemy_sprite(env, &line, parser))
		return (-1);
	if (parse_enemy_data(env, &line, parser))
		return (-1);
	//return (custom_error("Error while parsing enemy pos"));
	return (0);
}

int			parse_enemies(t_env *env, t_map_parser *parser)
{
	char	*line;
	char	*tmp;

	while (parser->enemies_count < env->nb_enemies
			&& (parser->ret = get_next_line(parser->fd, &line)))
	{
		parser->line_count++;
		tmp = line;
		if (*tmp)
		{
			if (parse_enemy(env, tmp, parser))
				return (-1);
			parser->enemies_count++;
		}
		else
		{
			ft_dprintf(STDERR_FILENO,
					"[Line %d] You must still declare %d enemies\n",
					parser->line_count,
					env->nb_enemies - parser->enemies_count);
			return (-1);
		}
		ft_strdel(&line);
	}
	if ((parser->ret = get_next_line(parser->fd, &line)))
	{
		parser->line_count++;
		if (*line)
			return (custom_error_with_line("Must be an empty line "
						"(every enemy has been declared)\n",
						parser));
		ft_strdel(&line);
	}
	else
		return (missing_data("player data", parser));
	return (0);
}
