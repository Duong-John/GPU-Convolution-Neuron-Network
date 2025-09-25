#ifndef MAX_POOLING_HPP
#define MAX_POOLING_HPP

#include "Header.h"

class Max_Pooling
{
    private:
    CUfunction k_pool;
    CUfunction k_relu_bwd;
    bool pool_ready = false;
    bool relu_bwd_ready = false;

    xt::xarray<double> cache_Pooling;
    vector<int> cache_Pooling_CUDA;

    int height;
    int width;
    
    public:
    Max_Pooling();
    ~Max_Pooling();
    xt::xarray<double> Foward(const double* input_ptr, int size, int batch_size, int Cout, int H, int W);
    // void create_index_list(int size);
    // void delete_index_list();
    //Backward
    // xt::xarray<double>  Backward(xt::xarray<double> input);
    std::vector<double> Backward(const double* dOut_ptr, int size);
    std::pair<int, int> get_height_width();
};

#endif