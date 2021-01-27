//
// Created by Ankit Batra on 1/26/21.
//

/* Design an in-memory file system to simulate the following functions:
 * ls: Given a path in string format.
 * If it is a file path, return a list that only contains this file's name.
 * If it is a directory path, return the list of file and directory names in this directory.
 * Your output (file and directory names together) should in lexicographic order.
 * mkdir: Given a directory path that does not exist, you should make a new directory according to the path.
 * If the middle directories in the path don't exist either, you should create them as well.
 * This function has void return type.
 * addContentToFile: Given a file path and file content in string format.
 * If the file doesn't exist, you need to create that file containing given content.
 * If the file already exists, you need to append given content to original content.
 * This function has void return type.
 * readContentFromFile: Given a file path, return its content in string format. */

#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::set;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

class FileSystem {
    unordered_map<string, string> fileMap; // file path -> file content
    unordered_map<string, set<string>> dirMap; // dir path -> list of dirs/files
public:
    FileSystem() {
        dirMap["/"];
    }

    vector<string> ls(string path) {
        vector<string> result;
        if (fileMap.find(path) != fileMap.end()) {
            int i = path.length() - 1;
            while (i >= 0 && path[i] != '/') --i;
            result.push_back(path.substr(i + 1));
        }
        if (dirMap.find(path) != dirMap.end()) {
            for (auto d : dirMap[path]) result.push_back(d);
        }
        return result;
    }

    void mkdir(string path) {
        string prev = "/";
        int pos = 1;
        for (int i = 1; i <= path.length(); ++i) {
            if (path[i] == '/' || i == path.length()) {
                dirMap[prev].insert(path.substr(pos, i - pos));
                pos = i + 1;
                prev = path.substr(0, i);
            }
        }
    }

    void addContentToFile(string filePath, string content) {
        int i = filePath.length() - 1;
        while (i >= 0 && filePath[i] != '/') --i;

        string path = filePath.substr(0, i);
        string fileName = filePath.substr(i + 1);

        if (path.empty()) path = '/';

        if (dirMap.find(path) == dirMap.end()) mkdir(path);
        dirMap[path].insert(fileName);
        fileMap[filePath].append(content);

    }

    string readContentFromFile(string filePath) {
        if (fileMap.find(filePath) != fileMap.end()) return fileMap[filePath];
        return "";
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
