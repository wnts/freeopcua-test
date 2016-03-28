/*
 * myobject.cpp
 *
 *  Created on: Mar 23, 2016
 *      Author: wouter
 */
#include <opc/ua/services/node_management.h>
#include <opc/ua/model.h>
#include "nodemanager.h"
#include "baseobject.h"


using namespace OpcUa;
using namespace OpcUa::Model;
using namespace std;

BaseObject::BaseObject(const string& name, NodeId objectType, NodeId nodeId, OpcUa::NodeManager * pNodeManager)
{
	AddNodesItem newObject;
	ObjectAttributes newObjectAttr;

	newObject.RequestedNewNodeId = nodeId;
	newObject.BrowseName = QualifiedName(name, pNodeManager->getNamespaceIdx());
	newObject.Class = NodeClass::Object;
	newObject.ParentNodeId = ObjectId::RootFolder;
	newObject.ReferenceTypeId = ReferenceId::Organizes;
	newObject.TypeDefinition = objectType;
	newObjectAttr.Description = LocalizedText(name);
	newObjectAttr.DisplayName = LocalizedText(name);
	newObject.Attributes = newObjectAttr;
	pNodeManager->addNodes(std::vector<AddNodesItem>{newObject});

	AddReferencesItem newObjectReference;
	newObjectReference.ReferenceTypeId == ReferenceId::HasTypeDefinition;
	newObjectReference.SourceNodeId = nodeId;
	newObjectReference.TargetNodeId = objectType;
	newObjectReference.TargetNodeClass = NodeClass::ObjectType;
	newObjectReference.IsForward = true;
	std::vector<StatusCode> result = pNodeManager->addReferences(std::vector<AddReferencesItem>{newObjectReference});
	result;
}

BaseObject::~BaseObject()
{

}





