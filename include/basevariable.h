#ifndef SRC_VARIABLE_H_
#define SRC_VARIABLE_H_
#include "node.h"
#include "typednode.h"
#include "variabletype.h"
#include "nodemanager.h"

/**
 * Abstract class representing a Variable node in the address space.
 * Actual Variables in the address space are represented by creating non-abstract
 * classes that derive from this class. When such a class is instantiated, a corresponding
 * Variable node is created in the address space.
 */
class BaseVariable : public TypedNode
{
	public:
		/**
		 * @copydoc Node::Node()
		 *
		 * @param dataType The Node Id of the datatype node for this Variable.
		 */
		BaseVariable(OpcUa::NodeId nodeId,
					 OpcUa::LocalizedText browseName,
					 OpcUa::LocalizedText displayName,
					 OpcUa::LocalizedText description,
					 NodeManager * pNodeManager,
					 OpcUa::NodeId parentNode,
					 OpcUa::NodeId parentReferenceType,
					 OpcUa::NodeId dataType,
					 bool bSetType);

		virtual ~BaseVariable() = 0;
		void setValue(OpcUa::Variant value);
		OpcUa::Variant getValue() const;
		OpcUa::DataValue getData() const;
		OpcUa::NodeClass getNodeClass();
};

#endif /* SRC_VARIABLE_H_ */
