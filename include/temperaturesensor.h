#ifndef SRC_TEMPERATURESENSOR_H_
#define SRC_TEMPERATURESENSOR_H_
#include <string>
#include <memory>
#include <time.h>

#include "objecttype.h"
#include "nodemanager.h"
#include "analogitem.h"
#include "baseobject.h"

using namespace OpcUa;


class TemperatureSensor : public BaseObject
{
	public:
		TemperatureSensor(OpcUa::NodeId nodeId,
						  OpcUa::LocalizedText browseName,
						  OpcUa::LocalizedText displayName,
						  OpcUa::LocalizedText description,
						  NodeManager * pNodeManager,
						  OpcUa::NodeId parentNode,
						  OpcUa::NodeId parentReferenceType);

		~TemperatureSensor();
		void setTemperature(int temperature, time_t sourceTimestamp = time(NULL));
		OpcUa::NodeId getType();
	protected:
		bool s_createdTypes = false;
	private:
		std::shared_ptr<AnalogItem> m_pTemperature;
		static std::shared_ptr<AnalogItem> s_pTemperatureInstDecl;
		void createTypes(NodeManager * pNodeManager);

};






#endif /* SRC_TEMPERATURESENSOR_H_ */
