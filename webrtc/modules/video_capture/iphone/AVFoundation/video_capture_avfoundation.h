/*
 *  Copyright (c) 2011 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef WEBRTC_MODULES_VIDEO_CAPTURE_MAIN_SOURCE_IPHONE_AVFOUNDATION_VIDEO_CAPTURE_AVFOUNDATION_H_
#define WEBRTC_MODULES_VIDEO_CAPTURE_MAIN_SOURCE_IPHONE_AVFOUNDATION_VIDEO_CAPTURE_AVFOUNDATION_H_

#import <AVFoundation/AVFoundation.h>

#include <stdio.h>

#include "../../video_capture_impl.h"
#include "video_capture_avfoundation_utility.h"
#include "../../device_info_impl.h"
#include "webrtc_libyuv.h"


// Forward declaraion
@class VideoCaptureIPhoneAVFoundationObjC;
@class VideoCaptureIPhoneAVFoundationInfoObjC;

namespace webrtc
{
namespace videocapturemodule
{

class VideoCaptureIPhoneAVFoundation : public VideoCaptureImpl
{
public:
    VideoCaptureIPhoneAVFoundation(const int32_t id);
    virtual ~VideoCaptureIPhoneAVFoundation();

    /*
    *   Create a video capture module object
    *
    *   id - unique identifier of this video capture module object
    *   deviceUniqueIdUTF8 -  name of the device. Available names can be found
    *       by using GetDeviceName
    *   deviceUniqueIdUTF8Length - length of deviceUniqueIdUTF8
    */
    static void Destroy(VideoCaptureModule* module);

    int32_t Init(const int32_t id,
                       const char* deviceUniqueIdUTF8);


    // Start/Stop
    virtual int32_t StartCapture(
        const VideoCaptureCapability& capability);
    virtual int32_t StopCapture();

    // Properties of the set device

    virtual bool CaptureStarted();

    int32_t CaptureSettings(VideoCaptureCapability& settings);

protected:
    // Help functions
    int32_t SetCameraOutput();

private:
    VideoCaptureIPhoneAVFoundationObjC*        _captureDevice;
    VideoCaptureIPhoneAVFoundationInfoObjC*    _captureInfo;
    bool                    _isCapturing;
    int32_t            _id;
    int32_t            _captureWidth;
    int32_t            _captureHeight;
    int32_t            _captureFrameRate;
    bool                     _faceDetection;
    uint8_t            _currentDeviceNameUTF8[MAX_NAME_LENGTH];
    uint8_t            _currentDeviceUniqueIdUTF8[MAX_NAME_LENGTH];
    uint8_t            _currentDeviceProductUniqueIDUTF8[MAX_NAME_LENGTH];
    int32_t            _frameCount;
};
}  // namespace videocapturemodule
}  // namespace webrtc

#endif  // WEBRTC_MODULES_VIDEO_CAPTURE_MAIN_SOURCE_IPHONE_AVFOUNDATION_VIDEO_CAPTURE_AVFOUNDATION_H_
