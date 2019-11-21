#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Components/ActorComponent.h" 

#include "UsefulBlueprintFunctionLibrary.generated.h"//Must be last include

//Need an include? Look it up: https://docs.unrealengine.com/en-US/index.html

//Squiggles? Ignore them. Try to compile, and check the OUTPUT window (not the error list).
//Also see
//C++ in Unreal: https://docs.unrealengine.com/en-US/Programming/Introduction/index.html
//Setting up Visual Studio for Unreal: https://docs.unrealengine.com/en-US/Programming/Development/VisualStudioSetup/index.html

//A class must be a UCLASS() to be visible in Editor.
//A function must be a UFUNCTION & usually BlueprintCallable to be visible in Editor.
//A variable must be a UPROPERTY (& usually EditAnywhere and/or BlueprintReadWrite) to be visible in editor.
//Also see:
//UCLASS:    https://docs.unrealengine.com/en-US/Programming/UnrealArchitecture/Reference/Classes/Specifiers/index.html
//UFUNCTION: https://docs.unrealengine.com/en-US/Programming/UnrealArchitecture/Reference/Functions/index.html
//UPROPERTY: https://docs.unrealengine.com/en-US/Programming/UnrealArchitecture/Reference/Properties/index.html

//Note that you can have classes/functions/variables that aren't UCLASS/UFUNCTION/UPROPERTY's, they will just be usable
//by other C++ code.
//Also note that public/private/protected only effect how other C++ code interacts with your code, not 
//how the editor can see or use your code.

UCLASS()
class DEFENDER_PROJECT_API UUsefulBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Helper Functions")
		static void LogWarning(FString text);

	UFUNCTION(BlueprintCallable, Category = "Helper Functions")
		static UActorComponent* SpawnActorComponent(TSubclassOf<UActorComponent> componentClass, AActor* owner);

	UFUNCTION(BlueprintCallable, Category = "Helper Functions")
		static USceneComponent* SpawnSceneComponent(TSubclassOf<USceneComponent> componentClass, AActor* owner, USceneComponent* attachTo = nullptr);

	UFUNCTION(BlueprintCallable, Category = "Helper Functions")
		static void SortByBoundsSize(UPARAM(ref) TArray<AActor*>& arr);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Helper Functions")//BlueprintPure means no white execution pin
		static bool HasComponent(const AActor* actor, const FName tag, const TSubclassOf<UActorComponent> componentClass);
};