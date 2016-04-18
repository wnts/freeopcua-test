#include <memory>

#include "analogitem.h"

AnalogItem::AnalogItem(OpcUa::NodeId nodeId,
			       	   OpcUa::LocalizedText browseName,
					   OpcUa::LocalizedText displayName,
					   OpcUa::LocalizedText description,
					   NodeManager * pNodeManager,
					   OpcUa::NodeId parentNode,
					   OpcUa::NodeId parentReferenceType)
: AnalogItem(nodeId, browseName, displayName, description, pNodeManager, parentNode, parentReferenceType, ObjectId::Number, true)
{

}

AnalogItem::AnalogItem(OpcUa::NodeId nodeId,
			       	   OpcUa::LocalizedText browseName,
					   OpcUa::LocalizedText displayName,
					   OpcUa::LocalizedText description,
					   NodeManager * pNodeManager,
					   OpcUa::NodeId parentNode,
					   OpcUa::NodeId parentReferenceType,
					   OpcUa::NodeId dataType,
					   bool bSetType)
: DataItem(nodeId, browseName, displayName, description, pNodeManager, parentNode, parentReferenceType, dataType, false)
{
	/* normally we would instantiate a VariableType object here, to create the BaseDataVariableType in the address space
	 * but BaseDataVariableType is already in the address space, through a mechanism other than instantiating a Type class (see notes.txt)
	 */
	if(bSetType)
		setType(ObjectId::AnalogItemType);
	// create mandatory properties
	pEURange = std::make_shared<Property>(NodeId(nodeId.GetStringIdentifier() + ".EURange", pNodeManager->getNamespaceIdx()),
										  LocalizedText("EURange"),
										  LocalizedText("EURange"),
										  LocalizedText("EURange"),
										  pNodeManager,
										  getNodeId(),
										  ObjectId::Range);
}

AnalogItem::AnalogItem(BaseVariable * pInstanceDeclaration,
					   OpcUa::NodeId nodeId,
		 	 	 	   NodeManager * pNodeManager,
					   OpcUa::NodeId parentNode)
: AnalogItem(nodeId,
		     pInstanceDeclaration->getBrowseName(),
			 pInstanceDeclaration->getDisplayName(),
			 pInstanceDeclaration->getDescription(),
			 pNodeManager,
			 parentNode,
			 ObjectId::HasComponent)
{

}

OpcUa::Variant AnalogItem::getEURange() const
{
	return pEURange->getValue();
}

void AnalogItem::setEURange(const OpcUa::Variant& value)
{
	pEURange->setValue(value);
}

OpcUa::Variant AnalogItem::getEngineeringUnits() const
{
	if(!pEngineeringUnits)
		throw std::logic_error("Optional properties must be set first");
	return pEngineeringUnits->getValue();

}

void AnalogItem::setEngineeringUnits(const OpcUa::Variant& value)
{
	if(!pEngineeringUnits)
	{
		pEngineeringUnits = std::make_shared<Property>(NodeId(getNodeId().GetStringIdentifier() + ".EngineeringUnits", m_pNodeManager->getNamespaceIdx()),
													   LocalizedText("EngineeringUnits"),
													   LocalizedText("EngineeringUnits"),
													   LocalizedText("EngineeringUnits"),
													   m_pNodeManager,
													   getNodeId(),
													   ObjectId::EUInformation,
													   false);
	}
	pEngineeringUnits->setValue(value);
}





