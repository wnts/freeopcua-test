#include "objecttype.h"

using namespace OpcUa;

ObjectType::ObjectType(OpcUa::NodeId nodeId,
					   OpcUa::LocalizedText browseName,
					   OpcUa::LocalizedText displayName,
					   OpcUa::LocalizedText description,
					   bool isAbstract,
					   OpcUa::NodeId parentNode,
					   OpcUa::NodeId parentReferenceType,
					   NodeManager * pNodeManager)
: TypeNode(nodeId, browseName, displayName, description, isAbstract, parentNode, parentReferenceType, pNodeManager)
{
	AddNodesItem newObjTypeNode;
	ObjectTypeAttributes newObjTypeNodeAttrs;

	newObjTypeNode.RequestedNewNodeId = nodeId;
	newObjTypeNode.BrowseName = QualifiedName(browseName.Text, pNodeManager->getNamespaceIdx());
	newObjTypeNode.Class = this->getNodeClass();
	newObjTypeNode.ParentNodeId = ObjectId::BaseObjectType;
	newObjTypeNode.ReferenceTypeId = ReferenceId::HasSubtype;

	newObjTypeNodeAttrs.DisplayName = displayName;
	newObjTypeNodeAttrs.IsAbstract = isAbstract;
	newObjTypeNode.Attributes = newObjTypeNodeAttrs;

	// todo : add error handling for when this fails
	pNodeManager->addNodes(std::vector<AddNodesItem>{newObjTypeNode});
}

NodeClass ObjectType::getNodeClass()
{
	return NodeClass::ObjectType;
}


