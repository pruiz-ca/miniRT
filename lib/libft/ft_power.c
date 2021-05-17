/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 02:12:22 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/04/15 21:48:48 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_power(double num, double pow)
{
	double		result;

	result = 1;
	while (pow-- > 0)
		result *= num;
	return (result);
}
