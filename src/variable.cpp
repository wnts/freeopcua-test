#include <vector>

#include "variable.h"
#include "typednode.h"
#include "variabletype.h"
#include "opcserver.h"

using namespace std;

Variable::Variable(OpcUa::NodeId nodeId,
		 	 	   OpcUa::LocalizedText browseName,
				   OpcUa::LocalizedText displayName,
				   OpcUa::LocalizedText description,
				   NodeManager * pNodeManager,
				   OpcUa::NodeId parentNode,
				   OpcUa::NodeId parentReferenceType,
				   OpcUa::NodeId dataType)
: TypedNode(nodeId, browseName, displayName, description, parentNode, parentReferenceType, pNodeManager)
{
	AddNodesItem newVarNode;
	VariableAttributes newVarAttrs;

	newVarNode.RequestedNewNodeId = nodeId;
	newVarNode.BrowseName = QualifiedName(browseName.Text, pNodeManager->getNamespaceIdx());
	newVarNode.Class = NodeClass::Variable;

	newVarAttrs.DisplayName = displayName;
	newVarAttrs.Description = description;
	newVarAttrs.Type = dataType;
	//newVarAttrs.Type = ObjectId::Double;
	newVarNode.Attributes = newVarAttrs;

	pNodeManager->addNodes(vector<AddNodesItem>{newVarNode});
	// todo this shouldn't be here
	addReference(parentNode, nodeId, parentReferenceType, true);
}

Variable::~Variable(){}

void Variable::setValue(OpcUa::Variant value)
{
	DataValue dataValue(value);

	OpcUa::Services::SharedPtr pServices = m_pNodeManager->getServer()->getServices();
	WriteValue wValue;
	wValue.NodeId = getNodeId();
	wValue.AttributeId = AttributeId::Value;
	wValue.Value = dataValue;
	pServices->Attributes()->Write({wValue});




}

OpcUa::NodeClass Variable::getNodeClass()
{
	return NodeClass::Variable;
}
