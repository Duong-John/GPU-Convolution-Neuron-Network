#ifndef DATASET_HPP
#define DATASET_HPP
#include "Header.h"

class Dataset
{
    public:
    std::vector<xt::xarray<double>> batch_list;
    std::vector<xt::xarray<double>> batch_label;

    std::vector<xt::xarray<double>> validation_list;
    std::vector<xt::xarray<double>> validation_label;

    int true_image;

    bool train;
    const char* data_set;
    int Output, number_of_image;
    int Height, Width;

    string *name;
    int *index;
    std::vector<xt::xarray<double>> in_label;

    void create_batch_list();
    void shuffle_array(int arr[], int size);
    void clean_data_list();

    public:
    Dataset(bool train, const char* data_set, int Height, int Width, int Output, int number_of_image);
    void shuffle_new(int batch_size);
    void shuffle_real();

    ~Dataset();
};



#endif