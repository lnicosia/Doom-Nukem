#ifndef INIT_H
# define INIT_H
# include "env.h"

/*
** Init functions
*/

int						init_screen_size(t_env *env);
void					set_screen_size(t_env *env);
void					init_weapons(t_env *env);
void					init_gatling_weapon(t_env *env);
int						init_audio(t_env *env);
void					init_animations(t_env *env);
void					init_pointers(t_env *env);
int						init_sdl(t_env *env);
int						set_sdl(t_env *env);
int						init_ttf(t_env *env);
int						init_textures(t_env *env);
int						init_ui_textures(t_env *env);
int						init_skyboxes_textures(t_env *env);
int						init_skybox(t_env *env);
int						init_wallpapers_and_buttons(t_env *env);
int						init_enemy_sprites(t_env *env);
void					init_lost_soul_sprite(t_env *env);
void					init_lost_soul_rest(t_env *env);
void					init_lost_soul_pursuit(t_env *env);
void					init_lost_soul_pursuit_two(t_env *env);
void					init_lost_soul_death(t_env *env);
void					init_cyber_demon_pursuit(t_env *env);
void					init_cyber_demon_pursuit_two(t_env *env);
void					init_cyber_demon_pursuit_three(t_env *env);
void					init_cyber_demon_pursuit_four(t_env *env);
void					init_cyber_demon_firing_anim(t_env *env);
void					init_cyber_demon_firing_anim_two(t_env *env);
void					init_cyber_demon_firing_anim_three(t_env *env);
void					init_cyber_demon_death(t_env *env);
int						init_object_sprites(t_env *env);
void					init_minigun(t_env *env);
void					init_rocket(t_env *env);
void					init_health_pack(t_env *env);
void					init_ammo(t_env *env);
void					init_lamp(t_env *env);
void					init_barrel(t_env *env);
void					init_monitor(t_env *env);
void					init_candle(t_env *env);
void					init_camera_sprite(t_env *env);
void					init_armor_green(t_env *env);
void					init_explosion(t_env *env);
void					init_grid_sprite(t_env *env);
void					init_button_sprite(t_env *env);
void					init_bullet_hole(t_env *env);
void					init_object_lost_soul(t_env *env);
void					init_object_cyber_demon(t_env *env);
void					init_shotgun_sprite(t_env *env);
void					init_raygun_sprite(t_env *env);
void					init_doom_guy(t_env *env);
void					init_doom_guy_face(t_env *env);
void					init_hd_sprite(t_env *env);
int						init_wall_sprites(t_env *env);
int						init_screen_pos(t_env *env);
void					init_options(t_env *env);
void					init_keys(t_env *env);
void					init_inputs(t_env *env);
void					set_enemies_hp(t_env *env);
int						init_camera(t_camera *camera, t_env *env);
int						init_camera_arrays(t_camera *camera, t_env *env);
void					init_player(t_env *env);
void					init_enemies_data(t_env *env);
void					init_objects_data(t_env *env);
void					init_object_data5(int i, t_env *env);
void					init_object_data10(int i, t_env *env);
void					init_objects_main_sprites(t_env *env);
void					init_sector_list(t_env *env, int curr);
void					init_event_types(t_env *env);
void					init_event_links_types(t_env *env);
void					init_print_target_data(t_env *env);
void					init_print_target_data6(t_env *env);
void					init_print_condition_target_data(t_env *env);
void					init_print_condition_target_data6(t_env *env);
void					init_print_link_target_data(t_env *env);

#endif
