#pragma once

#include<vector>
#include<iostream>
#include "../graphics/graphics.h"

class Cube
{
	typedef std::vector<float> vertex;
private: 
	const float m_Offset     = 0.025f;
	const float m_SideLength = 0.15f;
	const float m_Top   =	0.5f;  const float m_Down = -0.5f;
	const float m_Right =   0.5f;  const float m_Left = -0.5f;
	const float m_Near  =	0.5f;  const float m_Far  = -0.5f;
	unsigned int m_Size = 0;
	float *m_Buffer;
	static const glm::vec3 m_Colors[9];
	std::vector<vertex> m_Vertices[6];
	std::vector<vertex> m_Background;
	graphics::VertexArray *m_VertexArray;
	graphics::VertexBuffer *m_VertexBuffer;
	graphics::IndexBuffer *m_IndexBuffer;
	graphics::VertexBufferLayout *m_Layout;
	graphics::Renderer *m_Renderer;
public:
	graphics::Shader *m_Shader;
	Cube();
	~Cube();
	void AddFeature();
	void RenderCube();
private:
	void Init();
	void CreateCube();
	void CreateFace(std::vector<vertex> &vertices, glm::vec3 vertex);
	void DrawFace(int face, int x, int y, int z, glm::vec3 Pos, glm::vec3 Neg);
	void CreateRandomColor();
	void FillData();
	void CalculateSize();
};