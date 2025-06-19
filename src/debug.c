/* debug.c - Implementation of debug utilities for miniRT */
#include "debug.h"

void print_vector(t_tuples vec, const char *name)
{
    printf("%s%s:%s (%.3f, %.3f, %.3f)\n",
           COLOR_CYAN, name, COLOR_RESET, vec.x, vec.y, vec.z);
}

void print_camera(t_camera *cam)
{
    if (!cam)
    {
        DEBUG_ERROR("Camera is NULL");
        return;
    }

    printf("\n%s=== Camera Debug ===%s\n", COLOR_GREEN, COLOR_RESET);
    print_vector(cam->pos, "Position");
    print_vector(cam->orientation_vector, "Orientation Vector");
    printf("%sFOV:%s %d degrees\n", COLOR_YELLOW, COLOR_RESET, cam->fov);
    printf("%s===================%s\n\n", COLOR_GREEN, COLOR_RESET);
}

void print_lights(t_light_list *light_list)
{
    if (!light_list || !light_list->head)
    {
        printf("\n%s=== Lights Debug ===%s\n", COLOR_YELLOW, COLOR_RESET);
        printf("%sNo lights found%s\n", COLOR_RED, COLOR_RESET);
        printf("\n%s===================%s\n\n", COLOR_YELLOW, COLOR_RESET);
        return;
    }

    printf("\n%s=== Lights Debug ===%s\n", COLOR_YELLOW, COLOR_RESET);
    printf("%sLight List Size:%s %zd\n", COLOR_MAGENTA, COLOR_RESET, light_list->size);

    t_light *current = light_list->head;
    int light_index = 0;

    while (current)
    {
        printf("\n%sLight %d:%s\n", COLOR_CYAN, light_index++, COLOR_RESET);
        print_vector(current->pos, "Position");
        printf("%sBrightness:%s %.2f\n", COLOR_MAGENTA, COLOR_RESET, current->brightness);
        printf("%sColor:%s (%.3f, %.3f, %.3f)\n",
               COLOR_BLUE, COLOR_RESET,
               current->rgb.r, current->rgb.g, current->rgb.b);

        current = current->next;
    }

    printf("\n%s===================%s\n\n", COLOR_YELLOW, COLOR_RESET);
}

void print_scene(t_scene *scene)
{
    if (!scene)
    {
        DEBUG_ERROR("Scene is NULL");
        return;
    }

    printf("\n%s======= SCENE DEBUG =======%s\n", COLOR_GREEN, COLOR_RESET);

    /* Print ambient lighting */
    printf("%sAmbient Light:%s\n", COLOR_YELLOW, COLOR_RESET);
    printf("  Ratio: %.3f\n", scene->ambi_light.ratio);
    printf("  Color: (%.3f, %.3f, %.3f)\n",
           scene->ambi_light.rgb.r, scene->ambi_light.rgb.g, scene->ambi_light.rgb.b);

    /* Print camera */
    print_camera(&scene->camera);

    /* Print lights - now handles t_light_list */
    print_lights(scene->light_list);

    /* Print objects */
    print_objects(scene->obj_list);

    printf("%s==========================%s\n\n", COLOR_GREEN, COLOR_RESET);
}

