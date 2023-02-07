#ifndef RAYTRACER_HPP
#define RAYTRACER_HPP
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>


using namespace std;


// Classe source

class Source 
{public:
    Point P;
    uint8_t r; // valeurs rgb
    uint8_t g;
    uint8_t b;
};

class Maillage
{public:
    int N; // Nb de triangles
    vector<Triangle> Triangles(N);
};

class Point
{
    public:
    double x;
    double y;
    double z;
    Point() {x=0;y=0;z=0;};
    Point (double X, double Y, double Z)
    {
        x=X;
        y=Y;
        z=Z;
    };
};


class Ray
{
    public:
    Point S;
    double x,y,z;
    Ray() 
    {
        S.x=0;
        S.y=0;
        S.z=0;
        x=0;
        y=0;
        z=0;
    }
    Ray(Point P,double* v)
    {
        S=P;
        x=v[1];
        y=v[2];
        z=v[3];
    }
};

class Sphere
{
    public:
    Point C;
    double r;
    Point intersection(Ray R);
    Sphere()
    {
        C.x=0;
        C.y=0;
        C.z=0;
        r=1;
    }
    Sphere (Point P,double R)
    {
        C=P;
        r=R;
    }
};

class Triangle
{
    public:
    Point A;
    Point B;
    Point C;
    Point Intersection(Ray R);
    Triangle ()
    {
        A.x=0;
        A.y=0;
        A.z=0;
        B.x=0;
        B.y=0;
        B.z=0;
        C.x=0;
        C.y=0;
        C.z=0;
    }
    Triangle(Point a, Point b, Point c)
    {
        A=a;
        B=b;
        C=c;
    }
};



class Pixel
{
    private :

    Point centre;
    int largeur;
    vector<int> rgb(3);

    public :
    Pixel();
    Rayon Pixel::rayon_pixel(vector<float>(3) direction)
    {
        Rayon r;
        r.origine = Pixel.centre;
        r.dir = direction;
        return r;
    }
};
Point p;
p.x = 0;
p.y = 0;
p.z = 0;
Pixel::Pixel() : centre(p), largeur (0), rgb((0,0,0));


class Grille
{

    public :
    int l_p;
    int h_p;
    float taille;
    vector<Pixel>(n) g;
    public:
    Grille(l,h,t);
};

Grille::Grille(l,h,t)

{
    l_p(l);
    h_p(h);
    taille(t);
    int n = l_p*h_p;
    for(int i; i<=n;i++) { //initialisation d'une grille, k*l_p<i<(k+1)*l_p - > k_i�me ligne en partant du bas, i mod k eme colonne
        g[i].centre.x = t/2 + (i%k)*t
        g[i].centre.y = t/2 + floor(i/k)*t;
        g[i].centre.z = 0;
        g[i].largeur = t;
        g[i].rgb = (0,0,0); //initialisation du rgb � 0,0,0
    }
};
#endif