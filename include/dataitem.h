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
				 OpcUa::NodeId parentNode,
				 OpcUa::NodeId parentReferenceType);
		DataItem(BaseVariable * pInstanceDeclaration,
				 OpcUa::NodeId nodeId,
				 NodeManager * pNodeManager,
				 OpcUa::NodeId parentNode);
	protected:
		DataItem(OpcUa::NodeId nodeId,
				 OpcUa::LocalizedText browseName,
				 OpcUa::LocalizedText displayName,
				 OpcUa::LocalizedText description,
				 NodeManager * pNodeManager,
				 OpcUa::NodeId parentNode,
				 OpcUa::NodeId parentReferenceType,
				 OpcUa::NodeId dataType,
				 bool bSetType);

};



#endif /* SRC_DATAITEM_H_ */
