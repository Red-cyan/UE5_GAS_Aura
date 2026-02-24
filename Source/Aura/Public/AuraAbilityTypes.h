#pragma once

#include "GameplayEffectTypes.h"
#include "AuraAbilityTypes.generated.h"

USTRUCT(BlueprintType)
struct  FAuraGameplayEffectContext : public FGameplayEffectContext
{
	GENERATED_BODY()

public:
	bool IsCriticalHit() const{ return bIsCriticalHit; }
	bool IsBlockHit() const{ return bIsBlockHit; }
	
	void SetCriticalHit(bool bInIsCriticalHit){ bIsCriticalHit = bInIsCriticalHit; }
	void SetBlockHit(bool bInIsBlockHit){ bIsBlockHit = bInIsBlockHit; }
	
	virtual UScriptStruct* GetScriptStruct() const
	{
		return FGameplayEffectContext::StaticStruct();
	};
	
	virtual bool NetSerialize(FArchive& Ar, class UPackageMap* Map, bool& bOutSuccess) ;
protected:
	
	UPROPERTY()
	bool bIsBlockHit = false;
	
	UPROPERTY()
	bool bIsCriticalHit = false;

	
	
};