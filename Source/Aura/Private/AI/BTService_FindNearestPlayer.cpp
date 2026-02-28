


#include "AI/BTService_FindNearestPlayer.h"

#include "AIController.h"
#include "Kismet/GameplayStatics.h"

void UBTService_FindNearestPlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	APawn* OwingPawn= AIOwner->GetPawn();
	
	const FName TargetTag = OwingPawn->ActorHasTag(FName("Player")) ? FName("Enemy") : FName("Player");
	TArray<AActor*> ActorsWithTag;
	UGameplayStatics::GetAllActorsWithTag(OwingPawn,TargetTag,ActorsWithTag);
	
	
}
