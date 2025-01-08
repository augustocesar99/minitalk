/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:21:10 by acesar-m          #+#    #+#             */
/*   Updated: 2025/01/08 09:42:33 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	convert_binary(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		//5) Envie o sinal como valor de bit (SIGUSR1 = 1, SIGUSR2 = 0).
		if ((i & (0x01 << bit)) != 0)
		{
			kill(pid, SIGUSR1);
		}
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

void	send_msg(int pid, char *msg)
{
	//4) Converta a mensagem em binário.
	while (*msg)
	{
		convert_binary(pid, *msg);
		msg++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	//1) Verifique se há apenas dois argumentos (PID e mensagem).
	if (argc != 3)
		exit(write(1, "Error: Wrong format!", 20));
	//2) Verifique se o PID é válido (apenas números).
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] < '0' || argv[1][i] > '9')
			exit(write(1, "ERROR: PID invalid!\n", 20));
		i++;
	}
	//3) Envie a mensagem.
	send_msg(ft_atoi(argv[1]), argv[2]);
	send_msg(ft_atoi(argv[1]), "\n");
	if (argv[1][i] == '\0')
		write(1, "Message sent!\n", 14);
	return (0);
}
