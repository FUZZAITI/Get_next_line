#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> 


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

char    *get_next_line(int fd);
size_t  gnl_strlen(const char *s);
char    *gnl_strchr(const char *s, int c);
char    *gnl_strjoin(char *s1, char *s2);
char    *gnl_get_line(char *stash);
char    *gnl_save_rest(char *stash);

char *get_next_line(int fd)
{
	static char *stash;
	char *buffer;
	char *line;
	ssize_t bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer) 
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !gnl_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		stash = gnl_strjoin(stash, buffer);
		if (!stash) 
		{ 
			free(buffer); 
			return (NULL); 
		}
	}
		free(buffer);
		if (!stash || stash[0] == '\0')
		{
			free(stash);
			stash = NULL;
			return NULL;
		}
		line = gnl_get_line(stash);
		stash = gnl_save_rest(stash);
		return line;
}

size_t gnl_strlen(const char *s)
{
    size_t i = 0;
    if (!s) return 0;
    while (s[i]) i++;
    return i;
}

char *gnl_strchr(const char *s, int c)
{
    if (!s) return NULL;
    while (*s)
    {
        if (*s == (char)c)
            return (char *)s;
        s++;
    }
    if (c == '\0')
        return (char *)s;
    return NULL;
}

char *gnl_strjoin(char *s1, char *s2)
{
    size_t len1 = gnl_strlen(s1);
    size_t len2 = gnl_strlen(s2);
    char *res = malloc(len1 + len2 + 1);
    size_t i = 0, j = 0;

    if (!res)
    {
        free(s1);
        return NULL;
    }
    while (i < len1) { res[i] = s1[i]; i++; }
    while (j < len2) { res[i + j] = s2[j]; j++; }
    res[i + j] = '\0';
    free(s1);
    return res;
}

char *gnl_get_line(char *stash)
{
    size_t i = 0;
    char *line;

    if (!stash || !stash[0])
        return NULL;
    while (stash[i] && stash[i] != '\n')
        i++;
    if (stash[i] == '\n')
        line = malloc(i + 2);
    else
        line = malloc(i + 1);
    if (!line) return NULL;
    for (size_t k = 0; k < i; k++)
        line[k] = stash[k];
    if (stash[i] == '\n')
    {
        line[i] = '\n';
        line[i+1] = '\0';
    }
    else
        line[i] = '\0';
    return line;
}

char *gnl_save_rest(char *stash)
{
    size_t i = 0, j = 0;
    char *rest;

    while (stash[i] && stash[i] != '\n')
        i++;
    if (!stash[i]) /* sem '\n', não sobra nada */
    {
        free(stash);
        return NULL;
    }
    i++; /* pula o '\n' */
    rest = malloc(gnl_strlen(stash + i) + 1);
    if (!rest)
    {
        free(stash);
        return NULL;
    }
    while (stash[i + j])
    {
        rest[j] = stash[i + j];
        j++;
    }
    rest[j] = '\0';
    free(stash);
    return rest;
}

