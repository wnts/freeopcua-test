#include <vector>

#include "variable.h"
#include "typednode.h"
#include "variabletype.h"

using namespace std;

Variable::Variable(OpcUa::NodeId nodeId,
			       OpcUa::LocalizedText browseName,
			       OpcUa::LocalizedText displayName,
			       OpcUa::LocalizedText description,
			       NodeManager * pNodeManager)
: TypedNode(nodeId, browseName, displayName, description, pNodeManager)
{
	AddNodesItem newVarNode;
	VariableAttributes newVarAttrs;

	newVarNode.RequestedNewNodeId = nodeId;
	newVarNode.BrowseName = QualifiedName(browseName.Text, pNodeManager->getNamespaceIdx());
	newVarNode.Class = NodeClass::Variable;


	newVarAttrs.DisplayName = displayName;
	newVarAttrs.Description = description;
	//newVarAttrs.Type = ObjectId::Double;
	newVarNode.Attributes = newVarAttrs;

	pNodeManager->addNodes(vector<AddNodesItem>{newVarNode});
}

Variable::~Variable()
{

}

OpcUa::NodeClass Variable::getNodeClass()
{
	return NodeClass::Variable;
}
