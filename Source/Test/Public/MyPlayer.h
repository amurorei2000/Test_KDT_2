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

	// 속력 변수
	UPROPERTY(EditAnywhere, Category = "MySettings")
	float speed = 600.0f;
	
	// Input Mapping Context 변수
	UPROPERTY(EditAnywhere, Category = "MySettings")
	class UInputMappingContext* imc_myControlMap;

	// Input Action 변수
	UPROPERTY(EditAnywhere, Category = "MySettings")
	class UInputAction* ia_move;

	UPROPERTY(EditAnywhere, Category = "MySettings")
	class UInputAction* ia_fire;

	// 총알 블루프린트 파일 변수
	UPROPERTY(EditAnywhere, Category = "MySettings")
	TSubclassOf<class ABulletActor> bullet_bp;


private:
	// 이동 방향 변수
	FVector moveDirection;


	// 이동 입력 받기 함수
	UFUNCTION()
	void Move(const FInputActionValue& value);

	// 총알 발사 함수
	UFUNCTION()
	void Fire();

};
