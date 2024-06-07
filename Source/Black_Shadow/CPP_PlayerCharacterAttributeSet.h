// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "CPP_PlayerCharacterAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class BLACK_SHADOW_API UCPP_PlayerCharacterAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UCPP_PlayerCharacterAttributeSet();

	//GameplayEffectÇ…ÇÊÇÈBaseValueïœçXå„Ç…åƒÇŒÇÍÇÈ
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)override;

	//CurrentValueÇÃïœçXå„Ç…åƒÇŒÇÍÇÈ
	virtual void PostAttributeChange(const FGameplayAttribute& Attribute,float OldValue, float NewValue) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerCharacterAttributes");
	FGameplayAttributeData Speed;
	ATTRIBUTE_ACCESSORS(UCPP_PlayerCharacterAttributeSet,Speed)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerCharacterAttributes");
	FGameplayAttributeData HeartRate;
	ATTRIBUTE_ACCESSORS(UCPP_PlayerCharacterAttributeSet, HeartRate)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerCharacterAttributes");
	FGameplayAttributeData HeartRateIncrement;
	ATTRIBUTE_ACCESSORS(UCPP_PlayerCharacterAttributeSet, HeartRateIncrement)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerCharacterAttributes");
	FGameplayAttributeData Loudness;
	ATTRIBUTE_ACCESSORS(UCPP_PlayerCharacterAttributeSet, Loudness);
	
};
