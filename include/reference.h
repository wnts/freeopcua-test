#ifndef SRC_REFERENCE_H_
#define SRC_REFERENCE_H_
#include <opc/ua/protocol/nodeid.h>
#include "nodemanager.h"


/**
 * Class representing an OPC Reference.
 */
class Reference {
	/**
	 * Constructor.
	 *
	 * @param	source			Node Id of the source Node
	 * @param	target			Node Id of the target Node
	 * @param	isForward		Determines whether the Reference is forward or not.
	 * @param	pNodeManager	Pointer to NodeManager that manages the nodes between which this Reference
	 * 							exists.
	 */
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
