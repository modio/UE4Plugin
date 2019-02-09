// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioHWrapper.h"
#include "FModioTag.generated.h"

USTRUCT(BlueprintType)
struct FModioTag
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 DateAdded;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Name;
};

extern void InitializeTag(FModioTag &tag, const ModioTag &modio_tag);