
#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <cmath>

bool isHoveringStart = false;
bool isHoveringQuit = false;
float titleAlpha = 0.0f;

// Function to display text on the screen
void renderBitmapString(float x, float y, void *font, const char *string) {
    glRasterPos2f(x, y);
    while (*string) {
        glutBitmapCharacter(font, *string);
        string++;
    }
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
            std::cout << "Start Button Clicked! Game Starting..." << std::endl;
        } else if (isHoveringQuit) {
            std::cout << "Quit Button Clicked! Exiting..." << std::endl;
            exit(0);
        }
    }
}

// Function for title fade-in animation
void updateTitle() {
    if (titleAlpha < 1.0f) {
        titleAlpha += 0.01f;
        glutPostRedisplay();
    }
}

// Display function
void drawMazeBackground() {
    glColor3f(0.0f, 0.0f, 0.5f); // Dark blue maze lines
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    // Maze pattern
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

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawMazeBackground();
    // Render title text with fade-in effect above the Start button
    glColor4f(1.0f, 1.0f, 1.0f, titleAlpha);
    renderBitmapString(-0.2f, 0.32f, GLUT_BITMAP_TIMES_ROMAN_24, "ESCAPE ROOM");

    // Draw Start Button with smooth hover effect
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

    // Draw Quit Button with smooth hover effect
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

    glutSwapBuffers();
}

// Reshape function
void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

// Timer function to update animations
void timer(int value) {
    updateTitle();
    glutTimerFunc(16, timer, 0);
}

// Main function
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Game Start Menu");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutPassiveMotionFunc(checkHover);
    glutMouseFunc(mouseClick);
    glutTimerFunc(16, timer, 0);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutMainLoop();
    return 0;
}
