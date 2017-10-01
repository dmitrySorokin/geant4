// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
// $Id: $
//
// Helper namespace 'magneticfield'
//
// Description:
//    Modified midpoint method implementation
//    Implementation is based on modified_midpoint.hpp from boost
//
//    Implementation by Dmitry Sorokin - GSoC 2016
//       Work supported by Google as part of Google Summer of Code 2016.
//    Supervision / code review: John Apostolakis
//
///////////////////////////////////////////////////////////////////////////////

#ifndef G4MODIFIED_MIDPOINT_HH
#define G4MODIFIED_MIDPOINT_HH

#include "G4Types.hh"
#include "G4FieldTrack.hh"
#include "G4EquationOfMotion.hh"

class G4ModifiedMidpoint {
public:
    G4ModifiedMidpoint(
        G4EquationOfMotion* equation,
        G4int nvar = 6,
        G4int steps = 2);

    ~G4ModifiedMidpoint();

    void DoStep(
        const G4double xIn[],
        const G4double dxdtIn[],
        G4double xOut[],
        G4double dt);

    inline void SetSteps(G4int steps);

    inline G4int Steps() const;

private:
    G4EquationOfMotion* fEquation;
    G4int fnvar;
    G4int fsteps;

    G4double x0[G4FieldTrack::ncompSVEC];
    G4double x1[G4FieldTrack::ncompSVEC];
    G4double dxdt[G4FieldTrack::ncompSVEC];
    G4double tmp[G4FieldTrack::ncompSVEC];
};

#include "G4ModifiedMidpoint.icc"

#endif
