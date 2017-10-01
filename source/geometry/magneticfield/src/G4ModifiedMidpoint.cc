#include "G4ModifiedMidpoint.hh"

namespace internal {

G4ModifiedMidpoint::G4ModifiedMidpoint(
    G4EquationOfMotion* equation,
    G4int nvar,
    G4int steps)
        : fEquation(equation)
        , fnvar(nvar)
        , fsteps(steps)
{
}

G4ModifiedMidpoint::~G4ModifiedMidpoint()
{
}


void G4ModifiedMidpoint::do_step(
    const G4double xIn[],
    const G4double dxdtIn[],
    G4double xOut[],
    G4double dt)
{
    const G4double h = dt / fsteps;
    const G4double h2 = 2 * h;

    // x1 = xIn + h * dxdt
    for (G4int i = 0; i < fnvar; ++i) {
        x1[i] = xIn[i] + h * dxdtIn[i];
    }

    fEquation->RightHandSide(x1, dxdt);

    memcpy(x0, xIn, sizeof(G4double) * fnvar);

    // general step
    //tmp = x1; x1 = x0 + h2 * dxdt; x0 = tmp
    for (G4int i = 1; i < fsteps; ++i) {
        memcpy(tmp, x1, sizeof(G4double) * fnvar);
        for (G4int j = 0; j < fnvar; ++j){
            x1[j] = x0[j] + h2 * dxdt[j];
        }
        memcpy(x0, tmp, sizeof(G4double) * fnvar);

        fEquation->RightHandSide(x1, dxdt);
    }

    // last step
    // xOut = 0.5 * (x0 + x1 + h * dxdt)
    for (G4int i = 0; i < fnvar; ++i) {
        xOut[i] = 0.5 * (x0[i] + x1[i] + h * dxdt[i]);
    }
}

} // internal




