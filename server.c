/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 09:19:02 by mokellat          #+#    #+#             */
/*   Updated: 2021/06/16 11:48:50 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	func(int nb)
{
	printf("%d \n", nb);
}

int	main(void)
{
	signal(SIGUSR1, func);
	signal(SIGUSR2, func);
	ft_putstr("the PID is : ");
	ft_putnbr(getpid());
	while (1)
	{
		pause();
	}
}
