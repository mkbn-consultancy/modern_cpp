//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

void manipulateFile(const std::string& fName){
    //open the file and do some manipulation on it
    try{
        std::ifstream fin(fName);
        if(!fin.is_open()){
            std::cout<<"[manipulateFile:] throw: ";
            throw std::runtime_error("cannot open file ");
        }
        else{
            //do some staff...
            fin.close();
        }
    }
    catch(std::runtime_error& ex){
        std::runtime_error err(fName + ": " + ex.what());
        std::cout<<err.what()<<std::endl;
        ex = err;
        throw;
    }
}

void processFiles(const std::vector<std::string>& files){
    int numBrokenPaths = 0;
    //process all files
    for(auto f : files){
        try{
                manipulateFile(f);
            }
            catch(std::runtime_error& ex){
                numBrokenPaths++;
                if(numBrokenPaths > 0.3*files.size()){
                    std::cout<<"[processFile:] throwing exception of threashold\n";
                    throw std::runtime_error("Too many broken paths, process stopped!");
                }
            }
    }
}

int main(){
    std::vector<std::string> filePaths {R"(C:\filesForModernCpp\1.txt)",
                                        R"(C:\filesForModernCpp\2.txt)",
                                        R"(C:\filesForModernCpp\3.txt)",
                                        R"(C:\filesForModernCpp\4.txt)",
                                        R"(C:\filesForModernCpp\5.txt)",
                                        R"(C:\filesForModernCpp\6.txt)",
                                        R"(C:\filesForModernCpp\7.txt)",
                                        R"(C:\filesForModernCpp\8.txt)",
                                        R"(C:\filesForModernCpp\9.txt)"
                                        };
    try{
        processFiles(filePaths);
    }
    catch(std::runtime_error& err){
        std::cout<<"[in main]: Exception: "<<err.what();
    }
}