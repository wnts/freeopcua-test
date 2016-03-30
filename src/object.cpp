#include "object.h"
#include "node.h"
#include "objecttype.h"

using namespace OpcUa;

Object::Object(OpcUa::NodeId nodeId,
			   OpcUa::LocalizedText browseName,
			   OpcUa::LocalizedText displayName,
			   OpcUa::LocalizedText description,
			   NodeId objType,
			   NodeManager * pNodeManager)
: Node(nodeId, browseName, displayName, description, pNodeManager)
{
	AddNodesItem newObjNode;
	ObjectAttributes newObjAttrs;

	newObjNode.RequestedNewNodeId = nodeId;
	newObjNode.BrowseName = QualifiedName(browseName.Text, pNodeManager->getNamespaceIdx());
	newObjNode.Class = NodeClass::Object;
	newObjNode.TypeDefinition = objType;
	newObjNode.ParentNodeId = ObjectId::ObjectsFolder;
	newObjNode.ReferenceTypeId = ReferenceId::Organizes;

	newObjAttrs.DisplayName = displayName;
	newObjAttrs.Description = description;
	newObjNode.Attributes = newObjAttrs;

	// todo: add error handling when this fails
	pNodeManager->addNodes(std::vector<AddNodesItem>{newObjNode});
}

NodeClass Object::getNodeClass()
{
	return NodeClass::ObjectType;
}
