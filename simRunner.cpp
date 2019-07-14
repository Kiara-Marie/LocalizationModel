#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include <random>
#include "jComputer.h"
#include "findE.h"

using namespace arma;
using namespace std;

        SimRunner::SimRunner(){
            //TODO
        }
		SimRunner::~SimRunner(){
            //TODO
        }
		SimRunner::SimRunner( const SimRunner& anotherSimRunner ){
            //TODO
        }
        double SimRunner::findT(int xi, int xj){
            //TODO
        }
        int SimRunner::is_symmetric(const mat& A){
            //TODO
        }
        void SimRunner::getEnergies(int length, vec& energies, double W){
            //TODO
        }
        void SimRunner::runSim(double W, int length, mat& A, JComputer& jComputer){
            //TODO
        }