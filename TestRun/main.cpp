#include <windows.h>
#include <GL/glut.h>
#include <vector>
#include <iostream>

using namespace std;


const float CELL_SIZE = 40.0f;
GLfloat angle = 0.0f;
GLfloat center = 20.0f;

// Maze layout (1 = wall, 0 = empty space)
/*
const int ROWS = 30, COLS = 30;
int maze[ROWS][COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 1},
    {1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 1},
    {1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 1},
    {1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};
*/

const int ROWS = 15, COLS = 15;
int maze[ROWS][COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1}
};


// Wall Class
class Wall {
public:
    float x, y;
    Wall(float x, float y) : x(x), y(y) {}
    void draw() {
        glColor3f(0.0f, 0.0f, 1.0f);
        glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + CELL_SIZE, y);
        glVertex2f(x + CELL_SIZE, y + CELL_SIZE);
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
        int col = x / CELL_SIZE;
        int row = newY / CELL_SIZE;
        return maze[row][col] == 0;
    }

    void move() {
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
        angle += 25.0f;
    }
};


// Sword Class
class Sword {
public:
    float x, y;
    float speed = 5.0f;
    bool movingRight = true;
    Sword(float x, float y) : x(x), y(y) {}

    bool canMove(float newX) {
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
        glScalef(-1.0f, 1.0f, 1.0f); // Flip horizontally

        // Draw the blade
        glBegin(GL_QUADS);
        glColor3f(0.8f, 0.8f, 0.8f);
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





// Player Class
class Player {
public:
    float x, y;
    Player(float startX, float startY) : x(startX), y(startY) {}
    void draw() {
        glPushMatrix();
        glTranslatef(x+center, y+center, 0.0f);
        glScalef(0.5f, 0.5f, 0.0f); // Increase overall size

        // Draw the head
        glColor3f(1.0f, 0.8f, 0.6f);
        glBegin(GL_QUADS);
        glVertex2f(-CELL_SIZE / 5, CELL_SIZE / 2);
        glVertex2f(CELL_SIZE / 5, CELL_SIZE / 2);
        glVertex2f(CELL_SIZE / 4, CELL_SIZE / 4);
        glVertex2f(-CELL_SIZE / 4, CELL_SIZE / 4);
        glEnd();

        // Draw the body
        glColor3f(1.0f, 0.0f, 0.0f); // Change body color to red
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

std::vector<Wall> walls;
std::vector<Fireball> fireballs = { Fireball(4 * CELL_SIZE, 2 * CELL_SIZE) };
std::vector<Sword> swords = { Sword(6 * CELL_SIZE, 5 * CELL_SIZE) };
Player player(CELL_SIZE, CELL_SIZE);

void initMaze() {
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


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    for (auto &wall : walls) wall.draw();
    for (auto &fireball : fireballs) fireball.draw();
    for (auto &sword : swords) sword.draw();
    player.draw();
    glutSwapBuffers();
}

void update(int value) {
    for (auto &fireball : fireballs) fireball.move();
    for (auto &sword : swords) sword.move();
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void initOpenGL() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, COLS * CELL_SIZE, 0, ROWS * CELL_SIZE);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(COLS * CELL_SIZE, ROWS * CELL_SIZE);
    glutCreateWindow("Maze Game");
    initOpenGL();
    initMaze();
    glutDisplayFunc(display);
    glutSpecialFunc(keyboard);
    glutTimerFunc(16, update, 0);
    glutMainLoop();
    return 0;
}
