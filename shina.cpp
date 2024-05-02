
#ifdef __APPLE__
/* Defined before OpenGL and GLUT includes to avoid deprecation messages */
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <GLUT/glut.h>      // handle the window-managing operations
#else
#include <GL/glew.h>
#include <GL/freeglut.h>    // handle the window-managing operations
#endif
#include <Windows.h>
#include<mmsystem.h>
#include <iostream>

using namespace std;
GLint win_width = 500,
win_hight = 500;

float rectY = -0.2f;//cuonter to flip
float startY = rectY + 0.93f;
GLint page;
// flags to game 2
GLint flag;
GLint nflag;
GLint fflag;
GLint sflag;
GLint cflag;
GLint wflag;
GLint iflag;
GLint cfflag;
//cuont to game 2
GLint cuont = 1;

GLdouble PI = 3.14159265359;

void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius) {
    int i;
    int triangleAmount = 20; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}
//draw half Circle
void drawHalfCircle(GLfloat x, GLfloat y, GLfloat radius) {
    int i;
    int triangleAmount = 20;
    GLfloat twicePi = -1.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}
// to font
void renderBitmapString(float x, float y, void* font, const char* string) { // to display string on screen
    const char* c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

//texture--------------------------------------------------------------------------------
GLuint LoadTexture(const char* filename, int width, int height)
{
    GLuint texture;
    unsigned char* data;
    FILE* file;
    fopen_s(&file, filename, "rb");

    if (file == NULL)
    {
        std::cout << "Unable to open the image file: " << filename << std::endl;
        std::cout << "Program will exit :(" << std::endl;
        exit(0);
        return 0;
    }

    data = (unsigned char*)malloc(width * height * 3);
    fread(data, width * height * 3, 1, file);

    fclose(file);

    for (int i = 0; i < width * height; ++i)
    {
        int index = i * 3;
        unsigned char B, R;
        B = data[index];
        R = data[index + 2];

        data[index] = R;
        data[index + 2] = B;
    }

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    free(data);

    if (glGetError() != GL_NO_ERROR)
    {
        std::cout << "GLError in genTexture()" << std::endl;
    }

    return texture;
}

//Texture path
GLuint myTexture1;
char image1Path[] = "C:\\Users\\LENOVO\\Downloads\\picpro\\0.bmp";
GLuint myTexture2;
char image2Path[] = "C:\\Users\\LENOVO\\Downloads\\picpro\\2.bmp";
GLuint myTexture3;
char image3Path[] = "C:\\Users\\LENOVO\\Downloads\\picpro\\3.bmp";
GLuint myTexture4;
char image4Path[] = "C:\\Users\\LENOVO\\Downloads\\picpro\\4.bmp";
GLuint myTexture5;
char image5Path[] = "C:\\Users\\LENOVO\\Downloads\\picpro\\5.bmp";
GLuint myTexture6;
char image6Path[] = "C:\\Users\\LENOVO\\Downloads\\picpro\\6.bmp";
GLuint myTexture7;
char image7Path[] = "C:\\Users\\LENOVO\\Downloads\\picpro\\7.bmp";
GLuint myTexture8;
char image8Path[] = "C:\\Users\\LENOVO\\Downloads\\picpro\\8.bmp";


GLuint myTexture9;
char image9Path[] = "C:\\Users\\LENOVO\\Downloads\\picpro\\9.bmp";
GLuint myTexture10;
char image10Path[] = "C:\\Users\\LENOVO\\Downloads\\picpro\\10.bmp";
GLuint myTexture11;
char image11Path[] = "C:\\Users\\LENOVO\\Downloads\\picpro\\11.bmp";
GLuint myTexture12;
char image12Path[] = "C:\\Users\\LENOVO\\Downloads\\picpro\\12.bmp";
GLuint myTexture13;
char image13Path[] = "C:\\Users\\LENOVO\\Downloads\\picpro\\13.bmp";
GLuint myTexture14;
char image14Path[] = "C:\\Users\\LENOVO\\Downloads\\picpro\\14.bmp";
GLuint myTexture15;
char image15Path[] = "C:\\Users\\LENOVO\\Downloads\\picpro\\15.bmp";


GLuint myTexture16;
char image16Path[] = "C:\\Users\\LENOVO\\Downloads\\picpro\\16.bmp";
GLuint myTexture17;
char image17Path[] = "C:\\Users\\LENOVO\\Downloads\\picpro\\17.bmp";
GLuint myTexture18;
char image18Path[] = "C:\\Users\\LENOVO\\Downloads\\picpro\\18.bmp";
GLuint myTexture19;
char image19Path[] = "C:\\Users\\LENOVO\\Downloads\\picpro\\19.bmp";
GLuint myTexture20;
char image20Path[] = "C:\\Users\\LENOVO\\Downloads\\picpro\\20.bmp";
GLuint myTexture21;
char image21Path[] = "C:\\Users\\LENOVO\\Downloads\\picpro\\21.bmp";
GLuint myTexture22;
char image22Path[] = "C:\\Users\\LENOVO\\Downloads\\picpro\\22.bmp";
GLuint myTexture23;
char image23Path[] = "C:\\Users\\LENOVO\\Downloads\\picpro\\23.bmp";




GLuint myTexture24;
char image24Path[] = "C:\\Users\\LENOVO\\Downloads\\picpro\\24.bmp";
GLuint myTexture25;
char image25Path[] = "C:\\Users\\LENOVO\\Downloads\\picpro\\25.bmp";
GLuint myTexture26;
char image26Path[] = "C:\\Users\\LENOVO\\Downloads\\picpro\\26.bmp";
GLuint myTexture27;
char image27Path[] = "C:\\Users\\LENOVO\\Downloads\\picpro\\27.bmp";
GLuint myTexture28;
char image28Path[] = "C:\\Users\\LENOVO\\Downloads\\picpro\\28.bmp";
GLuint myTexture29;
char image29Path[] = "C:\\Users\\LENOVO\\Downloads\\picpro\\29.bmp";
GLuint myTexture30;
char image30Path[] = "C:\\Users\\LENOVO\\Downloads\\picpro\\30.bmp";
GLuint myTexture31;
char image31Path[] = "C:\\Users\\LENOVO\\Downloads\\picpro\\31.bmp";
GLuint myTexture32;
char image32Path[] = "C:\\Users\\LENOVO\\Downloads\\picpro\\32.bmp";


GLuint myTexture33;
char image33Path[] = "C:\\Users\\LENOVO\\Downloads\\picpro\\33.bmp";
GLuint myTexture34;
char image34Path[] = "C:\\Users\\LENOVO\\Downloads\\picpro\\34.bmp";
GLuint myTexture35;
char image35Path[] = "C:\\Users\\LENOVO\\Downloads\\picpro\\end.bmp";

void init1() {//size Texture
    myTexture1 = LoadTexture(image1Path, 1600, 1600);
    myTexture2 = LoadTexture(image2Path, 1600, 1600);
    myTexture3 = LoadTexture(image3Path, 1600, 1600);
    myTexture4 = LoadTexture(image4Path, 1600, 1600);
    myTexture5 = LoadTexture(image5Path, 1600, 1600);
    myTexture6 = LoadTexture(image6Path, 1600, 1600);
    myTexture7 = LoadTexture(image7Path, 1600, 1600);
    myTexture8 = LoadTexture(image8Path, 1600, 1600);

    myTexture9 = LoadTexture(image9Path, 1600, 1600);
    myTexture10 = LoadTexture(image10Path, 1600, 1600);
    myTexture11 = LoadTexture(image11Path, 1600, 1600);
    myTexture12 = LoadTexture(image12Path, 1600, 1600);
    myTexture13 = LoadTexture(image13Path, 1600, 1600);
    myTexture14 = LoadTexture(image14Path, 1600, 1600);
    myTexture15 = LoadTexture(image15Path, 1600, 1600);

    myTexture16 = LoadTexture(image16Path, 1600, 1600);
    myTexture17 = LoadTexture(image17Path, 1600, 1600);
    myTexture18 = LoadTexture(image18Path, 1600, 1600);
    myTexture19 = LoadTexture(image19Path, 1600, 1600);
    myTexture20 = LoadTexture(image20Path, 1600, 1600);
    myTexture21 = LoadTexture(image21Path, 1600, 1600);
    myTexture22 = LoadTexture(image22Path, 1600, 1600);
    myTexture23 = LoadTexture(image23Path, 1600, 1600);

    myTexture24 = LoadTexture(image24Path, 1600, 1600);
    myTexture25 = LoadTexture(image25Path, 1600, 1600);
    myTexture26 = LoadTexture(image26Path, 1600, 1600);
    myTexture27 = LoadTexture(image27Path, 1600, 1600);
    myTexture28 = LoadTexture(image28Path, 1600, 1600);
    myTexture29 = LoadTexture(image29Path, 1600, 1600);
    myTexture30 = LoadTexture(image30Path, 1600, 1600);
    myTexture31 = LoadTexture(image31Path, 1600, 1600);
    myTexture32 = LoadTexture(image32Path, 1600, 1600);

    myTexture33 = LoadTexture(image33Path, 1600, 1600);
    myTexture34 = LoadTexture(image34Path, 1600, 1600);
    myTexture35 = LoadTexture(image35Path, 1600, 1600);

   
}



// game number 1------------------------------------------------------------------------
void erorr1() {//erorr answer Q.1

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_BLEND);
    glColor3f(0.87f, 0.07f, 0.235f);
    renderBitmapString(-0.4f, 0.9, GLUT_BITMAP_HELVETICA_18, "stage 1 : guessing game");
    renderBitmapString(-0.6f, 0.3, GLUT_BITMAP_TIMES_ROMAN_24, "ooops!   Not true....Try again~");
    renderBitmapString(-0.6f, 0.1, GLUT_BITMAP_TIMES_ROMAN_24, "Press (1) to return to the question ");
    glutSwapBuffers();
}
void erorr2() {//erorr answer Q.2

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_BLEND);
    glColor3f(0.87f, 0.07f, 0.235f);
    renderBitmapString(-0.4f, 0.9, GLUT_BITMAP_HELVETICA_18, "stage 1 : guessing game");
    renderBitmapString(-0.6f, 0.3, GLUT_BITMAP_TIMES_ROMAN_24, "ooops!   Not true....Try again~");
    renderBitmapString(-0.6f, 0.1, GLUT_BITMAP_TIMES_ROMAN_24, "Press (2) to return to the question ");
    glutSwapBuffers();
}
void erorr3() {//erorr answer Q.3

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_BLEND);
    glColor3f(0.87f, 0.07f, 0.235f);
    renderBitmapString(-0.4f, 0.9, GLUT_BITMAP_HELVETICA_18, "stage 1 : guessing game");
    renderBitmapString(-0.6f, 0.3, GLUT_BITMAP_TIMES_ROMAN_24, "ooops!   Not true....Try again~");
    renderBitmapString(-0.6f, 0.2, GLUT_BITMAP_TIMES_ROMAN_24, "Press (3) to return to the question ");
    glutSwapBuffers();
}
//Draw snowman
void snowman()
{
    // Draw body
    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle(0.0f, 0.0f, 0.5f);

    // Draw head
    glColor3f(1.0f, 1.0f, 1.0f);
    drawFilledCircle(0.0f, 0.7f, 0.3f);

    // Draw eyes
    glColor3f(0.0f, 0.0f, 0.0f);
    drawFilledCircle(-0.1f, 0.8f, 0.05f);
    drawFilledCircle(0.1f, 0.8f, 0.05f);

    // Draw nose
    glColor3f(1.0f, 0.5f, 0.0f);
    drawFilledCircle(0.0f, 0.7f, 0.04f);

    // Draw mouth
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(4.0f);
    glEnable(GL_LINE_STIPPLE);
    glBegin(GL_LINES);
    glVertex2f(-0.1f, 0.60f);
    glVertex2f(0.1f, 0.60f);
    glEnd();

    // Draw hands
    glColor3f(0.396f, 0.263f, 0.129f); // Set color to dark brown
    glLineWidth(6.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.4f, 0.2f);
    glVertex2f(-0.6f, 0.4f);
    glVertex2f(0.4f, 0.2f);
    glVertex2f(0.6f, 0.4f);
    glEnd();

    // Draw buttons
    glColor3f(0.0f, 0.0f, 0.0f);
    drawFilledCircle(0.0f, -0.1f, 0.05f);
    drawFilledCircle(0.0f, -0.2f, 0.05f);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f); // Set color to red
    glVertex2f(-0.2f, 0.4f);
    glColor3f(1.0f, 0.5f, 0.0f); // Set color to orange
    glVertex2f(0.2f, 0.4f);
    glColor3f(1.0f, 1.0f, 0.0f); // Set color to yellow
    glVertex2f(0.2f, 0.45f);
    glColor3f(1.0f, 0.75f, 0.8f); // Set color to pink
    glVertex2f(-0.2f, 0.45f);
    glColor3f(1.0f, 0.0f, 0.0f); // Set color to red
    glVertex2f(-0.1f, 0.45f); // Adjusted y-coordinate
    glColor3f(1.0f, 0.5f, 0.0f); // Set color to orange
    glVertex2f(0.1f, 0.45f); // Adjusted y-coordinate
    glColor3f(1.0f, 1.0f, 0.0f); // Set color to yellow
    glVertex2f(0.2f, 0.1f); // Adjusted y-coordinat
    glColor3f(1.0f, 0.75f, 0.8f); // Set color to pink
    glVertex2f(-0.2f, 0.1f); // Adjusted y-coordinate
    glEnd();

}
//draw snow flake
void Snowflake() {

    glColor4f(0.6f, 0.8f, 1.0f, 1.0f);
    glLineWidth(10.0);

    //Polygon
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.2f, 0.0f);
    glVertex2f(0.4f, 0.0f);
    glVertex2f(0.5f, 0.25f);
    glVertex2f(0.4f, 0.5f);
    glVertex2f(0.2f, 0.5f);
    glVertex2f(0.1f, 0.25f);
    glEnd();
    glFlush();

    // short line
    glEnable(GL_LINE_STIPPLE);

    glBegin(GL_LINE_LOOP);
    glVertex2f(0.2f, 0.0f);
    glVertex2f(0.1f, -0.2f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(0.4f, 0.0f);
    glVertex2f(0.5f, -0.2f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(0.4f, 0.5f);
    glVertex2f(0.5f, 0.7f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(0.2f, 0.5f);
    glVertex2f(0.1f, 0.7f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(0.5f, 0.25f);
    glVertex2f(0.7f, 0.25f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(0.1f, 0.25f);
    glVertex2f(-0.1f, 0.25f);
    glEnd();

    // long line
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.3f, 0.0f);
    glVertex2f(0.3f, -0.4f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(0.3f, 0.5f);
    glVertex2f(0.3f, 0.9f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(0.15f, 0.4f);
    glVertex2f(-0.2f, 0.8f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(0.45f, 0.15f);
    glVertex2f(0.8f, -0.2f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(0.45f, 0.4f);
    glVertex2f(0.8f, 0.7f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(0.15f, 0.15f);
    glVertex2f(-0.2f, -0.2f);
    glEnd();

    glDisable(GL_LINE_STIPPLE);
    glFlush();

    // tringle
    glEnable(GL_LINE_STIPPLE);

    glBegin(GL_LINE_STRIP);
    glVertex2f(0.25f, -0.15f);
    glVertex2f(0.3f, -0.1f);
    glVertex2f(0.35f, -0.15f);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(0.25f, -0.25f);
    glVertex2f(0.3f, -0.2f);
    glVertex2f(0.35f, -0.25f);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(0.49f, 0.01f);
    glVertex2f(0.5f, 0.1f);
    glVertex2f(0.59f, 0.13f);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(0.6f, -0.09f);
    glVertex2f(0.6f, 0.0f);
    glVertex2f(0.68f, 0.03f);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(0.59f, 0.44f);
    glVertex2f(0.5f, 0.45f);
    glVertex2f(0.53f, 0.56f);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(0.7f, 0.52f);
    glVertex2f(0.6f, 0.53f);
    glVertex2f(0.63f, 0.65f);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(0.25f, 0.65f);
    glVertex2f(0.3f, 0.6f);
    glVertex2f(0.35f, 0.65f);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(0.25f, 0.75f);
    glVertex2f(0.3f, 0.7f);
    glVertex2f(0.35f, 0.75f);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.03f, 0.5f);
    glVertex2f(0.05f, 0.52f);
    glVertex2f(0.07f, 0.6f);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.1f, 0.58f);
    glVertex2f(-0.02f, 0.6f);
    glVertex2f(0.0f, 0.7f);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(0.12f, 0.0f);
    glVertex2f(0.1f, 0.1f);
    glVertex2f(0.0f, 0.1f);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(0.01f, -0.11f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.1f, 0.0f);
    glEnd();

    glDisable(GL_LINE_STIPPLE);
    glFlush();
    glClearColor(1.0f, 0.0f, 1.0f, 0.0f);

}
// draw sweater
void sweater() {
    // rect
    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.5f, 0.6f);
    glVertex2f(-0.3, 0.3);
    glVertex2f(0.3, 0.3);
    glVertex2f(0.3, -0.4);
    glVertex2f(-0.3, -0.4);
    glEnd();

    glLineWidth(10.0f);
    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.5f, 0.6f);
    glVertex2f(-0.3, 0.3);
    glVertex2f(-0.3, 0.05);
    glVertex2f(-0.6, -0.4);
    glVertex2f(-0.7, -0.28);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.5f, 0.6f);
    glVertex2f(0.3, 0.3);
    glVertex2f(0.3, 0.05);
    glVertex2f(0.6, -0.4);
    glVertex2f(0.7, -0.28);
    glEnd();

    //the neck det
    glColor3f(1.0f, 1.0f, 1.0f);
    drawHalfCircle(0.0, 0.3, 0.15);

    glColor3f(0.9f, 0.5f, 0.6f);
    drawHalfCircle(0.0, 0.3, 0.10);

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.3, -0.4);
    glVertex2f(-0.3, -0.4);
    glEnd();


    glColor3f(0.0f, 0.0f, 0.0f);
    drawFilledCircle(0.0, -0.1, 0.11);

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.1, 0.0);
    glVertex2f(0.1, -0.1);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.0, 0.0);
    glVertex2f(-0.1, 0.0);
    glVertex2f(-0.1, -0.1);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.7f, 0.8f);
    glVertex2f(0.0, -0.03);
    glVertex2f(-0.08, 0.0);
    glVertex2f(-0.08, -0.08);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.7f, 0.8f);
    glVertex2f(0.0, -0.03);
    glVertex2f(0.08, 0.0);
    glVertex2f(0.08, -0.08);
    glEnd();

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

