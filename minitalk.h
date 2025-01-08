/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:21:30 by acesar-m          #+#    #+#             */
/*   Updated: 2025/01/07 17:21:35 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>

size_t	ft_strlen(const char *s);

char	*ft_strjoin_mod(char *s1, char *s2);

void	ft_putstr_fd(char *s, int fd);

void	ft_putnbr(unsigned int pid);

int		ft_atoi(const char *nptr);

#endif
