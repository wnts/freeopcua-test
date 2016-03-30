#ifndef SRC_TEMPERATURESENSOR_H_
#define SRC_TEMPERATURESENSOR_H_
#include <string>
#include "object.h"
#include "objecttype.h"
#include "nodemanager.h"

using namespace OpcUa;


class TemperatureSensor : public Object
{
	public:
		TemperatureSensor(OpcUa::NodeId nodeId, std::string name, NodeManager * pNodeManager);
		~TemperatureSensor();
		OpcUa::NodeId getType();
	protected:
		bool s_createdTypes = false;
	private:
		void createTypes(NodeManager * pNodeManager);
		ObjectType * s_pObjType;

};






#endif /* SRC_TEMPERATURESENSOR_H_ */
