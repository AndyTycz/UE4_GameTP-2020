// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy_Melee.generated.h"

class UPawnSensingComponent;
class UHealthComponent;
class ATPCharacter;

UCLASS()
class UE4_GAMETP_API AEnemy_Melee : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy_Melee();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
		UPawnSensingComponent* PawnSenses;

	UPROPERTY(VisibleDefaultsOnly)
		UHealthComponent* HealthComponent;


	UFUNCTION()
		void OnPawnSeen(APawn* SeenPawn);

	UFUNCTION()
		void HandleTakeDamage(UHealthComponent* HealtComp, float Health, float HealthChange, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

	UMaterialInstanceDynamic* MatInstance;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class USphereComponent* AttackSphere;

	void AttackPlayer();

	FRotator GetLookAtYaw(FVector Target);

	bool bIsInAttackRange;

	ATPCharacter* PlayerTarget;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
