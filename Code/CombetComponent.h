// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MagicKnightEnums.h"
#include "CombetComponent.generated.h"

UENUM(BlueprintType)
enum class EAttackSocket : uint8
{
	None = 0 UMETA(DisplayName = "None"),
	LeftStartSocket UMETA(DisplayName = "Left Start Socket"), //왼손 시작
	LeftEndSocket UMETA(DisplayName = "Left End Socket"), //왼손 끝
	RightStartSocket UMETA(DisplayName = "Right Start Socket"), //오른손 시작
	RightEndSocket UMETA(DisplayName = "Right End Socket"), //오른손 끝
	AOE_StartSocket UMETA(DisplayName = "AOE Start Socket"), //범위 공격 시작
	AOE_EndSocket UMETA(DisplayName = "AOE End Socket"), //범위 공격 끝

	Max UMETA(DisplayName = "Max")
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PF_MAGICKNIGHT_API UCombetComponent : public UActorComponent
{
	GENERATED_BODY() 

private:
	// 소켓 배열
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "HitEffect", meta = (AllowPrivateAccess = "true"))
	TMap<EAttackSocket, FName> AttackSockets;

	//원거리용 타겟 좌표
	FVector TargetLocation;

public:	
	// Sets default values for this component's properties
	UCombetComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/// <summary>
	/// 오버랩 확인 함수
	/// </summary>
	/// <param name="Type">공격 타입</param>
	/// <param name="Range">공격 범위</param>
	/// <param name="DriectionType">공격 방향(왼손or 오른손....)</param>
	/// <param name="TraceChannel">반응할 트레이스 채널</param>
	/// <param name="isPlayer">플레이여 여부</param>
	/// <returns>bool (공격 성공 여부), FHitResult(Hit 결과 구조체)</returns>
	TTuple<bool, FHitResult> AttackCollision(EAttackCollisionType Type, float Range, EAttackDirectionType DriectionType, ECollisionChannel TraceChannel, bool isPlayer = false);

	void SetTargetLocation(FVector TLocation) { TargetLocation = TLocation; }

protected:
	// Called when the game starts
	virtual void BeginPlay() override;	
};
