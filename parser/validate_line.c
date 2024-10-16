/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:27:56 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/10/16 16:38:15 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data_structs/data_structs.h"
#include "../data_structs/data_funcs.h"

void	validate_n(char **line)
{
	if (**line == '-' || **line == '+')
		(*line)++;
	if (**line < '0' || **line > '9')
		exitf("NaN\n");
	while (**line >= '0' && **line <= '9')
		(*line)++;
	if (**line == '.')
	{
		(*line)++;
		if (**line < '0' || **line > '9')
			exitf("NaN\n");
	}
	while (**line >= '0' && **line <= '9')
		(*line)++;
}

void	validate_field(char **line, bool type)
{
	if (type == MULTI)
	{
		validate_n(line);
		if (**line != ',')
			exitf("missing comma\n");
		(*line)++;
		validate_n(line);
		if (**line != ',')
			exitf("missing comma\n");
		(*line)++;
		validate_n(line);
	}
	else
		validate_n(line);
}

void	validate_A(char *line)
{
	line++;
	while (*line == ' ')
		line++;
	validate_field(&line, SINGLE);
	if (*line != ' ')
		exitf("missing space between fields\n");
	while (*line == ' ')
		line++;
	validate_field(&line, MULTI);
	if (*line != '\n')
		exitf("A: too many fields\n");
}

void	validate_C(char *line)
{
	line++;
	while (*line == ' ')
		line++;
	validate_field(&line, MULTI);
	while (*line == ' ')
		line++;
	validate_field(&line, MULTI);
	while (*line == ' ')
		line++;
	validate_field(&line, SINGLE);
	if (*line != '\n')
		exitf("C: too many fields\n");
}

void	validate_L(char *line)
{
	line++;
	while (*line == ' ')
		line++;
	validate_field(&line, MULTI);
	while (*line == ' ')
		line++;
	validate_field(&line, SINGLE);
	while (*line == ' ')
		line++;
	validate_field(&line, MULTI);
	if (*line != '\n')
		exitf("L: too many fields\n");
}

void	validate_line(char *line)
{
	if (line[0] == 'A')
		validate_A(line);
	else if (line[0] == 'C')
		validate_C(line);
	else if (line[0] == 'L')
		validate_L(line);
	// else if (line[0] == 's')
	// 	validate_s(line);
}
