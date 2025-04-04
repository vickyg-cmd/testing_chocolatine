/*
** EPITECH PROJECT, 2025
** G-ING-200-BAR-2-1-myworld-victoria.gonzalez-malave
** File description:
** window_stuff
*/

#include "../include/myworld.h"

void init_window(sfRenderWindow **window)
{
    sfVideoMode mode = {900, 900};

    *window = sfRenderWindow_create(mode, "Window: My World", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(*window, 60);
}

void init_map(Map_t *map, int width, int height, sfTexture* earth_text)
{
    Tile_t *tile = NULL;

    map->width = width;
    map->height = height;
    map->zoom = 1.0f;
    map->earth_text = earth_text;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            tile = &map->tiles[y][x];
            tile->position.x = (x - y) * (64 / 2);
            tile->position.y = (x + y) * (64 / 4);
            tile->altitude = 0.0f;
            tile->color = sfGreen;
            tile->sprite = sfSprite_create();
            sfSprite_setTexture(tile->sprite, earth_text, sfTrue);
            sfSprite_setTextureRect(tile->sprite, (sfIntRect){0, 0, 64, 64});
            tile->use_texture = false;
        }
    }
}

void lupi(sfVector2f draw_pos, sfRenderWindow *window,
    Map_t *map, Tile_t *tile)
{
    float scaled_size;
    sfRectangleShape* tile_shape;

    scaled_size = 64 * map->zoom;
    if (tile->use_texture) {
        sfSprite_setPosition(tile->sprite, draw_pos);
        sfSprite_setScale(tile->sprite, (sfVector2f){map->zoom, map->zoom});
        sfRenderWindow_drawSprite(window, tile->sprite, NULL);
    } else {
        tile_shape = sfRectangleShape_create();
        sfRectangleShape_setSize(tile_shape,
            (sfVector2f){scaled_size, scaled_size});
        sfRectangleShape_setPosition(tile_shape, draw_pos);
        sfRectangleShape_setFillColor(tile_shape, tile->color);
        sfRenderWindow_drawRectangleShape(window, tile_shape, NULL);
        sfRectangleShape_destroy(tile_shape);
    }
}

void draw_map(sfRenderWindow* window, Map_t *map)
{
    sfVector2f center = {900 / 2, 900 / 2};
    sfVector2f draw_pos;
    Tile_t *tile;

    for (int y = 0; y < map->height; y++) {
        for (int x = 0; x < map->width; x++) {
            tile = &map->tiles[y][x];
            draw_pos.x = center.x + (tile->position.x - center.x) * map->zoom;
            draw_pos.y = center.y + (tile->position.y - center.y -
                tile->altitude * 10) * map->zoom;
            lupi(draw_pos, window, map, tile);
        }
    }
}
