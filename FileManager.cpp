#include "FileManager.h"

FileManager::FileManager() {}

FileManager::FileManager(std::string &dir) {
    struct dirent *dir_entry;

    this->pdir = opendir(dir.c_str());

    if (NULL != pdir) {
        while (dir_entry = readdir(pdir)) {
            if (dir_entry->d_type == DT_DIR) {
                continue;
            }
            string path(dir_entry->d_name);
            if ((path.find(".jpg") != -1 || path.find(".jpeg") != -1) && path.find("check_") == -1) {
                string element(dir_entry->d_name);
                this->fileList.push_back(element);
            }
        }
    }

    iter = fileList.begin();
    prev = iter;
    std::cout<<this->fileList.size()<<std::endl;
}

string FileManager::nextFilePath() {
    if (fileList.size() == 0 || iter == fileList.end()) {
        return NULL;
    }
    this->prev = this->iter;
    return *(iter++);
}

void FileManager::resetIter() {
    if (fileList.size() == 0 || iter == fileList.end()) {
        return;
    }

    iter = fileList.begin();
}

bool FileManager::hasNext() {
    if (fileList.size() == 0 || iter == fileList.end()) {
        return false;
    }
    return true;
}

string FileManager::pwd() {
    char tmp[250];
    getcwd(tmp,sizeof(tmp));
    string ret(tmp);
    return ret;
}

void FileManager::checkFile(string path) {

    string original = path + *prev;
    string newName = path+"check_fire" + *prev;
    std::cout<<original<<" : ";
    std::cout<<newName<<std::endl;
    rename(original.c_str(), newName.c_str());
}

void FileManager::checkFile2(string path) {

    string original = path + *prev;
    string newName = path+"check_nofire" + *prev;
    std::cout<<original<<" : ";
    std::cout<<newName<<std::endl;
    rename(original.c_str(), newName.c_str());
}
