#ifndef _RUNSIMA_H_
#define _RUNSIMA_H_
#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include "jComputer.h"
#include "simRunner.h"
#include "runSimRyd.h"

using namespace std;
using namespace arma;

class RunSimA : public RunSimRyd {
    public: 
        constexpr static double MAX_JUMP = 1;
        void runSim(double W, int length, mat& A, JComputer& jComputer) override;

    protected: 
        void getEnergies(int length, vec& energies, double W) override;

};
#endif
