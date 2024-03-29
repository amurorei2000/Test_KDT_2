// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPlayer.generated.h"

UCLASS()
class TEST_API AMyPlayer : public APawn
{
	GENERATED_BODY()

public:
	AMyPlayer();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, Category="MySettings")
	class UBoxComponent* boxComp;

	UPROPERTY(VisibleAnywhere, Category = "MySettings")
	class UStaticMeshComponent* meshComp;

	// �ӷ� ����
	UPROPERTY(EditAnywhere, Category = "MySettings")
	float speed = 600.0f;
	
	// Input Mapping Context ����
	UPROPERTY(EditAnywhere, Category = "MySettings")
	class UInputMappingContext* imc_myControlMap;

	// Input Action ����
	UPROPERTY(EditAnywhere, Category = "MySettings")
	class UInputAction* ia_move;

	UPROPERTY(EditAnywhere, Category = "MySettings")
	class UInputAction* ia_fire;

	// �Ѿ� �������Ʈ ���� ����
	UPROPERTY(EditAnywhere, Category = "MySettings")
	TSubclassOf<class ABulletActor> bullet_bp;


private:
	// �̵� ���� ����
	FVector moveDirection;


	// �̵� �Է� �ޱ� �Լ�
	UFUNCTION()
	void Move(const FInputActionValue& value);

	// �Ѿ� �߻� �Լ�
	UFUNCTION()
	void Fire();

};
