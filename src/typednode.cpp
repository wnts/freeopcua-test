#include <vector>

#include "typednode.h"
#include "node.h"
#include "nodemanager.h"

using namespace std;

TypedNode::TypedNode(OpcUa::NodeId nodeId,
		    		 OpcUa::LocalizedText browseName,
					 OpcUa::LocalizedText displayName,
					 OpcUa::LocalizedText description,
					 NodeManager * pNodeManager)
: Node(nodeId, browseName, displayName, description, pNodeManager)
{

}

TypedNode::TypedNode(OpcUa::NodeId nodeId,
					 OpcUa::LocalizedText browseName,
					 OpcUa::LocalizedText displayName,
					 OpcUa::LocalizedText description,
					 TypeNode * pTypeNode,
					 NodeManager * pNodeManager)
: Node(nodeId, browseName, displayName, description, pNodeManager),
  m_pType(pTypeNode)
{

}

TypedNode::~TypedNode(){}


TypeNode * TypedNode::getType()
{
	return m_pType;
}

void TypedNode::setType(NodeId type)
{
	AddReferencesItem typeRef;

	typeRef.IsForward = true;
	typeRef.SourceNodeId = this->getNodeId();
	typeRef.TargetNodeId = type;
	//typeRef.TargetNodeClass = pTypeNode->getNodeClass();
	typeRef.ReferenceTypeId = ObjectId::HasTypeDefinition;

	m_pNodeManager->addReferences(vector<AddReferencesItem>{typeRef});

}

void TypedNode::setType(TypeNode * pTypeNode)
{
	setType(pTypeNode->getNodeId());
}

