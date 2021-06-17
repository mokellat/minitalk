/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 09:07:42 by mokellat          #+#    #+#             */
/*   Updated: 2021/06/17 20:03:17 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	str_to_bin(char *str)
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
	for(i = 0; i < lenght * 8; i++)
	{
		printf("%d", binary[i]);
		if((i + 1) % 8 == 0 && i != 0)
			printf(" ");
	}
}

int	main(int argc, char **argv)
{
	if(argc != 3)
	{
		ft_putstr("Arguments are invalid");
		printf("1");
		exit(EXIT_FAILURE);
	}
	str_to_bin(argv[2]);
}
