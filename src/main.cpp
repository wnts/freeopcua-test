#include <unistd.h>
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
	string tempSensorName = "TemperatureSensor1";
	TemperatureSensor TemperatureSensor1(NodeId(tempSensorName, pMyNodeManager->getNamespaceIdx()), tempSensorName, pMyNodeManager);


	getchar();
	server.Stop();
	return 0;
}
