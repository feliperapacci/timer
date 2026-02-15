#define MINIAUDIO_IMPLEMENTATION
#include "vendored/miniaudio.h"

#include "audio.h"

std::string alarm_file("alarms/default.wav");

ma_result result;
ma_engine engine;
ma_sound sound;

int initialize_audio() {

    result = ma_engine_init(NULL, &engine);
    if (result != MA_SUCCESS)
        return -1;

    result = ma_sound_init_from_file(&engine, alarm_file.c_str(), 0, NULL, NULL, &sound); 
    if (result != MA_SUCCESS)
        return -1;

    return 0;
}

void play_sound() {
    ma_sound_start(&sound);
}
