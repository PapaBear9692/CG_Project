//Computer Graphics Project By: A simple 2D Maze Game : Escape Room using C++ and OpenGL
//SM Ashikullha Mhamud (22-47477-2)
//Tahsinul Islam Nishat (22-47478-2)
//Group 10
//Section - J
//Fall 2024-25

#include <windows.h>
#include <GL/glut.h>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

enum GameState { MENU, GAME };
GameState currentState = MENU;
bool isHoveringStart = false;
bool isHoveringQuit = false;


GLfloat angle = 0.0f;
int lives = 3;
int score = 200;

int currentMap = 1;

float CELL_SIZE = 50.0f;
float CELL_SIZE2 = 25.0f;

GLfloat center = 25.0f;
GLfloat center2 = 12.5f;

int ROWS = 15, COLS = 15;


// Maze layout (1 = wall, 0 = empty space)

int maze[30][30] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};
float EXIT_X1 = 13 * CELL_SIZE;
float EXIT_Y1 = 15 * CELL_SIZE;


int maze2[30][30] = {
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1},
    {0,0,0,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,0,1},
    {1,1,0,0,0,0,0,0,0,0,0,1,0,1,1,1,0,0,1,0,1,0,0,0,0,0,0,1,0,1},
    {1,1,0,1,1,1,0,0,1,1,0,1,0,1,1,1,0,1,1,0,1,1,1,1,0,1,0,1,0,1},
    {1,1,0,1,1,1,0,0,1,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1,0,1,0,0,0,1},
    {1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1},
    {1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,1,1,1,0,1},
    {1,0,0,0,0,0,1,1,1,1,0,1,1,1,1,1,0,0,0,0,0,0,0,1,0,1,0,0,0,1},
    {1,0,1,1,1,0,1,1,0,0,0,0,0,0,0,1,0,1,1,1,1,1,0,1,0,1,1,0,1,1},
    {1,0,1,1,1,1,1,1,0,1,1,1,1,1,0,1,0,1,1,0,0,0,0,1,0,1,1,0,1,1},
    {1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,1,1,0,0,0,0,1,0,1,0,0,1,1},
    {1,0,0,0,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,0,0,0,0,1,0,1,1,1,0,1},
    {1,0,1,0,0,0,0,1,0,0,0,0,0,0,1,1,0,1,1,0,1,1,1,1,0,1,0,0,0,1},
    {1,0,1,1,1,1,0,1,1,1,1,1,1,0,1,0,0,0,1,0,0,0,0,0,0,1,0,1,0,1},
    {1,0,1,1,1,1,1,1,0,0,0,0,1,0,1,0,0,0,1,1,1,1,1,1,0,1,0,1,0,1},
    {1,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1},
    {1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,0,1},
    {1,0,1,1,1,1,1,0,0,1,1,0,0,0,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,1},
    {1,0,1,1,0,0,0,0,0,1,1,1,1,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1},
    {1,0,1,1,0,1,1,1,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1},
    {1,0,1,1,0,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1},
    {1,0,0,0,0,0,0,1,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,1,0,0,0,1},
    {1,0,1,1,0,1,1,1,0,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,0,1,1,1,0,1},
    {1,0,1,1,0,1,1,1,0,1,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1,0,0,0,1},
    {1,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,0,0}
};

float EXIT_X2 = 29 * CELL_SIZE2;
float EXIT_Y2 = 29 * CELL_SIZE2;




// Wall Class
class Wall {
public:
    float x, y;
    Wall(float x, float y) : x(x), y(y) {}
    void draw() {
        glColor3f(0.6f, 0.6f, 0.6f);
        glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + CELL_SIZE, y);
        glVertex2f(x + CELL_SIZE, y + CELL_SIZE);
        glVertex2f(x, y + CELL_SIZE);
        glEnd();

        glColor3f(0.3f, 0.3f, 0.3f);
        glBegin(GL_LINES);
        glVertex2f(x, y);
        glVertex2f(x + CELL_SIZE, y + CELL_SIZE);
        glEnd();

        glBegin(GL_LINES);
        glVertex2f(x + CELL_SIZE, y);
        glVertex2f(x, y + CELL_SIZE);
        glEnd();

    }
};


