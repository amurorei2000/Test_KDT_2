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
	// spawnArrow�� pitch-Axis�� -90��, roll-Axis�� 180�� ȸ����Ű��

}

void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// currentTime�� DeltaTime ���� ������Ű��

	// ����, currentTime�� ������ ���� delayTime�� �Ѿ�ٸ�...
	
	// enemy_bp�� spawnArrow ������Ʈ�� ��ġ�� ȸ���� ���缭 �����Ѵ�.

	// currentTime�� 0�ʷ� �ʱ�ȭ�ϱ�
	
}

