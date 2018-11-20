#include <iostream>
#include <boost/filesystem.hpp>
void list_all_files_in_workdir() {
    namespace BFS = boost::filesystem;
    BFS::path p1( "." );
    std::cout << "Files in " << p1 << std::endl;
    for( BFS::directory_iterator it = BFS::directory_iterator(p1); 
        it != BFS::directory_iterator(); ++ it )
    {
        BFS::path px = it->path();
        std::cout << px.filename() << "\n";
    }
}