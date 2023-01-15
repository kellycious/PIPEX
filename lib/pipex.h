/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 23:09:02 by khuynh            #+#    #+#             */
/*   Updated: 2022/12/21 18:29:43 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <stdio.h>
# include "libft/libft.h"

char	*envparse(char *path, char **env);
char	*pathparse(char *cmd, char **env, int i);
void	freetab(char **tofree);
int		filemanager(char *file, int end);
void	shellcmd(char *cmd, char **env);
void	child_process(char **av, int *end, char **env);
void	parent_process(char **av, int *end, char **env);
int		main(int ac, char **av, char **env);

#	endif 