// Fireball Class
class Fireball {
public:
    float x, y;
    float speed = 3.0f;

    bool movingUp = true;
    Fireball(float x, float y) : x(x), y(y) {}

    bool canMove(float newY) {
        if(currentMap == 2)
            speed = 2.5f;

        int col = x / CELL_SIZE;
        int row = newY / CELL_SIZE;
        return maze[row][col] == 0;
    }

    void move() {
        if(currentMap == 2)
        speed = 2.0f;
        float newY = y + (movingUp ? speed : -speed);
        if (canMove(newY)) {
            y = newY;
        } else {
            movingUp = !movingUp;
        }
    }

    void draw() {
        glPushMatrix();
        glTranslatef(x+center, y, 0.0f);
        glScalef(0.8f, 0.8f, 1.0f);
        glRotatef(angle, 0.0f, 0.0f, 1.0f);

        glLineWidth(1.0f);
        glBegin(GL_LINE_LOOP);
            glColor3f(1.0f, 0.5f, 0.0f);
            glVertex2f(-CELL_SIZE / 5, -CELL_SIZE / 5);
            glVertex2f(CELL_SIZE / 5, -CELL_SIZE / 5);
            glVertex2f(CELL_SIZE / 5, CELL_SIZE / 5);
            glVertex2f(-CELL_SIZE / 5, CELL_SIZE / 5);
        glEnd();

        glBegin(GL_QUADS);
            glColor3f(1.0f, 0.5f, 0.0f);
            glVertex2f(-CELL_SIZE / 6, -CELL_SIZE / 6);
            glVertex2f(CELL_SIZE / 6, -CELL_SIZE / 6);
            glVertex2f(CELL_SIZE / 6, CELL_SIZE / 6);
            glVertex2f(-CELL_SIZE / 6, CELL_SIZE / 6);
        glEnd();

        glPopMatrix();
        angle += 45.0f;
    }
};


// Sword Class
class Sword {
public:
    float x, y;
    float speed = 3.0f;

    bool movingRight = true;
    Sword(float x, float y) : x(x), y(y) {}

    bool canMove(float newX) {
        if(currentMap == 2)
            speed = 2.0f;

        int col = newX / CELL_SIZE;
        int row = y / CELL_SIZE;
        return maze[row][col] == 0;
    }

    void move() {
        float newX = x + (movingRight ? speed : -speed);
        if (canMove(newX)) {
            x = newX;
        } else {
            movingRight = !movingRight;
        }
    }

    void draw() {
        glPushMatrix();
        glTranslatef(x, y+center, 0.0f);
        glScalef(0.8f, 0.8f, 1.0f);

        // Draw the blade
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.8f, 0.8f);
        glVertex2f(-CELL_SIZE / 2, -CELL_SIZE / 20);
        glVertex2f(CELL_SIZE / 2, -CELL_SIZE / 20);
        glVertex2f(CELL_SIZE / 2, CELL_SIZE / 20);
        glVertex2f(-CELL_SIZE / 2, CELL_SIZE / 20);
        glEnd();

        // Draw the pointy tip
        glBegin(GL_TRIANGLES);
        glColor3f(0.8f, 0.8f, 0.8f);
        glVertex2f(-CELL_SIZE / 2, -CELL_SIZE / 20);
        glVertex2f(-CELL_SIZE * 0.6f, 0.0f);
        glVertex2f(-CELL_SIZE / 2, CELL_SIZE / 20);
        glEnd();

        // Draw the hilt
        glBegin(GL_QUADS);
        glColor3f(0.6f, 0.3f, 0.0f);
        glVertex2f(CELL_SIZE / 2.2f, -CELL_SIZE / 10);
        glVertex2f(CELL_SIZE / 1.8f, -CELL_SIZE / 10);
        glVertex2f(CELL_SIZE / 1.8f, CELL_SIZE / 10);
        glVertex2f(CELL_SIZE / 2.2f, CELL_SIZE / 10);
        glEnd();

