#include <iostream>
// #include <ctime>
// #include <chrono>
#include <vector>
#include <string>
#include <algorithm>

#ifdef __has_include
#   if __has_include(<filesystem>)
#       include <filesystem>
        namespace fs = std::filesystem;
#   else
#       include <experimental/filesystem>
        namespace fs = std::experimental::filesystem;       
#   endif
#endif

void test1_simple_directory_entry(const std::string& filePath)
{
    fs::directory_entry entry{ filePath };

    std::cout<<"is directory? "<< std::boolalpha << entry.is_directory() << std::endl;
    std::cout<<"file size: "<< entry.file_size() << " bytes" << std::endl;
}

void test2_directory_iterator(const std::string& filePath)
{
    fs::path currPath{filePath};
     std::cout<<"The content of the director "<<currPath.string()<<": \n";
    for(const auto& dir_entry : fs::directory_iterator{currPath}){
        std::cout<< dir_entry.path().string() <<std::endl;
     }
}

void test3_directory_iterator_with_data(const std::string& filePath)
{
    fs::path currPath{ filePath };
    std::cout<<"The content of the director "<<currPath.string()<<": \n";
    for(const auto& dir_entry : fs::directory_iterator{currPath}){
        // std::cout<< dir_entry.path().string() <<std::endl;
        switch(const auto& f = dir_entry.path(); dir_entry.status().type()){
            case fs::file_type::directory:
                std::cout<<"[DIR]\t"<<f.string()<<std::endl;
                break;
            case fs::file_type::regular:
                std::cout<<'\t'<<f.string()<<'\t'<<dir_entry.file_size()<<std::endl;
                break;
        }
    }
}

//we will use the algorithm sts::partition on the directory entries.
//std::partition reorders the elements in the range [first, last) 
//in such a way that all elements for which the predicate p returns true 
//precede the elements for which predicate p returns false. 
//Relative order of the elements is not preserved.
void test4_parition_directories_and_files(const std::string& filePath)
{
    fs::path currPath{filePath};
    std::vector<fs::directory_entry> dir_entries{};

    for(const auto& dir_entry : fs::directory_iterator{currPath}){
        dir_entries.push_back(dir_entry);
    }

    std::partition(std::begin(dir_entries), std::end(dir_entries), [](const fs::directory_entry& de){ return de.is_directory();});

    for(const auto& dir_entry : dir_entries){
        // std::cout<< dir_entry.path().string() <<std::endl;
        switch(const auto& f = dir_entry.path(); dir_entry.status().type()){
            case fs::file_type::directory:
                std::cout<<"[DIR]\t"<<f.string()<<std::endl;
                break;
            case fs::file_type::regular:
                std::cout<<'\t'<<f.string()<<'\t'<<dir_entry.file_size()<<std::endl;
                break;
        }
    }
}


int main()
{
    std::string filePath{ R"(files\)" };
    
    std::cout<<"----------------\n";
    std::string filePath2 = filePath + "\\personal_data.txt";
    test1_simple_directory_entry(filePath2);

    std::cout<<"----------------\n";
    test2_directory_iterator(filePath);
 
    std::cout<<"----------------\n";
    test3_directory_iterator_with_data(filePath);

    std::cout<<"----------------\n";
    test4_parition_directories_and_files(filePath);

    std::cout<<"----------------\n";
 }