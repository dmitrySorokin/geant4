// This code implementation is the intellectual property of
// the RD44 GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4AllocatorPage.hh,v 2.0 1998/07/02 17:32:37 gunter Exp $
// GEANT4 tag $Name: geant4-00 $
//
// 
// ------------------------------------------------------------
//      GEANT 4 class header file 
//
//      For information related to this code contact:
//      CERN, CN Division, ASD group
//      History: first implementation, based on object model of
//      2nd December 1995, G.Cosmo
//      -------------- G4AllocatorPage ----------------
//                by Tim Bell, September 1995
// ------------------------------------------------------------

#ifndef G4AllocatorPage_h
#define G4AllocatorPage_h 1

//G4AllocatorUnit
#include "G4AllocatorUnit.hh"

template <class Type>
class G4AllocatorPage
{
public:
  G4AllocatorPage<Type> *fNext;
  G4AllocatorUnit<Type> *fUnits;
};

#endif