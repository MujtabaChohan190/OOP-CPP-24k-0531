#include <iostream>
using namespace std;

class MediaFile {
public:
    virtual void play() {  // Virtual function
        cout << "Playing generic media file." << endl;
    }
};

class VideoFile : public MediaFile {
public:
    void play() override {  // Overriding base class method
        cout << "Playing video file." << endl;
    }
};

class AudioFile : public MediaFile {
public:
    void play() override {  // Overriding base class method
        cout << "Playing audio file." << endl;
    }
};

int main() {
    MediaFile* media1 = new VideoFile();  // Base class pointer pointing to derived object
    MediaFile* media2 = new AudioFile();  

    media1->play();  // Calls VideoFile's play() method (Runtime polymorphism)
    media2->play();  // Calls AudioFile's play() method (Runtime polymorphism)

    delete media1;
    delete media2;
    return 0;
}
