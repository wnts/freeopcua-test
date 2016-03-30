#include "node.h"
#include "nodemanager.h"

using namespace OpcUa;


Node::Node(OpcUa::NodeId nodeId, OpcUa::LocalizedText browseName, OpcUa::LocalizedText displayName, OpcUa::LocalizedText description, NodeManager * pNodeManager)
: m_NodeId(nodeId),
  m_BrowseName(browseName),
  m_DisplayName(displayName),
  m_Description(description),
  m_pNodeManager(pNodeManager)
{

}

/**
 * @Todo: delete Node from namespace on object destruction
 */
Node::~Node()
{

}

NodeId Node::getNodeId()
{
	return m_NodeId;
}

LocalizedText Node::getBrowseName()
{
	return m_BrowseName;
}

LocalizedText Node::getDisplayName()
{
	return m_DisplayName;
}

LocalizedText Node::getDescription()
{
	return m_Description;
}









