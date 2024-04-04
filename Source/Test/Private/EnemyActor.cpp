// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyActor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

AEnemyActor::AEnemyActor()
{
	PrimaryActorTick.bCanEverTick = true;

	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));
	SetRootComponent(boxComp);
	boxComp->SetBoxExtent(FVector(50));

	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh Component"));
	meshComp->SetupAttachment(boxComp);
	meshComp->SetRelativeLocation(FVector(0, 0, -50));
}

void AEnemyActor::BeginPlay()
{
	Super::BeginPlay();
	
	// 0 ~ 99 사이의 랜덤한 정수 값을 추첨하기
	
	// 만일, 추첨된 값이 traceRate 값보다 작다면...

		// 월드에서 플레이어를 찾는다.
	
		// 자신이 플레이어를 바라보는 방향을 moveDirection으로 설정한다.

	// 그렇지 않다면...
	
		// 자기 자신의 forward 방향을 moveDirection으로 설정한다.
	
}

void AEnemyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorLocation(GetActorLocation() + moveDirection * moveSpeed * DeltaTime);
}

