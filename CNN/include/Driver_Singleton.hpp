#ifndef DRIVER_HPP
#define DRIVER_HPP

#ifdef __GNUC__
#pragma push_macro("__cdecl")
#undef __cdecl
#endif

#include <cuda_runtime.h>
#include <cuda.h>

extern bool driver_ready;
extern CUcontext ctx;
extern CUmodule  mod;

#ifdef __GNUC__
#pragma pop_macro("__cdecl")
#endif

#endif