/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_enemy_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 17:54:30 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 18:02:20 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		parse_enemy_data3(char **line, t_map_parser *parser)
{
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

int		parse_enemy_data2(t_env *env, char **line, t_map_parser *parser)
{
	env->enemies[parser->enemies_count].speed = ft_atoi(*line);
	if (env->enemies[parser->enemies_count].speed < 0
		|| env->enemies[parser->enemies_count].speed > 100)
		return (custom_error_with_line("Enemy must have speed"
		" between 0 and 100", parser));
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
		return (custom_error_with_line("Enemy must do more than 0 damage",
		parser));
		return (parse_enemy_data3(line, parser));
}

int		parse_enemy_data(t_env *env, char **line, t_map_parser *parser)
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
		return (custom_error_with_line("Enemy must have 1 or more health"
		" points", parser));
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
		return (parse_enemy_data2(env, line, parser));
}
