/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:21:44 by acesar-m          #+#    #+#             */
/*   Updated: 2025/01/08 11:18:08 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_str;

void	ft_listening_data(int sig)
{
	static int	bit;
	static int	i;
	char		*c1;
	//4) Converte o sinal recebido em bytes -> caractere -> string.
	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		c1 = (char *)malloc(sizeof(char) * 2);
		if (!c1)
			return ;
		c1[0] = (char)i;
		c1[1] = '\0';
		g_str = ft_strjoin_mod(g_str, c1);
		if (c1[0] == '\n')
		{
			ft_putstr_fd(g_str, 1);
			free(g_str);
			g_str = NULL;
		}
		bit = 0;
		i = 0;
		free(c1);
	}
}
	
int	main(void)
{
	//Passo 1) Imprimi o PID do Servidor.
	ft_putstr_fd("Server PID: [", 1);
	ft_putnbr(getpid());
	ft_putstr_fd("]\n", 1);
	//3) Define como cada sinal (SIGUSR1 e SIGUSR2) será tratado.
	signal(SIGUSR1, ft_listening_data);
	signal(SIGUSR2, ft_listening_data);
	//2) Mantem o programa em execução, aguardando sinais para escutar.
	while (1)
	{
		pause();
	}
}
