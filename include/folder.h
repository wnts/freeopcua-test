#ifndef SRC_FOLDER_H_
#define SRC_FOLDER_H_
#include "baseobject.h"

class Folder : public BaseObject
{
	public:
		Folder(OpcUa::NodeId nodeId,
			   OpcUa::LocalizedText browseName,
			   OpcUa::LocalizedText displayName,
			   OpcUa::LocalizedText description,
			   NodeManager * pNodeManager,
			   OpcUa::NodeId parentNode,
			   OpcUa::NodeId parentReferenceType);
		~Folder() {};

};




#endif /* SRC_FOLDER_H_ */
