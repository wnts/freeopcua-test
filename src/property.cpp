#include <opc/ua/model.h>
#include "property.h"

using namespace OpcUa::Model;

Property::Property(OpcUa::NodeId nodeId,
				   OpcUa::LocalizedText browseName,
				   OpcUa::LocalizedText displayName,
				   OpcUa::LocalizedText description,
				   NodeManager * pNodeManager,
				   OpcUa::NodeId parentNode,
				   OpcUa::NodeId dataType,
				   bool mandatory)
: BaseVariable(nodeId, browseName, displayName, description, pNodeManager, parentNode, ReferenceId::HasProperty, dataType, false)
{
	setType(ObjectId::PropertyType);
	NodeId ModellingTarget = ObjectId::ModellingRule_Optional;
	if(mandatory)
		ModellingTarget = ObjectId::ModellingRule_Mandatory;
	addReference(getNodeId(), ModellingTarget, ObjectId::HasModellingRule, NodeClass::Object, true);

}

Property::Property(Property * pInstanceDeclaration,
				   OpcUa::NodeId nodeId,
		 	 	   NodeManager * pNodeManager,
				   OpcUa::NodeId parentNode)
: Property(nodeId,
	  	   pInstanceDeclaration->getBrowseName(),
		   pInstanceDeclaration->getDisplayName(),
		   pInstanceDeclaration->getDescription(),
		   pNodeManager,
		   parentNode,
		   ObjectId::HasComponent)
{

}


