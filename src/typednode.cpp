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
	AddReferencesItem typeRef;

	typeRef.IsForward = true;
	typeRef.SourceNodeId = this->getNodeId();
	typeRef.TargetNodeId = type;
	// they set this to DataType for every targetnodeclass in the SDK too.
	typeRef.TargetNodeClass = NodeClass::DataType;
	typeRef.ReferenceTypeId = ObjectId::HasTypeDefinition;

	m_pNodeManager->addReferences(vector<AddReferencesItem>{typeRef});

}
