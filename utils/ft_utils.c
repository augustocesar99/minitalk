/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:24:04 by acesar-m          #+#    #+#             */
/*   Updated: 2025/01/06 16:41:33 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/minitalk.h"

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int ft_atoi(char *str)
{
	int i;
	int rest;
	int sing;

	i = 0;
	rest = 0;
	sing = 1;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if(str[i] == '-')
			sing = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		rest = rest * 10 + str[i++] - '0';
	return (rest * sing);
}

void	ft_exit(int fd, int status, char *msg)