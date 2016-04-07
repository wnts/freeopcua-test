#include <opc/ua/model.h>
#include "property.h"

using namespace OpcUa::Model;

Property::Property(OpcUa::NodeId nodeId,
				   OpcUa::LocalizedText browseName,
				   OpcUa::LocalizedText displayName,
				   OpcUa::LocalizedText description,
				   NodeManager * pNodeManager,
				   OpcUa::NodeId parentNode,
				   OpcUa::NodeId dataType)
: Variable(nodeId, browseName, displayName, description, pNodeManager, parentNode, ReferenceId::HasProperty, dataType)
{
	setType(ObjectId::PropertyType);
}


