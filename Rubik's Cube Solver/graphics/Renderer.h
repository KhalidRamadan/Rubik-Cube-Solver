#pragma once

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

namespace graphics
{

	class Renderer
	{
	public:
		void Clear() const;
		void DrawElements(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
		void DrawArrays(const VertexArray& va, const VertexBuffer& vb, const VertexBufferLayout& layout, const Shader& shader) const;
	};

}