/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 13:48:45 by aait-ihi          #+#    #+#             */
/*   Updated: 2020/11/07 19:38:04 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xml.h"

void		free_tokens(void **elm)
{
	t_xml_lexer	**token;

	if (!elm || !*elm)
		return ;
	token = (t_xml_lexer **)elm;
	ft_memdel((void **)&(*token)->value);
	ft_memdel(elm);
	*token = NULL;
}

t_xml_lexer	xmlexer_get_tag(char *line, size_t *c, size_t l)
{
	t_xml_lexer	node;
	int			i;

	i = *c;
	node.type = (line[*c + 1] == '/' ? XMLTAGCLOSE : XMLTAGOPEN);
	c[0] += ft_skip_unitl_char(&line[*c], ">", NULL) - &line[*c];
	c[0] += (line[*c] != '\0');
	node.value_len = *c - i;
	node.value = ft_strsub(line, i, node.value_len);
	node.line = l + 1;
	node.col = i + 1;
	return (node);
}

t_xml_lexer	xmlexer_get_value(char *line, size_t *c, size_t l)
{
	t_xml_lexer	node;
	int			i;

	i = *c;
	c[0] += ft_skip_unitl_char(&line[*c], "<", NULL) - &line[*c];
	node.type = XMLVALUE;
	node.value_len = *c - i;
	node.value = ft_strsub(line, i, node.value_len);
	node.line = l + 1;
	node.col = i + 1;
	return (node);
}

t_list		*add_to_xmlexer(t_list *tokens, char *line, size_t line_count)
{
	t_xml_lexer	xmlnode;
	size_t		col;

	col = 0;
	while (line[col])
	{
		col += ft_skip_chars(&line[col], NULL, ft_iswhitespace) - &line[col];
		if (line[col])
		{
			if (line[col] == '<')
				xmlnode = xmlexer_get_tag(line, &col, line_count);
			else
				xmlnode = xmlexer_get_value(line, &col, line_count);
			ft_lstenqueue(&tokens, ft_lstnew(&xmlnode, sizeof(t_xml_lexer)));
		}
	}
	return (tokens);
}

t_list		*read_and_tokenizexml(int fd)
{
	t_list	*tokens;
	char	*line;
	size_t	line_count;

	tokens = NULL;
	line = NULL;
	line_count = 0;
	while (get_next_line(fd, &line) > 0)
	{
		tokens = add_to_xmlexer(tokens, line, line_count);
		line_count++;
		ft_memdel((void **)&line);
	}
	ft_memdel((void **)&line);
	return (tokens);
}
