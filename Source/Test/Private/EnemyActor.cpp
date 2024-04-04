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
	
	// 0 ~ 99 ������ ������ ���� ���� ��÷�ϱ�
	
	// ����, ��÷�� ���� traceRate ������ �۴ٸ�...

		// ���忡�� �÷��̾ ã�´�.
	
		// �ڽ��� �÷��̾ �ٶ󺸴� ������ moveDirection���� �����Ѵ�.

	// �׷��� �ʴٸ�...
	
		// �ڱ� �ڽ��� forward ������ moveDirection���� �����Ѵ�.
	
}

void AEnemyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorLocation(GetActorLocation() + moveDirection * moveSpeed * DeltaTime);
}

