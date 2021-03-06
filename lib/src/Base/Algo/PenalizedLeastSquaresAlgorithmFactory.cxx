//                                               -*- C++ -*-
/**
 *  @brief A factory for building PenalizedLeastSquaresAlgorithm objects
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

#include "openturns/PersistentObjectFactory.hxx"
#include "openturns/PenalizedLeastSquaresAlgorithmFactory.hxx"

BEGIN_NAMESPACE_OPENTURNS



CLASSNAMEINIT(PenalizedLeastSquaresAlgorithmFactory);

static const Factory<PenalizedLeastSquaresAlgorithmFactory> RegisteredFactory;

/* Default constructor */
PenalizedLeastSquaresAlgorithmFactory::PenalizedLeastSquaresAlgorithmFactory(const Bool useNormal)
  : ApproximationAlgorithmImplementationFactory()
  , useNormal_(useNormal)
{
  // Nothing to do
}

/* Virtual constructor */
PenalizedLeastSquaresAlgorithmFactory * PenalizedLeastSquaresAlgorithmFactory::clone() const

{
  return new PenalizedLeastSquaresAlgorithmFactory(*this);
}

/* String converter */
String PenalizedLeastSquaresAlgorithmFactory::__repr__() const
{
  return OSS() << "class=" << GetClassName();
}

/* Method to create new PenalizedLeastSquaresAlgorithm objects */
PenalizedLeastSquaresAlgorithm * PenalizedLeastSquaresAlgorithmFactory::build(const NumericalSample & x,
    const NumericalSample & y,
    const NumericalPoint & weight,
    const Basis & psi,
    const Indices & indices) const
{
  const PenalizedLeastSquaresAlgorithm algo( x, y, weight, psi, indices, false, useNormal_ );
  return algo.clone();
}

/* Method save() stores the object through the StorageManager */
void PenalizedLeastSquaresAlgorithmFactory::save(Advocate & adv) const
{
  ApproximationAlgorithmImplementationFactory::save(adv);
}

/* Method load() reloads the object from the StorageManager */
void PenalizedLeastSquaresAlgorithmFactory::load(Advocate & adv)
{
  ApproximationAlgorithmImplementationFactory::load(adv);
}

END_NAMESPACE_OPENTURNS
