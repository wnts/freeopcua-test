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
	string tempSensorName = "TemperatureSensor1";
	TemperatureSensor TemperatureSensor1(NodeId(tempSensorName, pMyNodeManager->getNamespaceIdx()), tempSensorName, pMyNodeManager);
	for(int i = -100; i != 100; i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		TemperatureSensor1.setTemperature(i);
	}




	getchar();
	server.Stop();
	return 0;
}
