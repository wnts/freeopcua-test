#include "basevariable.h"

#ifndef SRC_PROPERTY_H_
#define SRC_PROPERTY_H_

/**
 * Class representing an OPC Property in the address space.
 * A property is an OPC Node with NodeClass "Variable" and a HasTypeDefinition reference
 * to PropertyType.
 */
class Property : public BaseVariable
{
public:
	/**
	 * @copydoc Variable::Variable()
	 */
	Property(OpcUa::NodeId nodeId,
			 OpcUa::LocalizedText browseName,
			 OpcUa::LocalizedText displayName,
			 OpcUa::LocalizedText description,
			 NodeManager * pNodeManager,
			 OpcUa::NodeId parentNode,
			 OpcUa::NodeId dataType,
			 bool mandatory = false);
	Property(Property * pInstanceDeclaration,
			 OpcUa::NodeId nodeId,
			 NodeManager * pNodeManager,
			 OpcUa::NodeId parentNode);
};




#endif /* SRC_PROPERTY_H_ */
