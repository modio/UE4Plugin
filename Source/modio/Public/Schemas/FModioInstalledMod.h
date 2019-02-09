// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioHWrapper.h"
#include "FModioMod.h"
#include "FModioInstalledMod.generated.h"

USTRUCT(BlueprintType)
struct FModioInstalledMod
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Path;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FModioMod mod;
};

extern void InitializeInstalledMod(FModioInstalledMod &installed_mod, const ModioInstalledMod &modio_installed_mod);