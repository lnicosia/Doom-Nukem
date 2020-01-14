/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_events_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:03:18 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/14 16:59:35 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "wall_sprite_modifier.h"
#include "events_conditions.h"

void		init_events_map(t_env *env)
{
		/************/
		/* Lumieres */
		/************/
		env->nb_global_events = 5;
		env->global_events =
		(t_event*)ft_memalloc(sizeof(t_event) * env->nb_global_events);

		env->global_events[0] =
		new_fixed_event(INT, &env->sectors[2].intensity, 50, 0);
		env->global_events[0].delay = 1000;

		env->global_events[1] =
		new_fixed_event(UINT32, &env->sectors[2].light_color, 0xFFFF0000, 0);
		env->global_events[1].delay = 1000;
		env->global_events[1].nb_launch_conditions = 1;
		env->global_events[1].launch_conditions =
		(t_condition*)ft_memalloc(sizeof(t_condition)
		* env->global_events[1].nb_launch_conditions);
		env->global_events[1].launch_conditions[0].target =
		&env->global_events[4];
		env->global_events[1].launch_conditions[0].type = EVENT_ENDED_START;

		env->global_events[2] =
		new_fixed_event(UINT32, &env->sectors[2].light_color, 0xFF0000FF, 0);
		env->global_events[2].delay = 1000;
		env->global_events[2].nb_launch_conditions = 1;
		env->global_events[2].launch_conditions =
		(t_condition*)ft_memalloc(sizeof(t_condition)
		* env->global_events[2].nb_launch_conditions);
		env->global_events[2].launch_conditions[0].target =
		&env->global_events[1];
		env->global_events[2].launch_conditions[0].type = EVENT_ENDED;

		env->global_events[3] =
		new_fixed_event(UINT32, &env->sectors[2].light_color, 0xFF00FF00, 0);
		env->global_events[3].delay = 1000;
		env->global_events[3].nb_launch_conditions = 1;
		env->global_events[3].launch_conditions =
		(t_condition*)ft_memalloc(sizeof(t_condition)
		* env->global_events[3].nb_launch_conditions);
		env->global_events[3].launch_conditions[0].target =
		&env->global_events[2];
		env->global_events[3].launch_conditions[0].type = EVENT_ENDED;

		env->global_events[4] =
		new_fixed_event(UINT32, &env->sectors[2].light_color, 0xFFFFFF00, 0);
		env->global_events[4].delay = 1000;
		env->global_events[4].nb_launch_conditions = 1;
		env->global_events[4].launch_conditions =
		(t_condition*)ft_memalloc(sizeof(t_condition)
		* env->global_events[4].nb_launch_conditions);
		env->global_events[4].launch_conditions[0].target =
		&env->global_events[3];
		env->global_events[4].launch_conditions[0].type = EVENT_ENDED;


		/*************/
		/* Ascenseur */
		/*************/
		env->sectors[1].nb_walk_events = 2;
		env->sectors[1].walk_on_me_event =
		(t_event*)ft_memalloc(sizeof(t_event) * env->sectors[1].nb_walk_events);

		env->sectors[1].walk_on_me_event[0] = new_fixed_event(DOUBLE,
		&env->sectors[1].floor, 10, 500);
		env->sectors[1].walk_on_me_event[0].update_func = &update_sector_event;
		env->sectors[1].walk_on_me_event[0].update_param.num = 1;

		env->sectors[1].walk_on_me_event[1] = new_fixed_event(DOUBLE,
		&env->sectors[1].floor, 0, 500);
		env->sectors[1].walk_on_me_event[1].update_func = &update_sector_event;
		env->sectors[1].walk_on_me_event[1].update_param.num = 1;


		/*********/
		/* Dalle */
		/*********/

		// Montee
		env->sectors[4].nb_stand_events = 3;
		env->sectors[4].stand_on_me_event =
		(t_event*)ft_memalloc(sizeof(t_event) * env->sectors[4].nb_stand_events);
		env->sectors[4].stand_on_me_event[0] = new_incr_event(DOUBLE,
		&env->sectors[4].floor, -0.45, 500);
		env->sectors[4].stand_on_me_event[0].update_func = &update_sector_event;
		env->sectors[4].stand_on_me_event[0].update_param.num = 4;
		/*env->sectors[4].stand_on_me_event[0].check_func = &check_equ_value_event;
		env->sectors[4].stand_on_me_event[0].check_param.target = &env->player.sector;
		env->sectors[4].stand_on_me_event[0].check_param.target_type = INT;
		env->sectors[4].stand_on_me_event[0].check_param.equ_value = 4;*/
		env->sectors[4].stand_on_me_event[0].nb_exec_conditions = 2;
		env->sectors[4].stand_on_me_event[0].exec_conditions =
		(t_condition*)ft_memalloc(sizeof(t_condition)
		* env->sectors[4].stand_on_me_event[0].nb_exec_conditions);
		env->sectors[4].stand_on_me_event[0].exec_conditions[0].target =
		&env->sectors[4].floor;
		env->sectors[4].stand_on_me_event[0].exec_conditions[0].type =
		GREATER;
		env->sectors[4].stand_on_me_event[0].exec_conditions[0].target_type =
		DOUBLE;
		env->sectors[4].stand_on_me_event[0].exec_conditions[0].value = 10;
		env->sectors[4].stand_on_me_event[0].exec_conditions[1].target =
		&env->player.sector;
		env->sectors[4].stand_on_me_event[0].exec_conditions[1].type =
		EQUALS;
		env->sectors[4].stand_on_me_event[0].exec_conditions[1].target_type =
		INT;
		env->sectors[4].stand_on_me_event[0].exec_conditions[1].value = 4;


		env->sectors[4].stand_on_me_event[1] = new_incr_event(DOUBLE,
		&env->sectors[7].floor, -10.0, 1000);
		/*env->sectors[4].stand_on_me_event[1].check_func = &check_equ_value_event;
		env->sectors[4].stand_on_me_event[1].check_param.target = &env->player.sector;
		env->sectors[4].stand_on_me_event[1].check_param.equ_value = 4;*/
		env->sectors[4].stand_on_me_event[1].nb_exec_conditions = 2;
		env->sectors[4].stand_on_me_event[1].exec_conditions =
		(t_condition*)ft_memalloc(sizeof(t_condition)
		* env->sectors[4].stand_on_me_event[1].nb_exec_conditions);
		env->sectors[4].stand_on_me_event[1].exec_conditions[0].target =
		&env->sectors[7].floor;
		env->sectors[4].stand_on_me_event[1].exec_conditions[0].type =
		GREATER;
		env->sectors[4].stand_on_me_event[1].exec_conditions[0].target_type =
		DOUBLE;
		env->sectors[4].stand_on_me_event[1].exec_conditions[0].value = 10;
		env->sectors[4].stand_on_me_event[1].update_func = &update_sector_event;
		env->sectors[4].stand_on_me_event[1].update_param.num = 7;
		env->sectors[4].stand_on_me_event[1].exec_conditions[1].target =
		&env->player.sector;
		env->sectors[4].stand_on_me_event[1].exec_conditions[1].type =
		EQUALS;
		env->sectors[4].stand_on_me_event[1].exec_conditions[1].target_type =
		INT;
		env->sectors[4].stand_on_me_event[1].exec_conditions[1].value = 4;

		env->sectors[4].stand_on_me_event[2] = new_incr_event(DOUBLE,
		&env->sectors[6].align[5].y, 10, 1000);
		env->sectors[4].stand_on_me_event[2].nb_exec_conditions = 2;
		env->sectors[4].stand_on_me_event[2].exec_conditions =
		env->sectors[4].stand_on_me_event[1].exec_conditions;
		/*env->sectors[4].stand_on_me_event[2].nb_exec_conditions = 2;
		env->sectors[4].stand_on_me_event[2].exec_conditions =
		env->sectors[4].stand_on_me_event[2].exec_conditions =
		(t_condition*)ft_memalloc(sizeof(t_condition)
		* env->sectors[4].stand_on_me_event[2].nb_exec_conditions);
		env->sectors[4].stand_on_me_event[2].exec_conditions[0].target =
		&env->sectors[6].align[5].y;
		env->sectors[4].stand_on_me_event[2].exec_conditions[0].type =
		LESS;
		env->sectors[4].stand_on_me_event[2].exec_conditions[0].target_type =
		DOUBLE;
		env->sectors[4].stand_on_me_event[2].exec_conditions[0].value = 10;
		env->sectors[4].stand_on_me_event[2].exec_conditions[1] =
		env->sectors[4].stand_on_me_event[1].exec_conditions[1];*/

		// Descente
		env->sectors[4].nb_walk_out_events = 3;
		env->sectors[4].walk_out_event =
		(t_event*)ft_memalloc(sizeof(t_event) * env->sectors[4].nb_walk_out_events);
		env->sectors[4].walk_out_event[0] = new_incr_event(DOUBLE,
		&env->sectors[4].floor, 0.45, 500);
		env->sectors[4].walk_out_event[0].update_func = &update_sector_event;
		env->sectors[4].walk_out_event[0].update_param.num = 4;
		env->sectors[4].walk_out_event[0].nb_exec_conditions = 2;
		env->sectors[4].walk_out_event[0].exec_conditions =
		(t_condition*)ft_memalloc(sizeof(t_condition)
		* env->sectors[4].walk_out_event[0].nb_exec_conditions);
		env->sectors[4].walk_out_event[0].exec_conditions[0].target =
		&env->sectors[4].floor;
		env->sectors[4].walk_out_event[0].exec_conditions[0].type =
		LESS;
		env->sectors[4].walk_out_event[0].exec_conditions[0].target_type =
		DOUBLE;
		env->sectors[4].walk_out_event[0].exec_conditions[0].value = 10.45;
		env->sectors[4].walk_out_event[0].exec_conditions[1].target =
		&env->player.sector;
		env->sectors[4].walk_out_event[0].exec_conditions[1].type =
		DIFFERENT;
		env->sectors[4].walk_out_event[0].exec_conditions[1].target_type =
		INT;
		env->sectors[4].walk_out_event[0].exec_conditions[1].value = 4;
		
		env->sectors[4].walk_out_event[1] = new_incr_event(DOUBLE,
		&env->sectors[7].floor, 10, 1000);
		env->sectors[4].walk_out_event[1].update_func = &update_sector_event;
		env->sectors[4].walk_out_event[1].update_param.num = 7;
		env->sectors[4].walk_out_event[1].nb_exec_conditions = 2;
		env->sectors[4].walk_out_event[1].exec_conditions =
		(t_condition*)ft_memalloc(sizeof(t_condition)
		* env->sectors[4].walk_out_event[1].nb_exec_conditions);
		env->sectors[4].walk_out_event[1].exec_conditions[0].target =
		&env->sectors[7].floor;
		env->sectors[4].walk_out_event[1].exec_conditions[0].type =
		LESS;
		env->sectors[4].walk_out_event[1].exec_conditions[0].target_type =
		DOUBLE;
		env->sectors[4].walk_out_event[1].exec_conditions[0].value = 20;
		env->sectors[4].walk_out_event[1].exec_conditions[1].target =
		&env->player.sector;
		env->sectors[4].walk_out_event[1].exec_conditions[1].type =
		DIFFERENT;
		env->sectors[4].walk_out_event[1].exec_conditions[1].target_type =
		INT;
		env->sectors[4].walk_out_event[1].exec_conditions[1].value = 4;

		env->sectors[4].walk_out_event[2] = new_incr_event(DOUBLE,
		&env->sectors[6].align[5].y, -10, 1000);
		env->sectors[4].walk_out_event[2].nb_exec_conditions = 2;
		env->sectors[4].walk_out_event[2].exec_conditions =
		env->sectors[4].walk_out_event[1].exec_conditions;
		/*env->sectors[4].walk_out_event[2].nb_exec_conditions = 2;
		env->sectors[4].walk_out_event[2].exec_conditions =
		(t_condition*)ft_memalloc(sizeof(t_condition)
		* env->sectors[4].walk_out_event[2].nb_exec_conditions);
		env->sectors[4].walk_out_event[2].exec_conditions[0].target =
		&env->sectors[6].align[5].y;
		env->sectors[4].walk_out_event[2].exec_conditions[0].type =
		LESS;
		env->sectors[4].walk_out_event[2].exec_conditions[0].target_type =
		DOUBLE;
		env->sectors[4].walk_out_event[2].exec_conditions[0].value = 10;
		env->sectors[4].walk_out_event[2].exec_conditions[1] =
		env->sectors[4].walk_out_event[1].exec_conditions[1];*/
		
		/*****************/
		/* Interrupteurs */
		/*****************/
		env->sectors[10].wall_sprites[1].nb_press_events[0] = 5;
		env->sectors[10].wall_sprites[1].press_events[0] =
		(t_event*)ft_memalloc(sizeof(t_event)
		* env->sectors[10].wall_sprites[1].nb_press_events[0]);
		// Anim bouton
		env->sectors[10].wall_sprites[1].press_events[0][0] =
		new_fixed_event(INT, &env->sectors[10].wall_sprites[1].sprite[0],
		1, 0);
		env->sectors[10].wall_sprites[1].press_events[0][1] =
		new_fixed_event(INT, &env->sectors[10].wall_sprites[1].sprite[0],
		2, 0);

		// Partie ouverture de grille
		env->sectors[10].wall_sprites[1].press_events[0][2] =
		new_fixed_event(DOUBLE, &env->sectors[15].wall_sprites[1].pos[0].x,
		-10, 5000);
		env->sectors[10].wall_sprites[1].press_events[0][3] =
		new_fixed_event(DOUBLE, &env->sectors[18].wall_sprites[0].pos[0].x,
		10, 5000);
		env->sectors[10].wall_sprites[1].press_events[0][4] =
		new_fixed_event(INT, &env->sectors[15].portals[1],
		1, 0);

		//Partie conditions
		env->sectors[10].wall_sprites[1].press_events[0][2].nb_launch_conditions = 2;
		env->sectors[10].wall_sprites[1].press_events[0][2].launch_conditions =
		(t_condition*)ft_memalloc(sizeof(t_condition)
		* env->sectors[10].wall_sprites[1].press_events[0][2].nb_launch_conditions);
		env->sectors[10].wall_sprites[1].press_events[0][2].launch_conditions[0].type = EQUALS;
		env->sectors[10].wall_sprites[1].press_events[0][2].launch_conditions[0].target_type = INT;
		env->sectors[10].wall_sprites[1].press_events[0][2].launch_conditions[0].target = &env->sectors[12].wall_sprites[1].sprite[0];
		env->sectors[10].wall_sprites[1].press_events[0][2].launch_conditions[0].value = 2;

		env->sectors[10].wall_sprites[1].press_events[0][2].launch_conditions[1].type = EQUALS;
		env->sectors[10].wall_sprites[1].press_events[0][2].launch_conditions[1].target_type = INT;
		env->sectors[10].wall_sprites[1].press_events[0][2].launch_conditions[1].target = &env->sectors[17].wall_sprites[1].sprite[0];
		env->sectors[10].wall_sprites[1].press_events[0][2].launch_conditions[1].value = 2;

		env->sectors[10].wall_sprites[1].press_events[0][3].nb_launch_conditions = 2;
		env->sectors[10].wall_sprites[1].press_events[0][4].nb_launch_conditions = 2;
		env->sectors[10].wall_sprites[1].press_events[0][3].launch_conditions =
		env->sectors[10].wall_sprites[1].press_events[0][2].launch_conditions;
		env->sectors[10].wall_sprites[1].press_events[0][4].launch_conditions =
		env->sectors[10].wall_sprites[1].press_events[0][2].launch_conditions;




		env->sectors[12].wall_sprites[1].nb_press_events[0] = 5;
		env->sectors[12].wall_sprites[1].press_events[0] =
		(t_event*)ft_memalloc(sizeof(t_event)
		* env->sectors[12].wall_sprites[1].nb_press_events[0]);
		// Anim bouton
		env->sectors[12].wall_sprites[1].press_events[0][0] =
		new_fixed_event(INT, &env->sectors[12].wall_sprites[1].sprite[0],
		1, 0);
		env->sectors[12].wall_sprites[1].press_events[0][1] =
		new_fixed_event(INT, &env->sectors[12].wall_sprites[1].sprite[0],
		2, 0);

		// Partie ouverture de grille
		env->sectors[12].wall_sprites[1].press_events[0][2] =
		new_fixed_event(DOUBLE, &env->sectors[15].wall_sprites[1].pos[0].x,
		-10, 5000);
		env->sectors[12].wall_sprites[1].press_events[0][3] =
		new_fixed_event(DOUBLE, &env->sectors[18].wall_sprites[0].pos[0].x,
		10, 5000);
		env->sectors[12].wall_sprites[1].press_events[0][4] =
		new_fixed_event(INT, &env->sectors[15].portals[1],
		1, 0);

		//Partie conditions
		env->sectors[12].wall_sprites[1].press_events[0][2].nb_launch_conditions = 2;
		env->sectors[12].wall_sprites[1].press_events[0][2].launch_conditions =
		(t_condition*)ft_memalloc(sizeof(t_condition)
		* env->sectors[12].wall_sprites[1].press_events[0][2].nb_launch_conditions);
		env->sectors[12].wall_sprites[1].press_events[0][2].launch_conditions[0].type = EQUALS;
		env->sectors[12].wall_sprites[1].press_events[0][2].launch_conditions[0].target_type = INT;
		env->sectors[12].wall_sprites[1].press_events[0][2].launch_conditions[0].target = &env->sectors[10].wall_sprites[1].sprite[0];
		env->sectors[12].wall_sprites[1].press_events[0][2].launch_conditions[0].value = 2;

		env->sectors[12].wall_sprites[1].press_events[0][2].launch_conditions[1].type = EQUALS;
		env->sectors[12].wall_sprites[1].press_events[0][2].launch_conditions[1].target_type = INT;
		env->sectors[12].wall_sprites[1].press_events[0][2].launch_conditions[1].target = &env->sectors[17].wall_sprites[1].sprite[0];
		env->sectors[12].wall_sprites[1].press_events[0][2].launch_conditions[1].value = 2;

		env->sectors[12].wall_sprites[1].press_events[0][3].nb_launch_conditions = 2;
		env->sectors[12].wall_sprites[1].press_events[0][4].nb_launch_conditions = 2;
		env->sectors[12].wall_sprites[1].press_events[0][3].launch_conditions =
		env->sectors[12].wall_sprites[1].press_events[0][2].launch_conditions;
		env->sectors[12].wall_sprites[1].press_events[0][4].launch_conditions =
		env->sectors[12].wall_sprites[1].press_events[0][2].launch_conditions;




		env->sectors[17].wall_sprites[1].nb_press_events[0] = 5;
		env->sectors[17].wall_sprites[1].press_events[0] =
		(t_event*)ft_memalloc(sizeof(t_event)
		* env->sectors[17].wall_sprites[1].nb_press_events[0]);
		// Anim bouton
		env->sectors[17].wall_sprites[1].press_events[0][0] =
		new_fixed_event(INT, &env->sectors[17].wall_sprites[1].sprite[0],
		1, 0);
		env->sectors[17].wall_sprites[1].press_events[0][1] =
		new_fixed_event(INT, &env->sectors[17].wall_sprites[1].sprite[0],
		2, 0);

		// Partie ouverture de grille
		env->sectors[17].wall_sprites[1].press_events[0][2] =
		new_fixed_event(DOUBLE, &env->sectors[15].wall_sprites[1].pos[0].x,
		-10, 5000);
		env->sectors[17].wall_sprites[1].press_events[0][3] =
		new_fixed_event(DOUBLE, &env->sectors[18].wall_sprites[0].pos[0].x,
		10, 5000);
		env->sectors[17].wall_sprites[1].press_events[0][4] =
		new_fixed_event(INT, &env->sectors[15].portals[1],
		1, 0);

		//Partie conditions
		env->sectors[17].wall_sprites[1].press_events[0][2].nb_launch_conditions = 2;
		env->sectors[17].wall_sprites[1].press_events[0][2].launch_conditions =
		(t_condition*)ft_memalloc(sizeof(t_condition)
		* env->sectors[17].wall_sprites[1].press_events[0][2].nb_launch_conditions);
		env->sectors[17].wall_sprites[1].press_events[0][2].launch_conditions[0].type = EQUALS;
		env->sectors[17].wall_sprites[1].press_events[0][2].launch_conditions[0].target_type = INT;
		env->sectors[17].wall_sprites[1].press_events[0][2].launch_conditions[0].target = &env->sectors[10].wall_sprites[1].sprite[0];
		env->sectors[17].wall_sprites[1].press_events[0][2].launch_conditions[0].value = 2;

		env->sectors[17].wall_sprites[1].press_events[0][2].launch_conditions[1].type = EQUALS;
		env->sectors[17].wall_sprites[1].press_events[0][2].launch_conditions[1].target_type = INT;
		env->sectors[17].wall_sprites[1].press_events[0][2].launch_conditions[1].target = &env->sectors[12].wall_sprites[1].sprite[0];
		env->sectors[17].wall_sprites[1].press_events[0][2].launch_conditions[1].value = 2;

		env->sectors[17].wall_sprites[1].press_events[0][3].nb_launch_conditions = 2;
		env->sectors[17].wall_sprites[1].press_events[0][4].nb_launch_conditions = 2;
		env->sectors[17].wall_sprites[1].press_events[0][3].launch_conditions =
		env->sectors[17].wall_sprites[1].press_events[0][2].launch_conditions;
		env->sectors[17].wall_sprites[1].press_events[0][4].launch_conditions =
		env->sectors[17].wall_sprites[1].press_events[0][2].launch_conditions;
}
