#include "node.h"
#include "nodemanager.h"

using namespace std;

Node::Node(OpcUa::NodeId nodeId,
		   OpcUa::LocalizedText browseName,
		   OpcUa::LocalizedText displayName,
		   OpcUa::LocalizedText description,
		   OpcUa::NodeId parentNode,
		   OpcUa::NodeId parentReferenceType,
		   NodeManager * pNodeManager)
: m_NodeId(nodeId),
  m_BrowseName(browseName),
  m_DisplayName(displayName),
  m_Description(description),
  m_pNodeManager(pNodeManager)
{

}

/**
 * @Todo delete Node from namespace on object destruction
 */
Node::~Node()
{

}

NodeId Node::getNodeId() const
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

shared_ptr<Reference> Node::addReference(Node * pTarget, OpcUa::NodeId referenceType, bool isForward)
{
	return addReference(getNodeId(), pTarget->getNodeId(), referenceType, pTarget->getNodeClass(), isForward);
}

shared_ptr<Reference> Node::addReference(OpcUa::NodeId source,
										 OpcUa::NodeId target,
										 OpcUa::NodeId referenceType,
										 OpcUa::NodeClass targetNodeClass,
										 bool isForward)
{
	shared_ptr<Reference> pNewRef = make_shared<Reference>(source, target, referenceType, isForward, targetNodeClass, m_pNodeManager);
	m_References.push_back(*pNewRef);

	return pNewRef;
}









