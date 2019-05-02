#ifndef __keyATM_basic__INCLUDED__
#define __keyATM_basic__INCLUDED__

#include <Rcpp.h>
#include <RcppEigen.h>
#include <unordered_set>
#include "sampler.h"
#include "keyATM.h"

using namespace Eigen;
using namespace Rcpp;
using namespace std;

class keyATMbasic : public keyATMbase
{
	public:	
		//
		// Parameters
		//

		// Slice Sampling
		double min_v = 1e-9;
		double max_v = 100.0;
		int max_shrink_time = 1000;

		double start, end, previous_p, new_p, newlikelihood, slice_;
		std::vector<int> topic_ids;
		VectorXd keep_current_param;
		double store_loglik;
		double newalphallk;

		double loglik;
		double fixed_part;

			// in alpha_loglik
			MatrixXd ndk_a;
		
		//
		// Functions
		//

		// Constructor
		keyATMbasic(List model_, const int iter_, const int output_per_);

		// Read data
		void read_data_specific();

		// Initialization
		void initialize_specific();

		// Iteration
		void iteration_single(int &it);
		void sample_parameters();
		void sample_alpha();
		double alpha_loglik();
		double loglik_total();


};


#endif

