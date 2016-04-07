#include "typenode.h"

TypeNode::TypeNode(OpcUa::NodeId nodeId,
		 	 	   OpcUa::LocalizedText browseName,
				   OpcUa::LocalizedText displayName,
				   OpcUa::LocalizedText description,
				   bool isAbstract,
				   OpcUa::NodeId parentNode,
				   OpcUa::NodeId parentReferenceType,
				   NodeManager * pNodeManager)
: Node(nodeId, browseName, displayName, description, parentNode, parentReferenceType, pNodeManager),
  m_isAbstract(isAbstract)
{

}
