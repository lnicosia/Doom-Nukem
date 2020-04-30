/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_enemy_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:03:07 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 18:45:18 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		parse_enemy_pos4(t_env *env, t_map_parser *parser)
{
	if (env->enemies[parser->enemies_count].sector >= 0)
	{
		if (env->enemies[parser->enemies_count].pos.z
		< get_floor_at_pos(&env->sectors[env->enemies[parser->enemies_count].
		sector], env->enemies[parser->enemies_count].pos, env))
			return (ft_printf("Enemy %d is under the floor\n",
			parser->enemies_count));
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

int		parse_enemy_pos3(t_env *env, char **line, t_map_parser *parser)
{
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
	return (parse_enemy_pos4(env, parser));
}

int		parse_enemy_pos2(t_env *env, char **line, t_map_parser *parser)
{
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
	return (parse_enemy_pos3(env, line, parser));
}

int		parse_enemy_pos(t_env *env, char **line, t_map_parser *parser)
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
		return (parse_enemy_pos2(env, line, parser));
}
