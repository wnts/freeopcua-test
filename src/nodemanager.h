/*
 * nodemanager.h
 *
 *  Created on: Mar 21, 2016
 *      Author: wouter
 */

#ifndef SRC_NODEMANAGER_H_
#define SRC_NODEMANAGER_H_
#include <opc/ua/services/node_management.h>




namespace OpcUa
{
	class OpcServer;
	class NodeManager
	{
		friend class OpcUa::OpcServer;
		public:
			NodeManager(const std::string& nameSpaceURI);
			virtual ~NodeManager();
			void Startup(void);
			uint32_t getNamespaceIdx(void);
			std::vector<OpcUa::AddNodesResult> addNodes(std::vector<AddNodesItem> nodes);
			std::vector<StatusCode> addReferences(std::vector<OpcUa::AddReferencesItem> references);
			virtual void afterStartup(OpcUa::NodeManagementServices::SharedPtr pNodeManagementService) = 0;
			virtual void beforeShutdown(OpcUa::NodeManagementServices::SharedPtr pNodeManagementService) = 0;
		protected:
			void setServer(OpcUa::OpcServer& server);
		private:
			OpcUa::NodeManagementServices::SharedPtr pNmService;
			OpcUa::OpcServer * pServer;
			std::string nsUri;
			uint32_t nsIdx;

	};
}




#endif /* SRC_NODEMANAGER_H_ */
