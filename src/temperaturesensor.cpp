#include <string>

#include "temperaturesensor.h"
#include "nodemanager.h"
#include "objecttype.h"
#include "analogitem.h"

using namespace std;
using namespace OpcUa;

string TemperatureSensorTypeName = "TemperatureSensorType";
NodeId TemperatureSensorTypeNodeId(1001, 0);

TemperatureSensor::TemperatureSensor(NodeId nodeId, string name, NodeManager * pNodeManager)
: Object(nodeId,
		 LocalizedText(name),
		 LocalizedText(name),
		 LocalizedText(name),
		 pNodeManager)
{
	createTypes(pNodeManager);
	setType(s_pObjType);
	// create member Variable Temperature
	string varName = "Temperature";
	AnalogItem Temperature(NodeId(varName, pNodeManager->getNamespaceIdx()),
			 LocalizedText(varName),
			 LocalizedText(varName),
			 LocalizedText(varName),
			 pNodeManager);
	Temperature.addReference(ObjectId::RootFolder, Temperature.getNodeId(), ReferenceId::Organizes, true);


}

TemperatureSensor::~TemperatureSensor()
{

}

NodeId TemperatureSensor::getType(void)
{
	return s_pObjType->getNodeId();
}

/**
 * Initialize: create the ObjectType node in the address space
 * This is only done once: when the first TemperatureSensor object is instantiated
 * @todo Figure out a way to delete the ObjectType node from the address space
 *       when the last TemperatureSensor object is destructed
 */
void TemperatureSensor::createTypes(NodeManager * pNodeManager)
{
	// create TemperatureSensorType node (nodeclass ObjectType)
	s_pObjType = new ObjectType(TemperatureSensorTypeNodeId,		// types go in namespace 0 (right?)
				 LocalizedText(TemperatureSensorTypeName),
				 LocalizedText(TemperatureSensorTypeName),
				 LocalizedText(TemperatureSensorTypeName),
				 false,
				 pNodeManager);
	// create Temperature variable instance declaration
	// we do this the old way, for reasons described in notes.txt
	string instDeclName = "Temperature";
	AddNodesItem temperatureInstDecl;
	VariableAttributes temperatureInstDeclAttrs;

	temperatureInstDecl.RequestedNewNodeId = NodeId(1002, 0);
	temperatureInstDecl.BrowseName = QualifiedName(instDeclName, 0);
	temperatureInstDecl.Class = NodeClass::Variable;
	temperatureInstDecl.ParentNodeId = TemperatureSensorTypeNodeId;
	temperatureInstDecl.ReferenceTypeId = ReferenceId::HasComponent;
	temperatureInstDecl.TypeDefinition = ObjectId::AnalogItemType;

	temperatureInstDeclAttrs.DisplayName = LocalizedText(instDeclName);
	temperatureInstDeclAttrs.Type = ObjectId::Int32;
	temperatureInstDeclAttrs.Rank = -1;
	temperatureInstDeclAttrs.AccessLevel = (VariableAccessLevel) 3;
	temperatureInstDeclAttrs.UserAccessLevel = (VariableAccessLevel) 3;
	temperatureInstDecl.Attributes = temperatureInstDeclAttrs;
	pNodeManager->addNodes(vector<AddNodesItem>{temperatureInstDecl});

}








