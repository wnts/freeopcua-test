#ifndef SRC_NODEMANAGER_H_
#define SRC_NODEMANAGER_H_
#include <opc/ua/services/node_management.h>



class OpcServer;
class NodeManager
{
	friend class OpcServer;
	friend class Node;
	public:
		NodeManager(const std::string& nameSpaceURI);
		virtual ~NodeManager();
		void Startup(void);
		uint32_t getNamespaceIdx(void);
		std::vector<OpcUa::AddNodesResult> addNodes(std::vector<OpcUa::AddNodesItem> nodes);
		std::vector<OpcUa::StatusCode> addReferences(std::vector<OpcUa::AddReferencesItem> references);
		virtual void afterStartup(OpcUa::NodeManagementServices::SharedPtr pNodeManagementService) = 0;
		virtual void beforeShutdown(OpcUa::NodeManagementServices::SharedPtr pNodeManagementService) = 0;
		OpcServer * getServer(void);
	protected:
		void setServer(OpcServer& server);
	private:
		OpcUa::NodeManagementServices::SharedPtr pNmService;
		OpcServer * pServer;
		std::string nsUri;
		uint32_t nsIdx;

};

#endif /* SRC_NODEMANAGER_H_ */
