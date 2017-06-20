#include "header.h"
#include "FileManager.h"

using namespace std;
using namespace cv;

PyObject *pArg1,*pArg2,*pArg3, *pModule, *pFunc_open,*pFunc_close, *pFunc, *pValue;



void python_open(){
    Py_Initialize();

    PyRun_SimpleString("import sys");
    /*PyRun_SimpleString("import tensorflow as tf");
    PyRun_SimpleString("import os");*/

    PyRun_SimpleString("sys.path");
    PyRun_SimpleString("sys.argv = ['']");
    // PyRun_SimpleString("sys.path.append('/home/sisun/Desktop/hee2')");
    PyRun_SimpleString("sys.path.append('/home/sisun/CLionProjects/untitled/ckpt')");
    PyRun_SimpleString("sys.path.append('/home/sisun/.pyenv/versions/3.5.3/lib/python3.5/site-packages')");
    PyRun_SimpleString("print(sys.version)");

    pModule = PyImport_ImportModule("isFire2");
    if (pModule == nullptr)
    {
        PyErr_Print();
        std::exit(1);
    }
    pFunc = PyObject_GetAttrString(pModule, "isFire");
    pFunc_open = PyObject_GetAttrString(pModule, "MLOpen");
    if (PyCallable_Check(pFunc_open)) {
        pValue = PyObject_CallFunctionObjArgs(pFunc_open, NULL);
    }

    //init_rtsp();
}

void python_close(){
   // pFunc_close = PyObject_GetAttrString(pModule, "MLClose");
    Py_Finalize();
    finishFlag1 = false;
}

void *t_function(void *data)
{
    decoding();
}


int main(int argc, char *argv[]) {
    int fcount=0;
    int ncount=0;
    int tcount=0;
    string path = "/home/sisun/Pictures/";
    //string path = "/home/sisun/Desktop/hdd/";
    FileManager fileManager(path);

    python_open();

    while(fileManager.hasNext()){
        string dir = path + fileManager.nextFilePath();
        Mat original = imread(dir);

        if(original.rows ==0 || original.cols ==0){
            continue;
        }
        if(extractFireSubImage(original,YCrCbR)){
            fileManager.checkFile(path);
            fcount++;
        }else{
            fileManager.checkFile2(path);
            ncount++;
        }
        tcount++;
        std::cout<<fcount<<"/"<<tcount<<"-> "<<((double)fcount/(double)tcount)*100<<std::endl;
        std::cout<<ncount<<"/"<<tcount<<"-> "<<((double)ncount/(double)tcount)*100<<std::endl;

    }

    python_close();
    return 0;
}

