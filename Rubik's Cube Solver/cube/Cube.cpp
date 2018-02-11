#include "Cube.h"
#include <time.h>  
#include <stdio.h> 
#include <stdlib.h>  

const glm::vec3 Cube::m_Colors[9] = 
{
	glm::vec3(1.0f, 1.0f, 1.0f), // white 
	glm::vec3(0.0f, 0.0f, 1.0f), // blue
	glm::vec3(1.0f, 1.0f, 0.0f), // yellow
	glm::vec3(0.0f, 1.0f, 0.0f), // green
	glm::vec3(1.0f, 0.0f, 0.0f), // red
	glm::vec3(1.0f, 0.5f, 0.0f), // orange
	glm::vec3(0.7f, 0.5f, 0.3f), // todo:: delete
	glm::vec3(0.3f, 0.3f, 0.3f), // todo:: delete
	glm::vec3(0.7f, 0.7f, 0.7f) // todo:: delete

};


Cube::Cube()
{
	Init();
}


void Cube::Init()
{
	CreateCube();
	CreateRandomColor();
	FillData();
	m_VertexArray = new graphics::VertexArray();
	m_VertexBuffer = new graphics::VertexBuffer(m_Buffer, m_Size);
	//m_IndexBuffer = new graphics::IndexBuffer() todo::
	m_Layout = new graphics::VertexBufferLayout();
	m_Shader = new graphics::Shader("cube/shaders/cubevertex.shader", "cube/shaders/cubefragment.shader"); // todo::
	m_Renderer = new graphics::Renderer();

	// todo::
	m_Layout->Push<float>(3); // position 
	m_Layout->Push<float>(3); // color
	m_VertexArray->AddBuffer(*m_VertexBuffer, *m_Layout);
}


void Cube::CalculateSize()
{
	for (unsigned int i = 0; i < m_Background.size(); i++)
		for (unsigned int j = 0; j < m_Background[i].size(); j++)
			m_Size += sizeof(m_Background[i][j]);
		
	for (unsigned int layer = 0; layer < 6; layer++)
		for (unsigned int i = 0; i < m_Vertices[layer].size(); i++)
			for (unsigned int j = 0; j < m_Vertices[layer][i].size(); j++)
				m_Size += sizeof(m_Vertices[layer][i][j]);
}

void Cube::FillData()
{
	CalculateSize();
	m_Buffer = (float*)std::malloc(m_Size);
	float *pointer = m_Buffer;
	for(unsigned int i = 0; i < m_Background.size(); i++)
		for (unsigned int j = 0; j < m_Background[i].size(); j++)
		{
			*pointer = m_Background[i][j];
			pointer++;
		}

	for(unsigned int layer = 0; layer < 6; layer++)
		for (unsigned int i = 0; i < m_Vertices[layer].size(); i++)
			for (unsigned int j = 0; j < m_Vertices[layer][i].size(); j++)
			{
				*pointer = m_Vertices[layer][i][j];
				pointer++;
			}
}




void Cube::CreateFace(std::vector<vertex> &vertices, glm::vec3 vertex)
{
	vertices.push_back({  vertex.x,  vertex.y, vertex.z });
	vertices.push_back({ -vertex.x,  vertex.y, vertex.z });
	vertices.push_back({  vertex.x, -vertex.y, vertex.z });
	vertices.push_back({ -vertex.x,  vertex.y, vertex.z });
	vertices.push_back({ -vertex.x, -vertex.y, vertex.z });
	vertices.push_back({  vertex.x, -vertex.y, vertex.z });

	vertices.push_back({  vertex.x, vertex.z,  vertex.y });
	vertices.push_back({ -vertex.x, vertex.z,  vertex.y });
	vertices.push_back({  vertex.x, vertex.z, -vertex.y });
	vertices.push_back({ -vertex.x, vertex.z,  vertex.y });
	vertices.push_back({ -vertex.x, vertex.z, -vertex.y });
	vertices.push_back({  vertex.x, vertex.z, -vertex.y });

	vertices.push_back({ vertex.z, vertex.x,  vertex.y });
	vertices.push_back({ vertex.z,-vertex.x,  vertex.y });
	vertices.push_back({ vertex.z, vertex.x, -vertex.y });
	vertices.push_back({ vertex.z,-vertex.x,  vertex.y });
	vertices.push_back({ vertex.z,-vertex.x, -vertex.y });
	vertices.push_back({ vertex.z, vertex.x, -vertex.y });


}



void Cube::DrawFace(int face, int x, int y, int z, glm::vec3 Pos, glm::vec3 Neg)
{

}





// X-axis  {left, right}  Y-axis {top, down} Z-axis {Near, Far}
void Cube::CreateCube()
{
	CreateFace(m_Background, glm::vec3(0.5f, 0.5f,  0.5f));
	//CreateFace(m_Background, glm::vec3(0.5f, 0.5f, -0.5f));
	



	float conterX = 0, conterY = 0, conterZ = m_Near + 0.001;
	for (int Zaxis = 0; Zaxis < 2; Zaxis++)
	{
		conterY = 2 * m_SideLength + m_Offset;
		for (int Xaxis = 0; Xaxis < 3; Xaxis++)
		{
			conterX = -(2 * m_SideLength + m_Offset);
			for (int Yaxis = 0; Yaxis < 3; Yaxis++)
			{
				float PosX = conterX + m_SideLength;
				float NegX = conterX - m_SideLength;
				float PosY = conterY + m_SideLength;
				float NegY = conterY - m_SideLength;
				float PosZ = conterZ;


				m_Vertices[Zaxis].push_back({ PosX, PosY, PosZ });
				m_Vertices[Zaxis].push_back({ NegX, PosY, PosZ });
				m_Vertices[Zaxis].push_back({ PosX, NegY, PosZ });
				m_Vertices[Zaxis].push_back({ NegX, PosY, PosZ });
				m_Vertices[Zaxis].push_back({ NegX, NegY, PosZ });
				m_Vertices[Zaxis].push_back({ PosX, NegY, PosZ });

				conterX += 2 * m_SideLength + m_Offset;
			}
			conterY -= (2 * m_SideLength + m_Offset);
		}
		conterZ -= (1 + 0.002);
	}
}

void Cube::CreateRandomColor()
{
	float red = 0.9f;
	float green = 0.9f;
	float blue = 0.9f;

	for (unsigned int i = 0; i < m_Background.size(); i++)
			m_Background[i].insert(m_Background[i].end(), { red, green, blue });




			srand(time(NULL));
	for (unsigned int layer = 0; layer < 6; layer++)
		for (unsigned int i = 0; i < m_Vertices[layer].size(); i += 6)
		{
			int rands = i / 6;
			for (unsigned int k = 0; k < 6; k++)
			{
				m_Vertices[layer][i + k].insert(m_Vertices[layer][i + k].end(),
				{ m_Colors[rands].x, m_Colors[rands].y, m_Colors[rands].z }); // color
			}
		}

}

Cube::~Cube()
{

}


void Cube::AddFeature()
{

}


void Cube::RenderCube()
{
	m_Renderer->DrawArrays(*m_VertexArray, *m_VertexBuffer, *m_Layout, *m_Shader);
}