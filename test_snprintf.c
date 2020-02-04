/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:13:14 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/04 12:02:14 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	char	*str;
	char	*printf_str;

	str = ft_strnew(2);
	printf_str = ft_strnew(2);
	ft_snprintf(str, 9, "%f", 45.78465);
	snprintf(printf_str, 9, "%f", 45.78465);
	printf("my res = %d\nprintf res = %d\n",
	ft_printf("moi: str: '%s'\n", str),
	printf("lui: str: '%s'\n", printf_str));
	return (0);
}
