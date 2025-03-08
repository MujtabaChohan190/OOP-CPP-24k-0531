#include <iostream>
#include <string>
using namespace std;


class MediaFile {
protected:
    string filePath;
    double size;  

public:
    MediaFile(string path, double sz) : filePath(path), size(sz) {}
    
    virtual void play() = 0;  // Pure virtual function is being used as different functions would have different functionalities related to it 
    virtual void stop() {
        cout << "Stopping media file: " << filePath << endl;
    }

    virtual ~MediaFile() {}  // Since We will use base class pointers to refer to derived objects. We might delete objects through the base class pointer. A virtual destructor ensures that when an object is deleted through a base class pointer, the destructor of the derived class is also called
};

// Intermediate class for visual media (Images & Videos)
class VisualMedia : virtual public MediaFile {
protected:
    string resolution;

public:
    VisualMedia(string path, double sz, string res) 
        : MediaFile(path, sz), resolution(res) {}

    void displayResolution() {
        cout << "Resolution: " << resolution << endl;
    }
};

// Intermediate class for audio media (Audio & Videos)
class AudioMedia : virtual public MediaFile {
protected:
    int sampleRate;  // in kHz

public:
    AudioMedia(string path, double sz, int rate) 
        : MediaFile(path, sz), sampleRate(rate) {}

    void displaySampleRate() {
        cout << "Sample Rate: " << sampleRate << " kHz" << endl;
    }
};


class ImageFile : public VisualMedia {
public:
    ImageFile(string path, double sz, string res) 
        : MediaFile(path, sz), VisualMedia(path, sz, res) {}

    void play() override {
        cout << "Displaying image: " << filePath << " at " << resolution << endl;
    }
};


class AudioFile : public AudioMedia {
public:
    AudioFile(string path, double sz, int rate) 
        : MediaFile(path, sz), AudioMedia(path, sz, rate) {}

    void play() override {
        cout << "Playing audio file: " << filePath << " at " << sampleRate << " kHz" << endl;
    }
};

// Video File (inherits from both AudioMedia and VisualMedia) - that is the reason both should have virtual inheritance so that mediafile does not get duplicated
class VideoFile : public VisualMedia, public AudioMedia {
public:
    VideoFile(string path, double sz, string res, int rate) 
        : MediaFile(path, sz), VisualMedia(path, sz, res), AudioMedia(path, sz, rate) {}

    void play() override {
        cout << "Playing video file: " << filePath 
             << " at " << resolution 
             << " resolution with " << sampleRate << " kHz audio.\n";
    }

    void stop() override {
        cout << "Stopping video playback: " << filePath << endl;
    }
};

int main() {
    MediaFile* files[] = {    //Instead of vectors , dynamically doing the things
        new ImageFile("photo.jpg", 5.2, "1920x1080"),
        new AudioFile("song.mp3", 3.1, 44),
        new VideoFile("movie.mp4", 700, "1920x1080", 48)
    };

    // Testing runtime polymorphism - Runtime polymorphism  refers to the ability of a base class pointer or reference to invoke derived class methods dynamically at runtime. 
    for (int i = 0; i < 3; i++) {
        files[i]->play();
        files[i]->stop();
        cout << "---\n";
    }

    // Cleanup
    for (int i = 0; i < 3; i++) {
        delete files[i];
    }

    return 0;
}
