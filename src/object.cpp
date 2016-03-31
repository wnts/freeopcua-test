#include <vector>

#include "object.h"
#include "typednode.h"
#include "objecttype.h"

using namespace std;
using namespace OpcUa;

Object::Object(OpcUa::NodeId nodeId,
			   OpcUa::LocalizedText browseName,
			   OpcUa::LocalizedText displayName,
			   OpcUa::LocalizedText description,
			   TypeNode& objType,
			   NodeManager * pNodeManager)
: TypedNode(nodeId, browseName, displayName, description, pNodeManager)

{
	AddNodesItem newObjNode;
	ObjectAttributes newObjAttrs;

	newObjNode.RequestedNewNodeId = nodeId;
	newObjNode.BrowseName = QualifiedName(browseName.Text, pNodeManager->getNamespaceIdx());
	newObjNode.Class = NodeClass::Object;
	newObjNode.TypeDefinition = objType.getNodeId();
	newObjNode.ParentNodeId = ObjectId::ObjectsFolder;
	newObjNode.ReferenceTypeId = ReferenceId::Organizes;

	newObjAttrs.DisplayName = displayName;
	newObjAttrs.Description = description;
	newObjNode.Attributes = newObjAttrs;

	// todo: add error handling when this fails
	pNodeManager->addNodes(std::vector<AddNodesItem>{newObjNode});
}

Object::Object(OpcUa::NodeId nodeId,
	   OpcUa::LocalizedText browseName,
	   OpcUa::LocalizedText displayName,
	   OpcUa::LocalizedText description,
	   NodeManager * pNodeManager)
: TypedNode(nodeId, browseName, displayName, description, pNodeManager)
{
	AddNodesItem newObjNode;
	ObjectAttributes newObjAttrs;

	newObjNode.RequestedNewNodeId = nodeId;
	newObjNode.BrowseName = QualifiedName(browseName.Text, pNodeManager->getNamespaceIdx());
	newObjNode.Class = NodeClass::Object;
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
