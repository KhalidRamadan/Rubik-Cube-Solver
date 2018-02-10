#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include<cmath>
#include<math.h>
#include<algorithm>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// my headers 
#include "graphics/Window.h"
#include "cube/Cube.h"



int main()
{
	std::string name = "Rubik's Cube";
	int width = 800; int height = 600;
	{
		graphics::Window mywindow(name.c_str(), width, height);
		glm::vec4 color(0.2f, 0.3f, 0.3f, 1.0f);
		mywindow.SetClearColor(color);


		Cube mycube();
	


		while (!mywindow.Closed())
		{
			mywindow.Clear();

			if (mywindow.IsKeyPressed(GLFW_KEY_ESCAPE) == 1) mywindow.Close();
			
	
			mywindow.Update();
		}
	}

	return 0;
}