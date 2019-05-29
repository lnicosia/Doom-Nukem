/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:30:20 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/29 16:40:43 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		init_textures(t_env *env)
{
	if (parse_bmp("images/wall0.bmp", 0, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/wall1.bmp", 1, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/wall2.bmp", 2, env))
		return (ft_printf("Invalid bmp file\n"));
	if (parse_bmp("images/wall3.bmp", 3, env))
		return (ft_printf("Invalid bmp file\n"));
	return (0);
}