//draw rectangle for game 2
void rec() {
    glBegin(GL_QUADS);
    glColor3f(0, 0.1, 0.4); // Set color to red
    glVertex2f(-0.9f, -0.2f);
    glVertex2f(0.9f, -0.2f);
    glVertex2f(0.9f, -0.9f);
    glVertex2f(-0.9f, -0.9f);
    glEnd();
    glClearColor(0.9, 0.9, 1, 0.0f);
}
//draw rectangle for game 1
void rec2() {
    glBegin(GL_QUADS);
    glColor4f(1.0, 1.0, 1.0, 0.5); // Set color to red
    glVertex2f(0.5f, 0.6f);
    glVertex2f(-0.5f, 0.6f);
    glVertex2f(-0.5, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glEnd();

}

//---------------------------------------------------------------------------------------------

//game number 2--------------------------------------------------------------------------------

void linn1() {// to draw line up the corect awnser
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.4f);
    glVertex2f(-0.1f, -0.68f);
    glVertex2f(0.3f, -0.68f);
    glEnd();
    glFlush();

}

void UpperWheel() {

    //the Upper Wheel
    glLineWidth(300.0f);
    glBegin(GL_LINES);
    glColor4f(0.8f, 0.6f, 0.5f, 1.0f);
    glVertex2f(-0.9, 0.9);
    glVertex2f(-0.9, 0.4);
    glEnd();

    glLineWidth(0.11f);
    glBegin(GL_LINES);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(-0.7, 0.4);
    glVertex2f(-0.7, 0.9);
    glEnd();


    glLineWidth(2.0f);
    glBegin(GL_LINES); //First Wheel Handle
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(-0.75, 0.6);
    glVertex2f(-0.75, 0.7);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES); //Second wheel handle
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(-0.35, 0.6);
    glVertex2f(-0.35, 0.7);
    glEnd();


    //a shelf above the stove

    glLineWidth(150.0f);
    glBegin(GL_LINES);
    glColor4f(0.0f, 0.0f, 0.0f, 0.3f);
    glVertex2f(-0.001, 0.9);
    glVertex2f(-0.001, 0.6);
    glEnd();

    glLineWidth(60.0f);
    glBegin(GL_LINES);
    glColor4f(0.0f, 0.0f, 0.0f, 0.3f);
    glVertex2f(0.0, 0.85);
    glVertex2f(0.0, 0.63);
    glEnd();

    glLineWidth(120.0f);
    glBegin(GL_LINES);
    glColor4f(0.0f, 0.0f, 0.0f, 0.3f);
    glVertex2f(0.0, 0.85);
    glVertex2f(0.0, 0.63);
    glEnd();

    //Right Upper Wheel

    //shadow
    glLineWidth(10.0f);
    glBegin(GL_LINES);
    glColor4f(0.8f, 0.6f, 0.5f, 0.7f);
    glVertex2f(0.28, 0.6);
    glVertex2f(0.28, 0.4);
    glEnd();

    glLineWidth(1.0f);
    glBegin(GL_LINES);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(0.3, 0.9);
    glVertex2f(0.3, 0.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(0.8f, 0.6f, 0.5f, 1.0f);
    glVertex2f(0.3, 0.9);
    glVertex2f(1.0, 0.9);
    glVertex2f(1.0, 0.4);
    glVertex2f(0.3, 0.4);
    glEnd();

    glLineWidth(1.0f);
    glBegin(GL_LINES);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(0.7, 0.9);
    glVertex2f(0.7, 0.4);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES); //First Wheel Handle
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(0.65, 0.7);
    glVertex2f(0.65, 0.6);
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES); //Second wheel handle
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(0.74, 0.7);
    glVertex2f(0.74, 0.6);
    glEnd();

}






