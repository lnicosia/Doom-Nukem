/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_enemies.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 14:18:10 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/02 11:51:55 by sipatry          ###   ########.fr       */
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
	if (valid_int(*line, parser))
		return (ft_printf("Invalid int for enemy %d hp\n",
		parser->enemies_count));
	env->enemies[parser->enemies_count].map_hp = ft_atoi(*line);
	if (env->enemies[parser->enemies_count].map_hp <= 0)
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
	if (valid_int(*line, parser))
		return (ft_printf("Invalid int for enemy %d speed\n",
		parser->enemies_count));
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
	if (valid_int(*line, parser))
		return (ft_printf("Invalid int for enemy %d damage\n",
		parser->enemies_count));
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
	int	parse;

	if (**line != '[')
		return (invalid_char("before enemy sprite", "'['", **line, parser));
	(*line)++;
	if (!**line || **line == ']')
		return (missing_data("enemy sprite and scale", parser));
	if (valid_int(*line, parser))
		return (ft_printf("Invalid int for enemy %d texture",
		parser->enemies_count));
	parse = ft_atoi(*line);
	if (parse < 0
			|| parse >= MAX_ENEMIES)
		return (custom_error_with_line("Invalid sprite texture", parser));
	env->enemies[parser->enemies_count].sprite =
	env->enemies_main_sprites[parse];
	*line = skip_number(*line);
	if (!**line || **line == ']')
		return (missing_data("enemy scale", parser));
	if (**line && **line != ' ')
		return (invalid_char("after enemy sprite", "a digit or space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	if (!**line || **line == ']')
		return (missing_data("enemy scale", parser));
	if (valid_double(*line, parser))
		return (ft_printf("Invalid double for enemy %d scale",
		parser->enemies_count));
	env->enemies[parser->enemies_count].scale = ft_atof(*line);
	if (env->enemies[parser->enemies_count].scale
	+ env->enemies[parser->enemies_count].pos.z + 1
	> get_ceiling_at_pos(env->sectors[env->enemies[parser->enemies_count].sector],
	env->enemies[parser->enemies_count].pos, env))
		return (ft_printf("Enemy's head is too high compared to ceiling height\n"));
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
	if (valid_double(*line, parser))
		return (ft_printf("Invalid double for enemy %d pos.y\n",
		parser->enemies_count));
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
	if (valid_double(*line, parser))
		return (ft_printf("Invalid double for enemy %d pos.x\n",
		parser->enemies_count));
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
	if (valid_double(*line, parser))
		return (ft_printf("Invalid double for enemy %d pos.z\n",
		parser->enemies_count));
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
	if (valid_double(*line, parser))
		return (ft_printf("Invalid double for enemy %d angle\n",
		parser->enemies_count));
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
	if (env->enemies[parser->enemies_count].sector >= 0)
	{
		if (env->enemies[parser->enemies_count].pos.z
		< get_floor_at_pos(env->sectors[env->enemies[parser->enemies_count].sector],
		env->enemies[parser->enemies_count].pos, env))
			return (ft_printf("Enemy %d is under the floor\n", parser->enemies_count));
		env->enemies[parser->enemies_count].brightness =
			env->sectors[env->enemies[parser->enemies_count].sector].brightness;
		env->enemies[parser->enemies_count].light_color =
			env->sectors[env->enemies[parser->enemies_count].sector].light_color;
		env->enemies[parser->enemies_count].intensity =
			env->sectors[env->enemies[parser->enemies_count].sector].intensity;
	}
	else
	{
		env->enemies[parser->enemies_count].brightness = 0;
		env->enemies[parser->enemies_count].light_color = 0;
		env->enemies[parser->enemies_count].intensity = 0;
	}
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
	while (parser->enemies_count < env->nb_enemies
			&& (parser->ret = get_next_line(parser->fd, &(parser->line))))
	{
		parser->line_count++;
		parser->tmp = parser->line;
		if (*(parser->tmp))
		{
			if (parse_enemy(env, parser->tmp, parser))
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
		ft_strdel(&(parser->line));
	}
	if ((parser->ret = get_next_line(parser->fd, &(parser->line))))
	{
		parser->line_count++;
		if (*(parser->line))
			return (custom_error_with_line("Must be an empty line "
						"(every enemy has been declared)\n",
						parser));
		ft_strdel(&(parser->line));
	}
	else
		return (missing_data("player data", parser));
	if (!(env->player.colliding_enemies = (int*)ft_memalloc(sizeof(int)
		* env->nb_enemies)))
		return (ft_perror("Could not malloc player colliding enemies"));
	return (0);
}
