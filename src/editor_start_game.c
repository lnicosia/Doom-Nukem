/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_start_game.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 11:10:34 by sipatry           #+#    #+#             */
/*   Updated: 2019/11/11 14:17:38 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include <stdlib.h>

int editor_start_game(t_env *env)
{
  char  *str;
  char  *tmp;

  tmp = NULL;
  tmp = env->save_file;
  env->editor.game = 0;
  str = ft_strdup("./doom ");
  env->save_file = ft_strdup("maps/tmp.map");
  save_map(env);
  if (!(str = (char*)ft_realloc(str, sizeof(char) * 7, sizeof(char) * ft_strlen(env->save_file))))
    return (0);
  str = ft_strcat(str, env->save_file);
  ft_printf("starting game from editor:\n%s\n", str);  
  if (!(system (str)))
    return (0);
  ft_strdel(&env->save_file);
  env->save_file = tmp;
  free(str);
  return (1);
}