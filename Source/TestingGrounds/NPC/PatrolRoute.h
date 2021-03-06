// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "PatrolRoute.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTINGGROUNDS_API UPatrolRoute : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPatrolRoute();

	//// Called when the game starts
	//virtual void BeginPlay() override;
	//
	//// Called every frame
	//virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	const TArray<AActor*>&	GetPatrolPoints() const;


	UPROPERTY(EditAnywhere, Category = Patrol)
	TArray<AActor*>	PatrolPoints;

private:

};
