/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 21:26:35 by aait-ihi          #+#    #+#             */
/*   Updated: 2020/11/07 20:01:17 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_TABLE_H
# define HASH_TABLE_H

typedef struct	s_hash_content
{
	void					*value;
	char					*key;
	struct s_hash_content	*next;
	struct s_hash_content	*last;
}				t_hash_content;

typedef struct	s_hash_table
{
	t_hash_content	*table;
	unsigned int	size;
	unsigned int	used_size;
	unsigned int	expanding_size;
}				t_hash_table;

t_hash_table	*new_hash_table(unsigned int size, unsigned int expnading_size);
void			*hash_find(t_hash_table *tab, const char *key);
int				hash_insert(t_hash_table *tab, char *key, void *value,
																	int expand);
void			free_hash_table(t_hash_table **tab, void (*del)(void **));

#endif
