#ifndef LOSS_HPP
#define LOSS_HPP
#include <iostream>
#include <cmath>
#include "Header.h"
class Loss
{
    private:
    double loss;
    xt::xarray<double> cache_L_Z2;
    xt::xarray<double> calculate_cache_L_Z2(xt::xarray<int> label, xt::xarray<double> input, Layer_Type type);
    public:
    Loss();
    ~Loss();
    void calculate_loss(xt::xarray<int> label, xt::xarray<double> input, Layer_Type type);
    void print_loss();
    double get_loss();
    xt::xarray<double> get_cache_L_Z2();
    double get_cache_L_Z2_Sigmod();
    
};


#endif //LOSS_HPP