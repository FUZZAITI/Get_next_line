#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> // para o strcpy


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 50
#endif

void test(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);

int main(void)
{
	int		fd;
	char	*line;
    int     n;
    char   *aaa;

    aaa = '\0';
	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	line = malloc(BUFFER_SIZE + 1);
	n = read(fd, line, BUFFER_SIZE);
	line[n] = '\0';
    aaa = ft_strjoin(aaa, line);
//	printf("%s", line);
    n = read(fd, line, BUFFER_SIZE);
	line[n] = '\0';
    aaa = ft_strjoin(aaa, line);
//	printf("%s", line);
	n = read(fd, line, BUFFER_SIZE);
	line[n] = '\0';
    aaa = ft_strjoin(aaa, line);
//	printf("%s", line);
	n = read(fd, line, BUFFER_SIZE);
	line[n] = '\0';
    aaa = ft_strjoin(aaa, line);
//	printf("%s", line);
	printf("\n");
    printf("%s", aaa);

	close(fd);
	return (0);
}

void test(int fd)
{
    char  *line2;
    int     n;

    line2 = malloc(BUFFER_SIZE + 1);
    n = read(fd, line2, BUFFER_SIZE);
    line2[n] = '\0';
	printf("%s", line2);
    n = read(fd, line2, BUFFER_SIZE);
	line2[n] = '\0';
	printf("%s", line2);

}


size_t	ft_strlen(const char *s)
{
	size_t i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1 = ft_strlen(s1);
	size_t	len2 = ft_strlen(s2);
	char	*new_str;
	size_t	i = 0;
	size_t	j = 0;

	new_str = malloc(len1 + len2 + 1);
	if (!new_str)
		return (NULL);
	while (i < len1)
	{
		new_str[i] = s1[i];
		i++;
	}
	while (j < len2)
		new_str[i++] = s2[j++];
	new_str[i] = '\0';

	if (s1)
		free(s1);
	return (new_str);
}