/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_hud_buttons.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 09:41:16 by marvin            #+#    #+#             */
/*   Updated: 2020/01/06 09:41:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
void    change_mode(void *target)
{
        t_env *env;

        env = (t_env*)target;
        if (!valid_map(env))
        {
                env->editor.selected_vertex = -1;
                env->editor.selected_sector = -1;
                env->editor.selected_player = -1;
                env->editor.selected_object = -1;
                env->selected_enemy = -1;
                env->editor.in_game = 1;
                env->screen_sectors_size = ft_min(env->nb_sectors, env->w);
                free_camera(&env->player.camera, env);
                precompute_slopes(env);
        /*      if (init_camera_arrays(&env->player.camera, env))
                        return (ft_printf("Could not init camera arrays\n"));
                if (env->sector_list)
                        ft_memdel((void**)&env->sector_list);
                if (!(env->sector_list = (int*)ft_memalloc(sizeof(int) * env->nb_sectors)))
                        return (ft_printf("Could not allocate sector list\n", env));*/
                update_camera_position(&env->player.camera);
                update_player_z(env);
                ft_bzero(&env->inputs, sizeof(env->inputs));
                env->options.mouse = 1;
                SDL_SetRelativeMouseMode(1);
                SDL_GetRelativeMouseState(&env->sdl.mouse_x, &env->sdl.mouse_y);
                SDL_GetRelativeMouseState(&env->sdl.mouse_x, &env->sdl.mouse_y);
        }
}

void	save_button(void *target)
{
	t_env *env;

	env = (t_env*)target;
	if (env->inputs.s && env->inputs.ctrl && !valid_map(env))
        {
                SDL_SetRelativeMouseMode(0);
                SDL_GetRelativeMouseState(&env->sdl.mouse_x, &env->sdl.mouse_y);
                new_input_box(&env->input_box, new_point(env->h_w, env->h_h),
                STRING, &env->save_file);
                env->inputs.s = 0;
                env->inputs.ctrl = 0;
        }

}

void	editor_mode_button(t_env *env)
{
	env->editor.change_mode = new_image_button(PRESSED, &change_mode, env, env);
        env->editor.change_mode.img_up = &env->sprite_textures[env->wall_sprites[2].texture];
        env->editor.change_mode.img_pressed = &env->sprite_textures[env->wall_sprites[1].texture];
        env->editor.change_mode.img_down = &env->sprite_textures[env->wall_sprites[1].texture];
        env->editor.change_mode.size_up = new_point(64, 64);
        env->editor.change_mode.size_down = new_point(env->editor.current_texture_selection.img_down->surface->w,
        env->editor.change_mode.img_down->surface->h);
        env->editor.change_mode.size_hover = new_point(env->editor.current_texture_selection.img_hover->surface->w,
        env->editor.change_mode.img_hover->surface->h);
        env->editor.change_mode.size_pressed = new_point(env->editor.current_texture_selection.img_pressed->surface->w,
        env->editor.change_mode.img_pressed->surface->h);
        env->editor.change_mode.pos = new_point(0, 0);
}

void	editor_save_button(t_env *env)
{
	env->editor.save = new_image_button(WHEN_DOWN, &change_mode, env, env);
        env->editor.save.img_up = &env->sprite_textures[env->wall_sprites[2].texture];
        env->editor.save.img_pressed = &env->sprite_textures[env->wall_sprites[1].texture];
        env->editor.save.img_down = &env->sprite_textures[env->wall_sprites[1].texture];
        env->editor.save.size_up = new_point(64, 64);
        env->editor.save.size_down = new_point(env->editor.current_texture_selection.img_down->surface->w,
        env->editor.save.img_down->surface->h);
        env->editor.save.size_hover = new_point(env->editor.current_texture_selection.img_hover->surface->w,
        env->editor.save.img_hover->surface->h);
        env->editor.save.size_pressed = new_point(env->editor.current_texture_selection.img_pressed->surface->w,
        env->editor.save.img_pressed->surface->h);
        env->editor.save.pos = new_point(66, 0);
}
