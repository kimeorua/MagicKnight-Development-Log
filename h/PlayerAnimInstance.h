// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MagicKnightEnums.h"
#include "Animation/AnimInstance.h"
#include "PlayerAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class PF_MAGICKNIGHT_API UPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Move", meta = (AllowPrivateAccess = "true"))
	float Speed; //캐릭터의 속도
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Move", meta = (AllowPrivateAccess = "true"))
	float Direction; //캐릭터의 방향

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Move", meta = (AllowPrivateAccess = "true"))
	class APlayerCharacter* Player = nullptr; // 플레이어 캐릭터 

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon", meta = (AllowPrivateAccess = "true"))
	EEquipedWeapon EquipedWeapon; //캐릭터가 현제 장착한 무기

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Move", meta = (AllowPrivateAccess = "true"))
	bool IsBlock;

public:
	UPlayerAnimInstance(); // 생성자
	virtual void NativeUpdateAnimation(float DeltaSeconds) override; //애니메이션 업데이트 함수

	EEquipedWeapon CheackWeaponTag(); //플레이어가 장착한 무기를 GameplayTag를 통해 확인
	bool CheackUseBlock();
};
