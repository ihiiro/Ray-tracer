/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_objects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:20:36 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/10/22 11:45:25 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data_structs/data_structs.h"
#include "../data_structs/data_funcs.h"

void	validate_sp(char *line)
{
	line += 2;
	if (*line != ' ')
		exitf("sp: no space after identifier\n");
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
		exitf("sp: too many fields\n");
}

void	validate_pl(char *line)
{
	line += 2;
	if (*line != ' ')
		exitf("pl: no space after identifier\n");
	while (*line == ' ')
		line++;
	validate_field(&line, MULTI);
	while (*line == ' ')
		line++;
	validate_field(&line, MULTI);
	while (*line == ' ')
		line++;
	validate_field(&line, MULTI);
	if (*line != '\n')
		exitf("pl: too many fields\n");
}

void	validate_cy(char *line)
{
	line += 2;
	if (*line != ' ')
		exitf("cy: no space after identifier\n");
	while (*line == ' ')
		line++;
	validate_field(&line, MULTI);
	while (*line == ' ')
		line++;
	validate_field(&line, MULTI);
	while (*line == ' ')
		line++;
	validate_field(&line, SINGLE);
	while (*line == ' ')
		line++;
	validate_field(&line, SINGLE);
	while (*line == ' ')
		line++;
	validate_field(&line, MULTI);
	if (*line != '\n')
		exitf("cy: too many fields\n");
}
