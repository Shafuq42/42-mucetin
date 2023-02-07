/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucetin <mucetin@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:34:22 by mucetin           #+#    #+#             */
/*   Updated: 2023/02/05 14:35:49 by mucetin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	x;
	int	y;

	x = 0;
	while (x <= 98)
	{
		y = x + 1;
		while (y <= 99)
		{
			ft_putchar (x / 10 + '0');
			ft_putchar (x % 10 + '0');
			ft_putchar (' ');
			ft_putchar (y / 10 + '0');
			ft_putchar (y % 10 + '0');
			if (x != 98)
				write (1, ", ", 2);
			y++;
		}
		x++;
	}
}
