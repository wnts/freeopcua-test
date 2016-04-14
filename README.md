# freeopcua-test
FreeOpcUa Test

High level abstraction built on top of the FreeOpcUa library. This library is meant to provide a programming interface
to an OPC UA server that maps more closely to C++. In a nutshell:
* OPC nodes  are represented by C++ classes.
* OPC nodes with a type (Variables, Objects) can be subtyped by deriving new classes from a base class representing the supertype
* Dynamic node management:
 * nodes are created in the address space when instantiating C++ objects
 *  nodes are deleted in the address space when C++ objects are destructed


This software package is documented with doxygen. (It is recommended to run doxygen with graphviz enabled to generate nice graphs of the inheritance tree)

## Todo
1. Node deletion upon object destruction
2. Fix Issues (see Issues tab)
3. Merge into FreeOpcUa (fork then pull request)
