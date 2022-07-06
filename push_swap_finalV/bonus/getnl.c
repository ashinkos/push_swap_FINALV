/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouni <aaouni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 01:35:32 by aaouni            #+#    #+#             */
/*   Updated: 2022/07/05 21:04:02 by aaouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include"getnl.h"

char	*ft_strdup(char *str)
{
	int		i;
	int		sz;
	char	*s;

	i = 0;
	sz = ft_strlen(str);
	s = malloc(sz * sizeof(char) + 1);
	if (!s)
		return (NULL);
	while (i < sz)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*getnl(int fd)
{
	char	buff;
	char	ret[7000000];
	int		i;
	int		n;

	i = 0;
	if (fd < 0)
		return (0);
	n = read(fd, &buff, 1);
	while (n > 0)
	{
		ret[i++] = buff;
		if (buff == '\n')
			break ;
		n = read(fd, &buff, 1);
	}
	ret[i] = '\0';
	if (i == 0 && n <= 0)
		return (0);
	return (ft_strdup(ret));
}

