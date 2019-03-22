#pragma once

#include "CoreMinimal.h"
#include "ModioResponse.h"
#include "Customizables/ModioModCreator.h"
#include "Customizables/ModioModEditor.h"
#include "ModioPackage.h"
#include "ModioPackage.h"
#include "AsyncRequest/ModioAsyncRequest_EmailExchange.h"
#include "AsyncRequest/ModioAsyncRequest_EmailRequest.h"
#include "AsyncRequest/ModioAsyncRequest_AddMod.h"
#include "AsyncRequest/ModioAsyncRequest_EditMod.h"

typedef TSharedPtr<struct FModioSubsystem, ESPMode::Fast> FModioSubsystemPtr;

/**
 * Interface for the modio c++ UE4 API. Please note that this class shouldn't
 * hold any references to any UObjects derived classes, as it is right now, as it's
 * not exposed to the GC. Reference objects with WeakObjectPointer if you want to
 * hold references to Object/Actors. And keep other pointers with Shared/Unique ptrs
 */
struct MODIO_API FModioSubsystem : public TSharedFromThis<FModioSubsystem, ESPMode::Fast>
{
public:
  static FModioSubsystemPtr Get(UWorld *World);

  virtual ~FModioSubsystem();

  /** Request an email from to the mod.io backend */
  void EmailRequest(const FString &Email, FEmailRequestDelegate ExchangeDelegate);

  /** Send your Security code to the backend */
  void EmailExchange(const FString &SecurityCode, FEmailExchangeDelegate ExchangeDelegate);

  /** Creates a new mod profile on mod.io */
  void AddMod(const FModioModCreator &ModCreator, FAddModDelegate AddModDelegate);

  /** Edits an already existing mod profile on mod.io */
  void EditMod(const FModioModEditor &ModEditor, uint32 ModId, FEditModDelegate EditModDelegate);

protected:
  friend class FModioModule;
  static FModioSubsystemPtr Create(const FString &RootDirectory, uint32 GameId, const FString &ApiKey, bool bIsLiveEnvironment);

  /** Queue up a new async request and take ownership of the memory */
  void QueueAsyncTask(struct FModioAsyncRequest *Request);
  PACKAGE_SCOPE :
      /** Called by the async request when it's done */
      void
      AsyncRequestDone(struct FModioAsyncRequest *Request);

  /** Should only be create from our create function */
  FModioSubsystem();

  /** Can be called multiple times during a session, as long as it's properly paired with it's shutdown */
  void Init(const FString &RootDirectory, uint32 GameId, const FString &ApiKey, bool bIsLiveEnvironent);

  /** Properly shutdowns modio */
  void Shutdown();

private:
  /** All running async requests */
  TArray<TSharedPtr<struct FModioAsyncRequest>> AsyncRequests;

  /** Are we initialized */
  uint8 bInitialized : 1;
};