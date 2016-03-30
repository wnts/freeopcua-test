#ifndef SRC_NODE_H_
#define SRC_NODE_H_

#include <vector>

#include <opc/ua/protocol/nodeid.h>
#include <opc/ua/model.h>
#include "nodemanager.h"


using namespace OpcUa;
/**
 * Represents a Node in the address space.
 */
class Node
{
	public:
		Node(OpcUa::NodeId nodeId, OpcUa::LocalizedText browseName, OpcUa::LocalizedText displayName, OpcUa::LocalizedText description, NodeManager * pNodeManager);
		virtual ~Node();
		virtual OpcUa::NodeId getNodeId();
		virtual OpcUa::LocalizedText getBrowseName();
		virtual OpcUa::LocalizedText getDisplayName();
		virtual OpcUa::LocalizedText getDescription();
		virtual OpcUa::NodeClass getNodeClass() = 0;
	private:
		OpcUa::NodeId m_NodeId;
		OpcUa::LocalizedText m_BrowseName;
		OpcUa::LocalizedText m_DisplayName;
		OpcUa::LocalizedText m_Description;
		std::vector<OpcUa::Model::Reference> references;
		NodeManager * m_pNodeManager;
};





#endif /* SRC_NODE_H_ */
