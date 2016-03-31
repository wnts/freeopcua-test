#ifndef SRC_OBJECTTYPE_H_
#define SRC_OBJECTTYPE_H_

#include "node.h"
#include "nodemanager.h"
#include "typenode.h"

class ObjectType : public TypeNode
{
	public:
		ObjectType(OpcUa::NodeId nodeId,
				   OpcUa::LocalizedText browseName,
				   OpcUa::LocalizedText displayName,
				   OpcUa::LocalizedText description,
				   bool isAbstract,
				   NodeManager * pNodeManager);
		OpcUa::NodeClass getNodeClass();
	private:
		bool isAbstract = false;
};





#endif /* SRC_OBJECTTYPE_H_ */
