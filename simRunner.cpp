#include <iostream>
#include <math.h>
#include <armadillo>
#include <string>
#include <random>
#include "simRunner.h"
#include "jComputer.h"
#include "findE.h"

SimRunner::SimRunner(){
    //TODO
}
SimRunner::~SimRunner(){
    //TODO
}
SimRunner::SimRunner( const SimRunner& anotherSimRunner ){
    //TODO
}
int SimRunner::is_symmetric(const mat& A){
    if (A.n_rows != A.n_cols){
        return 0;
    }
    for (unsigned int i = 0; i< A.n_rows;i++){
        for (unsigned int j = 0; j<A.n_cols;j++){
            if(A(i,j) != A(j,i)){
                return 0;
            }
        }
    }
    return 1;
}