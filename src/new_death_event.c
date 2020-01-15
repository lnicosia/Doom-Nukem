/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_death_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:19:38 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/15 17:27:18 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"

int		new_death_event(t_env *env, t_map_parser *parser, char **line,
t_events_parser *eparser)
{
	(void)line;
	(void)parser;
	(void)env;
	(void)eparser;
	if (enemy_parser(env, parser, line, eparser))
		return (-1);
	/*if (!(env->sectors[eparser->sector].death_event = (t_event*)ft_realloc(
		env->sectors[eparser->sector].death_event,
		sizeof(t_event) * env->sectors[eparser->sector].nb_death_events,
		sizeof(t_event) * (env->sectors[eparser->sector].nb_death_events + 1))))
		return (ft_perror("Could not realloc global events"));
	env->sectors[eparser->sector].nb_death_events++;*/
	return (0);
}
