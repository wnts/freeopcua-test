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
			   NodeManager * pNodeManager,
			   OpcUa::NodeId parentNode,
			   OpcUa::NodeId parentReferenceType)
: TypedNode(nodeId, browseName, displayName, description, parentNode, parentReferenceType, pNodeManager)

{
	AddNodesItem newObjNode;
	ObjectAttributes newObjAttrs;

	newObjNode.RequestedNewNodeId = nodeId;
	newObjNode.BrowseName = QualifiedName(browseName.Text, pNodeManager->getNamespaceIdx());
	newObjNode.Class = NodeClass::Object;
	newObjAttrs.DisplayName = displayName;
	newObjAttrs.Description = description;
	newObjNode.Attributes = newObjAttrs;

	// todo: add error handling when this fails
	pNodeManager->addNodes(std::vector<AddNodesItem>{newObjNode});
	// todo this shouldn't be here
	addReference(parentNode, nodeId, parentReferenceType, true);
}

NodeClass Object::getNodeClass()
{
	return NodeClass::ObjectType;
}

Object::~Object(){}
