/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaman <mdaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:21:08 by mdaman            #+#    #+#             */
/*   Updated: 2025/01/22 13:21:35 by mdaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_sigquit(int sig)
{
	struct termios	term;

	(void)sig;
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	if (rl_line_buffer && !is_line_empty(rl_line_buffer))
	{
		write(STDOUT_FILENO, "\nQuit (core dumped)\n", 20);
		rl_replace_line("", 0);
		rl_redisplay();
		exit(131);
	}
}
