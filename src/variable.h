#ifndef SRC_VARIABLE_H_
#define SRC_VARIABLE_H_
#include "node.h"
#include "typednode.h"
#include "variabletype.h"
#include "nodemanager.h"

class Variable : public TypedNode
{
	public:
		Variable(OpcUa::NodeId nodeId,
			     OpcUa::LocalizedText browseName,
			     OpcUa::LocalizedText displayName,
			     OpcUa::LocalizedText description,
			     NodeManager * pNodeManager,
				 OpcUa::NodeId dataType = ObjectId::BaseDataType);
		virtual ~Variable();
		void setValue(OpcUa::Variant value);
		OpcUa::NodeClass getNodeClass();
};

#endif /* SRC_VARIABLE_H_ */
