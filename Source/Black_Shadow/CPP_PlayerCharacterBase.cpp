// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_PlayerCharacterBase.h"

// Sets default values
ACPP_PlayerCharacterBase::ACPP_PlayerCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;
	CPP_PlayerCharacterAttributeSet = CreateDefaultSubobject<UCPP_PlayerCharacterAttributeSet>(TEXT("AttributeSet"));
	AbilitySystem = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystem"));
}

// Called when the game starts or when spawned
void ACPP_PlayerCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	SetWalkSpeed(CPP_PlayerCharacterAttributeSet->GetSpeed());
}

// Called every frame
void ACPP_PlayerCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPP_PlayerCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UAbilitySystemComponent* ACPP_PlayerCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystem;
}




