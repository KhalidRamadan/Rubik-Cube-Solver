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
	int width = 800; int height = 800;
	{
		graphics::Window mywindow(name.c_str(), width, height);
		glm::vec4 color(0.2f, 0.3f, 0.3f, 1.0f);
		mywindow.SetClearColor(color);
		Cube mycube;



		float visible = 0.4f;
		float viewposZ = -3.0f;
		float viewposY = 0.0f;
		float viewposX = 0.0f;



		mywindow.EnableDepthTest();

		glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
		glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
		glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);


		glm::mat4 model;
		glm::mat4 projection;
		glm::mat4 view;

		view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
		projection = glm::perspective(glm::radians(45.0f), (float)(width / height), 0.1f, 100.0f);


		mycube.m_Shader->SetUniformMatrix4fv("model", model);
		mycube.m_Shader->SetUniformMatrix4fv("projection", projection);
		mycube.m_Shader->SetUniformMatrix4fv("view", view);


		while (!mywindow.Closed())
		{
			mywindow.Clear();
			if (mywindow.IsKeyPressed(GLFW_KEY_ESCAPE) == 1) mywindow.Close();

			float currentFrame = glfwGetTime();
			view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
			mycube.m_Shader->SetUniformMatrix4fv("view", view);

			float angle = 50.0f;
			angle = glfwGetTime() * angle;
			model = glm::translate(glm::mat4(), glm::vec3(0.0f, 0.0f, 0.0f));
			model = glm::rotate(model, glm::radians(angle), glm::vec3(0.5f, 1.0f, 0.0f));
			mycube.m_Shader->SetUniformMatrix4fv("model", model);



			mycube.RenderCube();
	
			mywindow.Update();
		}
	}

	return 0;
}