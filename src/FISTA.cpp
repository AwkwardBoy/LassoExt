#include <Rcpp.h>
#include <RcppEigen.h>
#include <vector>
#include <iostream>

using namespace Rcpp;
using Eigen::MatrixXd;
using Eigen::MatrixXi;
using Eigen::Map;



extern "C" SEXP loadR(SEXP x){
    Map<MatrixXd> X(as<Map<MatrixXd> >(x));
    NumericMatrix Xr(wrap(X));
    return Xr;
}

