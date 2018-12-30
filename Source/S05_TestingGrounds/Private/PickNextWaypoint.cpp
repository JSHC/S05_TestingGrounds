// Fill out your copyright notice in the Description page of Project Settings.

#include "PickNextWaypoint.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UPickNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(FName(IndexKey.SelectedKeyName));
	UE_LOG(LogTemp, Warning, TEXT("Waypoint index: %i"), Index);
	
	return EBTNodeResult::Succeeded;
}