///-----------------


void BottomWheel() {
    // Left Bottom Wheel

    glBegin(GL_QUADS);
    glColor4f(0.8f, 0.6f, 0.5f, 1.0f);
    glVertex2f(-1.0, -0.22);
    glVertex2f(-0.35, -0.22);
    glVertex2f(-0.35, -0.8);
    glVertex2f(-1.0, -0.8);
    glEnd();



    glLineWidth(0.9f);
    glBegin(GL_LINES);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(-0.7, -0.22);
    glVertex2f(-0.7, -0.8);
    glEnd();

    //The first small shelf
    glLineWidth(0.9f);
    glBegin(GL_LINES);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(-1.0, -0.4);
    glVertex2f(-0.7, -0.4);
    glEnd();

    //The Second small shelf
    glLineWidth(0.9f);
    glBegin(GL_LINES);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(-1.0, -0.6);
    glVertex2f(-0.7, -0.6);
    glEnd();


    //Small handles

    glLineWidth(0.2f);
    glColor3f(0.0f, 0.0f, 0.0f);
    drawFilledCircle(-0.88, -0.45, 0.02);

    glLineWidth(0.2f);
    glColor3f(0.0f, 0.0f, 0.0f);
    drawFilledCircle(-0.88, -0.27, 0.02);


    glLineWidth(0.5f);
    glColor3f(0.0f, 0.0f, 0.0f);
    drawFilledCircle(-0.88, -0.64, 0.02);


    //First Wheel Handle
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(-0.4, -0.45);
    glVertex2f(-0.4, -0.57);
    glEnd();


    glLineWidth(1.0f);
    glBegin(GL_LINES);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(-0.35, -0.22);
    glVertex2f(-0.35, -0.8);
    glEnd();

    //Right Bottom Wheel

    glLineWidth(1.0f);
    glBegin(GL_LINES);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(0.2, -0.22);
    glVertex2f(0.2, -0.8);
    glEnd();

    glBegin(GL_QUADS);
    glColor4f(0.8f, 0.6f, 0.5f, 1.0f);
    glVertex2f(0.2, -0.22);
    glVertex2f(0.6, -0.22);
    glVertex2f(0.6, -0.8);
    glVertex2f(0.2, -0.8);
    glEnd();

    //First Wheel Handle
    glLineWidth(2.0f);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2f(0.55, -0.45);
    glVertex2f(0.55, -0.57);
    glEnd();

    glLineWidth(1.0f);
    glBegin(GL_LINES);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(0.6, -0.22);
    glVertex2f(0.6, -0.8);
    glEnd();

    glLineWidth(1.0f);
    glBegin(GL_LINES);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(0.6, -0.22);
    glVertex2f(1.0, -0.8);
    glEnd();

    //Lower Wheel Part 3
    glBegin(GL_QUADS);
    glColor4f(0.8f, 0.6f, 0.5f, 1.0f);
    glVertex2f(0.6, -0.22);
    glVertex2f(0.9, -1.0);
    glVertex2f(0.65, -1.0);
    glVertex2f(0.6, -0.8);
    glEnd();

    //Second wheel handle

    glLineWidth(2.0f);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2f(0.66, -0.55);
    glVertex2f(0.66, -0.7);
    glEnd();


    glLineWidth(0.10f);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2f(0.69, -0.47);
    glVertex2f(0.69, -1.0);
    glEnd();

    //Third Wheel Handle 
    glLineWidth(2.0f);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2f(0.73, -0.65);
    glVertex2f(0.73, -0.78);
    glEnd();



}

///-----------------
void Marble() {

    /// part 1
    glBegin(GL_QUADS);
    glColor4f(0.5f, 0.3f, 0.2f, 1.0f);
    glVertex2f(-1.0, -0.12);
    glVertex2f(-0.3, -0.12);
    glVertex2f(-0.35, -0.22);
    glVertex2f(-1.0, -0.22);
    glEnd();

    //part 2
    glBegin(GL_QUADS);
    glColor4f(0.5f, 0.3f, 0.2f, 1.0f);
    glVertex2f(0.2, -0.12);
    glVertex2f(0.6, -0.12);
    glVertex2f(0.6, -0.22);
    glVertex2f(0.2, -0.22);
    glEnd();

    // part 3
    glBegin(GL_QUADS);
    glColor4f(0.5f, 0.3f, 0.2f, 1.0f);
    glVertex2f(0.6, -0.12);
    glVertex2f(1.0, -0.12);
    glVertex2f(1.0, -0.22);
    glVertex2f(0.6, -0.22);
    glEnd();

    // part 4
    glBegin(GL_QUADS);
    glColor4f(0.5f, 0.3f, 0.2f, 1.0f);
    glVertex2f(0.6, -0.22);
    glVertex2f(0.9, -1.0);
    glVertex2f(1.0, -1.0);
    glVertex2f(1.0, -0.22);
    glEnd();




}

