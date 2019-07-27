#include <string>
using namespace std;

string get_file_name(string file_path);

string get_file_name(string file_path) {
    int pos = file_path.rfind('/');
    return file_path.substr(pos  + 1);
}

