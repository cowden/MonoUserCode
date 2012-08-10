#ifndef MONOALGORITHMS_MONOECALCLUSTER_H
#define MONOALGORITHMS_MONOECALCLUSTER_H
///////////////////////////////////////////////////////////////
// C S Cowden					10 July 2012
// Cluster class for monopole Ecal observables
//////////////////////////////////////////////////////////////

#include "Monopoles/MonoAlgorithms/interface/MonoEcalSeed.h"

namespace Mono {

class EBmap;

class MonoEcalCluster {

public:

  inline MonoEcalCluster(): m_length(0U),m_width(0U),m_iEta(0U),m_iPhi(0U),m_energy(0.) { }

  inline MonoEcalCluster(const unsigned L, const unsigned W, const unsigned iEta, const unsigned iPhi
    ,const double E, const MonoEcalSeed & S)
    :m_length(L)
    ,m_width(W)
    ,m_iEta(iEta)
    ,m_iPhi(iPhi)
    ,m_energy(E)
    ,m_seed(S)
    { }

  inline virtual ~MonoEcalCluster() { }

  // accessor methods
  inline const unsigned clusterLength() const { return m_length; }
  inline const unsigned clusterWidth() const { return m_width; }
  inline const unsigned ieta() const { return m_iEta; }
  inline const unsigned iphi() const { return m_iPhi; }
  inline const double   clusterEnergy() const { return m_energy; }
  inline const MonoEcalSeed & clusterSeed() const { return m_seed; }

  // return the energy in cell of EBmap 
  // the integer arguments are differences between the cluster's
  // ieta and iphi respectively.
  const double energy(int,int,const EBmap &) const;
  

private:

  // eta length
  unsigned m_length;
  // phi width
  unsigned m_width;
  // eta bin (lowest eta edge)
  unsigned m_iEta;
  // phi bin (middle in phi)
  unsigned m_iPhi;
  // energy
  double m_energy;
  // seed
  MonoEcalSeed m_seed; 

};


} // end Mono namespace

#endif