///-----------------
void Stove()
{

    glBegin(GL_QUADS);//stove
    glColor4f(0.0f, 0.0f, 0.0f, 0.3f);
    glVertex2f(-0.3, -0.12);
    glVertex2f(0.2, -0.12);
    glVertex2f(0.2, -0.22);
    glVertex2f(-0.35, -0.22);
    glEnd();


    glBegin(GL_QUADS); //Electric stove
    glColor4f(0.0f, 0.0f, 0.0f, 0.6f);
    glVertex2f(-0.35, -0.22);
    glVertex2f(0.2, -0.22);
    glVertex2f(0.2, -0.8);
    glVertex2f(-0.35, -0.8);
    glEnd();

    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(-0.25, -0.3);
    glVertex2f(0.11, -0.3);
    glEnd();

    glLineWidth(1.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    drawFilledCircle(-0.22, -0.33, 0.02);

    glLineWidth(1.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    drawFilledCircle(-0.06, -0.33, 0.02);

    glLineWidth(1.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    drawFilledCircle(0.09, -0.33, 0.02);


    glBegin(GL_QUADS);
    glColor4f(0.0f, 0.0f, 0.0f, 0.6f);
    glVertex2f(-0.25, -0.37);
    glVertex2f(0.11, -0.37);
    glVertex2f(0.11, -0.7);
    glVertex2f(-0.25, -0.7);
    glEnd();

}

// Draw RICE FLOUR 
void MyMainObj1()
{

    glLineWidth(5.0f);

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.8, 0.8);
    glVertex2f(-0.6f, 0.7f);
    glVertex2f(0.6f, 0.7f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(-0.5f, -0.5f);
    glEnd();
    glFlush();

    glBegin(GL_QUADS);
    glColor4f(1.0f, 1.0f, 1.0f, 0.5f);
    glVertex2f(-0.4f, 0.5f);
    glVertex2f(0.4f, 0.5f);
    glVertex2f(0.4f, -0.0f);
    glVertex2f(-0.4f, -0.0f);
    glEnd();
    glFlush();
    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.0f, 0.0f);
    glVertex2f(-0.5f, 0.7f);
    glVertex2f(0.5f, 0.7f);
    glVertex2f(0.49f, 0.6f);
    glVertex2f(-0.49f, 0.6f);
    glEnd();
    glFlush();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.1f, 0.35f);
    glVertex2f(0.1f, 0.35f);
    glVertex2f(0.4f, 0.0f);
    glVertex2f(-0.4f, 0.0f);

    glEnd();
    glFlush();
    drawFilledCircle(0.0, 0.3, .1);

    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.0f, 0.0f);
    glVertex2f(-0.5f, 0.1f);
    glVertex2f(0.5f, 0.1f);
    glVertex2f(0.3f, -0.1f);
    glVertex2f(-0.3f, -0.1f);
    glEnd();
    glFlush();

    glBegin(GL_QUADS);
    glColor4f(1.0f, 1.0f, 1.0f, 0.2f);
    glVertex2f(-0.6f, 0.7f);
    glVertex2f(0.6f, 0.7f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(-0.5f, -0.5f);
    glEnd();
    glFlush();

}
// Draw ICE CREAM
void MyMainObj2()
{
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.1, 0.3);
    glVertex2f(-0.54f, 0.1f);
    glVertex2f(0.54f, 0.1f);
    glVertex2f(0.3f, -0.7f);
    glVertex2f(-0.3f, -0.7f);
    glEnd();
    glFlush();
    glColor3f(1.0, 1.0, 1.0);
    drawFilledCircle(0.1, -0.3, .16);
    glColor4f(1.0, 1.0, 1.0, 0.5);
    drawFilledCircle(-0.1, -0.3, .13);

    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.7f, 0.0f);
    glVertex2f(-0.54f, 0.1f);
    glVertex2f(0.54f, 0.1f);
    glVertex2f(0.54f, -0.1f);
    glVertex2f(-0.54f, -0.1f);
    glEnd();
    glFlush();

    glBegin(GL_QUADS);
    glColor4f(1.0, 0.1, 0.3, 0.5);
    glVertex2f(-0.3f, -0.5f);
    glVertex2f(0.3f, -0.5f);
    glVertex2f(0.3f, -0.6f);
    glVertex2f(-0.3f, -0.6f);
    glEnd();
    glFlush();



}
// Draw CRON STARCH
void MyMainObj3()
{
    glBegin(GL_QUADS);
    glColor3f(0.9, 1, 0.5);
    glVertex2f(-0.54f, 0.7f);
    glVertex2f(0.54f, 0.7f);
    glVertex2f(0.54f, -0.7f);
    glVertex2f(-0.54f, -0.7f);
    glEnd();
    glFlush();

    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0);
    glVertex2f(-0.54f, 0.7f);
    glVertex2f(0.54f, 0.7f);
    glVertex2f(0.3f, 0.8f);
    glVertex2f(-0.7f, 0.8f);
    glEnd();
    glFlush();

    glBegin(GL_QUADS);
    glColor3f(0.9, 0.8, 0);
    glVertex2f(-0.54f, 0.7f);
    glVertex2f(-0.54f, -0.7f);
    glVertex2f(-0.7f, -0.54f);
    glVertex2f(-0.7f, 0.8f);
    glEnd();
    glFlush();


    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.1);
    glVertex2f(0.1f, 0.4f);
    glVertex2f(0.3f, 0.3f);
    glVertex2f(0.1f, -0.5f);
    glVertex2f(-0.3f, -0.3f);
    glEnd();
    glFlush();
    drawFilledCircle(0.19, 0.33, .12);
    glColor3f(0.6, 0.8, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.1f, 0.5f);
    glVertex2f(0.1f, -0.5f);
    glVertex2f(-0.3f, -0.3f);
    glEnd();
    glFlush();
    glColor3f(0.6, 0.9, 0.4);
    drawFilledCircle(-0.1, -0.4, .23);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.5f, 0.3f);
    glVertex2f(0.1f, -0.5f);
    glVertex2f(-0.3f, -0.3f);
    glEnd();
    glFlush();

}
// Draw WATER
void MyMainObj4()
{
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.9, 0.9);
    glVertex2f(-0.54f, 0.7f);
    glVertex2f(0.54f, 0.7f);
    glVertex2f(0.54f, -0.7f);
    glVertex2f(-0.54f, -0.7f);
    glEnd();
    glFlush();

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.6, 0.7);
    glVertex2f(-0.54f, 0.7f);
    glVertex2f(0.54f, 0.7f);
    glVertex2f(0.3f, 0.8f);
    glVertex2f(-0.7f, 0.8f);
    glEnd();
    glFlush();

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.6, 0.8);
    glVertex2f(-0.54f, 0.7f);
    glVertex2f(-0.54f, -0.7f);
    glVertex2f(-0.7f, -0.54f);
    glVertex2f(-0.7f, 0.8f);
    glEnd();
    glFlush();
    glColor4f(0.6, 0.7, 0.9, 0.2);
    drawFilledCircle(0.0, 0.0, .4);
    glColor3f(1.0, 1.0, 1.0);
    drawFilledCircle(0.0, 0.0, .3);

}
// Draw SUGER
void MyMainObj5()
{

    glLineWidth(5.0f);

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.8, 1.0);
    glVertex2f(-0.5f, 0.8f);
    glVertex2f(0.5f, 0.8f);
    glColor4f(0.6, 0.8, 1.0f, 0.7f);
    glVertex2f(0.3f, -0.5f);
    glVertex2f(-0.3f, -0.5f);
    glEnd();
    glFlush();

    glBegin(GL_QUADS);
    glColor4f(1.0f, 1.0f, 1.0f, 0.5f);
    glVertex2f(-0.4f, 0.6f);
    glVertex2f(0.4f, 0.6f);
    glColor4f(0.6, 0.8, 1.0f, 0.5f);
    glVertex2f(0.25f, -0.3f);
    glVertex2f(-0.25f, -0.3f);
    glEnd();
    glFlush();




}
// Draw FOOD COLORING
void MyMainObj6()
{

    glLineWidth(2.0f);
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.2f, 0.1f);
    glVertex2f(0.2f, 0.1f);
    glVertex2f(0.2f, -0.1f);
    glVertex2f(-0.2f, -0.1f);
    glEnd();
    glFlush();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.5);
    glVertex2f(-0.2f, 0.1f);
    glVertex2f(0.2f, 0.1f);
    glVertex2f(0.2f, -0.1f);
    glVertex2f(-0.2f, -0.1f);
    glEnd();
    glFlush();

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.1, 0);
    glVertex2f(-0.1f, -0.1f);
    glVertex2f(0.1f, -0.1f);
    glColor4f(0.4, 0.1, 0, 0.7f);
    glVertex2f(0.1f, -0.2f);
    glVertex2f(-0.1f, -0.2f);
    glEnd();
    glFlush();

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.1, 0);
    glVertex2f(-0.2f, -0.2f);
    glVertex2f(0.2f, -0.2f);
    glColor4f(0.4, 0.1, 0, 0.7f);
    glVertex2f(0.2f, -0.6f);
    glVertex2f(-0.2f, -0.6f);
    glEnd();
    glFlush();

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.5, 0.9);
    glVertex2f(-0.2f, -0.3f);
    glVertex2f(0.2f, -0.3f);
    glVertex2f(0.2f, -0.5f);
    glVertex2f(-0.2f, -0.5f);
    glEnd();
    glFlush();


}

void Rectangular() {

    glBegin(GL_QUADS);
    glColor4f(1.0, 1.0, 1.0, 0.6);
    glVertex2f(-0.7f, -0.5f);
    glVertex2f(0.7f, -0.5f);
    glVertex2f(0.7f, -0.9f);
    glVertex2f(-0.7f, -0.9f);
    glEnd();
    glFlush();

    glColor3f(0.0f, 0.0f, 0.2f); // Set text color

    renderBitmapString(-.5, -0.6, GLUT_BITMAP_9_BY_15, "ICE CREAM");
    renderBitmapString(-.5, -0.7, GLUT_BITMAP_9_BY_15, "COLORING FOOD");
    renderBitmapString(-.5, -0.8, GLUT_BITMAP_9_BY_15, "SUGAR");
    renderBitmapString(.1, -0.6, GLUT_BITMAP_9_BY_15, "WATER");
    renderBitmapString(.1, -0.7, GLUT_BITMAP_9_BY_15, "RICE FLOUR");
    renderBitmapString(.1, -0.8, GLUT_BITMAP_9_BY_15, "CRON STARCH");
}

//---------------------------------------------------------------------------------------------



//draw button next 
void next() {
    glBegin(GL_QUADS);
    glColor4f(0.1, 0.9, 1, 0.3);
    glVertex2f(-0.2f, -0.1f);
    glVertex2f(0.2f, -0.1f);
    glVertex2f(0.2f, -0.2f);
    glVertex2f(-0.2f, -0.2f);

    glEnd();
    glFlush();

    glColor3f(0.0f, 0.0f, 0.2f);
    renderBitmapString(-0.12, -0.16, GLUT_BITMAP_9_BY_15, " NEXT");
}