        // Draw the handle
        glBegin(GL_QUADS);
        glColor3f(0.2f, 0.2f, 0.2f);
        glVertex2f(CELL_SIZE * 0.65f, -CELL_SIZE / 20);
        glVertex2f(CELL_SIZE / 2.2f, -CELL_SIZE / 20);
        glVertex2f(CELL_SIZE / 2.2f, CELL_SIZE / 20);
        glVertex2f(CELL_SIZE * 0.65f, CELL_SIZE / 20);
        glEnd();

        glPopMatrix();
    }
};

// Function to draw a circle manually (border of the coin)
void drawCircle(GLfloat radius, int segments) {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < segments; ++i) {
        GLfloat theta = (2.0f * 3.14159265359f * i) / segments;
        GLfloat x = radius * cos(theta);
        GLfloat y = radius * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();
}

// Function to draw a filled circle (main body of the coin)
void drawFilledCircle(GLfloat radius, int segments) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < segments; ++i) {
        GLfloat theta = (2.0f * 3.14159265359f * i) / segments;
        GLfloat x = radius * cos(theta);
        GLfloat y = radius * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();
}

// Coin Class
class Coin {
public:
    float x, y;
    bool collected;

    Coin(float x, float y) : x(x), y(y), collected(false) {}

    void draw() {
        if (collected) return;

        glPushMatrix();
        glTranslatef(x + center, y + center, 0.0f);

        // Draw the black border
        glColor3f(0.0f, 0.0f, 0.0f);
        drawCircle(CELL_SIZE / 5.5f, 50);

        // Draw the gold coin
        glColor3f(1.0f, 0.84f, 0.0f);
        drawFilledCircle(CELL_SIZE / 6.2f, 50);

        // Draw the inner circle
        glColor3f(0.8f, 0.6f, 0.0f);
        glPushMatrix();
        glTranslatef(0.0f, 0.0f, 0.01f);
        drawFilledCircle(CELL_SIZE / 6, 50);
        glPopMatrix();

        glPopMatrix();
    }

    bool isCollected() {
        return collected;
    }

    void collect() {
        collected = true;
        score += 10;
        cout << "Score: " << score << endl;
    }
};

//Diamond Class
class Diamond {
public:
    float x, y;
    bool collected;

    Diamond(float x, float y) : x(x), y(y), collected(false) {}

    void draw() {
        if (collected) return;

        glPushMatrix();
        glTranslatef(x + CELL_SIZE / 2, y + CELL_SIZE / 2, 0.0f);


        glColor3f(1.0f, 0.0f, 0.0f);
        glScalef(CELL_SIZE / 1.9f, CELL_SIZE / 1.9f, 1.0f);

        glBegin(GL_POLYGON);
        glVertex2f(0.5f, 0.5f);
        glVertex2f(-0.5f, 0.5f);
        glVertex2f(-0.6f, 0.2f);
        glVertex2f(0.0f, -0.4f);
        glVertex2f(0.6f, 0.2f);
        glVertex2f(0.5f, 0.5f);
        glEnd();

        glPopMatrix();
    }

    bool isCollected() {
        return collected;
    }

    void collect() {
        collected = true;
        score += 100; // Increase score by 100
        cout << "Score: " << score << endl;
    }
};


