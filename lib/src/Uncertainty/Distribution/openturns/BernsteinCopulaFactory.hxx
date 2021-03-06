//                                               -*- C++ -*-
/**
 *  @brief This class implements a non parametric density estimator for copulas
 *         based on the Bernstein copula approximation of the empirical copula
 *
 *  Copyright 2005-2016 Airbus-EDF-IMACS-Phimeca
 *
 *  This library is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  along with this library.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef OPENTURNS_BERNSTEINCOPULAFACTORY_HXX
#define OPENTURNS_BERNSTEINCOPULAFACTORY_HXX

#include "openturns/DistributionFactoryImplementation.hxx"
#include "openturns/Distribution.hxx"
#include "openturns/NumericalSample.hxx"

BEGIN_NAMESPACE_OPENTURNS

/**
 * @class BernsteinCopulaFactory
 *
 * The class describes the probabilistic concept of BernsteinCopulaFactory.
 */
class OT_API BernsteinCopulaFactory
  : public DistributionFactoryImplementation
{
  CLASSNAME;
public:

  /** Default constructor */
  BernsteinCopulaFactory();

  /** Virtual constructor */
  virtual BernsteinCopulaFactory * clone() const;

  /** Build a Bernstein copula based on the given sample. The bin number is computed according to the inverse power rule */
  virtual Distribution build(const NumericalSample & sample);

  /** Build a Bernstein copula based on the given sample and bin number */
  virtual Distribution build(const NumericalSample & sample,
                             const UnsignedInteger binNumber);

  /** Compute the number of bins according to the inverse power rule */
  UnsignedInteger computeBinNumber(const NumericalSample & sample);

private:

}; /* class BernsteinCopulaFactory */


END_NAMESPACE_OPENTURNS

#endif /* OPENTURNS_BERNSTEINCOPULAFACTORY_HXX */
