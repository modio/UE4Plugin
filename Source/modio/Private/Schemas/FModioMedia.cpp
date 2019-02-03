// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "FModioMedia.h"

void InitializeMedia(FModioMedia &media, const modio::Media &modio_media)
{
  for (u32 i = 0; i < modio_media.youtube.size(); i++)
    media.Youtube.Add(UTF8_TO_TCHAR(modio_media.youtube[i].c_str()));
  for (u32 i = 0; i < modio_media.sketchfab.size(); i++)
    media.Sketchfab.Add(UTF8_TO_TCHAR(modio_media.sketchfab[i].c_str()));
  for (u32 i = 0; i < modio_media.images.size(); i++)
  {
    FModioImage image;
    InitializeImage(image, modio_media.images[i]);
    media.Images.Add(image);
  }
}

void InitializeMediaC(FModioMedia &media, const ModioMedia &modio_media)
{
  for (u32 i = 0; i < modio_media.youtube_size; i++)
    media.Youtube.Add(UTF8_TO_TCHAR(modio_media.youtube_array[i]));
  for (u32 i = 0; i < modio_media.sketchfab_size; i++)
    media.Sketchfab.Add(UTF8_TO_TCHAR(modio_media.sketchfab_array[i]));
  for (u32 i = 0; i < modio_media.images_size; i++)
  {
    FModioImage image;
    InitializeImageC(image, modio_media.images_array[i]);
    media.Images.Add(image);
  }
}