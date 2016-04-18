#include <vector>

#include "basevariable.h"
#include "typednode.h"
#include "variabletype.h"
#include "opcserver.h"

using namespace std;

BaseVariable::BaseVariable(OpcUa::NodeId nodeId,
		 	 	   OpcUa::LocalizedText browseName,
				   OpcUa::LocalizedText displayName,
				   OpcUa::LocalizedText description,
				   NodeManager * pNodeManager,
				   OpcUa::NodeId parentNode,
				   OpcUa::NodeId parentReferenceType,
				   OpcUa::NodeId dataType,
				   bool bSetType)
: TypedNode(nodeId, browseName, displayName, description, parentNode, parentReferenceType, pNodeManager)
{
	AddNodesItem newVarNode;
	VariableAttributes newVarAttrs;

	newVarNode.RequestedNewNodeId = nodeId;
	newVarNode.BrowseName = QualifiedName(browseName.Text, pNodeManager->getNamespaceIdx());
	newVarNode.Class = NodeClass::Variable;
	newVarNode.ParentNodeId = parentNode;
	newVarNode.ReferenceTypeId = parentReferenceType;
	newVarNode.TypeDefinition = ObjectId::Null;

	newVarAttrs.DisplayName = displayName;
	newVarAttrs.Description = description;
	newVarAttrs.Type = dataType;
	newVarAttrs.Rank = -1;
	newVarNode.Attributes = newVarAttrs;

	pNodeManager->addNodes(vector<AddNodesItem>{newVarNode});
	if(bSetType)
		setType(ObjectId::BaseDataVariableType);
}


BaseVariable::~BaseVariable(){}

/**
 * @todo Write overloaded version that takes server/source timestamps
 */
void BaseVariable::setValue(OpcUa::Variant value)
{
	DataValue dataValue(value);
	WriteValue wValue;

	wValue.NodeId = getNodeId();
	wValue.AttributeId = AttributeId::Value;
	wValue.Value = dataValue;
	m_pNodeManager->writeAttribute(wValue);
}

OpcUa::DataValue BaseVariable::getData() const
{
	ReadParameters readParam;
	ReadValueId readId;

	readId.AttributeId = AttributeId::Value;
	readId.NodeId = getNodeId();
	readParam.TimestampsToReturn = TimestampsToReturn::Both;
	readParam.AttributesToRead.push_back(readId);
	return m_pNodeManager->readAttribute(readParam);

}

OpcUa::Variant BaseVariable::getValue() const
{
	DataValue dataVal = getData();
	return dataVal.Value;
}

OpcUa::NodeClass BaseVariable::getNodeClass()
{
	return NodeClass::Variable;
}
