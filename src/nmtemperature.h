/*
 * nmbuildingautomation.h

 *
 *  Created on: Mar 21, 2016
 *      Author: wouter
 */
#include "nodemanager.h"
#include <opc/ua/services/node_management.h>

#define Temperature_TemperatureSensorType						1000
#define Temperature_TemperatureSensorType_Temperature			1001
#define Temperature_TemperatureSensorType_Temperature_EURange	1002

class NmTemperature : public OpcUa::NodeManager {
	public:
		NmTemperature();
		virtual void afterStartup(OpcUa::NodeManagementServices::SharedPtr pNodeManagementService);
		virtual void beforeShutdown(OpcUa::NodeManagementServices::SharedPtr pNodeManagementService);

};




