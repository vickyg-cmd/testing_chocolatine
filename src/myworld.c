/*
** EPITECH PROJECT, 2025
** G-ING-200-BAR-2-1-myworld-victoria.gonzalez-malave
** File description:
** myworld
*/

#include "../include/myworld.h"

static float calculate_distance(Tile_t *tile, sfVector2i point2)
{
    float dx = tile->position.x - point2.x;
    float dy = tile->position.y - point2.y;

    return sqrtf(dx * dx + dy * dy);
}

bool mod_dis(Tile_t *tile, float distance, float radius)
{
    if (distance < radius) {
        tile->altitude += 0.1f * (1 - distance / radius);
        tile->use_texture = true;
        return true;
    }
    return false;
}

void raise_terrain(Map_t *map, sfVector2i mouse_pos)
{
    Tile_t *tile = NULL;
    float distance;
    float rad = 70.0f;

    for (int y = 0; y < map->height; y++) {
        for (int x = 0; x < map->width; x++) {
            tile = &map->tiles[y][x];
            distance = calculate_distance(tile, mouse_pos);
            mod_dis(tile, distance, rad);
        }
    }
}

void reset_terrain(Map_t *map)
{
    for (int y = 0; y < map->height; y++) {
        for (int x = 0; x < map->width; x++) {
            map->tiles[y][x].altitude = 0.0f;
            map->tiles[y][x].color = sfGreen;
            map->tiles[y][x].use_texture = false;
        }
    }
}

void stuff(sfRenderWindow* window, sfClock* clock, float delta_time, Map_t map)
{
    sfTime elapsed;

    while (sfRenderWindow_isOpen(window)){
        elapsed = sfClock_getElapsedTime(clock);
        delta_time = sfTime_asSeconds(elapsed);
        sfClock_restart(clock);
        handle_events(window, &map, delta_time);
        sfRenderWindow_clear(window, sfWhite);
        draw_map(window, &map);
        sfRenderWindow_display(window);
    }
}

int main(void)
{
    sfRenderWindow* window;
    Map_t map;
    sfClock* clock = sfClock_create();
    float delta_time = 0.0f;
    sfTexture* earth_text = sfTexture_createFromFile("files/tierra.png", NULL);

    if (!earth_text) {
        printf("Error: No se pudo cargar la textura tierra.png\n");
        return 84;
    }
    init_window(&window);
    init_map(&map, 20, 20, earth_text);
    stuff(window, clock, delta_time, map);
    sfTexture_destroy(earth_text);
    sfClock_destroy(clock);
    sfRenderWindow_destroy(window);
    return 0;
}
