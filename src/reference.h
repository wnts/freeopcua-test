#ifndef SRC_REFERENCE_H_
#define SRC_REFERENCE_H_
#include <opc/ua/protocol/nodeid.h>
#include "nodemanager.h"

class Reference {
	public:
		Reference(OpcUa::NodeId source, OpcUa::NodeId target, OpcUa::NodeId referenceType, bool isForward, NodeManager * pNodeManager);
		~Reference();
	private:
		bool m_isForward;
		OpcUa::NodeId m_referenceType;
		OpcUa::NodeId m_Source;
		OpcUa::NodeId m_Target;

};



#endif /* SRC_REFERENCE_H_ */
