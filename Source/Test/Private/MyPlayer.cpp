// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "BulletActor.h"


AMyPlayer::AMyPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));
	SetRootComponent(boxComp);
	boxComp->SetBoxExtent(FVector(50));

	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh Component"));
	meshComp->SetupAttachment(boxComp);
	meshComp->SetRelativeLocation(FVector(0, 0, -50));

}

void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();

	// �÷��̾� ��Ʈ�ѷ��κ��� LocalPlayer Ŭ������ �ִ� UEnhancedInputLocalPlayerSubsystem ��������

	// InputMappingContext ������ �ε��ϱ�

}

void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// moveDirection �������� speed �ӷ¸�ŭ �̵��ϱ�

}

void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// UInputComponent*�� UEnhancedInputComponent*�� ��ȯ�ϱ�


	// UEnhancedInputComponent* �������� triggered �̺�Ʈ�� completed �̺�Ʈ�� Move() �Լ� �����ϱ�(Binding)


	// UEnhancedInputComponent* �������� Started �̺�Ʈ�� Fire() �Լ� �����ϱ�(Binding)


}

void AMyPlayer::Move(const FInputActionValue& value)
{
	// �Է� ���� FVector2D ���� MoveDirection ������ �ֱ�


}

void AMyPlayer::Fire()
{
	// �Ѿ�(bullet_bp)�� �ν��Ͻ��� �����ϱ�


}

