/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 17:52:33 by cel-oiri          #+#    #+#             */
/*   Updated: 2020/11/06 05:46:11 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include "../libft/includes/libft.h"
# include <pthread.h>
# include "bitmapheader.h"

# define WIN_HEIGHT 1100
# define WIN_WIDTH 1000
# define MPI 3.141592653589793
# define SPHERE 0
# define PLANE 1
# define CYLINDER 2
# define CONE 3
# define DISK 4
# define TRIG 5
# define SQUARE 6
# define PARAB 7
# define HYPER 8
# define CUBE 9
# define TORUS 10
# define SPOT_LIGHT 11
# define NORMAL_LIGHT 12
# define MIN_DIS 1E-6
# define MAX_DIS 1E+6
# define FILTERWIDTH 18
# define FILTERHEIGHT 18
# define EQN_EPS 1E-9

enum {wood, cloud, marble, perlin_noise, damier, xor__noise,
	toon_shad, normal_pert};

enum {
	normal, anti_alias, depth_of_field
};

typedef struct	s_vector
{
	double	x;
	double	y;
	double	z;
}				t_vector;

typedef	struct	s_verif_obj
{
	int i;
	int vec;
	int line;
	int mat;
	int tex;
	int	cut;
}				t_verif_obj;

typedef	struct	s_dof
{
	double		dx_aperture;
	double		dy_aperture;
	t_vector	destination;
	t_vector	new_origin;
	double		focus_dist;
	int			depth;
	int			s;
}				t_dof;

typedef	struct	s_bmp
{
	int						width_in_bytes;
	uint32_t				imagesize;
	t_bitmap_file_header	filehdr;
	t_bitmap_info_header	infohdr;
	unsigned char			*buf;
	int						fout;
}				t_bmp;

typedef	struct	s_toon_shading
{
	double		ndotl;
	t_vector	light_color;
	float		light_intens;
	t_vector	specular_color;
	t_vector	ret_color;
	t_vector	view_dir;
	t_vector	light_reflect;
	float		spec_ref;
	t_vector	rim;
	float		rim_dot;
	float		rim_intensity;
}				t_toon_shading;

typedef	struct	s_spot_light
{
	float		cutoff;
	float		outcutoff;
	t_vector	poslight;
	float		theta;
	float		epsilon;
	float		intensity;
}				t_spot_light;

typedef	struct	s_pnoise
{
	int		xi;
	int		yi;
	int		zi;
	double	u;
	double	v;
	double	w;
	int		a;
	int		aa;
	int		ab;
	int		b;
	int		ba;
	int		bb;
	int		*p;
}				t_pnoise;

typedef	struct	s_mb
{
	double		factor;
	double		bias;
	int			fx;
	int			fy;
	int			img_x;
	int			img_y;
	double		red;
	double		green;
	double		blue;
}				t_mb;

typedef	struct	s_rand_cos_vec
{
	double		r1;
	double		r2;
	t_vector	direct_rand_rep_loc;
	t_vector	random_vect;
	t_vector	tang1;
	t_vector	tang2;
	t_vector	random_dir;
}				t_rand_cos_vec;

typedef struct	s_intersect_var
{
	double		a;
	double		b;
	double		c;
	double		d;
	double		x;
	double		y;
	double		z;
	double		p;
	double		t;
	double		e;
	double		s;
	double		k;
	double		dot;
	double		tab[4];
	double		sl[5];
	double		r1;
	double		r2;
	double		det;
	double		beta;
	double		gamma;
	double		delta;
	double		sqrdelta;
	double		t0;
	double		t1;
	int			res;
	double		t0_neg;
	double		t1_neg;
	int			min;
	double		rdota;
	double		t_prec;
	double		hit_point;
	t_vector	oc;
	t_vector	dist;
	t_vector	u;
	t_vector	v;
	t_vector	i;
}				t_intersect_var;

typedef struct	s_list_pars
{
	char				*str;
	struct s_list_pars	*next;
}				t_list_pars;

typedef struct	s_ray
{
	t_vector	start;
	t_vector	dir;
	int			i;
	int			j;
}				t_ray;

typedef struct	s_light
{
	t_vector		pos;
	t_vector		intensity;
	float			amb_intens;
	t_vector		color;
	float			spot_light;
	struct s_light	*next;
}				t_light;

typedef struct	s_camera
{
	t_vector	lookfrom;
	t_vector	lookat;
	double		vfov;
	double		aspect;
	double		theta;
	double		half_height;
	double		half_width;
	t_vector	lookup;
	t_vector	origin;
	t_vector	k;
	t_vector	i;
	t_vector	j;
	t_vector	w;
	t_vector	horizontal;
	t_vector	vertical;
}				t_camera;

typedef struct	s_material
{
	int			diffuse;
	int			specular;
	double		reflection;
	double		refraction;
	int			texture_exist;
	int			type;
}				t_material;

typedef struct	s_obj
{
	int				type;
	double			radius;
	double			radius1;
	double			angle;
	double			cut_cyl;
	double			w;
	double			h;
	double			negative;
	double			cut_var_cone1;
	double			cut_var_cone2;
	int				cut_xyz;
	t_vector		limit_xyz1;
	t_vector		limit_xyz2;
	t_vector		pos;
	t_vector		rot;
	t_vector		trans;
	t_vector		color;
	t_vector		axis;
	t_vector		v1;
	t_vector		v2;
	t_vector		v3;
	t_vector		v4;
	t_material		material;
	struct s_obj	*next;
}				t_obj;

typedef struct	s_hit
{
	int			type;
	int			hit;
	double		t;
	t_vector	n;
	t_vector	p;
	t_material	m;
	t_vector	color;
	t_vector	start_cube;
	double		hit_point;
}				t_hit;

typedef struct	s_scene
{
	int	scene_type;
	int	indirect;
	int	filter;
	int	choices;
}				t_scene;

typedef struct	s_all
{
	t_obj		*obj;
	t_light		*lights;
	t_camera	cam;
	t_scene		scene;
}				t_all;

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	void	*img_ptr2;
	int		*data;
	int		end;
	int		s_l;
	int		b;
	t_all	*all;
	char	*file_name;
	t_bmp	bmp;
}				t_data;

typedef struct	s_shade_var
{
	t_light		*light;
	t_ray		r;
	t_vector	color;
}				t_shade_var;

typedef struct	s_quartic
{
	double		a;
	double		b;
	double		c;
	double		d;
	double		z;
	double		u;
	double		v;
	double		sub;
	double		sq_a;
	double		p;
	double		q;
	double		r;
}				t_quartic;

typedef struct	s_cubic
{
	double		a;
	double		b;
	double		c;
	double		d;
	double		sq_a;
	double		p;
	double		q;
	double		cb_p;
}				t_cubic;

int				rt_min(double t1, double *t);
t_all			*fill_scene(t_data *w);
t_all			*ft_all(char *namefile);
t_obj			*ft_obj_new(t_obj o);
t_list_pars		*insert_mat(t_material *mat, char *str, t_list_pars *l, int i);
t_list_pars		*verif_cone_cyl(t_list_pars *l2, int *v);
t_list_pars		*verif_cube(t_list_pars *l2, int *v);
t_list_pars		*verif_disk(t_list_pars *l2, int *v);
t_list_pars		*verif_hyperboloid(t_list_pars *l2, int *v);
t_list_pars		*verif_paraboloid(t_list_pars *l2, int *v);
t_list_pars		*verif_plane(t_list_pars *l2, int *v);
t_list_pars		*verif_sphere(t_list_pars *l2, int *v);
t_list_pars		*verif_square(t_list_pars *l2, int *v);
t_list_pars		*verif_torus(t_list_pars *l2, int *v);
t_list_pars		*verif_triangle(t_list_pars *l2, int *v);
void			add_dif_spe(t_material *mat, char *s);
t_vector		ambient(t_hit hit, t_light *light);
t_vector		call_scene(t_all *all, int i, int j);
double			cbrt(double a);
double			cmp(double value, double min, double max);
void			color_bmp(t_bmp *bmp, t_vector color, int i, int j);
int				deal_key(int key, t_data *w);
t_vector		diffuse(t_shade_var var, t_hit *hit);
double			fade(double t);
int				fequal(double a, double b);
int				find_neg_intersection(t_ray ray, t_all *all,
	double *t0, double *t1);
void			fill_bmp(t_bmp *bmp);
t_vector		filter(t_vector color, int filter_var);
void			free_list(t_list_pars *lt);
void			free_all(t_all *all);
void			ft_add_light_back(t_light **lst, t_light *nw);
void			ft_add_obj_back(t_obj **lst, t_obj *ne);
int				ft_case_norm(t_quartic *q);
int				ft_case_one(double s[2], double *q);
int				ft_case_one1(double coeffs[4], double s[4], double *q,
double *p);
int				ft_case_three(double s[3], double *q, double *d);
int				ft_case_two2(double coeffs[4], double s[4], t_quartic *q);
int				ft_case_two(double s[3], double *q, double *p, double *cb_p);
int				ft_close(void *data);
int				ft_limit_ray(t_intersect_var var, double *t, t_ray *r,
	t_obj *obj);
int				ft_min_ray(double t1, double t2, double *t);
int				ft_solve_cubic(double w[4], double s[3]);
int				ft_solve_quadric(double c[3], double s[2]);
int				ft_solve_quartic(double w[5], double s[4]);
t_ray			get_ray(double u, double v, t_camera *c);
double			grad(int hash, double x, double y, double z);
void			graph(t_data *s);
void			graph_multi_thread(t_data *w, int i);
void			graph_mb(t_data *w);
void			graph1(t_data *w);
void			graph2(t_data *w);
void			graph3(t_data *w);
void			graph4(t_data *w);
void			hit_cone(t_hit *hit, t_obj *new, t_ray r);
void			hit_cylinder(t_hit *hit, t_obj *new, t_ray r);
void			hit_cube(t_hit *hit, t_obj *new, t_ray r);
void			hit_disk(t_hit *hit, t_obj *new, t_ray r);
void			hit_hyper(t_hit *hit, t_obj *new, t_ray r);
void			hit_parab(t_hit *hit, t_obj *new, t_ray r);
void			hit_plan(t_hit *hit, t_obj *new, t_ray r);
void			hit_sphere(t_hit *hit, t_obj *new, t_ray r);
void			hit_square(t_hit *hit, t_obj *new, t_ray r);
void			hit_trig(t_hit *hit, t_obj *new, t_ray r);
void			hit_torus(t_hit *hit, t_obj *new, t_ray r);
void			init_camera(t_camera *cam, t_vector lookfrom, t_vector lookat);
void			init_bmp(t_bmp *bmp);
void			insert_cam(t_list_pars **lt, t_all *all);
void			insert_color(t_vector *vector, char *str);
void			insert_cone(t_list_pars **lt, t_all *all);
void			insert_cube(t_list_pars **lt, t_all *all);
void			insert_cylinder(t_list_pars **lt, t_all *all);
void			insert_disk(t_list_pars **lt, t_all *all);
void			insert_hyperboloid(t_list_pars **lt, t_all *all);
void			insert_light(t_list_pars **lt, t_all *all);
void			insert_paraboloid(t_list_pars **lt, t_all *all);
void			insert_plane(t_list_pars **lt, t_all *all);
void			insert_sph(t_list_pars **lt, t_all *all);
void			insert_square(t_list_pars **lt, t_all *all);
void			insert_three_var(double *var1, double *var2,
	double *var3, char *str);
void			insert_torus(t_list_pars **lt, t_all *all);
void			insert_triangle(t_list_pars **lt, t_all *all);
void			insert_var(double *var1, double *var2, char *str);
void			insert_vector(t_vector *vector, char *str);
int				intersect_paraboloid(t_ray *r, t_obj *parab, double *t);
int				intersect_ray_cone(t_all *all, t_ray r, t_obj *cyl, double *t);
int				intersect_ray_cylinder(t_all *all, t_ray r,
	t_obj *cyl, double *t);
int				intersect_ray_disk(t_all *all, t_ray r, t_obj *d, double *t);
int				intersect_ray_plan(t_all *all, t_ray r, t_obj *p, double *t);
int				intersect_ray_sphere(t_all *all, t_ray r, t_obj *s, double *t);
float			intersect_ray_square(t_ray *r, t_obj *s, double *t);
int				intersect_ray_triangle(t_ray *r, t_obj *tri, double *t);
int				intersect_ray_hyper(t_ray *r, t_obj *hyper, double *t);
double			intersect_neg_obj(double t0, double t1, t_intersect_var var);
int				intersection_sphere(double *t0, double *t1, t_ray r, t_obj *s);
int				intersection_cone(double *t0, double *t1, t_ray r, t_obj *cone);
int				intersection_cylinder(double *t0, double *t1, t_ray r,
	t_obj *cyl);
void			initial_verif_obj(t_verif_obj *vo);
int				intersect_neg_plan(double t0_neg, double t1_neg, double t0,
	double *t);
int				is_diffuse(t_all *all, t_hit *hit);
int				intersect_ray_torus(t_ray *r, t_obj *tor, double *t);
int				intersect_ray_cube(t_ray *r, t_obj *cube, t_hit *hit);
void			init_mlx(t_data *w);
double			is_zero(double a);
int				length_line_nbr(char *str);
double			lerp(double t, double a, double b);
float			max(float f1, float f2);
float			max_min(float d1, float d2, float d3);
float			min_max(float m);
void			menu(t_data *w);
void			mlx_input(t_data *w);
void			menu_color(t_data *w);
void			motion_blur(t_data *w, t_vector **image);
int				mouse_move(int x, int y, t_data *w);
int				mouse_press(int button, int x, int y, t_data *w);
void			mlx_destroy(t_data *w);
double			noise(double x, double y, double z);
void			perlin(int *p, int *permutation);
double			pow1(double a);
double			pow2(double a);
double			rand_double();
int				ray_primary_intersection(t_all *all, t_ray r, t_hit *hit);
int				ray_secondary_intersection(t_all *all, t_ray *ray, t_hit *hit);
t_vector		raytracing_color(t_all *all, t_hit *hit);
t_vector		reflect(t_vector rdir, t_vector n);
t_vector		refract(t_vector rdir, t_vector normal, float ior);
t_vector		reflection(t_all *all, t_hit hit, t_ray ray, int depth);
int				rgb_color(t_vector color);
void			rotation(t_vector *axis, t_vector rot);
t_vector		refract_reflect(t_all *all, t_ray ray, int depth, t_hit hit);
int				ray_secondary2(t_all *all, t_ray r, t_hit *hit, t_obj *new);
t_vector		scene_alias(t_all *all, int i, int j);
t_vector		scene_dof(t_all *all, int i, int j);
t_vector		scene_normal(t_all *all, int i, int j);
t_vector		shade(t_all *all, t_ray ray, int depth);
t_vector		specular(t_shade_var var, t_all *all, t_hit *hit);
t_vector		set_perlin_noise(t_ray ray);
void			swap_f(float *xp, float *yp);
void			set_texture(t_hit *hit, t_ray ray);
t_vector		spot_lighting(t_all *all, t_shade_var var, t_hit *hit,
	t_light *l);
int				solve(double c[5], double *t0);
void			translation(t_vector *pos, t_vector trans);
float			turbulence(float x, float y, float z, float size);
t_vector		toon_shading(t_shade_var var, t_all *all, t_hit *hit);
t_vector		vector_rot_x(t_vector v, double rad);
t_vector		vector_rot_y(t_vector v, double rad);
t_vector		vector_rot_z(t_vector v, double rad);
t_vector		vector_add(t_vector v1, t_vector v2);
t_vector		vector_sub(t_vector v1, t_vector v2);
t_vector		vector_normalize(t_vector v);
t_vector		vector_cross(t_vector v0, t_vector v1);
t_vector		vector_scale(t_vector v, double s);
t_vector		vector_mult(t_vector v1, t_vector v2);
double			vector_dot(t_vector v1, t_vector v2);
int				verif_camera(t_list_pars **l);
int				verif_format_file(t_list_pars *lt);
int				verif_name_obj(char *str);
t_vector		value_damier(t_hit hit);
double			vector_norm(t_vector v);
int				verif_obj(t_list_pars **l);
int				wrong_format(int v);
void			window_drawing(t_data *w);
t_vector		xor_noise(t_vector color, int x, int y);
void			print_vec(t_vector vec, const char *name);
#endif
