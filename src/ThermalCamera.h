//
// Created by G.F. Duivesteijn on 23.03.20.
//

#ifndef THERMALCAM_THERMALCAMERA_H
#define THERMALCAM_THERMALCAMERA_H

#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <MLX90640_API.h>
#include "constants.h"


class ThermalCamera {

public:
    ThermalCamera();

    virtual ~ThermalCamera();

    void init_sdl();

    void init_sensor();

    void handle_events();

    void update();

    void render();

    void clean();

    bool running() { return is_running; }


private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_Texture *texture_r;
    SDL_Texture *slider;
    std::vector<SDL_Texture*> animation;
    TTF_Font *font32;
    TTF_Font *font64;

    // === Settings ===
    const float MIN_TEMPERATURE = 5.0f;
    const float MAX_TEMPERATURE = 50.0f;
    const float MIN_MEASURE_RANGE = 31.0f;
    const float MAX_MEASURE_RANGE = 40.0f;
    const float MEASURE_AREA_FRACTION = 0.10f;
    const int MEASURE_AREA_THRESHOLD = static_cast<int>(round(SENSOR_W * SENSOR_H * MEASURE_AREA_FRACTION));
    // Emissivity value for human skin
    const float EMISSIVITY = 0.99;
    // Moving average parameter
    const float BETA = 0.90;
    // Screen rotation
    const int rotation = 0;
    // Font path
    std::string FONT_PATH = "/usr/share/fonts/truetype/piboto/Piboto-Regular.ttf";
    // Measure timer
    const float TIMER_THRESHOLD_SECONDS = .6f;
    const size_t TIMER_THRESHOLD_FRAMES = static_cast<int>(round(TIMER_THRESHOLD_SECONDS * FPS));
    size_t timer_is_measuring;
    size_t timer_is_animating;

    // === Buffers ===
    // Eeprom parameters buffer
    uint16_t eeMLX90640[832];
    // Sensor parameters, converted from parameter buffer.
    paramsMLX90640 mlx90640;
    // Buffer for storing raw sensor output.
    uint16_t frame[834];
    // Buffer for storing converted sensor values (temperatures as float[]).
    float mlx90640To[768];
    // Buffer for storing pixel color values to visualize sensor output.
    uint32_t pixels[768];

    // === Variables ===
    std::string resource_path;
    bool is_running;
    bool is_measuring;
    bool is_measuring_lpf;
    bool is_animating;
    int display_width;
    int display_height;
    int output_width;
    int output_height;
    int offset_left;
    int offset_top;
    int aspect_scale;
    SDL_Rect rect_preserve_aspect;
    SDL_Rect rect_fullscreen;
    bool preserve_aspect = true;
    // Estimated environment temperature
    float eTa;
    float temperature_moving_mean;
    float mean_val;
    float mean_val_lpf;
    std::string message;
    int animation_frame_nr;


    // === Functions ===
    void colormap(int x, int y, float v, float vmin, float vmax);

    void render_sensor_frame() const;

    void render_text(const std::string &text, const SDL_Color &text_color, SDL_Point origin, int anchor,
                     TTF_Font *font) const;

    void render_slider() const;

    void render_temp_labels() const;

    void render_animation();
};


#endif //THERMALCAM_THERMALCAMERA_H
