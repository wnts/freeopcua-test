#include "basedatavariable.h"

BaseDataVariable::BaseDataVariable(OpcUa::NodeId nodeId,
			       	   	   	       OpcUa::LocalizedText browseName,
								   OpcUa::LocalizedText displayName,
								   OpcUa::LocalizedText description,
								   NodeManager * pNodeManager,
								   OpcUa::NodeId parentNode,
								   OpcUa::NodeId parentReferenceType)
: Variable(nodeId, browseName, displayName, description, pNodeManager, parentNode, parentReferenceType, ObjectId::BaseDataType, true)
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
: Variable(nodeId, browseName, displayName, description, pNodeManager, parentNode, parentReferenceType, dataType, bSetType)
{
	if(bSetType)
		setType(ObjectId::BaseDataVariableType);
}

