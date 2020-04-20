#Program Information

This program creates a matrix representing a lattice of two-level systems with numSites sites, with random spacings between the levels, as specified in the diagonal terms, with random interactions on the off-diagonals.  


Some files in this repository are not used in the current version of the program.
Those used in the current version are:

**epsilonSum1D.cpp** - This is essentially the main file, which can be compiled and run from the command line.

**metric.cpp (metric.h)** - This is an abstract class to describe different metrics which might be used to analyse the results of this computation. Subclasses currently include:

	levelSpacings.cpp (levelSpacings.h)
	avgEigVec.cpp (avgEigVec.h)
	aboutRun.cpp (aboutRun.h)

**utils.cpp (utils.h)** - This is a file to put miscellaneous useful functions, which currently just contains functions to create date strings

**findE.cpp (findE.h)** - This file is actually written in C, and is basically also some utils which can be used for computing energies

**simRunner.cpp (simRunner.h)** - This is an abstract class for the step which creates the random matrices (the diagonal entries). Current subclasses include:

	runSimRid.cpp
	runSimSimple.cpp
	runSimA.cpp

**jComputer.cpp (jComputer.h)** - This is also an abstract class. There are many options of jComputer, which compute the off-diagonal elements, and they are all found in the jComputers folder. They include:

	constant.cpp
	gauss.cpp
	lorentz.cpp
	lorentzWithoutRDep.cpp

**resultFinder.cpp (resultFinder.h)** - This file diagonalizes the matrices and calls the functions in the metrics to find infromation about them. Another option is resultFinderNoDiag.cpp which does not diagonalize the matrices, which is sometimes useful for debugging / sanity checks.

**Makefile** - This compiles the whole thing


#Testing

There is a folder called googletest, in which I have started doing some testing. You can run the tests by going into googletest/make and running ./mostTests. The file which contains the tests is googletest/myTests/mostTests.cc
