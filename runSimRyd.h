#ifndef _RUNSIM1D_H_
#define _RUNSIM1D_H_
#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include "jComputer.h"

using namespace std;
using namespace arma;

void runSimRyd(double W, int length, mat& A, JComputer& jComputer);

double findT(int xi, int xj);
int is_symmetric(const mat& A);
void getEnergies(int length, vec& energies, double W);
vec getNs(int length, double W);
#endif