//to start  game
void start() {
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.9, 1);
    glVertex2f(-0.2f, -0.1f);
    glVertex2f(0.2f, -0.1f);
    glVertex2f(0.2f, -0.3f);
    glVertex2f(-0.2f, -0.3f);

    glEnd();
    glFlush();

    glColor3f(0.0f, 0.0f, 0.2f);
    renderBitmapString(-0.15, -0.22, GLUT_BITMAP_HELVETICA_18, "  START");
}
//to back first page
void back() {
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.9, 1);
    glVertex2f(-0.2f, -0.1f);
    glVertex2f(0.2f, -0.1f);
    glVertex2f(0.2f, -0.3f);
    glVertex2f(-0.2f, -0.3f);

    glEnd();
    glFlush();

    glColor3f(0.0f, 0.0f, 0.2f);
    renderBitmapString(-0.15, -0.22, GLUT_BITMAP_HELVETICA_18, "   BACK");

}
//end the game and show member of group
void end() {
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.9, 1);
    glVertex2f(-0.2f, -0.1f);
    glVertex2f(0.2f, -0.1f);
    glVertex2f(0.2f, -0.3f);
    glVertex2f(-0.2f, -0.3f);

    glEnd();
    glFlush();

    glColor3f(0.0f, 0.0f, 0.2f);
    renderBitmapString(-0.15, -0.22, GLUT_BITMAP_HELVETICA_18, "    END");

}
void Display1() {//to start game and story
    page = 1;
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, myTexture1);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(-1.0, 1.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(0.0, -0.4, 0.0);
    start();
    glPopMatrix();
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
  
    glutSwapBuffers();

}
void Display2() {
    page = 2;
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, myTexture2);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(-1.0, 1.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color
   
    renderBitmapString(-.9, -0.5, GLUT_BITMAP_9_BY_15, "A long time ago.. during my stay in the hospital..  ");
    renderBitmapString(-.9, -0.6, GLUT_BITMAP_9_BY_15, "I did not feel close to them..");
    renderBitmapString(-.9, -0.7, GLUT_BITMAP_9_BY_15, "or do I remember how I was with them?..");
    renderBitmapString(-.9, -0.8, GLUT_BITMAP_9_BY_15, "The only words I heard from them were");
    renderBitmapString(-.9, -0.9, GLUT_BITMAP_9_BY_15, " “we are your family”... Am I really one of them?");
   
    glutSwapBuffers();
}


void Display3() {
    page = 3;
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, myTexture3);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(-1.0, 1.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color
  
    renderBitmapString(-.9, -0.5, GLUT_BITMAP_9_BY_15, "I was thinking....if I had been conscious then");
    renderBitmapString(-.9, -0.6, GLUT_BITMAP_9_BY_15, ",would I have loved them as much as they do now?");
    glutSwapBuffers();
}
void Display4() {
    page = 4;
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, myTexture4);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(-1.0, 1.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color
    renderBitmapString(-.9, -0.5, GLUT_BITMAP_9_BY_15, "........ : Shinaaa! ");
    renderBitmapString(-.9, -0.6, GLUT_BITMAP_9_BY_15, "I apologize for making you wait so long!");
    glutSwapBuffers();
}
void Display5() {
    page = 5;
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, myTexture5);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(-1.0, 1.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color

    renderBitmapString(-.9, -0.5, GLUT_BITMAP_9_BY_15, "YUKI: You look healthy,");
    renderBitmapString(-.9, -0.6, GLUT_BITMAP_9_BY_15, "I'm happy to see you like this!");
    glutSwapBuffers();
}
void Display6() {
    page = 6;
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, myTexture6);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(-1.0, 1.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color

    renderBitmapString(-.9, -0.5, GLUT_BITMAP_9_BY_15, "SHINA :Yuki? Why did you come instead of my mother?");
    renderBitmapString(-.9, -0.6, GLUT_BITMAP_9_BY_15, "How did you get all that distance?");

    glutSwapBuffers();
}
void Display7() {
    page = 7;
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, myTexture7);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(-1.0, 1.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color

    renderBitmapString(-.9, -0.5, GLUT_BITMAP_9_BY_15, "YUKI: There is no need to worry, I know the way to ");
    renderBitmapString(-.9, -0.6, GLUT_BITMAP_9_BY_15, "the hospital well and also how to get back home");

    glutSwapBuffers();
}
void Display8() {
    page = 8;
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, myTexture8);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(-1.0, 1.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color

    renderBitmapString(-.9, -0.5, GLUT_BITMAP_9_BY_15, "YUKI: While you walk, I'll play a guessing game with you.  ");
    renderBitmapString(-.9, -0.6, GLUT_BITMAP_9_BY_15, "I want to measure your mental strength.");
    renderBitmapString(-.9, -0.7, GLUT_BITMAP_9_BY_15, "If you answer correctly, I will give you something ! ");

    glutSwapBuffers();
}
void Display9() {
    page = 9;
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, myTexture9);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(-1.0, 1.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color

    renderBitmapString(-.9, -0.5, GLUT_BITMAP_9_BY_15, "SHINA : Why do you say that so frankly ?");
    renderBitmapString(-.9, -0.6, GLUT_BITMAP_9_BY_15, "- Maybe he thinks I'm still unconscious-");

    glutSwapBuffers();
}
static
void key1() {
    page = 10;
    glClear(GL_COLOR_BUFFER_BIT );
    glEnable(GL_BLEND);
    rec();
    glColor3f(0.87f, 0.07f, 0.235f);
    renderBitmapString(-0.4f, 0.9, GLUT_BITMAP_HELVETICA_18, "stage 1 : guessing game");
    glColor3f(0.87f, 0.02f, 0.235f);
    renderBitmapString(-0.2f, -0.1f, GLUT_BITMAP_TIMES_ROMAN_24, "Question (1):");
    glColor3f(1.0f, 1.0f, 1.0f);
    renderBitmapString(-0.8f, -0.3f, GLUT_BITMAP_HELVETICA_18, "I am thinking of a white figure made of snow,It has ");
    renderBitmapString(-0.8f, -0.4f, GLUT_BITMAP_HELVETICA_18, "a round body, a head, and two arms.It often has a ");
    renderBitmapString(-0.8f, -0.5f, GLUT_BITMAP_HELVETICA_18, "hat, scarf,and other decorations. What is it ?");
    glColor3f(0.8, 1, 0.9);
    renderBitmapString(-0.8f, -0.8f, GLUT_BITMAP_HELVETICA_18, "a) Snowman.   b)Snow monster.  c)Snowball.");
    glClearColor(0.9, 0.9, 1, 0.0f);
    glutSwapBuffers();
}
void drawdis1() {
    page =11;
    glClear(GL_COLOR_BUFFER_BIT );
    glEnable(GL_BLEND);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(0.87f, 0.07f, 0.235f);
    renderBitmapString(-0.4f, 0.9, GLUT_BITMAP_HELVETICA_18, "stage 1 : guessing game");
    glColor3f(0.87f, 0.07f, 0.235f);
    renderBitmapString(-0.34f, -0.6, GLUT_BITMAP_TIMES_ROMAN_24, "Correct   answer!");
    glPushMatrix();
    glTranslatef(0.8, -0.8, 0.0);
    next();
    glPopMatrix();
    rec2();
    glPushMatrix();
    glScalef(0.4, 0.4, 0.4);
    glTranslatef(-0.0, -0.2, 0.0);
    snowman();
    glPopMatrix();
    glClearColor(0.9, 0.9, 1, 0.0f);
    glFlush();
    glutSwapBuffers();

}

static
void key2() {
    page = 12;
    glClear(GL_COLOR_BUFFER_BIT );
    glEnable(GL_BLEND);
    rec();
    glColor3f(0.87f, 0.07f, 0.235f);
    renderBitmapString(-0.4f, 0.9, GLUT_BITMAP_HELVETICA_18, "stage 1 : guessing game");
    glColor3f(0.87f, 0.02f, 0.235f);
    renderBitmapString(-0.2f, -0.1f, GLUT_BITMAP_TIMES_ROMAN_24, "Question (2):");
    glColor3f(1.0f, 1.0f, 1.0f);
    renderBitmapString(-0.8f, -0.3f, GLUT_BITMAP_HELVETICA_18, "I am thinking of something delicate and beautiful. It");
    renderBitmapString(-0.8f, -0.4f, GLUT_BITMAP_HELVETICA_18, "falls from the sky in winter. It's made of ice and has");
    renderBitmapString(-0.8f, -0.5f, GLUT_BITMAP_HELVETICA_18, "a unique shape with six sides. Some people say it ");
    renderBitmapString(-0.8f, -0.6f, GLUT_BITMAP_HELVETICA_18, "looks like a tiny star. Can you guess what it is ?");
    glColor3f(0.8, 1, 0.9);
    renderBitmapString(-0.8f, -0.8f, GLUT_BITMAP_HELVETICA_18, "a)Ice crystal.     b)Snow crystal.     c)Snowflake.");
    glClearColor(0.9, 0.9, 1, 0.0f);
    glFlush();
    glutSwapBuffers();
}
void drawdis2() {
    page =13;
    glClear(GL_COLOR_BUFFER_BIT );
    glEnable(GL_BLEND);
    glMatrixMode(GL_MODELVIEW);
    glColor3f(0.87f, 0.07f, 0.235f);
    renderBitmapString(-0.4f, 0.9, GLUT_BITMAP_HELVETICA_18, "stage 1 : guessing game");
    glColor3f(0.87f, 0.07f, 0.235f);
    renderBitmapString(-0.34f, -0.6, GLUT_BITMAP_TIMES_ROMAN_24, "Correct   answer!");
    glPushMatrix();
    glTranslatef(0.8, -0.8, 0.0);
    next();
    glPopMatrix();
    rec2();
    glLoadIdentity();
    glPushMatrix();
    glScalef(0.7, 0.7, 0.7);
    glTranslatef(.2, -0.2, 0.0);
    Snowflake();
    glPopMatrix();
    glPushMatrix();
    glScalef(0.4, 0.4, 0.4);
    glTranslatef(-.8, 0.6, 0.0);
    Snowflake();
    glPopMatrix();
    glPushMatrix();
    glScalef(0.4, 0.4, 0.4);
    glTranslatef(-.9, -0.7, 0.0);
    Snowflake();
    glPopMatrix();
    glClearColor(0.9, 0.9, 1, 0.0f);
    glFlush();
    glutSwapBuffers();
}



