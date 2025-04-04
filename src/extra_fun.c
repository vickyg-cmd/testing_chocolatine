/*
** EPITECH PROJECT, 2025
** G-ING-200-BAR-2-1-myworld-victoria.gonzalez-malave
** File description:
** extra_fun
*/

#include "../include/myworld.h"

static void keyboard_events(sfEvent event, sfRenderWindow* window,
    Map_t *map, float delta_time)
{
    if (event.type == sfEvtKeyPressed) {
        switch (event.key.code) {
            case sfKeyUp:
                map->zoom = fminf(map->zoom *
                    (1.0f + 1.5f * delta_time), 5.0f);
                break;
            case sfKeyDown:
                map->zoom = fmaxf(map->zoom /
                    (1.0f + 1.5f * delta_time), 0.2f);
                break;
            case sfKeyR:
                reset_terrain(map);
                break;
            case sfKeyEscape:
                sfRenderWindow_close(window);
                break;
        }
    }
}

static void mouse_events(sfEvent event, sfRenderWindow* window, Map_t *map)
{
    sfVector2i mouse_pos;

    if (event.type == sfEvtMouseButtonPressed) {
        if (event.mouseButton.button == sfMouseLeft) {
            mouse_pos = sfMouse_getPositionRenderWindow(window);
            raise_terrain(map, mouse_pos);
        }
    }
}

void handle_events(sfRenderWindow* window, Map_t *map, float delta_time)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        } else {
            mouse_events(event, window, map);
            keyboard_events(event, window, map, delta_time);
        }
    }
}
