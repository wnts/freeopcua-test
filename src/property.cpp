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
: Variable(nodeId, browseName, displayName, description, pNodeManager, parentNode, ReferenceId::HasProperty, dataType, false)
{
	setType(ObjectId::PropertyType);
	NodeId ModellingTarget = ObjectId::ModellingRule_Optional;
	if(mandatory)
		ModellingTarget = ObjectId::ModellingRule_Mandatory;
	addReference(getNodeId(), ModellingTarget, ObjectId::HasModellingRule, true);

}


