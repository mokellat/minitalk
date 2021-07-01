/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 09:07:42 by mokellat          #+#    #+#             */
/*   Updated: 2021/07/01 15:53:08 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned char	*str_to_bin(char *str)
{
	int	i;
	int	lenght;
	unsigned char	val;
	unsigned char	*binary;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 8;
	lenght = ft_strlen(str);
	binary = (unsigned char *)malloc(8 * lenght);
	while(i < 8 * lenght)
		binary[i++] = 0;
	i = 0;
	while(i < lenght)
	{
		val = str[i];
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
	unsigned char *binary;
	int	i;

	i = -1;
	if(argc != 3 || ft_atoi(argv[1]) < 0)
	{
		ft_putstr("Arguments are invalid");
		exit(EXIT_FAILURE);
	}
	binary = str_to_bin(argv[2]);
	while(++i < (8 * (int)ft_strlen(argv[2])))
	{
		if (binary[i] == 1)
		{
			if(kill(ft_atoi(argv[1]), SIGUSR1) == -1)
			{
				ft_putstr("The message faced a problem");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if(kill(ft_atoi(argv[1]), SIGUSR2) == -1)
			{
				ft_putstr("The message faced a problem");
				exit(EXIT_FAILURE);
			}
		}
		usleep(100);
	}
	ft_putstr("Message sent successfully");
}
