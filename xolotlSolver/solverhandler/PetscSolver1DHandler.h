#ifndef PETSCSOLVER1DHANDLER_H
#define PETSCSOLVER1DHANDLER_H

// Includes
#include "PetscSolverHandler.h"

namespace xolotlSolver {

/**
 * This class is a subclass of PetscSolverHandler and implement all the methods needed
 * to solve the ADR equations in 1D using PETSc from Argonne National Laboratory.
 */
class PetscSolver1DHandler: public PetscSolverHandler {
public:

	//! The Constructor
	PetscSolver1DHandler() {}

	//! The Destructor
	~PetscSolver1DHandler() {}

	/**
	 * Create everything needed before starting to solve.
     * \see ISolverHandler.h
	 */
	void createSolverContext(DM &da, int nx, double hx, int ny,
			double hy, int nz, double hz);

	/**
	 * Initialize the concentration solution vector.
     * \see ISolverHandler.h
	 */
	void initializeConcentration(DM &da, Vec &C) const;

	/**
	 * Compute the new concentrations for the RHS function given an initial
	 * vector of concentrations. Apply the diffusion, advection and all the reactions.
     * \see ISolverHandler.h
	 */
	void updateConcentration(TS &ts, Vec &localC, Vec &F, PetscReal ftime,
			bool &temperatureChanged);

	/**
	 * Compute the off-diagonal part of the Jacobian which is related to cluster's motion.
     * \see ISolverHandler.h
	 */
	void computeOffDiagonalJacobian(TS &ts, Vec &localC, Mat &J) const;

	/**
	 * Compute the diagonal part of the Jacobian which is related to cluster reactions.
     * \see ISolverHandler.h
	 */
	void computeDiagonalJacobian(TS &ts, Vec &localC, Mat &J);

}; //end class PetscSolver1DHandler

} /* end namespace xolotlSolver */
#endif