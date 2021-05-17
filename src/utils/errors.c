/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 15:44:42 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/04/16 16:17:11 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	errors(int numerror)
{
	printf("Error\n");
	if (numerror == -1)
		printf("Incorrect parsing.\n");
	if (numerror == -2)
		printf("Forbidden character.\n");
	if (numerror == -3)
		printf("There's a value that shouldn't be negative.\n");
	if (numerror == -4)
		printf("A value has decimals (and it shouldn't).\n");
	if (numerror == -5)
		printf("A value is outside the valid range.\n");
	if (numerror == -6)
		printf("Only one resolution and amb lighting per map.\n");
	if (numerror == -7)
		printf("Screenshot failed.\n");
	if (numerror == -8)
		printf("Bad arguments.\n");
	exit(0);
}

void	check_str(char *str, int neg, int dot, int comma)
{
	while (*str)
	{
		if (neg == 0 && *str == '-')
			errors(-3);
		if (dot == 0 && *str == '.')
			errors(-4);
		if (comma == 0 && *str == ',')
			errors(-4);
		if (!(ft_isdigit(*str)) && *str != '-' && *str != '.' && *str != ',')
			errors(-2);
		str++;
	}
}

void	check_range(int value, int min, int max)
{
	if (value < min || value > max)
		errors(-5);
}
