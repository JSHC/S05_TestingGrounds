// Fill out your copyright notice in the Description page of Project Settings.

#include "PickNextWaypoint.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Classes/AIController.h"
#include "PatrolComponent.h"


EBTNodeResult::Type UPickNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	//Get blackboard component and Index value
	UBlackboardComponent *BlackboardComp = OwnerComp.GetBlackboardComponent();
	int32 Index = BlackboardComp->GetValueAsInt(FName(IndexKey.SelectedKeyName));

	//Get the AIController to get the Pawn (character) and cast it to the PatrollingGuard class
	AAIController *AIController = OwnerComp.GetAIOwner();
	APawn *Guard = AIController->GetPawn();
	UPatrolComponent *PatrolComponent = Guard->FindComponentByClass<UPatrolComponent>();
	if (!ensure(PatrolComponent)) { return EBTNodeResult::Aborted; }

	//Get the array of patrol points and set the Waypoint to the current Index
	TArray<AActor*> PatrolPoints = PatrolComponent->GetPatrolPoints();
	if(PatrolPoints.Num() == 0) 
	{ 
		UE_LOG(LogTemp, Warning, TEXT("%s: Empty PatrolPoints array, make sure the instance of this guard has patrol points"), *Guard->GetName())
		return EBTNodeResult::Aborted; 
	}
	BlackboardComp->SetValueAsObject(FName(WaypointKey.SelectedKeyName), PatrolPoints[Index]);

	//Cycle the index
	BlackboardComp->SetValueAsInt(FName(IndexKey.SelectedKeyName), (Index+1) % PatrolPoints.Num());
	
	return EBTNodeResult::Succeeded;
}
