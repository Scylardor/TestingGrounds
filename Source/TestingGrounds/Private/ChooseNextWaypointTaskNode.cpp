// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingGrounds.h"
#include "ChooseNextWaypointTaskNode.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolRoute.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* bbCpnt = OwnerComp.GetBlackboardComponent();
	AAIController* controller = OwnerComp.GetAIOwner();
	APawn* guardPawn = (controller ? controller->GetPawn() : nullptr);
	UPatrolRoute* patrolRoute = (guardPawn ? guardPawn->FindComponentByClass<UPatrolRoute>() : nullptr);
	if (!ensure(bbCpnt != nullptr && patrolRoute != nullptr))
	{
		return EBTNodeResult::Failed;
	}

	// Get next waypoint index
	const TArray<AActor*>& patrolPoints = patrolRoute->GetPatrolPoints();
	int32 nextIndex = bbCpnt->GetValueAsInt(IndexKey.SelectedKeyName);

	// Set next waypoint
	if (ensure(nextIndex < patrolPoints.Num()))
	{
		bbCpnt->SetValueAsObject(WaypointKey.SelectedKeyName, patrolPoints[nextIndex]);
	}

	// Cycle waypoint index
	bbCpnt->SetValueAsInt(IndexKey.SelectedKeyName, (nextIndex + 1) % patrolPoints.Num());

	return EBTNodeResult::Succeeded;
}