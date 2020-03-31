#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include <random>
#include "jComputer.h"
#include "findE.h"
#include "runSimA.h"
#include "runSimRyd.h"
using namespace arma;
using namespace std;


void RunSimA::runSim(double W, int length, mat& A, JComputer& jComputer){

	if (W==0){
	cerr<<"W was zero\n";
	throw "Zero for W not implemented!\n";
	}

	vec energies = zeros(length);
	getEnergies(length, energies, W);

	A.diag() = energies;
	if (jComputer.needsEnergy){
		jComputer.additionalInfo(energies);
	}
	double j = 1;
	for (int xi = 0; xi<length;xi++){
		for (int xj = 0; xj<length; xj++){
			if(xi == xj) {
				continue;
			}
			j = jComputer.jFinder(xi,xj);
			A(xi, xj) = j;
			A(xj, xi) = j;
			}
		}
	//A.print();
	/* if(!is_symmetric(A)){
		cerr<<"Matrix Not Hermitian!\n";
	}
	*/
	return;
}

void RunSimA::getEnergies(int length, vec& energies, double W){
	// make random
	arma_rng::set_seed_random();
	default_random_engine generator;
	uniform_int_distribution<int> distribution(1,this->MAX_JUMP);

	vec nValues;
	vec lValues;
	this->getNsAndLs(length, W, nValues, lValues);

	for (int i = 0; i < length; i++){
		char nc = (char) nValues(i);
		char lc = (char) lValues(i);

		double delta =  distribution(generator);

		double lower = bindingEnergy(nc,lc);
		double upper = bindingEnergy(nc+delta, lc+1);
		if ((lower - upper) > 2){
			cout<<"lower = "<<lower<<", upper = "<<upper<<", n ="<<nValues(i)<<", delta = "<<delta<<"\n";
		}
		energies(i) = lower - upper;
	}

	//nValues.print("n values\n");
	//lValues.print("l values\n");
	//energies.print("energies\n");

}
