#include "folder.h"
#include "baseobject.h"
Folder::Folder(OpcUa::NodeId nodeId,
			   OpcUa::LocalizedText browseName,
			   OpcUa::LocalizedText displayName,
			   OpcUa::LocalizedText description,
			   NodeManager * pNodeManager,
			   OpcUa::NodeId parentNode,
			   OpcUa::NodeId parentReferenceType)
: BaseObject(nodeId, browseName, displayName, description, pNodeManager, parentNode, parentReferenceType, false)
{
	setType(ObjectId::FolderType);
}

