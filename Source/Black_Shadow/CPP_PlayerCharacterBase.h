// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "CPP_PlayerCharacterAttributeSet.h"
#include "CPP_PlayerCharacterBase.generated.h"

UCLASS()
class BLACK_SHADOW_API ACPP_PlayerCharacterBase : public ACharacter,public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACPP_PlayerCharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Abilities")
	UAbilitySystemComponent* AbilitySystem;

	UPROPERTY()
	UCPP_PlayerCharacterAttributeSet* CPP_PlayerCharacterAttributeSet;

	UFUNCTION(BlueprintImplementableEvent,Category="Alert")
	void Alert();

	UFUNCTION(BlueprintImplementableEvent, Category = "Speed")
	void SetWalkSpeed(float speed);

};
