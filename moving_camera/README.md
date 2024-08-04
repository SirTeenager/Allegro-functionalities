# HOW it works ?

You must know Allegro's basics ! 

## Initialisation of the "camera". 
In your main.c, before your game/main loop, create a camera.
```
Camera your_camera = init_camera();
```
Then you can use functions as you wish in your game/main loop.

## About constant.h
This file is used to define the screen size macro. And there's an ENUM which is needed to move the camera with the keyboard. You need to initiate it this way:
```
list_key[KEY_MAX] = {0,0,0,0};
```


