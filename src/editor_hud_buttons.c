/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_hud_buttons.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:52:01 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/06 14:26:36 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		launch_game(void *target)
{
	t_env	*env;
	char	*str;
	char	*tmp;
	int		status;

	env = (void*)target;
	tmp = NULL;
	tmp = env->save_file;
	env->editor.game = 0;
	str = ft_strdup("./doom");
	env->save_file = ft_strdup("maps/tmp.map");
	save_map(env);
	env->c_pid = fork();
	if (env->c_pid == 0)
	{
		ft_printf("starting child\n");
		env->c_pid = execve(str, &env->save_file, NULL);
	}
	while (env->c_pid > 0)
	{
		ft_printf("waiting for the child to end\n");	
		if ( (env->pid = wait(&status)) < 0)
		{
      		perror("wait");
      		exit(1);
    	}
	}
	env->save_file = tmp;
	free(str);
	return (0);
}

int		change_mode(void *target)
{
    t_env *env;

    env = (t_env*)target;
	if (env->nb_sectors >= 1)
	{
		if (env->editor.in_game)
			going_in_2D_mode(env);
		else
			going_in_3D_mode(env);
	}
	return (0);
}

int		save_button(void *target)
{
	t_env *env;

	env = (t_env*)target;
	if (!valid_map(env))
    {
    	SDL_SetRelativeMouseMode(0);
    	SDL_GetRelativeMouseState(&env->sdl.mouse_x, &env->sdl.mouse_y);
        new_input_box(&env->input_box, new_point(env->h_w, env->h_h),
        STRING, &env->save_file);
        env->inputs.s = 0;
        env->inputs.ctrl = 0;
    }
	return (0);
}

int		editor_options_button(t_env *env)
{
	env->editor.options = new_image_button(ON_RELEASE, NULL, env, env);
	env->editor.options.str = "OPTIONS";
	env->editor.options.pos = new_point(40, 210);
	return (0);
}

int		editor_mode_button(t_env *env)
{
	env->editor.change_mode = new_image_button(ON_RELEASE, &change_mode, env, env);
	env->editor.change_mode.str = "2D/3D";
	env->editor.change_mode.pos = new_point(40, 60);
	return (0);
}

int		editor_save_button(t_env *env)
{
	env->editor.save = new_image_button(ON_RELEASE, &save_button, env, env);
	env->editor.save.str = "SAVE";
    env->editor.save.pos = new_point(40, 110);
	return (0);
}

int		editor_launch_game(t_env *env)
{
	env->editor.launch_game = new_image_button(ON_RELEASE, &launch_game, env, env);
	env->editor.launch_game.str = "START";
    env->editor.launch_game.pos = new_point(40, 160);
	return (0);
}

int	next_ambiance_music(void *target)
{
	t_env	*env;

	env = (t_env *)target;
	if (env->sound.current_music < NB_MUSICS - 1)
		env->sound.current_music++;
	env->editor.ambiance_music = env->sound.current_music;
	return (0);
}

int	previous_ambiance_music(void *target)
{
	t_env	*env;

	env = (t_env *)target;
	if (env->sound.current_music > 0)
		env->sound.current_music--;
	env->editor.ambiance_music = env->sound.current_music;
	return (0);
}

int	next_fighting_music(void *target)
{
	t_env	*env;

	env = (t_env *)target;
	if (env->sound.current_music < NB_MUSICS - 1)
		env->sound.current_music++;
	env->editor.fighting_music = env->sound.current_music;
	return (0);
}

int	previous_fighting_music(void *target)
{
	t_env	*env;

	env = (t_env *)target;
	if (env->sound.current_music > 0)
		env->sound.current_music--;
	env->editor.fighting_music = env->sound.current_music;
	return (0);
}