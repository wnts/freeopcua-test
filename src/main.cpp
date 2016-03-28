#include <unistd.h>
#include "opcserver.h"
#include "nmtemperature.h"
#include "temperaturesensorobject.h"

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
	string sname = "TemperatureSensor1";
	TemperatureSensorObject TemperatureSensor1(sname, NodeId(sname, pMyNodeManager->getNamespaceIdx()), pMyNodeManager);

	getchar();
	server.Stop();
	return 0;
}
