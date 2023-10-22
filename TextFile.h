#ifndef TEXTFILE_H
#define TEXTFILE_H

#include "Markup.h"

#include <fstream>
#include <sstream>

using namespace std;

class TextFile
{
protected:
    const string FILE_NAME;

    bool isFileEmpty(fstream &textFile);

public:
    TextFile(string fileName) : FILE_NAME(fileName) {};
};


#endif
