/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 09:19:02 by mokellat          #+#    #+#             */
/*   Updated: 2021/10/05 16:32:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void	func(int nb)
{
	static char	n = 0;
	static int	i = 7;
	
	if (nb == SIGUSR1)
		n += ft_pow(2, i);
	i--;
	if (i == -1)
	{
		write(1, &n, 1);
		n = 0;
		i = 7;
	}
}

int	main(void)
{
	ft_putstr("the PID is : ");
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, func);
	signal(SIGUSR2, func);
	while (1)
	{
		pause();
	}
}
