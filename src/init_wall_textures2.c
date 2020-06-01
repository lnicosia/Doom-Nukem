/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wall_textures2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:56:33 by sipatry           #+#    #+#             */
/*   Updated: 2020/05/15 20:03:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "parser.h"

int		init_wall_textures10(t_env *env)
{
	if (parse_bmp_wall_textures("./images/textures/wood3.bmp", 108, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/wood4.bmp", 109, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/wood5.bmp", 110, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/wood6.bmp", 111, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/wood7.bmp", 112, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/wood8.bmp", 113, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/wood9.bmp", 114, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/woodgarg.bmp", 115, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/woodmet1.bmp", 116, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/woodmet2.bmp", 117, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/woodmet3.bmp", 118, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/woodmet4.bmp", 119, env))
		return (custom_error("Invalid bmp file\n"));
	return (init_wall_textures11(env));
}

int		init_wall_textures9(t_env *env)
{
	if (parse_bmp_wall_textures("./images/textures/steplad1.bmp", 96, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/steptop.bmp", 97, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/stone.bmp", 98, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/sw1cmt.bmp", 99, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/sw2cmt.bmp", 100, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/tlite6_1.bmp", 101, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/tlite6_4.bmp", 102, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/tlite6_5.bmp", 103, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/tlite6_6.bmp", 104, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/wood1.bmp", 105, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/wood10.bmp", 106, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/wood12.bmp", 107, env))
		return (custom_error("Invalid bmp file\n"));
	return (init_wall_textures10(env));
}

int		init_wall_textures8(t_env *env)
{
	if (parse_bmp_wall_textures("./images/textures/rrock09.bmp", 84, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/slime01.bmp", 85, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/slime02.bmp", 86, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/slime03.bmp", 87, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/slime04.bmp", 88, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/slime14.bmp", 89, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/slime15.bmp", 90, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/slime16.bmp", 91, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/spcdoor1.bmp", 92, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/spcdoor2.bmp", 93, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/step4.bmp", 94, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/step6.bmp", 95, env))
		return (custom_error("Invalid bmp file\n"));
	return (init_wall_textures9(env));
}

int		init_wall_textures7(t_env *env)
{
	if (parse_bmp_wall_textures("./images/textures/liteblu1.bmp", 72, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/liteblu4.bmp", 73, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/pancase1.bmp", 74, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/pancase2.bmp", 75, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/panel1.bmp", 76, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/panel2.bmp", 77, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/panel3.bmp", 78, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/panel4.bmp", 79, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/panel5.bmp", 80, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/panel6.bmp", 81, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/panel9.bmp", 82, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/panred.bmp", 83, env))
		return (custom_error("Invalid bmp file\n"));
	return (init_wall_textures8(env));
}

int		init_wall_textures6(t_env *env)
{
	if (parse_bmp_wall_textures("./images/textures/exitston.bmp", 60, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/flat20.bmp", 61, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/flat23.bmp", 62, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/flat3.bmp", 63, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/flat4.bmp", 64, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/flat5_1.bmp", 65, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/floor3_3.bmp", 66, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/floor4_8.bmp", 67, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/floor5_1.bmp", 68, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/floor5_2.bmp", 69, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/lite3.bmp", 70, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp_wall_textures("./images/textures/lite5.bmp", 71, env))
		return (custom_error("Invalid bmp file\n"));
	return (init_wall_textures7(env));
}
