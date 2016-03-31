#ifndef SRC_ANALOGITEM_H_
#define SRC_ANALOGITEM_H_

#include "basedatavariable.h"

class AnalogItem : public BaseDataVariable
{
	public:
		AnalogItem(OpcUa::NodeId nodeId,
					   OpcUa::LocalizedText browseName,
					   OpcUa::LocalizedText displayName,
					   OpcUa::LocalizedText description,
					   NodeManager * pNodeManager);
};





#endif /* SRC_ANALOGITEM_H_ */
