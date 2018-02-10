#include "Cube.h"

#include <iostream>   
#include <cstdlib> 
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
	m_Shader = new graphics::Shader("shaders/cubevertex.shader", "shaders/cubefragment.shader");
	m_Renderer = new graphics::Renderer();

	// todo::
	m_Layout->Push<float>(3); // position 
	m_Layout->Push<float>(3); // color
	m_VertexArray->AddBuffer(*m_VertexBuffer, *m_Layout);
}

void Cube::FillData()
{
	m_Size = sizeof(m_Vertices) + sizeof(m_Background);
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


// X-aixs  {left, right}  Y-aixs {top, down} Z-aixs {Near, Far}
void Cube::CreateCube()
{
	m_Background.push_back({ m_Top, m_Right, m_Near });
	m_Background.push_back({ m_Down, m_Right, m_Near });
	m_Background.push_back({ m_Top, m_Left, m_Near });

	m_Background.push_back({ m_Down, m_Right, m_Near });
	m_Background.push_back({ m_Down, m_Left, m_Near });
	m_Background.push_back({ m_Top, m_Left, m_Near });



}

void Cube::CreateRandomColor()
{

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