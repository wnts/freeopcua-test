#ifndef SRC_ANALOGITEM_H_
#define SRC_ANALOGITEM_H_

#include <memory>

#include "basedatavariable.h"
#include "property.h"
#include "dataitem.h"

class AnalogItem : public DataItem
{
	public:
		AnalogItem(OpcUa::NodeId nodeId,
					   OpcUa::LocalizedText browseName,
					   OpcUa::LocalizedText displayName,
					   OpcUa::LocalizedText description,
					   NodeManager * pNodeManager,
					   OpcUa::NodeId parentNode,
					   OpcUa::NodeId parentReferencetype,
					   OpcUa::NodeId dataType = ObjectId::Number);
	protected:
		std::shared_ptr<Property> pEURange;

};





#endif /* SRC_ANALOGITEM_H_ */
