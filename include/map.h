#pragma once

#include <nlohmann/json.hpp>
#include <vector>

#include "raylib.h"

constexpr const char* IID = "iid";
constexpr const char* COLLISION_LAYER_IID =
    "39356900-1030-11f0-b54c-3544221b5482";
constexpr const char* BACKGROUND_LAYER_IID =
    "9f24b700-1030-11f0-b54c-310d4878857d";

using json = nlohmann::json;

typedef struct CollisionTile {
    Vector2 grid_position;
    int tile_type;
} CollisionTile;

typedef struct Map {
    int width;
    int height;
    Vector2 origin;
    Vector2 spawn;
    std::vector<CollisionTile> collision;
    std::vector<Vector2> background_pos;
    std::vector<Vector2> background_src_pos;
} Map;

Map ParseMap();

void DrawMap(const Map* map_data, const Texture2D* tileset,
             Vector2* player_position);
