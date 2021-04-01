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

void test1_print_file_size(std::string_view file)
{
    std::cout<<"Size of file "<<file<<" is: "<<fs::file_size(file)<<std::endl;
}

void test1_delete_directory(std::string_view file)
{
    if(!fs::remove(file)){
        std::cout<<"Error: could not delete file "<<file<<std::endl;
    }
    else{
        std::cout<<"File "<<file<<" was successfuly deleted\n";
    }
}

int main()
{
    std::cout<<"----------------\n";
    std::string filePath{ R"(files\)" };

    try{
        test1_print_file_size(filePath);
    }catch(fs::filesystem_error& e){
       std::cout<<"[Exception]: "<<e.what()<<std::endl;
    }

    try{
        test1_print_file_size("dont_exists_file");
    }catch(fs::filesystem_error& e){
        std::cout<<"[Exception]: "<<e.what()<<std::endl;
    }

    std::cout<<"----------------\n";

    std::error_code ec{};
    fs::file_size("dont_exists_file",ec);
    if(ec){
        std::cout<<"Error! "<<ec.message()<<std::endl;
    }

   std::cout<<"----------------\n";
}