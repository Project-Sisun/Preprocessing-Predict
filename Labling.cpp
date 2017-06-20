#include "header.h"


using namespace cv;
using namespace std;

Mat img_labels, stats, centroids;
int numOfLables;

int BRIGHT_LIMIT = 120, CrCb_LIMIT = 35;

list <CvRect> list_rect;
list<CvRect>::iterator iter_rect;

Mat Filtering(Mat image, int option) {
    Mat ret;

    image.copyTo(ret);

    switch (option) {
        case YCrCbR:
            for (int i = 0; i < ret.rows; i++) {
                for (int j = 0; j < ret.cols; j++) {
                    uchar *b = &(ret.at<cv::Vec3b>(i, j))[0];
                    uchar *g = &(ret.at<cv::Vec3b>(i, j))[1];
                    uchar *r = &(ret.at<cv::Vec3b>(i, j))[2];

                    double Y, Cr, Cb;

                    Y = floor(0.299 * (*r) + 0.587 * (*g) + 0.114 * (*b) + 0.5);
                    Cb = floor(-0.16874 * (*r) - 0.33126 * (*g) + 0.5 * (*b) + 0.5) + 128;
                    Cr = floor(0.5 * (*r) - 0.41869 * (*g) - 0.08131 * (*b) + 0.5) + 128;

                    int tmp = abs(Cb - Cr);

                    ret.at<cv::Vec3b>(i, j)[0] = (uchar)Y;
                    ret.at<cv::Vec3b>(i, j)[1] = (uchar)tmp;
                }
            }
            return ret;
        case YCbR:
            for (int i = 0; i < ret.rows; i++) {
                for (int j = 0; j < ret.cols; j++) {
                    uchar *b = &(ret.at<cv::Vec3b>(i, j))[0];
                    uchar *g = &(ret.at<cv::Vec3b>(i, j))[1];
                    uchar *r = &(ret.at<cv::Vec3b>(i, j))[2];

                    double Y, Cr, Cb;

                    Y = floor(0.299 * (*r) + 0.587 * (*g) + 0.114 * (*b) + 0.5);
                    Cb = floor(-0.16874 * (*r) - 0.33126 * (*g) + 0.5 * (*b) + 0.5) + 128;
                    Cr = floor(0.5 * (*r) - 0.41869 * (*g) - 0.08131 * (*b) + 0.5) + 128;

                    ret.at<cv::Vec3b>(i, j)[0] = (uchar)Y;
                    ret.at<cv::Vec3b>(i, j)[1] = (uchar)Cb;
                }
            }
            return ret;
        case YCrCbBinary:
            for (int i = 0; i < ret.rows; i++) {
                for (int j = 0; j < ret.cols; j++) {
                    uchar *b = &(ret.at<cv::Vec3b>(i, j))[0];
                    uchar *g = &(ret.at<cv::Vec3b>(i, j))[1];
                    uchar *r = &(ret.at<cv::Vec3b>(i, j))[2];

                    double Y, Cr, Cb;

                    Y = floor(0.299 * (*r) + 0.587 * (*g) + 0.114 * (*b) + 0.5);
                    Cb = floor(-0.16874 * (*r) - 0.33126 * (*g) + 0.5 * (*b) + 0.5) + 128;
                    Cr = floor(0.5 * (*r) - 0.41869 * (*g) - 0.08131 * (*b) + 0.5) + 128;

                    bool test = Y >= BRIGHT_LIMIT && abs(Cb - Cr) >= CrCb_LIMIT;
                    ret.at<cv::Vec3b>(i, j)[0] = test ? 255 : 0;
                    ret.at<cv::Vec3b>(i, j)[1] = test ? 255 : 0;
                    ret.at<cv::Vec3b>(i, j)[2] = test ? 255 : 0;
                }
            }
            return ret;
    }
}

Mat Labeling(Mat image, bool option, int areaLimit, int YLimit, int CrCbLimit) {
    Mat buf = Filtering(image, YCrCbBinary).clone();
    Mat buf2;

    cvtColor(buf, buf2, COLOR_BGR2GRAY);
    threshold(buf2, buf2, 127, 255, THRESH_BINARY);
    numOfLables = connectedComponentsWithStats(buf2, img_labels, stats, centroids, 8, CV_32S);

    int imgSize = image.rows * image.cols;

    list_rect.clear();
    //라벨링 된 이미지에 각각 직사각형으로 둘러싸기
    for (int j = 1; j < numOfLables; j++) {
        int area = stats.at<int>(j, CC_STAT_AREA);
        int left = stats.at<int>(j, CC_STAT_LEFT);
        int top = stats.at<int>(j, CC_STAT_TOP);
        int width = stats.at<int>(j, CC_STAT_WIDTH);
        int height = stats.at<int>(j, CC_STAT_HEIGHT);

        int x = centroids.at<double>(j, 0); //중심좌표
        int y = centroids.at<double>(j, 1);

        if (option) {

        }
        else {
            if (area >= areaLimit && area <= imgSize * 0.4 ) {
                list_rect.push_back(CvRect(left, top, width, height));
            }
        }
    }
    return image;
}



bool extractFireSubImage(Mat original, int option) {
    static bool first = true;
    Labeling(original);

    
    int rect_count = list_rect.size();
    bool flag = false;
    Mat sub, subResize;

    cout << rect_count << endl;

    if(first) {
        pArg1 = PyTuple_New(32 * 32*3);
        first = false;
    }

    for (iter_rect = list_rect.begin(); iter_rect != list_rect.end(); iter_rect++) {
        sub = original((*iter_rect));
        switch (option) {
            case YCrCbR:

                resize(sub, subResize, Size(32, 32), 0, 0, CV_INTER_NN);
                subResize = Filtering(subResize, YCrCbR);

                int index=0;
                for (int i = 0; i < 32; i++) {
                    for (int j = 0; j < 32; j++) {
                        uchar Y = (subResize.at<cv::Vec3b>(i, j))[0];
                        uchar CrCb = (subResize.at<cv::Vec3b>(i, j))[1];
                        uchar R = (subResize.at<cv::Vec3b>(i, j))[2];

                        PyTuple_SetItem(pArg1, index++, PyLong_FromLong(Y));
                        PyTuple_SetItem(pArg1, index++, PyLong_FromLong(CrCb));
                        PyTuple_SetItem(pArg1, index++, PyLong_FromLong(R));
                        //index++;
                    }
                }
                if (PyCallable_Check(pFunc)) {
                    pValue = PyObject_CallFunctionObjArgs(pFunc,pArg1,NULL);
                    if (pValue == nullptr)
                    {
                        PyErr_Print();
                        std::exit(1);
                    }
                    bool ret = PyLong_AsLong(pValue) == 1 ? true : false;
                    flag |= ret;
                    if(flag |= ret){
                        return flag;
                    }
                }
                break;
        }
    }
    return flag;
}