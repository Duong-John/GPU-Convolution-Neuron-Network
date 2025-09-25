#ifndef HEADER_H
#define HEADER_H
#include "xtensor_lib.h"
#include "SDL.h"
#include "SDL_image.h"
#include "Driver_Singleton.hpp"
#include <iomanip>
#include <random>
#include <cmath>
#include <vector>
#include <cstring> 
#include <cuda_runtime.h>
#include <cuda.h>

enum Layer_Type
{
    RELU,
    LEAKY_RELU,
    SIGMOD,
    SOFTMAX,
};



#endif