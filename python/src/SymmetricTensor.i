// SWIG file SymmetricTensor.i

%{
#include "openturns/SymmetricTensor.hxx"
%}

%include SymmetricTensor_doc.i

%apply const NumericalScalarCollection & { const OT::SymmetricTensor::NumericalScalarCollection & };

%include openturns/SymmetricTensor.hxx

namespace OT {  

%extend SymmetricTensor {

  SymmetricTensor(const SymmetricTensor & other) { return new OT::SymmetricTensor(other); }

  SymmetricTensor(PyObject * pyObj) { return new OT::SymmetricTensor( OT::convert<OT::_PySequence_,OT::SymmetricTensor>(pyObj) ); }

  OTTensorAccessors(SymmetricTensor, NumericalScalar, _PyFloat_)

} // SymmetricTensor
} // OT
