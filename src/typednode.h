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
				  NodeManager * pNodeManager);
		TypedNode(OpcUa::NodeId nodeId,
				  OpcUa::LocalizedText browseName,
				  OpcUa::LocalizedText displayName,
				  OpcUa::LocalizedText description,
				  TypeNode * pTypeNode,
				  NodeManager * pNodeManager);
		virtual ~TypedNode() = 0;
		TypeNode * getType();
		OpcUa::NodeId getTypeNodeId();

	protected:
		void setType(NodeId type);
		void setType(TypeNode * pTypeNode);
		TypeNode * m_pType = NULL;
};





#endif /* SRC_TYPEDNODE_H_ */
