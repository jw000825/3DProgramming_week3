#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#define _USE_MATH_DEFINES
#include <math.h>



#pragma comment(lib, "OpenGL32")

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

}

const float steps = 100;
const float angle = 3.1415926 * 2.f / steps;

int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 640, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    float xPos = 0;
    float yPos = 0;
    float radius = 1.0f;

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;

        //90도와 같이 각도로 연산하고 싶으면
        //glm의 삼각함수는 radian 형식으로 입력을 받기 때문에 변환해서 넣어주어야한다.
        glm::sin(glm::radians(90.0));  
        glClearColor(0.0f, 0.0f, 0.0f, 0.1f);
        glClear(GL_COLOR_BUFFER_BIT);

        float prevX = xPos;
        float prevY = yPos - radius;
        for (int i = 0; i <= steps; i++) {
            float newX = radius * sin(angle * i);
            float newY = -radius * cos(angle * i);
            glBegin(GL_TRIANGLES);
            glVertex3f(0.0f, 0.0f, 0.0f);
            glVertex3f(prevX, prevY, 0.0f);
            glVertex3f(newX, newY, 0.0f);
            glEnd();

            prevX = newX;
            prevY = newY;
        }


        /*glBegin(GL_LINE_STRIP);
        glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, 0.0f);
        glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, 0.0f);
        glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
        glVertex3f(0.0f, 0.0f, 0.0f);*/


        
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();

       
        
    



        //------------------------------------------------------------------------



//        int width, height;
//        glfwGetFramebufferSize(window, &width, &height);
//
//        glClear(GL_COLOR_BUFFER_BIT);
//        glDisable(GL_DEPTH_TEST);
//        glMatrixMode(GL_PROJECTION);
//        glLoadIdentity();
//        glOrtho(0, width, height, 0, 0, 1); //left, right, bottom, top, near, far
//        glMatrixMode(GL_MODELVIEW);
//
//        glBegin(GL_LINE_LOOP);
//        int x1 = 320, y1 = 240;
//        //int x2 = 200, y2 = 200;
//
//        glColor3f(1, 1, 1);
//        //static double iteration = 0;
//        //static const int offset = 0;
//        static const float radius = 10;    //반지름 설정
//
//        //double x1 = offset + radius + 0 * cos(iteration);
//        //double y1 = offset + radius + 0 * sin(iteration);
//        //static double wobble = 0.0;
//
//        ///*y1 += sin(wobble) * 100;
//        //wobble += 0.01;*/
//
//        double a = M_PI * (100 * 2);
//        double c = 2 * M_PI * 100;
//        static double b = 128;
//        for (double i = 0; i < 2 * M_PI; i = i + ((2 * M_PI) / b)) {
//#if 0
//            double x = x1 + radius * cos(i);
//            double y = y1 + radius * sin(i);
//            glvertex2f(x, y);
//#endif
//            glVertex2f(x1 + radius * cos(i), y1 + radius * sin(i));
//        }
//        //iteration += 0.01;
//        glEnd();
//        glfwSwapBuffers(window);
//        glfwPollEvents();

        //------------------------------------------------------------------------------


    }
    
    glfwDestroyWindow(window);
    glfwTerminate();

    exit(EXIT_SUCCESS);
}