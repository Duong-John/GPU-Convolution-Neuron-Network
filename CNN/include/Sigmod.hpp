#ifndef SIGMOD_HPP
#define SIGMOD_HPP
#include "Layer.hpp"

class Sigmod: public Layer
{
    private:
    xt::xarray<double> Sigmod_input;
    
    public:
    
    Sigmod(int height_Weight, int width_Weight, int height_Bias, int width_Bias, const char* destination_file);
    ~Sigmod();
    xt::xarray<double> Foward(xt::xarray<double> input);
    xt::xarray<double> Backward(xt::xarray<double> in_cache_L_Z2);
};

#endif //SIGMOD_HPP