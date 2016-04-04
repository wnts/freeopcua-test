#ifndef SRC_OBJECT_H_
#define SRC_OBJECT_H_

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
class Object : public TypedNode
{
	public:
		/**
		 * @copydoc Node::Node()
		 * Constructor.
		 *
		 * @param type	Instance of C++ class representing the new Object's type.
		 *
		 */
		Object(OpcUa::NodeId nodeId,
			   OpcUa::LocalizedText browseName,
			   OpcUa::LocalizedText displayName,
			   OpcUa::LocalizedText description,
			   TypeNode& type,
			   NodeManager * pNodeManager);
		Object(OpcUa::NodeId nodeId,
				OpcUa::LocalizedText browseName,
			    OpcUa::LocalizedText displayName,
			    OpcUa::LocalizedText description,
			    NodeManager * pNodeManager);
		virtual ~Object() = 0;
		OpcUa::NodeClass getNodeClass();

	private:
		uint8_t m_eventNotifier = 0;
};




#endif /* SRC_OBJECT_H_ */
