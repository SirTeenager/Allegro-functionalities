#include "main_camera.h"


void apply_camera_transform(Camera *camera) {
    ALLEGRO_TRANSFORM transform;
    al_identity_transform(&transform);
    al_scale_transform(&transform, camera->scale, camera->scale);
    al_translate_transform(&transform, -camera->x, -camera->y);
    al_use_transform(&transform);
}

void event_camera_keyboard(ALLEGRO_EVENT event, int key[KEY_MAX]){
    switch (event.type) {

        /* ALLEGRO_EVENT_KEY_DOWN - a keyboard key was pressed.
         */
        case ALLEGRO_EVENT_KEY_DOWN:
            if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                return;
            }
            switch (event.keyboard.keycode) {
                case ALLEGRO_KEY_D:
                    key[RIGHT] = 1;
                    break;
                case ALLEGRO_KEY_A:
                    key[LEFT] = 1;
                    break;
                case ALLEGRO_KEY_W:
                    key[UP] = 1;
                    break;
                case ALLEGRO_KEY_S:
                    key[DOWN] = 1;
                    break;


            }
            break;

        case ALLEGRO_EVENT_KEY_UP:
            switch (event.keyboard.keycode) {
                case ALLEGRO_KEY_D:
                    key[RIGHT] = 0;
                    break;
                case ALLEGRO_KEY_A:
                    key[LEFT] = 0;
                    break;
                case ALLEGRO_KEY_W:
                    key[UP] = 0;
                    break;
                case ALLEGRO_KEY_S:
                    key[DOWN] = 0;
                    break;
            }
            break;
    }
}

void move_camera_keyboard(int const key[KEY_MAX], Camera* camera){
    if (key[UP]){
        camera->y += -CAMERA_SPEED;
    }
    else if (key[DOWN]){
        camera->y += CAMERA_SPEED;
    } if (key[LEFT]){
        camera->x += -CAMERA_SPEED;
    }else if (key[RIGHT]){
        camera->x+= CAMERA_SPEED;
    }
}

void move_camera_mouse(ALLEGRO_MOUSE_STATE mouse_state, Camera* camera){
    if (mouse_state.buttons & 1) {
        if (!camera->dragging) {
            camera->dragging = true;
            camera->mouse_x = mouse_state.x;
            camera->mouse_y = mouse_state.y;
        }
        float dx = (mouse_state.x - camera->mouse_x) ;
        float dy = (mouse_state.y - camera->mouse_y) ;
        camera->x -= dx;
        camera->y -= dy;
        camera->mouse_x = mouse_state.x;
        camera->mouse_y = mouse_state.y;
    } else {
        camera->dragging = false;
    }
}

void zoom_camera(ALLEGRO_EVENT event, Camera* camera){
    switch (event.type) {
        case ALLEGRO_EVENT_KEY_DOWN:
            if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                return;
            }
            switch (event.keyboard.keycode) {
                case ALLEGRO_KEY_UP:
                    camera->scale += 0.1f;
                    break;
                case ALLEGRO_KEY_DOWN:
                    camera->scale -= 0.1f;
                    break;
            }
            break;
    }
}
