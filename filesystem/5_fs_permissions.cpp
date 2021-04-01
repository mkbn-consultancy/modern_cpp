//source: https://en.cppreference.com/w/cpp/filesystem/permissions 

#include <fstream>
#include <bitset>
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

void demo_perms(fs::perms p)
{
    std::cout << ((p & fs::perms::owner_read) != fs::perms::none ? "r" : "-")
              << ((p & fs::perms::owner_write) != fs::perms::none ? "w" : "-")
              << ((p & fs::perms::owner_exec) != fs::perms::none ? "x" : "-")
              << ((p & fs::perms::group_read) != fs::perms::none ? "r" : "-")
              << ((p & fs::perms::group_write) != fs::perms::none ? "w" : "-")
              << ((p & fs::perms::group_exec) != fs::perms::none ? "x" : "-")
              << ((p & fs::perms::others_read) != fs::perms::none ? "r" : "-")
              << ((p & fs::perms::others_write) != fs::perms::none ? "w" : "-")
              << ((p & fs::perms::others_exec) != fs::perms::none ? "x" : "-")
              << '\n';
}
int main()
{
    fs::path file{"files/test.txt"}; 
 
    std::cout << "Print file's permissions:\t";
    auto perm = fs::status("test.txt").permissions();
    demo_perms(perm);
 
    fs::permissions(file,
                    fs::perms::owner_all,
                    fs::perm_options::remove);
 
    std::cout << "After removing permissions:\t";
    demo_perms(fs::status(file).permissions());
 
    fs::remove("test.txt");
}