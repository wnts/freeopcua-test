#include "baseobject.h"

#include <vector>

#include "typednode.h"
#include "objecttype.h"

using namespace std;
using namespace OpcUa;

std::shared_ptr<ObjectType> BaseObject::s_pObjType;

BaseObject::BaseObject(OpcUa::NodeId nodeId,
					   OpcUa::LocalizedText browseName,
					   OpcUa::LocalizedText displayName,
					   OpcUa::LocalizedText description,
					   NodeManager * pNodeManager,
					   OpcUa::NodeId parentNode,
					   OpcUa::NodeId parentReferenceType)
: BaseObject(nodeId, browseName, displayName, description, pNodeManager, parentNode, parentReferenceType, false)
{
	setType(ObjectId::BaseObjectType);
}

BaseObject::BaseObject(OpcUa::NodeId nodeId,
					   OpcUa::LocalizedText browseName,
					   OpcUa::LocalizedText displayName,
					   OpcUa::LocalizedText description,
					   NodeManager * pNodeManager,
					   OpcUa::NodeId parentNode,
					   OpcUa::NodeId parentReferenceType,
					   bool bSetType)
: TypedNode(nodeId, browseName, displayName, description, parentNode, parentReferenceType, pNodeManager)

{
	AddNodesItem newObjNode;
	ObjectAttributes newObjAttrs;

	newObjNode.RequestedNewNodeId = nodeId;
	newObjNode.BrowseName = QualifiedName(browseName.Text, pNodeManager->getNamespaceIdx());
	newObjNode.Class = NodeClass::Object;
	newObjNode.ParentNodeId = parentNode;
	newObjNode.ReferenceTypeId = parentReferenceType;
	newObjAttrs.DisplayName = displayName;
	newObjAttrs.Description = description;
	newObjNode.Attributes = newObjAttrs;

	pNodeManager->addNodes(std::vector<AddNodesItem>{newObjNode});

}

NodeClass BaseObject::getNodeClass()
{
	return NodeClass::ObjectType;
}

BaseObject::~BaseObject(){}
