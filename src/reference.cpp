#include <vector>

#include "reference.h"

using namespace std;
using namespace OpcUa;

Reference::Reference(OpcUa::NodeId source, OpcUa::NodeId target, OpcUa::NodeId referenceType, bool isForward, NodeManager * pNodeManager)
: m_isForward(isForward),
  m_referenceType(referenceType),
  m_Source(source),
  m_Target(target)
{
	AddReferencesItem newRef;
	newRef.IsForward = isForward;
	newRef.SourceNodeId = source;
	newRef.TargetNodeId = target;
	newRef.ReferenceTypeId = referenceType;
	newRef.TargetNodeClass = NodeClass::Variable;

	pNodeManager->addReferences(vector<AddReferencesItem>{newRef});
}

/**
 * @todo : remove reference in address space upon oject destruction
 */
Reference::~Reference()
{

}



