/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 11:30:09 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/02 17:35:09 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		custom_error(const char *message)
{
	ft_dprintf(STDERR_FILENO, "{red}%s{reset}\n", message);
	return (-1);
}
