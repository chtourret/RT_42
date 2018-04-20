/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_proto.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboualav <aboualav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 18:33:58 by aboualav          #+#    #+#             */
/*   Updated: 2017/06/21 12:36:03 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PROTO_H
# define RT_PROTO_H

/*
** Tools
*/

void			swap_double(double *a, double *b);

/*
** Main function
*/

void			raytracer(t_data *d);

/*
** Intersection computing
*/

void			get_plane_n(t_ray ray, t_obj *obj,
		t_thread *thread, double *dist);
void			n_ray_plane(t_ray ray, t_obj *obj,
		t_thread *thread, double *dist);

void			get_sphere_n(t_ray ray, t_obj *obj,
		t_thread *thread, double *dist);
void			n_ray_sphere(t_ray ray, t_obj *obj,
		t_thread *thread, double *dist);

void			get_triangle_n(t_ray ray, t_obj *obj,
		t_thread *thread, double *dist);
void			n_ray_triangle(t_ray ray, t_obj *obj,
		t_thread *thread, double *dist);

void			get_cone_n(t_ray ray, t_obj *obj,
		t_thread *thread, double *dist);
void			n_ray_cone(t_ray ray, t_obj *obj,
		t_thread *thread, double *dist);

void			get_cylinder_n(t_ray ray, t_obj *obj,
		t_thread *thread, double *dist);
void			n_ray_cylinder(t_ray ray, t_obj *obj,
		t_thread *thread, double *dist);

void			get_cube_n(t_ray ray, t_obj *obj,
		t_thread *thread, double *dist);
void			n_ray_cube(t_ray ray, t_obj *obj,
		t_thread *thread, double *dist);

void			get_prism_n(t_ray ray, t_obj *obj,
		t_thread *thread, double *dist);
void			n_ray_prism(t_ray ray, t_obj *obj,
		t_thread *thread, double *dist);

void			get_paraboloid_n(t_ray ray, t_obj *obj,
		t_thread *thread, double *dist);
void			n_ray_paraboloid(t_ray ray, t_obj *obj,
		t_thread *thread, double *dist);
void			get_hyperboloid_n(t_ray ray, t_obj *obj,
		t_thread *thread, double *dist);
void			n_ray_hyperboloid(t_ray ray, t_obj *obj,
		t_thread *thread, double *dist);

void			get_csg_n(t_research *r, t_thread *thread, t_data *d);
t_solid			*get_csg_solid(void *p);
/*
** Img init
*/

t_img			*init_img(void *mlx, int length, int height);
void			putpixel(int x, int y, unsigned int color, t_img *img);

t_texture		*get_texture_data(t_data *d, char *path);
t_record		*find_n(t_ray ray, t_data *d, t_thread *thread);
t_color			*get_color_at(t_data *d, t_record *info);
t_color			get_pixel_color(t_data *d, t_record *info, int type);

/*
** Free functions
*/

void			free_env(t_env *e);
void			free_prec_split(t_p_cache *cache);
void			free_data(t_data *d);
t_img			*free_img(void *mlx, t_img *img);
t_obj			*free_obj(t_obj **begin_light_list);
t_sphere		*free_sphere(t_sphere *sphere);
t_plane			*free_plane(t_plane *plane);
t_triangle		*free_triangle(t_triangle *triangle);
t_cylinder		*free_cylinder(t_cylinder *cylinder);
t_cone			*free_cone(t_cone *cone);
t_csg			*free_csg(t_csg *csg);
void			free_info(t_record *info);
t_tf_list		*free_tf_list(t_tf_list **begin_tf_list);
t_light			*free_light_list(t_light **begin_light_list);
t_func			*free_functions(t_func *func);
void			free_scene_list(t_scene *s);
void			free_butt(t_butt *butt_lst);
t_cube			*free_cube(t_cube *cube);
t_hyperboloid	*free_hyperboloid(t_hyperboloid *hyperboloid);
t_paraboloid	*free_paraboloid(t_paraboloid *paraboloid);
t_prism			*free_prism(t_prism *prism);
t_csg			*free_csg(t_csg *csg);
void			free_texture(void *mlx, t_texture *begin_texture);
t_obj			*free_cut(t_obj **begin_cut);
void			select_free_obj(t_obj *tmp);

