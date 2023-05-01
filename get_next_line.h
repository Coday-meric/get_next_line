/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaisonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:27:33 by amaisonn          #+#    #+#             */
/*   Updated: 2023/02/20 14:47:11 by amaisonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10 
# endif

int		ft_strlcpy_modif(char *dest, char *src, int size);
int		ft_treatstack(char *stack, int r);
int		ft_strlen_modif(char *str);
void	ft_copy(char *src, char *dest);
void	ft_strlcat_modif(char *dest, char *src, int size);
char	*ft_modifstack(char *stack, int i);
char	*ft_treatbuff(char *stack, int fd, int *r);
char	*ft_check_stack(char *stack);
char	*get_next_line(int fd);

#endif
