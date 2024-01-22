#pragma once
struct Image { int width; int height; int *data; }; 
struct Tilemap { int count; struct Image images[]; };
extern struct Tilemap tilemap;
