#ifndef SRC_OBJECT_H_
#define SRC_OBJECT_H_

#include <stdint.h>
#include "node.h"
#include "objecttype.h"
#include "nodemanager.h"
#include "typednode.h"
#include "typenode.h"


using namespace OpcUa;

class Object : public TypedNode
{
	public:
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
		OpcUa::NodeClass getNodeClass();
	private:
		uint8_t m_eventNotifier = 0;
};




#endif /* SRC_OBJECT_H_ */
