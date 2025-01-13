/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:21:44 by acesar-m          #+#    #+#             */
/*   Updated: 2025/01/13 14:26:29 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_message	g_message = {0, 0, NULL};

void	join_message(void)
{
	char	*temp;
	char	c;

	temp = NULL;
	c = (char)g_message.c;
	if (g_message.msg)
	{
		temp = ft_strjoin(g_message.msg, &c);
		free(g_message.msg);
	}
	else
	{
		temp = ft_strdup(&c);
	}
	if (!temp)
		exit(EXIT_FAILURE);
	g_message.msg = temp;
}

void	process_character(void)
{
	if (g_message.c == '\0')
	{
		if (g_message.msg)
			ft_printf("%s\n", g_message.msg);
		else
			ft_printf("\n");
		free(g_message.msg);
		g_message.msg = NULL;
	}
	else
		join_message();
	g_message.c = 0;
}

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static int	bit_count;

	(void)context;
	bit_count = 0;
	if (signal == SIGUSR1)
		g_message.c = (g_message.c << 1) | 1;
	else if (signal == SIGUSR2)
		g_message.c = (g_message.c << 1);
	bit_count++;
	if (bit_count == 8)
	{
		process_character();
		bit_count = 0;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		exit(EXIT_FAILURE);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Welcome the at acesar-m server.\n");
	ft_printf("Server PID: %d\n", getpid());
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
