#ifndef SRC_NODE_H_
#define SRC_NODE_H_

#include <vector>

#include <opc/ua/protocol/nodeid.h>
#include <opc/ua/model.h>
#include "nodemanager.h"
#include "reference.h"


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
		void addReference(OpcUa::NodeId source, OpcUa::NodeId target, OpcUa::NodeId referenceType, bool isForward);
		virtual OpcUa::NodeClass getNodeClass() = 0;
	protected:
		NodeManager * m_pNodeManager;
	private:
		OpcUa::NodeId m_NodeId;
		OpcUa::LocalizedText m_BrowseName;
		OpcUa::LocalizedText m_DisplayName;
		OpcUa::LocalizedText m_Description;
		std::vector<Reference> m_References;

};





#endif /* SRC_NODE_H_ */
