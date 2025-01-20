/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:13:11 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/01/20 10:18:58 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
#include <stdio.h>

char *g_p;

int main(void) {
	g_p = malloc(10 * sizeof(char));
	if (!g_p)
		return 1;
	
	char *p = malloc(10 * sizeof(char));
	if (p)
		return 1;
	return 0;
}