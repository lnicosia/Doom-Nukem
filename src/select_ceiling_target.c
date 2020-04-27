#include "events_parser.h"

int		select_ceiling_target2(t_env *env, t_event_panel *panel,
t_target_panel *target_panel, int sector)
{
	if (target_panel->selected_button == 3)
	{
		panel->event.target = &env->sectors[sector].ceiling_map_align.x;
		panel->event.target_index = SECTOR_CEILING_ALIGN_X;
	}
	else if (target_panel->selected_button == 4)
	{
		panel->event.target = &env->sectors[sector].ceiling_map_align.y;
		panel->event.target_index = SECTOR_CEILING_ALIGN_Y;
	}
	else if (target_panel->selected_button == 5)
	{
		panel->event.target = &env->sectors[sector].ceiling_map_scale.x;
		panel->event.target_index = SECTOR_CEILING_SCALE_X;
	}
	else if (target_panel->selected_button == 6)
	{
		panel->event.target = &env->sectors[sector].ceiling_map_scale.y;
		panel->event.target_index = SECTOR_CEILING_SCALE_Y;
	}
	panel->event.update_param.sector = sector;
	panel->event.check_param.sector = sector;
	return (0);
}

int		select_ceiling_target(t_env *env, t_event_panel *panel,
t_target_panel *target_panel)
{
	int	sector;

	sector = env->editor.selected_sector == -1 ? env->selected_ceiling : env->
	editor.selected_sector;
	if (target_panel->selected_button == 1)
		panel->event.type = INT;
	if (target_panel->selected_button == 0)
	{
		panel->event.target = &env->sectors[sector].ceiling;
		panel->event.target_index = SECTOR_CEILING_HEIGHT;
	}
	else if (target_panel->selected_button == 1)
	{
		panel->event.target = &env->sectors[sector].ceiling_texture;
		panel->event.target_index = SECTOR_CEILING_TEXTURE;
	}
	else if (target_panel->selected_button == 2)
	{
		panel->event.target = &env->sectors[sector].ceiling_slope;
		panel->event.target_index = SECTOR_CEILING_SLOPE;
	}
	return (select_ceiling_target2(env, panel, target_panel, sector));
}
