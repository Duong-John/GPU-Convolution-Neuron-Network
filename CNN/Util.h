#ifndef UTIL_H
#define UTIL_H
#include <random>
#include <thread>
#include "tensor/xtensor_lib.h"
void generate_random(int Input, int Hidden, int Output);
void find_correct(double &max_1, double &max_2, int &index_1, int &index_2, int Size, xt::xarray<double> &in_matrix, xt::xarray<int> &label);
void find_correct(double &max_1, int &index_1, int Size, xt::xarray<double> &in_matrix);
void generate_random_kernel(int num_kernel);
void printWide(const string &line);
void printLogo();
#endif