static void key3() {
    
    page = 14;

    // Clear the color buffer with the current background color
    glClear(GL_COLOR_BUFFER_BIT);

    // Enable blending for transparency
    glEnable(GL_BLEND);

    // Call the 'rec' function 
    rec();

    // Set the text color to a shade of red and display a title
    glColor3f(0.87f, 0.07f, 0.235f);
    renderBitmapString(-0.4f, 0.9, GLUT_BITMAP_HELVETICA_18, "stage 1 : guessing game");

    // Set the text color to a different shade of red and display a question label
    glColor3f(0.87f, 0.02f, 0.235f);
    renderBitmapString(-0.2f, -0.1f, GLUT_BITMAP_TIMES_ROMAN_24, "Question (3):");

    // Set the text color to white and display the question and options
    glColor3f(1.0f, 1.0f, 1.0f);
    renderBitmapString(-0.8f, -0.3f, GLUT_BITMAP_HELVETICA_18, "I am thinking of something you wear in winter to");
    renderBitmapString(-0.8f, -0.4f, GLUT_BITMAP_HELVETICA_18, "stay warm. It's soft and cozy, with long sleeves.");
    renderBitmapString(-0.8f, -0.5f, GLUT_BITMAP_HELVETICA_18, "It covers your upper body and comes in different");
    renderBitmapString(-0.8f, -0.6f, GLUT_BITMAP_HELVETICA_18, "colors and patterns. Can you guess what it is ?");

    // Set the text color to a light green and display answer options
    glColor3f(0.8, 1, 0.9);
    renderBitmapString(-0.8f, -0.8f, GLUT_BITMAP_HELVETICA_18, "a)Coat.          b)Sweater.          c)Cardigan.");

    // Set the background color to a light blue and clear the buffer
    glClearColor(0.9, 0.9, 1, 0.0f);

    // Flush the rendering pipeline and swap the display buffers
    glFlush();
    glutSwapBuffers();
}

void drawdis3() {
    page = 15;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_BLEND);
    glMatrixMode(GL_MODELVIEW);
    glColor3f(0.87f, 0.07f, 0.235f);
    renderBitmapString(-0.4f, 0.9, GLUT_BITMAP_HELVETICA_18, "stage 1 : guessing game");
    glColor3f(0.87f, 0.07f, 0.235f);
    renderBitmapString(-0.34f, -0.6, GLUT_BITMAP_TIMES_ROMAN_24, "Correct   answer!");
    glPushMatrix();
    glTranslatef(0.8, -0.8, 0.0);
    next();
    glPopMatrix();
    rec2();
    glLoadIdentity();
    glPushMatrix();
    glScalef(0.4, 0.4, 0.4);
    sweater();
    glPopMatrix();
    glClearColor(0.9, 0.9, 1, 0.0f);
    glFlush();
    glutSwapBuffers();
}
void Display16() {
    page = 16;
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, myTexture10);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(-1.0, 1.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color

    renderBitmapString(-.9, -0.5, GLUT_BITMAP_9_BY_15, "SHINA : This...it looks familiar...");


    glutSwapBuffers();
}
void Display17() {
    page = 17;
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, myTexture11);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(-1.0, 1.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color

    renderBitmapString(-.9, -0.5, GLUT_BITMAP_9_BY_15, "SHINA :  I feel like I've seen this thing somewhere!");

    glutSwapBuffers();
}
void Display18() {
    page = 18;
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, myTexture12);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(-1.0, 1.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color

    renderBitmapString(-.9, -0.5, GLUT_BITMAP_9_BY_15, "......: Welcome back, I didn't expect  ");
    renderBitmapString(-.9, -0.6, GLUT_BITMAP_9_BY_15, "you to arrive so early.Looks like Yuki");
    renderBitmapString(-.9, -0.7, GLUT_BITMAP_9_BY_15, "got you here by taking a shortcut.");
    glutSwapBuffers();
}
void Display19() {
    page = 19;
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, myTexture13);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(-1.0, 1.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color

    renderBitmapString(-.9, -0.5, GLUT_BITMAP_9_BY_15, "HARO mom: I apologize that I did not come to ");
    renderBitmapString(-.9, -0.6, GLUT_BITMAP_9_BY_15, "pick you up from the hospital in person, my daughter");
    glutSwapBuffers();
}
void Display20() {
    page = 20;
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, myTexture14);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(-1.0, 1.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color

    renderBitmapString(-.9, -0.5, GLUT_BITMAP_9_BY_15, "SHINA : Why apologise? I'd rather see you fine Mom !");
    renderBitmapString(-.9, -0.6, GLUT_BITMAP_9_BY_15, " I already knew something was wrong, so it's okay");
    glutSwapBuffers();
}
void Display21() {
    page = 21;
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, myTexture15);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(-1.0, 1.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color

    renderBitmapString(-.9, -0.5, GLUT_BITMAP_9_BY_15, "HARO mom: I was planning to surprise you.");
    renderBitmapString(-.9, -0.6, GLUT_BITMAP_9_BY_15, " I was preparing mochi ingredients that you like !");
    glutSwapBuffers();
}
void Display22() {
    page = 22;
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, myTexture16);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(-1.0, 1.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color

    renderBitmapString(-.9, -0.5, GLUT_BITMAP_9_BY_15, "SHINA : Well, I don't know if I remember what it ");
    renderBitmapString(-.9, -0.6, GLUT_BITMAP_9_BY_15, "looks like and what color it is...");
    glutSwapBuffers();
}

void Display23() {
    page = 23;
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, myTexture17);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(-1.0, 1.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color

    renderBitmapString(-.9, -0.5, GLUT_BITMAP_9_BY_15, "HARO mom: That's okay, because you're the one who will ");
    renderBitmapString(-.9, -0.6, GLUT_BITMAP_9_BY_15, "prepare it! and I'll give you a little something ");
    renderBitmapString(-.9, -0.7, GLUT_BITMAP_9_BY_15, "afterward ~");
    renderBitmapString(-.9, -0.9, GLUT_BITMAP_9_BY_15, "SHINA : What's wrong with everyone today?");
    glutSwapBuffers();
}

