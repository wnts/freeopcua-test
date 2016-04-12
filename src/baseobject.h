#ifndef SRC_BASEOBJECT_H_
#define SRC_BASEOBJECT_H_

#include <stdint.h>
#include "node.h"
#include "objecttype.h"
#include "nodemanager.h"
#include "typednode.h"
#include "typenode.h"


using namespace OpcUa;
/**
 * Abstract class representing an OPC Object node in the address space.
 * Actual Objects in the address space are represented by creating non-abstract
 * classes that derive from this class. When such a class is instantiated, a corresponding
 * Object node is created in the address space.
 */
class BaseObject : public TypedNode
{
	public:
		/**
		 * @copydoc Node::Node()
		 * Constructor.
		 *
		 * @param type	Instance of C++ class representing the new Object's type.
		 *
		 */
		BaseObject(OpcUa::NodeId nodeId,
				   OpcUa::LocalizedText browseName,
				   OpcUa::LocalizedText displayName,
				   OpcUa::LocalizedText description,
				   NodeManager * pNodeManager,
				   OpcUa::NodeId parentNode,
				   OpcUa::NodeId parentReferenceType);
		virtual ~BaseObject();
		OpcUa::NodeClass getNodeClass();
	protected:
		BaseObject(OpcUa::NodeId nodeId,
				   OpcUa::LocalizedText browseName,
				   OpcUa::LocalizedText displayName,
				   OpcUa::LocalizedText description,
				   NodeManager * pNodeManager,
				   OpcUa::NodeId parentNode,
				   OpcUa::NodeId parentReferenceType,
				   bool bSetType);
	private:
		uint8_t m_eventNotifier = 0;
};




#endif /* SRC_BASEOBJECT_H_ */
