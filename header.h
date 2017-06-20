//
// Created by sisun on 17. 5. 12.
//

#ifndef UNTITLED1_HEADER_H
#define UNTITLED1_HEADER_H

#include <Python.h>
#include <opencv2/opencv.hpp>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <iostream>

///////////////////////
#define YCrCb 0
#define YCrCbBinary 1
#define YCrCbR 2
#define YCbR 3
///////////////////////
//변경하면 작동이 달라짐

cv::Mat Filtering(cv::Mat image, int option);

cv::Mat Labeling(cv::Mat image, bool option = false, int areaLimit = 64, int YLimit = 120,
                 int CrCbLimit = 35); //1.이미지 2.옵션(YCrCb or YCrCbBinary)
bool extractFireSubImage(cv::Mat original, int option);

int init_rtsp();
void decoding();
void destroy();

extern uint8_t * dst;
extern int hei,wid,cha;
extern bool finishFlag1;
extern cv::Mutex imgmtx;
extern int imgBufSize;
extern bool isFull1;

extern PyObject *pArg1,*pArg2,*pArg3, *pModule, *pFunc, *pValue;

#endif //UNTITLED1_HEADER_H
