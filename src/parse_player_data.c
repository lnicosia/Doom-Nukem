/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:05:08 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 17:11:52 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "env.h"

/*
**	Parses player's speed
*/

int		parse_player_data3(t_env *env, t_map_parser *parser, char **line)
{
	*line = skip_number(*line);
	if (**(line) && **(line) != ' ')
		return (invalid_char("player speed", "space or a digit", **(line),
		parser));
		if (!**(line))
		return (missing_data("player speed", parser));
	*line = skip_spaces(*line);
	if (!**(line))
		return (missing_data("player speed", parser));
	if (valid_double(*line, parser))
		return (custom_error("Invalid int for player speed\n"));
	env->player.speed = ft_atof(*line);
	if (env->player.speed < 0.1 || env->player.speed > 1)
		return (custom_error("Player's speed must be between 0.1 and 1\n"));
	env->player.start_speed = env->player.speed;
	return (0);
}

/*
**	Parses player's armor
*/

int		parse_player_data2(t_env *env, t_map_parser *parser, char **line)
{
	*line = skip_number(*line);
	if (**(line) && **(line) != ' ')
		return (invalid_char("player armor", "space or a digit", **(line),
		parser));
		if (!**(line))
		return (missing_data("player armor and speed", parser));
	*line = skip_spaces(*line);
	if (!**(line))
		return (missing_data("player armor and speed", parser));
	if (valid_int(*line, parser))
		return (custom_error("Invalid int for player armor\n"));
	env->player.armor = ft_atoi(*line);
	if (env->player.armor < 0 || env->player.armor > 100)
		return (custom_error("Player's armor must be between 0 and 100\n"));
	return (parse_player_data3(env, parser, line));
}

/*
**	Parses player's health
*/

int		parse_player_data(t_env *env, t_map_parser *parser, char **line)
{
	*line = skip_number(*line);
	if (**(line) && **(line) != ' ')
		return (invalid_char("player health", "space or a digit", **(line),
		parser));
		if (!*(line))
		return (missing_data("player health, armor and speed", parser));
	*line = skip_spaces(*line);
	if (!**(line))
		return (missing_data("player health, armor and speed", parser));
	if (valid_int(*line, parser))
		return (custom_error("Invalid int for player health\n"));
	env->player.health = ft_atoi(*line);
	if (env->player.health < 1 || env->player.health > 100)
		return (custom_error("Player's health must be between 1 and 100\n"));
	return (parse_player_data2(env, parser, line));
}
