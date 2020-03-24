//
// Created by G.F. Duivesteijn on 23.03.20.
//
#include <chrono>
#include <thread>
#include "constants.h"
#include "ThermalCamera.h"

int main() {
    ThermalCamera thermal_camera;
    auto frame_time = std::chrono::microseconds(FRAME_TIME_MICROS + OFFSET_MICROS);
    while (thermal_camera.running()) {
        auto start = std::chrono::system_clock::now();

        thermal_camera.handle_events();
        thermal_camera.update();
        thermal_camera.render();

        auto end = std::chrono::system_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::this_thread::sleep_for(std::chrono::microseconds(frame_time - elapsed));

    }
    thermal_camera.clean();
    exit(EXIT_SUCCESS);
}
