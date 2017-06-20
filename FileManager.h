#pragma once
#include "header.h"
#include <dirent.h>
#include <errno.h>
#include <stdio.h>

using namespace std;

class FileManager {
private:
	string dir;
	list<string> fileList;
	list<string> ::iterator iter;
    list<string> ::iterator prev;
    DIR * pdir;
public:
    FileManager();
	FileManager(string &dir);
	string nextFilePath();
    static string pwd();
	void resetIter();
	bool hasNext();
    void checkFile(string path);
    void checkFile2(string path);
};