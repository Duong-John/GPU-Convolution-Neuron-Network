#ifndef CONVOLUTION_CUDA_HPP
#define CONVOLUTION_CUDA_HPP

#include "Header.h"
#include "ReLU.hpp"
#include "Max_Pooling.hpp"

struct Kernel
{
    xt::xarray<double> kernel_matrix;
    double bias;
    int index;
};


class Convolution
{
    private: 
    CUfunction k_conv; 
    CUfunction k_conv_bwd;
    bool conv_ready = false;
    bool conv_bwd_ready = false;

    //Foward:
    double learning_rate = 0.005;
    std::vector<Kernel*> kernels;
    xt::xarray<double> input;
    int size;
    
    const char* destination_file;
    int count_kernels = 0;
    ReLU relu;
    Max_Pooling max_pooling;

    xt::xarray<double>* result_from_pooling;
    //Backward:
    std::vector<xt::xarray<double>> cache_Weight;
    std::vector<double> cache_Bias;
    bool flatten;
    int batch_size;
    public:

    Convolution(const char* destination_file, std::vector<Kernel*> in_kernel, bool flatten);
    ~Convolution();
    void add_kernel(Kernel * in_kernel);
    xt::xarray<double> Foward(xt::xarray<double> input);
    void get_Matrix(const char* destination_file);
    void set_Matrix();
    std::vector<Kernel*> get_kernels();
    //Backward
    xt::xarray<double> Backward(xt::xarray<double> in_cache_L_Z2);
    void learn();
    std::pair<int, int> get_batch_size_and_Cout();
};

#endif

