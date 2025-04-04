/*
** EPITECH PROJECT, 2025
** B-PSU-200-BAR-2-1-minishell1-victoria.gonzalez-malave
** File description:
** mysh
*/

#ifndef INCLUDED_MYWORLD_H
    #define INCLUDED_MYWORLD_H
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <sys/wait.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <stdbool.h>
    #include <math.h>
    //Tile struct
typedef struct {
    sfVector2f position;
    float altitude;
    sfColor color;
    sfSprite* sprite;
    //animation sprites? no no hay...
    float target_altitude;
    bool is_animating;
    bool use_texture;
} Tile_t;
//Map struct
typedef struct {
    Tile_t tiles[50][50];
    int width;
    int height;
    float zoom;
    float animation_speed;
    sfTexture* earth_text;
} Map_t;
//window stuff.c
void init_window(sfRenderWindow **window);
void init_map(Map_t *map, int width, int height, sfTexture* earth_texture);
void draw_map(sfRenderWindow* window, Map_t *map);
//extra_fun.c
void handle_events(sfRenderWindow* window, Map_t *map, float delta_time);
//msin.c
void reset_terrain(Map_t *map);
void raise_terrain(Map_t *map, sfVector2i mouse_pos);
#endif
