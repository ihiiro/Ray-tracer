/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_envi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:20:29 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/10/25 20:10:15 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data_structs/data_structs.h"
#include "../data_structs/data_funcs.h"

void	validate_a(char *line)
{
	line++;
	if (*line != ' ')
		exitf("A: no space after identifier\n");
	while (*line == ' ')
		line++;
	validate_field(&line, SINGLE);
	if (*line != ' ')
		exitf("missing space between fields\n");
	while (*line == ' ')
		line++;
	validate_field(&line, MULTI);
	if (*line != '\n' && *line != '\0')
		exitf("A: too many fields\n");
}

void	validate_c(char *line)
{
	line++;
	if (*line != ' ')
		exitf("C: no space after identifier\n");
	while (*line == ' ')
		line++;
	validate_field(&line, MULTI);
	while (*line == ' ')
		line++;
	validate_field(&line, MULTI);
	while (*line == ' ')
		line++;
	validate_field(&line, SINGLE);
	if (*line != '\n' && *line != '\0')
		exitf("C: too many fields\n");
}

void	validate_l(char *line)
{
	line++;
	if (*line != ' ')
		exitf("L: no space after identifier\n");
	while (*line == ' ')
		line++;
	validate_field(&line, MULTI);
	while (*line == ' ')
		line++;
	validate_field(&line, SINGLE);
	while (*line == ' ')
		line++;
	validate_field(&line, MULTI);
	if (*line != '\n' && *line != '\0')
		exitf("L: too many fields\n");
}
