/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboualav <aboualav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 12:12:16 by aboualav          #+#    #+#             */
/*   Updated: 2017/06/21 12:35:59 by rqueverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_STRUCTS_H
# define RT_STRUCTS_H

typedef struct			s_matrix
{
	char				type;
	double				m11;
	double				m12;
	double				m13;
	double				m14;
	double				m21;
	double				m22;
	double				m23;
	double				m24;
	double				m31;
	double				m32;
	double				m33;
	double				m34;
	double				m41;
	double				m42;
	double				m43;
	double				m44;
}						t_matrix;

typedef struct			s_img
{
	char				*data;
	int					sl;
	int					endian;
	int					bpp;
	void				*img;
	int					x;
	int					y;
}						t_img;

typedef struct			s_texture
{
	t_img				img;
	struct s_texture	*next;
	char				*path;
}						t_texture;

typedef struct			s_tf_list
{
	t_matrix			tf;
	struct s_tf_list	*previous;
	struct s_tf_list	*next;
	char				type;
}						t_tf_list;

typedef struct			s_vect
{
	double				x;
	double				y;
	double				z;
	double				w;
}						t_vect;

typedef struct			s_ray
{
	t_vect				ori;
	t_vect				dir;
}						t_ray;

typedef struct			s_cam
{
	t_vect				pos;
	t_vect				dir;
	t_vect				first_pixel_dir;
	double				cam_plane_dist;
	double				plane_height;
	double				plane_width;
	t_vect				left;
	t_vect				up;
}						t_cam;

typedef struct			s_color
{
	int					r;
	int					g;
	int					b;
}						t_color;

typedef	struct			s_light
{
	t_vect				pos;
	t_color				color;
	struct s_light		*next;
}						t_light;

typedef struct			s_plane
{
	t_color				color;
	t_tf_list			*tf_list;
	double				reflection;
	double				shine;
	double				off_x;
	double				off_y;
	double				scale_x;
	double				scale_y;
	double				dist;
	t_vect				normal;
	t_texture			*texture;
	char				texmodifier;
	t_texture			*bumpmap;
	struct s_obj		*cut;
	struct s_obj		**cutted_obj;
	int					cut_type;
}						t_plane;

typedef struct			s_triangle
{
	t_color				color;
	t_tf_list			*tf_list;
	double				reflection;
	double				shine;
	t_vect				normal;
	double				distance;
	t_vect				a;
	t_vect				b;
	t_vect				c;
	t_vect				ab;
	t_vect				ac;
	t_vect				ba;
	t_vect				bc;
	t_vect				cb;
	t_vect				ca;
	t_texture			*texture;
	t_texture			*bumpmap;
	struct s_obj		*cut;
}						t_triangle;

typedef struct			s_prism
{
	struct s_obj		**triangle;
	t_vect				a;
	t_vect				b;
	t_vect				c;
	t_vect				d;
	t_tf_list			*tf_list;
	int					*closest_triangle;
	t_color				color;
	double				reflection;
	double				shine;
	t_texture			*texture;
	t_texture			*bumpmap;
	struct s_obj		*cut;
}						t_prism;

typedef struct			s_cube
{
	struct s_obj		**triangle;
	t_vect				corner1;
	t_vect				corner2;
	t_tf_list			*tf_list;
	int					*closest_triangle;
	t_color				color;
	double				reflection;
	double				shine;
	t_texture			*texture;
	t_texture			*bumpmap;
	struct s_obj		*cut;
}						t_cube;

typedef struct			s_sphere
{
	t_color				color;
	t_tf_list			*tf_list;
	double				reflection;
	double				shine;
	double				off_x;
	double				off_y;
	double				scale_x;
	double				scale_y;
	double				radius;
	t_texture			*texture;
	char				texmodifier;
	t_texture			*bumpmap;
	struct s_obj		*cut;
}						t_sphere;

typedef struct			s_cylinder
{
	t_color				color;
	t_tf_list			*tf_list;
	double				reflection;
	double				shine;
	double				off_x;
	double				off_y;
	double				scale_x;
	double				scale_y;
	double				radius;
	t_texture			*texture;
	char				texmodifier;
	t_texture			*bumpmap;
	struct s_obj		*cut;
}						t_cylinder;

typedef struct			s_cone
{
	t_color				color;
	t_tf_list			*tf_list;
	double				reflection;
	double				shine;
	double				off_x;
	double				off_y;
	double				scale_x;
	double				scale_y;
	double				tan_alpha;
	t_texture			*texture;
	char				texmodifier;
	t_texture			*bumpmap;
	struct s_obj		*cut;
}						t_cone;

typedef struct			s_paraboloid
{
	t_color				color;
	t_tf_list			*tf_list;
	double				reflection;
	double				shine;
	double				off_x;
	double				off_y;
	double				scale_x;
	double				scale_y;
	t_texture			*texture;
	char				texmodifier;
	t_texture			*bumpmap;
	struct s_obj		*cut;
}						t_paraboloid;

typedef struct			s_hyperboloid
{
	t_color				color;
	t_tf_list			*tf_list;
	double				reflection;
	double				shine;
	double				off_x;
	double				off_y;
	double				scale_x;
	double				scale_y;
	int					sheets;
	t_texture			*texture;
	char				texmodifier;
	t_texture			*bumpmap;
	struct s_obj		*cut;
}						t_hyperboloid;

typedef struct			s_csg
{
	struct s_obj		*first;
	struct s_obj		*second;
	int					operation;
}						t_csg;

typedef union			u_solid
{
	t_sphere			*sphere;
	t_plane				*plane;
	t_cylinder			*cylinder;
	t_cone				*cone;
	t_triangle			*triangle;
	t_prism				*prism;
	t_cube				*cube;
	t_paraboloid		*paraboloid;
	t_hyperboloid		*hyperboloid;
	t_csg				*csg;
}						t_solid;

typedef struct			s_obj
{
	int					type;
	double				*reflectionx;
	double				*shinex;
	t_solid				*solid;
	struct s_obj		*cut;
	struct s_obj		*next;
}						t_obj;

typedef struct			s_csg_condition
{
	int					in_neg;
	int					in_pos;
	int					neg_behind;
	int					neg_front;
	int					out;
	int					in;
	int					c1;
	int					c2;
	int					c3;
	int					c4;
	int					c5;
	int					c6;
	int					p1;
	int					p2;
	int					p3;
}						t_csg_condition;

typedef struct			s_csg_data
{
	t_obj				*one;
	t_obj				*two;
	t_ray				default_ray;
	t_ray				ray_one;
	t_ray				ray_two;
	double				p[3];
	double				n[3];
}						t_csg_data;

typedef struct			s_research
{
	t_csg_condition		c;
	t_obj				*current_obj;
	t_obj				*closest_obj;
	double				dist[3];
	double				final_dist;
	t_ray				modified_ray;
	t_ray				final_ray;
}						t_research;

typedef	struct			s_record
{
	t_vect				n_pos;
	t_vect				refl_dir;
	t_vect				to_light_dir;
	t_ray				refl_ray;
	t_ray				to_light_ray;
	t_ray				ray;
	t_vect				normal;
	float				dist_to_light;
	double				cosinus;
	double				dist;
	int					type;
	t_thread			*current_thread;
	t_obj				*obj;
	t_color				color;
	t_vect				oldnorm;
}						t_record;

typedef struct			s_cut_condition
{
	int					c1;
	int					c2;
	int					c3;
	int					c4;
	int					c5;
	int					c6;
	int					p1;
	int					p2;
	int					p3;
	int					in;
	int					f;
	int					b;
}						t_cut_condition;

typedef struct			s_cut
{
	double				plane[3];
	double				final_dist;
	double				dot;
	t_ray				object_ray;
	t_ray				modified_ray;
	t_obj				*current_obj;
	t_obj				*cutted_obj;
	double				final_dist_p;
	t_obj				*closest_negative;
	t_ray				closest_negative_ray;
	double				final_dist_n;
	t_obj				*closest_positive;
	t_ray				closest_positive_ray;
	t_cut_condition		c;
	t_cut_condition		c_p;
	t_cut_condition		c_n;
}						t_cut;

typedef struct			s_func
{
	void				**get_obj_tf_list;
	void				**get_obj_normal;
	void				**get_obj_color;
	void				**get_obj_n;
	void				**post_pro;
}						t_func;

typedef struct			s_data
{
	int					height;
	int					width;
	void				*mlx;
	void				*win;
	t_img				*img;
	t_obj				*obj;
	t_func				*func;
	t_cam				cam;
	t_light				*light_list;
	t_texture			*texturelist;
	double				x;
	double				y;
	double				aa_lvl;
	double				dpp;
	char				reflections;
	int					tld;
	float				ambient;
	t_thread			th[8];
}						t_data;

typedef struct			s_p_cache
{
	t_data				*d;
	char				scope;
	int					pos;
	int					linelen;
	char				*line;
	char				prec;
	char				*filename;
	char				*param_name;
	char				**params;

}						t_p_cache;

typedef struct			s_scene
{
	char				*name;
	t_data				*d;
	struct s_scene		*next;
}						t_scene;

typedef struct			s_butt
{
	int					xmin;
	int					xmax;
	int					ymin;
	int					ymax;
	int					moon;
	struct s_butt		*next;
}						t_butt;

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	void				*img_wel;
	void				*img_bg;
	void				*img_cmd;
	void				*img_loading;
	void				*img_rendering;
	t_scene				*lst_scene;
	t_data				*current_scene;
	int					page;
	int					page_m;
	int					lst_size;
	int					in_menu;
	t_butt				*butt_lst;
	int					w;
	int					h;
	int					rendering;
	int					loading;
	int					cmd;
}						t_env;
#endif
