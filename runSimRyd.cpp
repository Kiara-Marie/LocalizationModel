#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include "jComputer.h"
#include "findE.h"
#include "runSimRyd.h"
using namespace arma;
using namespace std;

void RunSimRyd::runSim(double W, int length, mat& A, JComputer& jComputer){

	if (W==0){
	cerr<<"W was zero\n";
	throw "Zero for W not implemented!\n";
	}
	unsigned int ulength = (unsigned int) length;
	if (A.n_rows != ulength || A.n_cols != ulength){
		throw "Given length doesn't match A!\n";
	}

	vec energies = zeros(length);
	this->getEnergies(length, energies, W);

	A.diag() = energies;
	if (jComputer.needsEnergy){
		jComputer.additionalInfo(energies);
	}
	double j = 1;
	for (int xi = 0; xi<length;xi++){
		for (int xj = xi + 1; xj<length; xj++){
			j = jComputer.jFinder(xi,xj);
			A(xi, xj) = j;
			A(xj, xi) = j;
			}
		}
	if(!this->is_symmetric(A)){
		cerr<<"Matrix Not Hermitian!\n";
		throw "Matrix not Hermitian!\n";
	}
	return;
}

void RunSimRyd::getEnergies(int length, vec& energies, double W){

	vec nValues = this->getNs(length, W);

	// generate a vector of values between 0 and 1, then multiply element-wise
	// by n
	vec lValues = randu<vec>(length) % nValues ;
	lValues.transform( [](double val) { return floor(val); } );

	for (int i = 0; i < length; i++){
		char nc = (char) nValues(i);
		char lc = (char) lValues(i);

		energies(i) = bindingEnergy(nc,lc);
	}

}

vec RunSimRyd::getNs(int length, double W){
	// make random
	arma_rng::set_seed_random();

	// set up
	vec nValues = randu<vec>(length) * W;
	nValues.transform( [](double val) { return floor(val); } );
	nValues.transform( [](double val) { return val + RunSimRyd::MIN_N; } );

	return nValues;
}
