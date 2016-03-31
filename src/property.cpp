#include "property.h"

Property::Property(OpcUa::NodeId nodeId,
			       OpcUa::LocalizedText browseName,
			       OpcUa::LocalizedText displayName,
			       OpcUa::LocalizedText description,
			       NodeManager * pNodeManager,
				   OpcUa::NodeId dataType)
: Variable(nodeId, browseName, displayName, description, pNodeManager, dataType)
{
	setType(ObjectId::PropertyType);
}


