#ifndef __keyATM_base__INCLUDED__
#define __keyATM_base__INCLUDED__
#define EIGEN_PERMANENTLY_DISABLE_STUPID_WARNINGS

#include <Rcpp.h>
#include <RcppEigen.h>
#include <unordered_set>
#include "sampler.h"
#include "keyATM_meta.h"

using namespace Eigen;
using namespace Rcpp;
using namespace std;

class keyATMbase : virtual public keyATMmeta
{
  public:
    //
    // Parameters
    //
    int estimate_alpha;
    int store_alpha;

    std::vector<int> topic_ids;
    VectorXd keep_current_param;
    double store_loglik;
    double newalphallk;

      // in alpha_loglik
      MatrixXd ndk_a;

    //
    // Functions
    //

    // Constructor
    keyATMbase(List model_, const int iter_) :
      keyATMmeta(model_, iter_) {};

    // Read data
    virtual void read_data_specific() override final;

    // Initialization
    virtual void initialize_specific() override final;

    // Iteration
    virtual void iteration_single(int it) override;
    virtual void sample_parameters(int it) override final;
    void sample_alpha();
    double alpha_loglik(int k);
    virtual double loglik_total() override;
    virtual double loglik_total_label() override;
};


#endif
