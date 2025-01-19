#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    
    int totalLength = 0;
    int lineCount = 0;
    
    while (!inf.eof()) {
        std::string word = inf.readToken("[A-Z]{1,63}", "word");
        inf.readEoln();
        totalLength += word.length() + 1;
        lineCount++;
        ensuref(totalLength <= 32768, "Total file size exceeds 32K");
    }
    
    ensuref(lineCount >= 1, "At least one word is required");
    inf.readEof();
} 