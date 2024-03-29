/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:57:33 by sergio            #+#    #+#             */
/*   Updated: 2024/03/10 10:03:27 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_mini_header(void)
{
	printf("\n\n");
	printf(BOLD_CYAN" /$$      /$$ /$$$$$$ /$$   /$$ /$$$$$$  /$$$");
	printf("$$$  /$$   /$$ /$$$$$$$$ /$$       /$$      \n");
	printf("| $$$    /$$$|_  $$_/| $$$ | $$|_  $$_/ /$$__");
	printf("  $$| $$  | $$| $$_____/| $$      | $$      \n");
	printf("| $$$$  /$$$$  | $$  | $$$$| $$  | $$  | $$  ");
	printf("\\__/| $$  | $$| $$      | $$      | $$      \n");
	printf("| $$ $$/$$ $$  | $$  | $$ $$ $$  | $$  |  $$$");
	printf("$$$ | $$$$$$$$| $$$$$   | $$      | $$      \n");
	printf("| $$  $$$| $$  | $$  | $$  $$$$  | $$   \\___");
	printf("_  $$| $$__  $$| $$__/   | $$      | $$      \n");
	printf("| $$\\  $ | $$  | $$  | $$\\  $$$  | $$   /$$");
	printf("  \\ $$| $$  | $$| $$      | $$      | $$      \n");
	printf("| $$ \\/  | $$ /$$$$$$| $$ \\  $$ /$$$$$$|  $$");
	printf("$$$$/| $$  | $$| $$$$$$$$| $$$$$$$$| $$$$$$$$\n");
	printf("|__/     |__/|______/|__/  \\__/|______/ \\___");
	printf("___/ |__/  |__/|________/|________/|________/\n"RESET);
	printf("\n\n");
}

char	*ft_remove_varible(char *dst, char *var_content)
{
	int num;
	int i;

	num = 0;
	i = 0;
	while (var_content[num] != '=')
		num++;
	while (var_content[++num] != '\0')
		dst[i++] = var_content[num];
	dst[i++] = ' ';
	dst[i++] = '-';
	dst[i++] = '-';
	dst[i++] = '>';
	dst[i++] = ' ';
	while (dst[i] != '\0')
		dst[i++] = '\0';
	return (dst);
}

int	ft_invalid_expr(t_mini *mini)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (mini->input[i] != '\0')
		j += ft_isspace(mini->input[i++]);
	if (j == i)
		return(-1);
	return (0);
}

void	ft_set_values(t_mini *mini, char **argv, char **envp)
{
	mini->pwd = NULL;
	mini->start = 1;
	argv[0] = argv[0];
	mini->envp = envp;
	mini->g_error = 0;
	mini->exit_status = 0;
}

char	*ft_find_in_envp(char *variable, char** envp)
{
	int i;
	char *temp;

	i = -1;
	variable = ft_strjoin(variable, "=");
	//printf("Variable -> %s\n", variable);
	while(envp[++i] != NULL)
	{
		if (ft_strnstr(envp[i], variable, ft_strlen(variable)) != NULL)
		{
			temp = ft_remove_varible(envp[i], envp[i]);
			free(variable);
			return (temp);
		}
	}
	free(variable);
	return (NULL);
}
                                             
void	ft_initialize(t_mini *mini)
{
	if (mini->start == 1 && mini->start-- > 0)
		ft_mini_header();
	if (mini->pwd == NULL)
		mini->pwd = ft_find_in_envp("PWD", mini->envp); /* 1 */
	mini->input = readline(mini->pwd);
}

void	ft_not_variable(void)
{
	printf(""); /* 2 */
}

// void	ft_free_matrix(char **matrix)
// {
// 	int	i;

// 	i = 0;
// 	if (!matrix)
// 		return ;
// 	while (matrix[i])
// 	{
// 		free(matrix[i]);
// 		matrix[i] = NULL;
// 		i++;
// 	}
// }