// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletActor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"


ABulletActor::ABulletActor()
{
	PrimaryActorTick.bCanEverTick = true;

	// �ڽ� ������Ʈ�� �����ϰ� ��Ʈ ������Ʈ�� �����ϱ�
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));
	SetRootComponent(boxComp);

	// �ڽ� ������Ʈ�� �ݸ��� ũ��� (50, 50, 50)���� �����ϱ�
	boxComp->SetBoxExtent(FVector(50));

	// �ڽ� ������Ʈ�� worldscale ���� (0.7, 0.3, 1.0)���� �����ϱ�
	boxComp->SetWorldScale3D(FVector(0.7f, 0.3f, 1.0f));

	// ����ƽ �޽� ������Ʈ�� �����ϰ� �ڽ� ������Ʈ�� �ڽ� ������Ʈ�� �����ϱ�
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Component"));
	meshComp->SetupAttachment(boxComp);

	// ����ƽ �޽� ������Ʈ�� ����� ��ġ�� (0, 0, -50)���� �����ϱ�
	meshComp->SetRelativeLocation(FVector(0, 0, -50));

}

void ABulletActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABulletActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// �ڽ��� ���� �������� speed �ӷ����� �̵��ϱ�
	SetActorLocation(GetActorLocation() + GetActorUpVector() * speed * DeltaTime);

}

