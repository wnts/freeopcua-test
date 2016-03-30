/*
 * nmbuildingautomation.cpp *
 *  Created on: Mar 21, 2016
 *      Author: wouter
 */
#include <string>

#include <opc/ua/protocol/string_utils.h>
#include <opc/common/addons_core/addon.h>
#include <opc/ua/protocol/strings.h>
#include <opc/ua/protocol/variable_access_level.h>
#include <opc/ua/services/node_management.h>

#include "nmtemperature.h"
#include "nodemanager.h"

using namespace std;
using namespace OpcUa;

NmTemperature::NmTemperature()
: NodeManager("http://reniver.eu/simple-server")
{

}

void NmTemperature::afterStartup(OpcUa::NodeManagementServices::SharedPtr pNodeManagementService)
{

}

void NmTemperature::beforeShutdown(OpcUa::NodeManagementServices::SharedPtr pNodeManagementService)
{
	return;
}

