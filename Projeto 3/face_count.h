#ifndef FACE_COUNT_H
#define FACE_COUNT_H
#include <exception>
#include <string>
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace std;
using namespace cv;

class FaceCount {
    public:
        FaceCount();
        void detectarFace(Mat &img, CascadeClassifier &cascade, double scale);
        virtual ~FaceCount();
        void correctBug(int);

       
        int getCont();
        int getFrame();
        void setFrame(int frame);
        double getClock();
        void setClock(double clck);
        double getMed();
        void setMed(double md);
        void exibirT(string,Mat &m,int);

    protected:
        int cont = 0;
        int aux1 = 0;
        int aux2 = 0;
        int dif = 0;
        int espera = 0;
	double med;
        int frame;
        double clock;

};

#endif // FACE_COUNT_H
