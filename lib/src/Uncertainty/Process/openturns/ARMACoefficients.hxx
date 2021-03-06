//                                               -*- C++ -*-
/**
 *  @brief ARMACoefficients class enables to stock coefficients of an ARMA process
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
#ifndef OPENTURNS_ARMACOEFFICIENTS_HXX
#define OPENTURNS_ARMACOEFFICIENTS_HXX

#include "openturns/PersistentCollection.hxx"
#include "openturns/SquareMatrix.hxx"
#include "openturns/NumericalPoint.hxx"
#include "openturns/Collection.hxx"
#include "openturns/UniVariatePolynomial.hxx"

BEGIN_NAMESPACE_OPENTURNS

/**
 * @class ARMACoefficients
 *
 * Coefficients of ARMA process
 *
 */
class OT_API ARMACoefficients
  : public PersistentCollection<SquareMatrix>
{
  CLASSNAME;

public:

  /** Some typedefs to ease reading */
  typedef Collection<SquareMatrix>             SquareMatrixCollection;
  typedef PersistentCollection<SquareMatrix>   SquareMatrixPersistentCollection;

  /** Default and standard constructors */
  explicit ARMACoefficients(const UnsignedInteger & size = 0,
                            const UnsignedInteger & dimension = 1);
  explicit ARMACoefficients(const SquareMatrixCollection & collection);
  explicit ARMACoefficients(const NumericalPoint & ScalarCoefficients);
  explicit ARMACoefficients(const UniVariatePolynomial & polynomial);

  /** Virtual constructor */
  virtual ARMACoefficients * clone() const;

  /** String converter */
  String __repr__() const;
  String __str__(const String & offset = "") const;

  /** Dimension accessor */
  UnsignedInteger getDimension() const;

  /** Definition of add method : control of SquareMatrix sizes */
  void add(const SquareMatrix & matrix);
  void add(const NumericalScalar scalar);

  /** Method save() stores the object through the StorageManager */
  void save(Advocate & adv) const;

  /** Method load() reloads the object from the StorageManager */
  void load(Advocate & adv);

private:

  /** Dimension of the underlying ARMA process */
  UnsignedInteger dimension_;

}; /* class ARMACoefficients */
END_NAMESPACE_OPENTURNS

#endif /* OPENTURNS_ARMACOEFFICIENTS_HXX */
