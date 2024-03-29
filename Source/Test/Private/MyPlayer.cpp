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

	// 플레이어 컨트롤러로부터 LocalPlayer 클래스에 있는 UEnhancedInputLocalPlayerSubsystem 가져오기

	// InputMappingContext 파일을 로드하기

}

void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// moveDirection 방향으로 speed 속력만큼 이동하기

}

void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// UInputComponent*를 UEnhancedInputComponent*로 변환하기


	// UEnhancedInputComponent* 변수에서 triggered 이벤트와 completed 이벤트에 Move() 함수 연결하기(Binding)


	// UEnhancedInputComponent* 변수에서 Started 이벤트에 Fire() 함수 연결하기(Binding)


}

void AMyPlayer::Move(const FInputActionValue& value)
{
	// 입력 받은 FVector2D 값을 MoveDirection 변수에 넣기


}

void AMyPlayer::Fire()
{
	// 총알(bullet_bp)을 인스턴스로 생성하기


}

