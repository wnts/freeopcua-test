#include <vector>

#include "typednode.h"
#include "node.h"
#include "nodemanager.h"

using namespace std;

TypedNode::TypedNode(OpcUa::NodeId nodeId,
					 OpcUa::LocalizedText browseName,
					 OpcUa::LocalizedText displayName,
					 OpcUa::LocalizedText description,
					 OpcUa::NodeId parentNode,
					 OpcUa::NodeId parentReferenceType,
					 NodeManager * pNodeManager)

: Node(nodeId, browseName, displayName, description, parentNode, parentReferenceType, pNodeManager)
{

}

TypedNode::~TypedNode(){}


NodeId TypedNode::getType()
{
	return m_Type;
}

void TypedNode::setType(NodeId type)
{
	addReference(getNodeId(), type, ObjectId::HasTypeDefinition, NodeClass::ObjectType);
}
