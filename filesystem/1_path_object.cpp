//compilation line: g++ -std=c++17 -lstdc++fs .\1_path_object.cpp

#include <iostream>

#ifdef __has_include
#   if __has_include(<filesystem>)
#       include <filesystem>
        namespace fs = std::filesystem;
#   else
#       include <experimental/filesystem>
        namespace fs = std::experimental::filesystem;       
#   endif
#endif

void test1()
{
        fs::path selectedPath(R"(C:\Windows\system.ini)");
        std::cout << selectedPath << std::endl;
        std::cout << selectedPath.string() << std::endl; //generic string
}

void test2()
{
        //an output for a file path like "C:\Windows\system.ini":
        fs::path pathToShow(R"(C:\Windows\system.ini)");
        std::cout << "exists() = "      << std::boolalpha << fs::exists(pathToShow) << "\n"
                << "root_name() = "     << pathToShow.root_name()       << "\n"
                << "root_path() = "     << pathToShow.root_path()       << "\n"
                << "relative_path() = " << pathToShow.relative_path()   << "\n"
                << "parent_path() = "   << pathToShow.parent_path()     << "\n"
                << "filename() = "      << pathToShow.filename()        << "\n"
                << "stem() = "          << pathToShow.stem()            << "\n"
                << "extension() = "     << pathToShow.extension()       << "\n";
}

void test3()
{
        fs::path pathToShow(R"(C:\Windows\system.ini)");
        int i = 0;    
        for (const auto& part : pathToShow)
                std::cout << "path part: " << i++ << " = " << part << "\n";
}

void test4()
{
        fs::path root {"/"};
        fs::path dir {"var/www/"};
        fs::path index {"index.html"};

        fs::path pathToIndex1 = root / dir / index;
 
        fs::path pathToIndex2 = root;
        pathToIndex2+= "var/www/";
        pathToIndex2+= "index.html";

        fs::path pathToIndex3 = root;
        pathToIndex3.append("var/www/").append("index.html");

        std::cout << pathToIndex1 << std::endl;
        std::cout << pathToIndex2 << std::endl;
        std::cout << pathToIndex3 << std::endl;
}

int main()
{
        std::cout<<"---------------\n"; 
        test1();
        std::cout<<"---------------\n";
        test2();
        std::cout<<"---------------\n";
        // test3();
        std::cout<<"---------------\n";
       return 0;
}