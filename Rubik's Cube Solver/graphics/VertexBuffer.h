#pragma once

namespace graphics
{

	class VertexBuffer
	{
	private:
		unsigned int m_RendererID;
		unsigned int m_Count;
	public:
		VertexBuffer(const void* data, unsigned int size);
		~VertexBuffer();

		void Bind() const;
		void Unbind() const;
		inline unsigned int GetCount() const { return m_Count;  };


	};

}