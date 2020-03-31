#ifndef _RUNSIMRYD_H_
#define _RUNSIMRYD_H_
#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include "simRunner.h"

using namespace std;
using namespace arma;

class RunSimRyd : public SimRunner {
    public:
        const static int MIN_N = 30;
        void runSim(double W, int length, mat& A, JComputer& jComputer);
        virtual void getEnergies(int length, vec& energies, double W);
        void getNsAndLs(int length, double W, vec& nValues, vec& lValues);
};

#endif
