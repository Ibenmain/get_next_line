/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:32:53 by ibenmain          #+#    #+#             */
/*   Updated: 2021/12/17 17:22:25 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include<stdio.h>
# include<stdlib.h>
# include<fcntl.h>
# include<unistd.h>

char	*get_next_line(int fd);
int		find_new_line(char *string);
char	*get_line(char *str);
char	*get_rest(char *str);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
char	*ft_substr(char *s, int start, int len);

#endif