void print_objects(t_obj_list *obj_list)
{
    if (!obj_list || !obj_list->head)
    {
        printf("\n%s=== Objects Debug ===%s\n", COLOR_GREEN, COLOR_RESET);
        printf("%sNo objects found%s\n", COLOR_RED, COLOR_RESET);
        printf("\n%s===================%s\n\n", COLOR_GREEN, COLOR_RESET);
        return;
    }

    printf("\n%s=== Objects Debug ===%s\n", COLOR_GREEN, COLOR_RESET);
    printf("%sObject List Size:%s %zd\n", COLOR_MAGENTA, COLOR_RESET, obj_list->size);

    t_obj_node *current = obj_list->head;
    int obj_index = 0;

    while (current)
    {
        printf("\n%sObject %d:%s ", COLOR_CYAN, obj_index++, COLOR_RESET);

        switch (current->type)
        {
            case SPHERE:
                printf("%s[SPHERE]%s\n", COLOR_BLUE, COLOR_RESET);
                if (current->data && current->data->sphere)
                {
                    print_vector(current->data->sphere->pos, "Position");
                    printf("%sDiameter:%s %.3f\n", COLOR_YELLOW, COLOR_RESET, current->data->sphere->diameter);
                    printf("%sColor:%s (%.3f, %.3f, %.3f)\n", COLOR_MAGENTA, COLOR_RESET,
                           current->data->sphere->rgb.r, current->data->sphere->rgb.g, current->data->sphere->rgb.b);
                }
                break;

            case PLANE:
                printf("%s[PLANE]%s\n", COLOR_BLUE, COLOR_RESET);
                if (current->data && current->data->plane)
                {
                    print_vector(current->data->plane->pos, "Position");
                    print_vector(current->data->plane->axis, "Normal");
                    printf("%sColor:%s (%.3f, %.3f, %.3f)\n", COLOR_MAGENTA, COLOR_RESET,
                           current->data->plane->rgb.r, current->data->plane->rgb.g, current->data->plane->rgb.b);
                }
                break;

            case CYLINDER:
                printf("%s[CYLINDER]%s\n", COLOR_BLUE, COLOR_RESET);
                if (current->data && current->data->cylinder)
                {
                    print_vector(current->data->cylinder->pos, "Position");
                    print_vector(current->data->cylinder->axis, "Axis");
                    printf("%sDiameter:%s %.3f\n", COLOR_YELLOW, COLOR_RESET, current->data->cylinder->diameter);
                    printf("%sHeight:%s %.3f\n", COLOR_YELLOW, COLOR_RESET, current->data->cylinder->height);
                    printf("%sColor:%s (%.3f, %.3f, %.3f)\n", COLOR_MAGENTA, COLOR_RESET,
                           current->data->cylinder->rgb.r, current->data->cylinder->rgb.g, current->data->cylinder->rgb.b);
                }
                break;

            default:
                printf("%s[UNKNOWN]%s\n", COLOR_RED, COLOR_RESET);
                break;
        }

        current = current->next;
    }

    printf("\n%s===================%s\n\n", COLOR_GREEN, COLOR_RESET);
}

void validate_scene(t_scene *scene)
{
    if (!scene)
    {
        DEBUG_ERROR("Scene validation failed: NULL scene");
        return;
    }

    DEBUG_INFO("Validating scene structure...");

    /* Validate ambient light */
    if (scene->ambi_light.ratio < 0.0 || scene->ambi_light.ratio > 1.0)
        DEBUG_WARN("Ambient light ratio %.2f is outside valid range [0.0, 1.0]",
                   scene->ambi_light.ratio);

    /* Validate camera */
    if (scene->camera.fov <= 0 || scene->camera.fov >= 180)
        DEBUG_WARN("Camera FOV %d is outside typical range (0, 180)",
                   scene->camera.fov);

    /* Validate lights - now handles t_light_list */
    int light_count = 0;
    if (scene->light_list && scene->light_list->head)
    {
        t_light *current_light = scene->light_list->head;
        while (current_light)
        {
            light_count++;
            if (current_light->brightness < 0.0 || current_light->brightness > 1.0)
                DEBUG_WARN("Light %d brightness %.2f is outside valid range [0.0, 1.0]",
                           light_count - 1, current_light->brightness);
            current_light = current_light->next;
        }

        /* Validate light list integrity */
        if (light_count != scene->light_list->size)
            DEBUG_WARN("Light list size mismatch: counted %d, list->size = %zd",
                       light_count, scene->light_list->size);
    }

    /* Count objects */
    int object_count = 0;
    if (scene->obj_list && scene->obj_list->head)
    {
        t_obj_node *obj = scene->obj_list->head;
        while (obj)
        {
            object_count++;
            obj = obj->next;
        }
    }

    DEBUG_INFO("Scene validation complete: %d lights, %d objects", light_count, object_count);
}

