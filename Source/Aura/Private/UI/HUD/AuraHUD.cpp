#include "UI/HUD/AuraHUD.h"
#include "UI/Widget/AuraUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"
#include "Blueprint/UserWidget.h"
#include "UI/WidgetController/AttributeMenuWidgetController.h"

/**
 * 获取或创建覆盖UI的WidgetController
 * 采用延迟初始化模式，仅在首次调用时创建实例
 * @param WCParams WidgetController的初始化参数
 * @return 已初始化的覆盖层WidgetController
 */
UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	// 如果WidgetController尚未创建，则创建新实例
	if (OverlayWidgetController == nullptr)
	{
		// 使用指定的类创建新的WidgetController实例
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		// 初始化WidgetController的参数
		OverlayWidgetController->SetWidgetControllerParams(WCParams);
		OverlayWidgetController->BindCallbacksToDependencies();
	}
	return OverlayWidgetController;
}

UAttributeMenuWidgetController* AAuraHUD::GetAttributeMenuWidgetController(const FWidgetControllerParams& WCParams)
{
	if (AttributeMenuWidgetController == nullptr)
	{
		AttributeMenuWidgetController = NewObject<UAttributeMenuWidgetController>(this, AttributeMenuWidgetControllerClass);
		AttributeMenuWidgetController->SetWidgetControllerParams(WCParams);
		AttributeMenuWidgetController->BindCallbacksToDependencies();
	}
	
	return AttributeMenuWidgetController;
	
}

/**
 * 初始化游戏覆盖UI
 * 包括创建Widget实例、获取WidgetController并将两者关联
 * @param PC 玩家控制器
 * @param PS 玩家状态
 * @param ASC 能力系统组件
 * @param AS 属性集
 */
void AAuraHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	// 确保覆盖UI类已设置
	checkf(OverlayWidgetClass, TEXT("OverlayWidgetClass is nullptr"));
	// 确保覆盖UI控制器类已设置
	checkf(OverlayWidgetControllerClass, TEXT("OverlayWidgetControllerClass is nullptr"));
	
	// 创建覆盖UI控件实例
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	// 将控件转换为自定义的AuraUserWidget类型
	OverlayWidget = Cast<UAuraUserWidget>(Widget);
	
	// 创建WidgetController参数结构体
	const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
	// 获取或创建WidgetController
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);
	
	// 将WidgetController与覆盖UI控件关联
	OverlayWidget->SetWidgetController(WidgetController);
	
	WidgetController->BroadcastInitialValues();
	
	// 将覆盖UI添加到视口
	Widget->AddToViewport();
}