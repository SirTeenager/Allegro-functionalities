#ifndef MOVECAMERA_MAIN_CAMERA_H
#define MOVECAMERA_MAIN_CAMERA_H

#include <allegro5/allegro.h>
#include "../constant.h"

#define CAMERA_SPEED 50

typedef struct {
    float x, y;
    float scale;
    float mouse_x, mouse_y;
    bool dragging;
}Camera;


void apply_camera_transform(Camera *camera);
void event_camera_keyboard(ALLEGRO_EVENT eventType, int key[KEY_MAX]);
void move_camera_keyboard(int const key[KEY_MAX], Camera* camera);
void move_camera_mouse(ALLEGRO_MOUSE_STATE mouseState, Camera* camera);
void zoom_camera(ALLEGRO_EVENT event, Camera* camera);

#endif
