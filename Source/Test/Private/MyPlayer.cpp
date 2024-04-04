// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "BulletActor.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"


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
	APlayerController* pc = GetController<APlayerController>();
	if (pc != nullptr)
	{
		UEnhancedInputLocalPlayerSubsystem* subsys = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(pc->GetLocalPlayer());
		
		// InputMappingContext ������ �ε��ϱ�
		if (subsys != nullptr)
		{
			subsys->AddMappingContext(imc_myControlMap, 0);
		}
	}
}

void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// moveDirection �������� speed �ӷ¸�ŭ �̵��ϱ�
	SetActorLocation(GetActorLocation() + moveDirection * speed * DeltaTime);
}

void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// UInputComponent*�� UEnhancedInputComponent*�� ��ȯ�ϱ�
	UEnhancedInputComponent* enhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (enhancedInputComponent != nullptr)
	{
		// UEnhancedInputComponent* �������� triggered �̺�Ʈ�� completed �̺�Ʈ�� Move() �Լ� �����ϱ�(Binding)
		enhancedInputComponent->BindAction(ia_move, ETriggerEvent::Triggered, this, &AMyPlayer::Move);
		enhancedInputComponent->BindAction(ia_move, ETriggerEvent::Completed, this, &AMyPlayer::Move);

		// UEnhancedInputComponent* �������� Started �̺�Ʈ�� Fire() �Լ� �����ϱ�(Binding)
		enhancedInputComponent->BindAction(ia_fire, ETriggerEvent::Started, this, &AMyPlayer::Fire);
	}
}

void AMyPlayer::Move(const FInputActionValue& value)
{
	// �Է� ���� FVector2D ���� MoveDirection ������ �ֱ�
	FVector2D inputValue = value.Get<FVector2D>();
	moveDirection = FVector(0, inputValue.X, inputValue.Y);

}

void AMyPlayer::Fire()
{
	// �Ѿ�(bullet_bp)�� �ν��Ͻ��� �����ϱ�
	FActorSpawnParameters params;
	params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	if (bullet_bp != nullptr)
	{
		GetWorld()->SpawnActor<ABulletActor>(bullet_bp, GetActorLocation(), GetActorRotation(), params);
	}
}

