#ifndef SRC_TEMPERATURESENSOR_H_
#define SRC_TEMPERATURESENSOR_H_
#include <string>
#include <memory>

#include "object.h"
#include "objecttype.h"
#include "nodemanager.h"
#include "analogitem.h"

using namespace OpcUa;


class TemperatureSensor : public Object
{
	public:
		TemperatureSensor(OpcUa::NodeId nodeId, std::string name, NodeManager * pNodeManager);
		~TemperatureSensor();
		void setTemperature(int temperature);
		OpcUa::NodeId getType();
	protected:
		bool s_createdTypes = false;
	private:
		std::shared_ptr<AnalogItem> m_pTemperature;
		void createTypes(NodeManager * pNodeManager);
		ObjectType * s_pObjType;

};






#endif /* SRC_TEMPERATURESENSOR_H_ */
