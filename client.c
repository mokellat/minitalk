/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 09:07:42 by mokellat          #+#    #+#             */
/*   Updated: 2021/06/18 17:30:43 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	*str_to_bin(char *str)
{
	int	i;
	int	lenght;
	int	val;
	int	*binary;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 8;
	lenght = ft_strlen(str);
	binary = (int *)malloc(8 * lenght);
	while(i < 8 * lenght)
		binary[i++] = 0;
	i = 0;
	while(i < lenght)
	{
		val = (int)str[i];
		j = k - 1;
		while(val != 0)
		{
			binary[j] = val % 2;
			j--;
			val /= 2;
		}
		k += 8;
		i++;
	}
	return (binary);
}

int	main(int argc, char **argv)
{
	int *binary;
	int	i;

	i = -1;
	if(argc != 3)
	{
		ft_putstr("Arguments are invalid");
		printf("1");
		exit(EXIT_FAILURE);
	}
	binary = str_to_bin(argv[2]);
	while(++i < (8 * (int)ft_strlen(argv[2])))
	{
		if (binary[i] == 1)
			kill(ft_atoi(argv[1]), SIGUSR1);
		else
			kill(ft_atoi(argv[1]), SIGUSR2);
		usleep(100);
	}
}