/*
** Color functions
*/

unsigned char	moy(t_color color);
t_color			set_color(int r, int g, int b);
void			color_add(t_color *c1, t_color c2);
t_color			copy_color(t_color color);
void			color_divide(t_color *c, double d);
void			color_multiply(t_color *c1, t_color c2);
void			color_scale(t_color *color, double scalar);
void			color_add_nolimit(t_color *c1, t_color c2);
int				get_color(t_color color);
int				get_obj_color(t_obj *obj);
t_ray			calculate_ray(t_data *d, double x, double y, t_thread *thread);
void			calculate_refl_ray(t_record *info);
void			add_refls(t_data *d, t_record *info,
		t_color *final_color);
void			specular_color(t_record *info, t_color *final_color,
		t_light *light_list);
void			add_diffuse_and_specular(t_record *info, t_data *d,
		t_light *light_list, t_color *final_color);

void			ft_error(void);
void			ft_malloc_error(void);

t_texture		*texturegetter(char type, t_obj *obj);
t_texture		*bumpmapgetter(char type, t_obj *obj);
char			texmodifiergetter(char type, t_obj *obj);
double			texscalex(char type, t_obj *obj, double in);
double			texscaley(char type, t_obj *obj, double in);
double			texoffx(char type, t_obj *obj, double in);
double			texoffy(char type, t_obj *obj, double in);

/*
** Scenes create -> Init
*/

t_func			*init_function(void);

t_cam			init_cam(t_vect pos, t_vect dir);
void			create_cam(t_cam *cam, t_data *d);

t_data			*init_data(int argc, char **argv);
t_obj			*create_default_obj(t_data *d);
void			init_info_zero(t_record *info);

t_light			*init_light();
void			push_light(t_light **begin_light, t_light *light);

void			create_default_lights(t_data *d);
t_solid			*init_solid(void *obj, char type);

t_ray			init_ray(t_vect ori, t_vect dir);

t_sphere		*init_sphere(double rad);
void			apply_color_sphere(t_sphere *sphere, t_color color,
		double reflection, double shine);
t_obj			*push_sphere(t_obj **begin_obj, t_sphere *sphere);

t_plane			*init_plane(void);
t_obj			*add_plane(t_plane *plane);
void			apply_color_plane(t_plane *plane, t_color color,
		double reflection, double shine);
t_obj			*push_plane(t_obj **begin_obj, t_plane *plane);

t_plane			*init_plane(void);
t_obj			*push_plane(t_obj **begin_obj, t_plane *plane);
void			apply_color_plane(t_plane *plane,
		t_color color, double reflection, double shine);

t_cone			*init_cone(double alpha);
t_obj			*push_cone(t_obj **begin_obj, t_cone *cone);
void			apply_color_cone(t_cone *cone,
		t_color color, double reflection, double shine);

t_cylinder		*init_cylinder(void);
t_obj			*push_cylinder(t_obj **begin_obj, t_cylinder *cylinder);
void			apply_color_cylinder(t_cylinder *cylinder,
		t_color color, double reflection, double shine);

t_obj			*add_triangle(t_triangle *triangle);
t_triangle		*init_triangle(void);
t_triangle		*init_tri_w_p(t_vect a, t_vect b, t_vect c);
void			apply_color_triangle(t_triangle *triangle,
		t_color color, double reflection, double shine);

t_triangle		*compute_triangle(t_triangle *triangle);
t_vect			compute_triangle_normal(t_triangle *t);
void			calculate_sides(t_triangle *triangle);
t_obj			*push_triangle(t_obj **begin_obj, t_triangle *triangle);

t_cube			*init_cube(void);
t_cube			*compute_cube(t_cube *cube);
t_obj			*push_cube(t_obj **begin_obj, t_cube *cube);

