/*
 * temperatureobject.cpp
 *
 *  Created on: Mar 23, 2016
 *      Author: wouter
 */


#include <opc/ua/node.h>
#include "nmtemperature.h"
#include "baseobject.h"
#include "temperaturesensorobject.h"

using namespace OpcUa;
using namespace std;

TemperatureSensorObject::TemperatureSensorObject(const string& name, OpcUa::NodeId nodeId, OpcUa::NodeManager * pNodeManager)
: BaseObject(name, NodeId(Temperature_TemperatureSensorType, 0), nodeId, pNodeManager)
{

}

TemperatureSensorObject::~TemperatureSensorObject()
{

}

NodeId TemperatureSensorObject::TypeDefinitionNodeId(void)
{
	return NodeId(Temperature_TemperatureSensorType, 0);
}