// Player Class
class Player {
public:
    float x, y;
    Player(float startX, float startY) : x(startX), y(startY) {}
    void draw() {
        glPushMatrix();
        glTranslatef(x+center, y+center, 0.0f);
        if(currentMap == 1)
            glScalef(0.5f, 0.5f, 0.0f);
        else
            glScalef(0.9f, 0.9f, 0.0f);

        // Draw the head
        glColor3f(1.0f, 0.8f, 0.6f);
        glBegin(GL_QUADS);
        glVertex2f(-CELL_SIZE / 5, CELL_SIZE / 2);
        glVertex2f(CELL_SIZE / 5, CELL_SIZE / 2);
        glVertex2f(CELL_SIZE / 4, CELL_SIZE / 4);
        glVertex2f(-CELL_SIZE / 4, CELL_SIZE / 4);
        glEnd();

        // Draw the body
        glColor3f(1.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
        glVertex2f(-CELL_SIZE / 3, CELL_SIZE / 4);
        glVertex2f(CELL_SIZE / 3, CELL_SIZE / 4);
        glVertex2f(CELL_SIZE / 4, -CELL_SIZE / 3);
        glVertex2f(-CELL_SIZE / 4, -CELL_SIZE / 3);
        glEnd();

        // Draw the legs
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
        glVertex2f(-CELL_SIZE / 6, -CELL_SIZE / 3);
        glVertex2f(-CELL_SIZE / 12, -CELL_SIZE / 3);
        glVertex2f(-CELL_SIZE / 12, -CELL_SIZE / 1.8);
        glVertex2f(-CELL_SIZE / 6, -CELL_SIZE / 1.8);
        glEnd();

        glBegin(GL_QUADS);
        glVertex2f(CELL_SIZE / 12, -CELL_SIZE / 3);
        glVertex2f(CELL_SIZE / 6, -CELL_SIZE / 3);
        glVertex2f(CELL_SIZE / 6, -CELL_SIZE / 1.8);
        glVertex2f(CELL_SIZE / 12, -CELL_SIZE / 1.8);
        glEnd();

        // Draw the arms
        glColor3f(1.0f, 0.8f, 0.6f);
        glBegin(GL_QUADS);
        glVertex2f(-CELL_SIZE / 3, CELL_SIZE / 4);
        glVertex2f(-CELL_SIZE / 2.2, CELL_SIZE / 4);
        glVertex2f(-CELL_SIZE / 2.2, -CELL_SIZE / 8);
        glVertex2f(-CELL_SIZE / 3, -CELL_SIZE / 8);
        glEnd();

        glBegin(GL_QUADS);
        glVertex2f(CELL_SIZE / 3, CELL_SIZE / 4);
        glVertex2f(CELL_SIZE / 2.2, CELL_SIZE / 4);
        glVertex2f(CELL_SIZE / 2.2, -CELL_SIZE / 8);
        glVertex2f(CELL_SIZE / 3, -CELL_SIZE / 8);
        glEnd();

        glPopMatrix();
    }
    void resetPlayer(){
        x = CELL_SIZE;
        y = CELL_SIZE;
    }
    bool canMove(float newX, float newY) {
        int col = newX / CELL_SIZE;
        int row = newY / CELL_SIZE;
        return maze[row][col] == 0;
    }
    void move(float dx, float dy) {
        if (canMove(x + dx, y + dy)) {
            x += dx;
            y += dy;
        }
    }
};

vector<Wall> walls;
vector<Fireball> fireballs = {
    Fireball(4 * CELL_SIZE, 2 * CELL_SIZE),
    Fireball(8 * CELL_SIZE, 3 * CELL_SIZE),
    Fireball(12 * CELL_SIZE, 5 * CELL_SIZE),
    Fireball(4 * CELL_SIZE, 6 * CELL_SIZE),
    Fireball(4 * CELL_SIZE, 12 * CELL_SIZE),
    Fireball(10 * CELL_SIZE, 9 * CELL_SIZE),
    Fireball(13 * CELL_SIZE, 3 * CELL_SIZE)
};
vector<Sword> swords = {
    Sword(6 * CELL_SIZE, 5 * CELL_SIZE),
    Sword(2 * CELL_SIZE, 3 * CELL_SIZE),
    Sword(8 * CELL_SIZE, 7 * CELL_SIZE),
    Sword(10 * CELL_SIZE, 2 * CELL_SIZE),
    Sword(1 * CELL_SIZE, 9 * CELL_SIZE),
    Sword(10 * CELL_SIZE, 9 * CELL_SIZE)
};

vector<Coin> coins = {
    Coin(2 * CELL_SIZE, 3 * CELL_SIZE),
    Coin(6 * CELL_SIZE, 7 * CELL_SIZE),
    Coin(8 * CELL_SIZE, 8 * CELL_SIZE),
    Coin(10 * CELL_SIZE, 3 * CELL_SIZE),
    Coin(12 * CELL_SIZE, 9 * CELL_SIZE)
};

vector<Diamond> diamonds = {
    Diamond(1 * CELL_SIZE, 12 * CELL_SIZE)
};


// Initializing Player
Player player(CELL_SIZE, CELL_SIZE);
//-----------------------------------//

void initMaze() {
    walls.clear();

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 1) {
                walls.emplace_back(j * CELL_SIZE, i * CELL_SIZE);
            }
        }
    }
}