t_prism			*init_prism(void);
t_prism			*compute_prism(t_prism *prism);
t_obj			*push_prism(t_obj **begin_obj, t_prism *prism);

t_paraboloid	*init_paraboloid(void);
t_obj			*push_paraboloid(t_obj **begin_obj, t_paraboloid *paraboloid);

t_hyperboloid	*init_hyperboloid(int sheets);
t_obj			*push_hyperboloid(t_obj **begin_obj, t_hyperboloid *hyper);

t_csg			*init_csg();
t_obj			*push_csg(t_obj **begin_obj, t_csg *csg);
/*
** Matrix
*/

t_matrix		init_xrotation_matrix(double theta);
t_matrix		init_yrotation_matrix(double theta);
t_matrix		init_zrotation_matrix(double theta);
t_matrix		init_translation_matrix(double x, double y, double z);
t_matrix		init_scale_matrix(double x, double y, double z);
t_matrix		init_xyzrotation_matrix(double theta, double x,
		double y, double z);
t_vect			get_bumped_vect(t_vect normal, t_vect transformed);

void			push_xrot_tf(t_tf_list **blist, double deg);
void			push_yrot_tf(t_tf_list **blist, double deg);
void			push_zrot_tf(t_tf_list **blist, double deg);
void			push_trans_tf(t_tf_list **blist, double x, double y, double z);
void			push_scale_tf(t_tf_list **blist, double x, double y, double z);
t_tf_list		*add_xrot_tf(double deg);
t_tf_list		*add_yrot_tf(double deg);
t_tf_list		*add_zrot_tf(double deg);
t_tf_list		*add_trans_tf(t_vect t);
t_tf_list		*add_scale_tf(double x, double y, double z);

void			apply_matrix(t_matrix matrix, t_vect *v);
t_matrix		get_inverse_matrix(t_matrix m);

void			apply_tf(t_obj *obj, t_vect *v, t_data *d, int type);
void			apply_inverse_tf(t_obj *obj, t_vect *v, t_data *d);

/*
** Get object values
*/

void			define_obj_color(t_record *info);
t_color			get_plane_color(t_obj *obj);
t_color			get_cylinder_color(t_obj *obj);
t_color			get_sphere_color(t_obj *obj);
t_color			get_cone_color(t_obj *obj);
t_color			get_triangle_color(t_obj *obj);
t_color			get_prism_color(t_obj *obj);
t_color			get_cube_color(t_obj *obj);
t_color			get_paraboloid_color(t_obj *obj);
t_color			get_hyperboloid_color(t_obj *obj);

t_tf_list		*get_cylinder_tf_list(t_obj *obj);
t_tf_list		*get_sphere_tf_list(t_obj *obj);
t_tf_list		*get_plane_tf_list(t_obj *obj);
t_tf_list		*get_cone_tf_list(t_obj *obj);
t_tf_list		*get_triangle_tf_list(t_obj *obj);
t_tf_list		*get_prism_tf_list(t_obj *obj);
t_tf_list		*get_cube_tf_list(t_obj *obj);
t_tf_list		*get_paraboloid_tf_list(t_obj *obj);
t_tf_list		*get_hyperboloid_tf_list(t_obj *obj);
t_vect			define_obj_normal(t_record *info, t_data *d, t_thread *thread);
t_vect			get_cylinder_normal(t_obj *obj, t_vect n, t_thread *thread);
t_vect			get_sphere_normal(t_obj *obj, t_vect n, t_thread *thread);
t_vect			get_plane_normal(t_obj *obj, t_vect n, t_thread *thread);
t_vect			get_cone_normal(t_obj *obj, t_vect n, t_thread *thread);
t_vect			get_triangle_normal(t_obj *obj, t_vect n, t_thread *thread);
t_vect			get_prism_normal(t_obj *obj, t_vect n, t_thread *thread);
t_vect			get_cube_normal(t_obj *obj, t_vect n, t_thread *thread);
t_vect			get_paraboloid_normal(t_obj *obj, t_vect n, t_thread *thread);
t_vect			get_hyperboloid_normal(t_obj *obj, t_vect n, t_thread *thread);

