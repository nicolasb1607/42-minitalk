/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:38:47 by nburat-d          #+#    #+#             */
/*   Updated: 2022/01/17 15:50:24 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Alloue (avec malloc(3)) et retourne une nouvelle
chaine, résultat de la concaténation de s1 et s2.

La nouvelle chaine de caractères. NULL si
l’allocation échoue.

#1. La chaine de caractères préfixe.
#2. La chaine de caractères suffixe. */
char	*ft_strjoin(char *s1, char c)
{
	int		catlen;
	char	*strcat;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1)
		calloc(1, 1);
	catlen = ft_strlen(s1) + 1;
	strcat = malloc((catlen + 1) * sizeof(char));
	if (!strcat)
		return (NULL);
	while (s1[++i])
		strcat[++j] = s1[i];
	strcat[++j] = c;
	strcat[++j] = '\0';
	return (strcat);
}
