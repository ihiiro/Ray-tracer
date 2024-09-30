/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:30:17 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/09/30 11:04:49 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	exitf(char *msg)
{
	size_t	len;

	len = 0;
	while (msg[len])
		len++;
	write(STDERR_FILENO, "Error\n", 6);
	write(STDERR_FILENO, msg, len);
	exit(EXIT_FAILURE);
}