t_solid			*get_cone_solid(void *p);
t_solid			*get_sphere_solid(void *p);
t_solid			*get_plane_solid(void *p);
t_solid			*get_cylinder_solid(void *p);
t_solid			*get_triangle_solid(void *p);
t_solid			*get_prism_solid(void *p);
t_solid			*get_cube_solid(void *p);
t_solid			*get_paraboloid_solid(void *p);
t_solid			*get_hyperboloid_solid(void *p);
t_solid			*get_csg_solid(void *p);

/*
** Vector
*/

t_vect			init_vector(double x, double y, double z, double w);
void			negative_vector(t_vect *v);
double			vector_magnitude(t_vect v);
void			normalize_vector(t_vect *v);
void			mult_vector(t_vect *v, double d);
void			add_to_vector(t_vect *v1, t_vect v2);
double			dot_product_vector(t_vect v1, t_vect v2);
t_vect			cross_product_vector(t_vect v1, t_vect v2);
t_vect			copy_vector(t_vect v);
void			substract_to_vector(t_vect *v1, t_vect v2);

/*
** MLX
*/

int				welcome_to_rt(t_env *e);
void			remake(t_data *d);
void			display_again(t_data *d);
void			reload_env(t_env *e);
int				ft_close_cross(t_env *e);

int				events_key(int keycode, t_env *e);
int				events_key_menu(int keycode, t_env *e);
int				events_key_scene(int keycode, t_data *d);
int				events_mouse(int button, int x, int y, t_env *e);
int				events_mouse_menu(int button, int x, int y, t_env *e);
int				events_mouse_scene(int button, int x, int y, t_data *d);

void			event_mov_fwd(t_data *d);
void			event_mov_bwd(t_data *d);
void			event_mov_strafe_lft(t_data *d);
void			event_mov_strafe_rgt(t_data *d);
void			event_mov_dwn(t_data *d);
void			event_mov_up(t_data *d);
void			event_mov_look_left(t_data *d);
void			event_mov_look_right(t_data *d);
void			event_mov_look_up(t_data *d);
void			event_mov_look_down(t_data *d);
void			idostuff(t_data *d);
void			add_eblouissement(t_data *d);

t_scene			*get_scene_list(void);
void			load_scenes(t_env *e);
void			foreach_d_thumbnail(t_env *e);
void			display_scenes(t_env *e);
void			init_data_zero(t_data *d);
t_env			*init_env(void);
void			init_default_scene(t_env *e);
int				select_scene(t_env *e, int k);
t_butt			*init_butt(void);
int				clic_scene(t_env *e, int x, int y);
void			print_page_string(t_env *e);
char			*get_scene_name(int nb, char *name);

/*
** POST PRO
*/

void			**init_post_pro(void);
t_color			img_get_hit(double x, double y, t_texture *tex, char alter);
t_color			img_pull_pixel(int x, int y, t_img *img);
t_img			*img_map_pixel(t_data *d, int (*f)(t_color));
void			img_recolor(t_data *d, int (*f)(t_color));
int				img_b_n_w(t_color c);
int				img_sepia(t_color c);
int				img_negative(t_color c);
void			img_anaglyph(t_data *d);
void			generate_scene(t_data *d, int argc, char **argv);
void			ft_parsing_error(int linenbr, char *line, char *filename);
void			lexer(int fd, char *filename);
void			cache_init(t_p_cache *cache, char *filename);

/*
** Q
*/
void			transform(t_tf_list **lst, char *param_name, char **params,
		t_p_cache *cache);
void			attributeboth(double *xa, double *ya, float xb, float yb);
int				tf(char *lolilol, int line, t_p_cache *cache);
char			isempty(char *str);
void			parser(int fd, t_data *d, char *filename);
void			manage_root_parameters(t_p_cache *cache, t_data *d);
void			declarator_redirect(int fd, t_p_cache *cache,
		t_obj **lst, t_obj **cut);
