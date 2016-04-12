#include <vector>

#include <opc/ua/protocol/protocol_auto.h>
#include "nodemanager.h"
#include "opcserver.h"


using namespace std;

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

std::vector<OpcUa::AddNodesResult> NodeManager::addNodes(std::vector<OpcUa::AddNodesItem> nodes)
{
	return pServer->pNodeManagementService->AddNodes(nodes);
}

std::vector<OpcUa::StatusCode> NodeManager::addReferences(std::vector<OpcUa::AddReferencesItem> references)
{
	return pServer->pNodeManagementService->AddReferences(references);
}

void NodeManager::writeAttribute(OpcUa::WriteValue value)
{
	pServer->getServices()->Attributes()->Write({value});
}

OpcUa::DataValue NodeManager::readAttribute(OpcUa::ReadParameters readParam) const
{
	vector<OpcUa::DataValue> values;
	values = pServer->getServices()->Attributes()->Read({readParam});
	return values[0];
}

void NodeManager::setServer(OpcServer& server)
{
	pServer = &server;
}

OpcServer * NodeManager::getServer(void)
{
	return pServer;
}
