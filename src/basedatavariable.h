#ifndef SRC_BASEDATAVARIABLE_H_
#define SRC_BASEDATAVARIABLE_H_
#include "variable.h"

class BaseDataVariable : public Variable
{
	public:
		BaseDataVariable(OpcUa::NodeId nodeId,
						 OpcUa::LocalizedText browseName,
						 OpcUa::LocalizedText displayName,
						 OpcUa::LocalizedText description,
						 NodeManager * pNodeManager,
						 OpcUa::NodeId dataType = ObjectId::BaseDataType);
};




#endif /* SRC_BASEDATAVARIABLE_H_ */
