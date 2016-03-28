/*
 * nmbuildingautomation.cpp *
 *  Created on: Mar 21, 2016
 *      Author: wouter
 */

#include <opc/ua/protocol/string_utils.h>
#include <opc/common/addons_core/addon.h>
#include <opc/ua/protocol/strings.h>
#include <opc/ua/protocol/variable_access_level.h>
#include <opc/ua/services/node_management.h>

#include "nmtemperature.h"
#include "nodemanager.h"

using namespace OpcUa;

NmTemperature::NmTemperature()
: NodeManager("http://reniver.eu/simple-server")
{

}

void NmTemperature::afterStartup(OpcUa::NodeManagementServices::SharedPtr pNodeManagementService)
{

	/**
	 * Add TemperatureSensorType Node
	 * */
	AddNodesItem TemperatureSensorTypeNode;
	ObjectTypeAttributes TemperatureSensorTypeNodeAttrs;
	AddReferencesItem TemperatureSensorTypeReference;

	TemperatureSensorTypeNode.RequestedNewNodeId = NodeId(Temperature_TemperatureSensorType, 0);
	TemperatureSensorTypeNode.BrowseName = QualifiedName("TemperatureSensorType");
	TemperatureSensorTypeNode.Class = NodeClass::ObjectType;
	TemperatureSensorTypeNode.ParentNodeId = NodeId(ObjectId::BaseObjectType);
	TemperatureSensorTypeNode.ReferenceTypeId = ReferenceId::HasSubtype;

	TemperatureSensorTypeNodeAttrs.DisplayName = LocalizedText("TemperatureSensorType");
	TemperatureSensorTypeNodeAttrs.IsAbstract = false;
	TemperatureSensorTypeNode.Attributes = TemperatureSensorTypeNodeAttrs;
	addNodes(std::vector<OpcUa::AddNodesItem>{TemperatureSensorTypeNode});


	TemperatureSensorTypeReference.IsForward = true;
	TemperatureSensorTypeReference.ReferenceTypeId = ReferenceId::HasComponent;
	TemperatureSensorTypeReference.SourceNodeId = TemperatureSensorTypeNode.RequestedNewNodeId;
	TemperatureSensorTypeReference.TargetNodeClass = NodeClass::Variable;
	TemperatureSensorTypeReference.TargetNodeId = NodeId(Temperature_TemperatureSensorType_Temperature, getNamespaceIdx());
	addReferences(std::vector<AddReferencesItem>{TemperatureSensorTypeReference});

	/**
	 * Add Temperature (Variable of TemperatureSensorType)
	 **/
	AddNodesItem TemperatureNode;
	VariableAttributes TemperatureNodeAttrs;
	std::vector<AddReferencesItem> TemperatureNodeReferences;

	TemperatureNode.RequestedNewNodeId = NodeId(Temperature_TemperatureSensorType_Temperature, 0);
	TemperatureNode.BrowseName = QualifiedName("Temperature");
	TemperatureNode.Class = NodeClass::Variable;
	TemperatureNode.ParentNodeId = NodeId(ObjectId(Temperature_TemperatureSensorType));
	TemperatureNode.ReferenceTypeId = ReferenceId::HasComponent;
	TemperatureNode.TypeDefinition = NodeId(ObjectId::AnalogItemType);
	VariableAttributes attrs;
	TemperatureNodeAttrs.DisplayName = LocalizedText("Temperature");
	TemperatureNodeAttrs.Type = ObjectId::Double;
	TemperatureNodeAttrs.Rank = -1;
	TemperatureNodeAttrs.AccessLevel = (VariableAccessLevel) 3;
	TemperatureNodeAttrs.UserAccessLevel = (VariableAccessLevel) 3;
	TemperatureNode.Attributes = TemperatureNodeAttrs;
	addNodes(std::vector<AddNodesItem>{TemperatureNode});

	// add references to temperaturenode
	std::vector<AddReferencesItem> TemperatureReferences;

	AddReferencesItem EURangeReference;
	EURangeReference.IsForward = true;
	EURangeReference.ReferenceTypeId = ReferenceId::HasProperty;
	EURangeReference.SourceNodeId = TemperatureNode.RequestedNewNodeId;
	EURangeReference.TargetNodeClass = NodeClass::Variable;
	EURangeReference.TargetNodeId = NodeId(ObjectId::AnalogItemType_EURange);
	TemperatureReferences.push_back(EURangeReference);

	/*
	{
	AddReferencesItem ref;
	ref.IsForward = true;
	ref.ReferenceTypeId = ReferenceId::HasProperty;
	ref.SourceNodeId = ToNodeId("ns=1;i=6001");
	ref.TargetNodeClass = NodeClass::DataType;
	ref.TargetNodeId = ToNodeId("ns=1;i=6002");
	refs.push_back(ref);
	}
	{
	AddReferencesItem ref;
	ref.IsForward = true;
	ref.ReferenceTypeId = ReferenceId::HasProperty;
	ref.SourceNodeId = ToNodeId("ns=1;i=6001");
	ref.TargetNodeClass = NodeClass::DataType;
	ref.TargetNodeId = ToNodeId("ns=1;i=6004");
	refs.push_back(ref);
	}
	{
	AddReferencesItem ref;
	ref.IsForward = true;
	ref.ReferenceTypeId = ReferenceId::HasModellingRule;
	ref.SourceNodeId = ToNodeId("ns=1;i=6001");
	ref.TargetNodeClass = NodeClass::DataType;
	ref.TargetNodeId = ToNodeId("i=78");
	refs.push_back(ref);
	}
	{
	AddReferencesItem ref;
	ref.IsForward = true;
	ref.ReferenceTypeId = ReferenceId::HasProperty;
	ref.SourceNodeId = ToNodeId("ns=1;i=6001");
	ref.TargetNodeClass = NodeClass::DataType;
	ref.TargetNodeId = ToNodeId("ns=1;i=6005");
	refs.push_back(ref);
	}
	registry.AddReferences(refs);
	}

	{
	AddNodesItem node;
	node.RequestedNewNodeId = ToNodeId("ns=1;i=6003");
	node.BrowseName = ToQualifiedName("EngineeringUnits");
	node.Class = NodeClass::Variable;
	node.ParentNodeId = ToNodeId("ns=1;i=6001");
	node.ReferenceTypeId = ReferenceId::HasProperty;
	node.TypeDefinition = ToNodeId("i=68");
	VariableAttributes attrs;
	attrs.DisplayName = LocalizedText("EngineeringUnits");
	attrs.Type = ObjectId::EUInformation;
	attrs.Rank = -1;
	node.Attributes = attrs;
	registry.AddNodes(std::vector<AddNodesItem>{node});
	std::vector<AddReferencesItem> refs;
	{
	AddReferencesItem ref;
	ref.IsForward = true;
	ref.ReferenceTypeId = ReferenceId::HasModellingRule;
	ref.SourceNodeId = ToNodeId("ns=1;i=6003");
	ref.TargetNodeClass = NodeClass::DataType;
	ref.TargetNodeId = ToNodeId("i=80");
	refs.push_back(ref);
	}
	registry.AddReferences(refs);
	}

	{
	AddNodesItem node;
	node.RequestedNewNodeId = ToNodeId("ns=1;i=6002");
	node.BrowseName = ToQualifiedName("EURange");
	node.Class = NodeClass::Variable;
	node.ParentNodeId = ToNodeId("ns=1;i=6001");
	node.ReferenceTypeId = ReferenceId::HasProperty;
	node.TypeDefinition = ToNodeId("i=68");
	VariableAttributes attrs;
	attrs.DisplayName = LocalizedText("EURange");
	attrs.Type = ObjectId::Range;
	attrs.Rank = -1;
	node.Attributes = attrs;
	registry.AddNodes(std::vector<AddNodesItem>{node});
	std::vector<AddReferencesItem> refs;
	{
	AddReferencesItem ref;
	ref.IsForward = true;
	ref.ReferenceTypeId = ReferenceId::HasModellingRule;
	ref.SourceNodeId = ToNodeId("ns=1;i=6002");
	ref.TargetNodeClass = NodeClass::DataType;
	ref.TargetNodeId = ToNodeId("i=78");
	refs.push_back(ref);
	}
	registry.AddReferences(refs);
	}

	{
	AddNodesItem node;
	node.RequestedNewNodeId = ToNodeId("ns=1;i=6004");
	node.BrowseName = ToQualifiedName("InstrumentRange");
	node.Class = NodeClass::Variable;
	node.ParentNodeId = ToNodeId("ns=1;i=6001");
	node.ReferenceTypeId = ReferenceId::HasProperty;
	node.TypeDefinition = ToNodeId("i=68");
	VariableAttributes attrs;
	attrs.DisplayName = LocalizedText("InstrumentRange");
	attrs.Type = ObjectId::Range;
	attrs.Rank = -1;
	node.Attributes = attrs;
	registry.AddNodes(std::vector<AddNodesItem>{node});
	std::vector<AddReferencesItem> refs;
	{
	AddReferencesItem ref;
	ref.IsForward = true;
	ref.ReferenceTypeId = ReferenceId::HasModellingRule;
	ref.SourceNodeId = ToNodeId("ns=1;i=6004");
	ref.TargetNodeClass = NodeClass::DataType;
	ref.TargetNodeId = ToNodeId("i=80");
	refs.push_back(ref);
	}
	registry.AddReferences(refs);
	}

	{
	AddNodesItem node;
	node.RequestedNewNodeId = ToNodeId("ns=1;i=6005");
	node.BrowseName = ToQualifiedName("ValuePrecision");
	node.Class = NodeClass::Variable;
	node.ParentNodeId = ToNodeId("ns=1;i=6001");
	node.ReferenceTypeId = ReferenceId::HasProperty;
	node.TypeDefinition = ToNodeId("i=68");
	VariableAttributes attrs;
	attrs.Description = LocalizedText("The maximum precision that the server can maintain for the item based on restrictions in the target environment.");
	attrs.DisplayName = LocalizedText("ValuePrecision");
	attrs.Type = ObjectId::Double;
	attrs.Rank = -1;
	node.Attributes = attrs;
	registry.AddNodes(std::vector<AddNodesItem>{node});
	std::vector<AddReferencesItem> refs;
	{
	AddReferencesItem ref;
	ref.IsForward = true;
	ref.ReferenceTypeId = ReferenceId::HasModellingRule;
	ref.SourceNodeId = ToNodeId("ns=1;i=6005");
	ref.TargetNodeClass = NodeClass::DataType;
	ref.TargetNodeId = ToNodeId("i=80");
	refs.push_back(ref);
	}
	registry.AddReferences(refs);
	}
*/
	addReferences(TemperatureReferences);
}

void NmTemperature::beforeShutdown(OpcUa::NodeManagementServices::SharedPtr pNodeManagementService)
{
	return;
}

