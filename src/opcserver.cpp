/******************************************************************************
 *   Copyright (C) 2013-2014 by Olivier Roulet-Dubonnet                       *
 *                                                                            *
 *   This library is free software; you can redistribute it and/or modify     *
 *   it under the terms of the GNU Lesser General Public License as           *
 *   published by the Free Software Foundation; version 3 of the License.     *
 *                                                                            *
 *   This library is distributed in the hope that it will be useful,          *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of           *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            *
 *   GNU Lesser General Public License for more details.                      *
 *                                                                            *
 *   You should have received a copy of the GNU Lesser General Public License *
 *   along with this library; if not, write to the                            *
 *   Free Software Foundation, Inc.,                                          *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.                *
 ******************************************************************************/

#include "opcserver.h"
#include "nmtemperature.h"

#include <opc/ua/server/addons/common_addons.h>
#include <opc/ua/server/addons/address_space.h>
#include <opc/ua/protocol/string_utils.h>

#include <opc/ua/server/addons/services_registry.h>
#include <opc/ua/server/addons/subscription_service.h>
#include <opc/ua/node.h>
#include <opc/ua/model.h>
#include <iostream>

using namespace std;
using namespace OpcUa;

OpcServer::OpcServer()
{

}

OpcServer::OpcServer(const string& ConfigDir)
{
  pAddonsManager = Common::CreateAddonsManager();
  Server::LoadConfiguration(ConfigDir, *pAddonsManager);
}


void OpcServer::addNodeManager(NodeManager * pNodeManager)
{
  nodeManagers.push_back(pNodeManager);
  pNodeManager->setServer(*this);
  if(bStarted)
  {
	pNodeManager->Startup();
	pNodeManager->afterStartup(pNodeManagementService);
  }
}

uint32_t OpcServer::AddNamespace(const string& NsUri)
{
  OpcUa::Node namespaceArray(pServiceRegistry->GetServer(), OpcUa::ObjectId::Server_NamespaceArray);
  std::vector<std::string> uris = namespaceArray.GetValue().As<std::vector<std::string>>();
  uint32_t index = uris.size() - 1;
  uris.push_back(NsUri);
  namespaceArray.SetValue(uris);

  return index;
}

void OpcServer::Start(void)
{
  pAddonsManager->Start();
  pServiceRegistry = pAddonsManager->GetAddon<Server::ServicesRegistry>(Server::ServicesRegistryAddonId);
  pNodeManagementService = pAddonsManager->GetAddon<OpcUa::NodeManagementServices>(OpcUa::Server::AddressSpaceRegistryAddonId);
  for(std::vector<NodeManager *>::iterator it = nodeManagers.begin(); it != nodeManagers.end(); it++)
  {
	  (*it)->Startup();
	  (*it)->afterStartup(pNodeManagementService);
  }

  bStarted = true;
}

OpcUa::Services::SharedPtr OpcServer::getServices()
{
	return pServiceRegistry->GetServer();
}

void OpcServer::Stop(void)
{
  pAddonsManager->Stop();
}

