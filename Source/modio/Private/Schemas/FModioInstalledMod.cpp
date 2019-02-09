// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "FModioInstalledMod.h"

void InitializeInstalledMod(FModioInstalledMod &installed_mod, const ModioInstalledMod &modio_installed_mod)
{
  installed_mod.Path = UTF8_TO_TCHAR(modio_installed_mod.path);
  InitializeMod(installed_mod.mod, modio_installed_mod.mod);
}