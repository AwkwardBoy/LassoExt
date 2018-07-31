#include <Rcpp.h>
// #include <Rinternals.h>
#include <vector>
#include "Eigen/Dense"
#include <iostream>

using namespace Rcpp;
using Eigen::MatrixXd;
using Eigen::MatrixXi;
using Eigen::Map;

// void load(const int n, const int p, std::vector<int> &);
// void loadFromR(const int n, const int p);
/*
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
*/
/*
void load(const int n, const int p, std::vector<int> &x) 
{
    Map<MatrixXi> X(x.data(), n, p);
    std::cout << X*2<< std::endl;
}
 */

/*
MatrixXd loadRdata(Map<MatrixXd> &x)
{
    std::cout << x << std::endl;
    return x.transpose();
}
*/


extern "C" SEXP loadR(SEXP x, SEXP n, SEXP p){
    // Map<MatrixXd> X(as<Map<MatrixXd> >(x));
    Vector<traits::r_sexptype_traits<double>::rtype> vec(x);
    int nc = as<int>(n);
    int pc = as<int>(p);
    Map<MatrixXd> X(vec.begin(), nc, pc);
    NumericMatrix Xr(wrap(X));
    return Xr;
}
