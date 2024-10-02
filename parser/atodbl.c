/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atodbl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 03:00:50 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/10/02 03:27:33 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data_structs/data_funcs.h"
#include "../maths/maths.h"
#include <stdlib.h>
#include <stdio.h>

int    ft_strncmp(char *s1, char *s2, size_t n)
{
    size_t    i;

    if (n == 0)
        return (0);
    i = 0;
    while ((s1[i] || s2[i]) && n > i)
    {
        if (s1[i] != s2[i])
            return ((unsigned char)s1[i] - (unsigned char)s2[i]);
        i++;
    }
    return (0);
}

static double    get_fraction(const char *str, int i)
{
    int        point;
    double    res2;

    point = 0;
    res2 = 0;
    if (str[i] == '\0')
        exitf("parse error near a fraction\n");
    while (str[i] >= '0' && str[i] <= '9')
    {
        res2 = res2 * 10 + str[i] - '0';
        i++;
        point++;
    }
    ((str[i] < '0' || str[i] > '9') && str[i] != '\0') && (exitf("parse error near a fraction\n"), 0);
    while (point > 0)
    {
        res2 = res2 / 10;
        point--;
    }
    return (res2);
}

double    atodbl(const char *str)
{
    double    res;
    double    res2;
    int        i;
    int        sign;

    i = 0;
    res = 0;
    res2 = 0;
    sign = 1;
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
        || str[i] == '\f' || str[i] == '\r')
        i++;
    if (str[i] == '-' || str[i] == '+')
        if (str[i++] == '-')
            sign = -1;
    (str[i] == '.') && (exitf((const char *)str), 0);
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + str[i] - '0';
        i++;
    }
    (str[i] == '.') && (res2 = get_fraction(str, i + 1));
    if (str[i] != '.' && str[i] != '\0')
        exitf((const char *)str);
    return ((res + res2) * sign);
}