void keyboard(int key, int, int) {
    switch (key) {
        case GLUT_KEY_UP: player.move(0, CELL_SIZE); break;
        case GLUT_KEY_DOWN: player.move(0, -CELL_SIZE); break;
        case GLUT_KEY_LEFT: player.move(-CELL_SIZE, 0); break;
        case GLUT_KEY_RIGHT: player.move(CELL_SIZE, 0); break;
    }
    glutPostRedisplay();
}

void displayLives() {
    glColor3f(0.0f, 0.0f, 0.0f);
    glRasterPos2f(10, ROWS * CELL_SIZE - 20);
    string livesText = "Lives: " + to_string(lives);
    for (char c : livesText) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}

void restartGame() {
    player.x = CELL_SIZE;
    player.y = CELL_SIZE;
    score = 0;
    lives = 3;


    for (auto &coin : coins) coin.collected = false;
    for (auto &diamond : diamonds) diamond.collected = false;

    initMaze();
    glutPostRedisplay();
}


void checkLevelCompletion() {
    float exitX = (currentMap == 1) ? EXIT_X1 : EXIT_X2;
    float exitY = (currentMap == 1) ? EXIT_Y1 : EXIT_Y2;

    if (player.x == exitX && player.y == exitY) {
        if (currentMap == 1 && score >= 130) {
            MessageBox(NULL, "Level Complete! \nProceeding to the next level...", "Level Completed", MB_OK | MB_ICONINFORMATION);

            currentMap = 2;
            CELL_SIZE = CELL_SIZE2;
            center = center2;

            for (int i = 0; i < 30; i++) {
                for (int j = 0; j < 30; j++) {
                    maze[i][j] = maze2[i][j];
            }
}
            ROWS = 30;
            COLS = 30;

            vector<Fireball> fireballs2 = {
                Fireball(8 * CELL_SIZE, 12 * CELL_SIZE),
                Fireball(8 * CELL_SIZE, 27 * CELL_SIZE),
                Fireball(21 * CELL_SIZE,13 * CELL_SIZE),
                Fireball(19 * CELL_SIZE, 3 * CELL_SIZE),
                Fireball(3 * CELL_SIZE, 13 * CELL_SIZE),
                Fireball(26 * CELL_SIZE, 25 * CELL_SIZE),
                Fireball(24 * CELL_SIZE, 15 * CELL_SIZE),
                Fireball(12 * CELL_SIZE, 3 * CELL_SIZE)
            };
            vector<Sword> swords2 = {
                Sword(21 * CELL_SIZE, 12 * CELL_SIZE),
                Sword(21 * CELL_SIZE, 14 * CELL_SIZE),
                Sword(3 * CELL_SIZE, 25 * CELL_SIZE),
                Sword(17 * CELL_SIZE, 25 * CELL_SIZE),
                Sword(10 * CELL_SIZE, 3 * CELL_SIZE),
                Sword(16 * CELL_SIZE, 28 * CELL_SIZE),
                Sword(1 * CELL_SIZE,10 * CELL_SIZE),
                Sword(3 * CELL_SIZE, 7 * CELL_SIZE),
                Sword(25 * CELL_SIZE, 3 * CELL_SIZE),
                Sword(4 * CELL_SIZE, 20 * CELL_SIZE),
                Sword(17 * CELL_SIZE, 19 * CELL_SIZE),
                Sword(10 * CELL_SIZE, 9 * CELL_SIZE)
            };

            vector<Coin> coins2 = {
                Coin(2 * CELL_SIZE, 3 * CELL_SIZE),
                Coin(6 * CELL_SIZE, 7 * CELL_SIZE),
                Coin(9 * CELL_SIZE, 11 * CELL_SIZE),
                Coin(10 * CELL_SIZE, 3 * CELL_SIZE),
                Coin(1 * CELL_SIZE, 15 * CELL_SIZE),
                Coin(26 * CELL_SIZE, 25 * CELL_SIZE),
                Coin(13 * CELL_SIZE, 21 * CELL_SIZE),
                Coin(24 * CELL_SIZE, 27 * CELL_SIZE),
                Coin(10 * CELL_SIZE, 9 * CELL_SIZE),
                Coin(16 * CELL_SIZE, 13 * CELL_SIZE)
            };

            vector<Diamond> diamonds2 = {
                Diamond(5 * CELL_SIZE, 13 * CELL_SIZE),
                Diamond(20 * CELL_SIZE, 13 * CELL_SIZE),
                Diamond(12 * CELL_SIZE, 28 * CELL_SIZE),
            };

            fireballs = fireballs2;
            swords = swords2;
            coins = coins2;
            diamonds = diamonds2;

            restartGame();
            glutPostRedisplay();
        }
        else if (currentMap == 2 && score >= 300) {
            MessageBox(NULL, "You completed all levels! ", "Game Finished", MB_OK | MB_ICONINFORMATION);
            exit(0);
        }
    }
}


