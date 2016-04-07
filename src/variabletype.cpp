#include "variabletype.h"

using namespace OpcUa;

VariableType::VariableType(OpcUa::NodeId nodeId,
					   	   OpcUa::LocalizedText browseName,
						   OpcUa::LocalizedText displayName,
						   OpcUa::LocalizedText description,
						   bool isAbstract,
						   OpcUa::NodeId parentNode,
						   OpcUa::NodeId parentReferenceType,
						   NodeManager * pNodeManager)
: TypeNode(nodeId, browseName, displayName, description, isAbstract, parentNode, parentReferenceType, pNodeManager)
{
	AddNodesItem newVarTypeNode;
	VariableTypeAttributes newVarTypeNodeAttrs;

	newVarTypeNode.RequestedNewNodeId = nodeId;
	newVarTypeNode.BrowseName = QualifiedName(browseName.Text, pNodeManager->getNamespaceIdx());
	newVarTypeNode.Class = this->getNodeClass();
	newVarTypeNode.ParentNodeId = ObjectId::BaseVariableType;
	newVarTypeNode.ReferenceTypeId = ReferenceId::HasSubtype;

	newVarTypeNodeAttrs.DisplayName = displayName;
	newVarTypeNodeAttrs.IsAbstract = isAbstract;
	newVarTypeNode.Attributes = newVarTypeNodeAttrs;

	// todo : add error handling for when this fails
	pNodeManager->addNodes(std::vector<AddNodesItem>{newVarTypeNode});
}

NodeClass VariableType::getNodeClass()
{
	return NodeClass::VariableType;
}
