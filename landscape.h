#ifndef LANDSCAPE_H
#define LANDSCAPE_H
#ifdef __APPLE_C__
#include<GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <vector>
#include <cmath>
#include <cstdlib>

class Landscape {
  int rows;
  int columns;
  double highest;                         // the highest point in the mesh
  std::vector< std::vector<double>  > d;  // the grid of elevations
  int solidId;                            // display list id for solid mesh
  int wireFrameId;                        // display list id for wire mesh
  static double unused;
  void generate(int x1, int y1, int x2, int y2, double rug);
  double scale(double x) {return x * (((double)rand()/RAND_MAX) - 0.5);}
  void drawTriangle(int x1, int z1, int x2, int z2, int x3, int z3);
  void vertex(double x, double z);
  void createSolidDisplayList();
  void createWireFrameDisplayList();
public:
  Landscape(int rows, int columns);
  void create(double rug);
  void draw() {glCallList(solidId);}
  void drawWireFrame() {glCallList(wireFrameId);}
};


#endif // LANDSCAPE_H
