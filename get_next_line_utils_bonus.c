/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaisonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:32:17 by amaisonn          #+#    #+#             */
/*   Updated: 2023/02/21 19:28:28 by amaisonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen_modif(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_strlcat_modif(char *dest, char *src, int size)
{
	int	td;

	td = ft_strlen_modif(src) - size + 1;
	if (td < 0)
		td = td * -1;
	while (td < size - 1)
	{
		dest[td] = *src;
		td++;
		src++;
	}
	dest[td] = '\0';
}

int	ft_strlcpy_modif(char *dest, char *src, int size)
{
	int	i;

	i = 0;
	if (size != 0)
	{
		while (i < (size - 1) && src[i] != '\0')
		{	
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = '\0';
	return (ft_strlen_modif(src));
}

int	ft_treatstack(char *stack, int r)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		if (stack[i] == '\n')
			return (i);
		i++;
	}
	if (r < BUFFER_SIZE)
		return (ft_strlen_modif(stack) - 1);
	return (-1);
}

char	*ft_modifstack(char *stack, int i)
{
	int		it;
	char	*tmp;

	it = 0;
	tmp = malloc((ft_strlen_modif(stack) - i + 1) * sizeof(char));
	while (stack[i])
	{
		tmp[it] = stack[i];
		i++;
		it++;
	}
	tmp[it] = '\0';
	free(stack);
	stack = malloc((ft_strlen_modif(tmp) + 1) * sizeof(char));
	it = 0;
	while (tmp[it])
	{
		stack[it] = tmp[it];
		it++;
	}
	stack[it] = '\0';
	free(tmp);
	return (stack);
}
