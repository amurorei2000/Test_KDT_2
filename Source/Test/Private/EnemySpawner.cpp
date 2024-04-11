// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"
#include "Components/ArrowComponent.h"
#include "EnemyActor.h"


AEnemySpawner::AEnemySpawner()
{
	PrimaryActorTick.bCanEverTick = true;

	rootComp = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	SetRootComponent(rootComp);

	spawnArrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow Component"));
	spawnArrow->SetupAttachment(RootComponent);
	// spawnArrow�� pitch-Axis�� -90��, roll-Axis�� 180�� ȸ����Ű��
	spawnArrow->SetRelativeRotation(FRotator(-90, 0, 180));
}

void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();

}

void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// currentTime�� DeltaTime ���� ������Ű��
	currentTime += DeltaTime;

	// ����, currentTime�� ������ ���� delayTime�� �Ѿ�ٸ�...
	if (currentTime > delayTime)
	{
		// enemy_bp�� spawnArrow ������Ʈ�� ��ġ�� ȸ���� ���缭 �����Ѵ�.
		GetWorld()->SpawnActor<AEnemyActor>(enemy_bp, spawnArrow->GetComponentLocation(), spawnArrow->GetComponentRotation());

		// currentTime�� 0�ʷ� �ʱ�ȭ�ϱ�
		currentTime = 0;
	}
}

