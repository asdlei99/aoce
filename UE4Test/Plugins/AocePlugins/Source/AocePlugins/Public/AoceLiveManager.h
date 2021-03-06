// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "aoce/AoceCore.h"
#include "Engine/Texture2D.h"
#include "AoceDisplayActor.h"
#include <string>
#include <memory>
/**
 *
 */
class AOCEPLUGINS_API AoceLiveManager : public aoce::ILiveObserver
{
public:
	AoceLiveManager();
	virtual ~AoceLiveManager() override;
private:
	aoce::LiveRoom* room = nullptr;
	AAoceDisplayActor* display = nullptr;

private:
	void aoceMsg(int32_t level, const char* message);
public:
	aoce::LiveRoom* getRoom();
	void initRoom(aoce::LiveType liveType, AAoceDisplayActor* display);
	//void updateTexture();
public:
	virtual void onEvent(int32_t operater, int32_t code, aoce::LogLevel level,
		const std::string& msg) override;
	virtual void onInitRoom() override;
	virtual void onLoginRoom(bool bReConnect = false) override;
	virtual void onUserChange(int32_t userId, bool bAdd) override;
	virtual void onStreamUpdate(int32_t index, bool bAdd, int32_t code) override;
	virtual void onStreamUpdate(int32_t userId, int32_t index, bool bAdd,
		int32_t code) override;
	virtual void onVideoFrame(int32_t userId, int32_t index,
		const aoce::VideoFrame& videoFrame) override;
	virtual void onAudioFrame(int32_t userId, int32_t index,
		const aoce::AudioFrame& audioFrame) override;
	virtual void onPushQuality(int32_t index, int32_t quality, float fps,
		float kbs) override;
	virtual void onPullQuality(int32_t userId, int32_t index, int32_t quality,
		float fps, float kbs) override;
	virtual void onLogoutRoom() override;
};
