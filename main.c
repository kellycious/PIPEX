/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 22:31:50 by khuynh            #+#    #+#             */
/*   Updated: 2022/12/21 18:32:00 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/pipex.h"

int	filemanager(char *file, int end)
{
	int	action;

	if (end == 0)
		action = open(file, O_RDONLY, 0774);
	if (end == 1)
		action = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0774);
	if (action == -1)
	{
		ft_printf("Invalid read of file\n");
		exit(EXIT_FAILURE);
	}
	return (action);
}

void	shellcmd(char *cmd, char **env)
{
	char	**command;
	char	*path;

	command = ft_split(cmd, ' ');
	path = pathparse(command[0], env, 0);
	if (execve(path, command, env) == -1)
	{
		ft_putstr_fd("command not found:", 2);
		ft_putendl_fd(command[0], 2);
		freetab(command);
		exit(EXIT_FAILURE);
	}
}

void	child_process(char **av, int *end, char **env)
{
	int	fd;

	fd = filemanager(av[1], 0);
	dup2(fd, 0);
	dup2(end[1], 1);
	close(end[0]);
	shellcmd(av[2], env);
}

void	parent_process(char **av, int *end, char **env)
{
	int	fd;

	fd = filemanager(av[4], 1);
	dup2(fd, 1);
	dup2(end[0], 0);
	close(end[1]);
	shellcmd(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	int		end[2];
	pid_t	process;
	pid_t	process2;

	if (ac != 5)
		return (ft_printf("ERROR: use infile cmd cmd outfile\n"), 0);
	if (pipe(end) == -1)
		exit(EXIT_FAILURE);
	process = fork ();
	if (process == -1)
		exit(EXIT_FAILURE);
	if (!process)
		child_process(av, end, env);
	close (end[1]);
	process2 = fork ();
	if (process2 == -1)
		exit(EXIT_FAILURE);
	if (!process2)
		parent_process(av, end, env);
	close (end[1]);
	close (end[0]);
	waitpid(process, NULL, 0);
	waitpid(process2, NULL, 0);
	return (0);
}
