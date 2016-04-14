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
				   OpcUa::NodeId parentReferencetype);
		OpcUa::Variant getEURange() const;
		void setEURange(const OpcUa::Variant &value);
		OpcUa::Variant getEngineeringUnits() const;
		void setEngineeringUnits(const OpcUa::Variant & value);
	protected:
		AnalogItem(OpcUa::NodeId nodeId,
				   OpcUa::LocalizedText browseName,
				   OpcUa::LocalizedText displayName,
				   OpcUa::LocalizedText description,
				   NodeManager * pNodeManager,
				   OpcUa::NodeId parentNode,
				   OpcUa::NodeId parentReferencetype,
				   OpcUa::NodeId dataType,
				   bool bSetType);
		std::shared_ptr<Property> pEURange;
		std::shared_ptr<Property> pEngineeringUnits;
		std::shared_ptr<Property> pInstrumentRange;

};





#endif /* SRC_ANALOGITEM_H_ */
