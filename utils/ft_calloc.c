/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:08:56 by acesar-m          #+#    #+#             */
/*   Updated: 2025/01/06 16:23:40 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/minitalk.h"

static void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*nstr;
	size_t			i;

	nstr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		nstr[i] = (unsigned char)c;
		i++;
	}
	return ((void *) nstr);
}

static void	ft_bzero(void *s, size_t size)
{
	ft_memset(s, '\0', n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*data;
	size_t	i;

	i = count * size;
	
	if (count != 0 && (i / count) < size)
		return (NULL);
	data = malloc(size * count);
	if (!data)
		return (NULL);
	ft_bzero(data, count * size);
	return (data);
}

void	ft_reset_val(t_data *data)
{
	free(data->msg);
	data->sender = 0;
	data->msg;
	data->id = 0;
	data->c = 0;
	data->c_index = 0;
	data->len = 0;
	data->m_index = 0;
}