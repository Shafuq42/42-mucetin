/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucetin <mucetin@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:23:05 by mucetin           #+#    #+#             */
/*   Updated: 2023/02/24 11:33:01 by mucetin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int ac, char *str[])
{
	int	i;

	i = 0;
	while (str[0][i] && ac)
	{
		ft_putchar(str[0][i]);
		i++;
	}
	ft_putchar('\n');
	return (0);
}
