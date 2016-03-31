#ifndef SRC_DATAITEM_H_
#define SRC_DATAITEM_H_

#include "basedatavariable.h"
#include "property.h"

class DataItem : public BaseDataVariable
{
	public:
		DataItem(OpcUa::NodeId nodeId,
				 OpcUa::LocalizedText browseName,
				 OpcUa::LocalizedText displayName,
				 OpcUa::LocalizedText description,
				 NodeManager * pNodeManager,
				 OpcUa::NodeId dataType = ObjectId::BaseDataType);
	protected:

};



#endif /* SRC_DATAITEM_H_ */