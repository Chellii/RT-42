/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xml.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 12:04:12 by aait-ihi          #+#    #+#             */
/*   Updated: 2020/11/09 13:39:06 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XML_H
# define XML_H

# include "libft.h"
# include <fcntl.h>
# define XMLTAGOPEN 1
# define XMLTAGCLOSE 2
# define XMLVALUE 3
# define TAG_TYPE_LEN 10

/*
** DEFINE ERROR MESSAGE
*/

# define OPEN_TAG_ERR "Invalide open tag at %lu:%lu\n"
# define NO_TAG_TO_CLOSE "No open tag to close at %lu:%lu\n"
# define INV_TAG_CLOS "Invalid tag close except `</%s>` found `%s` at %lu:%lu\n"
# define NO_TAG_FOR_VAL "No opened tag to put the value at %lu:%lu\n"
# define ELEM_AFTER_ROOT "Element after root tag at %lu:%lu\n"
# define NO_TAG_CLOSE "No tag close found for `%s` at the end of file\n"

typedef struct	s_xml_lexer
{
	char	*value;
	size_t	line;
	size_t	col;
	int		type;
	int		value_len;
}				t_xml_lexer;

typedef union	u_tag_value
{
	int		integer;
	float	decimal;
	double	real;
	long	bigint;
	char	*string;
}				t_tag_value;

typedef struct	s_xml_tag
{
	char		*name;
	t_list		*nodes;
	t_list		*attributes;
	char		*value;
	size_t		line;
	size_t		col;
}				t_xml_tag;

typedef struct	s_dtd_restriction
{
	long		min;
	long		max;
	char		*type;
	char		**enumeration;
}				t_dtd_restriction;

typedef struct	s_dtd_element_content
{
	char	*name;
	char	cardinality;
	char	splitter;
	t_list	*elements;
}				t_dtd_element_content;

typedef struct	s_dtd
{
	char					*name;
	t_dtd_element_content	content;
	t_list					*attributes;
	t_dtd_restriction		restriction;
}				t_dtd;

typedef struct	s_rule_tag
{
	char	*name;
	char	*type;
	char	*dep;
	int		optional;
}				t_rule_tag;

typedef struct	s_tag_rule
{
	char		*name;
	t_rule_tag	*rule_tags;
}				t_tag_rule;

t_list			*read_and_tokenizexml(int fd);
t_xml_tag		*xml_modeling(t_list *tokens);

int				valid_min_max(char *str, size_t *col, size_t line);
int				valid_type(char *str, size_t *col, size_t line);
int				valid_enum(char *str, size_t *col, size_t line);
int				valid_dtd_element(char *str, size_t line);
t_dtd			*parse_dtd(char *file);
void			free_xml_dom(void **elm);
void			free_tokens(void **elm);
void			free_xml_dom(void **elm);

#endif
