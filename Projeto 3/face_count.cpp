#include "face_count.h"

using namespace std;
using namespace cv;

FaceCount::FaceCount() {}

FaceCount::~FaceCount() {}

void FaceCount::detectarFace( Mat &img, CascadeClassifier &cascade, double scale) {
    vector<Rect> faces;

    Scalar color = Scalar(0,0,255);//cor do retangulo da face
    Mat gray, smallImg;

    cvtColor( img, gray, COLOR_BGR2GRAY );
    double fx = 1 / scale;
    resize( gray, smallImg, Size(), fx, fx, INTER_LINEAR );
    equalizeHist( smallImg, smallImg );

    cascade.detectMultiScale( smallImg, faces,
        1.1, 2, 0
        |CASCADE_SCALE_IMAGE,
        Size(50, 30) );

    for ( size_t i = 0; i < faces.size(); i++ ) {
        Rect r = faces[i];
        Point center;

        rectangle( img, cvPoint(cvRound(r.x*scale), cvRound(r.y*scale)),
                   cvPoint(cvRound((r.x + r.width-1)*scale), cvRound((r.y + r.height-1)*scale)),
                   color, 1, 8, 0);
    }

        exibirT("Faces na tela: " + to_string(faces.size()),img,15);
        exibirT("                         Faces Capturadas: " + to_string(cont-1),img,15);
        correctBug(faces.size());

        imshow( "Face Detector", img );
}
void FaceCount::correctBug(int nFace){
    if(cont==0){
            cont=nFace;
        }
    aux1=nFace;

    if(aux1==aux2){
        espera++;
        if(espera==20){

            cont+=dif;
            dif=0;
            espera=0;
    }
}

    if(aux1>aux2){

        dif=aux1-aux2;
    }else if(aux1<aux2){
        dif=0;

    }

    aux2=nFace;

}
void FaceCount::exibirT(std::string texto,Mat &m, int posicao) {
    putText(m,texto,Point2f(0, posicao),FONT_HERSHEY_COMPLEX, 0.5, Scalar(0, 0, 0,0), 1, LINE_AA);

}
int FaceCount::getCont() {
    return cont;
}
int FaceCount::getFrame() {
    return frame;
}
void FaceCount::setFrame(int f) {
    frame = f;
}
double FaceCount::getClock() {
    return clock;
}
void FaceCount::setClock(double clck) {
    clock = clck;
}
double FaceCount::getMed() {
    return med;
}
void FaceCount::setMed(double md) {
   med = md;
}
