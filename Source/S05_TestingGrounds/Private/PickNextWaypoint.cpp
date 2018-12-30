// Fill out your copyright notice in the Description page of Project Settings.

#include "PickNextWaypoint.h"


EBTNodeResult::Type UPickNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	UE_LOG(LogTemp, Warning, TEXT("PickNextWaypoint C++ called"));

	return EBTNodeResult::Succeeded;
}
