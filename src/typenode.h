#ifndef SRC_TYPENODE_H_
#define SRC_TYPENODE_H_
#include "node.h"
#include "nodemanager.h"

class TypeNode : public ::Node
{
public:
	TypeNode(OpcUa::NodeId nodeId,
			 OpcUa::LocalizedText browseName,
			 OpcUa::LocalizedText displayName,
			 OpcUa::LocalizedText description,
			 bool isAbstract,
			 NodeManager * pNodeManager);
	protected:
		bool m_isAbstract = false;

};






#endif /* SRC_TYPENODE_H_ */
