#include <memory>

#include "analogitem.h"
#include "property.h"

AnalogItem::AnalogItem(OpcUa::NodeId nodeId,
			       	   OpcUa::LocalizedText browseName,
					   OpcUa::LocalizedText displayName,
					   OpcUa::LocalizedText description,
					   NodeManager * pNodeManager,
					   OpcUa::NodeId parentNode,
					   OpcUa::NodeId parentReferenceType,
					   OpcUa::NodeId dataType)
: DataItem(nodeId, browseName, displayName, description, pNodeManager, parentNode, parentReferenceType, dataType)
{
	/* normally we would instantiate a VariableType object here, to create the BaseDataVariableType in the address space
	 * but BaseDataVariableType is already in the address space, through a mechanism other than instantiating a Type class (see notes.txt)
	 */
	setType(ObjectId::AnalogItemType);
	// create properties
	pEURange = std::make_shared<Property>(NodeId(browseName.Text + "_EURange", pNodeManager->getNamespaceIdx()),
										  LocalizedText("EURange"),
										  LocalizedText("EURange"),
										  LocalizedText("EURange"),
										  pNodeManager,
										  ObjectId::Range);
	addReference(getNodeId(), pEURange->getNodeId(), ObjectId::HasProperty, true);
	addReference(pEURange->getNodeId(), ObjectId::ModellingRule_Mandatory, ObjectId::HasModellingRule, true);
}


