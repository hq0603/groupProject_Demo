// Fill out your copyright notice in the Description page of Project Settings.
// 子弹效果 鼠标左键发射紫色的攻击子弹

#pragma once

#include "CoreMinimal.h"
#include "SProjectileBase.h"
#include "GameplayTagContainer.h"
#include "SMagicProjectile.generated.h"

class USActionEffect;

UCLASS()
class ACTIONROGUELIKE_API ASMagicProjectile : public ASProjectileBase // Re-parented from AActor
{
	// 这里不知道为什么会报错 上面include的包应该是正确的
	GENERATED_BODY()

protected:
	
	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	float DamageAmount;

	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	FGameplayTag ParryTag;

	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	TSubclassOf<USActionEffect> BurningActionClass;

	UFUNCTION()
	void OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	virtual void PostInitializeComponents() override;

public:

	ASMagicProjectile();

};