void displayScore() {
    glColor3f(0.0f, 0.0f, 0.0f);
    glRasterPos2f(10, ROWS * CELL_SIZE - 40);
    string scoreText = "Score: " + to_string(score);
    for (char c : scoreText) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}

bool checkCollision(float objX, float objY, float size = center) {
    return (player.x < objX + size && player.x + CELL_SIZE > objX &&
            player.y < objY + size && player.y + CELL_SIZE > objY);
}

void update(int value) {
    for (auto &fireball : fireballs) {
        fireball.move();
        if (checkCollision(fireball.x, fireball.y)) {
            player.resetPlayer();
            lives--;
            if (lives <= 0) {
                cout << "Game Over! You lost all lives.\n";
                exit(0);
            }

        }
    }

    for (auto &sword : swords) {
        sword.move();
        if (checkCollision(sword.x, sword.y)) {
            player.resetPlayer();
            lives--;
            if (lives <= 0) {
                cout << "Game Over! You lost all lives.\n";
                exit(0);
            }
        }
    }

    for (auto &coin : coins) {
        if (!coin.isCollected() && checkCollision(coin.x, coin.y)) {
            coin.collect();
        }
    }

    for (auto &diamond : diamonds) {
        if (!diamond.isCollected() && checkCollision(diamond.x, diamond.y)) {
            diamond.collect();
        }
    }

    checkLevelCompletion();

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}


void drawHomeBackground() {

    glColor3f(0.0f, 0.0f, 0.5f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);

    // Drawing pattern
    glVertex2f(-0.8f, 0.8f); glVertex2f(0.8f, 0.8f);
    glVertex2f(-0.8f, 0.8f); glVertex2f(-0.8f, -0.8f);
    glVertex2f(0.8f, 0.8f); glVertex2f(0.8f, 0.2f);
    glVertex2f(0.8f, 0.2f); glVertex2f(0.4f, 0.2f);
    glVertex2f(0.4f, 0.2f); glVertex2f(0.4f, -0.4f);
    glVertex2f(0.4f, -0.4f); glVertex2f(0.0f, -0.4f);
    glVertex2f(0.0f, -0.4f); glVertex2f(0.0f, -0.8f);
    glVertex2f(0.0f, -0.8f); glVertex2f(-0.4f, -0.8f);
    glVertex2f(-0.4f, -0.8f); glVertex2f(-0.4f, -0.4f);
    glVertex2f(-0.4f, -0.4f); glVertex2f(-0.8f, -0.4f);
    glVertex2f(-0.8f, -0.4f); glVertex2f(-0.8f, 0.4f);
    glVertex2f(-0.8f, 0.4f); glVertex2f(-0.4f, 0.4f);
    glVertex2f(-0.4f, 0.4f); glVertex2f(-0.4f, 0.8f);
    glEnd();

    for (float j = -0.9f; j <= 0.9f; j += 0.2f) {
        glVertex2f(-1.0f, j);
        glVertex2f(1.0f, j);
    }
    glEnd();
}
void renderBitmapString(float x, float y, void *font, const char *string) {
    glRasterPos2f(x, y);
    while (*string) {
        glutBitmapCharacter(font, *string);
        string++;
    }
}
void displayControls() {
    glColor3f(1.0f, 1.0f, 1.0f);

    renderBitmapString(0.20f, -0.55f, GLUT_BITMAP_HELVETICA_18, "Play with:");
    renderBitmapString(0.20f, -0.65f, GLUT_BITMAP_HELVETICA_18, "Left Arrow Key: Move Left");
    renderBitmapString(0.20f, -0.70f, GLUT_BITMAP_HELVETICA_18, "Right Arrow Key: Move Right");
    renderBitmapString(0.20f, -0.75f, GLUT_BITMAP_HELVETICA_18, "Up Arrow Key: Move Up");
    renderBitmapString(0.20f, -0.80f, GLUT_BITMAP_HELVETICA_18, "Down Arrow Key: Move Down");
}


