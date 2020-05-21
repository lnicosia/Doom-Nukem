/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_floor_sprites.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:20:37 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 17:10:15 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "map_parser.h"

int		parse_floor_sprites3(t_env *env, char **line, t_map_parser *parser)
{
	int	i;

	i = 0;
	while (i < parser->sector_floor_sprites_count)
	{
		if (parse_current_floor_sprite(env, line, parser, i))
			return (-1);
		i++;
	}
	(*line)++;
	if (**line != ' ')
		return (invalid_char("after sector floor sprites", "space(s)",
			**line, parser));
		*line = skip_spaces(*line);
	return (0);
}

int		parse_floor_sprites2(t_env *env, char **line, t_map_parser *parser)
{
	if (!(env->sectors[parser->sectors_count].floor_sprites.nb_shoot_events =
		(size_t*)ft_memalloc(sizeof(size_t)
		* parser->sector_floor_sprites_count)))
		return (ft_perror("Could not malloc sector floor"
		" sprite nb shoot events"));
	if (!(env->sectors[parser->sectors_count].floor_sprites.nb_press_events =
		(size_t*)ft_memalloc(sizeof(size_t)
		* parser->sector_floor_sprites_count)))
		return (ft_perror("Could not malloc sector floor"
		" sprite nb press events"));
	if (!(env->sectors[parser->sectors_count].floor_sprites.shoot_events =
		(t_event**)ft_memalloc(sizeof(t_event*)
		* parser->sector_floor_sprites_count)))
		return (ft_perror("Could not malloc sector floor"
		" sprite shoot events"));
	if (!(env->sectors[parser->sectors_count].floor_sprites.press_events =
		(t_event**)ft_memalloc(sizeof(t_event*)
		* parser->sector_floor_sprites_count)))
		return (ft_perror("Could not malloc sector floor"
		" sprite press events"));
	return (parse_floor_sprites3(env, line, parser));
}

int		parse_floor_sprites(t_env *env, char **line, t_map_parser *parser)
{
	if (!**line)
		return (missing_data("floor sprites", parser));
	if (**line != '(')
		return (invalid_char("before floor sprites", "'('", **line, parser));
	(*line)++;
	if ((parser->sector_floor_sprites_count =
		count_floor_sprites(*line, parser)) == -1)
		return (custom_error("Error while counting floor sprites\n"));
	env->sectors[parser->sectors_count].floor_sprites.nb_sprites =
	parser->sector_floor_sprites_count;
	if (!(env->sectors[parser->sectors_count].floor_sprites.sprite = (int*)
		ft_memalloc(sizeof(int) * parser->sector_floor_sprites_count)))
		return (ft_perror("Could not malloc sector floor sprite indexes"));
	if (!(env->sectors[parser->sectors_count].floor_sprites.scale = (t_v2*)
		ft_memalloc(sizeof(t_v2) * parser->sector_floor_sprites_count)))
		return (ft_perror("Could not malloc sector floor sprite scales"));
	if (!(env->sectors[parser->sectors_count].floor_sprites.pos = (t_v2*)
		ft_memalloc(sizeof(t_v2) * parser->sector_floor_sprites_count)))
		return (ft_perror("Could not malloc sector floor sprite pos"));
	if (!(env->sectors[parser->sectors_count].floor_sprites_scale = (t_v2*)
		ft_memalloc(sizeof(t_v2) * parser->sector_floor_sprites_count)))
		return (ft_perror("Could not malloc sector floor sprite pos"));
	return (parse_floor_sprites2(env, line, parser));
}
