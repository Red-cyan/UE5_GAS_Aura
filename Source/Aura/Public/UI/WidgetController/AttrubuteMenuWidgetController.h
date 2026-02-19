

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/AuraWidgetController.h"
#include "AttrubuteMenuWidgetController.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAttrubuteMenuWidgetController : public UAuraWidgetController
{
	GENERATED_BODY()
	
	
public:
	
	virtual void BindCallbacksToDependencies() override;
	virtual void BroadcastInitialValues() override;
	
};
