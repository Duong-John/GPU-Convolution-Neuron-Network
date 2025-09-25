#ifndef RELU_HPP
#define RELU_HPP
#include "Layer.hpp"


class ReLU: public Layer
{
    private:
    CUfunction k_relu;
    CUfunction k_relu_bwd;
    bool relu_ready = false;
    bool relu_bwd_ready = false;

    xt::xarray<double> ReLU_input;
    xt::xarray<double> ReLU_value;
    double leak_coefficient;
    bool active;

    xt::xarray<double> cache_ReLU;
    vector<int> cache_ReLU_CUDA;
    
    public:
    ReLU();
    ReLU(int height_Weight, int width_Weight, int height_Bias, int width_Bias, const char* destination);
    ~ReLU();

    xt::xarray<double> Foward(xt::xarray<double> input);
    std::vector<double> Foward(const double* input_ptr, int size, int batch, int Cout, int H, int W);

    xt::xarray<double> Backward(xt::xarray<double> in_cache_L_Z2);
    std::vector<double> Backward(const double* dOut_ptr, int size);

    void change_Type(Layer_Type type, double leak_coefficient);
    xt::xarray<double> get_cache_ReLU();
};





#endif //RELU_HPP