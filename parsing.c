/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 23:46:17 by khuynh            #+#    #+#             */
/*   Updated: 2022/12/04 14:31:55 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/pipex.h"

char	*envparse(char *path, char **env)
{
	int		i;
	int		j;
	char	*crop;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		crop = ft_substr(env[i], 0, j);
		if (ft_strncmp(crop, path, ft_strlen(crop)) == 0)
		{
			free(crop);
			return (env[i] + j + 1);
		}
		free(crop);
		i++;
	}
	return (NULL);
}

void	freetab(char **tofree)
{
	int	i;

	i = 0;
	while (tofree[i])
	{
		free(tofree[i]);
		i++;
	}
	free(tofree);
}

char	*pathparse(char *cmd, char **env, int i)
{
	char	*exe;
	char	**envpath;
	char	*path;
	char	**command;

	envpath = ft_split(envparse("PATH", env), ':');
	command = ft_split(cmd, ' ');
	if (!command || !envpath)
		return (0);
	while (envpath[i])
	{
		path = ft_strjoin(envpath[i], "/");
		if (!path)
			return (0);
		exe = ft_strjoin(path, command[0]);
		if (!exe)
			return (0);
		if (access(exe, F_OK | X_OK) == 0)
			return (freetab(command), exe);
		free(exe);
		i++;
	}
	return (free(envpath), freetab(command), cmd);
}

/*
int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	ft_printf("envparse = %s\n", envparse("PATH", env));
	ft_printf("pathparse = %s\n", pathparse("ls", env));
	return (0);
}*/