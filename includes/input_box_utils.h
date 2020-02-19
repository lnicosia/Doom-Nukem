/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_box_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 10:27:01 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/19 09:28:53 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

#ifndef INPUT_BOX_UTILS_H
# define INPUT_BOX_UTILS_H

int		parse_integer_input(t_input_box *box, t_env *env);
int		parse_double_input(t_input_box *box, t_env *env);
int		parse_uint32_input(t_input_box *box, t_env *env);
int		parse_str_input(t_input_box *box, t_env *env);

#endif
