/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_enemies.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 14:18:10 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 17:04:55 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "parser.h"

int		parse_enemy(t_env *env, char *line, t_map_parser *parser)
{
	env->enemies[parser->enemies_count].num = parser->enemies_count;
	if (parse_enemy_pos(env, &line, parser))
		return (-1);
	if (parse_enemy_sprite(env, &line, parser))
		return (-1);
	if (parse_enemy_data(env, &line, parser))
		return (-1);
	return (0);
}

int		parse_enemies2(t_env *env, t_map_parser *parser)
{
	if ((parser->ret = get_next_line(parser->fd, &(parser->line))))
	{
		parser->line_count++;
		if (*(parser->line))
			return (custom_error_with_line("Must be an empty line "
				"(every enemy has been declared)\n", parser));
			ft_strdel(&(parser->line));
	}
	else
		return (missing_data("player data", parser));
	if (!(env->player.colliding_enemies = (int*)ft_memalloc(sizeof(int)
		* env->nb_enemies)))
		return (ft_perror("Could not malloc player colliding enemies"));
	return (0);
}

int		parse_enemies(t_env *env, t_map_parser *parser)
{
	char	*line;

	while (parser->enemies_count < env->nb_enemies
			&& (parser->ret = get_next_line(parser->fd, &(parser->line))))
	{
		parser->line_count++;
		line = parser->line;
		if (*line)
		{
			if (parse_enemy(env, line, parser))
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
	return (parse_enemies2(env, parser));
}
