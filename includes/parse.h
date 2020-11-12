/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:01:06 by aait-ihi          #+#    #+#             */
/*   Updated: 2020/11/07 20:51:40 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libft.h"
# include "xml.h"
# include "rt.h"
# include <fcntl.h>

# define L1 "camera:6\n"
# define L2 "\tlook_from :0: vec\n"
# define L3 "\tlook_at :0: vec\n"
# define L4 "\tscene_type :0: enum : normal , antialiasing, depth_of_field\n"
# define L5 "\tindirect_light :1: enum: 1,0\n"
# define L6 "\talgo_type :0: enum : simple , multithreading , motionblur\n"
# define L6_2 "\tfilter :1: enum : 0 , sepia , grey , gray\n"

# define L7 "sphere:11\n"
# define L8 "\tposition :0: vec\n"
# define L9 "\tradius :0: double\n"
# define L10 "\tsphere_negatif :1: enum : 1 , 0\n"
# define L11 "\tcut_exist :1: cut_exist\n"
# define L12 "\tcolor :0: vec\n"
# define L13 "\ttranslation :1: vec\n"
# define L14 "\tdiffuse :1: enum : 1 , 0\n"
# define L15 "\tspecular :1: enum : 1 , 0\n"
# define L16 "\treflection :1: uint\n"
# define L17 "\trefraction :1: uint\n"

# define L19 "cone:14\n"
# define L20 "\tposition :0: vec\n"
# define L21 "\taxis :0: vec\n"
# define L22 "\tangle :0: double\n"
# define L23 "\tcut_limit1 :1: double\n"
# define L24 "\tcut_limit2 :1: double\n"
# define L25 "\tcut_exist :1: cut_exist\n"
# define L26 "\tcolor :0: vec\n"
# define L27 "\ttranslation :1: vec\n"
# define L28 "\trotation :1: vec\n"
# define L29 "\tdiffuse :1: enum : 1 , 0\n"
# define L30 "\tspecular :1: enum : 1 , 0\n"
# define L31 "\treflection :1: uint\n"
# define L32 "\trefraction :1: uint\n"

# define L34 "cylinder:14\n"
# define L35 "\tposition :0: vec\n"
# define L36 "\taxis :0: vec\n"
# define L37 "\tradius :0: double\n"
# define L38 "\tcut_limit :1: double\n"
# define L39 "\tcyl_negatif :1: enum : 1 , 0\n"
# define L40 "\tcut_exist :1: cut_exist \n"
# define L41 "\tcolor :0: vec\n"
# define L42 "\ttranslation :1: vec\n"
# define L43 "\trotation :1: vec\n"
# define L44 "\tdiffuse :1: enum : 1 , 0\n"
# define L45 "\tspecular :1: enum : 1 , 0\n"
# define L46 "\treflection :1: uint\n"
# define L47 "\trefraction :1: uint\n"

# define L49 "plane:10\n"
# define L50 "\tposition :0: vec\n"
# define L51 "\taxis :0: vec\n"
# define L52 "\tcolor :0: vec\n"
# define L53 "\ttranslation :1: vec\n"
# define L54 "\trotation :1: vec\n"
# define L55 "\tdiffuse :1: enum : 1 , 0\n"
# define L56 "\tspecular :1: enum : 1 , 0\n"
# define L57 "\treflection :1: uint\n"
# define L58 "\trefraction :1: uint\n"

# define L60 "disk:8\n"
# define L61 "\tposition :0: vec\n"
# define L62 "\taxis :0: vec\n"
# define L63 "\tradius :0: double\n"
# define L64 "\tcolor :0: vec\n"
# define L65 "\ttranslation :1: vec\n"
# define L66 "\trotation :1: vec\n"
# define L67 "\tdiffuse :1: enum : 1 , 0\n"
# define L68 "\tspecular :1: enum : 1 , 0\n"

# define L69 "paraboloid:8\n"
# define L70 "\tposition :0: vec\n"
# define L71 "\taxis :0: vec\n"
# define L72 "\tradius :0: double\n"
# define L73 "\tcolor :0: vec\n"
# define L74 "\ttranslation :1: vec\n"
# define L75 "\trotation :1: vec\n"
# define L76 "\tdiffuse :1: enum : 1 , 0\n"
# define L77 "\tspecular :1: enum : 1 , 0\n"

# define L78 "hyperboloid:7\n"
# define L79 "\tposition :0: vec\n"
# define L80 "\tradius :0: double\n"
# define L81 "\tcolor :0: vec\n"
# define L82 "\ttranslation :1: vec\n"
# define L83 "\trotation :1: vec\n"
# define L84 "\tdiffuse :1: enum : 1 , 0\n"
# define L85 "\tspecular :1: enum : 1 , 0\n"

# define L86 "triangle:8\n"
# define L87 "\tposition :0: vec\n"
# define L88 "\tvalue_of_v1 :0: vec\n"
# define L89 "\tvalue_of_v2 :0: vec\n"
# define L90 "\tcolor :0: vec\n"
# define L91 "\ttranslation :1: vec\n"
# define L92 "\trotation :1: vec\n"
# define L93 "\tdiffuse :1: enum : 1 , 0\n"
# define L94 "\tspecular :1: enum : 1 , 0\n"

# define L95 "square:11\n"
# define L96 "\tposition :0: vec\n"
# define L97 "\taxis :0: vec\n"
# define L98 "\tvalue_of_v1 :0: vec\n"
# define L99 "\tvalue_of_v2 :0: vec\n"
# define L100 "\tvalue_of_w :0: double\n"
# define L101 "\tvalue_of_h :0: double\n"
# define L102 "\tcolor :0: vec\n"
# define L103 "\ttranslation :1: vec\n"
# define L104 "\trotation :1: vec\n"
# define L105 "\tdiffuse :1: enum : 1 , 0\n"
# define L106 "\tspecular :1: enum : 1 , 0\n"

# define L107 "cube:5\n"
# define L108 "\tposition :0: vec\n"
# define L109 "\tradius :0: double\n"
# define L110 "\tcolor :0: vec\n"
# define L111 "\tdiffuse :1: enum : 1 , 0\n"
# define L112 "\tspecular :1: enum : 1 , 0\n"

# define L113 "torus:6\n"
# define L114 "\tposition :0: vec\n"
# define L115 "\tradius :0: double\n"
# define L116 "\tradius1 :0: double\n"
# define L117 "\tcolor :0: vec\n"
# define L118 "\tdiffuse :1: enum : 1 , 0\n"
# define L119 "\tspecular :1: enum : 1 , 0\n"

# define L120 "light:5\n"
# define L121 "\tposition :0: vec\n"
# define L122 "\tcolor :0: vec\n"
# define L123 "\ttype :1: double\n"
# define L124 "\tintensity :0: vec\n"
# define L125 "\tambient :0: double\n"

# define E_SCENE_TYPE "normal , antialiasing, depth_of_field"
# define E_ALGO_TYPE "simple , multithreading , motionblur"
# define E_FILTER "0, sepia , grey , gray"
# define E_TEXTURE "wood , cloud , marble , perlin_noise , damier , xor_noise"
# define E_TEXTURE2 " , toon_shading , normal_perturbation"
# define E_ONE_ZERO "0,1"
# define TEXTURE "\ttexture :1: enum :"

# define TAG_NOTFOUND "Tag %s not found at the end of file\n"
# define TAG_NOTFOUND_AT "Tag `%s` not found after `%s`  at %lu:%lu\n"
# define INVALID_TAG "Invalid tag name at %lu:%lu\n"
# define ADDITIONAL_TAG "additional tag at %lu:%lu\n"
# define TAG_EXCEPT_FOUND "Except tag `%s` found `%s` at %lu:%lu\n"
# define INVALID_VAL "invalid value except `%s` at %lu:%lu\n"

# define VAL1 "value_of_v1"
# define VAL2 "value_of_v2"

bool			rt_valid_vec(t_xml_tag *tag);
bool			rt_valid_cut_exist(t_xml_tag *tag);
bool			rt_valid_enum(t_xml_tag *tag, const char *enums);
t_xml_tag		*get_val(t_xml_tag *parent, const char *except);
bool			rt_valid_number(t_xml_tag *tag, char *type);
int				make_enum(t_list **node);
double			make_double(t_list **node);
void			make_cut_exist(t_list **node, t_obj *obj);
t_vector		make_vector(t_list **node);
t_all			*make_all(t_xml_tag *tag);
bool			valide_tags(t_xml_tag *root, t_hash_table *rules);
t_hash_table	*get_rules(char **lines);
char			**make_file_indicator(void);
t_all			*read_make_obj(char *file);
t_vector		divise_color(t_vector color);
t_obj			*make_object(t_xml_tag *tag);
void			free_rule(void **to_free);
bool			valid_rule_by_type(t_xml_tag *tag, char *type, char *dep);
bool			valide_rule(t_xml_tag *tag, t_tag_rule *rule);

#endif
