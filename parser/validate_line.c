/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:27:56 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/10/28 18:52:40 by yel-yaqi         ###   ########.fr       */
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

void	validate_line(char *line)
{
	if (line[0] == 'A')
		validate_a(line);
	else if (line[0] == 'C')
		validate_c(line);
	else if (line[0] == 'L')
		validate_l(line);
	else if (line[0] == 's')
		validate_sp(line);
	else if (line[0] == 'p')
		validate_pl(line);
	else if (line[0] == 'c')
		validate_cy(line);
}
