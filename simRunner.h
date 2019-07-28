#ifndef _SIMRUNNER_H_
#define _SIMRUNNER_H_
#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include "jComputer.h"

using namespace std;
using namespace arma;


class SimRunner {
	public:
        explicit SimRunner();
		~SimRunner();
		SimRunner( const SimRunner& anotherSimRunner );
        int is_symmetric(const mat& A);
        virtual void runSim(double W, int length, mat& A, JComputer& jComputer);
};

#endif
