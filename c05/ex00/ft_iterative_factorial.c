/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucetin <mucetin@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:02:38 by mucetin           #+#    #+#             */
/*   Updated: 2023/02/23 19:02:34 by mucetin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	unsigned int	fac;

	fac = 1;
	while (nb > 0)
	{
		fac = nb * fac;
		nb--;
	}
	if (0 > nb)
		return (0);
	return (fac);
}
