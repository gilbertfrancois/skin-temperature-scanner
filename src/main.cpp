/*
Copyright 2020 Gilbert François Duivesteijn

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
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
