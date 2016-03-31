#include "variable.h"

#ifndef SRC_PROPERTY_H_
#define SRC_PROPERTY_H_

class Property : public Variable
{
public:
	Property(OpcUa::NodeId nodeId,
			 OpcUa::LocalizedText browseName,
			 OpcUa::LocalizedText displayName,
			 OpcUa::LocalizedText description,
			 NodeManager * pNodeManager,
			 OpcUa::NodeId dataType = ObjectId::BaseDataType);
};




#endif /* SRC_PROPERTY_H_ */