void Display24() {
    page = 24;
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glColor3f(0.2, 0.0, .0);
    renderBitmapString(-0.45, 0.3f, GLUT_BITMAP_9_BY_15, " stage 2 : Recipe order");
    UpperWheel();
    BottomWheel();
    Stove();
    Marble();
    glFlush();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glScalef(0.2, 0.2, 0.2);
    glTranslatef(-4.0, 0.0, 0.0);
    MyMainObj6();
    glPopMatrix();
    glPushMatrix();
    glScalef(0.2, 0.2, 0.2);
    glTranslatef(4.0, -0.2, 0.0);
    MyMainObj5();
    glPopMatrix();
    glPushMatrix();
    glScalef(0.2, 0.2, 0.2);
    glTranslatef(3.0, -0.3, 0.0);
    MyMainObj4();
    glPopMatrix();
    glPushMatrix();
    glScalef(0.2, 0.2, 0.2);
    glTranslatef(-3.0, -0.3, 0.0);
    MyMainObj3();
    glPopMatrix();
    glPushMatrix();
    glScalef(0.2, 0.2, 0.2);
    glTranslatef(4.2, -1, 0.0);
    MyMainObj2();
    glPopMatrix();
    glPushMatrix();
    glScalef(0.2, 0.2, 0.2);
    glTranslatef(1.7, -0.1, 0.0);
    MyMainObj1();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-.2, 0.0, 0.0);
    Rectangular();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.8, -0.8, 0.0);
    next();
    glPopMatrix();

    if (fflag == 1) {


        glPushMatrix();
       
        linn1();
        glPopMatrix();


    }
    if (sflag == 2) {

        glPushMatrix();
      
        glTranslatef(-0.60, -0.10, 0.0);
        linn1();
        glPopMatrix();


    }
    if (wflag == 3) {

        glPushMatrix();
        glTranslatef(0.01, 0.10, 0.0);
        linn1();
        glPopMatrix();



    }
    if (cfflag == 4) {

        glPushMatrix();
      
        glTranslatef(-0.60, -0.001, 0.0);
        linn1();
        glPopMatrix();

    }
    if (cflag == 5) {

        glPushMatrix();
        glTranslatef(0.01, -0.11, 0.0);
        linn1();
        glPopMatrix();

    }
    if (iflag == 6) {
        glPushMatrix();
       
        glTranslatef(-0.60, 0.1, 0.0);
        linn1();
        glPopMatrix();
    }

    glClearColor(0.9f, 0.9f, 0.9f, 0.0f);
    glutSwapBuffers();
}
void Display25() {
    page = 25;
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, myTexture18);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(-1.0, 1.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color

    renderBitmapString(-.9, -0.5, GLUT_BITMAP_9_BY_15, "SHINA : Yum! It's delicious, I remember having  ");
    renderBitmapString(-.9, -0.6, GLUT_BITMAP_9_BY_15, "eaten something like that somewhere");
    glutSwapBuffers();
}
void Display26() {
    page = 26;
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, myTexture19);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(-1.0, 1.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color

    renderBitmapString(-.9, -0.5, GLUT_BITMAP_9_BY_15, "SHINA : Well...this piece is similar to the ");
    renderBitmapString(-.9, -0.6, GLUT_BITMAP_9_BY_15, "one Yuki gave me.... ");
    renderBitmapString(-.9, -0.7, GLUT_BITMAP_9_BY_15, "I wonder if it's telling me something");
    glutSwapBuffers();
}
void Display27() {
    page = 27;
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, myTexture20);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(-1.0, 1.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color

    renderBitmapString(-.9, -0.5, GLUT_BITMAP_9_BY_15, ".......: Yaaaaay, My sister is back!!!");
    glutSwapBuffers();
}
void Display28() {
    page = 28;
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, myTexture21);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(-1.0, 1.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color

    renderBitmapString(-.9, -0.5, GLUT_BITMAP_9_BY_15, "NATSUMI: Finally, I will play with you like before!!");

    glutSwapBuffers();
}
void Display29() {
    page = 29;
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, myTexture22);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(-1.0, 1.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color

    renderBitmapString(-.9, -0.5, GLUT_BITMAP_9_BY_15, "SHINA : Oh hey Natsumi, what's up with all this ");
    renderBitmapString(-.9, -0.6, GLUT_BITMAP_9_BY_15, "activity?, Do you have another surprise for me ?");
    glutSwapBuffers();
}
void Display30() {
    page = 30;
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, myTexture23);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(-1.0, 1.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color

    renderBitmapString(-.9, -0.5, GLUT_BITMAP_9_BY_15, "NATSUMI: I have the rest of the pieces");
    renderBitmapString(-.9, -0.6, GLUT_BITMAP_9_BY_15, "So I'll give it to you to put together");
    
    glutSwapBuffers();
}
void Display31() {
    page =31;
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, myTexture24);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(-1.0, 1.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color

    renderBitmapString(-.9, -0.5, GLUT_BITMAP_9_BY_15, "NATSUMI: Only then…… I hope it helps you remember~");

    glutSwapBuffers();
}
void Display32() {
    page = 32;
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, myTexture25);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(-1.0, 1.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color

    renderBitmapString(-.9, -0.5, GLUT_BITMAP_9_BY_15, "SHINA :..... what you are talking about.... ");
    glutSwapBuffers();
}
//void Display33() {
//    page = 33;
//    game 3
//}
void Display34() {
    page = 34;

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, myTexture26);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(-1.0, 1.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color

    renderBitmapString(-.9, -0.5, GLUT_BITMAP_9_BY_15, "SHINA :...............");
    renderBitmapString(-.9, -0.6, GLUT_BITMAP_9_BY_15, "I think I...remember something.....");
    glutSwapBuffers();
}
void Display35() {
    page = 35;
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, myTexture27);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(-1.0, 1.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color

    renderBitmapString(-.9, -0.5, GLUT_BITMAP_9_BY_15, "SHINA : Something that was dear to me....");
    glutSwapBuffers();
}
void Display36() {
    page = 36;
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, myTexture28);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(-1.0, 1.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color

    renderBitmapString(-.9, -0.5, GLUT_BITMAP_9_BY_15, "SHINA : I remember...his promise to me...");
    renderBitmapString(-.9, -0.6, GLUT_BITMAP_9_BY_15, "I think he was going to give me this letter...");
    glutSwapBuffers();
}
void Display37() {
    page = 37;
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, myTexture29);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(-1.0, 1.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color

    renderBitmapString(-.9, -0.5, GLUT_BITMAP_9_BY_15, "SHINA : I remember being with him when I was young...");

    glutSwapBuffers();
}
void Display38() {
    page = 38;
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, myTexture30);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(-1.0, 1.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color

    renderBitmapString(-.9, -0.5, GLUT_BITMAP_9_BY_15, "SHINA : I remember his face and his smile....");

    glutSwapBuffers();
}
void Display39() {
    page = 39;
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, myTexture31);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(-1.0, 1.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color

    renderBitmapString(-.9, -0.5, GLUT_BITMAP_9_BY_15, "SHINA : I remember him caressing me...");
    renderBitmapString(-.9, -0.6, GLUT_BITMAP_9_BY_15, "and how warm his embrace was...");
    glutSwapBuffers();
}
void Display40() {
    page = 40;
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, myTexture32);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(-1.0, 1.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color

    renderBitmapString(-.9, -0.5, GLUT_BITMAP_9_BY_15, "SHINA : I remember him lovingly scolding me when ");
    renderBitmapString(-.9, -0.6, GLUT_BITMAP_9_BY_15, "I caused troubles");
    glutSwapBuffers();
}
void Display41() {
    page = 41;
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, myTexture33);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(-1.0, 1.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color

    renderBitmapString(-.9, -0.5, GLUT_BITMAP_9_BY_15, "SHINA : I may have lost him...but he left an ");
    renderBitmapString(-.9, -0.6, GLUT_BITMAP_9_BY_15, "indelible mark on me...even if I don't remember");
    renderBitmapString(-.9, -0.7, GLUT_BITMAP_9_BY_15, "who he is..but ");
    renderBitmapString(-.9, -0.8, GLUT_BITMAP_9_BY_15, "I'm lucky to be part of his family");
    glutSwapBuffers();
}
void Display42() {
    page = 42;
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, myTexture34);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-1.0, -1.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.0, -1.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(-1.0, 1.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(0.0, -0.65, 0.0);
    end();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0, -0.4, 0.0);
    back();
    glPopMatrix();
    glClearColor(0.0, 0.0, 0.2, 1.0f);
    glutSwapBuffers();
}
//display end page
void Display43() {
    page = 43;

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, myTexture35);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-1.0, - 1.0);
    glTexCoord2f(1.0, 0.0); glVertex2f(1.0,  - 1.0);
    glTexCoord2f(1.0, 1.0); glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex2f(-1.0, 1.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f);
    renderBitmapString(-0.4f, - .9, GLUT_BITMAP_9_BY_15, " HOPE YOU ENJOYED (^v^)~");
  
    glutSwapBuffers();
}



//for game 2 and button back,start ,end and next
static void mouse(int button, int state, int x, int y)
{
    int new_y = win_hight - y; // Assuming win_height is defined and initialized

    if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
        cout << "x=" << x << endl;
        cout << "y=" << new_y << endl;

        if (page == 1 && x > 202 && x < 296 && new_y > 79 && new_y < 123) {
          
            glutDisplayFunc(Display2);
            cout << "test" << endl;
        }
        else if (page == 11 && x > 400 && x < 498 && new_y > 1 && new_y < 26) {
            glutDisplayFunc(key2);
            cout << "test" << endl;
        }
        else if (page == 13 && x > 400 && x < 498 && new_y > 1 && new_y < 26) {
            glutDisplayFunc(key3);
            cout << "test" << endl;
        }
        else if (page == 15 && x > 400 && x < 498 && new_y > 1 && new_y < 26) {
            glutDisplayFunc(Display16);
            cout << "test" << endl;
        }
        else if (page == 42 && x > 202 && x < 296 && new_y > 79 && new_y < 123) {
            glutDisplayFunc(Display1);
            cout << "test" << endl;
        }
        else if (page == 42 && x > 200 && x < 299 && new_y > 16 && new_y < 62) {
            glutDisplayFunc(Display43);
            PlaySound(TEXT("uu.wav"), NULL, SND_SYNC);
            cout << "test" << endl;
        }
    }
    else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        cout << "x=" << x << endl;
        cout << "y=" << new_y << endl;

        if (page == 24) {
            if (cuont == 1 && x > 312 && x < 361 && new_y < 279 && new_y > 223) {
                fflag = 1;
                cout << "test" << endl;
                cout << cuont << endl;
                PlaySound(TEXT("pin_1.wav"), NULL, SND_SYNC);
                PlaySound(TEXT("spoon_2.wav"), NULL, SND_SYNC);
                cuont++;
            }
            else if (cuont == 2 && x > 373 && x < 415 && new_y > 202 && new_y < 276) {
                sflag = 2;
                cout << "test" << endl;
                cout << cuont << endl;
                PlaySound(TEXT("pin_1.wav"), NULL, SND_SYNC);
                PlaySound(TEXT("spoon_2.wav"), NULL, SND_SYNC);
                cuont++;
            }
            else if (cuont == 3 && x > 435 && x < 473 && new_y > 215 && new_y < 278) {
                wflag = 3;
                cout << "test" << endl;
                cout << cuont << endl;
                PlaySound(TEXT("pin_1.wav"), NULL, SND_SYNC);
                PlaySound(TEXT("spoon_2.wav"), NULL, SND_SYNC);
                cuont++;
            }
            else if (cuont == 4 && x > 40 && x < 59 && new_y > 221 && new_y < 255) {
                cfflag = 4;
                cout << "test" << endl;
                cout << cuont << endl;
                PlaySound(TEXT("pin_1.wav"), NULL, SND_SYNC);
                PlaySound(TEXT("spoon_2.wav"), NULL, SND_SYNC);
                cuont++;
            }
            else if (cuont == 5 && x > 72 && x < 117 && new_y > 201 && new_y < 275) {
                cflag = 5;
                cout << "test" << endl;
                cout << cuont << endl;
                PlaySound(TEXT("pin_1.wav"), NULL, SND_SYNC);
                PlaySound(TEXT("spoon_2.wav"), NULL, SND_SYNC);
                cuont++;
            }
            else if (cuont == 6 && x > 246 && x < 487 && new_y > 167 && new_y < 205) {
                iflag = 6;
                cout << "test" << endl;
                cout << cuont << endl;
                PlaySound(TEXT("pin_1.wav"), NULL, SND_SYNC);
                PlaySound(TEXT("spoon_2.wav"), NULL, SND_SYNC);
                cuont++;
            }
            else if (cuont == 7 && x > 400 && x < 498 && new_y > 1 && new_y < 26) {
                glutDisplayFunc(Display25);
                PlaySound(TEXT("Shina_mom-1.wav"), NULL, SND_SYNC);
                cout << "test" << endl;
                cout << cuont << endl;
            }
        }
    }

    glutPostRedisplay();
}



