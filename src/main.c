#include "miniRT.h"

int create_color(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void init_balls(t_data *data)
{
    int i;

    srand(time(NULL));
    i = 0;
    while (i < NUM_BALLS)
    {
        data->balls[i].x = rand() % (WIDTH - 40) + 20;
        data->balls[i].y = rand() % (HEIGHT - 40) + 20;
        data->balls[i].vx = (rand() % 4 + 1) * (rand() % 2 ? 1 : -1);
        data->balls[i].vy = (rand() % 4 + 1) * (rand() % 2 ? 1 : -1);
        data->balls[i].radius = rand() % 20 + 10;
        data->balls[i].color = create_color(
            rand() % 256,
            rand() % 256,
            rand() % 256,
            255
        );
        i++;
    }
}

void clear_image(mlx_image_t *img)
{
    int x, y;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            mlx_put_pixel(img, x, y, create_color(0, 0, 20, 255));
            x++;
        }
        y++;
    }
}

void draw_ball(mlx_image_t *img, t_ball *ball)
{
    int x, y;
    int dx, dy;

    y = ball->y - ball->radius;
    while (y <= ball->y + ball->radius)
    {
        x = ball->x - ball->radius;
        while (x <= ball->x + ball->radius)
        {
            dx = x - ball->x;
            dy = y - ball->y;
            if (dx * dx + dy * dy <= ball->radius * ball->radius)
            {
                if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
                    mlx_put_pixel(img, x, y, ball->color);
            }
            x++;
        }
        y++;
    }
}

void update_balls(t_data *data)
{
    int i;

    i = 0;
    while (i < NUM_BALLS)
    {
        // Update position
        data->balls[i].x += data->balls[i].vx;
        data->balls[i].y += data->balls[i].vy;

        // Bounce off walls
        if (data->balls[i].x - data->balls[i].radius <= 0 ||
            data->balls[i].x + data->balls[i].radius >= WIDTH)
        {
            data->balls[i].vx = -data->balls[i].vx;
            data->balls[i].x = data->balls[i].x - data->balls[i].radius <= 0 ?
                data->balls[i].radius : WIDTH - data->balls[i].radius;
        }

        if (data->balls[i].y - data->balls[i].radius <= 0 ||
            data->balls[i].y + data->balls[i].radius >= HEIGHT)
        {
            data->balls[i].vy = -data->balls[i].vy;
            data->balls[i].y = data->balls[i].y - data->balls[i].radius <= 0 ?
                data->balls[i].radius : HEIGHT - data->balls[i].radius;
        }
        i++;
    }
}

void screensaver_loop(void *param)
{
    t_data *data = (t_data *)param;
    int i;

    // Clear the screen
    clear_image(data->img);

    // Update ball positions
    update_balls(data);

    // Draw all balls
    i = 0;
    while (i < NUM_BALLS)
    {
        draw_ball(data->img, &data->balls[i]);
        i++;
    }
}

int main(void)
{
    t_data data;

    // Initialize MLX
    data.mlx = mlx_init(WIDTH, HEIGHT, "MiniRT Screensaver", true);
    if (!data.mlx)
    {
        printf("Failed to initialize MLX\n");
        return (1);
    }

    // Create image
    data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
    if (!data.img)
    {
        printf("Failed to create image\n");
        mlx_terminate(data.mlx);
        return (1);
    }

    // Display image
    if (mlx_image_to_window(data.mlx, data.img, 0, 0) < 0)
    {
        printf("Failed to display image\n");
        mlx_terminate(data.mlx);
        return (1);
    }

    // Initialize screensaver
    init_balls(&data);

    // Set up the animation loop
    mlx_loop_hook(data.mlx, screensaver_loop, &data);

    // Start the main loop
    mlx_loop(data.mlx);

    // Cleanup
    mlx_terminate(data.mlx);
    return (0);
}
