#include "mini_rt.h"

// First, you need a color_at function that handles the full ray tracing pipeline
t_rgb *color_at(t_scene *scene, t_ray *ray, int remaining)
{
    t_obj_list *intersections;
    t_rgb *surface_color;
    t_rgb *reflected_color;
    t_rgb *refracted_color_result;
    t_rgb *final_color;
    t_material material;

    if (remaining <= 0)
        return (init_rgb(0, 0, 0));

    // Get intersections
    intersections = intersect_to_list(scene, ray);

    // If no hit, return black
    if (!intersections->head || !intersections->head->t)
        return (init_rgb(0, 0, 0));

    // Prepare computations for the hit
    if (!set_comp_to_obj(intersections->head, ray, intersections))
        return (init_rgb(0, 0, 0));

    // Get the base shaded color
    surface_color = get_shaded_with_shadows(scene, intersections->head, remaining);

    // Get material for reflective/refractive properties
    material = get_material_from_comps(intersections->head->comp, intersections);

    // Calculate reflected color if the material is reflective
    reflected_color = reflected_color_func(scene, intersections->head->comp, remaining - 1);

    // Calculate refracted color if the material is transparent
    refracted_color_result = refracted_color(intersections->head, intersections, scene, remaining - 1);

    // Combine all colors
    final_color = combine_colors(surface_color, reflected_color, refracted_color_result, material);

    // Clean up
    free(surface_color);
    free(reflected_color);
    free(refracted_color_result);

    return (final_color);
}

// Your refracted_color function needs these fixes:
t_rgb *refracted_color(t_obj_node *obj_node, t_obj_list *obj_list,
                      t_scene *scene, int remaining)
{
    t_material material;
    double sin2_t;
    t_tuples *direction;
    t_ray *refract_ray;
    t_rgb *color;

    if (remaining == 0)
        return (init_rgb(0, 0, 0));

    // FIX 1: Get material from the computations, not uninitialized variable
    material = get_material_from_comps(obj_node->comp, obj_list);

    if (material.transparency == 0)
        return (init_rgb(0, 0, 0));

    sin2_t = snells_law(obj_node->comp);
    if (sin2_t > 1.0)
        return (init_rgb(0, 0, 0)); // Total internal reflection

    direction = find_direction(obj_node->comp, sin2_t);
    refract_ray = init_ray(obj_node->comp->under_point, direction);

    // FIX 2: Call color_at recursively, not get_shaded_with_shadows
    color = color_at(scene, refract_ray, remaining - 1);

    // FIX 3: Multiply by transparency
    color = ftm_rgb_mult(color, material.transparency);

    // Clean up
    free(refract_ray);
    free(direction);

    return (color);
}

// Your find_direction function also has an issue - fix the formula:
t_tuples *find_direction(t_computations *comps, double sin2_t)
{
    double cos_t;
    double cos_i;
    double n_ratio;
    t_tuples *direction;
    t_tuples *normal_component;
    t_tuples *eye_component;

    cos_t = sqrt(1.0 - sin2_t);
    cos_i = ftm_tup_dot(comps->eyev, comps->normalv);
    n_ratio = comps->n1 / comps->n2;

    // FIX: Correct refraction formula
    // direction = normal * (n_ratio * cos_i - cos_t) - eye * n_ratio
    normal_component = ftm_tup_mult(comps->normalv, (n_ratio * cos_i - cos_t));
    eye_component = ftm_tup_mult(comps->eyev, n_ratio);
    direction = ftm_tup_subtract(normal_component, eye_component);

    // Clean up intermediate calculations
    free(normal_component);
    free(eye_component);

    return (direction);
}

// Modified get_shaded_with_shadows - this should only handle surface shading
t_rgb *get_shaded_with_shadows(t_scene *scene, t_obj_node *obj_node, int remaining)
{
    t_computations *comps;
    t_rgb *shaded;
    t_rgb *temp;
    t_light *curr;

    shaded = init_rgb(0, 0, 0);
    curr = scene->light_list->head;
    comps = obj_node->comp;

    while (curr)
    {
        temp = shade_hit(scene, comps, curr, remaining);
        shaded = ftm_rgb_add(temp, shaded);
        free(temp);
        curr = curr->next;
    }

    // Clamp colors to [0, 1]
    if (shaded->r > 1.0) shaded->r = 1.0;
    if (shaded->g > 1.0) shaded->g = 1.0;
    if (shaded->b > 1.0) shaded->b = 1.0;

    return (shaded);
}

// Helper function to combine surface, reflected, and refracted colors
t_rgb *combine_colors(t_rgb *surface, t_rgb *reflected, t_rgb *refracted, t_material material)
{
    t_rgb *result = init_rgb(0, 0, 0);

    // Add surface color
    result->r += surface->r;
    result->g += surface->g;
    result->b += surface->b;

    // Add reflected color scaled by reflectivity
    result->r += reflected->r * material.reflective;
    result->g += reflected->g * material.reflective;
    result->b += reflected->b * material.reflective;

    // Add refracted color (already scaled by transparency in refracted_color)
    result->r += refracted->r;
    result->g += refracted->g;
    result->b += refracted->b;

    // Clamp to [0, 1]
    if (result->r > 1.0) result->r = 1.0;
    if (result->g > 1.0) result->g = 1.0;
    if (result->b > 1.0) result->b = 1.0;

    return (result);
}