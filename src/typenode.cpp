#include "typenode.h"

TypeNode::TypeNode(OpcUa::NodeId nodeId,
		 	 	   OpcUa::LocalizedText browseName,
				   OpcUa::LocalizedText displayName,
				   OpcUa::LocalizedText description,
				   bool isAbstract,
				   NodeManager * pNodeManager)
: Node(nodeId, browseName, displayName, description, pNodeManager),
  m_isAbstract(isAbstract)
{

}
