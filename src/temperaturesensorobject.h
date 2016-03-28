/*
 * temperatureobject.h
 *
 *  Created on: Mar 23, 2016
 *      Author: wouter
 */

#ifndef SRC_TEMPERATURESENSOROBJECT_H_
#define SRC_TEMPERATURESENSOROBJECT_H_
#include <opc/ua/model.h>
#include <opc/ua/protocol/nodeid.h>
#include "baseobject.h"

class TemperatureSensorObject : OpcUa::Model::BaseObject
{
	public:
		TemperatureSensorObject(const std::string& name, OpcUa::NodeId nodeId, OpcUa::NodeManager * pNodeManager);
		virtual ~TemperatureSensorObject();

		OpcUa::NodeId TypeDefinitionNodeId(void);
};




#endif /* SRC_TEMPERATURESENSOROBJECT_H_ */
