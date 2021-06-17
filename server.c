/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 09:19:02 by mokellat          #+#    #+#             */
/*   Updated: 2021/06/17 21:49:53 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
char n;
int i;
void	func(int nb)
{
	if (nb == SIGUSR1)
		n += 1 << i;
	i--;
	if (i == -1)
	{
		// printf("\n%d\n", n);
		write(1, &n, 1);
		n = 0;
		i = 7;
	}
}

int	main(void)
{
	i =7;
	n = 0;
	signal(SIGUSR1, func);
	signal(SIGUSR2, func);
	ft_putstr("the PID is : ");
	ft_putnbr(getpid());
	while (1)
	{
		pause();
	}
}
