// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingGrounds.h"
#include "ChooseNextWaypointTaskNode.h"
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* bbCpnt = OwnerComp.GetBlackboardComponent();
	if (!ensure(bbCpnt != nullptr))
	{
		return EBTNodeResult::Failed;
	}

	int32 nextIndex = bbCpnt->GetValueAsInt(IndexKey.SelectedKeyName);


	return EBTNodeResult::Succeeded;
}