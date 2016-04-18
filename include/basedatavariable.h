#ifndef SRC_BASEDATAVARIABLE_H_
#define SRC_BASEDATAVARIABLE_H_
#include "basevariable.h"

class BaseDataVariable : public BaseVariable
{
	public:
		BaseDataVariable(OpcUa::NodeId nodeId,
						 OpcUa::LocalizedText browseName,
						 OpcUa::LocalizedText displayName,
						 OpcUa::LocalizedText description,
						 NodeManager * pNodeManager,
						 OpcUa::NodeId parentNode,
						 OpcUa::NodeId parentReferenceType);
		BaseDataVariable(BaseVariable * pInstanceDeclaration,
						 OpcUa::NodeId nodeId,
						 NodeManager * pNodeManager,
						 OpcUa::NodeId parentNode);
	protected:
		BaseDataVariable(OpcUa::NodeId nodeId,
						 OpcUa::LocalizedText browseName,
						 OpcUa::LocalizedText displayName,
						 OpcUa::LocalizedText description,
						 NodeManager * pNodeManager,
						 OpcUa::NodeId parentNode,
						 OpcUa::NodeId parentReferenceType,
						 OpcUa::NodeId dataType,
						 bool bSetType);
};




#endif /* SRC_BASEDATAVARIABLE_H_ */
