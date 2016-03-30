#ifndef SRC_VARIABLETYPE_H_
#define SRC_VARIABLETYPE_H_
#include "node.h"
#include "nodemanager.h"

class VariableType : public ::Node
{
	public:
		VariableType(OpcUa::NodeId nodeId,
			OpcUa::LocalizedText browseName,
			OpcUa::LocalizedText displayName,
			OpcUa::LocalizedText description,
			bool isAbstract,
			NodeManager * pNodeManager);
		OpcUa::NodeClass getNodeClass();
	private:
		bool isAbstract = false;
};




#endif /* SRC_VARIABLETYPE_H_ */