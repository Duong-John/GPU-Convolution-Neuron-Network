#ifndef SOFTMAX_HPP
#define SOFTMAX_HPP
#include "Layer.hpp"

class Softmax: public Layer
{
    private:
    xt::xarray<double> Softmax_input;
    
    public:
    
    Softmax(int height_Weight, int width_Weight, int height_Bias, int width_Bias, const char* destination_file);
    ~Softmax();
    xt::xarray<double> Foward(xt::xarray<double> input);
    xt::xarray<double> Backward(xt::xarray<double> in_cache_L_Z2);
};

#endif //SOFTMAX_HPP