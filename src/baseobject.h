/*
 * myobject.h
 *
 *  Created on: Mar 23, 2016
 *      Author: wouter
 */

#ifndef SRC_BASEOBJECT_H_
#define SRC_BASEOBJECT_H_
#include <opc/ua/model.h>
#include <opc/ua/protocol/nodeid.h>
#include "nodemanager.h"

namespace OpcUa
{
	namespace Model
	{
		class BaseObject
		{
			public:
				BaseObject(const std::string& name, NodeId objectType, NodeId nodeId, OpcUa::NodeManager * pNodeManager);
				virtual ~BaseObject();
				virtual NodeId TypeDefinitionNodeId() = 0;
		};
	}
}




#endif /* SRC_MYOBJECT_H_ */
