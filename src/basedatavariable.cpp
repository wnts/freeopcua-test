#include "basedatavariable.h"

BaseDataVariable::BaseDataVariable(OpcUa::NodeId nodeId,
			       	   	   	       OpcUa::LocalizedText browseName,
								   OpcUa::LocalizedText displayName,
								   OpcUa::LocalizedText description,
								   NodeManager * pNodeManager,
								   OpcUa::NodeId parentNode,
								   OpcUa::NodeId parentReferenceType)
: BaseVariable(nodeId, browseName, displayName, description, pNodeManager, parentNode, parentReferenceType, ObjectId::BaseDataType, true)
{
	/* normally we would instantiate a VariableType object here, to create the BaseDataVariableType in the address space
	 * but BaseDataVariableType is already in the address space, through a mechanism other than instantiating a Type class (see notes.txt)
	 */



}

BaseDataVariable::BaseDataVariable(OpcUa::NodeId nodeId,
						  	  	   OpcUa::LocalizedText browseName,
								   OpcUa::LocalizedText displayName,
								   OpcUa::LocalizedText description,
								   NodeManager * pNodeManager,
								   OpcUa::NodeId parentNode,
								   OpcUa::NodeId parentReferenceType,
								   OpcUa::NodeId dataType,
								   bool bSetType)
: BaseVariable(nodeId, browseName, displayName, description, pNodeManager, parentNode, parentReferenceType, dataType, bSetType)
{
	if(bSetType)
		setType(ObjectId::BaseDataVariableType);
}

BaseDataVariable::BaseDataVariable(BaseVariable * pInstanceDeclaration,
								   OpcUa::NodeId nodeId,
								   NodeManager * pNodeManager,
								   OpcUa::NodeId parentNode)
: BaseDataVariable(nodeId,
		       	   pInstanceDeclaration->getBrowseName(),
				   pInstanceDeclaration->getDisplayName(),
				   pInstanceDeclaration->getDescription(),
				   pNodeManager,
				   parentNode,
				   ObjectId::HasComponent)
{

}

