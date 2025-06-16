/* debug.h - Debug utilities for miniRT */
#ifndef DEBUG_H
# define DEBUG_H

# include "mini_rt.h"
# include <stdio.h>

/* Debug levels */
# define DBG_LEVEL_NONE  0
# define DBG_LEVEL_ERROR 1
# define DBG_LEVEL_WARN  2
# define DBG_LEVEL_INFO  3
# define DBG_LEVEL_TRACE 4

/* Set your desired debug level here */
# define CURRENT_DEBUG_LEVEL DBG_LEVEL_INFO

/* Color codes for terminal output */
# define COLOR_RED     "\x1b[31m"
# define COLOR_GREEN   "\x1b[32m"
# define COLOR_YELLOW  "\x1b[33m"
# define COLOR_BLUE    "\x1b[34m"
# define COLOR_MAGENTA "\x1b[35m"
# define COLOR_CYAN    "\x1b[36m"
# define COLOR_RESET   "\x1b[0m"

/* Debug macros */
# if CURRENT_DEBUG_LEVEL >= DBG_LEVEL_ERROR
#  define DEBUG_ERROR(fmt, ...) fprintf(stderr, COLOR_RED "[ERROR] " COLOR_RESET fmt "\n", ##__VA_ARGS__)
# else
#  define DEBUG_ERROR(fmt, ...)
# endif

# if CURRENT_DEBUG_LEVEL >= DBG_LEVEL_WARN
#  define DEBUG_WARN(fmt, ...) fprintf(stderr, COLOR_YELLOW "[WARN] " COLOR_RESET fmt "\n", ##__VA_ARGS__)
# else
#  define DEBUG_WARN(fmt, ...)
# endif

# if CURRENT_DEBUG_LEVEL >= DBG_LEVEL_INFO
#  define DEBUG_INFO(fmt, ...) fprintf(stderr, COLOR_BLUE "[INFO] " COLOR_RESET fmt "\n", ##__VA_ARGS__)
# else
#  define DEBUG_INFO(fmt, ...)
# endif

# if CURRENT_DEBUG_LEVEL >= DBG_LEVEL_TRACE
#  define DEBUG_TRACE(fmt, ...) fprintf(stderr, COLOR_CYAN "[TRACE] " COLOR_RESET fmt "\n", ##__VA_ARGS__)
# else
#  define DEBUG_TRACE(fmt, ...)
# endif

/* Function prototypes for miniRT debugging */
void print_scene(t_scene *scene);
void print_vector(t_tuples vec, const char *name);
void print_camera(t_camera *cam);
void print_lights(t_light_list *light_list);
void print_objects(t_obj_list *obj_list);
void validate_scene(t_scene *scene);
// void debug_ray(t_ray ray, const char *description);
// void debug_intersection(t_hit *hit, const char *description);
// void debug_color(t_color color, const char *description);

#endif /* DEBUG_H */