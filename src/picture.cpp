#include <string>
#include "picture.h"
using namespace std;
//Class for creation the object of a picture with name, width and height.
    void Picture::SetAll(string p_name, string p_width, string p_height, int p_id) {
        name = p_name;
        height = p_height;
        width = p_width;
        Id = p_id;
    }

    string Picture::GetName() {
        return name;
    }
    string Picture::GetHeight() {
        return height;
    }
    string Picture::GetWidth() {
        return width;
    }
    int Picture::GetId() {
        return Id;
    }
