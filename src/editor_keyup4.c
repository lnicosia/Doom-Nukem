#include "env.h"

int		is_mouse_on_any_selection_tab(t_env *env)
{
	if (is_mouse_on_texture_selection_tab(env)
		|| is_mouse_on_object_selection_tab(env)
		|| is_mouse_on_enemy_selection_tab(env)
		|| is_mouse_on_wall_sprite_selection_tab(env))
		return (1);
	return (0);
}

int		editor_left_click_up(t_env *env)
{
	if (!is_mouse_on_texture_selection_tab(env))
		env->editor.draw_texture_tab = 0;
	if (!is_mouse_on_object_selection_tab(env))
		env->editor.draw_object_tab = 0;
	if (!is_mouse_on_enemy_selection_tab(env))
		env->editor.draw_enemy_tab = 0;
	if (!is_mouse_on_wall_sprite_selection_tab(env))
		env->editor.draw_sprite_tab = 0;
	if (env->editor.create_enemy && env->sdl.mx > 400)
	{
		if (add_enemy(env))
			return (-1);
	}
	if (env->editor.create_object && env->sdl.mx > 400)
	{
		if (add_object(env))
			return (-1);
	}
	return (0);
}

int		click_on_sector(t_env *env)
{
	if (env->sdl.mx > 400 && env->sdl.event.button.button == SDL_BUTTON_LEFT
			&& !env->confirmation_box.state
			&& env->editor.event_panel_dragged == -1
			&& env->editor.start_vertex == -1
			&& env->editor.dragged_player == -1
			&& env->editor.dragged_start_player == -1
			&& (!is_mouse_on_event_panel(env) || (!env->editor.creating_event
			&& !env->editor.creating_condition))
			&& env->editor.dragged_object == -1
			&& env->editor.dragged_vertex == -1
			&& env->editor.dragged_enemy == -1
			&& !is_mouse_on_any_selection_tab(env)
			&& !is_mouse_on_weapon_picker(env))
	  	return (1);
	return (0);
}

int		select_sector(t_env *env)
{
  	if (click_on_sector(env))
	{
		reset_selection(env);
		env->editor.selected_sector = get_sector_no_z(env,
			new_v3((env->sdl.mx - env->editor.center.x) / env->editor.scale,
			(env->sdl.my - env->editor.center.y) / env->editor.scale,
			0));
		env->editor.selected_vertex = -1;
		env->editor.selected_player = -1;
		env->editor.selected_start_player = -1;
		env->editor.selected_events = 0;
		env->editor.selected_event = 0;
		env->editor.selected_launch_condition = 0;
		env->editor.selected_exec_condition = 0;
		if (env->editor.selected_sector == -1)
		{
			env->selected_floor = -1;
			env->selected_ceiling = -1;
		}
		env->selected_enemy = -1;
		tabs_gestion(env);
		check_event_creation(env);
	}
	return (0);
}