// Main Display Function to handle all display affairs
void display() {
    glClear(GL_COLOR_BUFFER_BIT);


    if (currentState == MENU) {
        drawHomeBackground();
        glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
        renderBitmapString(-0.2f, 0.32f, GLUT_BITMAP_TIMES_ROMAN_24, "ESCAPE ROOM");

        // Draw Start Button
        float startColor = isHoveringStart ? 0.9f : 1.0f;
        glColor3f(startColor, 0.2f, 0.2f);
        glBegin(GL_QUADS);
            glVertex2f(-0.3f, 0.0f);
            glVertex2f(0.3f, 0.0f);
            glVertex2f(0.3f, 0.2f);
            glVertex2f(-0.3f, 0.2f);
        glEnd();
        glColor3f(1.0f, 1.0f, 1.0f);
        renderBitmapString(-0.05f, 0.08f, GLUT_BITMAP_HELVETICA_18, "Start");

        // Draw Quit Button
        float quitColor = isHoveringQuit ? 0.9f : 1.0f;
        glColor3f(quitColor, 0.2f, 0.2f);
        glBegin(GL_QUADS);
            glVertex2f(-0.3f, -0.3f);
            glVertex2f(0.3f, -0.3f);
            glVertex2f(0.3f, -0.1f);
            glVertex2f(-0.3f, -0.1f);
        glEnd();
        glColor3f(1.0f, 1.0f, 1.0f);
        renderBitmapString(-0.05f, -0.22f, GLUT_BITMAP_HELVETICA_18, "Quit");

        displayControls();

    }
    else{
        for (auto &wall : walls) wall.draw();
        for (auto &fireball : fireballs) fireball.draw();
        for (auto &sword : swords) sword.draw();
        for (auto &coin : coins) coin.draw();
        for (auto &diamond : diamonds) diamond.draw();
        player.draw();
        displayLives();
        displayScore();
    }
    glutSwapBuffers();
}

void initOpenGL() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, COLS * CELL_SIZE, 0, ROWS * CELL_SIZE);
    if(currentState == GAME)
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    else
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

// Function to check if the mouse is hovering over the buttons
void checkHover(int x, int y) {
    int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
    float mouseX = (float)x / glutGet(GLUT_WINDOW_WIDTH) * 2.0f - 1.0f;
    float mouseY = 1.0f - (float)y / windowHeight * 2.0f;
    isHoveringStart = (mouseX > -0.3f && mouseX < 0.3f && mouseY > 0.0f && mouseY < 0.2f);
    isHoveringQuit = (mouseX > -0.3f && mouseX < 0.3f && mouseY > -0.3f && mouseY < -0.1f);
    glutPostRedisplay();
}

// Mouse click function
void mouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (isHoveringStart) {
            cout << "Start Button Clicked! Game Starting..." << endl;
            currentState = GAME;

            glutDestroyWindow(glutGetWindow()); // Close menu window

            // Create a new window for the game
            glutInitWindowSize(COLS * CELL_SIZE, ROWS * CELL_SIZE);
            glutCreateWindow("Escape Room");

            initOpenGL();
            initMaze();
            glutDisplayFunc(display);
            glutSpecialFunc(keyboard);
            glutTimerFunc(16, update, 0);

            glutPostRedisplay();
        }
        else if (isHoveringQuit) {
            cout << "Quit Button Clicked! Exiting..." << endl;
            exit(0);
        }
    }
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(COLS * CELL_SIZE, ROWS * CELL_SIZE);
    glutCreateWindow("Welcome Escape Room");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutPassiveMotionFunc(checkHover);
    glutMouseFunc(mouseClick);
    glutTimerFunc(16, update, 0);
    glutMainLoop();
    return 0;
}

