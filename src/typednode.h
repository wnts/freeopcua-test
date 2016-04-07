#ifndef SRC_TYPEDNODE_H_
#define SRC_TYPEDNODE_H_
#include "typenode.h"
#include "nodemanager.h"
/**
 * Abstract class representing an OPC Node with a type.
 *
 * A Node with a type always has a HasTypeDefinition reference to an OPC type Node (%VariableType, %ObjectType, ...) *
 * @sa TypeNode
 */
class TypedNode : public ::Node
{
	public:
		TypedNode(OpcUa::NodeId nodeId,
				  OpcUa::LocalizedText browseName,
				  OpcUa::LocalizedText displayName,
				  OpcUa::LocalizedText description,
				  OpcUa::NodeId parentNode,
				  OpcUa::NodeId parentReferenceType,
				  NodeManager * pNodeManager);

		virtual ~TypedNode() = 0;
		OpcUa::NodeId getType();
		OpcUa::NodeId getTypeNodeId();

	protected:
		void setType(NodeId type);
		OpcUa::NodeId m_Type;
};





#endif /* SRC_TYPEDNODE_H_ */
