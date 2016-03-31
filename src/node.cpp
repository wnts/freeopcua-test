#include "node.h"
#include "nodemanager.h"


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
 */Node::~Node()
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

void Node::addReference(OpcUa::NodeId source, OpcUa::NodeId target, OpcUa::NodeId referenceType, bool isForward)
{
	Reference newRef(source, target, referenceType, isForward, m_pNodeManager);
	m_References.push_back(newRef);
}









