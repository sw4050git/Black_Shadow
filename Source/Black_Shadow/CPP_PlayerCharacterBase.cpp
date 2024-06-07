// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_PlayerCharacterBase.h"

// Sets default values
ACPP_PlayerCharacterBase::ACPP_PlayerCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CPP_PlayerCharacterAttributeSet = CreateDefaultSubobject<UCPP_PlayerCharacterAttributeSet>(TEXT("AttributeSet"));
	AbilitySystem = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystem"));

}

// Called when the game starts or when spawned
void ACPP_PlayerCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
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