// void debug_ray(t_ray ray, const char *description)
// {
//     printf("\n%s=== Ray Debug: %s ===%s\n", COLOR_CYAN, description, COLOR_RESET);
//     print_vector(ray.origin, "Origin");
//     print_vector(ray.direction, "Direction");
//     printf("%s========================%s\n\n", COLOR_CYAN, COLOR_RESET);
// }

// void debug_intersection(t_hit *hit, const char *description)
// {
//     if (!hit)
//     {
//         printf("\n%s=== Intersection Debug: %s ===%s\n", COLOR_RED, description, COLOR_RESET);
//         printf("%sNo intersection%s\n", COLOR_RED, COLOR_RESET);
//         printf("%s==============================%s\n\n", COLOR_RED, COLOR_RESET);
//         return;
//     }

//     printf("\n%s=== Intersection Debug: %s ===%s\n", COLOR_GREEN, description, COLOR_RESET);
//     printf("%sDistance:%s %.3f\n", COLOR_YELLOW, COLOR_RESET, hit->t);
//     print_vector(hit->point, "Hit Point");
//     print_vector(hit->normal, "Normal");
//     printf("%s==============================%s\n\n", COLOR_GREEN, COLOR_RESET);
// }

void debug_color(t_rgb color, const char *description)
{
    printf("%s%s:%s (%.3f, %.3f, %.3f)\n",
           COLOR_MAGENTA, description, COLOR_RESET,
           color.r, color.g, color.b);
}

void debug_matrix_m2(t_m2 *m2, const char *description)
{
    if (!m2)
    {
        DEBUG_ERROR("Matrix M2 is NULL: %s", description);
        return;
    }

    printf("\n%s=== M2 Matrix Debug: %s ===%s\n", COLOR_CYAN, description, COLOR_RESET);
    printf("%sSize:%s %zd columns\n", COLOR_YELLOW, COLOR_RESET, m2->size);

    t_m2_col *current = m2->head;
    int col_index = 0;

    while (current)
    {
        printf("%sCol[%d]:%s (%.3f, %.3f)\n",
               COLOR_MAGENTA, col_index, COLOR_RESET,
               current->x, current->y);
        current = current->next;
        col_index++;
    }
    printf("%s========================%s\n\n", COLOR_CYAN, COLOR_RESET);
}

void debug_matrix_m3(t_m3 *m3, const char *description)
{
    if (!m3)
    {
        DEBUG_ERROR("Matrix M3 is NULL: %s", description);
        return;
    }

    printf("\n%s=== M3 Matrix Debug: %s ===%s\n", COLOR_GREEN, description, COLOR_RESET);
    printf("%sSize:%s %zd columns\n", COLOR_YELLOW, COLOR_RESET, m3->size);

    t_m3_col *current = m3->head;
    int col_index = 0;

    while (current)
    {
        printf("%sCol[%d]:%s (%.3f, %.3f, %.3f)\n",
               COLOR_MAGENTA, col_index, COLOR_RESET,
               current->x, current->y, current->z);
        current = current->next;
        col_index++;
    }
    printf("%s========================%s\n\n", COLOR_GREEN, COLOR_RESET);
}

void debug_matrix_m4(t_m4 *m4, const char *description)
{
    if (!m4)
    {
        DEBUG_ERROR("Matrix M4 is NULL: %s", description);
        return;
    }

    printf("\n%s=== M4 Matrix Debug: %s ===%s\n", COLOR_BLUE, description, COLOR_RESET);
    printf("%sSize:%s %zd columns\n", COLOR_YELLOW, COLOR_RESET, m4->size);

    t_m4_col *current = m4->head;
    int col_index = 0;

    while (current)
    {
        printf("%sCol[%d]:%s (%.3f, %.3f, %.3f, %.3f)\n",
               COLOR_MAGENTA, col_index, COLOR_RESET,
               current->x, current->y, current->z, current->w);
        current = current->next;
        col_index++;
    }
    printf("%s========================%s\n\n", COLOR_BLUE, COLOR_RESET);
}