/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_hud_buttons.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:52:01 by sipatry           #+#    #+#             */
/*   Updated: 2020/03/03 16:32:31 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

/*
**
*/

int		launch_game(void *target)
{
	t_env	*env;
	char	*str;
	char	**tmp;
	char	*map_name;
	t_v3	tmp_pos;
	double	tmp_angle;

	env = (t_env*)target;
	if (env->editor.creating_event)
	{
		if (update_confirmation_box(&env->confirmation_box,
			"Please save your event before saving the map", ERROR, env))
			return (-1);
		return (0);
	}
	map_name = ft_strdup(env->save_file);
	str = ft_strdup("./doom-nukem");
	tmp = ft_strsplit("./doom-nukem maps/tmp.map", ' ');
	tmp_pos = env->player.starting_pos;
	env->player.starting_pos = env->player.pos;
	tmp_angle = env->player.init_data.camera.angle;
	env->player.init_data.camera.angle =
	env->player.camera.angle * CONVERT_DEGREES;
	env->save_file  = ft_strdup("maps/tmp.map");
	if (save_map(env))
		return (-1);
	ft_strdel(&env->save_file);
	env->save_file = map_name;
	env->pid = fork();
	if (env->pid == 0)
		execv(str, tmp);
	else
	{
		if ( (env->pid = wait(NULL)) < 0)
      		exit(1);
	}
	env->player.starting_pos = tmp_pos;
	env->player.init_data.camera.angle = tmp_angle;
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
	t_env	*env;
	int		ret;

	env = (t_env*)target;
	ret = valid_map(env);
	if (ret == -1)
		return (-1);
	else if (!ret)
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
	env->editor.launch_game =
	new_image_button(ON_RELEASE, &launch_game, env, env);
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
