#ifndef SRC_TYPEDNODE_H_
#define SRC_TYPEDNODE_H_
#include "typenode.h"
#include "nodemanager.h"

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
		virtual ~TypedNode();
		TypeNode * getType();
		OpcUa::NodeId getTypeNodeId();
		void setType(TypeNode * pTypeNode);
	protected:
		TypeNode * m_pType = NULL;
};





#endif /* SRC_TYPEDNODE_H_ */
