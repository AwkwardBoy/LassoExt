#include <Rcpp.h>
#include <vector>
#include "Eigen/Dense"
#include <iostream>
// using namespace Rcpp;
using Eigen::MatrixXd;
using Eigen::MatrixXi;
using Eigen::Map;

void load(const int n, const int p, std::vector<int> &);
void loadFromR(const int n, const int p);

int main()
{
    const int n = 3;
    const int p = 4;
    std::vector<int> x;
    for(int i=0; i < 12; i++)
    {
        x.push_back(i);
    }
  load(n, p, x);
}

void load(const int n, const int p, std::vector<int> &x) 
{
    Map<MatrixXi> X(x.data(), n, p);
    std::cout << X*2<< std::endl;
}

// [[Rcpp::export]]
void loadRdata(Rcpp::NumericMatrix &x)
{
    Map<MatrixXi> X(Rcpp::as<Map<MatrixXi> >(x));
    std::cout << X << std::endl;
}