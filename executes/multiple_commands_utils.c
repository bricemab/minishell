/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_commands_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <bmabilla>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:35:21 by lalex-ku          #+#    #+#             */
/*   Updated: 2024/09/24 12:50:28 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	*init_children_pid(char **commands)
{
	int		*children_pid;
	size_t	size;

	size = sizeof(int) * (arr_len(commands) + 1);
	children_pid = malloc(size);
	if (!children_pid)
		return (NULL);
	ft_bzero(children_pid, size);
	return (children_pid);
}

void	clean_after_execute(int *children_pid)
{
	close_extra_fds();
	free(children_pid);
}

void	quit_child(char **commands, t_env **minienv)
{
	clear_history();
	free_minienv(minienv);
	free_array(commands);
	close_all_fds();
	exit(EXIT_FAILURE);
}
