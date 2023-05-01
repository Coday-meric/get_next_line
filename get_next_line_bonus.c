/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaisonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:08:17 by amaisonn          #+#    #+#             */
/*   Updated: 2023/02/22 17:48:49 by amaisonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_realloc(char *stack, int newsize)
{
	int		ts;
	char	*tmp;

	ts = ft_strlen_modif(stack);
	tmp = malloc((ts + 1) * sizeof(char));
	ft_strlcpy_modif(tmp, stack, ts + 1);
	free(stack);
	stack = malloc(newsize * sizeof(char));
	ft_strlcpy_modif(stack, tmp, ts + 1);
	free(tmp);
	return (stack);
}

static char	*ft_treatbuff(char *stack, int fd, int *r)
{
	int		newsize;
	char	*buff;

	while (ft_treatstack(stack, *r) == -1 && *r == BUFFER_SIZE)
	{
		buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
		*r = read(fd, buff, BUFFER_SIZE);
		if (*r == 0)
		{
			free(buff);
			break ;
		}
		buff[*r] = '\0';
		newsize = (ft_strlen_modif(buff) + ft_strlen_modif(stack) + 1);
		stack = ft_realloc(stack, newsize);
		ft_strlcat_modif(stack, buff, newsize);
		free(buff);
	}
	return (stack);
}

static char	*ft_check_stack(char *stack)
{
	if (!stack)
	{
		stack = malloc(1);
		stack[0] = '\0';
	}
	return (stack);
}

char	*get_next_line(int fd)
{
	int			r;
	int			t;
	char		*res;
	static char	*stack[32767];

	stack[fd] = ft_check_stack(stack[fd]);
	if (fd == -1 || read(fd, 0, 0) < 0)
	{
		free(stack[fd]);
		stack[fd] = NULL;
		return (NULL);
	}
	r = BUFFER_SIZE;
	stack[fd] = ft_treatbuff(stack[fd], fd, &r);
	if (*stack[fd] == '\0')
	{
		free(stack[fd]);
		stack[fd] = NULL;
		return (NULL);
	}
	t = ft_treatstack(stack[fd], r);
	res = malloc((t + 2) * sizeof(char));
	ft_strlcpy_modif(res, stack[fd], t + 2);
	stack[fd] = ft_modifstack(stack[fd], t + 1);
	return (res);
}
