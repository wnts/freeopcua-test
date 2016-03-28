#include "nodemanager.h"
#include "opcserver.h"

using namespace OpcUa;

NodeManager::NodeManager(const std::string& nameSpaceURI)
: nsUri(nameSpaceURI)
{

}

NodeManager::~NodeManager()
{

}

void NodeManager::Startup(void)
{
	nsIdx = pServer->AddNamespace(nsUri);
}

uint32_t NodeManager::getNamespaceIdx(void)
{
	return nsIdx;
}

std::vector<OpcUa::AddNodesResult> NodeManager::addNodes(std::vector<AddNodesItem> nodes)
{
	return pServer->pNodeManagementService->AddNodes(nodes);
}

std::vector<StatusCode> NodeManager::addReferences(std::vector<AddReferencesItem> references)
{
	return pServer->pNodeManagementService->AddReferences(references);
}

void NodeManager::setServer(OpcUa::OpcServer& server)
{
	pServer = &server;
}

