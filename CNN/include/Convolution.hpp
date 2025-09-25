// #ifndef CONVOLUTION_HPP
// #define CONVOLUTION_HPP

// #include "Header.h"
// #include "ReLU.hpp"
// #include "Max_Pooling.hpp"
// struct Kernel
// {
//     xt::xarray<double> kernel_matrix;
//     double bias;
//     int index;
// };


// class Convolution
// {
//     private: 
//     //Foward:
//     double learning_rate = 0.005;
//     std::vector<Kernel*> kernels;
//     xt::xarray<double> input;
//     int size;

//     const char* destination_file;
//     int count_kernels = 0;
//     ReLU relu;
//     Max_Pooling max_pooling;

//     xt::xarray<double>* result_from_kernel;
//     xt::xarray<double>* result_from_pooling;
//     xt::xarray<double>* result_from_relu;
//     //Backward:
//     std::vector<xt::xarray<double>> cache_Weight;
//     std::vector<double> cache_Bias;
//     public:

    

//     Convolution(const char* destination_file, std::vector<Kernel*> in_kernel);
//     ~Convolution();
//     void add_kernel(Kernel * in_kernel);
//     void Forward(xt::xarray<double> input);
//     void get_Matrix(const char* destination_file);
//     void set_Matrix();
//     std::vector<Kernel*> get_kernels();
//     //Backward
//     void Backward(std::vector<xt::xarray<double>> input);
//     void learn();
// };

// #endif

