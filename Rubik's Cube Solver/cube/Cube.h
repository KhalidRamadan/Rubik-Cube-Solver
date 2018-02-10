#pragma once

#include<vector>
#include<iostream>
#include "../graphics/graphics.h"

class Cube
{
	typedef std::vector<float> vertex;
private: 
	float m_Offset = 0.05f;
	float m_SideLength = 0.2f;
	float m_Top =	0.5f;
	float m_Down = -0.5f;
	float m_Right = 0.5f;
	float m_Left = -0.5f;
	float m_Near =	0.5f;
	float m_Far =	-0.5f;
	float m_Size = 0;
	float *m_Buffer;
	std::vector<vertex> m_Vertices[6];
	std::vector<vertex> m_Background;
	graphics::VertexArray *m_VertexArray;
	graphics::VertexBuffer *m_VertexBuffer;
	graphics::IndexBuffer *m_IndexBuffer;
	graphics::VertexBufferLayout *m_Layout;
	graphics::Shader *m_Shader;
	graphics::Renderer *m_Renderer;
public:
	Cube();
	~Cube();
	void AddFeature();
	void RenderCube();
private:
	void Init();
	void CreateCube();
	void CreateRandomColor();
	void FillData();
};