#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include "metrics/metric.h"
#include "resultFinder.h"
using namespace std;
using namespace arma;

ResultFinder::ResultFinder(vector<metric*> metrics){
	this->metrics = metrics;
}

pair<vec, mat> ResultFinder::saveResults(mat& A, int iterations){
	vec eigval;
	mat eigvec;
	// diagonalize the matrix, assuming it's symmetric
	eig_sym(eigval, eigvec, A);
	for (unsigned int i = 0; i< this->metrics.size(); i++){
		this->metrics[i]->save(eigval, eigvec, A, iterations);
	}
	return pair<vec, mat>(eigval,eigvec);
}

void ResultFinder::printResults(){
	for (unsigned int i = 0; i< this->metrics.size(); i++){
		this->metrics[i]->printResult();
	}
}
