// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BulletActor.generated.h"

UCLASS()
class TEST_API ABulletActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ABulletActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	// 박스 컴포넌트 변수 boxComp 선언
	UPROPERTY(VisibleAnywhere, Category="Components")
	class UBoxComponent* boxComp;

	// 스테틱 메시 컴포넌트 변수 meshComp 선언
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UStaticMeshComponent* meshComp;

	// 속력 변수 speed 선언(기본값: 600)
	UPROPERTY(VisibleAnywhere, Category = "Variables")
	float speed = 600.0f;
};
