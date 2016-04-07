#ifndef SRC_NODE_H_
#define SRC_NODE_H_

#include <vector>

#include <opc/ua/protocol/nodeid.h>
#include <opc/ua/model.h>
#include "nodemanager.h"
#include "reference.h"


using namespace OpcUa;
/**
 * Abstract class representing an OPC Node in the address space.
 */
class Node
{
	/**
	 * Constructor.
	 *
	 * @param nodeId		The node ID of the new Node.
	 * 						The Nodeid attribute of the OPC Node will be given this value.
	 * @param browseName	The browse name of the new Node.
	 * 						A Node's browsename does not need to be unique.
	 * 						The Browsename attribute of the OPC Node wil be given this value.
	 * @param displayName	Human readable name of the new Node.
	 * 						The Displayname attribute of the OPC Node will be given this value.
	 * @param description	Description of the new Node.
	 * 						The Description attribute of the OPC Node will be given this value.
	 * @param pNodeManager	Pointer to a Node Manager. The new Node will be placed in the namespace
	 * 						managed by this Node Manager.
	 *
	 */
	public:
		Node(OpcUa::NodeId nodeId,
			 OpcUa::LocalizedText browseName,
			 OpcUa::LocalizedText displayName,
			 OpcUa::LocalizedText description,
			 OpcUa::NodeId parentNode,
			 OpcUa::NodeId parentReferenceType,
			 NodeManager * pNodeManager);
		/**
		 * Destructor.
		 * @todo	Remove node from address space upon object destruction.
		 */
		virtual ~Node();
		/**
		 * @return The Node Id of this node.
		 */
		virtual OpcUa::NodeId getNodeId();
		/**
		 * @return The Browsename attribute of this Node.
		 */
		virtual OpcUa::LocalizedText getBrowseName();
		/**
		 * @return The Displayname attribute of this Node.
		 */
		virtual OpcUa::LocalizedText getDisplayName();
		/**
		 * @return The description attribute of this Node.
		 */
		virtual OpcUa::LocalizedText getDescription();
		/**
		 * Add a reference to this Node.
		 *
		 * @param	source			The Node Id of the source Node.
		 * @param	target			The Node Id of the target Node.
		 * @param	referenceType	The Node Id of the ReferenceType
		 * @param	isForward		Determines whether the reference is forward or not.
		 *
		 * @return	A pointer to the newly created Reference.
		 */
		std::shared_ptr<Reference> addReference(OpcUa::NodeId source, OpcUa::NodeId target, OpcUa::NodeId referenceType, bool isForward);
		/**
		 * @return The Nodeclass attribute of this Node.
		 */
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
