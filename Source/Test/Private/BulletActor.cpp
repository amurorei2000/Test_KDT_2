// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletActor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "MyPlayer.h"
#include "EnemyActor.h"
#include <../../../../../../../Source/Runtime/Engine/Classes/Kismet/GameplayStatics.h>


ABulletActor::ABulletActor()
{
	PrimaryActorTick.bCanEverTick = true;

	// 박스 컴포넌트를 생성하고 루트 컴포넌트로 지정하기
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));
	SetRootComponent(boxComp);

	// 박스 컴포넌트의 콜리전 크기는 (50, 50, 50)으로 설정하기
	boxComp->SetBoxExtent(FVector(50));

	// 박스 컴포넌트의 worldscale 값은 (0.7, 0.3, 1.0)으로 설정하기
	boxComp->SetWorldScale3D(FVector(0.7f, 0.3f, 1.0f));

	// 스태틱 메시 컴포넌트를 생성하고 박스 컴포넌트의 자식 컴포넌트로 지정하기
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Component"));
	meshComp->SetupAttachment(boxComp);

	// 스태틱 메시 컴포넌트의 상대적 위치를 (0, 0, -50)으로 설정하기
	meshComp->SetRelativeLocation(FVector(0, 0, -50));

}

void ABulletActor::BeginPlay()
{
	Super::BeginPlay();
	
	// Box 컴포넌트의 BeginOverlap 이벤트에 OnOverlap 함수를 바인딩한다.

}

void ABulletActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 자신의 위쪽 방향으로 speed 속력으로 이동하기
	SetActorLocation(GetActorLocation() + GetActorUpVector() * speed * DeltaTime);

}

void ABulletActor::OnOverlap()
{
	// 만일, 충돌한 액터가 AEnemy 클래스라면...
	
		// 충돌한 액터의 위치에서 explosionFX 이펙트를 실행한다.
		
		// 충돌한 액터를 제거한다.
	
		// 자신도 제거한다.


}

