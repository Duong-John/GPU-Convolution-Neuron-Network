#ifndef LAYER_HPP
#define LAYER_HPP

#include <iostream>
#include <fstream>
#include "Header.h"
class Layer
{
    protected:
    //Foward:
    
    xt::xarray<double> Weight;
    xt::xarray<double> Bias;

    int height_Weight = 0;
    int width_Weight = 0;

    int height_Bias = 0;
    int width_Bias = 0;

    const char* destination_file;
    //Backward:
    //...
    xt::xarray<double> cache_Weight;
    xt::xarray<double> cache_Bias;
    public:
    double learning_rate;
    Layer_Type type;
    Layer();
    Layer(int height_Weight, int width_Weight, int height_Bias, int width_Bias, const char* destination_file);
    ~Layer();
    virtual xt::xarray<double> Foward(xt::xarray<double> input) = 0;
    virtual xt::xarray<double> Backward(xt::xarray<double> in_cache_L_Z2) = 0;
    void update(xt::xarray<double> in_Weight, xt::xarray<double> in_Bias);
    void getMatrix(const char* name);
    void setMatrix();
    void printWeight();
    void printBias();
    void learn();
    xt::xarray<double> get_Weight();
};



#endif //LAYER_HPP