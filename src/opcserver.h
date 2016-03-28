#pragma once
#include <opc/common/addons_core/addon_manager.h>
#include <opc/ua/server/addons/common_addons.h>
#include <opc/ua/event.h>
#include <opc/ua/node.h>
#include <opc/ua/server/services_registry.h>
#include <opc/ua/server/subscription_service.h>
#include <opc/ua/services/services.h>
#include <opc/ua/subscription.h>
#include <opc/ua/server_operations.h>

#include "nodemanager.h"



namespace OpcUa
{
	class OpcServer
	{
		friend class OpcUa::NodeManager;
		public:
      		OpcServer();
      		explicit OpcServer(const std::string& configdDir);
      		void Start(void);
      		void Stop(void);
      		void addNodeManager(OpcUa::NodeManager * pNodeManager);
      		uint32_t AddNamespace(const std::string& NsUri);
		private:
      		Common::AddonsManager::UniquePtr pAddonsManager;
      		Server::ServicesRegistry::SharedPtr pServiceRegistry;
      		OpcUa::NodeManagementServices::SharedPtr pNodeManagementService;
      		std::vector<OpcUa::NodeManager *> nodeManagers;
      		bool bStarted = false;
	};
}