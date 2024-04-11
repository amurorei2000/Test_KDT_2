// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyActor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "EngineUtils.h"
#include "MyPlayer.h"
#include <../../../../../../../Source/Runtime/Engine/Classes/Kismet/KismetMathLibrary.h>


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
	
	// 0 ~ 99 ������ ������ ���� ���� ��÷�ϱ�
	int32 value = FMath::RandRange(0, 99);

	// ����, ��÷�� ���� traceRate ������ �۴ٸ�...
	if (value < traceRate)
	{
		// ���忡�� �÷��̾ ã�´�.
		for (TActorIterator<AMyPlayer> player(GetWorld()); player; ++player)
		{
			// �ڽ��� �÷��̾ �ٶ󺸴� ������ moveDirection���� �����Ѵ�.
			moveDirection = (player->GetActorLocation() - GetActorLocation()).GetSafeNormal();
		}
	}
	// �׷��� �ʴٸ�...
	else
	{
		// �ڱ� �ڽ��� forward ������ moveDirection���� �����Ѵ�.
		moveDirection = GetActorForwardVector();
	}
}

void AEnemyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorLocation(GetActorLocation() + moveDirection * moveSpeed * DeltaTime);

	// �̵��Ϸ��� ������ �ٶ󺸵��� ȸ���Ѵ�.
	
}
