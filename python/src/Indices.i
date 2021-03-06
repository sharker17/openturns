// SWIG file Indices.i

%{
#include "openturns/Indices.hxx"
%}

%include Indices_doc.i

%typemap(in) const Indices & ($1_basetype temp) {
  if (! SWIG_IsOK(SWIG_ConvertPtr($input, (void **) &$1, $1_descriptor, 0))) {
    try {
      temp = OT::convert<OT::_PySequence_,OT::Indices>( $input );
      $1 = &temp;
    } catch (OT::InvalidArgumentException & ex) {
      SWIG_exception(SWIG_TypeError, "Object passed as argument is not convertible to an Indices");
    }
  }
}

%typemap(typecheck,precedence=SWIG_TYPECHECK_POINTER) const Indices & {
  $1 = SWIG_IsOK(SWIG_ConvertPtr($input, NULL, $1_descriptor, 0)) ||
       OT::isAPythonSequenceOf<OT::_PyInt_>( $input );
}

%apply const Indices & { const OT::Indices & };

%include openturns/Indices.hxx
namespace OT {  

%extend Indices {

  Indices(const Indices & other) { return new OT::Indices(other); }  

  Indices(PyObject * pyObj) { return new OT::Indices( OT::convert<OT::_PySequence_,OT::Indices>(pyObj) ); }
  
  OT_COLLECTION_GETITEM(OT::Indices, OT::UnsignedInteger)
  OT_COLLECTION_SETITEM(OT::Indices, OT::UnsignedInteger)

  Bool __eq__(const Indices & other) { return (*self) == other; }

} // Indices

} // OT
