// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"
#include "Components/ArrowComponent.h"


AEnemySpawner::AEnemySpawner()
{
	PrimaryActorTick.bCanEverTick = true;

	rootComp = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	SetRootComponent(rootComp);

	spawnArrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow Component"));
	spawnArrow->SetupAttachment(RootComponent);
	// spawnArrow를 pitch-Axis로 -90도, roll-Axis로 180도 회전시키기

}

void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// currentTime에 DeltaTime 값을 누적시키기

	// 만일, currentTime에 누적된 값이 delayTime을 넘어섰다면...
	
	// enemy_bp를 spawnArrow 컴포넌트의 위치와 회전에 맞춰서 생성한다.

	// currentTime을 0초로 초기화하기
	
}

