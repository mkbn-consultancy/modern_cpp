#ifdef __has_include
#   if __has_include(<filesystem>)
#       include <filesystem>
        namespace fs = std::filesystem;
#   else
#       include <experimental/filesystem>
        namespace fs = std::experimental::filesystem;       
#   endif
#endif

#include <iostream>

//forward declarations
void test3_delete_directory(std::string_view file);


void test1_check_file_exists(std::string_view file)
{
    fs::path currPath{file};
    if(!fs::exists(currPath)){
        std::cout<<"Error: file "<<currPath.string()<<" does not exists!\n";
        return;
    }
}

void test2_create_new_directory(std::string_view file)
{
    //create a new directory under the given path
    fs::path currPath{file};
    currPath /= "NewDir";
    
    if(fs::exists(currPath)){
        std::cout<<"File already exists... ";
        test3_delete_directory(currPath.string());
    }

    if(!fs::create_directory(currPath)){
        std::cout<<"Error: could not create directory "<<currPath.string()<<std::endl;
    }
    else{
        std::cout<<"Directory "<<currPath.string()<<" was create successfuly\n";
    }
}

void test3_delete_directory(std::string_view file)
{
    if(!fs::remove(file)){
        std::cout<<"Error: could not delete file "<<file<<std::endl;
    }
    else{
        std::cout<<"File "<<file<<" was successfuly deleted\n";
    }
}

void test4_change_file_name(std::string_view file)
{
    fs::directory_entry entry{ file };
    std::cout << entry << '\n';
    entry.replace_filename("hello.txt");    //This function does not commit any changes to the filesystem!
    std::cout << entry << '\n';
 }

int main()
{
    std::cout<<"----------------\n";
    std::string filePath{ R"(files\)" };

    test1_check_file_exists(filePath);

    std::cout<<"----------------\n";
    test2_create_new_directory(filePath);
    test2_create_new_directory(filePath);   //will fail (if won't delete) since new dir is already created

    std::cout<<"----------------\n";
    std::string filePath2 = filePath + R"(\cpp_docs\file1.txt)";
    test4_change_file_name(filePath2);
}