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

	// �ڽ� ������Ʈ ���� boxComp ����
	UPROPERTY(VisibleAnywhere, Category="Components")
	class UBoxComponent* boxComp;

	// ����ƽ �޽� ������Ʈ ���� meshComp ����
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UStaticMeshComponent* meshComp;

	// �ӷ� ���� speed ����(�⺻��: 600)
	UPROPERTY(VisibleAnywhere, Category = "Variables")
	float speed = 600.0f;
};
