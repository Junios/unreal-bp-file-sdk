// Copyright Incanta Games 2020. All Rights Reserved.

#pragma once

#include <ios>
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FileSDKFileInfo.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"

#include "FileSDKBPLibrary.generated.h"

UCLASS()
class UFileSDKBPLibrary : public UBlueprintFunctionLibrary {
  GENERATED_UCLASS_BODY()

  UFUNCTION(
    BlueprintCallable,
    meta = (
      DisplayName = "Create File",
      Keywords = "FileSDK create make generate file"
    ),
    Category = "FileSDK"
  )
  static void CreateFile(FString FileName, bool ClearContentsIfExists = true, bool CreateDirectoryTree = true);

  UFUNCTION(
    BlueprintCallable,
    meta = (
      DisplayName = "Delete File",
      Keywords = "FileSDK delete file destroy"
    ),
    Category = "FileSDK"
  )
  static bool DeleteFile(FString FileName);

  UFUNCTION(
    BlueprintCallable,
    meta = (
      DisplayName = "Create Directory",
      Keywords = "FileSDK create make generate directory folder"
    ),
    Category = "FileSDK"
  )
  static bool CreateDirectory(FString DirectoryName, bool CreateDirectoryTree = true);

  UFUNCTION(
    BlueprintCallable,
    meta = (
      DisplayName = "Delete Directory",
      Keywords = "FileSDK delete destroy remove directory folder"
    ),
    Category = "FileSDK"
  )
  static bool DeleteDirectory(FString DirectoryName, bool Recursive = true);

  UFUNCTION(
    BlueprintCallable,
    meta = (
      DisplayName = "Rename File or Directory",
      Keywords = "FileSDK rename move file directory folder"
    ),
    Category = "FileSDK"
  )
  static bool RenameFileOrDirectory(FString Source, FString Destination);

  UFUNCTION(
    BlueprintCallable,
    meta = (
      DisplayName = "Copy File",
      Keywords = "FileSDK copy file"
    ),
    Category = "FileSDK"
  )
  static bool CopyFile(FString Source, FString Destination);

  UFUNCTION(
    BlueprintCallable,
    meta = (
      DisplayName = "Copy Directory",
      Keywords = "FileSDK copy directory folder"
    ),
    Category = "FileSDK"
  )
  static bool CopyDirectory(
    FString Source,
    FString Destination,
    bool OverwriteDestination = false
  );

  UFUNCTION(
    BlueprintPure,
    meta = (
      DisplayName = "Read String from File",
      Keywords = "FileSDK read file string text"
    ),
    Category = "FileSDK"
  )
  static bool ReadStringFromFile(FString FileName, FString & Content);

  UFUNCTION(
    BlueprintCallable,
    meta = (
      DisplayName = "Write String to File",
      Keywords = "FileSDK write append save file string text"
    ),
    Category = "FileSDK"
  )
  static bool WriteStringToFile(FString FileName, FString Content, bool Append = false);

  UFUNCTION(
    BlueprintCallable,
    meta = (
      DisplayName = "Write Bytes to File",
      Keywords = "FileSDK write save file bytes binary"
    ),
    Category = "FileSDK"
  )
  static bool WriteBytesToFile(FString FileName, TArray<uint8> Content);

  UFUNCTION(
    BlueprintPure,
    meta = (
      DisplayName = "Read Bytes from File",
      Keywords = "FileSDK read file bytes binary"
    ),
    Category = "FileSDK"
  )
  static bool ReadBytesFromFile(FString FileName, TArray<uint8> & Content);

  UFUNCTION(
    BlueprintCallable,
    meta = (
      DisplayName = "Get Files from Directory",
      Keywords = "FileSDK get search find files list directory contents"
    ),
    Category = "FileSDK"
  )
  static TArray<FString> GetFilesFromDirectory(
    FString DirectoryToSearch,
    FString FilterFilesWithExtension,
    bool SearchSubfolders = false
  );

  UFUNCTION(
    BlueprintPure,
    meta = (
      DisplayName = "Get File or Directory Info",
      Keywords = "FileSDK get file"
    ),
    Category = "FileSDK"
  )
  static void GetFileOrDirectoryInfo(FString Path, FFileSDKFileInfo & Info);
};
