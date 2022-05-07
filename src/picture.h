#ifndef PICTURE_H
#define PICTURE_H
//Class for creation the object of a picture with name, width and height.
class Picture
{
public:
    Picture() {};

    void SetAll(std::string p_name, std::string p_width, std::string p_height, int p_id);

    std::string GetName();
    std::string GetHeight();
    std::string GetWidth();
    int GetId();

private:
    std::string width, height;
    int Id;
    std::string name;
};

#endif 
