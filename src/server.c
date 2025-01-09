/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:21:44 by acesar-m          #+#    #+#             */
/*   Updated: 2025/01/09 18:24:32 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_message g_message = {0, 0, NULL};

void create_message(void)
{
    char *msg = NULL;
    char c = (char)g_message.c;

    if (g_message.msg)
    {
        msg = ft_strjoin(g_message.msg, &c);
        free(g_message.msg);
    }
    else
    {
        msg = ft_strdup(&c);
    }
    if (!msg)
        exit(EXIT_FAILURE);
    g_message.msg = msg;
}

void signal_handler(int signal, siginfo_t *info, void *context)
{
    (void)context;

    g_message.c = (g_message.c << 1) | (signal == SIGUSR1);
    g_message.i++;
    
    if (g_message.i == 8)
    {
        if (g_message.c == '\0')
        {
            ft_printf("%s\n", g_message.msg ? g_message.msg : "");
            free(g_message.msg);
            g_message.msg = NULL;
        }
        else
        {
            create_message();
        }
        g_message.c = 0;
        g_message.i = 0;
    }
    
    if (kill(info->si_pid, SIGUSR1) == -1)
        exit(EXIT_FAILURE);
}

int main(void)
{
    struct sigaction sa;

    ft_printf("Server PID: %d\n", getpid());

    sa.sa_sigaction = signal_handler;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    while (1)
        pause();
    return 0;
}
