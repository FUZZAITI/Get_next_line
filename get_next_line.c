/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepinhei <pepinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 11:33:25 by pepinhei          #+#    #+#             */
/*   Updated: 2025/09/08 16:40:38 by pepinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> // para o strcpy


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 20
#endif

char	*test(int fd);
char	*ft_strncpy(char *dest, const char *src, size_t n);

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	line = malloc(BUFFER_SIZE + 1);
	line = test(fd);
	printf("%s", line);
	free(line);
	close(fd);
	return (0);
}

char	*test(int fd)
{
	char	*buf;
	int		n;
	int		i;
	char	*result;

	i = 0;
	n = 0;
	buf = malloc(BUFFER_SIZE + 1);
	result = malloc(BUFFER_SIZE + 1);
	n = read(fd, buf, BUFFER_SIZE);
	buf[n] = '\0';
	while (buf[i] != '\0' && buf[i] != '\n')
	{
		i++;
	}
//	strncpy(result, buf, i);
//	free(buf);
	return (buf);
}
