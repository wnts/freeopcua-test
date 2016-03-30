#ifndef SRC_OBJECT_H_
#define SRC_OBJECT_H_

#include <stdint.h>
#include "node.h"
#include "objecttype.h"
#include "nodemanager.h"


using namespace OpcUa;

class Object : public ::Node
{
	public:
		Object(OpcUa::NodeId nodeId,
					   OpcUa::LocalizedText browseName,
					   OpcUa::LocalizedText displayName,
					   OpcUa::LocalizedText description,
					   NodeId type,
					   NodeManager * pNodeManager);
		OpcUa::NodeClass getNodeClass();
		/**
		 * Get the object type
		 *
		 * This should not be implemented by subclasses representing abstract
		 * types in the address space. This way, a subclass representing an abstract
		 * object in the address space cannot be instantiated.
		 */
		virtual OpcUa::NodeId getType() = 0;
	private:
		uint8_t m_eventNotifier = 0;
};




#endif /* SRC_OBJECT_H_ */
