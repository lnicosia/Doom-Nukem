/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:13:14 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/04 14:55:53 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	char	*str;
	char	*printf_str;

	str = ft_strnew(20);
	printf_str = ft_strnew(20);
	ft_printf("\n");
	ft_snprintf(str, 9, "%d", 45);
	snprintf(printf_str, 9, "%d", 45);
	printf("my res = %d\nprintf res = %d\n",
	ft_printf("moi: str: '%s'\n", str),
	printf("lui: str: '%s'\n", printf_str));
	ft_printf("\n");
	ft_snprintf(str, 9, "%.5f", 45.4646464);
	snprintf(printf_str, 9, "%.5f", 45.4646464);
	printf("my res = %d\nprintf res = %d\n",
	ft_printf("moi: str: '%s'\n", str),
	printf("lui: str: '%s'\n", printf_str));
	ft_printf("\n");
	ft_snprintf(str, 9, "0x%X", 0xFFFF0000);
	snprintf(printf_str, 9, "0x%X", 0xFFFF0000);
	printf("my res = %d\nprintf res = %d\n",
	ft_printf("moi: str: '%s'\n", str),
	printf("lui: str: '%s'\n", printf_str));
	ft_printf("\n");
	ft_snprintf(str, 20, "%.5f", 45.123456789);
	snprintf(printf_str, 20, "%.5f", 45.123456789);
	printf("my res = %d\nprintf res = %d\n",
	ft_printf("moi: str: '%s'\n", str),
	printf("lui: str: '%s'\n", printf_str));
	ft_printf("\n");
	ft_snprintf(str, 20, "%.5f", 23.123456789);
	snprintf(printf_str, 20, "%.5f", 23.123456789);
	printf("my res = %d\nprintf res = %d\n",
	ft_printf("moi: str: '%s'\n", str),
	printf("lui: str: '%s'\n", printf_str));
	ft_printf("\n");
	return (0);
}
