#pragma once

// ReSharper disable IdentifierTypo
// ReSharper disable CppInconsistentNaming
// ReSharper disable CppNonInlineFunctionDefinitionInHeaderFile

#include "include_opencv.h"

#ifndef _WINRT_DLL

CVAPI(void) objdetect_QRCodeDetector_new(cv::QRCodeDetector **returnValue)
{
    *returnValue = new cv::QRCodeDetector();
}

CVAPI(void) objdetect_QRCodeDetector_delete(cv::QRCodeDetector *obj)
{
    delete obj;
}

CVAPI(void) objdetect_QRCodeDetector_setEpsX(cv::QRCodeDetector *obj, double epsX)
{
    obj->setEpsX(epsX);
}

CVAPI(void) objdetect_QRCodeDetector_setEpsY(cv::QRCodeDetector *obj, double epsY)
{
    obj->setEpsY(epsY);
}

CVAPI(void) objdetect_QRCodeDetector_detect(
    cv::QRCodeDetector *obj, cv::_InputArray *img, std::vector<cv::Point2f> *points, int *returnValue)
{
    *returnValue = obj->detect(*img, *points) ? 1 : 0;
}

CVAPI(void) objdetect_QRCodeDetector_decode(
    cv::QRCodeDetector *obj, cv::_InputArray *img, std::vector<cv::Point2f> *points, cv::_OutputArray *straight_qrcode, std::string *returnValue)
{
    *returnValue = obj->decode(*img, *points, entity(straight_qrcode));
}

CVAPI(void) objdetect_QRCodeDetector_detectAndDecode(
    cv::QRCodeDetector *obj, cv::_InputArray *img, std::vector<cv::Point2f> *points,
    cv::_OutputArray *straight_qrcode, std::string *returnValue)
{
    *returnValue = obj->detectAndDecode(*img, *points, entity(straight_qrcode));
}

CVAPI(void) objdetect_QRCodeDetector_detectMulti(
    cv::QRCodeDetector* obj, cv::_InputArray* img, std::vector<cv::Point2f>* points, int* returnValue)
{
    *returnValue = obj->detectMulti(*img, *points) ? 1 : 0;
}

CVAPI(void) objdetect_QRCodeDetector_decodeMulti(
    cv::QRCodeDetector* obj, cv::_InputArray* img, std::vector<cv::Point2f>* points, std::vector<std::string>* decoded_info, std::vector<cv::Mat>* straight_qrcode, int* returnValue)
{
    *returnValue = obj->decodeMulti(*img, *points, *decoded_info, *straight_qrcode) ? 1 : 0;
}

CVAPI(void) objdetect_QRCodeDetector_decodeMulti_NoStraightQrCode(
    cv::QRCodeDetector* obj, cv::_InputArray* img, std::vector<cv::Point2f>* points, std::vector<std::string>* decoded_info, int* returnValue)
{
    *returnValue = obj->decodeMulti(*img, *points, *decoded_info) ? 1 : 0;
}

#endif
