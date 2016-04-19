#include <unistd.h>

#include <thread>

#include "opcserver.h"
#include "nmtemperature.h"
#include "temperaturesensor.h"
#include "objecttype.h"
#include "variabletype.h"

using namespace OpcUa;
using namespace std;

char szCwd[255];

int main(void)
{
	getcwd(szCwd, sizeof(szCwd));
	OpcServer server(szCwd);
	NmTemperature * pMyNodeManager = new NmTemperature();
	server.addNodeManager(pMyNodeManager);
	server.Start();
	std::string name = "TemperatureSensor1";
	TemperatureSensor * pTemperatureSensor1 = new TemperatureSensor(NodeId(name, pMyNodeManager->getNamespaceIdx()),
												LocalizedText(name),
												LocalizedText(name),
												LocalizedText(name),
												pMyNodeManager,
												ObjectId::Null,
												ReferenceId::Organizes);
	pTemperatureSensor1->addReference(ObjectId::ObjectsFolder, pTemperatureSensor1->getNodeId(), ReferenceId::Organizes, NodeClass::Object);




	getchar();
	server.Stop();
	return 0;
}