// for game 1 to answer some qus
static
void key(unsigned char key, int x, int y) {
    switch (key)
    {
    case 'a':
    case 'A':
        if (page ==10) {
            cout << "ta" << endl;
            PlaySound(TEXT("Y-R-A.wav"), NULL, SND_SYNC);//sound right answer
            glutDisplayFunc(drawdis1);
        }

        if (page == 12) {
            cout << "ee" << endl;
            PlaySound(TEXT("Y-W-A-2.wav"), NULL, SND_SYNC);
            glutDisplayFunc(erorr2);

        }
        if (page == 14) {
            cout << "ee" << endl;
            PlaySound(TEXT("Y-W-A-2.wav"), NULL, SND_SYNC);
            glutDisplayFunc(erorr3);

        }


        break;
    case '1':
        if (page ==10) {

            cout << "t1" << endl;
            glutDisplayFunc(key1);
        }

        break;
    case '2':
        if (page == 13 || page == 12) {
            cout << "t2" << endl;
            glutDisplayFunc(key2);
        }

        break;
    case 'b':
    case 'B':
        if (page == 14) {
            cout << "tb" << endl;
            PlaySound(TEXT("Y-R-A.wav"), NULL, SND_SYNC);//sound right answer
            glutDisplayFunc(drawdis3);
        }
        if (page == 10) {
            cout << "ee" << endl;
            PlaySound(TEXT("Y-W-A-2.wav"), NULL, SND_SYNC);//sound wrong answer
            glutDisplayFunc(erorr1);

        }
        if (page == 12) {
            cout << "ee" << endl;
            PlaySound(TEXT("Y-W-A-2.wav"), NULL, SND_SYNC);//sound wrong answer
            glutDisplayFunc(erorr2);

        }
        break;
    case '3':
        cout << "t3" << endl;
        glutDisplayFunc(key3);

        break;

    case 'c':
    case 'C':
        if (page == 12) {
            cout << "tc" << endl;
            PlaySound(TEXT("Y-R-A.wav"), NULL, SND_SYNC);//sound right answer
            glutDisplayFunc(drawdis2);
        }
        if (page == 10) {
            cout << "ee" << endl;
            PlaySound(TEXT("Y-W-A-2.wav"), NULL, SND_SYNC);//sound wrong answer
            glutDisplayFunc(erorr1);

        }
        if (page == 14) {
            cout << "ee" << endl;
            PlaySound(TEXT("Y-W-A-2.wav"), NULL, SND_SYNC);//sound wrong answer
            glutDisplayFunc(erorr3);

        }

        break;
    default:

        break;
    }


    glutPostRedisplay();
}

static
void special(int key, int x, int y)
{
    //handle special keys
    switch (key) {
 // to move page by page
    case GLUT_KEY_RIGHT:
        if (page == 2) {
            cout << "test" << endl;
            PlaySound(TEXT("uu.wav"), NULL, SND_SYNC);
            glutDisplayFunc(Display3);
        }
        if (page == 3) {
            cout << "test" << endl;
            PlaySound(TEXT("uu.wav"), NULL, SND_SYNC);
            glutDisplayFunc(Display4);
        }
        if (page == 4) {
            cout << "test" << endl;
            PlaySound(TEXT("uu.wav"), NULL, SND_SYNC);
            glutDisplayFunc(Display5);
        }
        if (page == 5) {
            cout << "test" << endl;
            PlaySound(TEXT("uu.wav"), NULL, SND_SYNC);
            glutDisplayFunc(Display6);
        }
        if (page == 6) {
            cout << "test" << endl;
            PlaySound(TEXT("uu.wav"), NULL, SND_SYNC);
            glutDisplayFunc(Display7);
        }
        if (page == 7) {
            cout << "test" << endl;
            PlaySound(TEXT("uu.wav"), NULL, SND_SYNC);
            glutDisplayFunc(Display8);
        }
        if (page == 8) {
            cout << "test" << endl;
            PlaySound(TEXT("uu.wav"), NULL, SND_SYNC);
            glutDisplayFunc(Display9);
        }
        if (page == 9) {
            cout << "test" << endl;
            PlaySound(TEXT("uu.wav"), NULL, SND_SYNC);
            glutDisplayFunc(key1);
        }
        //------------------------
        if (page == 16) {
            cout << "test" << endl;
            PlaySound(TEXT("uu.wav"), NULL, SND_SYNC);
            glutDisplayFunc(Display17);
        }
        if (page == 17) {
            cout << "test" << endl;
            PlaySound(TEXT("uu.wav"), NULL, SND_SYNC);
            glutDisplayFunc(Display18);
        }
        if (page == 18) {
            cout << "test" << endl;
            PlaySound(TEXT("uu.wav"), NULL, SND_SYNC);
            glutDisplayFunc(Display19);
        }
        if (page ==19) {
            cout << "test" << endl;
            PlaySound(TEXT("uu.wav"), NULL, SND_SYNC);
            glutDisplayFunc(Display20);
        }
        if (page == 20) {
            cout << "test" << endl;
            PlaySound(TEXT("uu.wav"), NULL, SND_SYNC);
            glutDisplayFunc(Display21);
        }
        if (page == 21) {
            cout << "test" << endl;
            PlaySound(TEXT("uu.wav"), NULL, SND_SYNC);
            glutDisplayFunc(Display22);
        }
        if (page ==22) {
            cout << "test" << endl;
            PlaySound(TEXT("uu.wav"), NULL, SND_SYNC);
            glutDisplayFunc(Display23);
        }
        if (page == 23) {
            cout << "test" << endl;
            PlaySound(TEXT("uu.wav"), NULL, SND_SYNC);
            glutDisplayFunc(Display24);
        }
        //------------------------
        if (page == 25) {
            cout << "test" << endl;
            PlaySound(TEXT("uu.wav"), NULL, SND_SYNC);
            glutDisplayFunc(Display26);
        }
        if (page == 26) {
            cout << "test" << endl;
            PlaySound(TEXT("uu.wav"), NULL, SND_SYNC);
            glutDisplayFunc(Display27);
        }
        if (page == 27) {
            cout << "test" << endl;
            PlaySound(TEXT("uu.wav"), NULL, SND_SYNC);
            glutDisplayFunc(Display28);
        }
        if (page == 28) {
            cout << "test" << endl;
            PlaySound(TEXT("uu.wav"), NULL, SND_SYNC);
            glutDisplayFunc(Display29);
        }
        if (page == 29) {
            cout << "test" << endl;
            PlaySound(TEXT("uu.wav"), NULL, SND_SYNC);
            glutDisplayFunc(Display30);
        }
        if (page == 30) {
            cout << "test" << endl;
            PlaySound(TEXT("uu.wav"), NULL, SND_SYNC);
            glutDisplayFunc(Display31);
        }
        if (page == 31) {
            cout << "test" << endl;
            PlaySound(TEXT("uu.wav"), NULL, SND_SYNC);
            glutDisplayFunc(Display32);
        }
        if (page == 32) {
            cout << "test" << endl;
            PlaySound(TEXT("uu.wav"), NULL, SND_SYNC);
           glutDisplayFunc(Display34);
        }
        if (page == 34) {
            cout << "test" << endl;
            PlaySound(TEXT("uu.wav"), NULL, SND_SYNC);
            glutDisplayFunc(Display35);
        }
        if (page == 35) {
            cout << "test" << endl;
            PlaySound(TEXT("uu.wav"), NULL, SND_SYNC);
            glutDisplayFunc(Display36);
        }
        if (page ==36) {
            cout << "test" << endl;
            PlaySound(TEXT("uu.wav"), NULL, SND_SYNC);
            glutDisplayFunc(Display37);
        }
        if (page ==37) {
            cout << "test" << endl;
            PlaySound(TEXT("uu.wav"), NULL, SND_SYNC);
            glutDisplayFunc(Display38);
        }
        if (page == 38) {
            cout << "test" << endl;
            PlaySound(TEXT("uu.wav"), NULL, SND_SYNC);
            glutDisplayFunc(Display39);
        }
        if (page == 39) {
            cout << "test" << endl;
            PlaySound(TEXT("uu.wav"), NULL, SND_SYNC);
            glutDisplayFunc(Display40);
        }
        if (page == 40) {
            cout << "test" << endl;
            PlaySound(TEXT("uu.wav"), NULL, SND_SYNC);
            glutDisplayFunc(Display41);
        }
        if (page == 41) {
            cout << "test" << endl;
            PlaySound(TEXT("uu.wav"), NULL, SND_SYNC);
          
            glutDisplayFunc(Display42);
        }
        
        break;
    default:
        break;
    }
    glutPostRedisplay();
}


void reshapeFun(GLint newWidth, GLint newHight)
{
    glViewport(0, 0, newWidth, newHight);
    win_width = newWidth;
    win_hight = newHight;
}

void init()
{

    // Set background color to White and opaque
    glMatrixMode(GL_PROJECTION);          // set the projection parameters
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);                          // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);   //  Specify the display Mode – RGB, RGBA or color //  Index, single or double Buffer
    glutInitWindowSize(win_width, win_hight);       // Set the window's initial width & height
    glutInitWindowPosition(100, 100);                 // Position the window's initial top-left corner
    glutCreateWindow("shina");    // Create a window with the given title
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glutDisplayFunc(Display1);                        // Register display callback handler for window re-paint
    glutReshapeFunc(reshapeFun);
    init();
    init1();
    glutKeyboardFunc(key);
    glutMouseFunc(mouse);
    glutSpecialFunc(special);
    glutMainLoop();                                  // Enter the infinitely event-processing loop
    return 0;
}