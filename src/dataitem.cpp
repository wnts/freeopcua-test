
#include "dataitem.h"

DataItem::DataItem(OpcUa::NodeId nodeId,
				   OpcUa::LocalizedText browseName,
				   OpcUa::LocalizedText displayName,
				   OpcUa::LocalizedText description,
				   NodeManager * pNodeManager,
				   OpcUa::NodeId parentNode,
				   OpcUa::NodeId parentReferenceType)
: DataItem(nodeId, browseName, displayName, description, pNodeManager, parentNode, parentReferenceType, ObjectId::BaseDataType, true)
{


}

DataItem::DataItem(OpcUa::NodeId nodeId,
			       OpcUa::LocalizedText browseName,
				   OpcUa::LocalizedText displayName,
				   OpcUa::LocalizedText description,
				   NodeManager * pNodeManager,
				   OpcUa::NodeId parentNode,
				   OpcUa::NodeId parentReferenceType,
				   OpcUa::NodeId dataType,
				   bool bSetType)
: BaseDataVariable(nodeId, browseName, displayName, description, pNodeManager, parentNode, parentReferenceType, dataType, false)
{
	if(bSetType)
		setType(ObjectId::DataItemType);
}

DataItem::DataItem(BaseVariable * pInstanceDeclaration,
				   OpcUa::NodeId nodeId,
		 	 	   NodeManager * pNodeManager,
				   OpcUa::NodeId parentNode)
: DataItem(nodeId,
	  	   pInstanceDeclaration->getBrowseName(),
		   pInstanceDeclaration->getDisplayName(),
		   pInstanceDeclaration->getDescription(),
		   pNodeManager,
		   parentNode,
		   ObjectId::HasComponent)
{

}