char			line_identifier(t_p_cache *cache);
void			populatesphere(int fd, t_p_cache *c, t_obj **lst);
void			manage_sphere_params(t_p_cache *cache, t_sphere *sphere);
void			populatecylinder(int fd, t_p_cache *c, t_obj **lst);
void			manage_cylinder_params(t_p_cache *cache, t_cylinder *cylinder);
void			populatecone(int fd, t_p_cache *cache, t_obj **lst);
void			manage_cone_params(t_p_cache *cache, t_cone *cone);
void			populateplane(int fd, t_p_cache *cache, t_obj **lst);
void			manage_plane_params(t_p_cache *cache, t_plane *plane);
void			populatetriangle(int fd, t_p_cache *cache, t_obj **lst);
void			manage_triangle_params(t_p_cache *cache, t_triangle *triangle);
void			populateprism(int fd, t_p_cache *cache, t_obj **lst);
void			manage_prism_params(t_p_cache *cache, t_prism *prism);
void			populatecube(int fd, t_p_cache *cache, t_obj **lst);
void			manage_cube_params(t_p_cache *cache, t_cube *cube);
void			populateparaboloid(int fd, t_p_cache *cache, t_obj **lst);
void			manage_paraboloid_params(t_p_cache *cache,
		t_paraboloid *paraboloid);
void			populatehyperboloid(int fd, t_p_cache *cache, t_obj **lst);
void			manage_hyperboloid_params(t_p_cache *cache,
		t_hyperboloid *hyperboloid);
void			populatelight(int fd, t_p_cache *cache, t_light **lst);
void			manage_light_params(t_p_cache *cache, t_light *light);
void			populatecsg(int fd, t_p_cache *cache, t_obj **lst,
		char booleantype);
void			disect_param(char *str, char **param, char ***args);
char			chk(char **params, int n,
		int (*f)(char *, int, struct s_p_cache *), t_p_cache *cache);
void			populatecamera(int fd, t_p_cache *cache);
void			manage_camera_params(t_p_cache *cache, t_cam *cam);
int				parsetest_vector(char *line, int linenbr, t_p_cache *cache);
t_vect			get_bumped_vect(t_vect normal, t_vect transformed);
int				one_double_required(char *name);
int				three_double_required(char *name);
int				accepted_types(char *str, int scope);

/*
** CUT OBJECTS
*/

void			save_dist(t_research *r, t_cut *cut, t_thread *thread);
void			select_negative_case(t_research *r, t_cut *cut);
void			select_positive_case(t_research *r, t_cut *cut);
void			select_special_case(t_research *r, t_cut *cut);
void			save_negative_plane(t_research *r, t_cut *cut);
void			save_positive_plane(t_research *r, t_cut *cut);
void			save_cutted_object(t_research *r, t_cut *cut);
void			save_nothing(t_research *r, t_cut *cut);
int				keep_plane(t_cut *cut);
int				keep_nothing(t_research *r, t_cut *cut);
int				research_in_cone(t_research *r, t_cut *cut);
int				research_in_others(t_research *r, t_cut *cut);
void			init_cut_condition_cone(t_research *r, t_cut *cut);
void			init_cut_condition_others(t_research *r, t_cut *cut);
void			if_plane_cut_an_object(t_data *d, t_record *info,
		t_thread *thread);
void			init_var(t_research *r, t_ray ray);
t_vect			find_n_pos(t_ray ray, t_record *info);
void			find_n_dist(t_research *r, t_data *d, t_thread *thread);
void			check_cut(t_research *r, t_data *d, t_thread *thread);
void			init_csg_data(t_csg_data *c_data, t_research *r);
void			init_conditions_diff(t_research *r, double *p, double *n,
		int type);
int				check_diff(t_research *r, t_research *rp, t_research *rn);
int				check_inter(t_research *r, t_research *rp, t_research *rn);
int				check_add(t_research *r, t_research *rp, t_research *rn);

/*
** DEBUG
*/

void			print_data(t_data *d);
void			vector_state(t_vect v, char *s);
void			init_default_csg(t_data *d);
void			print_objects(t_data *d);

#endif
