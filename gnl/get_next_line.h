#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
char	*get_correct_line(char *file, int start_pos, int pos_n);
int		first_read(int fd, char **file, int *start_pos, int *pos_n);
char	*read_until_newline(int fd, char **file, int start_pos, int *pos_n);
int		free_and_zero(char *file);

char	*ft_strdup_gnl(char *s1);
char	*ft_join_free(char *file, char *temp);
int		ft_strlen_v2(char *str, int start_pos);
int		get_pos_n(char *file, int start_pos);
char	*ft_cpy(char *str, char *file, int start_pos, int pos_n);

#endif
