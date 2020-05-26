/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:39:19 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/22 16:07:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"
#include "events.h"

void		free_parser(t_env *env)
{
	if (env->parser.tmp)
		ft_strdel(&env->parser.tmp);
	if (env->parser.resource_name)
		ft_strdel(&env->parser.resource_name);
	if (env->parser.line)
		ft_strdel(&env->parser.line);
	if (env->eparser.current_str)
		ft_strdel(&env->eparser.current_str);
}

void		free_all2(t_env *env)
{
	if (env->save_file)
		ft_strdel(&env->save_file);
	if (env->res[0])
		ft_strdel(&env->res[0]);
	if (env->res[1])
		ft_strdel(&env->res[1]);
	if (env->res[2])
		ft_strdel(&env->res[2]);
	if (env->input_box.str)
		ft_strdel(&env->input_box.str);
	if (env->snprintf)
		ft_strdel(&env->snprintf);
	free_audio(env, 0);
	free_textures(env);
	free_buttons(env);
	TTF_Quit();
	SDL_Quit();
	if (env->editor.events_to_delete)
		ft_lstdelfront(&env->editor.events_to_delete);
	ft_printf("Exiting..\n");
}

void		free_all(t_env *env)
{
	int	i;

	ft_printf("Freeing data..\n");
	if (!env)
		return ;
	free_parser(env);
	free_resources_init(env);
	free_event(&env->eparser.event);
	if (env->editor.creating_event)
	{
		if (env->editor.event_panel.selected_event != -1)
			save_event(env);
		else
			create_event(env);
	}
	free_all_sdl_relative(env);
	free_fonts(env);
	free_map(env);
	i = 0;
	while (++i < 4)
	{
		if (env->skybox[i].texture_scale)
			ft_memdel((void**)&env->skybox[i].texture_scale);
	}
	free_all2(env);
}

int			crash(char *str, t_env *env)
{
	ft_dprintf(STDERR_FILENO, "%s", str);
	ft_printf("{red}[Critical error]{reset}\n");
	free_all(env);
	return (-1);
}
